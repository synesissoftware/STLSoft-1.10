/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/internal/FileManagement.h
 *
 * Purpose:     Internal preprocessor aliases for internal Windows' File
 *              Management Functions API.
 *
 * Created:     13th October 2019
 * Updated:     30th November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2019, Matthew Wilson and Synesis Software
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

#ifndef WINSTL_INCL_WINSTL_API_internal_h_FileManagement
#define WINSTL_INCL_WINSTL_API_internal_h_FileManagement

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_FileManagement
# include <winstl/api/external/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_FileManagement */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

/* /////////////////////////////////////////////////////////////////////////
 * Windows' File Management Functions
 */


STLSOFT_INLINE
HANDLE
WINSTL_API_INTERNAL_FileManagement_CreateFileA(
    LPCSTR                  path
,   DWORD                   desiredAccess
,   DWORD                   shareMode
,   LPSECURITY_ATTRIBUTES   securityAttributes
,   DWORD                   creationDisposition
,   DWORD                   flagsAndAttributes
,   HANDLE                  templateFile
) STLSOFT_NOEXCEPT
{
    WINSTL_ASSERT(
        CREATE_NEW          == creationDisposition ||
        CREATE_ALWAYS       == creationDisposition ||
        OPEN_EXISTING       == creationDisposition ||
        OPEN_ALWAYS         == creationDisposition ||
        TRUNCATE_EXISTING   == creationDisposition
    );

    return WINSTL_API_EXTERNAL_FileManagement_CreateFileA(
        path
    ,   desiredAccess
    ,   shareMode
    ,   securityAttributes
    ,   creationDisposition
    ,   flagsAndAttributes
    ,   templateFile
    );
}

STLSOFT_INLINE
HANDLE
WINSTL_API_INTERNAL_FileManagement_CreateFileW(
    LPCWSTR                 path
,   DWORD                   desiredAccess
,   DWORD                   shareMode
,   LPSECURITY_ATTRIBUTES   securityAttributes
,   DWORD                   creationDisposition
,   DWORD                   flagsAndAttributes
,   HANDLE                  templateFile
) STLSOFT_NOEXCEPT
{
    WINSTL_ASSERT(
        CREATE_NEW          == creationDisposition ||
        CREATE_ALWAYS       == creationDisposition ||
        OPEN_EXISTING       == creationDisposition ||
        OPEN_ALWAYS         == creationDisposition ||
        TRUNCATE_EXISTING   == creationDisposition
    );

    return WINSTL_API_EXTERNAL_FileManagement_CreateFileW(
        path
    ,   desiredAccess
    ,   shareMode
    ,   securityAttributes
    ,   creationDisposition
    ,   flagsAndAttributes
    ,   templateFile
    );
}

STLSOFT_INLINE
DWORD
WINSTL_API_INTERNAL_FileManagement_GetFullPathNameW(
    LPCWSTR lpFileName
,   DWORD   nBufferLength
,   LPWSTR  lpBuffer
,   LPWSTR* lpFilePart
)
{
    WINSTL_ASSERT(NULL != lpFileName);

    if (0 == STLSOFT_NS_GLOBAL(lstrcmpW)(L"\\\\?\\.", lpFileName) ||
        0 == STLSOFT_NS_GLOBAL(lstrcmpW)(L"\\\\?\\.\\", lpFileName))
    {
        return WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameW(L".", nBufferLength, lpBuffer, lpFilePart);
    }

    return WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart);
}

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_internal_h_FileManagement */

/* ///////////////////////////// end of file //////////////////////////// */

