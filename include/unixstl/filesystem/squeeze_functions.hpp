/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/squeeze_functions.hpp (formerly unixstl/filesystem/path_functions.hpp)
 *
 * Purpose:     Path squeeze functions
 *
 * Created:     13th June 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/filesystem/squeeze_functions.hpp
 *
 * \brief [C++] Path squeeze functions
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_MAJOR     2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_MINOR     0
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_REVISION  3
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_EDIT      27
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

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH
# include <unixstl/filesystem/path.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#if defined(_WIN32) || \
    defined(_WIN64)
# include <ctype.h>
#endif /* Windows */

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
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_OPEN_WORKER_NS_(ximpl_unixstl_squeeze_functions_)

template<
    ss_typename_param_k C
>
us_size_t
path_squeeze_impl(
    C const*    path
,   us_size_t   pathLen
,   C           buffer[]
,   us_size_t   cchBuffer
)
{
    typedef C                       char_t;
    typedef filesystem_traits<C>    traits_t;
    typedef us_size_t               size_t;

    if (NULL == buffer)
    {
        cchBuffer = pathLen + 1u;
    }
    else if (0 != cchBuffer)
    {
        typedef basic_path<char_t>                              path_t_;
        typedef ss_typename_param_k path_t_::string_slice_type  slice_t_;

        path_t_         p(path, pathLen);
        slice_t_ const  file        =   p.get_file();
        char_t const*   path_ptr    =   p.c_str();

        if (cchBuffer > pathLen)
        {
            // Room for all

            p.copy(buffer, cchBuffer);

            cchBuffer = pathLen + 1u;
        }
        else
        {
            size_t rootLen;

            // Need to handle:
            //
            // 1. UNC
            // 2. drive
            // 3. rooted - begins with \ or /
            // 4. non-rooted

            if (p.is_rooted())
            {
                if (p.is_absolute())
                {
                    if (traits_t::is_path_UNC(path_ptr))
                    {
                        // 1. UNC

                        char_t const* p1 = traits_t::str_chr(path_ptr + 2, '\\');

                        rootLen = 1 + static_cast<size_t>(p1 - path_ptr);
                    }
#if defined(_WIN32) || \
    defined(_WIN64)
                    else if (isalpha(path_ptr[0]) &&
                            ':' == path_ptr[1])
                    {
                        // 2. drive
                        rootLen = 3;
                    }
#endif /* Windows */
                    else
                    {
                        // 3. rooted - begins with \ or /
                        rootLen = 1;
                    }
                }
                else
                {
                    // 3. rooted - begins with \ or /
                    rootLen = 1;
                }
            }
            else
            {
                // 4. non-rooted
                rootLen = 0;
            }

            if (cchBuffer < 5 + 1)
            {
                traits_t::char_copy(buffer, file.ptr, cchBuffer - 1);
                buffer[cchBuffer - 1] = '\0';

                if (cchBuffer > file.len)
                {
                    cchBuffer = file.len + 1;
                }
            }
            else if (cchBuffer < file.len + 1)
            {
                // Squeezing just file+ext
                size_t const    leftLen     =   (cchBuffer - 3 - 1) / 2;
                size_t const    rightLen    =   (cchBuffer - 3 - 1) - leftLen;

                traits_t::char_copy(buffer, file.ptr, leftLen);
                buffer[leftLen + 0] = '.';
                buffer[leftLen + 1] = '.';
                buffer[leftLen + 2] = '.';
                traits_t::char_copy(buffer + leftLen + 3, file.ptr + (file.len - rightLen), rightLen);
                buffer[leftLen + 3 + rightLen] = '\0';
            }
            else if (cchBuffer < rootLen + 3 + 1 + file.len + 1)
            {
                // File (name + ext) only

                traits_t::char_copy(buffer, file.ptr, file.len);
                buffer[file.len] = '\0';

                if (cchBuffer > file.len)
                {
                    cchBuffer = file.len + 1;
                }
            }
            else
            {
                UNIXSTL_ASSERT(cchBuffer < pathLen + 1);

                // Squeezing whole path
                size_t const    rightLen    =   1 + file.len;
                size_t const    leftLen     =   (cchBuffer - 3 - 1) - rightLen;

                traits_t::char_copy(buffer, path_ptr, leftLen);
                buffer[leftLen + 0] = '.';
                buffer[leftLen + 1] = '.';
                buffer[leftLen + 2] = '.';
                traits_t::char_copy(buffer + leftLen + 3, file.ptr - 1, rightLen);
                buffer[leftLen + 3 + rightLen] = '\0';
            }
        }
    }

    return cchBuffer;
}


template<
    ss_typename_param_k S
>
us_size_t
path_squeeze_impl2(
    S const&    path
,   us_char_a_t buffer[]
,   us_size_t   cchBuffer
)
{
    return path_squeeze_impl(STLSOFT_NS_QUAL(c_str_ptr_a)(path), STLSOFT_NS_QUAL(c_str_len)(path), buffer, cchBuffer);
}

template<
    ss_typename_param_k S
>
us_size_t
path_squeeze_impl2(
    S const&    path
,   us_char_w_t buffer[]
,   us_size_t   cchBuffer
)
{
    return path_squeeze_impl(STLSOFT_NS_QUAL(c_str_ptr_w)(path), STLSOFT_NS_QUAL(c_str_len)(path), buffer, cchBuffer);
}

STLSOFT_CLOSE_WORKER_NS_(ximpl_unixstl_squeeze_functions_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Squeezes a path into a fixed length character buffer
 *
 * \ingroup group__library__FileSystem
 *
 * \param path The path
 * \param buffer Pointer to the buffer into which the sqeezed path will be
 *   written. If NULL, function returns required size (=== len(path) + 1)
 * \param cchBuffer The number of available characters inc buffer. This
 *   value in inclusive of the required <code>nul</code>-terminator
 *
 */

template<
    ss_typename_param_k S
,   ss_typename_param_k C
>
us_size_t
path_squeeze(
    S const&    path
,   C           buffer[]
,   us_size_t   cchBuffer
)
{
    return STLSOFT_WORKER_NS_QUAL_(ximpl_unixstl_squeeze_functions_, path_squeeze_impl2)(path, buffer, cchBuffer);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
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

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

