/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/bits/count_functions.h
 *
 * Purpose:     Bit count functions.
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


/** \file stlsoft/util/bits/count_functions.h
 *
 * \brief [C++] Functions to count bits
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS_MINOR    3
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS_REVISION 1
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS_EDIT     18
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
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef __cplusplus
namespace ximpl_bit_functions
{
# endif /* __cplusplus */
    typedef ss_uint8_t const(*stlsoft_C_count_functions_table_ptr_type)[256];

    static
    stlsoft_C_count_functions_table_ptr_type
    stlsoft_C_count_functions_get_8bit_table()
    {
        static const ss_uint8_t s_table[256] =
        {
            /*    0 0x00 */ 0,
            /*    1 0x01 */ 1,
            /*    2 0x02 */ 1,
            /*    3 0x03 */ 2,
            /*    4 0x04 */ 1,
            /*    5 0x05 */ 2,
            /*    6 0x06 */ 2,
            /*    7 0x07 */ 3,
            /*    8 0x08 */ 1,
            /*    9 0x09 */ 2,
            /*   10 0x0a */ 2,
            /*   11 0x0b */ 3,
            /*   12 0x0c */ 2,
            /*   13 0x0d */ 3,
            /*   14 0x0e */ 3,
            /*   15 0x0f */ 4,
            /*   16 0x10 */ 1,
            /*   17 0x11 */ 2,
            /*   18 0x12 */ 2,
            /*   19 0x13 */ 3,
            /*   20 0x14 */ 2,
            /*   21 0x15 */ 3,
            /*   22 0x16 */ 3,
            /*   23 0x17 */ 4,
            /*   24 0x18 */ 2,
            /*   25 0x19 */ 3,
            /*   26 0x1a */ 3,
            /*   27 0x1b */ 4,
            /*   28 0x1c */ 3,
            /*   29 0x1d */ 4,
            /*   30 0x1e */ 4,
            /*   31 0x1f */ 5,
            /*   32 0x20 */ 1,
            /*   33 0x21 */ 2,
            /*   34 0x22 */ 2,
            /*   35 0x23 */ 3,
            /*   36 0x24 */ 2,
            /*   37 0x25 */ 3,
            /*   38 0x26 */ 3,
            /*   39 0x27 */ 4,
            /*   40 0x28 */ 2,
            /*   41 0x29 */ 3,
            /*   42 0x2a */ 3,
            /*   43 0x2b */ 4,
            /*   44 0x2c */ 3,
            /*   45 0x2d */ 4,
            /*   46 0x2e */ 4,
            /*   47 0x2f */ 5,
            /*   48 0x30 */ 2,
            /*   49 0x31 */ 3,
            /*   50 0x32 */ 3,
            /*   51 0x33 */ 4,
            /*   52 0x34 */ 3,
            /*   53 0x35 */ 4,
            /*   54 0x36 */ 4,
            /*   55 0x37 */ 5,
            /*   56 0x38 */ 3,
            /*   57 0x39 */ 4,
            /*   58 0x3a */ 4,
            /*   59 0x3b */ 5,
            /*   60 0x3c */ 4,
            /*   61 0x3d */ 5,
            /*   62 0x3e */ 5,
            /*   63 0x3f */ 6,
            /*   64 0x40 */ 1,
            /*   65 0x41 */ 2,
            /*   66 0x42 */ 2,
            /*   67 0x43 */ 3,
            /*   68 0x44 */ 2,
            /*   69 0x45 */ 3,
            /*   70 0x46 */ 3,
            /*   71 0x47 */ 4,
            /*   72 0x48 */ 2,
            /*   73 0x49 */ 3,
            /*   74 0x4a */ 3,
            /*   75 0x4b */ 4,
            /*   76 0x4c */ 3,
            /*   77 0x4d */ 4,
            /*   78 0x4e */ 4,
            /*   79 0x4f */ 5,
            /*   80 0x50 */ 2,
            /*   81 0x51 */ 3,
            /*   82 0x52 */ 3,
            /*   83 0x53 */ 4,
            /*   84 0x54 */ 3,
            /*   85 0x55 */ 4,
            /*   86 0x56 */ 4,
            /*   87 0x57 */ 5,
            /*   88 0x58 */ 3,
            /*   89 0x59 */ 4,
            /*   90 0x5a */ 4,
            /*   91 0x5b */ 5,
            /*   92 0x5c */ 4,
            /*   93 0x5d */ 5,
            /*   94 0x5e */ 5,
            /*   95 0x5f */ 6,
            /*   96 0x60 */ 2,
            /*   97 0x61 */ 3,
            /*   98 0x62 */ 3,
            /*   99 0x63 */ 4,
            /*  100 0x64 */ 3,
            /*  101 0x65 */ 4,
            /*  102 0x66 */ 4,
            /*  103 0x67 */ 5,
            /*  104 0x68 */ 3,
            /*  105 0x69 */ 4,
            /*  106 0x6a */ 4,
            /*  107 0x6b */ 5,
            /*  108 0x6c */ 4,
            /*  109 0x6d */ 5,
            /*  110 0x6e */ 5,
            /*  111 0x6f */ 6,
            /*  112 0x70 */ 3,
            /*  113 0x71 */ 4,
            /*  114 0x72 */ 4,
            /*  115 0x73 */ 5,
            /*  116 0x74 */ 4,
            /*  117 0x75 */ 5,
            /*  118 0x76 */ 5,
            /*  119 0x77 */ 6,
            /*  120 0x78 */ 4,
            /*  121 0x79 */ 5,
            /*  122 0x7a */ 5,
            /*  123 0x7b */ 6,
            /*  124 0x7c */ 5,
            /*  125 0x7d */ 6,
            /*  126 0x7e */ 6,
            /*  127 0x7f */ 7,
            /*  128 0x80 */ 1,
            /*  129 0x81 */ 2,
            /*  130 0x82 */ 2,
            /*  131 0x83 */ 3,
            /*  132 0x84 */ 2,
            /*  133 0x85 */ 3,
            /*  134 0x86 */ 3,
            /*  135 0x87 */ 4,
            /*  136 0x88 */ 2,
            /*  137 0x89 */ 3,
            /*  138 0x8a */ 3,
            /*  139 0x8b */ 4,
            /*  140 0x8c */ 3,
            /*  141 0x8d */ 4,
            /*  142 0x8e */ 4,
            /*  143 0x8f */ 5,
            /*  144 0x90 */ 2,
            /*  145 0x91 */ 3,
            /*  146 0x92 */ 3,
            /*  147 0x93 */ 4,
            /*  148 0x94 */ 3,
            /*  149 0x95 */ 4,
            /*  150 0x96 */ 4,
            /*  151 0x97 */ 5,
            /*  152 0x98 */ 3,
            /*  153 0x99 */ 4,
            /*  154 0x9a */ 4,
            /*  155 0x9b */ 5,
            /*  156 0x9c */ 4,
            /*  157 0x9d */ 5,
            /*  158 0x9e */ 5,
            /*  159 0x9f */ 6,
            /*  160 0xa0 */ 2,
            /*  161 0xa1 */ 3,
            /*  162 0xa2 */ 3,
            /*  163 0xa3 */ 4,
            /*  164 0xa4 */ 3,
            /*  165 0xa5 */ 4,
            /*  166 0xa6 */ 4,
            /*  167 0xa7 */ 5,
            /*  168 0xa8 */ 3,
            /*  169 0xa9 */ 4,
            /*  170 0xaa */ 4,
            /*  171 0xab */ 5,
            /*  172 0xac */ 4,
            /*  173 0xad */ 5,
            /*  174 0xae */ 5,
            /*  175 0xaf */ 6,
            /*  176 0xb0 */ 3,
            /*  177 0xb1 */ 4,
            /*  178 0xb2 */ 4,
            /*  179 0xb3 */ 5,
            /*  180 0xb4 */ 4,
            /*  181 0xb5 */ 5,
            /*  182 0xb6 */ 5,
            /*  183 0xb7 */ 6,
            /*  184 0xb8 */ 4,
            /*  185 0xb9 */ 5,
            /*  186 0xba */ 5,
            /*  187 0xbb */ 6,
            /*  188 0xbc */ 5,
            /*  189 0xbd */ 6,
            /*  190 0xbe */ 6,
            /*  191 0xbf */ 7,
            /*  192 0xc0 */ 2,
            /*  193 0xc1 */ 3,
            /*  194 0xc2 */ 3,
            /*  195 0xc3 */ 4,
            /*  196 0xc4 */ 3,
            /*  197 0xc5 */ 4,
            /*  198 0xc6 */ 4,
            /*  199 0xc7 */ 5,
            /*  200 0xc8 */ 3,
            /*  201 0xc9 */ 4,
            /*  202 0xca */ 4,
            /*  203 0xcb */ 5,
            /*  204 0xcc */ 4,
            /*  205 0xcd */ 5,
            /*  206 0xce */ 5,
            /*  207 0xcf */ 6,
            /*  208 0xd0 */ 3,
            /*  209 0xd1 */ 4,
            /*  210 0xd2 */ 4,
            /*  211 0xd3 */ 5,
            /*  212 0xd4 */ 4,
            /*  213 0xd5 */ 5,
            /*  214 0xd6 */ 5,
            /*  215 0xd7 */ 6,
            /*  216 0xd8 */ 4,
            /*  217 0xd9 */ 5,
            /*  218 0xda */ 5,
            /*  219 0xdb */ 6,
            /*  220 0xdc */ 5,
            /*  221 0xdd */ 6,
            /*  222 0xde */ 6,
            /*  223 0xdf */ 7,
            /*  224 0xe0 */ 3,
            /*  225 0xe1 */ 4,
            /*  226 0xe2 */ 4,
            /*  227 0xe3 */ 5,
            /*  228 0xe4 */ 4,
            /*  229 0xe5 */ 5,
            /*  230 0xe6 */ 5,
            /*  231 0xe7 */ 6,
            /*  232 0xe8 */ 4,
            /*  233 0xe9 */ 5,
            /*  234 0xea */ 5,
            /*  235 0xeb */ 6,
            /*  236 0xec */ 5,
            /*  237 0xed */ 6,
            /*  238 0xee */ 6,
            /*  239 0xef */ 7,
            /*  240 0xf0 */ 4,
            /*  241 0xf1 */ 5,
            /*  242 0xf2 */ 5,
            /*  243 0xf3 */ 6,
            /*  244 0xf4 */ 5,
            /*  245 0xf5 */ 6,
            /*  246 0xf6 */ 6,
            /*  247 0xf7 */ 7,
            /*  248 0xf8 */ 5,
            /*  249 0xf9 */ 6,
            /*  250 0xfa */ 6,
            /*  251 0xfb */ 7,
            /*  252 0xfc */ 6,
            /*  253 0xfd */ 7,
            /*  254 0xfe */ 7,
            /*  255 0xff */ 8,
        };

        return &s_table;
    }

