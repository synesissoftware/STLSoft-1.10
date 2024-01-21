/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/integral_printf_traits.hpp (formerly stlsoft/util/printf_traits.hpp)
 *
 * Purpose:     integral_printf_traits classes.
 *
 * Created:     16th January 2002
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/util/integral_printf_traits.hpp
 *
 * \brief [C++] Definition of the stlsoft::integral_printf_traits class
 *   template
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_TRAITS
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_TRAITS_MAJOR      6
# define STLSOFT_VER_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_TRAITS_MINOR      0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_TRAITS_REVISION   8
# define STLSOFT_VER_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_TRAITS_EDIT       85
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
# error stlsoft/util/integral_printf_traits.hpp is obsolete; instead include stlsoft/traits/integral_printf_format_traits.hpp and use integral_printf_format_traits (rather than integral_printf_traits)
#else /* ? obsolete */
# ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS
#  include <stlsoft/traits/integral_printf_format_traits.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS */
# ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS
#  include <stlsoft/limits/integral_format_width_limits.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS */
# ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE
#  include <stlsoft/meta/is_signed_type.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE */
#endif /* obsolete */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Constants & definitions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT8_MIN           -128
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT8_MAX           127

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT8_MIN           0
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT8_MAX           255

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MIN          -32768
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MAX          32767

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MIN          0
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MAX          65535

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT32_MIN          -2147483648
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT32_MAX          2147483647

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT32_MIN          0
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT32_MAX          4294967295

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MIN          -9223372036854775808
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MAX          9223372036854775807

# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MIN          0
# define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MAX          18446744073709551615



 /* char */
# if _STLSOFT_SIZEOF_CHAR == 1

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_SCHAR_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT8_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_SCHAR_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT8_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UCHAR_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT8_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UCHAR_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT8_MAX

#  ifdef STLSOFT_CF_CHAR_IS_UNSIGNED
#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_CHAR_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_UCHAR_MIN
#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_CHAR_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_UCHAR_MAX
#  else /* ? STLSOFT_CF_CHAR_IS_UNSIGNED */
#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_CHAR_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_SCHAR_MIN
#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_CHAR_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_SCHAR_MAX
#  endif /* STLSOFT_CF_CHAR_IS_UNSIGNED */

# else /* ? _STLSOFT_SIZEOF_CHAR */
#  error Cannot operate with a compiler for which sizeof(char) != 1
# endif /* _STLSOFT_SIZEOF_CHAR */


 /* short */
# if _STLSOFT_SIZEOF_SHORT == 2

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_SHORT_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_SHORT_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_USHORT_MIN         STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_USHORT_MAX         STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MAX

# elif _STLSOFT_SIZEOF_SHORT == 4

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_SHORT_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_SHORT_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_USHORT_MIN         STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_USHORT_MAX         STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MAX

# else /* ? _STLSOFT_SIZEOF_SHORT */
#  error Cannot operate with a compiler for which sizeof(short) != 2 && sizeof(short) != 4
# endif /* _STLSOFT_SIZEOF_SHORT */


 /* int */
# if _STLSOFT_SIZEOF_INT == 2

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_INT_MIN            STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_INT_MAX            STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT_MIN           STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT_MAX           STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MAX

# elif _STLSOFT_SIZEOF_INT == 4

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_INT_MIN            STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT32_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_INT_MAX            STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT32_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT_MIN           STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT32_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT_MAX           STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT32_MAX

# elif _STLSOFT_SIZEOF_INT == 8

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_INT_MIN            STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_INT_MAX            STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT_MIN           STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT_MAX           STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MAX

# else /* ? _STLSOFT_SIZEOF_INT */
#  error Cannot operate with a compiler for which sizeof(int) != 2 && sizeof(int) != 4 && sizeof(int) != 8
# endif /* _STLSOFT_SIZEOF_INT */


 /* long */
# if _STLSOFT_SIZEOF_LONG == 2

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MIN           STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MAX           STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT16_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT16_MAX

# elif _STLSOFT_SIZEOF_LONG == 4

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MIN           STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT32_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MAX           STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT32_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT32_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT32_MAX

# elif _STLSOFT_SIZEOF_LONG == 8

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MIN           STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MAX           STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MAX

#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MIN          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MIN
#  define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MAX          STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MAX

# else /* ? _STLSOFT_SIZEOF_LONG */
#  error Cannot operate with a compiler for which sizeof(long) != 2 && sizeof(long) != 4 && sizeof(long) != 8
# endif /* _STLSOFT_SIZEOF_LONG */


 /* long long */
# ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
#  if _STLSOFT_SIZEOF_LONG_LONG == 8

#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_LONG_MIN     STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MIN
#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_LONG_MAX     STLSOFT_INTEGRAL_PRINTF_TRAITS_SINT64_MAX

#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_LONG_MIN    STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MIN
#   define STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_LONG_MAX    STLSOFT_INTEGRAL_PRINTF_TRAITS_UINT64_MAX

#  else /* ? _STLSOFT_SIZEOF_LONG_LONG */
#   error Cannot operate with a compiler for which sizeof(long long) != 8
#  endif /* _STLSOFT_SIZEOF_LONG_LONG */
# endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// struct integral_printf_traits

/** [DEPRECATED] Traits for determining the size, in printf-ed form, of the minimum and
 * maximum values of types
 *
 * \ingroup group__library__Utility
 *
 * \deprecated This class template is deprecated, and will be removed in a
 *   future version of STLSoft.
 */
template <ss_typename_param_k T>
struct integral_printf_traits
    : public integral_printf_format_traits<T>
    , public integral_format_width_limits<T>
{
private:
    enum
    {
        typeIsSigned = is_signed_type<T>::value
    };

public:
    enum
    {
            size_min = 1 + (typeIsSigned ? integral_format_width_limits<T>::maxDecimalWidth : 1)
        ,   size_max = 1 + integral_format_width_limits<T>::maxDecimalWidthWithoutSign
#if 0

            // This is the original logic (left in for revisibility), but ...
        ,   size = (size_min < size_max) ? size_max : size_min
#else
            // ... this is the form required by Borland, presumably because it
            // sees a '<' as doing something templatey.
        ,   size = (size_max > size_min) ? size_max : size_min
#endif
    };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_printf_traits<char>
#ifdef STLSOFT_CF_char_IS_UNSIGNED
    : public integral_printf_traits<unsigned char>
#else /* ? STLSOFT_CF_char_IS_UNSIGNED */
    : public integral_printf_traits<signed char>
#endif /* STLSOFT_CF_char_IS_UNSIGNED */
{};

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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

