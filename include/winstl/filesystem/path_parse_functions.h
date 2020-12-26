/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path_parse_functions.h
 *
 * Purpose:     Utility functions for path parsing.
 *
 * Created:     7th February 2002
 * Updated:     21st December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/path_parse_functions.h
 *
 * \brief [C, C++] Utility functions for path parsing
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_MAJOR      6
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_REVISION   1
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_EDIT       72
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
 * API functions
 */

STLSOFT_INLINE
char const*
winstl_C_find_first_path_name_separator_m(
    char const*     path
)
{
    WINSTL_ASSERT(NULL != path);

    for (; '\0' != *path; ++path)
    {
        switch (*path)
        {
        case '\\':
        case '/':

            return path;
        }
    }

    return ss_nullptr_k;
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_first_path_name_separator_w(
    wchar_t const*  path
)
{
    WINSTL_ASSERT(NULL != path);

    for (; '\0' != *path; ++path)
    {
        switch (*path)
        {
        case '\\':
        case '/':

            return path;
        }
    }

    return ss_nullptr_k;
}

STLSOFT_INLINE
char const*
winstl_C_find_first_path_name_separator_len_m(
    char const*     path
,   size_t          cchPath
)
{
    WINSTL_ASSERT(0 == cchPath || NULL != path);

    for (; 0 != cchPath; --cchPath, ++path)
    {
        switch (*path)
        {
        case '\\':
        case '/':

            return path;
        }
    }

    return NULL;
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_first_path_name_separator_len_w(
    wchar_t const*  path
,   size_t          cchPath
)
{
    WINSTL_ASSERT(0 == cchPath || NULL != path);

    for (; 0 != cchPath; --cchPath, ++path)
    {
        switch (*path)
        {
        case '\\':
        case '/':

            return path;
        }
    }

    return NULL;
}

STLSOFT_INLINE
char const*
winstl_C_find_last_path_name_separator_m(
    char const*     path
)
{
    char const* lastBSlash  =   NULL;
    char const* lastFSlash  =   NULL;

    WINSTL_ASSERT(NULL != path);

    for (; '\0' != *path; ++path)
    {
        switch (*path)
        {
        case '\\':

            lastBSlash  =   path;
            break;
        case '/':

            lastFSlash  =   path;
            break;
        }
    }

    if (NULL == lastFSlash)
    {
        lastFSlash = lastBSlash;
    }
    else if (NULL != lastBSlash)
    {
        if (lastFSlash < lastBSlash)
        {
            lastFSlash = lastBSlash;
        }
    }

    return lastFSlash;
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_last_path_name_separator_w(
    wchar_t const*  path
)
{
    wchar_t const* lastBSlash  =   NULL;
    wchar_t const* lastFSlash  =   NULL;

    WINSTL_ASSERT(NULL != path);

    for (; '\0' != *path; ++path)
    {
        switch (*path)
        {
        case '\\':

            lastBSlash  =   path;
            break;
        case '/':

            lastFSlash  =   path;
            break;
        }
    }

    if (NULL == lastFSlash)
    {
        lastFSlash = lastBSlash;
    }
    else if (NULL != lastBSlash)
    {
        if (lastFSlash < lastBSlash)
        {
            lastFSlash = lastBSlash;
        }
    }

    return lastFSlash;
}

STLSOFT_INLINE
char const*
winstl_C_find_last_path_name_separator_len_m(
    char const*     path
,   size_t          cchPath
)
{
    WINSTL_ASSERT(0 == cchPath || NULL != path);

    for (path += (cchPath - 1); 0 != cchPath; --cchPath, --path)
    {
        switch (*path)
        {
        case '\\':
        case '/':

            return path;
        }
    }

    return NULL;
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_last_path_name_separator_len_w(
    wchar_t const*  path
,   size_t          cchPath
)
{
    WINSTL_ASSERT(0 == cchPath || NULL != path);

    for (path += (cchPath - 1); 0 != cchPath; --cchPath, --path)
    {
        switch (*path)
        {
        case '\\':
        case '/':

            return path;
        }
    }

    return NULL;
}

#ifdef __cplusplus

STLSOFT_INLINE
char const*
winstl_C_find_first_path_name_separator(
    char const*     path
)
{
    return winstl_C_find_first_path_name_separator_m(path);
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_first_path_name_separator(
    wchar_t const*  path
)
{
    return winstl_C_find_first_path_name_separator_w(path);
}

STLSOFT_INLINE
char const*
winstl_C_find_first_path_name_separator_len(
    char const*     path
,   size_t          cchPath
)
{
    return winstl_C_find_first_path_name_separator_len_m(path, cchPath);
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_first_path_name_separator_len(
    wchar_t const*  path
,   size_t          cchPath
)
{
    return winstl_C_find_first_path_name_separator_len_w(path, cchPath);
}

STLSOFT_INLINE
char const*
winstl_C_find_last_path_name_separator(
    char const*     path
)
{
    return winstl_C_find_last_path_name_separator_m(path);
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_last_path_name_separator(
    wchar_t const*  path
)
{
    return winstl_C_find_last_path_name_separator_w(path);
}

STLSOFT_INLINE
char const*
winstl_C_find_last_path_name_separator_len(
    char const*     path
,   size_t          cchPath
)
{
    return winstl_C_find_last_path_name_separator_len_m(path, cchPath);
}

STLSOFT_INLINE
wchar_t const*
winstl_C_find_last_path_name_separator_len(
    wchar_t const*  path
,   size_t          cchPath
)
{
    return winstl_C_find_last_path_name_separator_len_w(path, cchPath);
}
#endif /* __cplusplus */

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

/* /////////////////////////////////////////////////////////////////////////
 * C++ API functions
 */

inline
char const*
find_first_path_name_separator(
    char const*     path
)
{
    return winstl_C_find_first_path_name_separator(path);
}

inline
wchar_t const*
find_first_path_name_separator(
    wchar_t const*  path
)
{
    return winstl_C_find_first_path_name_separator(path);
}


inline
char const*
find_first_path_name_separator(
    char const*     path
,   size_t          cchPath
)
{
    return winstl_C_find_first_path_name_separator_len(path, cchPath);
}

inline
wchar_t const*
find_first_path_name_separator(
    wchar_t const*  path
,   size_t          cchPath
)
{
    return winstl_C_find_first_path_name_separator_len(path, cchPath);
}

inline
char const*
find_last_path_name_separator(
    char const*     path
)
{
    return winstl_C_find_last_path_name_separator(path);
}

inline
wchar_t const*
find_last_path_name_separator(
    wchar_t const*  path
)
{
    return winstl_C_find_last_path_name_separator(path);
}


inline
char const*
find_last_path_name_separator(
    char const*     path
,   size_t          cchPath
)
{
    return winstl_C_find_last_path_name_separator_len(path, cchPath);
}

inline
wchar_t const*
find_last_path_name_separator(
    wchar_t const*  path
,   size_t          cchPath
)
{
    return winstl_C_find_last_path_name_separator_len(path, cchPath);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

