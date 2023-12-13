/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/throw_policies.hpp (formerly stlsoft/error/throw_policies.hpp)
 *
 * Purpose:     Exception throwing policy classes.
 *
 * Created:     19th January 2002
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/exception/throw_policies.hpp
 *
 * \brief [C++] Definition of the stlsoft::nothrow_exception_policy and
 *   stlsoft::throw_exception_policy exception policy classes
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES
#define STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_THROW_POLICIES_MAJOR     6
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_THROW_POLICIES_MINOR     0
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_THROW_POLICIES_REVISION  1
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_THROW_POLICIES_EDIT      60
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_EXCEPTION
# define STLSOFT_INCL_EXCEPTION
# include <exception>
#endif /* !STLSOFT_INCL_EXCEPTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** The no-throwing exception policy. It does not throw, and its throw type is empty.
 *
 * \ingroup group__library__Exception
 *
 */
// [[synesis:class:exception-policy: null_exception_policy]]
struct null_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    struct thrown_type
    {
    };
/// @}

/// \name Operators
/// @{
public:
    /// Function call operator, taking no parameters
    void operator ()() const
    {}
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator, taking one parameter
    template <ss_typename_param_k T>
    void operator ()(T const& /* t */) const STLSOFT_NOEXCEPT
    {
        // Do nothing
    }
    /// Function call operator, taking two parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            >
    void operator ()(T1 const& /* t1 */, T2 const& /* t2 */) const STLSOFT_NOEXCEPT
    {
        // Do nothing
    }
    /// Function call operator, taking three parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            ,   ss_typename_param_k T3
            >
    void operator ()(T1 const& /* t1 */, T2 const& /* t2 */, T3 const& /* t3 */) const STLSOFT_NOEXCEPT
    {
        // Do nothing
    }
    /// Function call operator, taking four parameters
    template<   ss_typename_param_k T1
            ,   ss_typename_param_k T2
            ,   ss_typename_param_k T3
            ,   ss_typename_param_k T4
            >
    void operator ()(T1 const& /* t1 */, T2 const& /* t2 */, T3 const& /* t3 */, T4 const& /* t4 */) const STLSOFT_NOEXCEPT
    {
        // Do nothing
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
/// @}
};

/** Alternative typedef for null_exception_policy
 *
 * \ingroup group__library__Exception
 *
 */
typedef null_exception_policy   nothrow_exception_policy;

/** The throwing exception policy. It throws instances of its parameterising type.
 *
 * \ingroup group__library__Exception
 *
 */
template<ss_typename_param_k E>
// [[synesis:class:exception-policy: throw_exception_policy]]
struct throw_exception_policy
{
/// \name Member Types
/// @{
public:
    /// The thrown type
    typedef E               thrown_type;
/// @}

/// \name Operators
/// @{
public:
    /// Function call operator, taking no parameters
    void operator ()() const
    {
        STLSOFT_THROW_X(thrown_type());
    }
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator, taking one parameter
    template <ss_typename_param_k T>
    void operator ()(T const& t) const
    {
        STLSOFT_THROW_X(thrown_type(t));
    }
    /// Function call operator, taking two parameters
    template<ss_typename_param_k T1, ss_typename_param_k T2>
    void operator ()(T1 const& t1, T2 const& t2) const
    {
        STLSOFT_THROW_X(thrown_type(t1, t2));
    }
    /// Function call operator, taking three parameters
    template<ss_typename_param_k T1, ss_typename_param_k T2, ss_typename_param_k T3>
    void operator ()(T1 const& t1, T2 const& t2, T3 const& t3) const
    {
        STLSOFT_THROW_X(thrown_type(t1, t2, t3));
    }
    /// Function call operator, taking four parameters
    template<ss_typename_param_k T1, ss_typename_param_k T2, ss_typename_param_k T3, ss_typename_param_k T4>
    void operator ()(T1 const& t1, T2 const& t2, T3 const& t3, T4 const& t4) const
    {
        STLSOFT_THROW_X(thrown_type(t1, t2, t3, t4));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
/// @}
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef _STLSOFT_INCLUDE_OBSOLETE

#if _STLSOFT_VER < 0x010a0200
typedef null_exception_policy   null_exception;
typedef null_exception_policy   nothrow_exception;
#endif

# endif /* _STLSOFT_INCLUDE_OBSOLETE */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

