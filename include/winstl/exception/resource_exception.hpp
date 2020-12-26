/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/exception/resource_exception.hpp (formerly in winstl/error/exceptions.hpp)
 *
 * Purpose:     winstl::resource_exception class
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


/** \file winstl/exception/resource_exception.hpp
 *
 * \brief [C++] Definition of the winstl::resource_exception exception
 * class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION
#define WINSTL_INCL_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION_MAJOR       5
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION_MINOR       0
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION_REVISION    1
# define WINSTL_VER_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION_EDIT        74
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

/** Indicates that a resource could not be located.
 *
 * \ingroup group__library__Exception
 *
 * \see winstl::applet_module |
 *      winstl::basic_resource_string
 */
class resource_exception
    : public winstl_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef winstl_exception                                parent_class_type;
    /// The class type
    typedef resource_exception                              class_type;
/// @}

/// \name Construction
/// @{
public:
    resource_exception(
        char const*         reason
    ,   status_code_type    sc
    )
        : parent_class_type(reason, sc)
        , m_resourceId(NULL)
        , m_resourceType(NULL)
    {}
    resource_exception(
        char const*         reason
    ,   status_code_type    sc
    ,   LPCTSTR             resourceId
    ,   LPCTSTR             resourceType
    )
        : parent_class_type(reason, sc)
        , m_resourceId(resourceId)
        , m_resourceType(resourceType)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Members
/// @{
public:
    LPCTSTR get_resource_id() const
    {
        return m_resourceId;
    }
    LPCTSTR get_resource_type() const
    {
        return m_resourceType;
    }
/// @}

/// \name Fields
/// @{
private:
    LPCTSTR const   m_resourceId;
    LPCTSTR const   m_resourceType;
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_RESOURCE_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

