/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/typelib/TypeInfo_resource_scope.hpp
 *
 * Purpose:     Scoping class template for type information resources.
 *
 * Created:     6th April 2005
 * Updated:     28th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/typelib/TypeInfo_resource_scope.hpp
 *
 * \brief [C++] Scoping class template for type information resources
 */

#ifndef COMSTL_INCL_COMSTL_TYPELIB_HPP_TYPEINFO_RESOURCE_SCOPE
#define COMSTL_INCL_COMSTL_TYPELIB_HPP_TYPEINFO_RESOURCE_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_TYPELIB_HPP_TYPEINFO_RESOURCE_SCOPE_MAJOR    1
# define COMSTL_VER_COMSTL_TYPELIB_HPP_TYPEINFO_RESOURCE_SCOPE_MINOR    2
# define COMSTL_VER_COMSTL_TYPELIB_HPP_TYPEINFO_RESOURCE_SCOPE_REVISION 4
# define COMSTL_VER_COMSTL_TYPELIB_HPP_TYPEINFO_RESOURCE_SCOPE_EDIT     41
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

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR
# include <stlsoft/smartptr/ref_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

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
 * typedefs
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct ximpl_comstl_typelib_TypeInfo_resource_scope_util_
{
public:
    struct TYPEATTR_traits
    {
    public:
        typedef TYPEATTR        resource_type;

        static void release_resource(ITypeInfo* ti, resource_type* resource)
        {
            ti->ReleaseTypeAttr(resource);
        }
    };
    struct VARDESC_traits
    {
    public:
        typedef VARDESC         resource_type;

        static void release_resource(ITypeInfo* ti, resource_type* resource)
        {
            ti->ReleaseVarDesc(resource);
        }
    };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Class template that acts as a scoping class for type information
 * resource types
 *
 */
template <ss_typename_param_k T>
class TypeInfo_resource_scope
{
public:
    typedef T                                               traits_type;
    typedef ss_typename_type_k traits_type::resource_type   resource_type;
    typedef TypeInfo_resource_scope<T>                      class_type;

public: // Construction
    TypeInfo_resource_scope(ITypeInfo* ti, resource_type* resource)
        : m_ti(ti, true)
        , m_resource(resource)
    {
        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != ti, "pointer to type info may not be null");
        STLSOFT_CONTRACT_ENFORCE_ASSUMPTION((NULL == ti || NULL != m_ti.get()));
    }
    template <typename TI>
    TypeInfo_resource_scope(TI const& ti, resource_type* resource)
        : m_ti(stlsoft::get_ptr(ti), true)
        , m_resource(resource)
    {
        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != stlsoft::get_ptr(ti), "pointer to type info may not be null");
        STLSOFT_CONTRACT_ENFORCE_ASSUMPTION((NULL == stlsoft::get_ptr(ti) || NULL != m_ti.get()));
    }
    ~TypeInfo_resource_scope() STLSOFT_NOEXCEPT
    {
        traits_type::release_resource(m_ti.get(), m_resource);
    }
private:
    TypeInfo_resource_scope(class_type const&);
    class_type& operator =(class_type const&);

public: // Accessors
    resource_type* get() const
    {
        return m_resource;
    }

    resource_type* operator ->()
    {
        return m_resource;
    }
    resource_type* operator ->() const
    {
        return m_resource;
    }

private: // Member Variables
    stlsoft::ref_ptr<ITypeInfo> m_ti;
    resource_type*              m_resource;
};

/** Scoping class for TYPEATTR
 */
typedef TypeInfo_resource_scope<ximpl_comstl_typelib_TypeInfo_resource_scope_util_::TYPEATTR_traits>    TYPEATTR_scope;

/** Scoping class for VARDESC
 */
typedef TypeInfo_resource_scope<ximpl_comstl_typelib_TypeInfo_resource_scope_util_::VARDESC_traits>     VARDESC_scope;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace stlsoft::comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_TYPELIB_HPP_TYPEINFO_RESOURCE_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

