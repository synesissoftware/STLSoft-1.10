/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/limit_traits.h (originally MLLimits.h; ::SynesisStd)
 *
 * Purpose:     limit_traits classes. Provides nothing that is not in
 *              std::numeric_limits, but uses minimum() and maximum() rather
 *              than min() and max(), since some compilers are not
 *              well-behaved in making these functions rather than macros.
 *
 * Created:     16th January 2002
 * Updated:     26th December 2020
 *
 * Thanks:      To Jonathan Wakely for help with Solaris compatibility.
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/** \file stlsoft/util/limit_traits.h
 *
 * \brief [C, C++] Macros, constants and traits (stlsoft::limit_traits) for
 *  classes
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS
#define STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_H_LIMIT_TRAITS_MAJOR    5
# define STLSOFT_VER_STLSOFT_UTIL_H_LIMIT_TRAITS_MINOR    0
# define STLSOFT_VER_STLSOFT_UTIL_H_LIMIT_TRAITS_REVISION 2
# define STLSOFT_VER_STLSOFT_UTIL_H_LIMIT_TRAITS_EDIT     70
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

#if STLSOFT_HEAD_VER >= 0x010a0000 && \
    defined(STLSOFT_ALLOW_OBSOLETE_1_9_IN_1_10)
# if defined(__cplusplus)
#  error stlsoft/util/limit_traits.h is obsolete; instead include stlsoft/limits/integral_limits.hpp and use integral_limits (rather than limit_traits)
# else /* ? __cplusplus */
#  error stlsoft/util/limit_traits.h is obsolete; instead include stlsoft/limits/integral_limits.h
# endif /* __cplusplus */
#else /* ? obsolete */
# if defined(__cplusplus)
#  include <stlsoft/limits/integral_limits.hpp>
# else /* ? __cplusplus */
#  include <stlsoft/limits/integral_limits.h>
# endif /* __cplusplus */
#endif /* obsolete */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef __cplusplus

# ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** [DEPRECATED] Traits for determining the minimum and maximum values of
 * types
 *
 * \ingroup group__library__Utility
 *
 * limit_traits is a traits class for acquiring the minimum and maximum
 * values of types.
 *
\code
  assert(stlsoft::limit_traits<ss_sint16_t>::minimum() == -32768);
  assert(stlsoft::limit_traits<ss_sint16_t>::maximum() == 32767);
\endcode
 * \param T The type
 *
 * \note Provides nothing that is not in std::numeric_limits, but uses
 *   minimum() and maximum() rather than min() and max(), since some
 *   compilers are not well-behaved in making these functions rather than
 *   macros.
 *
 * \deprecated This traits class is deprecated, and will be removed in a
 *   future version of STLSoft; users should instead use integral_traits.
 */
template <ss_typename_param_k T>
struct limit_traits
{
public:
    /** The value type */
    typedef T   value_type;

public:
    /** Returns the minimum value for the type */
    static value_type       minimum();
    /** Returns the maximum value for the type */
    static value_type       maximum();

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = ???;
    static const value_type maximum_value = ???;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

# else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* class limit_traits */

template <ss_typename_param_k T>
struct limit_traits
    : public integral_limits<T>
{};

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#endif /* __cplusplus */

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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

