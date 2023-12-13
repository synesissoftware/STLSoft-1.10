/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/limits/integral_limits.hpp (formerly stlsoft/util/limit_traits.h; originally MLLimits.h; ::SynesisStd)
 *
 * Purpose:     integral_limits traits classes. Provides nothing that is
 *              not in std::integral_limits, but uses minimum() and
 *              maximum() rather than min() and max(), since some compilers
 *              are not well-behaved in making these functions rather than
 *              macros.
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


/** \file stlsoft/limits/integral_limits.hpp
 *
 * \brief [C++] Integral macros, constants and
 *   traits (stlsoft::integral_limits) classes
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS
#define STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS_MAJOR       5
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS_MINOR       0
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS_REVISION    6
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS_EDIT        72
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

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.h>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS */

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

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** Traits for determining the minimum and maximum values of types
 *
 * \ingroup group__library__Utility
 *
 * integral_limits is a traits class for acquiring the minimum and maximum values
 * of types.
 *
\code
  assert(stlsoft::integral_limits<ss_sint16_t>::minimum() == -32768);
  assert(stlsoft::integral_limits<ss_sint16_t>::maximum() == 32767);
\endcode
 * \param T The type
 *
 * \note Provides nothing that is not in std::integral_limits, but uses
 *   minimum() and maximum() rather than min() and max(), since some
 *   compilers are not well-behaved in making these functions rather than
 *   macros.
 *
 */
