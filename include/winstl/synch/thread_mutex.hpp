/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/thread_mutex.hpp
 *
 * Purpose:     Intra-process mutex, based on Windows CRITICAL_SECTION.
 *
 * Created:     17th December 1996
 * Updated:     23rd November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1996-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/thread_mutex.hpp
 *
 * \brief [C++] Definition of winstl::thread_mutex class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_THREAD_MUTEX
#define WINSTL_INCL_WINSTL_SYNCH_HPP_THREAD_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_THREAD_MUTEX_MAJOR     4
# define WINSTL_VER_WINSTL_SYNCH_HPP_THREAD_MUTEX_MINOR     0
# define WINSTL_VER_WINSTL_SYNCH_HPP_THREAD_MUTEX_REVISION  12
# define WINSTL_VER_WINSTL_SYNCH_HPP_THREAD_MUTEX_EDIT      69
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON
# include <winstl/synch/common.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * spin-count support
 */

#ifdef __WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT
# undef __WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT
#endif /* __WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT */

#ifdef __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT
# undef __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT
#endif /* __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT */

#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0403
# define __WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT
#endif /* _WIN32_WINNT >= 0x0403 */

#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0400
# define __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT
#endif /* _WIN32_WINNT >= 0x0400 */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class thread_mutex
/** This class provides an implementation of the mutex model based on the Win32 CRITICAL_SECTION
 *
 * \ingroup group__library__Synch
 */
class thread_mutex
    : public STLSOFT_NS_QUAL(critical_section)< STLSOFT_CRITICAL_SECTION_IS_RECURSIVE
#ifdef __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT
                                            ,   STLSOFT_CRITICAL_SECTION_IS_TRYABLE
#else /* ? __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT */
                                            ,   STLSOFT_CRITICAL_SECTION_ISNOT_TRYABLE
#endif /* __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT */
                                            >
{
public:
    /// This type
    typedef thread_mutex class_type;

// Construction
public:
    /// Creates an instance of the mutex
    thread_mutex() STLSOFT_NOEXCEPT
    {
        WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSection(&m_cs);
    }
#if defined(__WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT)
    /// Creates an instance of the mutex and sets its spin count
    ///
    /// \param spinCount The new spin count for the mutex
    /// \note Only available with Windows NT 4 SP3 and later
    thread_mutex(ws_dword_t spinCount) STLSOFT_NOEXCEPT
    {
        WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSectionAndSpinCount(&m_cs, spinCount);
    }
#endif /* __WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT */
    /// Destroys an instance of the mutex
    ~thread_mutex() STLSOFT_NOEXCEPT
    {
        WINSTL_API_EXTERNAL_Synchronization_DeleteCriticalSection(&m_cs);
    }
private:
    thread_mutex(class_type const&);            // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed

// Operations
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is acquired
    void lock() STLSOFT_NOEXCEPT
    {
        WINSTL_API_EXTERNAL_Synchronization_EnterCriticalSection(&m_cs);
    }
#if defined(__WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT)
    /// Attempts to lock the mutex
    ///
    /// \return <b>true</b> if the mutex was acquired, or <b>false</b> if not
    /// \note Only available with Windows NT 4 and later
    bool try_lock()
    {
        return WINSTL_API_EXTERNAL_Synchronization_TryEnterCriticalSection(&m_cs) != FALSE;
    }
#endif /* __WINSTL_THREAD_MUTEX_TRY_LOCK_SUPPORT */
    /// Releases an acquired lock on the mutex
    void unlock() STLSOFT_NOEXCEPT
    {
        WINSTL_API_EXTERNAL_Synchronization_LeaveCriticalSection(&m_cs);
    }

#if defined(__WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT)
    /// Sets the spin count for the mutex
    ///
    /// \param spinCount The new spin count for the mutex
    /// \return The previous spin count associated with the mutex
    /// \note Only available with Windows NT 4 SP3 and later
    ws_dword_t set_spin_count(ws_dword_t spinCount) STLSOFT_NOEXCEPT
    {
        return WINSTL_API_EXTERNAL_Synchronization_SetCriticalSectionSpinCount(&m_cs, spinCount);
    }
#endif /* __WINSTL_THREAD_MUTEX_SPIN_COUNT_SUPPORT */

// Members
private:
    CRITICAL_SECTION    m_cs;   // critical section
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * control shims
 */

/** This \ref group__concept__Shim "control shim" acquires a lock on the given mutex
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param mx The mutex on which to acquire the lock.
 */
inline
void
lock_instance(
    WINSTL_NS_QUAL(thread_mutex)& mx
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
inline
void
unlock_instance(
    WINSTL_NS_QUAL(thread_mutex)& mx
)
{
    mx.unlock();
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace winstl {
# else
namespace winstl_project {
#  if defined(STLSOFT_COMPILER_IS_BORLAND)
using ::stlsoft::lock_instance;
using ::stlsoft::unlock_instance;
#  endif /* compiler */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * lock_traits
 */

// class lock_traits
/** Traits for the thread_mutex class
 *
 * \ingroup group__library__Synch
 */
struct thread_mutex_lock_traits
{
public:
    /// The lockable type
    typedef thread_mutex                lock_type;
    /// This type
    typedef thread_mutex_lock_traits    class_type;

// Operations
public:
    /// Lock the given thread_mutex instance
    static void lock(thread_mutex &c)
    {
        lock_instance(c);
    }

    /// Unlock the given thread_mutex instance
    static void unlock(thread_mutex &c)
    {
        unlock_instance(c);
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_THREAD_MUTEX */

/* ///////////////////////////// end of file //////////////////////////// */

