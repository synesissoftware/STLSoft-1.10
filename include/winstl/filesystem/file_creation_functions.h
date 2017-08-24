/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/file_creation_functions.h
 *
 * Purpose:     File creation functions.
 *
 * Created:     12th September 2005
 * Updated:     24th August 2017
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2017, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/file_creation_functions.h
 *
 * \brief [C, C++] File creation functions
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_MAJOR      2
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_MINOR      1
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_REVISION   1
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_EDIT       23
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_FileManagement
# include <winstl/api/external/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_FileManagement */

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
 * C functions
 */

/** [DEPRECATED] Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
STLSOFT_INLINE HANDLE winstl__open_file_read_shared_a(ws_char_a_t const* fileName, DWORD dwShareMode)
{
    return WINSTL_API_EXTERNAL_FileManagement_CreateFileA(fileName, GENERIC_READ, dwShareMode, NULL, OPEN_ALWAYS, 0, NULL);
}

/** [DEPRECATED] Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
STLSOFT_INLINE HANDLE winstl__open_file_read_shared_w(ws_char_w_t const* fileName, DWORD dwShareMode)
{
    return WINSTL_API_EXTERNAL_FileManagement_CreateFileW(fileName, GENERIC_READ, dwShareMode, NULL, OPEN_ALWAYS, 0, NULL);
}

/** [DEPRECATED] Opens an existing file for exclusive read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
STLSOFT_INLINE HANDLE winstl__open_file_exclusive_a(ws_char_a_t const* fileName)
{
    return WINSTL_API_EXTERNAL_FileManagement_CreateFileA(fileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, 0, NULL);
}

/** [DEPRECATED] Opens an existing file for exclusive read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
STLSOFT_INLINE HANDLE winstl__open_file_exclusive_w(ws_char_w_t const* fileName)
{
    return WINSTL_API_EXTERNAL_FileManagement_CreateFileW(fileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, 0, NULL);
}



/** Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 */
STLSOFT_INLINE
HANDLE
winstl_C_open_existing_file_for_read_with_sharemode_m(
    ws_char_a_t const*      path
,   DWORD                   shareMode
)
{
    return WINSTL_API_EXTERNAL_FileManagement_CreateFileA(path, GENERIC_READ, shareMode, NULL, OPEN_EXISTING, 0, NULL);
}

/** Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 */
STLSOFT_INLINE
HANDLE
winstl_C_open_existing_file_for_read_with_sharemode_w(
    ws_char_w_t const*      path
,   DWORD                   shareMode
)
{
    return WINSTL_API_EXTERNAL_FileManagement_CreateFileW(path, GENERIC_READ, shareMode, NULL, OPEN_EXISTING, 0, NULL);
}

#ifdef UNICODE

# define winstl_C_open_existing_file_for_read_with_sharemode    winstl_C_open_existing_file_for_read_with_sharemode_w
#else /* ? UNICODE */

# define winstl_C_open_existing_file_for_read_with_sharemode    winstl_C_open_existing_file_for_read_with_sharemode_m
#endif /* UNICODE */


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

#ifdef __cplusplus

/** [DEPRECATED] Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
inline HANDLE open_file_read_shared(ws_char_a_t const* fileName, DWORD dwShareMode)
{
    return winstl__open_file_read_shared_a(fileName, dwShareMode);
}
/** [DEPRECATED] Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
inline HANDLE open_file_read_shared(ws_char_w_t const* fileName, DWORD dwShareMode)
{
    return winstl__open_file_read_shared_w(fileName, dwShareMode);
}

/** [DEPRECATED] Opens an existing file for exclusive read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
inline HANDLE open_file_exclusive(ws_char_a_t const* fileName)
{
    return winstl__open_file_exclusive_a(fileName);
}
/** [DEPRECATED] Opens an existing file for exclusive read access.
 *
 * \ingroup group__library__FileSystem
 *
 * \deprecated This function is deprecated because it always creates the
 *   file
 */
inline HANDLE open_file_exclusive(ws_char_w_t const* fileName)
{
    return winstl__open_file_exclusive_w(fileName);
}




/** Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 */
inline
HANDLE
open_existing_file_for_read_with_sharemode(
    ws_char_a_t const*      path
,   DWORD                   shareMode
)
{
    return winstl_C_open_existing_file_for_read_with_sharemode_m(path, shareMode);
}

/** Opens an existing file for shared read access.
 *
 * \ingroup group__library__FileSystem
 */
inline
HANDLE
open_existing_file_for_read_with_sharemode(
    ws_char_w_t const*      path
,   DWORD                   shareMode
)
{
    return winstl_C_open_existing_file_for_read_with_sharemode_w(path, shareMode);
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

#endif /* !WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
