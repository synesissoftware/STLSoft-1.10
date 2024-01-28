/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/CY_functions.h
 *
 * Purpose:     CY helper functions.
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


/** \file comstl/util/CY_functions.h
 *
 * \brief [C++; requires COM] CY helper functions
 *   (\ref group__library__COM_Utility "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_H_CY_FUNCTIONS
#define COMSTL_INCL_COMSTL_UTIL_H_CY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_H_CY_FUNCTIONS_MAJOR       1
# define COMSTL_VER_COMSTL_UTIL_H_CY_FUNCTIONS_MINOR       1
# define COMSTL_VER_COMSTL_UTIL_H_CY_FUNCTIONS_REVISION    2
# define COMSTL_VER_COMSTL_UTIL_H_CY_FUNCTIONS_EDIT        16
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

/** [C] Compares two CY structures
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
comstl_C_CY_compare(
    CY const*   lhs
,   CY const*   rhs
) STLSOFT_NOEXCEPT
{
    COMSTL_MESSAGE_ASSERT("Cannot pass NULL pointer(s) to CY_compare()", (NULL != lhs && NULL != rhs));

    if (lhs->Hi != rhs->Hi)
    {
        if (lhs->Hi < rhs->Hi)
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
        if (lhs->Lo < rhs->Lo)
        {
            return -1;
        }
        else
        {
            return +1;
        }
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * backwards compatibility
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(comstl__CY_compare, comstl_C_CY_compare)
STLSOFT_INLINE
int
comstl__CY_compare(
    CY const*   lhs
,   CY const*   rhs
) STLSOFT_NOEXCEPT
{
    return comstl_C_CY_compare(lhs, rhs);
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

/** [C++] Compares two CY structures
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
CY_compare(
    CY const*   lhs
,   CY const*   rhs
)
{
    return comstl_C_CY_compare(lhs, rhs);
}

/** [C++] Compares two CY structures
 *
 * \ingroup group__library__COM_Utility
 *
 * \param lhs Reference to the left-hand instances to compare
 * \param rhs Reference to the right-hand instances to compare
 */
inline
int
CY_compare(
    CY const&   lhs
,   CY const&   rhs
)
{
    return comstl_C_CY_compare(&lhs, &rhs);
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

#endif /* !COMSTL_INCL_COMSTL_UTIL_H_CY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

