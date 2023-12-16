/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry/error/exceptions.hpp
 *
 * Purpose:     Exceptions used by the Registry library.
 *
 * Created:     8th February 2006
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


/** \file winstl/registry/error/exceptions.hpp
 *
 * \brief [C++] Exceptions used by
 *   the \ref group__library__Windows_Registry "Windows Registry" Library.
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS
#define WINSTL_INCL_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS_MAJOR      2
# define WINSTL_VER_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS_MINOR      1
# define WINSTL_VER_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS_REVISION   6
# define WINSTL_VER_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS_EDIT       31
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

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
# include <winstl/exception/winstl_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS
# include <stlsoft/util/sign_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS */

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

/* ////////////////////////////////////////////////////////////////////// */

/** Root exception thrown by
 *   the \ref group__library__Windows_Registry "Windows Registry" Library.
 *
 * \ingroup group__library__Windows_Registry
 */
class registry_exception
    : public winstl_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef winstl_exception                                parent_class_type;
    /// The class type
    typedef registry_exception                              class_type;
    /// The status code type
    typedef parent_class_type::status_code_type             status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    typedef STLSOFT_NS_QUAL(sign_traits)<
        status_code_type
    >::alt_sign_type                                        status_code_alt_type;

/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance from a reason and an error code
    registry_exception(char const* reason, status_code_type sc)
        : parent_class_type(reason, sc)
    {}
    /// Constructs an instance from a reason and an error code
    ///
    /// \note Since the Windows Registry API error code type is LONG
    ///  this provides a suitable overload that does not incur compiler
    ///  warnings. The casting to an unsigned type within the body is
    ///  entirely benign.
    registry_exception(char const* reason, status_code_alt_type sc)
        : parent_class_type(reason, static_cast<status_code_type>(sc))
    {}
/// @}
};

/** Indicates that a registry key could not be duplicated.
 *
 * \ingroup group__library__Windows_Registry
 */
class key_not_duplicated_exception
    : public registry_exception
{
/// \name Member Types
/// @{
public:
    typedef registry_exception              parent_class_type;
    typedef key_not_duplicated_exception    class_type;
/// @}

/// \name Construction
/// @{
public:
    key_not_duplicated_exception(char const* reason, status_code_type sc)
        : parent_class_type(reason, sc)
    {}
    key_not_duplicated_exception(char const* reason, status_code_alt_type sc)
        : parent_class_type(reason, sc)
    {}
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type& operator =(class_type const&);
/// @}
};

/** Indicates a registry value type mismatch.
 *
 * \ingroup group__library__Windows_Registry
 */
class wrong_value_type_exception
    : public registry_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef registry_exception                              parent_class_type;
    /// The class type
    typedef wrong_value_type_exception                      class_type;
/// @}

/// \name Construction
/// @{
public:
    wrong_value_type_exception(char const* reason, status_code_type sc, ws_dword_t type)
        : parent_class_type(reason, sc)
        , m_valueType(type)
    {}
    wrong_value_type_exception(char const* reason, status_code_alt_type sc, ws_dword_t type)
        : parent_class_type(reason, sc)
        , m_valueType(type)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Accessors
/// @{
public:
    /// The actual type of the value
    ws_dword_t actual_value_type() const
    {
        return m_valueType;
    }
/// @}

/// \name Members
/// @{
private:
    ws_dword_t const    m_valueType;
/// @}
};

/** Indicates insufficient rights to access a registry key.
 *
 * \ingroup group__library__Windows_Registry
 */
class access_denied_exception
    : public registry_exception
{
/// \name Member Types
/// @{
public:
    typedef registry_exception          parent_class_type;
    typedef access_denied_exception     class_type;
/// @}

/// \name Construction
/// @{
public:
    access_denied_exception(char const* reason, status_code_type sc)
        : parent_class_type(reason, sc)
    {}
    access_denied_exception(char const* reason, status_code_alt_type sc)
        : parent_class_type(reason, sc)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !WINSTL_INCL_WINSTL_REGISTRY_ERROR_HPP_EXCEPTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

