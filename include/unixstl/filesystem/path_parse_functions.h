/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/path_parse_functions.h
 *
 * Purpose:     Utility functions for path parsing.
 *
 * Created:     7th February 2002
 * Updated:     24th December 2020
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


/** \file unixstl/filesystem/path_parse_functions.h
 *
 * \brief [C, C++] Utility functions for path parsing
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_MAJOR    4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_MINOR    0
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_REVISION 2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS_EDIT     62
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

STLSOFT_INLINE
char const*
unixstl_C_find_first_path_name_separator_m(
    char const*     path
)
{
    UNIXSTL_ASSERT(NULL != path);

    for (; '\0' != *path; ++path)
    {
        switch (*path)
        {
#ifdef _WIN32
        case '\\':
#endif
        case '/':

            return path;
        }
    }

    return ss_nullptr_k;
}

STLSOFT_INLINE
char const*
unixstl_C_find_first_path_name_separator_len_m(
    char const*     path
,   size_t          cchPath
)
{
    UNIXSTL_ASSERT(0 == cchPath || NULL != path);

    for (; 0 != cchPath; --cchPath, ++path)
    {
        switch (*path)
        {
#ifdef _WIN32
        case '\\':
#endif
        case '/':

            return path;
        }
    }

    return NULL;
}

STLSOFT_INLINE
char const*
unixstl_C_find_last_path_name_separator_m(
    char const*     path
)
{
    char const* lastBSlash  =   NULL;
    char const* lastFSlash  =   NULL;

    UNIXSTL_ASSERT(NULL != path);

    for (; '\0' != *path; ++path)
    {
        switch (*path)
        {
#ifdef _WIN32
        case '\\':

            lastBSlash  =   path;
            break;
#endif
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
unixstl_C_find_last_path_name_separator_len_m(
    char const*     path
,   size_t          cchPath
)
{
    UNIXSTL_ASSERT(0 == cchPath || NULL != path);

    for (path += (cchPath - 1); 0 != cchPath; --cchPath, --path)
    {
        switch (*path)
        {
#ifdef _WIN32
        case '\\':
#endif
        case '/':

            return path;
        }
    }

    return NULL;
}

#ifdef __cplusplus

STLSOFT_INLINE
char const*
unixstl_C_find_first_path_name_separator(
    char const*     path
)
{
    return unixstl_C_find_first_path_name_separator_m(path);
}

STLSOFT_INLINE
char const*
unixstl_C_find_first_path_name_separator_len(
    char const*     path
,   size_t          cchPath
)
{
    return unixstl_C_find_first_path_name_separator_len_m(path, cchPath);
}

STLSOFT_INLINE
char const*
unixstl_C_find_last_path_name_separator(
    char const*     path
)
{
    return unixstl_C_find_last_path_name_separator_m(path);
}

STLSOFT_INLINE
char const*
unixstl_C_find_last_path_name_separator_len(
    char const*     path
,   size_t          cchPath
)
{
    return unixstl_C_find_last_path_name_separator_len_m(path, cchPath);
}
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{
namespace unixstl_project
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
    return unixstl_C_find_first_path_name_separator(path);
}

inline
char const*
find_first_path_name_separator(
    char const*     path
,   size_t          cchPath
)
{
    return unixstl_C_find_first_path_name_separator_len(path, cchPath);
}

inline
char const*
find_last_path_name_separator(
    char const*     path
)
{
    return unixstl_C_find_last_path_name_separator(path);
}


inline
char const*
find_last_path_name_separator(
    char const*     path
,   size_t          cchPath
)
{
    return unixstl_C_find_last_path_name_separator_len(path, cchPath);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

