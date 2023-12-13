/* /////////////////////////////////////////////////////////////////////////
 * File:        atlstl/automation/property_method_helpers.hpp
 *
 * Purpose:     Contains functions for assisting in the implementation of
 *              property methods of ATL COM server classes.
 *
 * Created:     25th June 2002
 * Updated:     25th November 2020
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


/** \file atlstl/automation/property_method_helpers.hpp
 * \brief [C++; requires ATL library] Definition of the
 *  atlstl::get_MemberValue(), atlstl::put_MemberValue() and
 *  atlstl::get_ConstantValue() function suites, which simplify the
 *  definition of property methods in ATL COM servers
 *   (\ref group__library__COM_Automation "COM Automation" Library).
 */

#ifndef ATLSTL_INCL_ATLSTL_AUTOMATION_HPP_PROPERTY_METHOD_HELPERS
#define ATLSTL_INCL_ATLSTL_AUTOMATION_HPP_PROPERTY_METHOD_HELPERS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_AUTOMATION_HPP_PROPERTY_METHOD_HELPERS_MAJOR    5
# define ATLSTL_VER_ATLSTL_AUTOMATION_HPP_PROPERTY_METHOD_HELPERS_MINOR    0
# define ATLSTL_VER_ATLSTL_AUTOMATION_HPP_PROPERTY_METHOD_HELPERS_REVISION 2
# define ATLSTL_VER_ATLSTL_AUTOMATION_HPP_PROPERTY_METHOD_HELPERS_EDIT     88
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

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# error No recognised Borland compiler generates correct code when used with these functions
#endif /* compiler */

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
 * get_MemberValue
 *
 * This can be used to get a member variable value. The function has the
 * general usage:
 *
 *   HRESULT Class::get_Member(MemberType* ret)
 *   {
 *       return get_MemberValue(this, ret, &Class::m_memberVariable);
 *   }
 */

/** Inline retrieval of member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a pointer to a return value
 * and a pointer to member of the given class, and retrieves the value
 * of the member into the return value.
 *
 * \note This generic version should only be used for built-in types, or
 *   those which have value semantics.
 *
 * \param cls Pointer to the class instance
 * \param ret Pointer to the return value
 * \param mem Pointer to the member variable
 * \return An HRESULT code indicating whether the access succeeded or failed
 * \retval E_POINTER ret was a null pointer
 * \retval S_OK The value was retrieved successfully
 */
template <class C, ss_typename_param_k T>
inline HRESULT get_MemberValue(C* const cls, T* ret, T C::*mem)
{
    return (ret == 0) ? E_POINTER : (*ret = cls->*mem, S_OK);
}

/** Ghost overload to prevent use of get_MemberValue with pointer types
 *
 * \ingroup group__library__COM_Automation
 *
 * This version is overloaded to deal with pointer types, and is not
 * implemented so as to prevent the generic version being used with such types.
 *
 * Although this is inconvenient, there is no other way to prevent the use of
 * free functions. In such circumstances, the shorthand of
 * <code>get_memberValue()</code> must be eschewed for full and congnisant
 * implementation.
 *
 * \note This is deemed worth the inconvenience since using the generic
 *   version would like lead to code that violated COM's memory rules
 *
 */
template <class C, ss_typename_param_k T>
inline HRESULT get_MemberValue(C* const cls, T **ret, T *C::*mem);

/** Inline retrieval of a <code>CComBSTR</code> member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a pointer to a return value
 * and a pointer to a <code>CComBSTR</code> member of the given class, and
 * retrieves the value of the member into the <code>BSTR</code> return
 * value.
 *
 * \param cls Pointer to the class instance
 * \param ret Pointer to the <code>BSTR</code> return value
 * \param mem Pointer to the <code>CComBSTR</code> member variable
 * \return An HRESULT code indicating whether the access succeeded or failed
 * \retval E_POINTER ret was a null pointer
 * \retval E_OUTOFMEMORY Not enough memory to create a copy for the returned
 *   value
 * \retval S_OK The value was retrieved successfully
 */
template <class C>
inline HRESULT get_MemberValue(C* const cls, BSTR* ret, CComBSTR C::*mem)
{
    return (ret == 0) ? E_POINTER : (*ret = (cls->*mem).Copy(), (*ret != 0 ? S_OK :  E_OUTOFMEMORY));
}

/** Inline retrieval of a VARIANT member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a pointer to a return value
 * and a pointer to a <code>CComVariant</code> member of the given class,
 * and retrieves the value of the member into the <code>VARIANT</code>
 * return value.
 *
 * \param cls Pointer to the class instance
 * \param ret Pointer to the <code>VARIANT</code> return value
 * \param mem Pointer to the <code>CComVariant</code> member variable
 * \return An HRESULT code indicating whether the access succeeded or failed
 * \retval E_POINTER ret was a null pointer
 * \retval DISP_E_ARRAYISLOCKED The variant contains an array that is
 *   locked.
 * \retval DISP_E_BADVARTYPE The source and destination have an invalid
 *   variant type (usually uninitialized).
 * \retval E_OUTOFMEMORY Memory could not be allocated for the copy.
 * \retval E_INVALIDARG One of the arguments is invalid.
 * \retval S_OK The value was retrieved successfully
 */
