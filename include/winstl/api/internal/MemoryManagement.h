/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/internal/MemoryManagement.h
 *
 * Purpose:     Internal preprocessor aliases for internal Windows' Memory
 *              Management Functions API.
 *
 * Created:     18th July 2014
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


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef WINSTL_INCL_WINSTL_API_internal_h_MemoryManagement
#define WINSTL_INCL_WINSTL_API_internal_h_MemoryManagement

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_MemoryManagement
# include <winstl/api/external/MemoryManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_MemoryManagement */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

/* /////////////////////////////////////////////////////////////////////////
 * Windows' Memory Management Functions
 */


/* *************************************
 * General Memory functions
 */



/* *************************************
 * Data Execution Prevention functions
 */


/* *************************************
 * File Mapping functions
 */

STLSOFT_INLINE
HANDLE
WINSTL_API_INTERNAL_MemoryManagement_CreateFileMappingA(
    HANDLE                              hFile
,   LPSECURITY_ATTRIBUTES               lpAttributes
,   DWORD                               flProtect
,   WINSTL_NS_QUAL(ws_uint64_t)         maximumSize
,   WINSTL_NS_QUAL(ws_char_a_t) const*  lpName
)
{
    DWORD const mapSizeHi   =   stlsoft_static_cast(DWORD, maximumSize >> 32);
    DWORD const mapSizeLo   =   stlsoft_static_cast(DWORD, maximumSize);

    return WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingA(hFile, lpAttributes, flProtect, mapSizeHi, mapSizeLo, lpName);
}

STLSOFT_INLINE
HANDLE
WINSTL_API_INTERNAL_MemoryManagement_CreateFileMappingW(
    HANDLE                              hFile
,   LPSECURITY_ATTRIBUTES               lpAttributes
,   DWORD                               flProtect
,   WINSTL_NS_QUAL(ws_uint64_t)         maximumSize
,   WINSTL_NS_QUAL(ws_char_w_t) const*  lpName
)
{
    DWORD const mapSizeHi   =   stlsoft_static_cast(DWORD, maximumSize >> 32);
    DWORD const mapSizeLo   =   stlsoft_static_cast(DWORD, maximumSize);

    return WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingW(hFile, lpAttributes, flProtect, mapSizeHi, mapSizeLo, lpName);
}


STLSOFT_INLINE
LPVOID
WINSTL_API_INTERNAL_MemoryManagement_MapViewOfFile(
    HANDLE                      hFileMappingObject
,   DWORD                       dwDesiredAccess
,   WINSTL_NS_QUAL(ws_uint64_t) fileOffset
,   SIZE_T                      dwNumberOfBytesToMap
)
{
    DWORD const fileOffsetHigh  =   STLSOFT_STATIC_CAST(DWORD, fileOffset >> 32);
    DWORD const fileOffsetLow   =   STLSOFT_STATIC_CAST(DWORD, fileOffset);

    return WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFile(hFileMappingObject, dwDesiredAccess, fileOffsetHigh, fileOffsetLow, dwNumberOfBytesToMap);
}

STLSOFT_INLINE
LPVOID
WINSTL_API_INTERNAL_MemoryManagement_MapViewOfFileEx(
    HANDLE                      hFileMappingObject
,   DWORD                       dwDesiredAccess
,   WINSTL_NS_QUAL(ws_uint64_t) fileOffset
,   SIZE_T                      dwNumberOfBytesToMap
,   LPVOID                      lpBaseAddress
)
{
    DWORD const fileOffsetHigh  =   STLSOFT_STATIC_CAST(DWORD, fileOffset >> 32);
    DWORD const fileOffsetLow   =   STLSOFT_STATIC_CAST(DWORD, fileOffset);

    return WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, fileOffsetHigh, fileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress);
}

/* *************************************
 * AWE functions
 */



/* *************************************
 * Heap functions
 */



/* *************************************
 * Virtual Memory functions
 */



/* *************************************
 * Global and Local functions
 */



/* *************************************
 * Bad Memory functions
 */


/* *************************************
 * Enclave functions
 */


/* *************************************
 * Obsolete functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_internal_h_MemoryManagement */

/* ///////////////////////////// end of file //////////////////////////// */