# ifdef __cplusplus
} /* namespace ximpl_bit_functions */
# endif /* __cplusplus */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Counts the number of bits in a 32-bit unsigned integer, using Brian
 * Kernighan's method (see TCPL).
 *
 * \param v The number whose bits are to be counted
 *
 * \return The number of bits in \c v
 */
STLSOFT_INLINE
unsigned
stlsoft_C_count_bits_in_32bit_unsigned_integer_by_Kernighan_method(
    ss_uint32_t v
) STLSOFT_NOEXCEPT
{
    unsigned n = 0;

    STLSOFT_COVER_MARK_LINE();

    for (; 0 != v; ++n)
    {
        STLSOFT_COVER_MARK_LINE();

        v &= v - 1;
    }

    STLSOFT_COVER_MARK_LINE();

    return n;
}

/** Counts the number of bits in a 64-bit unsigned integer, using Brian
 * Kernighan's method (see TCPL).
 *
 * \param v The number whose bits are to be counted
 *
 * \return The number of bits in \c v
 */
STLSOFT_INLINE
unsigned
stlsoft_C_count_bits_in_64bit_unsigned_integer_by_Kernighan_method(
    ss_uint64_t v
) STLSOFT_NOEXCEPT
{
    unsigned    n_high  =   stlsoft_C_count_bits_in_32bit_unsigned_integer_by_Kernighan_method(STLSOFT_STATIC_CAST(ss_uint32_t, v >> 32));
    unsigned    n_low   =   stlsoft_C_count_bits_in_32bit_unsigned_integer_by_Kernighan_method(STLSOFT_STATIC_CAST(ss_uint32_t, v >>  0));

    return n_high + n_low;
}

