/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path_buffer.hpp
 *
 * Purpose:     Contains the basic_path_buffer template class.
 *
 * Created:     27th May 2020
 * Updated:     4th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/filesystem/path_buffer.hpp
 *
 * \brief [C++] Definition of the winstl::basic_path_buffer class
 *  template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_BUFFER
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_BUFFER_MAJOR     1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_BUFFER_MINOR     0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_BUFFER_REVISION  1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_BUFFER_EDIT      1
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

#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER
# include <stlsoft/filesystem/path_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER */

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
 * classes
 */

/** Generator template for stlsoft::basic_path_buffer that incorporates
 * WinSTL's processheap_allocator and WINSTL_CONST_MAX_PATH
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k T_allocator             =   processheap_allocator<T_character>
,   ss_size_t           V_internalBufferSize    =   1 + WINSTL_CONST_MAX_PATH
>
struct path_buffer_generator
{
    typedef STLSOFT_NS_QUAL(basic_path_buffer)<
        T_character
    ,   T_allocator
    ,   V_internalBufferSize
    >                                                       type;
};

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/* Typedefs to commonly encountered types. */

/** Specialisation of the basic_path_buffer template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef path_buffer_generator<
    ws_char_a_t
>::type                                                     path_buffer_a;
/** Specialisation of the basic_path_buffer template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef path_buffer_generator<
    ws_char_w_t
>::type                                                     path_buffer_w;
/** Specialisation of the basic_path_buffer template for the ambient character type \c TCHAR
 *
 * \ingroup group__library__FileSystem
 */
typedef path_buffer_generator<
    TCHAR
>::type                                                     path_buffer;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE

# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

/* There is no stlsoft namespace, so must define ::winstl */
} /* namespace winstl */
# else

/* Define stlsoft::winstl_project */
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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

