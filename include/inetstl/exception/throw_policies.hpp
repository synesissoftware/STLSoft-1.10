/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/exception/throw_policies.hpp (formerly inetstl/error/exceptions.hpp)
 *
 * Purpose:     Contains the internet_exception class.
 *
 * Created:     25th April 2004
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file inetstl/exception/throw_policies.hpp
 *
 * \brief [C++] Definition of the
 *    inetstl::throw_internet_exception_policy exception policy class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef INETSTL_INCL_INETSTL_EXCEPTION_HPP_THROW_POLICIES
#define INETSTL_INCL_INETSTL_EXCEPTION_HPP_THROW_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_THROW_POLICIES_MAJOR     4
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_THROW_POLICIES_MINOR     2
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_THROW_POLICIES_REVISION  7
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_THROW_POLICIES_EDIT      55
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef INETSTL_INCL_INETSTL_H_INETSTL
# include <inetstl/inetstl.h>
#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef INETSTL_INCL_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION
# include <inetstl/exception/inetstl_exception.hpp>
#endif /* !INETSTL_INCL_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES
# include <stlsoft/exception/throw_policies.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES */

#ifndef INETSTL_OS_IS_WINDOWS
# include <errno.h>
#endif /* !INETSTL_OS_IS_WINDOWS */

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error This file cannot be included when exception-handling is not supported
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef _WIN32
# ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
#  include <winstl/api/external/ErrorHandling.h>
# endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */
namespace stlsoft
{
namespace inetstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** The policy class, which throws a inetstl_exception class.
 *
 * \ingroup group__library__Exception
 *
 */
// [[synesis:class:exception-policy: throw_internet_exception_policy]]
struct throw_internet_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef inetstl_exception                               thrown_type;
    /// The status code type
    typedef thrown_type::status_code_type                   status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Operators
/// @{
public:
    /// Function call operator, taking no parameters
    void operator ()() const
    {
#ifdef INETSTL_OS_IS_WINDOWS
        STLSOFT_THROW_X(thrown_type(WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? INETSTL_OS_IS_WINDOWS */
        STLSOFT_THROW_X(thrown_type(errno));
#endif /* INETSTL_OS_IS_WINDOWS */
    }
    /// Function call operator, taking one parameter
    void operator ()(status_code_type sc) const
    {
        STLSOFT_THROW_X(thrown_type(sc));
    }
    /// Function call operator, taking two parameters
    void operator ()(char const* reason, status_code_type sc) const
    {
        STLSOFT_THROW_X(thrown_type(reason, sc));
    }
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace inetstl */
# else
} /* namespace inetstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !INETSTL_INCL_INETSTL_EXCEPTION_HPP_THROW_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

