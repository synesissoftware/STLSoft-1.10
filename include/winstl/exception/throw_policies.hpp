/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/exception/throw_policies.hpp (formerly winstl/error/exceptions.hpp)
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


/** \file winstl/exception/throw_policies.hpp
 *
 * \brief [C++] Definition of the winstl::windows_exception_policy and
 * winstl::resource_exception_policy exception policy classes
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES
#define WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_THROW_POLICIES_MAJOR       5
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_THROW_POLICIES_MINOR       1
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_THROW_POLICIES_REVISION    3
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_THROW_POLICIES_EDIT        77
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

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION
# include <winstl/exception/resource_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION */
#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_SECURITY_EXCEPTION
# include <winstl/exception/security_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_SECURITY_EXCEPTION */
#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
# include <winstl/exception/winstl_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

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

/** A policy class that throws a winstl_exception class.
 *
 * \ingroup group__library__Exception
 *
 */
// [[synesis:class:exception-policy: windows_exception_policy]]
struct windows_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef winstl_exception                                thrown_type;
    /// The status code type
    typedef ws_dword_t                                      status_code_type;
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
        STLSOFT_THROW_X(thrown_type(WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
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

/** A policy class that throws a resource_exception class.
 *
 * \ingroup group__library__Exception
 *
 */
// [[synesis:class:exception-policy: resource_exception_policy]]
struct resource_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef resource_exception                              thrown_type;
    /// The status code type
    typedef ws_dword_t                                      status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Operators
/// @{
public:
    /// Function call operator, taking two parameters
    void operator ()(char const* reason, status_code_type sc) const
    {
        STLSOFT_THROW_X(thrown_type(reason, sc));
    }
    /// Function call operator, taking four parameters
    void operator ()(char const* reason, status_code_type sc, LPCTSTR resourceId, LPCTSTR resourceType) const
    {
        STLSOFT_THROW_X(thrown_type(reason, sc, resourceId, resourceType));
    }
/// @}
};

/** A policy class that throws a security_exception class.
 *
 * \ingroup group__library__Exception
 *
 */
// [[synesis:class:exception-policy: security_exception_policy]]
struct security_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef security_exception                              thrown_type;
    /// The status code type
    typedef ws_dword_t                                      status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Operators
/// @{
public:
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

#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

