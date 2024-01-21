/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/bits/test_functions.h
 *
 * Purpose:     Bit test functions
 *
 * Created:     2nd June 2010
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/bits/test_functions.h
 *
 * \brief [C++] Functions to test bits
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS_MAJOR       1
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS_MINOR       0
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS_REVISION    3
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS_EDIT        11
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
 * functions
 */

/** Find the 1-based index of the highest non-zero bit in a 8-bit unsigned
 * integer
 *
 * \retval 0 no bits are found
 */
STLSOFT_INLINE
unsigned
stlsoft_C_find_highest_bit_in_8bit_unsigned_integer(
    ss_uint8_t v
) STLSOFT_NOEXCEPT
{
    unsigned c;

    for (c = 0; 0 != v; ++c, v >>= 1)
    {}

    return c;
}

/** Find the 1-based index of the highest non-zero bit in a 16-bit unsigned
 * integer
 *
 * \retval 0 no bits are found
 */
STLSOFT_INLINE
unsigned
stlsoft_C_find_highest_bit_in_16bit_unsigned_integer(
    ss_uint16_t v
) STLSOFT_NOEXCEPT
{
    unsigned const r_high = stlsoft_C_find_highest_bit_in_8bit_unsigned_integer(STLSOFT_STATIC_CAST(ss_uint8_t, v >> 8));

    if (0 != r_high)
    {
        return r_high + 8u;
    }

    return stlsoft_C_find_highest_bit_in_8bit_unsigned_integer(STLSOFT_STATIC_CAST(ss_uint8_t, v));
}

/** Find the 1-based index of the highest non-zero bit in a 32-bit unsigned
 * integer
 *
 * \retval 0 no bits are found
 */
STLSOFT_INLINE
unsigned
stlsoft_C_find_highest_bit_in_32bit_unsigned_integer(
    ss_uint32_t v
) STLSOFT_NOEXCEPT
{
    unsigned const r_high = stlsoft_C_find_highest_bit_in_16bit_unsigned_integer(STLSOFT_STATIC_CAST(ss_uint16_t, v >> 16));

    if (0 != r_high)
    {
        return r_high + 16u;
    }

    return stlsoft_C_find_highest_bit_in_16bit_unsigned_integer(STLSOFT_STATIC_CAST(ss_uint16_t, v));
}

/** Find the 1-based index of the highest non-zero bit in a 64-bit unsigned
 * integer
 *
 * \retval 0 no bits are found
 */
STLSOFT_INLINE
unsigned
stlsoft_C_find_highest_bit_in_64bit_unsigned_integer(
    ss_uint64_t v
) STLSOFT_NOEXCEPT
{
    unsigned const r_high = stlsoft_C_find_highest_bit_in_32bit_unsigned_integer(STLSOFT_STATIC_CAST(ss_uint32_t, v >> 32));

    if (0 != r_high)
    {
        return r_high + 32u;
    }

    return stlsoft_C_find_highest_bit_in_32bit_unsigned_integer(STLSOFT_STATIC_CAST(ss_uint32_t, v));
}

/* /////////////////////////////////////////////////////////////////////////
 * C++
 */

#ifdef __cplusplus

/**
 *
 * \see stlsoft_C_find_highest_bit_in_64bit_unsigned_integer
 */
inline
unsigned
find_highest_bit(
    ss_uint64_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_find_highest_bit_in_64bit_unsigned_integer(v);
}

/**
 *
 * \see stlsoft_C_find_highest_bit_in_32bit_unsigned_integer
 */
inline
unsigned
find_highest_bit(
    ss_uint32_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_find_highest_bit_in_32bit_unsigned_integer(v);
}

/**
 *
 * \see stlsoft_C_find_highest_bit_in_16bit_unsigned_integer
 */
inline
unsigned
find_highest_bit(
    ss_uint16_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_find_highest_bit_in_16bit_unsigned_integer(v);
}

/**
 *
 * \see stlsoft_C_find_highest_bit_in_8bit_unsigned_integer
 */
inline
unsigned
find_highest_bit(
    ss_uint8_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_find_highest_bit_in_8bit_unsigned_integer(v);
}


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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

