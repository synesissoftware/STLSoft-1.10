/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/number/grouping_functions.hpp
 *
 * Purpose:     Number formatting functions.
 *
 * Created:     28th August 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/conversion/number/grouping_functions.hpp
 *
 * \brief [C++] Definition of the stlsoft::format_thousands() formatting
 *   function
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_MAJOR     1
# define STLSOFT_VER_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_MINOR     0
# define STLSOFT_VER_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_REVISION  12
# define STLSOFT_VER_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_EDIT      29
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

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */

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

/**
 *
 * \ingroup group__library__Conversion
 *
 * \param dest Pointer to buffer to receive translation. If NULL, function returns required size.
 * \param cchDest Size of available buffer. Ignored if dest is NULL.
 * \param picture Grouping picture. May not be NULL. Behaviour is undefined if empty, or contains any characters other than <code>fmtSep</code> and non-0 digits.
 * \param rawNumber The raw number form. May not be NULL. Behaviour is undefined contains any characters other than digits.
 * \param fmtSep The separator in the format.
 * \param outputSep The separator in the output.
 */
template <ss_typename_param_k C>
inline
ss_size_t
translate_thousands(
    C*          dest
,   ss_size_t   cchDest
,   C const*    picture
,   C const*    rawNumber
,   ss_size_t   cchRawNumber
,   C           fmtSep
,   C           outputSep
)
{
    typedef char_traits<C>  traits_t;

    auto_buffer<C>  res(1 + 2 * cchRawNumber);
    C const*        pic_next;

    for (pic_next = picture; fmtSep == *pic_next; ++pic_next)
    {}
    STLSOFT_ASSERT('0' != *pic_next);
    STLSOFT_ASSERT('0' < *pic_next);

    C const*        raw_end     =   rawNumber + cchRawNumber;
    C const* const  raw_begin   =   rawNumber;
    C*              res_end     =   &*(res.end() - 1);
    ss_size_t       num         =   static_cast<ss_size_t>(*pic_next - '0');    // Derive the first
    ss_size_t       n           =   num;

    *res_end = '\0';
    for (--raw_end, --res_end; raw_end != raw_begin; --raw_end, --res_end)
    {
        *res_end = *raw_end;
        if (0 != n &&
            0 == --n)
        {
            if ('\0' == *pic_next)
            {
            }
            else if ('0' == *pic_next)
            {
                n = num;
            }
            else
            {
                C const* pic_end_next = ++pic_next;

                for (; *pic_end_next == fmtSep; ++pic_end_next)
                {}

                pic_next = pic_end_next;

                if ('\0' == *pic_next)
                {
                    *--res_end = outputSep;
                }
                else if ('0' == *pic_next)
                {
                    n = num;
                }
                else
                {
                    num =   static_cast<ss_size_t>(*pic_next - '0');
                    n   =   num;
                }
            }

            if (0 != n)
            {
                *--res_end = outputSep;
            }
        }
    }
    *res_end = *raw_end;

    ss_size_t cch = static_cast<ss_size_t>(res.end() - res_end);

    if (NULL != dest)
    {
        if (cch > cchDest)
        {
            cch = cchDest;
        }

        traits_t::copy(dest, res_end, cch);
    }

    return cch;
}

template <ss_typename_param_k C>
inline
ss_size_t
translate_thousands(
    C*          dest
,   ss_size_t   cchDest
,   C const*    picture
,   C const*    rawNumber
,   C           fmtSep
,   C           outputSep
)
{
    typedef char_traits<C>  traits_t;

    ss_size_t const cchRawNumber = traits_t::length(rawNumber);

    return translate_thousands(dest, cchDest, picture, rawNumber, cchRawNumber, fmtSep, outputSep);
}

/**
 *
 * \ingroup group__library__Conversion
 *
 * \param dest Pointer to buffer to receive translation. If NULL, function returns required size.
 * \param cchDest Size of available buffer. Ignored if dest is NULL.
 * \param picture Grouping picture. May not be NULL. Behaviour is undefined if empty, or contains any characters other than <code>fmtSep</code> and non-0 digits.
 * \param number The raw number form. May not be NULL. Behaviour is undefined contains any characters other than digits.
 * \param fmtSep The separator in the format.
 * \param outputSep The separator in the output.
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k I
        >
inline
ss_size_t
format_thousands(
    C*          dest
,   ss_size_t   cchDest
,   C const*    picture
,   I const&    number
,   C           fmtSep
,   C           outputSep
)
{
    C           szRawNumber[21];    // 21 is large enough for any 64-bit number (signed or unsigned)
    ss_size_t   cchRawNumber;
    C const*    rawNumber = integer_to_decimal_string(szRawNumber, STLSOFT_NUM_ELEMENTS(szRawNumber), static_cast<unsigned int>(number), &cchRawNumber);

    STLSOFT_STATIC_ASSERT(sizeof(C) <= 8);

    return translate_thousands(dest, cchDest, picture, rawNumber, cchRawNumber, fmtSep, outputSep);
}

/**
 *
 * \ingroup group__library__Conversion
 *
 * \param dest Pointer to buffer to receive translation. If NULL, function returns required size.
 * \param cchDest Size of available buffer. Ignored if dest is NULL.
 * \param picture Grouping picture. May not be NULL. Behaviour is undefined if empty, or contains any characters other than <code>;</code> and non-0 digits.
 * \param number The raw number form. May not be NULL. Behaviour is undefined contains any characters other than digits.
 *
 * \return The number of characters written, including that of the nul-terminator
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k I
        >
inline
ss_size_t
format_thousands(
    C*          dest
,   ss_size_t   cchDest
,   C const*    picture
,   I const&    number
)
{
    return format_thousands<C, I>(dest, cchDest, picture, number, ';', ',');
}

/* /////////////////////////////////////////////////////////////////////////
 * unittest
 */

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

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

