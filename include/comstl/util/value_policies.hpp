/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/value_policies.hpp (originally MOEnSeq.h, ::SynesisCom)
 *
 * Purpose:     Value policies that work with STL sequence types for IEnumXXXX
 *              enumerator interfaces.
 *
 * Created:     17th September 1998
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/util/value_policies.hpp
 *
 * \brief [C++; requires COM] Value policies for various COM types
 *   (\ref group__library__COM_Utility "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_HPP_VALUE_POLICIES
#define COMSTL_INCL_COMSTL_UTIL_HPP_VALUE_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_HPP_VALUE_POLICIES_MAJOR    5
# define COMSTL_VER_COMSTL_UTIL_HPP_VALUE_POLICIES_MINOR    1
# define COMSTL_VER_COMSTL_UTIL_HPP_VALUE_POLICIES_REVISION 8
# define COMSTL_VER_COMSTL_UTIL_HPP_VALUE_POLICIES_EDIT     179
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

#ifndef COMSTL_INCL_COMSTL_STRING_H_OLESTRING_FUNCTIONS
# include <comstl/string/olestring_functions.h>   // for olestring_dup(), etc.
#endif /* !COMSTL_INCL_COMSTL_STRING_H_OLESTRING_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION
#  include <comstl/exception/comstl_exception.hpp>
# endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

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

/** Value policy for GUID
 *
 * \ingroup group__library__COM_Utility
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
struct GUID_policy
{
public:
    typedef GUID        value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of the <code>GUID</code> type, this is a no-op
    static void init(value_type* ) STLSOFT_NOEXCEPT
    {}
    /// Initialises an instance from another
    ///
    /// In the case of the <code>GUID</code> type, this is a straight
    /// byte-for-byte copy
    static void copy(value_type* dest, value_type const* src)
    {
        *dest = *src;
    }
    /// Releases an instance
    ///
    /// In the case of the <code>GUID</code> type, this is a no-op
    static void clear(value_type* ) STLSOFT_NOEXCEPT
    {}
};


/** Value policy for BSTR
 *
 * \ingroup group__library__COM_Utility
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
struct BSTR_policy
{
public:
    typedef BSTR    value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of the <code>BSTR</code> type, this involves setting
    /// the value to NULL
    static void init(value_type* p) STLSOFT_NOEXCEPT
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    ///
    /// In the case of the <code>BSTR</code> type, this involves calling
    /// <code>SysAllocString()</code>
    ///
    /// \exception comstl::comstl_exception If exception support is enabled,
    ///   an instance of <code>comstl::comstl_exception</code> will be
    ///   thrown if the copy cannot be made
    static void copy(value_type* dest, value_type const* src)
    {
        *dest = ::SysAllocString(*src);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if (NULL == *dest &&
            NULL != *src &&
            L'\0' != (*src)[0])
        {
            STLSOFT_THROW_X(comstl_exception("failed to copy BSTR", E_OUTOFMEMORY));
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    /// Releases an instance
    ///
    /// In the case of the <code>BSTR</code> type, this involves calling
    /// <code>SysFreeString()</code>
    static void clear(value_type* p) STLSOFT_NOEXCEPT
    {
        ::SysFreeString(*p);
    }
};


/** Value policy for LPOLESTR
 *
 * \ingroup group__library__COM_Utility
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
struct LPOLESTR_policy
{
public:
    typedef LPOLESTR    value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of the OLE string type, this involves setting
    /// the value to NULL
    static void init(value_type* p) STLSOFT_NOEXCEPT
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    ///
    /// In the case of the OLE string type, this involves calling
    /// <code>olestring_dup()</code>
    ///
    /// \exception comstl::comstl_exception If exception support is enabled,
    ///   an instance of <code>comstl::comstl_exception</code> will be
    ///   thrown if the copy cannot be made
    static void copy(value_type* dest, value_type const* src)
    {
        *dest = olestring_dup(*src);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if (NULL == *dest &&
            NULL != *src)
        {
            STLSOFT_THROW_X(comstl_exception("failed to copy OLE string", E_OUTOFMEMORY));
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    /// Releases an instance
    ///
    /// In the case of the OLE string type, this involves calling
    /// <code>olestring_destroy()</code>
    static void clear(value_type* p) STLSOFT_NOEXCEPT
    {
        olestring_destroy(*p);
    }
};


/** Value policy for VARIANT
 *
 * \ingroup group__library__COM_Utility
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
struct VARIANT_policy
{
public:
    typedef VARIANT value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of the <code>VARIANT</code> type, this involves calling
    /// <code>VariantInit()</code>
    static void init(value_type* p) STLSOFT_NOEXCEPT
    {
        ::VariantInit(p);
    }
    /// Initialises an instance from another
    ///
    /// In the case of the <code>VARIANT</code> type, this involves calling
    /// <code>VariantCopy()</code>
    ///
    /// \exception comstl::comstl_exception If exception support is enabled,
    ///   an instance of <code>comstl::comstl_exception</code> will be
    ///   thrown if the copy cannot be made
    static void copy(value_type* dest, value_type const* src)
    {
        HRESULT hr = ::VariantCopy(dest, const_cast<VARIANT*>(src));

        if (FAILED(hr))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(comstl_exception("failed to copy VARIANT", hr));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    /// Releases an instance
    ///
    /// In the case of the <code>VARIANT</code> type, this involves calling
    /// <code>VariantClear()</code>
    static void clear(value_type* p) STLSOFT_NOEXCEPT
    {
        ::VariantClear(p);
    }
};


/** Value policy for interface
 *
 * \ingroup group__library__COM_Utility
 *
 * \param I The interface
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
template <ss_typename_param_k I>
struct interface_policy
{
public:
    typedef I               interface_type;
    typedef interface_type* value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of an interface pointer type, this involves setting
    /// the value to NULL
    static void init(value_type* p) STLSOFT_NOEXCEPT
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    ///
    /// In the case of an interface pointer type, this involves taking a
    /// copy of the pointer and, if the source is non-NULL, invoking
    /// <code>AddRef()</code>
    static void copy(value_type* dest, value_type const* src)
    {
        *dest = *src;
        if (NULL != *dest)
        {
            (*dest)->AddRef();
        }
    }
    /// Releases an instance
    ///
    /// In the case of an interface pointer type, this involves
    /// invoking <code>Release()</code> and setting the value to NULL
    /// (unless it is already NULL)
    static void clear(value_type* p) STLSOFT_NOEXCEPT
    {
        if (NULL != *p)
        {
            (*p)->Release();
            *p = NULL;
        }
    }
};


/** Value policy for LPUNKNOWN
 *
 * \ingroup group__library__COM_Utility
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
struct LPUNKNOWN_policy
{
public:
    typedef LPUNKNOWN   value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of the <code>LPUNKNOWN</code> type, this involves setting
    /// the value to NULL
    static void init(value_type* p) STLSOFT_NOEXCEPT
    {
        *p = NULL;
    }
    /// Initialises an instance from another
    ///
    /// In the case of the <code>LPUNKNOWN</code> type, this involves taking
    /// a copy of the pointer and, if the source is non-NULL, invoking
    /// <code>AddRef()</code>
    static void copy(value_type* dest, value_type const* src)
    {
        *dest = *src;
        if (NULL != *dest)
        {
            (*dest)->AddRef();
        }
    }
    /// Releases an instance
    ///
    /// In the case of the <code>LPUNKNOWN</code> type, this involves
    /// invoking <code>Release()</code> and setting the value to NULL
    /// (unless it is already NULL)
    static void clear(value_type* p) STLSOFT_NOEXCEPT
    {
        if (NULL != *p)
        {
            (*p)->Release();
            *p = NULL;
        }
    }
};


/** Value policy for STATSTG
 *
 * \ingroup group__library__COM_Utility
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
struct STATSTG_policy
{
public:
    typedef STATSTG value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of the <code>STATSTG</code> type, this involves setting
    /// the <code>pwcsName</code> member to NULL
    static void init(value_type* p) STLSOFT_NOEXCEPT
    {
        p->pwcsName = NULL;
    }
    /// Initialises an instance from another
    ///
    /// In the case of the <code>STATSTG</code> type, this involves a
    /// straight byte-for-byte copy of the structure contents, following by
    /// invoking <code>olestring_dup()</code> on the <code>pwcsName</code>
    /// member, to obtain a deep copy
    ///
    /// \exception comstl::comstl_exception If exception support is enabled,
    ///   an instance of <code>comstl::comstl_exception</code> will be
    ///   thrown if the copy cannot be made
    static void copy(value_type* dest, value_type const* src)
    {
        *dest = *src;
        if (NULL != src->pwcsName)
        {
            dest->pwcsName = olestring_dup(src->pwcsName);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            if (NULL == dest->pwcsName)
            {
                STLSOFT_THROW_X(comstl_exception("failed to copy OLE string when copying STATSTG", E_OUTOFMEMORY));
            }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        };
    }
    /// Releases an instance
    ///
    /// In the case of the <code>STATSTG</code> type, this involves invoking
    /// <code>olestring_destroy()</code> on the <code>pwcsName</code> member
    static void clear(value_type* p) STLSOFT_NOEXCEPT
    {
        olestring_destroy(p->pwcsName);
    }
};


/** Value policy for FORMATETC
 *
 * \ingroup group__library__COM_Utility
 *
 * \sa comstl::collection_sequence
 * \sa comstl::enumerator_sequence
 */
struct FORMATETC_policy
{
public:
    typedef FORMATETC   value_type;

public:
    /// Initialises an instance
    ///
    /// In the case of the <code>FORMATETC</code> type, this involves setting
    /// the <code>ptd</code> member to NULL
    static void init(value_type* p) STLSOFT_NOEXCEPT
    {
        p->ptd = NULL;
    }
    /// Initialises an instance from another
    ///
    /// In the case of the <code>FORMATETC</code> type, this involves a
    /// straight byte-for-byte copy of the structure contents, following by
    /// invoking <code>CoTaskMemAlloc()</code> on the <code>ptd</code>
    /// member, to obtain a deep copy
    ///
    /// \exception comstl::comstl_exception If exception support is enabled,
    ///   an instance of <code>comstl::comstl_exception</code> will be
    ///   thrown if the copy cannot be made
    static void copy(value_type* dest, value_type const* src)
    {
        *dest = *src;
        if (NULL != dest->ptd)
        {
            dest->ptd = static_cast<DVTARGETDEVICE*>(::CoTaskMemAlloc(src->ptd->tdSize));

            if (NULL == dest->ptd)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_THROW_X(comstl_exception("failed to copy DVTARGETDEVICE when copying FORMATETC", E_OUTOFMEMORY));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
            else
            {
                BYTE const* src_begin   =   STLSOFT_NS_QUAL(sap_cast)<BYTE const*>(&src->ptd);
                BYTE const* src_end     =   src_begin + src->ptd->tdSize;
                BYTE*       dest_begin  =   STLSOFT_NS_QUAL(sap_cast)<BYTE*>(&dest->ptd);

                for (; src_begin != src_end; ++src_begin, ++dest_begin)
                {
                    *dest_begin = *src_begin;
                }
            }
        }
    }
    /// Releases an instance
    ///
    /// In the case of the <code>FORMATETC</code> type, this involves invoking
    /// <code>CoTaskMemFree()</code> on the <code>ptd</code> member
    static void clear(value_type* p) STLSOFT_NOEXCEPT
    {
        ::CoTaskMemFree(p->ptd);
    }
};

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_VALUE_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

