/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/exception/bad_interface_cast.hpp (formerly comstl/error/bad_interface_cast.hpp)
 *
 * Purpose:     Exception thrown when interface casts fail.
 *
 * Created:     22nd December 2003
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/exception/bad_interface_cast.hpp
 *
 * \brief [C++] Definition of the comstl::bad_interface_cast class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_BAD_INTERFACE_CAST
#define COMSTL_INCL_COMSTL_EXCEPTION_HPP_BAD_INTERFACE_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_BAD_INTERFACE_CAST_MAJOR       6
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_BAD_INTERFACE_CAST_MINOR       0
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_BAD_INTERFACE_CAST_REVISION    2
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_BAD_INTERFACE_CAST_EDIT        51
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

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error This file cannot be included when exception-handling is not supported
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_IDENTIFIER_PROVIDER
# include <stlsoft/exception/project_identifier_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_IDENTIFIER_PROVIDER */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER
# include <stlsoft/exception/status_code_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER */

#ifndef STLSOFT_INCL_TYPEINFO
# define STLSOFT_INCL_TYPEINFO
# include <typeinfo>     // for std::bad_cast
#endif /* !STLSOFT_INCL_TYPEINFO */

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

/** Exception class thrown by the interface cast classes and
 *    functions when interface queries fail
 *
 * \see comstl::interface_cast
 * \see comstl::interface_cast_addref
 * \see comstl::interface_cast_noaddref
 * \see comstl::interface_cast_test
 *
 * \ingroup group__library__Exception
 */
// [[synesis:class:exception: comstl::bad_cast]]
class bad_interface_cast
    : public STLSOFT_NS_QUAL_STD(bad_cast)
    , public STLSOFT_NS_QUAL(status_code_provider)<HRESULT>
    , public project_identifier_provider
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef STLSOFT_NS_QUAL_STD(bad_cast)                   parent_class_type;
    /// The status code type
    typedef HRESULT                                         status_code_type;
    /// The class type
    typedef bad_interface_cast                              class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance of the exception from the given interface
    /// identifier and result code.
    bad_interface_cast(
        REFIID              riid
    ,   status_code_type    sc
    ) STLSOFT_NOEXCEPT
        : parent_class_type()
        , m_iid(riid)
        , m_sc(sc)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Accessors
/// @{
public:
    /// Returns a human-readable description of the exceptional condition
    /* virtual */ char const*
    what() const STLSOFT_NOEXCEPT ss_override_k
    {
        return "Failed to acquire requested interface";
    }

    /// The interface identifier that is associated with the exception
    REFIID      iid() const STLSOFT_NOEXCEPT
    {
        return m_iid;
    }

    /// [DEPRECATED] Equivalent to status_code()
    ///
    /// \deprecated
    HRESULT     hresult() const STLSOFT_NOEXCEPT
    {
        return hr();
    }

    /// [DEPRECATED] Equivalent to status_code()
    ///
    /// \deprecated
    HRESULT     hr() const STLSOFT_NOEXCEPT
    {
        return m_sc;
    }

    /// The status code that is associated with the exception
    /* virtual */ status_code_type
    status_code() const ss_override_k
    {
        return m_sc;
    }

    /* virtual */ project_identifier_type
    project_identifier() const ss_override_k
    {
        return STLSoftProjectIdentifier_COMSTL;
    }
/// @}

/// \name Members
/// @{
private:
    IID const               m_iid;
    status_code_type const  m_sc;
/// @}
};

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_BAD_INTERFACE_CAST */

/* ///////////////////////////// end of file //////////////////////////// */

