/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/Synchronisation_status_code.h
 *
 * Purpose:     Definition of the Synchronisation_status_code enumeration.
 *
 * Created:     13th May 2014
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2014-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/Synchronisation_status_code.h
 *
 * \brief [C, C++] Definition of the Synchronisation_status_code enumeration
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE
#define WINSTL_INCL_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE_MAJOR    1
# define WINSTL_VER_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE_MINOR    2
# define WINSTL_VER_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE_REVISION 2
# define WINSTL_VER_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE_EDIT     10
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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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
 * typedefs
 */

enum Synchronisation_status_code_t
{
        Synchronisation_Unknown =   0
    ,   Synchronisation_SynchronisationObjectCreationFailed
    ,   Synchronisation_EventSetFailed
    ,   Synchronisation_EventResetFailed
    ,   Synchronisation_MutexReleaseFailed
    ,   Synchronisation_SemaphoreReleaseFailed
    ,   Synchronisation_TssIndexCreationFailed
    ,   Synchronisation_WaitFailed
    ,   Synchronisation_WaitAbandoned
    ,   Synchronisation_WaitOperationInterrupted
    ,   Synchronisation_WaitableTimerSetFailed
    ,   Synchronisation_WaitHandleInvalid
    ,   Synchronisation_WaitHandleDuplicate
    ,   Synchronisation_ThreadNotSuspended
    ,   Synchronisation_ThreadCreateFailed

/* New values must be inserted AFTER this point */

    ,   Synchronisation_SynchronisationObjectOpenFailed

    ,   Synchronisation_reserved_16
    ,   Synchronisation_reserved_17
    ,   Synchronisation_reserved_18
    ,   Synchronisation_reserved_19
    ,   Synchronisation_reserved_20
    ,   Synchronisation_reserved_21
    ,   Synchronisation_reserved_22
    ,   Synchronisation_reserved_23
    ,   Synchronisation_reserved_24
    ,   Synchronisation_reserved_25
    ,   Synchronisation_reserved_26
    ,   Synchronisation_reserved_27
    ,   Synchronisation_reserved_28
    ,   Synchronisation_reserved_29
#if 0
    ,   Synchronisation_
#endif /* 0 */

/* New values must be inserted BEFORE this point */

    ,   Synchronisation_COUNT
    ,   Synchronisation_MAXIMUM =   Synchronisation_COUNT - 1
};

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE */

/* ///////////////////////////// end of file //////////////////////////// */

