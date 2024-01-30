/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/VARIANT_functions.h
 *
 * Purpose:     VARIANT helper functions.
 *
 * Created:     23rd August 2008
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/util/VARIANT_functions.h
 *
 * \brief [C++; requires COM] VARIANT helper functions
 *   (\ref group__library__COM_Utility "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_H_VARIANT_FUNCTIONS
#define COMSTL_INCL_COMSTL_UTIL_H_VARIANT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_H_VARIANT_FUNCTIONS_MAJOR       1
# define COMSTL_VER_COMSTL_UTIL_H_VARIANT_FUNCTIONS_MINOR       2
# define COMSTL_VER_COMSTL_UTIL_H_VARIANT_FUNCTIONS_REVISION    2
# define COMSTL_VER_COMSTL_UTIL_H_VARIANT_FUNCTIONS_EDIT        20
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

#ifndef COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS
# include <comstl/string/BSTR_functions.h>
#endif /* !COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_UTIL_H_CY_FUNCTIONS
# include <comstl/util/CY_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_CY_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_UTIL_H_DECIMAL_FUNCTIONS
# include <comstl/util/DECIMAL_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_DECIMAL_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_UTIL_H_OBJECT_FUNCTIONS
# include <comstl/util/object_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_OBJECT_FUNCTIONS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(COMSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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
 * C functions
 */

/** [C] Indicates whether two VARIANT structures are equal
 *
 * \ingroup group__library__COM_Utility
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param rhs Pointer to the right-hand instances to compare
 * \param comparisonSucceeded Pointer to a result-code instance that will have
 *   an HRESULT value not equal to S_OK if the comparison cannot be made. May
 *   be NULL if the caller does not care
 *
 * \return a value indicating whether the values are equal
 * \retval 0 The structures are not equal
 * \retval >0 The structures are equal
 *
 * \pre \c lhs must not be NULL.
 * \pre \c rhs must not be NULL.
 */
STLSOFT_INLINE
int
comstl_C_VARIANT_equal(
    VARIANT const*  lhs
,   VARIANT const*  rhs
,   HRESULT*        comparisonSucceeded
)
{
    HRESULT comparisonSucceeded_;

    COMSTL_MESSAGE_ASSERT("Cannot pass NULL pointer(s) to VARIANT_compare()", (NULL != lhs && NULL != rhs));

    /* Use the Null Object (Variable) pattern to relieve rest of code
     * of burden of knowing whether value required by caller
     */
    if (NULL == comparisonSucceeded)
    {
        comparisonSucceeded = &comparisonSucceeded_;
    }

    *comparisonSucceeded = S_OK;

    if (COMSTL_ACCESS_VARIANT_vt_BYPTR(lhs) != COMSTL_ACCESS_VARIANT_vt_BYPTR(rhs))
    {
        return 0;
    }
    else
    {
        switch (COMSTL_ACCESS_VARIANT_vt_BYPTR(lhs))
        {
            case    VT_EMPTY:
            case    VT_NULL:
                return 1;
            case    VT_I1:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, cVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, cVal);
            case    VT_UI1:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, bVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, bVal);
            case    VT_I2:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, iVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, iVal);
            case    VT_UI2:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, uiVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, uiVal);
            case    VT_I4:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, lVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, lVal);
            case    VT_UI4:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, ulVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, ulVal);
            case    VT_INT:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, intVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, intVal);
            case    VT_UINT:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, uintVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, uintVal);
            case    VT_R4:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, fltVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, fltVal);
            case    VT_R8:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, dblVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, dblVal);
            case    VT_BOOL:
                return (VARIANT_FALSE != COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, boolVal)) == (VARIANT_FALSE != COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, boolVal));
            case    VT_BSTR:
                return 0 == comstl_C_BSTR_compare(COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, bstrVal), COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, bstrVal));
            case    VT_ERROR:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, scode) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, scode);
            case    VT_DECIMAL:
                return 0 == comstl_C_DECIMAL_compare(&COMSTL_ACCESS_VARIANT_decVal_BYPTR(lhs), &COMSTL_ACCESS_VARIANT_decVal_BYPTR(rhs));
            case    VT_CY:
                return 0 == comstl_C_CY_compare(&COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, cyVal), &COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, cyVal));
            case    VT_UNKNOWN:
                return (COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, punkVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, punkVal)) || (S_OK == comstl_C_is_same_object(COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, punkVal), COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, punkVal)));
            case    VT_DISPATCH:
                return (COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, pdispVal) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, pdispVal)) || (S_OK == comstl_C_is_same_object(stlsoft_static_cast(LPUNKNOWN, COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, pdispVal)), stlsoft_static_cast(LPUNKNOWN, COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, pdispVal))));
            case    VT_DATE:
                return COMSTL_ACCESS_VARIANT_MEM_BYPTR(lhs, date) == COMSTL_ACCESS_VARIANT_MEM_BYPTR(rhs, date);
#if 0
            case    VT_VARIANT:
            case    VT_RECORD:
