/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/path_buffer.hpp
 *
 * Purpose:     Platform header for the path_buffer components.
 *
 * Created:     22nd December 2020
 * Updated:     30th December 2020
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


/** \file platformstl/filesystem/path_buffer.hpp
 *
 * \brief [C++] Definition of the platformstl::basic_path_buffer
 *  type
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH_BUFFER
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH_BUFFER

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_BUFFER_MAJOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_BUFFER_MINOR       0
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_BUFFER_REVISION    2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PATH_BUFFER_EDIT        2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH_BUFFER
#  include <unixstl/filesystem/path_buffer.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH_BUFFER */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_BUFFER
#  include <winstl/filesystem/path_buffer.hpp>
# endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_BUFFER */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */
namespace stlsoft
{
namespace platformstl_project
{
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

    /** Class used for composing and decomposing file-system paths.
     *
     * \ingroup group__library__FileSystem
     *
     * The class is not actually defined in the
     * \link ::platformstl platformstl\endlink namespace. Rather, it
     * resolves to the appropriate type for the given platform, relying on
     * \ref section__principle__conformance__intersecting_conformance "Intersecting Conformance"
     * of the resolved platform-specific types.
     *
     * When compiling on UNIX platforms, the platformstl::basic_path_buffer
     * type resolves to the unixstl::basic_path_buffer class. On Windows
     * platforms it resolves to the winstl::basic_path_buffer class. It
     * is not defined for other platforms.
     */
    template<
        ss_typename_param_k T_character
    ,   ss_typename_param_k T_allocator
    ,   ss_size_t           V_internalBufferSize
    >
    class basic_path_buffer
    {};

    /// Specialisation of the basic_path_buffer template for the ANSI character type \c char
    typedef basic_path_buffer<char>                         path_buffer_a;
    /// Specialisation of the basic_path_buffer template for the Unicode character type \c wchar_t
    typedef basic_path_buffer<wchar_t>                      path_buffer_w;
    /// Specialisation of the basic_path_buffer template for the ANSI character type \c char on UNIX, and for the \c TCHAR type on Windows
    typedef basic_path_buffer<tchar>                        path_buffer;
#elif defined(PLATFORMSTL_OS_IS_UNIX)

# ifdef UNIXSTL_NO_NAMESPACE
    using ::path_buffer_a;
    using ::path_buffer_w;
    using ::path_buffer;
# else /* ? UNIXSTL_NO_NAMESPACE */
    using ::unixstl::path_buffer_a;
    using ::unixstl::path_buffer_w;
    using ::unixstl::path_buffer;
# endif /* UNIXSTL_NO_NAMESPACE */

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

# ifdef WINSTL_NO_NAMESPACE
    using ::path_buffer_a;
    using ::path_buffer_w;
    using ::path_buffer;
# else /* ? WINSTL_NO_NAMESPACE */
    using ::winstl::path_buffer_a;
    using ::winstl::path_buffer_w;
    using ::winstl::path_buffer;
# endif /* WINSTL_NO_NAMESPACE */

#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
#else
} /* namespace platformstl_project */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

