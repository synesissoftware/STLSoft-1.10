/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/exception/throw_policies.hpp (formerly unixstl/error/exceptions.hpp)
 *
 * Purpose:     Exception throwing policy classes.
 *
 * Created:     19th June 2004
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


/** \file unixstl/exception/throw_policies.hpp
 *
 * \brief [C++] Definition of the unixstl::unix_exception_policy
 *   exception policy class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES
#define UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES_MAJOR     4
# define UNIXSTL_VER_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES_MINOR     2
# define UNIXSTL_VER_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES_REVISION  10
# define UNIXSTL_VER_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES_EDIT      63
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

#ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_UNIXSTL_EXCEPTION
# include <unixstl/exception/unixstl_exception.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_UNIXSTL_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES
# include <stlsoft/exception/throw_policies.hpp>        // for null_exception_policy
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES */
#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */

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
 * classes
 */

/** A policy class that throws a unixstl_exception class.
 *
 * \ingroup group__library__Exception
 *
 */
// [[synesis:class:exception-policy: unix_exception_policy]]
struct unix_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef unixstl_exception                               thrown_type;
    /// The status code type
    typedef int                                             status_code_type;
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
        STLSOFT_THROW_X(thrown_type(errno));
    }
    /// Function call operator, taking one parameter
    void operator ()(status_code_type err) const
    {
        STLSOFT_THROW_X(thrown_type(err));
    }
    /// Function call operator, taking two parameters
    void operator ()(char const* reason, status_code_type err) const
    {
        STLSOFT_THROW_X(thrown_type(reason, err));
    }
/// @}
};

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_THROW_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

