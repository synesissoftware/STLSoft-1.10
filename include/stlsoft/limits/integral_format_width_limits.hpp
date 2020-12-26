/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/limits/integral_format_width_limits.hpp
 *
 * Purpose:     integral_format_width_limits traits class template.
 *
 * Created:     10th July 2012
 * Updated:     26th December 2020
 *
 * Thanks:      To Jonathan Wakely for help with Solaris compatibility.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2012-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/limits/integral_format_width_limits.hpp
 *
 * \brief [C++] stlsoft::integral_format_width_limits traits class
 *   template
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS
#define STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS_MAJOR      1
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS_MINOR      0
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS_REVISION   7
# define STLSOFT_VER_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS_EDIT       12
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
 * classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/// Limits-traits class template that specifies the maximum length of
/// integer-to-string conversion strings, for octal, decimal, and
/// hexadecimal conversion of integral types.
///
/// \note The lengths given do <strong>not</strong> assume any kind of
///   integral promotion, such as occurs, for example, with variadic
///   functions such as <code>printf()</code>.
///
/// \note The lengths given do <strong>not</strong> count the
///  nul-terminator character.
///
/// \param I The integral type for which the
template <ss_typename_param_k I>
struct integral_format_width_limits
{
    enum
    {
            /// The maximum width of octal representation of any value in
            /// the range of the type
            maxOctalWidth
            /// The maximum width of octal representation of any value in
            /// the range of the type, excluding the sign (for negative
            /// values; signed types only)
        ,   maxOctalWidthWithoutSign
            /// The maximum width of decimal representation of any value in
            /// the range of the type
        ,   maxDecimalWidth
            /// The maximum width of decimal representation of any value in
            /// the range of the type, excluding the sign (for negative
            /// values; signed types only)
        ,   maxDecimalWidthWithoutSign
            /// The maximum width of hexadecimal representation of any
            /// value in the range of the type
        ,   maxHexadecimalWidth
            /// The maximum width of hexadecimal representation of any
            /// value in the range of the type, excluding the sign (for
            /// negative values; signed types only)
        ,   maxHexadecimalWidthWithoutSign
    };
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k>
struct integral_format_width_limits;

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_sint8_t>
{
    enum
    {
            maxOctalWidth                   =   4
        ,   maxOctalWidthWithoutSign        =   3
        ,   maxDecimalWidth                 =   4
        ,   maxDecimalWidthWithoutSign      =   3
        ,   maxHexadecimalWidth             =   3
        ,   maxHexadecimalWidthWithoutSign  =   2
    };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_uint8_t>
{
    enum
    {
            maxOctalWidth                   =   3
        ,   maxOctalWidthWithoutSign        =   3
        ,   maxDecimalWidth                 =   3
        ,   maxDecimalWidthWithoutSign      =   3
        ,   maxHexadecimalWidth             =   2
        ,   maxHexadecimalWidthWithoutSign  =   2
    };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_sint16_t>
{
    enum
    {
            maxOctalWidth                   =   7
        ,   maxOctalWidthWithoutSign        =   6
        ,   maxDecimalWidth                 =   6
        ,   maxDecimalWidthWithoutSign      =   5
        ,   maxHexadecimalWidth             =   5
        ,   maxHexadecimalWidthWithoutSign  =   4
    };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_uint16_t>
{
    enum
    {
            maxOctalWidth                   =   5
        ,   maxOctalWidthWithoutSign        =   5
        ,   maxDecimalWidth                 =   5
        ,   maxDecimalWidthWithoutSign      =   5
        ,   maxHexadecimalWidth             =   4
        ,   maxHexadecimalWidthWithoutSign  =   4
    };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_sint32_t>
{
    enum
    {
            maxOctalWidth                   =   12
        ,   maxOctalWidthWithoutSign        =   11
        ,   maxDecimalWidth                 =   11
        ,   maxDecimalWidthWithoutSign      =   10
        ,   maxHexadecimalWidth             =   9
        ,   maxHexadecimalWidthWithoutSign  =   8
    };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_uint32_t>
{
    enum
    {
            maxOctalWidth                   =   11
        ,   maxOctalWidthWithoutSign        =   11
        ,   maxDecimalWidth                 =   10
        ,   maxDecimalWidthWithoutSign      =   10
        ,   maxHexadecimalWidth             =   8
        ,   maxHexadecimalWidthWithoutSign  =   8
    };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_sint64_t>
{
    enum
    {
            maxOctalWidth                   =   23
        ,   maxOctalWidthWithoutSign        =   22
        ,   maxDecimalWidth                 =   20
        ,   maxDecimalWidthWithoutSign      =   19
        ,   maxHexadecimalWidth             =   17
        ,   maxHexadecimalWidthWithoutSign  =   16
    };
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<ss_uint64_t>
{
    enum
    {
            maxOctalWidth                   =   21
        ,   maxOctalWidthWithoutSign        =   21
        ,   maxDecimalWidth                 =   20
        ,   maxDecimalWidthWithoutSign      =   20
        ,   maxHexadecimalWidth             =   16
        ,   maxHexadecimalWidthWithoutSign  =   16
    };
};

STLSOFT_OPEN_WORKER_NS_(ximpl_stlsoft_integral_format_width_limits)

template<
    ss_size_t   TypeSizeInBytes
,   ss_bool_t   TypeIsSigned
>
struct integral_format_width_limits_selector;

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<1, true>
{
    typedef integral_format_width_limits<ss_sint8_t>    type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<1, false>
{
    typedef integral_format_width_limits<ss_uint8_t>    type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<2, true>
{
    typedef integral_format_width_limits<ss_sint16_t>   type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<2, false>
{
    typedef integral_format_width_limits<ss_uint16_t>   type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<4, true>
{
    typedef integral_format_width_limits<ss_sint32_t>   type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<4, false>
{
    typedef integral_format_width_limits<ss_uint32_t>   type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<8, true>
{
    typedef integral_format_width_limits<ss_sint64_t>   type;
};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits_selector<8, false>
{
    typedef integral_format_width_limits<ss_uint64_t>   type;
};



STLSOFT_CLOSE_WORKER_NS_(ximpl_stlsoft_integral_format_width_limits)


/* char */

STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<char>
#ifdef STLSOFT_CF_char_IS_UNSIGNED
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(char), false>::type
#else /* ? STLSOFT_CF_char_IS_UNSIGNED */
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(char), true>::type
#endif /* STLSOFT_CF_char_IS_UNSIGNED */
{};
#ifdef STLSOFT_CF_CHAR_DISTINCT_INT_TYPE
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<signed char>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(signed char), true>::type
{};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<unsigned char>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(unsigned char), false>::type
{};
#endif /* STLSOFT_CF_CHAR_DISTINCT_INT_TYPE */


/* short */

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<signed short>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(signed short), true>::type
{};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<unsigned short>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(unsigned short), false>::type
{};
#endif /* !STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */


/* int */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<signed int>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(signed int), true>::type
{};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<unsigned int>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(unsigned int), false>::type
{};
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */


/* long */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<signed long>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(signed long), true>::type
{};
STLSOFT_TEMPLATE_SPECIALISATION
struct integral_format_width_limits<unsigned long>
    : public STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_integral_format_width_limits, integral_format_width_limits_selector)<sizeof(unsigned long), false>::type
{};
#endif /* !STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

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

#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS */

/* ///////////////////////////// end of file //////////////////////////// */

