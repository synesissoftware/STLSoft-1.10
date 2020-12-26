/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/system/system_traits.hpp
 *
 * Purpose:     Platform header for the system_traits components.
 *
 * Created:     2nd July 2006
 * Updated:     26th December 2020
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


/** \file platformstl/system/system_traits.hpp
 *
 * \brief [C++] Definition of the platformstl::system_traits
 *  type
 *   (\ref group__library__System "System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_HPP_SYSTEM_TRAITS
#define PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_HPP_SYSTEM_TRAITS

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_HPP_SYSTEM_TRAITS_MAJOR     1
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_HPP_SYSTEM_TRAITS_MINOR     2
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_HPP_SYSTEM_TRAITS_REVISION  6
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_HPP_SYSTEM_TRAITS_EDIT      19
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS
#  include <unixstl/system/system_traits.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
#  include <winstl/system/system_traits.hpp>
# endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */
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

    /** Traits class for system operations.
     *
     * \ingroup group__library__System
     *
     * The class is not actually defined in the
     * \link ::platformstl platformstl\endlink namespace. Rather, it
     * resolves to the appropriate type for the given platform, relying on
     * \ref section__principle__conformance__intersecting_conformance "Intersecting Conformance"
     * of the resolved platform-specific types.
     *
     * When compiling on UNIX platforms, the platformstl::system_traits
     * type resolves to the unixstl::system_traits class. On Windows
     * platforms it resolves to the winstl::system_traits class. It
     * is not defined for other platforms.
     */
    template<   ss_typename_param_k C
            >
    class system_traits
    {};

#elif defined(PLATFORMSTL_OS_IS_UNIX)

    // Because early incarnations of Visual C++ are pretty stupid, we need to
    // work around their inability to introduce a template via using by
    // defining and deriving here

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template <ss_typename_param_k C>
    struct system_traits;

    STLSOFT_TEMPLATE_SPECIALISATION
    struct system_traits<UNIXSTL_NS_QUAL(us_char_a_t)>
        : public UNIXSTL_NS_QUAL(system_traits)<UNIXSTL_NS_QUAL(us_char_a_t)>
    {};

    STLSOFT_TEMPLATE_SPECIALISATION
    struct system_traits<UNIXSTL_NS_QUAL(us_char_w_t)>
        : public UNIXSTL_NS_QUAL(system_traits)<UNIXSTL_NS_QUAL(us_char_w_t)>
    {};

# else /* ? compiler */

#  ifdef UNIXSTL_NO_NAMESPACE
    using ::system_traits;
#  else /* ? UNIXSTL_NO_NAMESPACE */
    using ::unixstl::system_traits;
#  endif /* UNIXSTL_NO_NAMESPACE */
# endif /* compiler */

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    // Because early incarnations of Visual C++ are pretty stupid, we need to
    // work around their inability to introduce a template via using by
    // defining and deriving here

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template <ss_typename_param_k C>
    struct system_traits;

    STLSOFT_TEMPLATE_SPECIALISATION
    struct system_traits<WINSTL_NS_QUAL(ws_char_a_t)>
        : public WINSTL_NS_QUAL(system_traits)<WINSTL_NS_QUAL(ws_char_a_t)>
    {};

    STLSOFT_TEMPLATE_SPECIALISATION
    struct system_traits<WINSTL_NS_QUAL(ws_char_w_t)>
        : public WINSTL_NS_QUAL(system_traits)<WINSTL_NS_QUAL(ws_char_w_t)>
    {};

# else /* ? compiler */

#  ifdef WINSTL_NO_NAMESPACE
    using ::system_traits;
#  else /* ? WINSTL_NO_NAMESPACE */
    using ::winstl::system_traits;
#  endif /* WINSTL_NO_NAMESPACE */

# endif /* compiler */

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

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_HPP_SYSTEM_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

