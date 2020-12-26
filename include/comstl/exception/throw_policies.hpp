/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/exception/throw_policies.hpp (formerly comstl/error/exceptions.hpp)
 *
 * Purpose:     COM-related exception classes, and their policy classes
 *
 * Created:     8th December 2004
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


/** \file comstl/exception/throw_policies.hpp
 *
 * \brief [C++] Definition of the
 *   comstl::exception_policy_base exception policy class template
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_THROW_POLICIES
#define COMSTL_INCL_COMSTL_EXCEPTION_HPP_THROW_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_THROW_POLICIES_MAJOR       3
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_THROW_POLICIES_MINOR       0
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_THROW_POLICIES_REVISION    3
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_THROW_POLICIES_EDIT        57
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION
# include <comstl/exception/comstl_exception.hpp>
#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION */
#ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION
# include <comstl/exception/variant_type_exception.hpp>
#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Policy adaptor template for exception throwing
 *
 * \ingroup group__library__Exception
 *
 */
template <ss_typename_param_k X>
// [[synesis:class:exception-policy: exception_policy_base]]
struct exception_policy_base
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef X       thrown_type;
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
    void operator ()(HRESULT hr) const
    {
        STLSOFT_THROW_X(thrown_type(hr));
    }
    /// Function call operator, taking two parameters
    void operator ()(char const* reason, HRESULT hr) const
    {
        STLSOFT_THROW_X(thrown_type(reason, hr));
    }
/// @}
};

/** The policy class, which throws a comstl_exception class.
 *
 * \ingroup group__library__Exception
 *
 */
typedef exception_policy_base<comstl_exception>         com_exception_policy;

/** The policy class, which throws a variant_type_exception class.
 *
 * \ingroup group__library__Exception
 *
 */
typedef exception_policy_base<variant_type_exception>   variant_type_exception_policy;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_THROW_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

