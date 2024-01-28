/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/external/HandleAndObject.h
 *
 * Purpose:     External preprocessor aliases for external Windows' Handle
 *              and Object Functions API.
 *
 * Created:     20th August 2017
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2017-2019, Matthew Wilson and Synesis Software
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
#define WINSTL_INCL_WINSTL_API_external_h_HandleAndObject

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
 * Windows' Handle and Object Functions
 */

#ifndef WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle
# define WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle    STLSOFT_NS_GLOBAL_(CloseHandle)
#endif /* !WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle */

#ifndef WINSTL_API_EXTERNAL_HandleAndObject_CompareObjectHandles
# define WINSTL_API_EXTERNAL_HandleAndObject_CompareObjectHandles               STLSOFT_NS_GLOBAL_(CompareObjectHandles)
#endif /* !WINSTL_API_EXTERNAL_HandleAndObject_CompareObjectHandles */

#ifndef WINSTL_API_EXTERNAL_HandleAndObject_DuplicateHandle
# define WINSTL_API_EXTERNAL_HandleAndObject_DuplicateHandle                    STLSOFT_NS_GLOBAL_(DuplicateHandle)
#endif /* !WINSTL_API_EXTERNAL_HandleAndObject_DuplicateHandle */

#ifndef WINSTL_API_EXTERNAL_HandleAndObject_GetHandleInformation
# define WINSTL_API_EXTERNAL_HandleAndObject_GetHandleInformation               STLSOFT_NS_GLOBAL_(GetHandleInformation)
#endif /* !WINSTL_API_EXTERNAL_HandleAndObject_GetHandleInformation */

#ifndef WINSTL_API_EXTERNAL_HandleAndObject_SetHandleInformation
# define WINSTL_API_EXTERNAL_HandleAndObject_SetHandleInformation               STLSOFT_NS_GLOBAL_(SetHandleInformation)
#endif /* !WINSTL_API_EXTERNAL_HandleAndObject_SetHandleInformation */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */

/* ///////////////////////////// end of file //////////////////////////// */

