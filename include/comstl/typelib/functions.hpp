/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/typelib/functions.hpp
 *
 * Purpose:     Functions for manipulating COM Type Libraries.
 *
 * Created:     5th April 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file comstl/typelib/functions.hpp
 *
 * \brief [C++] Functions for manipulating COM Type Libraries.
 */

#ifndef COMSTL_INCL_COMSTL_TYPELIB_HPP_FUNCTIONS
#define COMSTL_INCL_COMSTL_TYPELIB_HPP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_TYPELIB_HPP_FUNCTIONS_MAJOR      1
# define COMSTL_VER_COMSTL_TYPELIB_HPP_FUNCTIONS_MINOR      4
# define COMSTL_VER_COMSTL_TYPELIB_HPP_FUNCTIONS_REVISION   3
# define COMSTL_VER_COMSTL_TYPELIB_HPP_FUNCTIONS_EDIT       84
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

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_M2W
# include <stlsoft/conversion/m2w.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_M2W */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR
# include <stlsoft/smartptr/ref_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */

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

struct ximpl_comstl_typelib_function_util_
{
public:
    static
    HRESULT
    LoadTypeLibEx_(
        cs_char_w_t const*  path
    ,   REGKIND             kind
    ,   ITypeLib**          pptl
    )
    {
        COMSTL_ASSERT(NULL != path);
        COMSTL_ASSERT(NULL != pptl);

        return ::LoadTypeLibEx(path, kind, pptl);
    }
    static
    HRESULT
    LoadTypeLibEx_(
        cs_char_a_t const*  path
    ,   REGKIND             kind
    ,   ITypeLib**          pptl
    )
    {
        COMSTL_ASSERT(NULL != path);
        COMSTL_ASSERT(NULL != pptl);

        return ::LoadTypeLibEx(stlsoft::m2w(path), kind, pptl);
    }
#if 0
    static
    HRESULT
    LoadRegTypeLib_(
        libdesc const&  desc
    ,   ITypeLib**      pptl
    )
    {
        COMSTL_ASSERT(NULL != pptl);

        return ::LoadRegTypeLib(desc.guid, desc.verMajor, desc.verMinor, desc.lcid, pptl);
    }
#else /* ? 0 */
    static
    HRESULT
    LoadRegTypeLib_(
        REFGUID     guid
    ,   USHORT      verMajor
    ,   USHORT      verMinor
    ,   LCID        lcid
    ,   ITypeLib**  pptl
    )
    {
        COMSTL_ASSERT(NULL != pptl);

        return ::LoadRegTypeLib(guid, verMajor, verMinor, lcid, pptl);
    }
#endif /* 0 */
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Loads a type library from the given path, according to the given flags,
 * optionally registering it in the system registry
 *
 * \param path The path of the type-library. May be an instance of any kind
 *   for which the string access shim <b>stlsoft::c_str_ptr</b> is defined
 * \param kind The kind of registration to perform on the library
 * \param typelib A pointer to an instance of
 *   <code>stlsoft::ref_ptr&lt;ITypeLib></code> that will receive the type
 *   library pointer if the operation is successful
 *
 * \return A code indicating the success/failure of the operation
 */
template <typename S>
HRESULT
typelib_load(
    S const&                    path
,   REGKIND                     kind
,   stlsoft::ref_ptr<ITypeLib>* typelib
)
{
    COMSTL_ASSERT(NULL != typelib);

    ITypeLib*   ptl;
    HRESULT     hr = ximpl_comstl_typelib_function_util_::LoadTypeLibEx_(stlsoft::c_str_ptr(path), kind, &ptl);

    if (SUCCEEDED(hr))
    {
        typelib->set(ptl, false);
    }

    return hr;
}

/** Loads a type library from the given GUID, according to the given flags,
 * optionally registering it in the system registry
 *
 * \param guid The GUID of the type library
 * \param verMajor The major version of the type library
 * \param verMinor The minor version of the type library
 * \param lcid The locale to use
 * \param typelib A pointer to an instance of
 *   <code>stlsoft::ref_ptr&lt;ITypeLib></code> that will receive the type
 *   library pointer if the operation is successful
 *
 * \return A code indicating the success/failure of the operation
 */
HRESULT
typelib_load(
    REFGUID                     guid
,   USHORT                      verMajor
,   USHORT                      verMinor
,   LCID                        lcid
,   stlsoft::ref_ptr<ITypeLib>* typelib
)
{
    COMSTL_ASSERT(NULL != typelib);

    ITypeLib*   ptl;
    HRESULT     hr = ximpl_comstl_typelib_function_util_::LoadRegTypeLib_(guid, verMajor, verMinor, lcid, &ptl);

    if (SUCCEEDED(hr))
    {
        typelib->set(ptl, false);
    }

    return hr;
}

/** Finds a name within a type library and load the type information
 * associated with it
 *
 * \param typelib The type library
 * \param name The name of the type within the type library
 * \param id Pointer to a variable to receive the type's identifier
 * \param typeinfo A pointer to an instance of
 *   <code>stlsoft::ref_ptr&lt;ITypeInfo></code> that will receive the type
 *   information pointer if the operation is successful
 *
 * \return A code indicating the success/failure of the operation
 */
HRESULT
typelib_find_name(
    stlsoft::ref_ptr<ITypeLib> const&   typelib
,   LPCOLESTR                           name
,   MEMBERID*                           id
,   stlsoft::ref_ptr<ITypeInfo>*        typeinfo
)
{
    COMSTL_ASSERT(NULL != typelib.get());
    COMSTL_ASSERT(NULL != name);
    COMSTL_ASSERT(NULL != id);
    COMSTL_ASSERT(NULL != typeinfo);

    stlsoft::ref_ptr<ITypeLib>  typelib2(typelib);
    ITypeInfo*                  pti;
    USHORT                      num =   1;
    HRESULT                     hr  =   typelib2->FindName(const_cast<LPOLESTR>(name), 0, &pti, id, &num);

    if (SUCCEEDED(hr))
    {
        typeinfo->set(pti, false);
    }

    return hr;
}

HRESULT
typelib_get_typeinfo(
    stlsoft::ref_ptr<ITypeLib> const&   typelib
,   UINT                                n
,   stlsoft::ref_ptr<ITypeInfo>*        typeinfo
)
{
    stlsoft::ref_ptr<ITypeLib>  typelib2(typelib);
    ITypeInfo*                  pti;
    HRESULT                     hr = typelib2->GetTypeInfo(n, &pti);

    if (SUCCEEDED(hr))
    {
        typeinfo->set(pti, false);
    }

    return hr;
}

HRESULT
typelib_get_name(
    stlsoft::ref_ptr<ITypeLib> const&   typelib
,   UINT                                n
,   BSTR*                               pbstrName
)
{
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != typelib.get(), "type library must not be null");
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != pbstrName, "must pass non-null pointer to receive name");

    return stlsoft::ref_ptr<ITypeLib>(typelib)->GetDocumentation(n, pbstrName, NULL, NULL, NULL);
}

HRESULT
typeinfo_get_name(
    stlsoft::ref_ptr<ITypeInfo> const&  typeinfo
,   MEMBERID                            id
,   BSTR*                               pbstrName
)
{
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != typeinfo.get(), "type information must not be null");
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != pbstrName, "must pass non-null pointer to receive name");

    UINT dummy;

    return stlsoft::ref_ptr<ITypeInfo>(typeinfo)->GetNames(id, pbstrName, 1, &dummy);
}

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

#endif /* !COMSTL_INCL_COMSTL_TYPELIB_HPP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

