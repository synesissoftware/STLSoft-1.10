/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/util/status_code_translating_exception_base.hpp (formerly (unix|win)stl/exception/(unix|win)stl_exception.hpp)
 *
 * Purpose:     stlsoft::status_code_translating_exception_base class
 *              template
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


/** \file stlsoft/exception/util/status_code_translating_exception_base.hpp
 *
 * \brief [C++] Definition of the stlsoft::status_code_translating_exception_base
 *   class template
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE
#define STLSOFT_INCL_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE_MAJOR      6
# define STLSOFT_VER_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE_MINOR      0
# define STLSOFT_VER_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE_REVISION   2
# define STLSOFT_VER_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE_EDIT       80
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

#ifndef STLSOFT_INCL_STLSOFT_DIAGNOSTICS_H_PROJECTIDENTIFIER
# include <stlsoft/diagnostics/ProjectIdentifier.h>
#endif /* !STLSOFT_INCL_STLSOFT_DIAGNOSTICS_H_PROJECTIDENTIFIER */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER
# include <stlsoft/exception/status_code_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING
# include <stlsoft/util/exception_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error This file cannot be included when exception-handling is not supported
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

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

/** General exception class template for translating status codes
 *
 * \ingroup group__library__Exception
 *
 */
template<
    ss_typename_type_k  T_parentClassType
,   ProjectIdentifier_t V_libraryIdentifier
,   ss_typename_type_k  P_statusCodeToStringTranslator
>
class status_code_translating_exception_base
    : public T_parentClassType
    , public status_code_provider<ss_typename_type_k P_statusCodeToStringTranslator::status_code_type>
{
/// \name Member Types
/// @{
protected:
    typedef STLSOFT_NS_QUAL(exception_string)               string_type;
public:
    /// The parent class type
    typedef T_parentClassType                               parent_class_type;
    /// The translation policy type
    typedef P_statusCodeToStringTranslator                  status_code_to_string_translator_policy_type;
    /// The status code type
    typedef ss_typename_type_k status_code_to_string_translator_policy_type::status_code_type

                                                            status_code_type;
#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
    /// The class type
    typedef status_code_translating_exception_base<
        parent_class_type
    ,   V_libraryIdentifier
    ,   status_code_to_string_translator_policy_type
    >                                                       class_type;
    /// The size type
    typedef ss_size_t                                       size_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance from the given status code
    ///
    /// \param sc The status code associated with the exception
    ss_explicit_k
    status_code_translating_exception_base(
        status_code_type    sc
    )
        : parent_class_type(V_libraryIdentifier)
        , m_message(create_message_(NULL, sc))
        , m_statusCode(sc)
    {}
    /// Constructs an instance from the given message and status code
    ///
    /// \param reason The message code associated with the exception
    /// \param sc The status code associated with the exception
    status_code_translating_exception_base(
        char const*         reason
    ,   status_code_type    sc
    )
        : parent_class_type(V_libraryIdentifier)
        , m_message(create_message_(reason, sc))
        , m_statusCode(sc)
    {}
protected:
    /// Contructor for derived classes
    status_code_translating_exception_base(
        string_type const&  reason
    ,   status_code_type    sc
    )
        : parent_class_type(V_libraryIdentifier)
        , m_message(reason)
        , m_statusCode(sc)
    {}
public:
    /// Destructor
    ///
    /// \note This does not do have any implementation, but is required to placate
    /// the Comeau and GCC compilers, which otherwise complain about mismatched
    /// exception specifications between this class and its parent
    ~status_code_translating_exception_base() STLSOFT_NOEXCEPT
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Overrides
/// @{
public:
    /* virtual */ char const*
    what() const STLSOFT_NOEXCEPT ss_override_k
    {
        return m_message.c_str();
    }

    /* virtual */ status_code_type
    status_code() const ss_override_k
    {
        return m_statusCode;
    }
/// @}

/// \name Implementation
/// @{
private:
    static
    string_type
    create_message_(
        char const*         message
    ,   status_code_type    sc
    )
    {
        return status_code_to_string_translator_policy_type::create_message(sc, message);
    }
/// @}

/// \name Fields
/// @{
private:
    string_type const       m_message;
    status_code_type const  m_statusCode;
/// @}
};

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

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE */

/* ///////////////////////////// end of file //////////////////////////// */

