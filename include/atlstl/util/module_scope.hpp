/* /////////////////////////////////////////////////////////////////////////
 * File:        atlstl/util/module_scope.hpp
 *
 * Purpose:     Scoping class for ATL _Module
 *
 * Created:     8th December 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file atlstl/util/module_scope.hpp
 *
 * \brief [C++] Definition of the atlstl::module_scope class template
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef ATLSTL_INCL_ATLSTL_UTIL_HPP_MODULE_SCOPE
#define ATLSTL_INCL_ATLSTL_UTIL_HPP_MODULE_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_UTIL_HPP_MODULE_SCOPE_MAJOR       2
# define ATLSTL_VER_ATLSTL_UTIL_HPP_MODULE_SCOPE_MINOR       1
# define ATLSTL_VER_ATLSTL_UTIL_HPP_MODULE_SCOPE_REVISION    8
# define ATLSTL_VER_ATLSTL_UTIL_HPP_MODULE_SCOPE_EDIT        41
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ATLSTL_INCL_ATLSTL_HPP_ATLSTL
# include <atlstl/atlstl.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES
# include <stlsoft/exception/throw_policies.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::atlstl */
namespace atlstl
{
# else
/* Define stlsoft::atlstl_project */
namespace stlsoft
{
namespace atlstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Scopes the initialisation and uninitialisation of an ATL module
 *
 * \ingroup group__library__Utility
 */
// [[synesis:class:raii: atlstl::module_scope<T<M>, T<X>>]]
template<   ss_typename_param_k M
        ,   ss_typename_param_k X = STLSOFT_NS_QUAL(null_exception_policy)
        >
class module_scope
{
public:
    typedef M                   module_type;
    typedef X                   exception_policy_type;
    typedef module_scope<M, X>  class_type;

/// \name Construction
/// @{
public:
    module_scope(module_type &m, ATL::_ATL_OBJMAP_ENTRY *pObjMap, HINSTANCE hinst, GUID const* pLibID = NULL)
        : m_m(m)
        , m_hr(m.Init(pObjMap, hinst, pLibID))
    {
        if (FAILED(m_hr))
        {
            exception_policy_type   xp;

            xp(m_hr);
        }
    }
    ~module_scope() STLSOFT_NOEXCEPT
    {
        m_m.Term();
    }
/// @}

/// \name Attributes
/// @{
public:
    HRESULT hr() const STLSOFT_NOEXCEPT
    {
        return m_hr;
    }
/// @}

// Members
private:
    M               &m_m;
    const HRESULT   m_hr;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace atlstl */
# else
} /* namespace atlstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ATLSTL_INCL_ATLSTL_UTIL_HPP_MODULE_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

