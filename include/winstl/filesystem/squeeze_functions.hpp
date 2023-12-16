/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/squeeze_functions.hpp (formerly winstl/filesystem/path_functions.hpp)
 *
 * Purpose:     Path squeeze functions
 *
 * Created:     6th June 2006
 * Updated:     30th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/filesystem/squeeze_functions.hpp
 *
 * \brief [C++] Path squeeze functions
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_MAJOR       2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_REVISION    4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS_EDIT        34
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

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH
# include <winstl/filesystem/path.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

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
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_OPEN_WORKER_NS_(ximpl_winstl_squeeze_functions_)

template<
    ss_typename_param_k C
>
ws_size_t
path_squeeze_impl(
    C const*    path
,   ws_size_t   pathLen
,   C           buffer[]
,   ws_size_t   cchBuffer
)
{
    typedef C                       char_t;
    typedef filesystem_traits<C>    traits_t;
    typedef ws_size_t               size_t;

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

                        if (NULL == p1)
                        {
                            // badly formed UNC, so treat as no-root
                            rootLen = 0;
                        }
                        else
                        {
                            rootLen = 1 + static_cast<size_t>(p1 - path_ptr);
                        }
                    }
                    else
                    {
                        // 2. drive
                        rootLen = 3;
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
                WINSTL_ASSERT(cchBuffer < pathLen + 1);

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
ws_size_t
path_squeeze_impl2(
    S const&    path
,   ws_char_a_t buffer[]
,   ws_size_t   cchBuffer
)
{
    return path_squeeze_impl(STLSOFT_NS_QUAL(c_str_ptr_a)(path), STLSOFT_NS_QUAL(c_str_len)(path), buffer, cchBuffer);
}

template<
    ss_typename_param_k S
>
ws_size_t
path_squeeze_impl2(
    S const&    path
,   ws_char_w_t buffer[]
,   ws_size_t   cchBuffer
)
{
    return path_squeeze_impl(STLSOFT_NS_QUAL(c_str_ptr_w)(path), STLSOFT_NS_QUAL(c_str_len)(path), buffer, cchBuffer);
}

STLSOFT_CLOSE_WORKER_NS_(ximpl_winstl_squeeze_functions_)
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
 *   value in inclusive of the required <code>NUL</code>-terminator
 *
 * \return The number of characters required (if buffer is NULL), or the
 *   number of characters written (if buffer is non-NULL). In both cases, it
 *   includes the one required for the <code>NUL</code>-terminator
 *
 * \remarks The squeeze algorithm is as follows. The path is split into
 *   volume+directory and file+ext. If the buffer is too small to fit the
 *   file+ext, then the result will be a squeezed form of file+ext. If the
 *   buffer is too small to fit the volume+...+file+ext, then the result
 *   will be file+ext. If the buffer is too small to fit the entire path,
 *   then the result will be volume+part_of_directory+...+file+ext.
 *   Otherwise the result will be the full path.
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k C
>
ws_size_t
path_squeeze(
    S const&    path
,   C           buffer[]
,   ws_size_t   cchBuffer
)
{
    return STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_squeeze_functions_, path_squeeze_impl2)(path, buffer, cchBuffer);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

