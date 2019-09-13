/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/directory_functions.h
 *
 * Purpose:     Directory functions.
 *
 * Created:     29th January 2013
 * Updated:     13th September 2019
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2013-2019, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


/** \file winstl/system/directory_functions.h
 *
 * \brief [C++] Directory functions
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_REVISION    3
# define WINSTL_VER_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_EDIT        9
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
 * functions
 */

STLSOFT_INLINE
ws_size_t
winstl_C_get_home_directory_a(
    ws_char_a_t*    buffer
,   ws_size_t       cchBuffer
)
{
    /* NOTE: assumes that HOMEDRIVE and HOMEPATH can never be larger than _MAX_PATH */

    ws_char_a_t     drive[_MAX_PATH];
    ws_char_a_t     directory[_MAX_PATH];
    DWORD const     cchDrive        =   STLSOFT_NS_GLOBAL(GetEnvironmentVariableA)("HOMEDRIVE", &drive[0], STLSOFT_NUM_ELEMENTS(drive));
    DWORD const     cchDirectory    =   (0 == cchDrive) ? 0 : STLSOFT_NS_GLOBAL(GetEnvironmentVariableA)("HOMEPATH", &directory[0], STLSOFT_NUM_ELEMENTS(directory));
    DWORD const     cchTotal        =   cchDrive + cchDirectory;

    if(0 == cchDirectory)
    {
        return 0;
    }

    if(cchBuffer < 1 + cchTotal)
    {
        if( NULL != buffer &&
            cchBuffer > 0)
        {
            buffer[0] = '\0';
        }

        return 1 + cchTotal;
    }

    memcpy(buffer + 0, drive, sizeof(ws_char_a_t) * cchDrive);
    memcpy(buffer + cchDrive, directory, sizeof(ws_char_a_t) * cchDirectory);
    buffer[cchDrive + cchDirectory] = '\0';

    return cchTotal;
}

STLSOFT_INLINE
ws_size_t
winstl_C_get_home_directory_w(
    ws_char_w_t*    buffer
,   ws_size_t       cchBuffer
)
{
    /* NOTE: assumes that HOMEDRIVE and HOMEPATH can never be larger than _MAX_PATH */

    ws_char_w_t     drive[_MAX_PATH];
    ws_char_w_t     directory[_MAX_PATH];
    DWORD const     cchDrive        =   STLSOFT_NS_GLOBAL(GetEnvironmentVariableW)(L"HOMEDRIVE", &drive[0], STLSOFT_NUM_ELEMENTS(drive));
    DWORD const     cchDirectory    =   (0 == cchDrive) ? 0 : STLSOFT_NS_GLOBAL(GetEnvironmentVariableW)(L"HOMEPATH", &directory[0], STLSOFT_NUM_ELEMENTS(directory));
    DWORD const     cchTotal        =   cchDrive + cchDirectory;

    if(0 == cchDirectory)
    {
        return 0;
    }

    if(cchBuffer < 1 + cchTotal)
    {
        if( NULL != buffer &&
            cchBuffer > 0)
        {
            buffer[0] = '\0';
        }

        return 1 + cchTotal;
    }

    memcpy(buffer + 0, drive, sizeof(ws_char_w_t) * cchDrive);
    memcpy(buffer + cchDrive, directory, sizeof(ws_char_w_t) * cchDirectory);
    buffer[cchDrive + cchDirectory] = '\0';

    return cchTotal;
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#if defined(__cplusplus)

inline
ws_size_t
get_home_directory(
    ws_char_a_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return winstl_C_get_home_directory_a(buffer, cchBuffer);
}

inline
ws_size_t
get_home_directory(
    ws_char_w_t*    buffer
,   ws_size_t       cchBuffer
)
{
    return winstl_C_get_home_directory_w(buffer, cchBuffer);
}

#endif /* __cplusplus */

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

