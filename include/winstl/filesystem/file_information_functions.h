/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/file_information_functions.h
 *
 * Purpose:     File  functions.
 *
 * Created:     7th November 2014
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/filesystem/file_information_functions.h
 *
 * \brief [C, C++] File information functions
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_FILE_INFORMATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_FILE_INFORMATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_FILE_INFORMATION_FUNCTIONS_MAJOR       2
# define WINSTL_VER_WINSTL_H_FILE_INFORMATION_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_H_FILE_INFORMATION_FUNCTIONS_REVISION    4
# define WINSTL_VER_WINSTL_H_FILE_INFORMATION_FUNCTIONS_EDIT        9
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_Authorization
# include <winstl/api/external/Authorization.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Authorization */
#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

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
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
SECURITY_DESCRIPTOR*
WinSTL_C_FileInformation_alloc_(
    ws_size_t   cb
)
{
    return STLSOFT_C_CAST(SECURITY_DESCRIPTOR*, STLSOFT_NS_GLOBAL(HeapAlloc)(STLSOFT_NS_GLOBAL(GetProcessHeap)(), 0, cb));
}

STLSOFT_INLINE
void
WinSTL_C_FileInformation_free_(
    void*       pv
)
{
    STLSOFT_NS_GLOBAL(HeapFree)(STLSOFT_NS_GLOBAL(GetProcessHeap)(), 0, pv);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

STLSOFT_INLINE
void
WinSTL_C_FileInformation_free_SECURITY_DESCRIPTOR(
    SECURITY_DESCRIPTOR*    psd
)
{
    WinSTL_C_FileInformation_free_(psd);
}

STLSOFT_INLINE
BOOL
WinSTL_C_FileInformation_get_SECURITY_DESCRIPTOR_a(
    ws_char_a_t const*      path
,   SECURITY_INFORMATION    si
,   SECURITY_DESCRIPTOR**   ppsd
,   ws_size_t*              pcbsd
)
{
    DWORD       dwSize = 0;
    ws_size_t   dummy;

    WINSTL_ASSERT(NULL != path);
    WINSTL_ASSERT(NULL != ppsd);

    if (NULL == pcbsd)
    {
        pcbsd = &dummy;
    }

    WINSTL_API_EXTERNAL_Authorization_GetFileSecurityA(path, si, NULL, dwSize, &dwSize);

    for (*ppsd = NULL;;)
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        switch (e)
        {
            case    ERROR_INSUFFICIENT_BUFFER:
            case    ERROR_MORE_DATA:
                break;
            default:
                return FALSE;
        }

        *ppsd = WinSTL_C_FileInformation_alloc_(dwSize);

        if (NULL == *ppsd)
        {
            break;
        }

        if (WINSTL_API_EXTERNAL_Authorization_GetFileSecurityA(path, si, *ppsd, dwSize, &dwSize))
        {
            *pcbsd = dwSize;

            return TRUE;
        }

        WinSTL_C_FileInformation_free_(*ppsd);

        *pcbsd = 0;
    }

    return FALSE;
}

STLSOFT_INLINE
BOOL
WinSTL_C_FileInformation_get_SECURITY_DESCRIPTOR_w(
    ws_char_w_t const*      path
,   SECURITY_INFORMATION    si
,   SECURITY_DESCRIPTOR**   ppsd
,   ws_size_t*              pcbsd
)
{
    DWORD       dwSize = 0;
    ws_size_t   dummy;

    WINSTL_ASSERT(NULL != path);
    WINSTL_ASSERT(NULL != ppsd);

    if (NULL == pcbsd)
    {
        pcbsd = &dummy;
    }

    WINSTL_API_EXTERNAL_Authorization_GetFileSecurityW(path, si, NULL, dwSize, &dwSize);

    for (*ppsd = NULL;;)
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        switch (e)
        {
            case    ERROR_INSUFFICIENT_BUFFER:
            case    ERROR_MORE_DATA:
                break;
            default:
                return FALSE;
        }

        *ppsd = WinSTL_C_FileInformation_alloc_(dwSize);

        if (NULL == *ppsd)
        {
            break;
        }

        if (WINSTL_API_EXTERNAL_Authorization_GetFileSecurityW(path, si, *ppsd, dwSize, &dwSize))
        {
            *pcbsd = dwSize;

            return TRUE;
        }

        WinSTL_C_FileInformation_free_(*ppsd);

        *pcbsd = 0;
    }

    return FALSE;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifndef WINSTL_NO_NAMESPACE
namespace file_information
{

inline
void
free_SECURITY_DESCRIPTOR(
    SECURITY_DESCRIPTOR*    psd
)
{
    WinSTL_C_FileInformation_free_SECURITY_DESCRIPTOR(psd);
}

inline
BOOL
get_SECURITY_DESCRIPTOR(
    ws_char_a_t const*      path
,   SECURITY_INFORMATION    si
,   SECURITY_DESCRIPTOR**   ppsd
,   ws_size_t*              pcbsd   =   NULL
)
{
    return WinSTL_C_FileInformation_get_SECURITY_DESCRIPTOR_a(path, si, ppsd, pcbsd);
}

inline
BOOL
get_SECURITY_DESCRIPTOR(
    ws_char_w_t const*      path
,   SECURITY_INFORMATION    si
,   SECURITY_DESCRIPTOR**   ppsd
,   ws_size_t*              pcbsd   =   NULL
)
{
    return WinSTL_C_FileInformation_get_SECURITY_DESCRIPTOR_w(path, si, ppsd, pcbsd);
}

} /* namespace file_information */
#endif /* !WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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

#endif /* WINSTL_INCL_WINSTL_H_FILE_INFORMATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