/** Counts the number of bits in a 32-bit unsigned integer, using an 8-bit.
 * lookup table.
 *
 * \param v The number whose bits are to be counted
 *
 * \return The number of bits in \c v
 */
STLSOFT_INLINE
unsigned
stlsoft_C_count_bits_in_32bit_unsigned_integer_by_8bit_table(
    ss_uint32_t v
) STLSOFT_NOEXCEPT
{
    ss_uint8_t const* const py = STLSOFT_STATIC_CAST(ss_uint8_t const*, STLSOFT_STATIC_CAST(void*, &v));

#ifdef __cplusplus
    using namespace ximpl_bit_functions;
#endif /* __cplusplus */

    stlsoft_C_count_functions_table_ptr_type ptr = stlsoft_C_count_functions_get_8bit_table();

    STLSOFT_COVER_MARK_LINE();

    return (*ptr)[0[py]] + (*ptr)[1[py]] + (*ptr)[2[py]] + (*ptr)[3[py]];
}

/** Counts the number of bits in a 64-bit unsigned integer, using an 8-bit.
 * lookup table.
 *
 * \param v The number whose bits are to be counted
 *
 * \return The number of bits in \c v
 */
STLSOFT_INLINE
unsigned
stlsoft_C_count_bits_in_64bit_unsigned_integer_by_8bit_table(
    ss_uint64_t v
) STLSOFT_NOEXCEPT
{
    unsigned    n_high  =   stlsoft_C_count_bits_in_32bit_unsigned_integer_by_8bit_table(STLSOFT_STATIC_CAST(ss_uint32_t, v >> 32));
    unsigned    n_low   =   stlsoft_C_count_bits_in_32bit_unsigned_integer_by_8bit_table(STLSOFT_STATIC_CAST(ss_uint32_t, v >>  0));

    return n_high + n_low;
}

