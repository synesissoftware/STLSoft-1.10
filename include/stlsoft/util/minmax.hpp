/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/minmax.hpp (originally MLFwdEnm.h)
 *
 * Purpose:     Definition of minimum() and maximum() template functions.
 *
 * Created:     11th April 2005
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/util/minmax.hpp
 *
 * \brief [C++] Definition of the stlsoft::minimum() and
 *   stlsoft::maximum() function templates
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MINMAX_MAJOR       2
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MINMAX_MINOR       1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MINMAX_REVISION    4
# define STLSOFT_VER_STLSOFT_UTIL_HPP_MINMAX_EDIT        25
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Determines the minimum of two values
 *
 * \ingroup group__library__Utility
 *
 * \note This is supplied to avoid problems with libraries that \#define \c min
 */
template <ss_typename_param_k T>
inline T const& minimum(T const& lhs, T const& rhs)
{
    return (lhs < rhs) ? lhs : rhs;
}

/** Determines the maximum of two values
 *
 * \ingroup group__library__Utility
 *
 * \note This is supplied to avoid problems with libraries that \#define \c min
 */
template <ss_typename_param_k T>
inline T const& maximum(T const& lhs, T const& rhs)
{
    return (lhs < rhs) ? rhs : lhs;
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <
    ss_typename_param_k T
>
inline T const& maximum(
    T const& v0
,   T const& v1
,   T const& v2
)
{
    return maximum(maximum(v0, v1), v2);
}

template <
    ss_typename_param_k T
>
inline T const& minimum(
    T const& v0
,   T const& v1
,   T const& v2
)
{
    return minimum(minimum(v0, v1), v2);
}

template <
    ss_typename_param_k T
>
inline T const& maximum(
    T const& v0
,   T const& v1
,   T const& v2
,   T const& v3
)
{
    return maximum(maximum(v0, v1), maximum(v2, v3));
}

template <
    ss_typename_param_k T
>
inline T const& minimum(
    T const& v0
,   T const& v1
,   T const& v2
,   T const& v3
)
{
    return minimum(minimum(v0, v1), minimum(v2, v3));
}

template <
    ss_typename_param_k T
>
inline T const& maximum(
    T const& v0
,   T const& v1
,   T const& v2
,   T const& v3
,   T const& v4
)
{
    return maximum(maximum(maximum(v0, v1), maximum(v2, v3)), v4);
}

template <
    ss_typename_param_k T
>
inline T const& minimum(
    T const& v0
,   T const& v1
,   T const& v2
,   T const& v3
,   T const& v4
)
{
    return minimum(minimum(minimum(v0, v1), minimum(v2, v3)), v4);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX */

/* ///////////////////////////// end of file //////////////////////////// */