#endif /* 0 */
            default:
                *comparisonSucceeded = E_NOTIMPL;
                break;
        }
    }

    return 0;
}

/** [C] Converts a variant from one type to another
 *
 * \ingroup group__library__COM_Utility
 *
 * \param dest Pointer to the VARIANT to receive the coerced value
 * \param src Pointer to the source VARIANT
 * \param lcid The LCID for the coercion
 * \param flags Flags that moderate the coercion; see the MSDN documentation
 *   for <code>VariantChangeTypeEx()</code>
 * \param vt The type to coerce to
 *
 * Equivalent to <code>VariantChangeTypeEx()</code>, except that in the case
 * where the source VARIANT type is <code>VT_UNKNOWN</code>, the function
 * will query for the <code>IDispatch</code> and, if retrieved, attempt the
 * coercion on it.
 */
STLSOFT_INLINE
HRESULT
comstl_C_VARIANT_change_type(
    VARIANT*        dest
,   VARIANT const*  src
,   LCID            lcid
,   USHORT          flags
,   VARTYPE         vt
)
{
    HRESULT hr = STLSOFT_NS_GLOBAL(VariantChangeTypeEx)(dest, stlsoft_const_cast(VARIANT*, src), lcid, flags, vt);

    if (FAILED(hr) &&
        0 == (VARIANT_NOVALUEPROP & flags))
    {
        if (VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYPTR(src) &&
            NULL != COMSTL_ACCESS_VARIANT_MEM_BYPTR(src, punkVal))
        {
            /* Try to elicit IDispatch interface */
            VARIANT src2;
            HRESULT hr2;

            COMSTL_ACCESS_VARIANT_vt_BYREF(src2) = VT_DISPATCH;

            hr2 = COMSTL_ITF_CALL(COMSTL_ACCESS_VARIANT_MEM_BYPTR(src, punkVal))->QueryInterface(COMSTL_ITF_THIS(COMSTL_ACCESS_VARIANT_MEM_BYPTR(src, punkVal)) COMSTL_IID_2_REF(IID_IDispatch), stlsoft_reinterpret_cast(void**, &COMSTL_ACCESS_VARIANT_MEM_BYREF(src2, pdispVal)));

            if (SUCCEEDED(hr2))
            {
                hr = comstl_C_VARIANT_change_type(dest, &src2, lcid, flags, vt);

                COMSTL_ITF_CALL(COMSTL_ACCESS_VARIANT_MEM_BYREF(src2, pdispVal))->Release(COMSTL_ITF_THIS0(COMSTL_ACCESS_VARIANT_MEM_BYREF(src2, pdispVal)));
            }
        }
    }

    return hr;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace comstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** [C++] Indicates whether two VARIANT structures are equal
 *
 * \ingroup group__library__COM_Utility
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param rhs Pointer to the right-hand instances to compare
 * \param comparisonSucceeded Pointer to a result-code instance that will have
 *   an HRESULT value not equal to S_OK if the comparison cannot be made. May
 *   be NULL if the caller does not care
 *
 * \return a value indicating whether the values are equal
 * \retval 0 The structures are not equal
 * \retval >0 The structures are equal
 *
 * \pre \c lhs must not be NULL.
 * \pre \c rhs must not be NULL.
 */
inline
bool
VARIANT_equal(
    VARIANT const*  lhs
,   VARIANT const*  rhs
,   HRESULT*        comparisonSucceeded
)
{
    return 0 != comstl_C_VARIANT_equal(lhs, rhs, comparisonSucceeded);
}

/** [C++] Indicates whether two VARIANT structures are equal
 *
 * \ingroup group__library__COM_Utility
 *
 * \param lhs Reference to the left-hand instances to compare
 * \param rhs Reference to the right-hand instances to compare
 * \param comparisonSucceeded Pointer to a result-code instance that will have
 *   an HRESULT value not equal to S_OK if the comparison cannot be made. May
 *   be NULL if the caller does not care
 *
 * \return a value indicating whether the values are equal
 * \retval 0 The structures are not equal
 * \retval >0 The structures are equal
 */
inline
bool
VARIANT_equal(
    VARIANT const&  lhs
,   VARIANT const&  rhs
,   HRESULT*        comparisonSucceeded
)
{
    return 0 != comstl_C_VARIANT_equal(&lhs, &rhs, comparisonSucceeded);
}

inline
HRESULT
VARIANT_change_type(
    VARIANT*        dest
,   VARIANT const*  src
,   LCID            lcid
,   USHORT          flags
,   VARTYPE         vt
)
{
    return comstl_C_VARIANT_change_type(dest, src, lcid, flags, vt);
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * backwards compatibility
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(comstl__VARIANT_equal, comstl_C_VARIANT_equal)
STLSOFT_INLINE
int
comstl__VARIANT_equal(
    VARIANT const*  lhs
,   VARIANT const*  rhs
,   HRESULT*        comparisonSucceeded
)
{
    return comstl_C_VARIANT_equal(lhs, rhs, comparisonSucceeded);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !COMSTL_INCL_COMSTL_UTIL_H_VARIANT_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

