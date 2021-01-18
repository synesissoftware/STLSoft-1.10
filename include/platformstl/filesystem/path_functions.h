/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/path_functions.h
 *
 * Purpose:     Path manipulation functions.
 *
 * Created:     3rd February 2011
 * Updated:     16th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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


/** \file platformstl/filesystem/path_functions.h
 *
 * \brief [C++] Path manipulation functions
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS

#ifndef PLATFORMSTL_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_MAJOR    2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_MINOR    2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_REVISION 7
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_EDIT     27
#endif /* !PLATFORMSTL_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# include <platformstl/platformstl.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
# include <stlsoft/string/string_slice.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PLATFORMSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
# else
/* Define stlsoft::platformstl_project */
namespace stlsoft
{
namespace platformstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !PLATFORMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Elicits a multibyte slice to the part of the given path representing the
 * executable name, including removal of program extension on Windows.
 *
 * \param path A full or partial path. May be nullptr or empty string
 *
 * \return A slice representing the executable part of the path, or an
 *   empty slice if the path is empty or has no file (stem+extension) part
 */
STLSOFT_INLINE
stlsoft_C_string_slice_m_t const
platformstl_C_get_executable_name_from_path(
    ss_char_a_t const* path
)
{
    if (NULL == path)
    {
#ifdef __cplusplus

        return stlsoft_C_string_slice_m_t::create(ss_nullptr_k, 0);
#else /* ? __cplusplus */

        stlsoft_C_string_slice_m_t r = { 0, NULL };

        return r;
#endif /* __cplusplus */
    }
    else
    {
        stlsoft_C_string_slice_m_t  r;
        size_t const                cch     =   strlen(path);
        ss_char_a_t const*          slash   =   strrchr(path, '/');
#ifdef _WIN32
        ss_char_a_t const* const    bslash  =   strrchr(path, '\\');
        ss_char_a_t const*          dot;

        if (NULL == slash)
        {
            slash = bslash;
        }
        else
        {
            if (NULL != bslash)
            {
                if (slash < bslash)
                {
                    slash = bslash;
                }
            }
        }
#endif

        if (NULL != slash)
        {
            r.ptr = slash + 1;
        }
        else
        {
            r.ptr = path;
        }

#ifdef _WIN32
        dot = strrchr(r.ptr, '.');
        if (NULL != dot)
        {
            r.len = dot - r.ptr;
        }
        else
#endif
        {
            r.len = cch - (r.ptr - path);
        }

        return r;
    }
}

/** Elicits a wide slice to the part of the given path representing the
 * executable name, including removal of program extension on Windows.
 *
 * \param path A full or partial path. May be nullptr or empty string
 *
 * \return A slice representing the executable part of the path, or an
 *   empty slice if the path is empty or has no file (stem+extension) part
 */
STLSOFT_INLINE
stlsoft_C_string_slice_w_t const
platformstl_C_get_executable_name_from_path_w(
    ss_char_w_t const* path
)
{
    if (NULL == path)
    {
#ifdef __cplusplus

        return stlsoft_C_string_slice_w_t::create(ss_nullptr_k, 0);
#else /* ? __cplusplus */

        stlsoft_C_string_slice_w_t r = { 0, NULL };

        return r;
#endif /* __cplusplus */
    }
    else
    {
        stlsoft_C_string_slice_w_t  r;
        size_t const                cch     =   wcslen(path);
        ss_char_w_t const*          slash   =   wcsrchr(path, '/');
#ifdef _WIN32
        ss_char_w_t const* const    bslash  =   wcsrchr(path, '\\');
        ss_char_w_t const*          dot;

        if (NULL == slash)
        {
            slash = bslash;
        }
        else
        {
            if (NULL != bslash)
            {
                if (slash < bslash)
                {
                    slash = bslash;
                }
            }
        }
#endif

        if (NULL != slash)
        {
            r.ptr = slash + 1;
        }
        else
        {
            r.ptr = path;
        }

#ifdef _WIN32
        dot = wcsrchr(r.ptr, '.');
        if (NULL != dot)
        {
            r.len = dot - r.ptr;
        }
        else
#endif
        {
            r.len = cch - (r.ptr - path);
        }

        return r;
    }
}



/** Elicits a multibyte slice to the part of the given path representing the
 * directory path, including the volume (if present) on Windows.
 *
 * \param path A full or partial path. May be nullptr or empty string
 *
 * \return A slice representing the directory path of the path, or an
 *   empty slice if the path is empty or has no file (stem+extension) part
 */
STLSOFT_INLINE
stlsoft_C_string_slice_m_t const
platformstl_C_get_directory_path_from_path(
    ss_char_a_t const* path
)
{
    if (NULL == path)
    {
#ifdef __cplusplus

        return stlsoft_C_string_slice_m_t::create(ss_nullptr_k, 0);
#else /* ? __cplusplus */

        stlsoft_C_string_slice_m_t r = { 0, NULL };

        return r;
#endif /* __cplusplus */
    }
    else
    {
        stlsoft_C_string_slice_m_t  r;
        ss_char_a_t const*          slash   =   strrchr(path, '/');
#ifdef _WIN32
        ss_char_a_t const* const    bslash  =   strrchr(path, '\\');

        if (NULL == slash)
        {
            slash = bslash;
        }
        else
        {
            if (NULL != bslash)
            {
                if (slash < bslash)
                {
                    slash = bslash;
                }
            }
        }
#endif

        r.ptr   =   path;

        if (NULL == slash)
        {
            r.len = 0;
        }
        else
        {
            r.len = STLSOFT_STATIC_CAST(ss_size_t, slash - path);
        }

        return r;
    }
}

/** Elicits a wide slice to the part of the given path representing the
 * directory path, including the volume (if present) on Windows.
 *
 * \param path A full or partial path. May be nullptr or empty string
 *
 * \return A slice representing the directory path of the path, or an
 *   empty slice if the path is empty or has no file (stem+extension) part
 */
STLSOFT_INLINE
stlsoft_C_string_slice_w_t const
platformstl_C_get_directory_path_from_path_w(
    ss_char_w_t const* path
)
{
    if (NULL == path)
    {
#ifdef __cplusplus

        return stlsoft_C_string_slice_w_t::create(ss_nullptr_k, 0);
#else /* ? __cplusplus */

        stlsoft_C_string_slice_w_t r = { 0, NULL };

        return r;
#endif /* __cplusplus */
    }
    else
    {
        stlsoft_C_string_slice_w_t  r;
        ss_char_w_t const*          slash   =   wcsrchr(path, '/');
#ifdef _WIN32
        ss_char_w_t const* const    bslash  =   wcsrchr(path, '\\');

        if (NULL == slash)
        {
            slash = bslash;
        }
        else
        {
            if (NULL != bslash)
            {
                if (slash < bslash)
                {
                    slash = bslash;
                }
            }
        }
#endif

        r.ptr   =   path;

        if (NULL == slash)
        {
            r.len = 0;
        }
        else
        {
            r.len = STLSOFT_STATIC_CAST(ss_size_t, slash - path);
        }

        return r;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ Functions
 */

#ifdef __cplusplus

/** \see platformstl_C_get_executable_name_from_path()
 */
inline
stlsoft_C_string_slice_m_t const
get_executable_name_from_path(
    ss_char_a_t const* path
)
{
    return platformstl_C_get_executable_name_from_path(path);
}

/** \see platformstl_C_get_executable_name_from_path_w()
 */
inline
stlsoft_C_string_slice_w_t const
get_executable_name_from_path(
    ss_char_w_t const* path
)
{
    return platformstl_C_get_executable_name_from_path_w(path);
}


/** \see platformstl_C_get_directory_path_from_path()
 */
inline
stlsoft_C_string_slice_m_t const
get_directory_path_from_path(
    ss_char_a_t const* path
)
{
    return platformstl_C_get_directory_path_from_path(path);
}

/** \see platformstl_C_get_directory_path_from_path_w()
 */
inline
stlsoft_C_string_slice_w_t const
get_directory_path_from_path(
    ss_char_w_t const* path
)
{
    return platformstl_C_get_directory_path_from_path_w(path);
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef PLATFORMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
# else
} /* namespace platformstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !PLATFORMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