template <ss_typename_param_k T>
struct integral_limits
{
public:
    /** The value type */
    typedef T   value_type;

public:
    /** Returns the minimum value for the type */
    static value_type       minimum();
    /** Returns the maximum value for the type */
    static value_type       maximum();

# ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = ???;
    static const value_type maximum_value = ???;
# endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* struct integral_limits */

template <ss_typename_param_k T>
struct integral_limits;

#ifdef STLSOFT_CF_NATIVE_BOOL_SUPPORT

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_bool_t>
{
public:
    typedef ss_bool_t  value_type;

public:
    static value_type       minimum() { return false; }
    static value_type       maximum() { return true; }

# ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = false;
    static const value_type maximum_value = true;
# endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

#endif /* STLSOFT_CF_NATIVE_BOOL_SUPPORT */

STLSOFT_OPEN_WORKER_NS_(ximpl_stlsoft_integral_limits)

template <ss_typename_param_k T>
struct limit_traits_fixed;

/* s/uint8 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint8_t>
{
public:
    typedef ss_sint8_t  value_type;

public:
    static value_type       minimum() { return STLSOFT_INTEGRAL_LIMIT_SINT8_MIN; }
    static value_type       maximum() { return STLSOFT_INTEGRAL_LIMIT_SINT8_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_SINT8_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_SINT8_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint8_t>
{
public:
    typedef ss_uint8_t  value_type;

public:
    static value_type   minimum() { return STLSOFT_INTEGRAL_LIMIT_UINT8_MIN; }
    static value_type   maximum() { return STLSOFT_INTEGRAL_LIMIT_UINT8_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_UINT8_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_UINT8_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

/* s/uint16 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint16_t>
{
public:
    typedef ss_sint16_t value_type;

public:
    static value_type   minimum() { return STLSOFT_INTEGRAL_LIMIT_SINT16_MIN; }
    static value_type   maximum() { return STLSOFT_INTEGRAL_LIMIT_SINT16_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_SINT16_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_SINT16_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint16_t>
{
public:
    typedef ss_uint16_t value_type;

public:
    static value_type   minimum() { return STLSOFT_INTEGRAL_LIMIT_UINT16_MIN; }
    static value_type   maximum() { return STLSOFT_INTEGRAL_LIMIT_UINT16_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_UINT16_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_UINT16_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

/* s/uint32 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint32_t>
{
public:
    typedef ss_sint32_t value_type;

public:
    static value_type   minimum() { return STLSOFT_INTEGRAL_LIMIT_SINT32_MIN; }
    static value_type   maximum() { return STLSOFT_INTEGRAL_LIMIT_SINT32_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_SINT32_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_SINT32_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint32_t>
{
public:
    typedef ss_uint32_t value_type;

public:
    static value_type   minimum() { return STLSOFT_INTEGRAL_LIMIT_UINT32_MIN; }
    static value_type   maximum() { return STLSOFT_INTEGRAL_LIMIT_UINT32_MAX; }

#  ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_UINT32_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_UINT32_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

/* s/uint64 */
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_sint64_t>
{
public:
    typedef ss_sint64_t value_type;

public:
    static value_type   minimum() { return STLSOFT_INTEGRAL_LIMIT_SINT64_MIN; }
    static value_type   maximum() { return STLSOFT_INTEGRAL_LIMIT_SINT64_MAX; }

#  if defined(STLSOFT_CF_MEMBER_CONSTANT_SUPPORT) && \
      !defined(STLSOFT_COMPILER_IS_BORLAND)
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_SINT64_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_SINT64_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed<ss_uint64_t>
{
public:
    typedef ss_uint64_t value_type;

public:
    static value_type   minimum() { return STLSOFT_INTEGRAL_LIMIT_UINT64_MIN; }
    static value_type   maximum() { return STLSOFT_INTEGRAL_LIMIT_UINT64_MAX; }

#  if defined(STLSOFT_CF_MEMBER_CONSTANT_SUPPORT) && \
      !defined(STLSOFT_COMPILER_IS_BORLAND)
    static const value_type minimum_value = STLSOFT_INTEGRAL_LIMIT_UINT64_MIN;
    static const value_type maximum_value = STLSOFT_INTEGRAL_LIMIT_UINT64_MAX;
#  endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
};
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


template<
    ss_size_t   TypeSizeInBytes
,   ss_bool_t   TypeIsSigned
>
struct limit_traits_fixed_selector;

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<1, true>
{
    typedef limit_traits_fixed<ss_sint8_t>  type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<1, false>
{
    typedef limit_traits_fixed<ss_uint8_t>  type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<2, true>
{
    typedef limit_traits_fixed<ss_sint16_t> type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<2, false>
{
    typedef limit_traits_fixed<ss_uint16_t> type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<4, true>
{
    typedef limit_traits_fixed<ss_sint32_t> type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<4, false>
{
    typedef limit_traits_fixed<ss_uint32_t> type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<8, true>
{
    typedef limit_traits_fixed<ss_sint64_t> type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct limit_traits_fixed_selector<8, false>
{
    typedef limit_traits_fixed<ss_uint64_t> type;
};


STLSOFT_CLOSE_WORKER_NS_(ximpl_stlsoft_integral_limits)

#ifdef STLSOFT_CF_CHAR_DISTINCT_INT_TYPE

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<signed char>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(signed char), true>::type
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<unsigned char>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(unsigned char), false>::type
{};

#endif /* STLSOFT_CF_CHAR_DISTINCT_INT_TYPE */


STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<char>
#ifdef STLSOFT_CF_CHAR_IS_UNSIGNED
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(char), true>::type
#else /* ? STLSOFT_CF_CHAR_IS_UNSIGNED */
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(char), false>::type
#endif /* STLSOFT_CF_CHAR_IS_UNSIGNED */
{};




STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_sint8_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_sint8_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_uint8_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_uint8_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_sint16_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_sint16_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_uint16_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_uint16_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_sint32_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_sint32_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_uint32_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_uint32_t>
{};

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_sint64_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_sint64_t>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<ss_uint64_t>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed)<ss_uint64_t>
{};
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<signed short>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(signed short), true>::type
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<unsigned short>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(unsigned short), false>::type
{};
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<int>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(signed int), true>::type
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<unsigned int>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(unsigned int), false>::type
{};
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<long>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(signed long), true>::type
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_limits<unsigned long>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_limits, limit_traits_fixed_selector)<sizeof(unsigned long), false>::type
{};
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

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

#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS */

/* ///////////////////////////// end of file //////////////////////////// */

