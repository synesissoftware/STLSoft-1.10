/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/count_digits.hpp
 *
 * Purpose:     Overloads of count_digits(), a function for counting the
 *              number of (decimal) digits in an integer number.
 *
 * Created:     7th June 2011
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


/** \file stlsoft/util/count_digits.hpp
 *
 * \brief [C++] Definition of the function suite count_digits()
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_INCL_H_COUNT_DIGITS
#define STLSOFT_INCL_STLSOFT_UTIL_INCL_H_COUNT_DIGITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_COUNT_DIGITS_MAJOR     2
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_COUNT_DIGITS_MINOR     0
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_COUNT_DIGITS_REVISION  1
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_COUNT_DIGITS_EDIT      13
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
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_count_digits_
{

    template <ss_typename_param_k I>
    inline
    size_t count_digits_unsigned_(
        I i
    )
    {
#if 0
        static size_t const width = sizeof(i);
#endif /* 0 */

        if (I(0) == i)
        {
            return 1u;
        }
        else
        {
            size_t n = 0u;

            for (; 0 != i; i /= 10, ++n)
            {}

            return n;
        }
    }


    inline
    size_t count_digits_u8_(
        ss_uint8_t const& i
    )
    {
        return ximpl_count_digits_::count_digits_unsigned_(i);
    }

    inline
    size_t count_digits_u16_(
        ss_uint16_t const& i
    )
    {
#if 0
        if (0 == (0xff00 & i))
        {
            return count_digits_u8_(static_cast<uint8_t>(i));
        }
        else
#endif /* 0 */
        {
            return ximpl_count_digits_::count_digits_unsigned_(i);
        }
    }

    inline
    size_t count_digits_u32_(
        ss_uint32_t const& i
    )
    {
#if 0
        if (0 == (0xffff0000 & i))
        {
            return count_digits_u16_(static_cast<uint16_t>(i));
        }
        else
#endif /* 0 */
        {
            return ximpl_count_digits_::count_digits_unsigned_(i);
        }
    }

    inline
    size_t count_digits_u64_(
        ss_uint64_t const& i
    )
    {
#if 1
        if (0 == (0xffffffff00000000 & i))
        {
            return count_digits_u32_(static_cast<uint32_t>(i));
        }
        else
#endif /* 0 */
        {
            return ximpl_count_digits_::count_digits_unsigned_(i);
        }
    }

} /* namespace ximpl_count_digits_ */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint8_t i
)
{
    return ximpl_count_digits_::count_digits_u8_(i);
}

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint16_t i
)
{
    return ximpl_count_digits_::count_digits_u16_(i);
}

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint32_t i
)
{
    return ximpl_count_digits_::count_digits_u32_(i);
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    unsigned int i
)
{
    return ximpl_count_digits_::count_digits_u32_(i);
}

#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

/** Counts the number of decimal digits in \c i
 */
inline
size_t
count_digits(
    ss_uint64_t const& i
)
{
    return ximpl_count_digits_::count_digits_u64_(i);
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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_INCL_H_COUNT_DIGITS */

/* ///////////////////////////// end of file //////////////////////////// */

