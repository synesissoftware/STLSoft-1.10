/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/semaphore.hpp
 *
 * Purpose:     Semaphore class, based on Win32 kernel semaphore object.
 *
 * Created:     30th May 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/semaphore.hpp
 *
 * \brief [C++] Definition of winstl::semaphore class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_SEMAPHORE
#define WINSTL_INCL_WINSTL_SYNCH_HPP_SEMAPHORE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_SEMAPHORE_MAJOR    1
# define WINSTL_VER_WINSTL_SYNCH_HPP_SEMAPHORE_MINOR    3
# define WINSTL_VER_WINSTL_SYNCH_HPP_SEMAPHORE_REVISION 16
# define WINSTL_VER_WINSTL_SYNCH_HPP_SEMAPHORE_EDIT     44
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
# include <winstl/api/external/HandleAndObject.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */

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
 * classes
 */

// class semaphore
/** This class acts as a semaphore based on the Win32
 *   kernel semaphore object
 *
 * \ingroup group__library__Synch
 */
class semaphore
    : public STLSOFT_NS_QUAL(critical_section)< STLSOFT_CRITICAL_SECTION_ISNOT_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_IS_TRYABLE
                                            >
    , public STLSOFT_NS_QUAL(synchronisable_object_tag)
{
public:
    /// This type
    typedef semaphore       class_type;
    /// The synchronisation handle type
    typedef HANDLE          synch_handle_type;
    /// The Boolean type
    typedef ws_bool_t       bool_type;
    /// The count type
    typedef ws_size_t       count_type;
    /// The resource type
    typedef HANDLE          resource_type;
private:
#if 0
    typedef LONG            underlying_count_type_;
#else /* ? 0 */
    typedef count_type      underlying_count_type_;
#endif /* 0 */

public:
    enum
    {
        maxCountValue   =   0x7fffffff  ///!< Borrowed from PThreads-win32
    };

/// \name Construction
/// @{
public:
    /// Conversion constructor
    semaphore(synch_handle_type sem, bool_type bTakeOwnership)
        : m_sem(sem)
        , m_maxCount(0)
        , m_bOwnHandle(bTakeOwnership)
    {
        WINSTL_ASSERT(NULL != sem);
    }
    /// Creates an instance of the semaphore
    ss_explicit_k semaphore(count_type initialCount, count_type maxCount = maxCountValue)
        : m_sem(create_semaphore_(NULL, initialCount, maxCount, static_cast<ws_char_a_t const*>(NULL)))
        , m_maxCount(maxCount)
        , m_bOwnHandle(true)
    {}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    // This disambiguates cases where the initial count is 0
    ss_explicit_k semaphore(int initialCount, count_type maxCount = maxCountValue)
        : m_sem(create_semaphore_(NULL, static_cast<count_type>(initialCount), maxCount, static_cast<ws_char_a_t const*>(NULL)))
        , m_maxCount(maxCount)
        , m_bOwnHandle(true)
    {}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// Creates an instance of the semaphore
    ss_explicit_k semaphore(ws_char_a_t const* name, count_type initialCount, count_type maxCount = maxCountValue)
        : m_sem(create_semaphore_(NULL, initialCount, maxCount, name))
        , m_maxCount(maxCount)
        , m_bOwnHandle(true)
    {}
    /// Creates an instance of the semaphore
    ss_explicit_k semaphore(ws_char_w_t const* name, count_type initialCount, count_type maxCount = maxCountValue)
        : m_sem(create_semaphore_(NULL, initialCount, maxCount, name))
        , m_maxCount(maxCount)
        , m_bOwnHandle(true)
    {}
    /// Creates an instance of the semaphore
    ss_explicit_k semaphore(ws_char_a_t const* name, LPSECURITY_ATTRIBUTES psa, count_type initialCount, count_type maxCount = maxCountValue)
        : m_sem(create_semaphore_(psa, initialCount, maxCount, name))
        , m_maxCount(maxCount)
        , m_bOwnHandle(true)
    {}
    /// Creates an instance of the semaphore
    ss_explicit_k semaphore(ws_char_w_t const* name, LPSECURITY_ATTRIBUTES psa, count_type initialCount, count_type maxCount = maxCountValue)
        : m_sem(create_semaphore_(psa, initialCount, maxCount, name))
        , m_maxCount(maxCount)
        , m_bOwnHandle(true)
    {}

    /// Destroys an instance of the semaphore
    ~semaphore() STLSOFT_NOEXCEPT
    {
        if (NULL != m_sem &&
            m_bOwnHandle)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(m_sem);
        }
    }