template <class C>
inline HRESULT get_MemberValue(C* const cls, VARIANT* ret, CComVariant C::*mem)
{
    return (ret == 0) ? E_POINTER : ::VariantCopy(ret, &(cls->*mem));
}

/** Inline retrieval of a <code>bool</code> member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a pointer to a return value
 * and a pointer to a <code>bool</code> member of the given class, and
 * retrieves the value of the member into the <code>BOOL</code> return
 * value.
 *
 * \param cls Pointer to the class instance
 * \param ret Pointer to the <code>BOOL</code> return value
 * \param mem Pointer to the <code>bool</code> member variable
 * \return An HRESULT code indicating whether the access succeeded or failed
 * \retval E_POINTER ret was a null pointer
 * \retval E_OUTOFMEMORY Not enough memory to create a copy for the returned value
 * \retval S_OK The value was retrieved successfully
 */
template <class C>
inline HRESULT get_MemberValue(C* const cls, BOOL* ret, bool C::*mem)
{
    return (ret == 0) ? E_POINTER : (*ret = (cls->*mem), S_OK);
}

/** Inline retrieval of a <code>bool</code> member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a pointer to a return value
 * and a pointer to a <code>bool</code> member of the given class, and
 * retrieves the value of the member into the <code>VARIANT_BOOL</code>
 * return value.
 *
 * \param cls Pointer to the class instance
 * \param ret Pointer to the <code>VARIANT_BOOL</code> return value
 * \param mem Pointer to the <code>bool</code> member variable
 * \return An HRESULT code indicating whether the access succeeded or failed
 * \retval E_POINTER ret was a null pointer
 * \retval E_OUTOFMEMORY Not enough memory to create a copy for the returned value
 * \retval S_OK The value was retrieved successfully
 */
template <class C>
inline HRESULT get_MemberValue(C* const cls, VARIANT_BOOL* ret, bool C::*mem)
{
    return (ret == 0) ? E_POINTER : (*ret = (cls->*mem) ? VARIANT_TRUE : VARIANT_FALSE, S_OK);
}



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/* Overloads for specific mismatches between interface and member types*/

/*
 * interface    :   long
 * member       :   size_t
 */
