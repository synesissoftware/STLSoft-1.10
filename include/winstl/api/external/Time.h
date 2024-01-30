/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/external/Time.h
 *
 * Purpose:     External preprocessor aliases for external Windows' Time
 *              Functions API.
 *
 * Created:     29th October 2016
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2016-2019, Matthew Wilson and Synesis Software
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


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Time
#define WINSTL_INCL_WINSTL_API_external_h_Time

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

/* /////////////////////////////////////////////////////////////////////////
 * Windows' System Information Functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * FILETIME functions
 */

#ifndef WINSTL_API_EXTERNAL_Time_CompareFileTime
# define WINSTL_API_EXTERNAL_Time_CompareFileTime           STLSOFT_NS_GLOBAL_(CompareFileTime)
#endif /* !WINSTL_API_EXTERNAL_Time_CompareFileTime */

#ifndef WINSTL_API_EXTERNAL_Time_FileTimeToLocalFileTime
# define WINSTL_API_EXTERNAL_Time_FileTimeToLocalFileTime   STLSOFT_NS_GLOBAL_(FileTimeToLocalFileTime)
#endif /* !WINSTL_API_EXTERNAL_Time_FileTimeToLocalFileTime */

#ifndef WINSTL_API_EXTERNAL_Time_FileTimeToSystemTime
# define WINSTL_API_EXTERNAL_Time_FileTimeToSystemTime      STLSOFT_NS_GLOBAL_(FileTimeToSystemTime)
#endif /* !WINSTL_API_EXTERNAL_Time_FileTimeToSystemTime */

#ifndef WINSTL_API_EXTERNAL_Time_GetFileTime
# define WINSTL_API_EXTERNAL_Time_GetFileTime               STLSOFT_NS_GLOBAL_(GetFileTime)
#endif /* !WINSTL_API_EXTERNAL_Time_GetFileTime */

#ifndef WINSTL_API_EXTERNAL_Time_GetFileTimeAsSystemTime
# define WINSTL_API_EXTERNAL_Time_GetFileTimeAsSystemTime   STLSOFT_NS_GLOBAL_(GetFileTimeAsSystemTime)
#endif /* !WINSTL_API_EXTERNAL_Time_GetFileTimeAsSystemTime */

#ifndef WINSTL_API_EXTERNAL_Time_LocalTimeToFileTime
# define WINSTL_API_EXTERNAL_Time_LocalTimeToFileTime       STLSOFT_NS_GLOBAL_(LocalTimeToFileTime)
#endif /* !WINSTL_API_EXTERNAL_Time_LocalTimeToFileTime */

#ifndef WINSTL_API_EXTERNAL_Time_SetFileTime
# define WINSTL_API_EXTERNAL_Time_SetFileTime               STLSOFT_NS_GLOBAL_(SetFileTime)
#endif /* !WINSTL_API_EXTERNAL_Time_SetFileTime */

#ifndef WINSTL_API_EXTERNAL_Time_SystemTimeToFileTime
# define WINSTL_API_EXTERNAL_Time_SystemTimeToFileTime      STLSOFT_NS_GLOBAL_(SystemTimeToFileTime)
#endif /* !WINSTL_API_EXTERNAL_Time_SystemTimeToFileTime */

/* *************************************
 * MS-DOS Date and Time functions
 */

#ifndef WINSTL_API_EXTERNAL_Time_DosDateTimeToFileTime
# define WINSTL_API_EXTERNAL_Time_DosDateTimeToFileTime     STLSOFT_NS_GLOBAL_(DosDateTimeToFileTime)
#endif /* !WINSTL_API_EXTERNAL_Time_DosDateTimeToFileTime */

#ifndef WINSTL_API_EXTERNAL_Time_FileTimeToDosDateTime
# define WINSTL_API_EXTERNAL_Time_FileTimeToDosDateTime     STLSOFT_NS_GLOBAL_(FileTimeToDosDateTime)
#endif /* !WINSTL_API_EXTERNAL_Time_FileTimeToDosDateTime */


/* *************************************
 * Windows Time functions
 */

#ifndef WINSTL_API_EXTERNAL_Time_GetSystemTime
# define WINSTL_API_EXTERNAL_Time_GetSystemTime             STLSOFT_NS_GLOBAL_(GetSystemTime)
#endif /* !WINSTL_API_EXTERNAL_Time_GetSystemTime  */

#ifndef WINSTL_API_EXTERNAL_Time_GetTickCount
# define WINSTL_API_EXTERNAL_Time_GetTickCount              STLSOFT_NS_GLOBAL_(GetTickCount)
#endif /* !WINSTL_API_EXTERNAL_Time_GetTickCount */

#if WINSTL_WIN32_WINNT >= 0x0400
# ifndef WINSTL_API_EXTERNAL_Time_GetTickCount64
#  define WINSTL_API_EXTERNAL_Time_GetTickCount64           STLSOFT_NS_GLOBAL_(GetTickCount64)
# endif /* !WINSTL_API_EXTERNAL_Time_GetTickCount64 */
#endif


/* *************************************
 * High-resolution Performace Counter functions
 */

#ifndef WINSTL_API_EXTERNAL_Time_QueryPerformanceCounter
# define WINSTL_API_EXTERNAL_Time_QueryPerformanceCounter   STLSOFT_NS_GLOBAL_(QueryPerformanceCounter)
#endif /* !WINSTL_API_EXTERNAL_Time_QueryPerformanceCounter */

#ifndef WINSTL_API_EXTERNAL_Time_QueryPerformanceFrequency
# define WINSTL_API_EXTERNAL_Time_QueryPerformanceFrequency STLSOFT_NS_GLOBAL_(QueryPerformanceFrequency)
#endif /* !WINSTL_API_EXTERNAL_Time_QueryPerformanceFrequency */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* *************************************
 * XXXX functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_external_h_Time */

/* ///////////////////////////// end of file //////////////////////////// */

