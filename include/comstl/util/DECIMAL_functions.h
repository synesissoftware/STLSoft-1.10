/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/DECIMAL_functions.h
 *
 * Purpose:     DECIMAL helper functions.
 *
 * Created:     23rd August 2008
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file comstl/util/DECIMAL_functions.h
 *
 * \brief [C++; requires COM] DECIMAL helper functions
 *   (\ref group__library__COM_Utility "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_H_DECIMAL_FUNCTIONS
#define COMSTL_INCL_COMSTL_UTIL_H_DECIMAL_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_H_DECIMAL_FUNCTIONS_MAJOR       1
# define COMSTL_VER_COMSTL_UTIL_H_DECIMAL_FUNCTIONS_MINOR       0
# define COMSTL_VER_COMSTL_UTIL_H_DECIMAL_FUNCTIONS_REVISION    7
# define COMSTL_VER_COMSTL_UTIL_H_DECIMAL_FUNCTIONS_EDIT        16
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

#ifndef STLSOFT_INCL_H_OAIDL
# define STLSOFT_INCL_H_OAIDL
# include <oaidl.h>
#endif /* !STLSOFT_INCL_H_OAIDL */
#ifndef STLSOFT_INCL_H_WTYPES
# define STLSOFT_INCL_H_WTYPES
# include <wtypes.h>
#endif /* !STLSOFT_INCL_H_WTYPES */

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

/** [C] Compares two DECIMAL structures
 *
 * \ingroup group__library__COM_Utility
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param rhs Pointer to the right-hand instances to compare
 *
 * \pre \c lhs must not be NULL.
 * \pre \c rhs must not be NULL.
 */
STLSOFT_INLINE
int
comstl_C_DECIMAL_compare(
    DECIMAL const* lhs
,   DECIMAL const* rhs
) STLSOFT_NOEXCEPT
{
    COMSTL_MESSAGE_ASSERT("Cannot pass NULL pointer(s) to DECIMAL_compare()", (NULL != lhs && NULL != rhs));
    COMSTL_MESSAGE_ASSERT("invalid sign value in lhs", (0 == lhs->sign || DECIMAL_NEG == lhs->sign));
    COMSTL_MESSAGE_ASSERT("invalid sign value in rhs", (0 == rhs->sign || DECIMAL_NEG == rhs->sign));

    if(lhs->sign != rhs->sign)
    {
        /* signs are different, so we need only check for both being 0,
         * otherwise just return indication of which is -ve
         */

        if( 0 == lhs->Hi32 &&
            0 == rhs->Hi32 &&
            0 == lhs->Mid32 &&
            0 == rhs->Mid32 &&
            0 == lhs->Lo32 &&
            0 == rhs->Lo32)
        {
            return 0;
        }
        else
        {
            if(0 != lhs->sign)
            {
                /* lhs is negative, and rhs is not, so lhs is less */
                return -1;
            }
            else
            {
                return +1;
            }
        }
    }
    else
    {
        /* next see if scale is the same */
        if(lhs->scale != rhs->scale)
        {
            /* This is too-hard, so we convert to VARIANTS and do the check
             * that way
             */
            VARIANT vdecL;
            VARIANT vdecR;
            VARIANT vdblL;
            VARIANT vdblR;

            VariantClear(&vdecL);
            VariantClear(&vdecR);
            VariantClear(&vdblL);
            VariantClear(&vdblR);

            COMSTL_ACCESS_VARIANT_vt_BYREF(vdecL)       =   VT_DECIMAL;
            COMSTL_ACCESS_VARIANT_decVal_BYREF(vdecL)   =   *lhs;

            COMSTL_ACCESS_VARIANT_vt_BYREF(vdecR)       =   VT_DECIMAL;
            COMSTL_ACCESS_VARIANT_decVal_BYREF(vdecR)   =   *rhs;

            VariantChangeType(&vdblL, &vdecL, 0, VT_R8);
            VariantChangeType(&vdblR, &vdecR, 0, VT_R8);

            if(COMSTL_ACCESS_VARIANT_MEM_BYREF(vdblL, dblVal) == COMSTL_ACCESS_VARIANT_MEM_BYREF(vdblR, dblVal))
            {
                return 0;
            }
            else if(COMSTL_ACCESS_VARIANT_MEM_BYREF(vdblL, dblVal) < COMSTL_ACCESS_VARIANT_MEM_BYREF(vdblR, dblVal))
            {
                return -1;
            }
            else
            {
                return +1;
            }
        }
        else
        {
            /* scale is the same, so compare Hi32 first */
            if(lhs->Hi32 != rhs->Hi32)
            {
                return (lhs->Hi32 < rhs->Hi32) ? -1 : +1;
            }
            else
            {
                if(lhs->Mid32 != rhs->Mid32)
                {
                    return (lhs->Mid32 < rhs->Mid32) ? -1 : +1;
                }
                else
                {
                    if(lhs->Lo32 != rhs->Lo32)
                    {
                        return (lhs->Lo32 < rhs->Lo32) ? -1 : +1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * backwards compatibility
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(comstl__DECIMAL_compare, comstl_C_DECIMAL_compare)
STLSOFT_INLINE
int
comstl__DECIMAL_compare(
    DECIMAL const* lhs
,   DECIMAL const* rhs
) STLSOFT_NOEXCEPT
{
    return comstl_C_DECIMAL_compare(lhs, rhs);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

/** [C++] Compares two DECIMAL structures
 *
 * \ingroup group__library__COM_Utility
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param rhs Pointer to the right-hand instances to compare
 *
 * \pre \c lhs must not be NULL.
 * \pre \c rhs must not be NULL.
 */
inline
int
DECIMAL_compare(
    DECIMAL const* lhs
,   DECIMAL const* rhs
) STLSOFT_NOEXCEPT
{
    return comstl_C_DECIMAL_compare(lhs, rhs);
}

/** [C++] Compares two DECIMAL structures
 *
 * \ingroup group__library__COM_Utility
 *
 * \param lhs Reference to the left-hand instances to compare
 * \param rhs Reference to the right-hand instances to compare
 */
inline
int
DECIMAL_compare(
    DECIMAL const& lhs
,   DECIMAL const& rhs
) STLSOFT_NOEXCEPT
{
    return comstl_C_DECIMAL_compare(&lhs, &rhs);
}

#endif /* __cplusplus */

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

#endif /* !COMSTL_INCL_COMSTL_UTIL_H_DECIMAL_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