template <class C>
inline
HRESULT
get_MemberValue(
    C* const    pThis
,   long*       ret
,   size_t  C::*mem
)
{
    if (NULL == ret)
    {
        return E_POINTER;
    }
    else
    {
        size_t const v = pThis->*mem;

        if (size_t(integral_limits<long>::maximum()) < v)
        {
            return DISP_E_OVERFLOW;
        }
        else
        {
            *ret = (long)v;

            return S_OK;
        }
    }
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/** Inline retrieval of method value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a pointer to a return value
 * and a pointer to method of the given class, and retrieves the return
 * value of the method into the return value.
 *
 * \note This generic version should only be used for built-in types, or
 *   those which have value semantics.
 *
 * \param cls Pointer to the class instance
 * \param ret Pointer to the return value
 * \param pfn Pointer to the method
 * \return An HRESULT code indicating whether the access succeeded or failed
 * \retval E_POINTER ret was a null pointer
 * \retval S_OK The value was retrieved successfully
 */
template<class C, ss_typename_param_k T, ss_typename_param_k T2>
inline HRESULT get_MemberValue(C* const cls, T* ret, T2 (C::*pfn)() const)
{
    return (ret == 0) ? E_POINTER : (*ret = (cls->*pfn)(), S_OK);
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1400

#  pragma message("try this in VC++ 8+")
# endif
# if 0

/* Overloads for specific mismatches between interface and method types*/

/*
 * interface    :   long
 * method       :   size_t
 */
template <class C>
inline
HRESULT
get_MemberValue(
    C* const    pThis
,   long*       ret
,   size_t (C::*pfn)() const
)
{
    if (NULL == ret)
    {
        return E_POINTER;
    }
    else
    {
        size_t const v = (pThis->*pfn)();

        if (size_t(integral_limits<long>::maximum()) < v)
        {
            return DISP_E_OVERFLOW;
        }
        else
        {
            *ret = (long)v;

            return S_OK;
        }
    }
}
# endif
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * put_MemberValue
 *
 * This can be used to put a member variable value. The function has the
 * general usage:
 *
 *   HRESULT Class::put_Member(MemberType newValue)
 *   {
 *       return put_MemberValue(this, newValue, &Class::m_memberVariable);
 *   }
 */

/** Inline assignment of a member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a new value and a pointer to
 * member of the given class, and assigns the new value to the member.
 *
 * \note This generic version should only be used for built-in types, or
 *   those which have value semantics.
 *
 * \param cls Pointer to the class instance
 * \param newVal The new value
 * \param mem Pointer to the member variable
 * \retval S_OK The value was assigned successfully
 */
template <ss_typename_param_k C, ss_typename_param_k T>
inline HRESULT put_MemberValue(C* const cls, T const& newVal, T C::*mem)
{
    return (cls->*mem = newVal, S_OK);
}

/** Inline assignment of a <code>CComBSTR</code> member variable
 *    value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a new <code>BSTR</code> value
 * and a pointer to <code>CComBSTR</code> member of the given class, and
 * assigns the new value to the member.
 *
 * \param cls Pointer to the class instance
 * \param newVal The new <code>BSTR</code> value
 * \param mem Pointer to the <code>CComBSTR</code> member variable
 * \retval S_OK The value was assigned successfully
 */
template <ss_typename_param_k C>
inline HRESULT put_MemberValue(C* const cls, BSTR newVal, CComBSTR C::*mem)
{
    return (cls->*mem = newVal, S_OK);
}

/** Inline assignment of a <code>CComBSTR</code> member variable
 *    value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a new <code>CComBSTR</code>
 * value and a pointer to <code>CComBSTR</code> member of the given class,
 * and assigns the new value to the member.
 *
 * \param cls Pointer to the class instance
 * \param newVal The new <code>CComBSTR</code> value
 * \param mem Pointer to the <code>CComBSTR</code> member variable
 * \retval S_OK The value was assigned successfully
 */
template <ss_typename_param_k C>
inline HRESULT put_MemberValue(C* const cls, CComBSTR const& newVal, CComBSTR C::*mem)
{
    return put_MemberValue(cls, (BSTR)newVal, mem);
}

/** Inline assignment of a <code>CComVariant</code> member variable
 *    value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a new <code>VARIANT</code>
 * value and a pointer to <code>CComVariant</code> member of the given
 * class, and assigns the new value to the member.
 *
 * \param cls Pointer to the class instance
 * \param newVal The new <code>VARIANT</code> value
 * \param mem Pointer to the <code>CComVariant</code> member variable
 * \retval S_OK The value was assigned successfully
 */
template <ss_typename_param_k C>
inline HRESULT put_MemberValue(C* const cls, VARIANT const& newVal, CComVariant C::*mem)
{
    return (cls->*mem = newVal, (VT_ERROR == (cls->*mem).vt) ? (cls->*mem).scode : S_OK);
}

/** Inline assignment of a Boolean member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a new <code>BOOL</code> value
 * and a pointer to a <code>bool</code> member of the given class, and
 * assigns the new value to the member.
 *
 * \param cls Pointer to the class instance
 * \param newVal The new <code>BOOL</code> value
 * \param mem Pointer to the <code>bool</code> member variable
 * \retval S_OK The value was assigned successfully
 */
template <ss_typename_param_k C>
inline HRESULT put_MemberValue(C* const cls, BOOL const& newVal, bool C::*mem)
{
    return (cls->*mem = (0 != newVal), S_OK);
}

/** Inline assignment of a Boolean member variable value
 *
 * \ingroup group__library__COM_Automation
 *
 * This function takes a pointer to a class, a new <code>VARIANT_BOOL</code>
 * value and a pointer to a <code>bool</code> member of the given class, and
 * assigns the new value to the member.
 *
 * \param cls Pointer to the class instance
 * \param newVal The new <code>VARIANT_BOOL</code> value
 * \param mem Pointer to the <code>bool</code> member variable
 * \retval S_OK The value was assigned successfully
 */
template <ss_typename_param_k C>
inline HRESULT put_MemberValue(C* const cls, VARIANT_BOOL const& newVal, bool C::*mem)
{
    return (cls->*mem = (VARIANT_FALSE != newVal), S_OK);
}







/** Shorthand for implementing methods that return a constant value
 *
 * \ingroup group__library__COM_Automation
 *
 * This method is used to implement methods that return a value of a
 * known constant, e.g.
 *
\code

STDMETHODIMP DatabaseFlags::get_OrderFields(BOOL *pVal)
{
    return atlstl::get_ConstantValue(pVal, openrj::ORJ_FLAG_ORDERFIELDS);
}

\endcode
 *
 * \param ret Pointer to the return value
 * \param value The value to obtain
 *
 */

template <ss_typename_type_k T1, ss_typename_type_k T2>
inline HRESULT get_ConstantValue(T1* ret, T2 const& value)
{
    return (NULL == ret) ? E_POINTER : (*ret = value, S_OK);
}

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

#endif /* !ATLSTL_INCL_ATLSTL_AUTOMATION_HPP_PROPERTY_METHOD_HELPERS */

/* ///////////////////////////// end of file //////////////////////////// */

