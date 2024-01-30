/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/synch/util/windows_api_.h
 *
 * Purpose:     Discrimination of synchronisation features.
 *
 * Created:     3rd January 2017
 * Updated:     22nd January 2024
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


/** \file stlsoft/synch/util/windows_api_.h
 *
 * \brief [INTERNAL] Discrimination of synchronisation features
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_UTIL_H_WINDOWS_API_
#define STLSOFT_INCL_STLSOFT_SYNCH_UTIL_H_WINDOWS_API_

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYNCH_UTIL_H_WINDOWS_API__MAJOR    1
# define STLSOFT_VER_STLSOFT_SYNCH_UTIL_H_WINDOWS_API__MINOR    2
# define STLSOFT_VER_STLSOFT_SYNCH_UTIL_H_WINDOWS_API__REVISION 3
# define STLSOFT_VER_STLSOFT_SYNCH_UTIL_H_WINDOWS_API__EDIT     9
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

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/* (|__)declspec */

# if 0
# elif defined(STLSOFT_CF_SUPPORT___declspec)

#  if 0
#  elif defined(STLSOFT_COMPILER_IS_BORLAND) &&\
        __BORLANDC__ <= 0x0550
#   define STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_    __declspec(__dllimport)
#  else
#   define STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_    __declspec(dllimport)
#  endif
# else
#   define STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_
# endif

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Windows API declarations
 */

#ifndef WINAPI

# ifdef __cplusplus
extern "C" {
# endif

/* /////////////////////////////////////
 * 64-bit architecture
 */

# if defined(_WIN64)

/* /////////////////////////////////////
 * 64-bit interlocked API functions
 */

/* InterlockedDecrement64 */
#  if 0
__int64
InterlockedDecrement64(
    __int64 volatile*
);
#  else
__int64
_InterlockedDecrement64(
    __int64 volatile *
);
#   pragma intrinsic(_InterlockedDecrement64)
#   define InterlockedDecrement64                           _InterlockedDecrement64
#  endif


/* InterlockedExchange64 */
#  if 0
__int64
InterlockedExchange64(
    __int64 volatile*
,   __int64
);
#  else
__int64
_InterlockedExchange64(
    __int64 volatile *
,   __int64
);
#   pragma intrinsic(_InterlockedExchange64)
#   define InterlockedExchange64                            _InterlockedExchange64
#  endif


/* InterlockedExchangeAdd64 */
#  if 0
__int64
InterlockedExchangeAdd64(
    __int64 volatile*
,   __int64
);
#  else
__int64
_InterlockedExchangeAdd64(
    __int64 volatile *
,   __int64
);
#   pragma intrinsic(_InterlockedExchangeAdd64)
#   define InterlockedExchangeAdd64                         _InterlockedExchangeAdd64
#  endif


/* InterlockedIncrement64 */
#  if 0
__int64
InterlockedIncrement64(
    __int64 volatile*
);
#  else
__int64
_InterlockedIncrement64(
    __int64 volatile *
);
#   pragma intrinsic(_InterlockedIncrement64)
#   define InterlockedIncrement64                           _InterlockedIncrement64
#  endif

/* /////////////////////////////////////
 * 32-bit interlocked API functions (in 64-bit)
 */

/* InterlockedDecrement */
#  if 0
long
InterlockedDecrement(
    long volatile*
);
#  else
long
_InterlockedDecrement(
    long volatile *
);
#   pragma intrinsic(_InterlockedDecrement)
#   define InterlockedDecrement                             _InterlockedDecrement
#  endif


/* InterlockedExchange */
#  if 0
long
InterlockedExchange(
    long volatile*
,   long
);
#  else
long
_InterlockedExchange(
    long volatile *
,   long
);
#   pragma intrinsic(_InterlockedExchange)
#   define InterlockedExchange                              _InterlockedExchange
#  endif


/* InterlockedExchangeAdd */
#  if 0
long
InterlockedExchangeAdd(
    long volatile*
,   long
);
#  else
long
_InterlockedExchangeAdd(
    long volatile *
,   long
);
#   pragma intrinsic(_InterlockedExchangeAdd)
#   define InterlockedExchangeAdd                           _InterlockedExchangeAdd
#  endif


/* InterlockedIncrement */
#  if 0
long
InterlockedIncrement(
    long volatile*
);
#  else
long
_InterlockedIncrement(
    long volatile *
);
#   pragma intrinsic(_InterlockedIncrement)
#   define InterlockedIncrement                             _InterlockedIncrement
#  endif
#endif

/* /////////////////////////////////////
 * 32-bit interlocked API functions
 */

# if defined(_WIN32) && \
     !defined(_WIN64)

STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_
long
STLSOFT_STDCALL
InterlockedDecrement(
    long volatile*
);

STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_
long
STLSOFT_STDCALL
InterlockedExchange(
    long volatile*
,   long
);

STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_
long
STLSOFT_STDCALL
InterlockedExchangeAdd(
    long volatile*
,   long
);

STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_
long
STLSOFT_STDCALL
InterlockedIncrement(
    long volatile*
);
# endif

/* /////////////////////////////////////
 * misc
 */

/* Sleep */
STLSOFT_INTERNAL_SYNCH_WindowsAPI_declimport_
void
STLSOFT_STDCALL
Sleep(
    unsigned long
);


# ifdef __cplusplus
} /* extern "C" */
# endif

#endif

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_UTIL_H_WINDOWS_API_ */

/* ///////////////////////////// end of file //////////////////////////// */

