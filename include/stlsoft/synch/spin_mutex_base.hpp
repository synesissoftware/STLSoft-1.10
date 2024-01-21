/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/synch/spin_mutex_base.hpp (originally MWSpinMx.h, ::SynesisWin)
 *
 * Purpose:     stlsoft::spin_mutex_base class template.
 *
 * Created:     27th August 1997
 * Updated:     22nd January 2024
 *
 * Thanks:      To Rupert Kittinger, for pointing out that the prior
 *              implementation that always yielded was not really "spinning".
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1997-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file stlsoft/synch/spin_mutex_base.hpp
 *
 * \brief [C++] Definition of the stlsoft::spin_mutex_base class
 *   template
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE
#define STLSOFT_INCL_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE_MAJOR     6
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE_MINOR     0
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE_REVISION  3
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE_EDIT      77
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility & feature control
 */

#if defined(_ATL_MIN_CRT)
# define WINSTL_SPINMUTEX_CHECK_INIT
#endif /* _ATL_MIN_CRT */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class spin_mutex_base
/** This class provides an implementation of the mutex model based on a
 *    spinning mechanism
 *
 * \ingroup group__library__Synch
 *
 * \note A spin mutex is not recursive. If you re-enter it your thread will
 *   be in irrecoverable deadlock.
 */
template<
    ss_typename_param_k P_spinPolicy
>
class spin_mutex_base
    : public STLSOFT_NS_QUAL(critical_section)< STLSOFT_CRITICAL_SECTION_ISNOT_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_ISNOT_TRYABLE
                                            >
{
/// \name Member Types
/// @{
private:
    /// The spin-policy class
    typedef P_spinPolicy                                        spin_policy_;
public:
    /// This class
    typedef spin_mutex_base<P_spinPolicy>                       class_type;
    /// The atomic integer type
    typedef ss_typename_type_k spin_policy_::atomic_int_type    atomic_int_type;
    /// The count type
    typedef ss_sint32_t                                         count_type;
/// @}

/// \name Construction
/// @{
public:
#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("Create stlsoft/synch/spin_mutex_base.hpp, and factor out"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

    /// Creates an instance of the mutex
    ///
    /// \param p Pointer to an external counter variable. May be NULL, in
    ///  which case an internal member is used for the counter variable.
    ss_explicit_k
    spin_mutex_base(atomic_int_type *p = NULL) STLSOFT_NOEXCEPT
        : m_spinCount((NULL != p) ? p : &m_internalCount)
        , m_internalCount(0)
        , m_cLocks(0)
        , m_spunCount(0)
        , m_yieldContext(NULL)
    {}
    /// Creates an instance of the mutex
    ///
    /// \param p Pointer to an external counter variable. May be NULL, in
    ///   which case an internal member is used for the counter variable.
    /// \param yieldContext The yield context
    spin_mutex_base(atomic_int_type *p, void* yieldContext) STLSOFT_NOEXCEPT
        : m_spinCount((NULL != p) ? p : &m_internalCount)
        , m_internalCount(0)
        , m_cLocks(0)
        , m_spunCount(0)
        , m_yieldContext(yieldContext)
    {}
    /// Destroys an instance of the mutex
    ~spin_mutex_base() STLSOFT_NOEXCEPT
    {
        spin_policy_::on_destroy(m_yieldContext, m_spunCount, m_cLocks);
    }
private:
    spin_mutex_base(class_type const&);         // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Operations
/// @{
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is acquired
    void lock() STLSOFT_NOEXCEPT
    {
#ifdef STLSOFT_SPINMUTEX_CHECK_INIT
        // If the dynamic initialisation phase has been skipped, the
        // members will all be assigned to 0, which is correct for
        // all except m_spinCount, which must be assigned to
        // &m_internalCount
        if (NULL == m_spinCount)
        {
            m_spinCount = &m_internalCount;
        }
#endif /* STLSOFT_SPINMUTEX_CHECK_INIT  */

        STLSOFT_MESSAGE_ASSERT("A global instance of an instantiation of spin_mutex_base<> has skipped dynamic initialisation. You must #define STLSOFT_SPINMUTEX_CHECK_INIT if your compilation causes dynamic initialisation to be skipped.", NULL != m_spinCount);

        for (m_spunCount = 1; !spin_policy_::try_acquire_lock(m_yieldContext, m_spinCount, m_spunCount); ++m_spunCount)
        {
            spin_policy_::on_spin(m_yieldContext, m_spunCount);
        }

        ++m_cLocks;

        spin_policy_::on_acquire(m_yieldContext, m_spunCount, m_cLocks);
    }
    /// Releases an acquired lock on the mutex
    void unlock() STLSOFT_NOEXCEPT
    {
        count_type const spunCount  =   m_spunCount;
        count_type const lockCount  =   m_cLocks;

        --m_cLocks;

        spin_policy_::release_lock(m_yieldContext, m_spinCount, spunCount, lockCount);
    }
/// @}

/// \name Attributes
/// @{
public:
    /// An indicator as to the level of contention on the mutex.
    ///
    /// \note The value returned is only meaningful after lock() has been
    ///  called and before a corresponding unlock() has been called.
    ///
    /// \note The value returned is only reliable when an external counter
    ///  variable is being used, and when each spin_mutex_base<> instance is
    ///  thread-specific. In all other cases, the spun count is subject to
    ///  race conditions (that do <em>not</em> affect the good functioning
    ///  of the spin mutex) and value returned may be, at best, used only as
    ///  a guide as to contention.
    count_type  spun_count() const
    {
        return m_spunCount;
    }
/// @}

/// \name Fields
/// @{
private:
    atomic_int_type*    m_spinCount;
    atomic_int_type     m_internalCount;
    count_type          m_cLocks;       // Used as check on matched Lock/Unlock calls
    count_type          m_spunCount;
    void*               m_yieldContext;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * control shims
 */

/** This \ref group__concept__Shim "control shim" acquires a lock on the given mutex
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param mx The mutex on which to acquire the lock.
 */
template<
    ss_typename_param_k P_spinPolicy
>
inline
void
lock_instance(
    spin_mutex_base<P_spinPolicy>& mx
)
{
    mx.lock();
}

/** This \ref group__concept__Shim "control shim" releases a lock on the given mutex
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param mx The mutex on which to release the lock
 */
template<
    ss_typename_param_k P_spinPolicy
>
inline
void
unlock_instance(
    spin_mutex_base<P_spinPolicy>& mx
)
{
    mx.unlock();
}

/* /////////////////////////////////////////////////////////////////////////
 * lock_traits
 */

// class lock_traits
/** Traits for the spin_mutex_base class
 *
 * \ingroup group__library__Synch
 */
struct spin_mutex_lock_traits
{
// Operations
public:
    /// Lock the given spin_mutex_base instance
    template<
        ss_typename_param_k P_spinPolicy
    >
    static
    void
    lock(
        spin_mutex_base<P_spinPolicy> &c
    )
    {
        lock_instance(c);
    }

    /// Unlock the given spin_mutex_base instance
    template<
        ss_typename_param_k P_spinPolicy
    >
    static
    void
    unlock(
        spin_mutex_base<P_spinPolicy> &c
    )
    {
        unlock_instance(c);
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE */

/* ///////////////////////////// end of file //////////////////////////// */

