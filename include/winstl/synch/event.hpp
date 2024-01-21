/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/event.hpp
 *
 * Purpose:     event class, based on Windows EVENT.
 *
 * Created:     3rd July 2003
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/event.hpp
 *
 * \brief [C++] Definition of the winstl::event class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EVENT
#define WINSTL_INCL_WINSTL_SYNCH_HPP_EVENT

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_MAJOR    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_MINOR    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_REVISION 6
# define WINSTL_VER_WINSTL_SYNCH_HPP_EVENT_EDIT     81
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

/** Class which wraps the Win32 EVENT synchronisation object
 *
 * \ingroup group__library__Synch
 */
class event
    : public STLSOFT_NS_QUAL(synchronisable_object_tag)
{
public:
    /// This type
    typedef event           class_type;
    typedef HANDLE          synch_handle_type;

    typedef HANDLE          resource_type;

/// \name Construction
/// @{
public:
    /// Creates the event
    event(ws_bool_t bManualReset, ws_bool_t bInitialState)
        : m_ev(create_event_(NULL, bManualReset, bInitialState, static_cast<ws_char_a_t const*>(0)))
        , m_bOwnHandle(true)
    {}
    /// Creates the event with the given name
    event(ws_char_a_t const* name, ws_bool_t bManualReset, ws_bool_t bInitialState)
        : m_ev(create_event_(NULL, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// Creates the event with the given name
    event(ws_char_w_t const* name, ws_bool_t bManualReset, ws_bool_t bInitialState)
        : m_ev(create_event_(NULL, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// Creates the event with the given name and security attributes
    event(ws_char_a_t const* name, ws_bool_t bManualReset, ws_bool_t bInitialState, LPSECURITY_ATTRIBUTES psa)
        : m_ev(create_event_(psa, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// Creates the event with the given name and security attributes
    event(ws_char_w_t const* name, ws_bool_t bManualReset, ws_bool_t bInitialState, LPSECURITY_ATTRIBUTES psa)
        : m_ev(create_event_(psa, bManualReset, bInitialState, name))
        , m_bOwnHandle(true)
    {}
    /// Destroys the event instance
    ~event() STLSOFT_NOEXCEPT
    {
        if (NULL != m_ev &&
            m_bOwnHandle)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(m_ev);
        }
    }
private:
    event(class_type const&);           // copy-construction proscribed
    void operator =(class_type const&); // copy-assignment proscribed
/// @}

/// \name Operations
/// @{
public:
    /// Sets the state of the event to signalled
    void set()
    {
        WINSTL_ASSERT(NULL != m_ev);

        if (!WINSTL_API_EXTERNAL_Synchronisation_SetEvent(m_ev))
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_object_state_change_failed_exception(e, "event set operation failed", Synchronisation_EventSetFailed));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_EventSetFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    /// Sets the state of the event to signalled
    void reset()
    {
        WINSTL_ASSERT(NULL != m_ev);

        if (!WINSTL_API_EXTERNAL_Synchronisation_ResetEvent(m_ev))
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_object_state_change_failed_exception(e, "event reset operation failed", Synchronisation_EventResetFailed));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_EventResetFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// The underlying kernel object handle
    HANDLE  handle()
    {
        return m_ev;
    }
    /// The underlying kernel object handle
    HANDLE  get()
    {
        return m_ev;
    }
/// @}

// Implementation
private:
    static HANDLE create_event_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bManualReset, ws_bool_t bInitialState, ws_char_a_t const* name)
    {
        HANDLE  h = WINSTL_API_EXTERNAL_Synchronisation_CreateEventA(psa, bManualReset, bInitialState, name);

        if (NULL == h)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_creation_exception(e, "failed to create kernel event object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectCreationFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return h;
    }
    static HANDLE create_event_(LPSECURITY_ATTRIBUTES psa, ws_bool_t bManualReset, ws_bool_t bInitialState, ws_char_w_t const* name)
    {
        HANDLE h = WINSTL_API_EXTERNAL_Synchronisation_CreateEventW(psa, bManualReset, bInitialState, name);

        if (NULL == h)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_creation_exception(e, "failed to create kernel event object"));
#else
            WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(Synchronisation_SynchronisationObjectCreationFailed, e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return h;
    }

// Members
private:
    HANDLE          m_ev;
    const ws_bool_t m_bOwnHandle;   // Does the instance own the handle?
};

/* /////////////////////////////////////////////////////////////////////////
 * attribute shims
 */

/** Overload of the form of the winstl::get_synch_handle() shim for
 *    the winstl::event type.
 *
 * \param ev The winstl::event instance
 *
 * \retval The synchronisation handle of \c ev
 */
inline
HANDLE
get_synch_handle(
    event &ev
)
{
    return ev.get();
}

/** Overload of the form of the winstl::get_kernel_handle() shim for
 *    the winstl::event type.
 *
 * \ingroup group__library__Shims_Attribute_Windows_KernelHandle
 *
 * \param ev The winstl::event instance
 *
 * \retval The synchronisation handle of \c ev
 */
inline
HANDLE
get_kernel_handle(
    event &ev
)
{
    return ev.get();
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

/** This \ref group__concept__Shim "control shim" acquires the given event
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param ev The event to acquire
 */
inline
void
lock_instance(
    WINSTL_NS_QUAL(event) &ev
)
{
    HANDLE h = ev.get();

    DWORD const dwRes = WINSTL_API_EXTERNAL_Synchronization_WaitForSingleObject(h, INFINITE);

    if (WAIT_OBJECT_0 != dwRes)
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(WINSTL_NS_QUAL(wait_failed_logic_exception)(e, "event wait failed"));
#else
        WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(WINSTL_NS_QUAL(Synchronisation_WaitFailed), e);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

/** This \ref group__concept__Shim "control shim" releases the given event
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param ev The event to release
 */
inline
void
unlock_instance(
    WINSTL_NS_QUAL(event) &ev
)
{
    ev.set();
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
/** Traits for the event class
 *
 * \ingroup group__library__Synch
 */
struct event_lock_traits
{
public:
    /// The lockable type
    typedef event                                           lock_type;
    /// This type
    typedef event_lock_traits                               class_type;

// Operations
public:
    /// Lock the given event instance
    static void lock(event &c)
    {
        lock_instance(c);
    }

    /// Unlock the given event instance
    static void unlock(event &c)
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EVENT */

/* ///////////////////////////// end of file //////////////////////////// */