/* /////////////////////////////////////////////////////////////////////////
 * C++
 */

#ifdef __cplusplus

/**
 *
 * \see stlsoft_C_count_bits_in_32bit_unsigned_integer_by_Kernighan_method
 */
inline
unsigned
count_bits_by_Kernighan_method(
    ss_uint32_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_count_bits_in_32bit_unsigned_integer_by_Kernighan_method(v);
}

/**
 *
 * \see stlsoft_C_count_bits_in_64bit_unsigned_integer_by_Kernighan_method
 */
inline
unsigned
count_bits_by_Kernighan_method(
    ss_uint64_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_count_bits_in_64bit_unsigned_integer_by_Kernighan_method(v);
}

/**
 *
 * \see stlsoft_C_count_bits_in_32bit_unsigned_integer_by_8bit_table
 */
inline
unsigned
count_bits_by_8bit_table(
    ss_uint32_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_count_bits_in_32bit_unsigned_integer_by_8bit_table(v);
}

/**
 *
 * \see stlsoft_C_count_bits_in_64bit_unsigned_integer_by_8bit_table
 */
inline
unsigned
count_bits_by_8bit_table(
    ss_uint64_t v
) STLSOFT_NOEXCEPT
{
    return stlsoft_C_count_bits_in_64bit_unsigned_integer_by_8bit_table(v);
}


/** Counts the number of bits in a 32-bit unsigned integer
 *
 * \param v The number whose bits are to be counted
 *
 * \return The number of bits in \c v
 */
inline
unsigned
count_bits(
    ss_uint32_t v
) STLSOFT_NOEXCEPT
{
# if defined(STLSOFT_BIT_COUNT_BY_Kernighan)
    return count_bits_by_Kernighan(v);
# else
    return count_bits_by_8bit_table(v);
# endif
}

/** Counts the number of bits in a 64-bit unsigned integer
 *
 * \param v The number whose bits are to be counted
 *
 * \return The number of bits in \c v
 */
inline
unsigned
count_bits(
    ss_uint64_t v
) STLSOFT_NOEXCEPT
{
# if defined(STLSOFT_BIT_COUNT_BY_Kernighan)
    return count_bits_by_Kernighan(v);
# else
    return count_bits_by_8bit_table(v);
# endif
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <size_t N_bytes>
unsigned
count_bits_int_(
    int v
);

STLSOFT_TEMPLATE_SPECIALISATION
inline
unsigned
count_bits_int_<4>(
    int v
)
{
    return count_bits(static_cast<ss_uint32_t>(v));
}

STLSOFT_TEMPLATE_SPECIALISATION
inline
unsigned
count_bits_int_<8>(
    int v
)
{
    return count_bits(static_cast<ss_uint64_t>(v));
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Counts the number of bits in an integer
 *
 * \param v The number whose bits are to be counted
 *
 * \return The number of bits in \c v
 */
inline
unsigned
count_bits(
    int v
)
{
    return count_bits_int_<sizeof(int)>(v);
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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

