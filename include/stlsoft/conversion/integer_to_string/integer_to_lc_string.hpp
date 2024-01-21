/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/integer_to_string/integer_to_lc_string.hpp
 *
 * Purpose:     Efficient integer to locale-specific string conversion
 *              functions for decimal representation.
 *
 * Created:     1st November 2011
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/integer_to_string/integer_to_lc_string.hpp
 *
 * \brief [C++] Efficient integer to locale-specific string conversion
 *   functions for decimal representation
 *  (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_LC_STRING
#define STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_LC_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_LC_STRING_MAJOR    1
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_LC_STRING_MINOR    0
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_LC_STRING_REVISION 13
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_LC_STRING_EDIT     19
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

#ifndef STLSOFT_INCL_H_LIMITS
# define STLSOFT_INCL_H_LIMITS
# include <limits.h>
#endif /* !STLSOFT_INCL_H_LIMITS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

template<
    ss_typename_param_k C1
,   ss_typename_param_k C2
,   ss_typename_param_k I
>
C1 const*
integer_to_lc_string(
    C2 const*   grouping
,   C1 const    thousands_sep
,   C1*         dest
,   ss_size_t   cchDest
,   I const&    value
,   ss_size_t*  numWritten = NULL
)
{
    STLSOFT_ASSERT(NULL != grouping);
    STLSOFT_ASSERT('\0' == grouping[0] || 0 != thousands_sep);
    STLSOFT_ASSERT(NULL != dest);

    ss_size_t dummy;

    if (NULL == numWritten)
    {
        numWritten = &dummy;
    }

    if ('\0' == grouping[0])
    {
        return stlsoft::integer_to_decimal_string(dest, cchDest, value, numWritten);
    }
    else
    {
        C1              raw[21];
        ss_size_t       nRaw;
        C1* const       eRaw    =   raw + STLSOFT_NUM_ELEMENTS(raw);
        C1 const* const sRaw    =   stlsoft::integer_to_decimal_string(raw, STLSOFT_NUM_ELEMENTS(raw), value, &nRaw);
        C1* const       eDst    =   dest + (cchDest - 1);
        C1*             d       =   eDst;
        ss_size_t       index   =   0;
        int             width   =   grouping[index];
        int             n       =   0;

        STLSOFT_SUPPRESS_UNUSED(sRaw);

        *d = '\0';

        for (ss_size_t i = 0; i != nRaw; ++i)
        {
            if (0 < width &&
                n == width)
            {
                *--d = thousands_sep;

                int const nextWidth = grouping[1 + index];
                if (nextWidth < 0 ||
                    CHAR_MAX == nextWidth)
                {
                    width = -1;
                }
                else if ('\0' == nextWidth)
                {
                    ; // Do nothing, and therefore reuse previous width
                }
                else
                {
                    // Change to next width
                    width = nextWidth;
                    ++index;
                }
                n = 0;
            }
            *--d = *(eRaw - (2 + i));
            ++n;
        }

        STLSOFT_MESSAGE_ASSERT("insufficient buffer", !(d < dest));

        *numWritten = eDst - d;

        return d;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_LC_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