private:
    semaphore(class_type const&);       // copy-construction proscribed
    void operator =(class_type const&); // copy-assignment proscribed
/// @}

/// \name Operations
/// @{
public:
    /// Acquires a lock on the semaphore, pending the thread until the lock is acquired
    void lock()
    {
        WINSTL_ASSERT(NULL != m_sem);

        DWORD const dwRes = WINSTL_API_EXTERNAL_Synchronization_WaitForSingleObject(m_sem, INFINITE);

        if (WAIT_OBJECT_0 != dwRes)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(wait_failed_logic_exception(e, "semaphore wait failed"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_WaitFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    /// Acquires a lock on the semaphore, pending the thread until the lock is acquired
    bool_type lock(ws_dword_t wait)
    {
        WINSTL_ASSERT(NULL != m_sem);

        DWORD const dwRes = WINSTL_API_EXTERNAL_Synchronization_WaitForSingleObject(m_sem, wait);

        if (WAIT_OBJECT_0 != dwRes &&
            WAIT_TIMEOUT != dwRes)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(wait_failed_logic_exception(e, "semaphore wait failed"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_WaitFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return (dwRes == WAIT_OBJECT_0);
    }
    /// Attempts to lock the semaphore
    ///
    /// \return <b>true</b> if the semaphore was acquired, or <b>false</b> if not
    bool_type try_lock()
    {
        return lock(0);
    }
    /// Releases an acquired lock on the semaphore, increasing the
    ///  semaphore's counter by one.
    ///
    /// \note Equivalent to \link winstl::semaphore::unlock(count_type) unlock()\endlink.
    void unlock()
    {
        WINSTL_ASSERT(NULL != m_sem);

        if (!::ReleaseSemaphore(m_sem, 1, NULL))
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_object_state_change_failed_exception(e, "semaphore release failed", Synchronisation_SemaphoreReleaseFailed));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SemaphoreReleaseFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    /// Releases a number of acquired "locks" on the semaphore,
    ///  increasing the semaphore's counter by the given value.
    ///
    /// \param numLocksToRelease The number by which to increment the
    ///  semaphore's counter. If this is greater than the available
    ///  value, the function fails. (It will throw an exception, if
    ///  exception handling is enabled, or return -1 otherwise.)
    ///
    /// \return Returns the value of the semaphore's counter prior to the
    ///  change effected by the call.
    /// \retval -1 Indicates call failure (only if exception handling is not
    ///  enabled).
    ws_long_t unlock(count_type numLocksToRelease)
    {
        WINSTL_ASSERT(NULL != m_sem);
        WINSTL_ASSERT(numLocksToRelease > 0);
        WINSTL_ASSERT(static_cast<LONG>(numLocksToRelease) > 0);

        LONG    previousCount   =   0;

        if (!::ReleaseSemaphore(m_sem, static_cast<LONG>(numLocksToRelease), &previousCount))
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_object_state_change_failed_exception(e, "semaphore release failed", Synchronisation_SemaphoreReleaseFailed));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SemaphoreReleaseFailed, e);

            return -1;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return static_cast<ws_long_t>(previousCount);
    }
/// @}

/// \name Accessors
/// @{
public:
    /// The underlying kernel object handle
    synch_handle_type handle()
    {
        return m_sem;
    }
    /// The underlying kernel object handle
    synch_handle_type get()
    {
        return m_sem;
    }
/// @}

// Implementation
private:
    static HANDLE CreateSemaphore_A_arguments_adjusted_(
        LPSECURITY_ATTRIBUTES   psa
    ,   underlying_count_type_  initialCount
    ,   underlying_count_type_  maxCount
    ,   ws_char_a_t const*      name
    )
    {
        return STLSOFT_NS_GLOBAL(CreateSemaphoreA)(psa, static_cast<LONG>(initialCount), static_cast<LONG>(maxCount), name);
    }
    static HANDLE CreateSemaphore_W_arguments_adjusted_(
        LPSECURITY_ATTRIBUTES   psa
    ,   underlying_count_type_  initialCount
    ,   underlying_count_type_  maxCount
    ,   ws_char_w_t const*      name
    )
    {
        return STLSOFT_NS_GLOBAL(CreateSemaphoreW)(psa, static_cast<LONG>(initialCount), static_cast<LONG>(maxCount), name);
    }


    static synch_handle_type create_semaphore_(
        LPSECURITY_ATTRIBUTES   psa
    ,   underlying_count_type_  initialCount
    ,   underlying_count_type_  maxCount
    ,   ws_char_a_t const*      name
    )
    {
        WINSTL_MESSAGE_ASSERT("Maximum semaphore count must be > 0", maxCount > 0);
        WINSTL_ASSERT(initialCount <= maxCount);

        synch_handle_type sem = CreateSemaphore_A_arguments_adjusted_(psa, initialCount, maxCount, name);

        if (NULL == sem)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_creation_exception(e, "failed to create kernel semaphore object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectCreationFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return sem;
    }
    static synch_handle_type create_semaphore_(
        LPSECURITY_ATTRIBUTES   psa
    ,   underlying_count_type_  initialCount
    ,   underlying_count_type_  maxCount
    ,   ws_char_w_t const*      name
    )
    {
        WINSTL_MESSAGE_ASSERT("Maximum semaphore count must be > 0", maxCount > 0);
        WINSTL_ASSERT(initialCount <= maxCount);

        synch_handle_type sem = CreateSemaphore_W_arguments_adjusted_(psa, initialCount, maxCount, name);

        if (NULL == sem)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_creation_exception(e, "failed to create kernel semaphore object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectCreationFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return sem;
    }

// Members
private:
    synch_handle_type   m_sem;          // The underlying semaphore object
    count_type const    m_maxCount;     // Record of the maximum counter value
    bool_type const     m_bOwnHandle;   // Does the instance own the handle?
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** Overload of the form of the winstl::get_synch_handle() shim for
 *    the winstl::semaphore type.
 *
 * \param sem The winstl::semaphore instance
 *
 * \retval The synchronisation handle of \c sem
 */
inline HANDLE get_synch_handle(semaphore &sem)
{
    return sem.get();
}

/** Overload of the form of the winstl::get_kernel_handle() shim for
 *    the winstl::semaphore type.
 *
 * \ingroup group__library__Shims_Attribute_Windows_KernelHandle
 *
 * \param sem The winstl::semaphore instance
 *
 * \retval The synchronisation handle of \c sem
 */
inline HANDLE get_kernel_handle(semaphore &sem)
{
    return sem.get();
}


#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/** This \ref group__concept__Shim "control shim" acquires a lock on the given semaphore
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param sem The semaphore on which to acquire the lock.
 */
inline void lock_instance(WINSTL_NS_QUAL(semaphore) &sem)
{
    sem.lock();
}

/** This \ref group__concept__Shim "control shim" releases a lock on the given semaphore
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param sem The semaphore on which to release the lock
 */
inline void unlock_instance(WINSTL_NS_QUAL(semaphore) &sem)
{
    sem.unlock();
}

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
/** Traits for the semaphore class
 *
 * \ingroup group__library__Synch
 */
struct semaphore_lock_traits
{
public:
    /// The lockable type
    typedef semaphore                lock_type;
    /// This type
    typedef semaphore_lock_traits    class_type;

// Operations
public:
    /// Lock the given semaphore instance
    static void lock(semaphore &c)
    {
        lock_instance(c);
    }

    /// Unlock the given semaphore instance
    static void unlock(semaphore &c)
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_SEMAPHORE */

/* ///////////////////////////// end of file //////////////////////////// */

