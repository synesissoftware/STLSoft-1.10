/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/process_mutex.hpp
 *
 * Purpose:     Inter-process mutex, based on Windows MUTEX.
 *
 * Created:     15th May 2002
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/process_mutex.hpp
 *
 * \brief [C++] Definition of winstl::process_mutex class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX
#define WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_MAJOR    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_MINOR    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_REVISION 2
# define WINSTL_VER_WINSTL_SYNCH_HPP_PROCESS_MUTEX_EDIT     83
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

// class process_mutex
/** This class acts as an inter-process mutex based on the Win32
 *   MUTEX kernel object
 *
 * \ingroup group__library__Synch
 */
class process_mutex
    : public STLSOFT_NS_QUAL(critical_section)< STLSOFT_CRITICAL_SECTION_IS_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_IS_TRYABLE
                                            >
    , public STLSOFT_NS_QUAL(synchronisable_object_tag)
{
/// \name Member Types
/// @{
public:
    /// This type
    typedef process_mutex                                   class_type;
    /// The boolean type
    typedef ws_bool_t                                       bool_type;
    /// The Windows synchronisation handle type
    typedef HANDLE                                          synch_handle_type;
    /// The resource type
    typedef HANDLE                                          resource_type;
/// @}

/// \name Construction
/// @{
public:
    /// Creates an instance of the mutex
    process_mutex()
        : m_mx(create_mutex_(ss_nullptr_k, false, static_cast<ws_char_a_t const*>(0), m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// Conversion constructor, taking control of the native MUTEX handle in
    /// the constructed instance
    ///
    /// \exception noexcept
    process_mutex(resource_type mx, bool_type bTakeOwnership) STLSOFT_NOEXCEPT
        : m_mx(mx)
        , m_bOwnHandle(bTakeOwnership)
        , m_bCreated(false)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {
        WINSTL_ASSERT(ss_nullptr_k != mx);
    }
    /// Creates an instance of the mutex with the given name
    ss_explicit_k process_mutex(ws_char_a_t const* name)
        : m_mx(create_mutex_(ss_nullptr_k, false, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// Creates an instance of the mutex with the given name
    ss_explicit_k process_mutex(ws_char_w_t const* name)
        : m_mx(create_mutex_(ss_nullptr_k, false, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// [DEPRECATED] Creates an instance of the mutex with the given
    /// initial ownership
    ///
    /// \deprecated This method uses a Boolean parameter, which means that
    ///   it reduces transparency when used in client code. It will be
    ///   replaced in a future version of the libraries
    STLSOFT_DECLARE_DEPRECATION()
    ss_explicit_k process_mutex(bool_type bInitialOwer)
        : m_mx(create_mutex_(ss_nullptr_k, bInitialOwer, static_cast<ws_char_a_t const*>(0), m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// [DEPRECATED] Creates an instance of the mutex with the given name
    /// and initial ownership
    ///
    /// \deprecated This method uses a Boolean parameter, which means that
    ///   it reduces transparency when used in client code. It will be
    ///   replaced in a future version of the libraries
    process_mutex(ws_char_a_t const* name, bool_type bInitialOwer)
        : m_mx(create_mutex_(ss_nullptr_k, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// [DEPRECATED] Creates an instance of the mutex with the given name
    /// and initial ownership
    ///
    /// \deprecated This method uses a Boolean parameter, which means that
    ///   it reduces transparency when used in client code. It will be
    ///   replaced in a future version of the libraries
    process_mutex(ws_char_w_t const* name, bool_type bInitialOwer)
        : m_mx(create_mutex_(ss_nullptr_k, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// [DEPRECATED] Creates an instance of the mutex with the given name,
    /// initial ownership, and security attributes
    ///
    /// \deprecated This method uses a Boolean parameter, which means that
    ///   it reduces transparency when used in client code. It will be
    ///   replaced in a future version of the libraries
    process_mutex(ws_char_a_t const* name, bool_type bInitialOwer, LPSECURITY_ATTRIBUTES psa)
        : m_mx(create_mutex_(psa, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// [DEPRECATED] Creates an instance of the mutex with the given name,
    /// initial ownership, and security attributes
    ///
    /// \deprecated This method uses a Boolean parameter, which means that
    ///   it reduces transparency when used in client code. It will be
    ///   replaced in a future version of the libraries
    process_mutex(ws_char_w_t const* name, bool_type bInitialOwer, LPSECURITY_ATTRIBUTES psa)
        : m_mx(create_mutex_(psa, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(ss_nullptr_k)
    {}
    /// Creates an instance of the mutex
    process_mutex(ws_char_a_t const* name, bool_type bInitialOwer, LPSECURITY_ATTRIBUTES psa, HANDLE hevAbandoned)
        : m_mx(create_mutex_(psa, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(hevAbandoned)
    {}
    /// Creates an instance of the mutex
    process_mutex(ws_char_w_t const* name, bool_type bInitialOwer, LPSECURITY_ATTRIBUTES psa, HANDLE hevAbandoned)
        : m_mx(create_mutex_(psa, bInitialOwer, name, m_bCreated))
        , m_bOwnHandle(true)
        , m_bAbandoned(false)
        , m_evAbandoned(hevAbandoned)
    {}

    /// Destroys an instance of the mutex
    ~process_mutex() STLSOFT_NOEXCEPT
    {
        if (ss_nullptr_k != m_mx &&
            m_bOwnHandle)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(m_mx);
        }
    }
private:
    process_mutex(class_type const&);           // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Operations
/// @{
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is acquired
    void lock()
    {
        WINSTL_ASSERT(ss_nullptr_k != m_mx);

        DWORD const dwRes = WINSTL_API_EXTERNAL_Synchronization_WaitForSingleObject(m_mx, INFINITE);

        if (WAIT_ABANDONED == dwRes)
        {
            if (ss_nullptr_k != m_evAbandoned)
            {
                ::SetEvent(m_evAbandoned);
            }

            m_bAbandoned = true;
        }
        else
        {
            m_bAbandoned = false;

            if (WAIT_OBJECT_0 != dwRes)
            {
                DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_THROW_X(wait_failed_logic_exception(e, "mutex wait failed"));
#else
                WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_WaitFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }
    }
    /// Acquires a lock on the mutex, pending the thread until the lock is acquired
    bool_type lock(ws_dword_t wait)
    {
        WINSTL_ASSERT(ss_nullptr_k != m_mx);

        DWORD const dwRes = WINSTL_API_EXTERNAL_Synchronization_WaitForSingleObject(m_mx, wait);

        if (WAIT_ABANDONED == dwRes)
        {
            if (ss_nullptr_k != m_evAbandoned)
            {
                ::SetEvent(m_evAbandoned);
            }

            m_bAbandoned = true;

            return true;
        }
        else
        {
            m_bAbandoned = false;

            if (WAIT_TIMEOUT == dwRes)
            {
                return false;
            }
            else
            {
                if (WAIT_OBJECT_0 != dwRes)
                {
                    DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    STLSOFT_THROW_X(wait_failed_logic_exception(e, "mutex wait failed"));
#else
                    WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_WaitFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                }

                return true;
            }
        }
    }
    /// Attempts to lock the mutex
    ///
    /// \return <b>true</b> if the mutex was acquired, or <b>false</b> if not
    bool_type try_lock()
    {
        return lock(0);
    }
    /// Releases an acquired lock on the mutex
    void unlock()
    {
        WINSTL_ASSERT(ss_nullptr_k != m_mx);

        if (!WINSTL_API_EXTERNAL_Synchronization_ReleaseMutex(m_mx))
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_object_state_change_failed_exception(e, "mutex release failed", Synchronisation_MutexReleaseFailed));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_MutexReleaseFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// The underlying kernel object handle
    resource_type handle() STLSOFT_NOEXCEPT
    {
        return m_mx;
    }
    /// The underlying kernel object handle
    resource_type get() STLSOFT_NOEXCEPT
    {
        return m_mx;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether this object instance created the underlying mutex object
    ///
    /// \return true The mutex object was created by this instance
    /// \return false The mutex object was not created by this instance
    /// \note For unnamed mutexes this will always be false
    bool_type created() const STLSOFT_NOEXCEPT
    {
        return m_bCreated;
    }

    /// Indicates whether a successful call to lock occurred because the underlying
    /// mutex was previously held by a thread that abandoned.
    ///
    /// \return true The mutex object was abandoned by its previous owning thread
    /// \return false The mutex object was not abandoned by its previous owning thread
    /// \note This attribute is meaningful with respect to the result of the last call to lock() or try_lock(). Subsequent calls to unlock() do not affect this attribute.
    bool_type abandoned() const STLSOFT_NOEXCEPT
    {
        return m_bAbandoned;
    }
/// @}

/// \name Implementation
/// @{
private:
    static HANDLE create_mutex_(LPSECURITY_ATTRIBUTES psa, bool_type bInitialOwner, ws_char_a_t const* name, bool_type &bCreated)
    {
        HANDLE const mx = WINSTL_API_EXTERNAL_Synchronization_CreateMutexA(psa, bInitialOwner, name);

        if (ss_nullptr_k == mx)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_creation_exception(e, "failed to create kernel mutex object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectCreationFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != ss_nullptr_k && WINSTL_API_EXTERNAL_ErrorHandling_GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }
    static HANDLE create_mutex_(LPSECURITY_ATTRIBUTES psa, bool_type bInitialOwner, ws_char_w_t const* name, bool_type &bCreated)
    {
        HANDLE const mx = WINSTL_API_EXTERNAL_Synchronization_CreateMutexW(psa, bInitialOwner, name);

        if (ss_nullptr_k == mx)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_creation_exception(e, "failed to create kernel mutex object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectCreationFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != ss_nullptr_k && WINSTL_API_EXTERNAL_ErrorHandling_GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }
    static HANDLE open_mutex_(ws_dword_t access, bool_type bInheritHandle, ws_char_a_t const* name, bool_type &bCreated)
    {
        HANDLE const mx = WINSTL_API_EXTERNAL_Synchronization_OpenMutexA(access, bInheritHandle, name);

        if (ss_nullptr_k == mx)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_open_exception(e, "failed to open kernel mutex object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectOpenFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != ss_nullptr_k && WINSTL_API_EXTERNAL_ErrorHandling_GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }
    static HANDLE open_mutex_(ws_dword_t access, bool_type bInheritHandle, ws_char_w_t const* name, bool_type &bCreated)
    {
        HANDLE const mx = WINSTL_API_EXTERNAL_Synchronization_OpenMutexW(access, bInheritHandle, name);

        if (ss_nullptr_k == mx)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_open_exception(e, "failed to open kernel mutex object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectOpenFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        bCreated = (mx != ss_nullptr_k && WINSTL_API_EXTERNAL_ErrorHandling_GetLastError() != ERROR_ALREADY_EXISTS);

        return mx;
    }
/// @}

/// \name Fields
/// @{
private:
    resource_type   m_mx;           // The underlying mutex object
    bool_type const m_bOwnHandle;   // Does the instance own the handle?
    bool_type       m_bCreated;     // Did this object (thread) create the underlying mutex object?
    bool_type       m_bAbandoned;   // Did the previous owner abandon the underlying mutex object?
    resource_type   m_evAbandoned;  // Optional event that is signalled if the muted is abandoned
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * attribute shims
 */

/** Overload of the form of the winstl::get_synch_handle() shim for
 *    the winstl::process_mutex type.
 *
 * \param mx The winstl::process_mutex instance
 *
 * \retval The synchronisation handle of \c mx
 */
inline
HANDLE
get_synch_handle(
    process_mutex& mx
)
{
    return mx.get();
}

/** Overload of the form of the winstl::get_kernel_handle() shim for
 *    the winstl::process_mutex type.
 *
 * \ingroup group__library__Shims_Attribute_Windows_KernelHandle
 *
 * \param mx The winstl::process_mutex instance
 *
 * \retval The synchronisation handle of \c mx
 */
inline
HANDLE
get_kernel_handle(
    process_mutex& mx
)
{
    return mx.get();
}

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
    WINSTL_NS_QUAL(process_mutex)& mx
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
    WINSTL_NS_QUAL(process_mutex)& mx
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
/** Traits for the process_mutex class
 *
 * \ingroup group__library__Synch
 */
struct process_mutex_lock_traits
{
public:
    /// The lockable type
    typedef process_mutex                lock_type;
    /// This type
    typedef process_mutex_lock_traits    class_type;

// Operations
public:
    /// Lock the given process_mutex instance
    static void lock(process_mutex &c)
    {
        lock_instance(c);
    }

    /// Unlock the given process_mutex instance
    static void unlock(process_mutex &c)
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_PROCESS_MUTEX */

/* ///////////////////////////// end of file //////////////////////////// */

