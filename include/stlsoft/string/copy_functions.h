/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/copy_functions.h
 *
 * Purpose:     String copy functions.
 *
 * Created:     29th September 2016
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2016-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/copy_functions.h
 *
 * \brief [C++] Definition of the stlsoft::string_copy*() suite of functions
 *
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_H_COPY_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_H_COPY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_H_COPY_FUNCTIONS_MAJOR      2
# define STLSOFT_VER_STLSOFT_STRING_H_COPY_FUNCTIONS_MINOR      0
# define STLSOFT_VER_STLSOFT_STRING_H_COPY_FUNCTIONS_REVISION   3
# define STLSOFT_VER_STLSOFT_STRING_H_COPY_FUNCTIONS_EDIT       12
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
# include <stlsoft/string/string_slice.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

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

/** Copies the maximum possible number of non-nul characters in the source
 * string to the destination, and a terminating nul-character if the
 * destination is sufficently large
 *
 * \param dest Pointer to the destination memory
 * \param cchDest Number of characters available to write in \c dest
 * \param src Pointer to the source memory
 * \param cchSrc Number of characters available to copy in \c src
 *
 * \return The number of non-nul characters from \c src written to \c dest
 *
 * \note Always applies a terminating nul character if cchDest > cchSrc
 *
 * \pre (0 == cchDest || NULL != dest);
 * \pre (0 == cchSrc || NULL != src);
 */
STLSOFT_INLINE
ss_size_t
STLSoft_C_string_copy_a(
    ss_char_a_t*            dest
,   ss_size_t               cchDest
,   ss_char_a_t const*      src
,   ss_size_t               cchSrc
)
{
    ss_size_t n;

    STLSOFT_ASSERT(0 == cchDest || NULL != dest);
    STLSOFT_ASSERT(0 == cchSrc || NULL != src);

    n = (cchDest < cchSrc) ? cchDest : cchSrc;

    if (0 != n &&
        0 != cchSrc)
    {
        STLSOFT_API_INTERNAL_memfns_memcpy(dest, src, sizeof(ss_char_a_t) * n);

        if (n < cchDest)
        {
            dest[n] = '\0';
        }
    }

    return n;
}

STLSOFT_INLINE
ss_size_t
STLSoft_C_string_copy_w(
    ss_char_w_t*            dest
,   ss_size_t               cchDest
,   ss_char_w_t const*      src
,   ss_size_t               cchSrc
)
{
    ss_size_t n;

    STLSOFT_ASSERT(0 == cchDest || NULL != dest);
    STLSOFT_ASSERT(0 == cchSrc || NULL != src);

    n = (cchDest < cchSrc) ? cchDest : cchSrc;

    if (0 != n &&
        0 != cchSrc)
    {
        STLSOFT_API_INTERNAL_memfns_memcpy(dest, src, sizeof(ss_char_w_t) * n);
    }

    if (n < cchDest)
    {
        dest[n] = '\0';
    }

    return n;
}


/** Copies the maximum possible number of non-nul characters in the source
 * string and a terminating nul-character to the destination.
 *
 * \param dest Pointer to the destination memory
 * \param cchDest Number of characters available to write in \c dest
 * \param src Pointer to the source memory
 * \param cchSrc Number of characters available to copy in \c src
 *
 * \return The number of non-nul characters from \c src written to \c dest
 *
 * \note Always applies a terminating nul character if cchDest > 0
 *
 * \pre (0 == cchDest || NULL != dest);
 * \pre (0 == cchSrc || NULL != src);
 */
STLSOFT_INLINE
ss_size_t
STLSoft_C_string_copy_with_nul_a(
    ss_char_a_t*            dest
,   ss_size_t               cchDest
,   ss_char_a_t const*      src
,   ss_size_t               cchSrc
)
{
    ss_size_t n;

    STLSOFT_ASSERT(0 == cchDest || NULL != dest);
    STLSOFT_ASSERT(0 == cchSrc || NULL != src);

    if (cchSrc < cchDest)
    {
        n = cchSrc;
    }
    else
    {
        if (0 == cchDest)
        {
            n = 0;
        }
        else
        {
            n = cchDest - 1;
        }
    }

    if (0 != n)
    {
        STLSOFT_API_INTERNAL_memfns_memcpy(dest, src, sizeof(ss_char_a_t) * n);

        dest[n] = '\0';
    }

    return n;
}

STLSOFT_INLINE
ss_size_t
STLSoft_C_string_copy_with_nul_w(
    ss_char_w_t*            dest
,   ss_size_t               cchDest
,   ss_char_w_t const*      src
,   ss_size_t               cchSrc
)
{
    ss_size_t n;

    STLSOFT_ASSERT(0 == cchDest || NULL != dest);
    STLSOFT_ASSERT(0 == cchSrc || NULL != src);

    if (cchSrc < cchDest)
    {
        n = cchSrc;
    }
    else
    {
        if (0 == cchDest)
        {
            n = 0;
        }
        else
        {
            n = cchDest - 1;
        }
    }

    if (0 != n)
    {
        STLSOFT_API_INTERNAL_memfns_memcpy(dest, src, sizeof(ss_char_w_t) * n);
    }

    if (0 != cchDest)
    {
        dest[n] = '\0';
    }

    return n;
}

/* /////////////////////////////////////////////////////////////////////////
 * API functions (C++)
 */

#ifdef __cplusplus

// string_copy

inline
ss_size_t
string_copy(
    ss_char_a_t*            dest
,   ss_size_t               cchDest
,   ss_char_a_t const*      src
,   ss_size_t               cchSrc
)
{
    return STLSoft_C_string_copy_a(dest, cchDest, src, cchSrc);
}

inline
ss_size_t
string_copy(
    ss_char_w_t*            dest
,   ss_size_t               cchDest
,   ss_char_w_t const*      src
,   ss_size_t               cchSrc
)
{
    return STLSoft_C_string_copy_w(dest, cchDest, src, cchSrc);
}

inline
ss_size_t
string_copy(
    ss_char_a_t*            dest
,   ss_size_t               cchDest
,   string_slice_a_t const& src
)
{
    return STLSoft_C_string_copy_a(&dest[0], cchDest, src.ptr, src.len);
}

inline
ss_size_t
string_copy(
    ss_char_w_t*            dest
,   ss_size_t               cchDest
,   string_slice_w_t const& src
)
{
    return STLSoft_C_string_copy_w(&dest[0], cchDest, src.ptr, src.len);
}

# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template<
    ss_size_t   N_dest
,   ss_size_t   N_src
>
inline
ss_size_t
string_copy(
    ss_char_a_t           (&dest)[N_dest]
,   ss_char_a_t const     (&src)[N_src]
)
{
    return STLSoft_C_string_copy_a(&dest[0], N_dest, &src[0], N_src);
}

template<
    ss_size_t   N_dest
,   ss_size_t   N_src
>
inline
ss_size_t
string_copy(
    ss_char_w_t           (&dest)[N_dest]
,   ss_char_w_t const     (&src)[N_src]
)
{
    return STLSoft_C_string_copy_w(&dest[0], N_dest, &src[0], N_src);
}

template<
    ss_size_t   N_dest
>
inline
ss_size_t
string_copy(
    ss_char_a_t           (&dest)[N_dest]
,   string_slice_a_t const& src
)
{
    return STLSoft_C_string_copy_a(&dest[0], N_dest, src.ptr, src.len);
}

template<
    ss_size_t   N_dest
>
inline
ss_size_t
string_copy(
    ss_char_w_t           (&dest)[N_dest]
,   string_slice_w_t const& src
)
{
    return STLSoft_C_string_copy_w(&dest[0], N_dest, src.ptr, src.len);
}

# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

// string_copy_with_nul

inline
ss_size_t
string_copy_with_nul(
    ss_char_a_t*            dest
,   ss_size_t               cchDest
,   ss_char_a_t const*      src
,   ss_size_t               cchSrc
)
{
    return STLSoft_C_string_copy_with_nul_a(dest, cchDest, src, cchSrc);
}

inline
ss_size_t
string_copy_with_nul(
    ss_char_w_t*            dest
,   ss_size_t               cchDest
,   ss_char_w_t const*      src
,   ss_size_t               cchSrc
)
{
    return STLSoft_C_string_copy_with_nul_w(dest, cchDest, src, cchSrc);
}

inline
ss_size_t
string_copy_with_nul(
    ss_char_a_t*            dest
,   ss_size_t               cchDest
,   string_slice_a_t const& src
)
{
    return STLSoft_C_string_copy_with_nul_a(&dest[0], cchDest, src.ptr, src.len);
}

inline
ss_size_t
string_copy_with_nul(
    ss_char_w_t*            dest
,   ss_size_t               cchDest
,   string_slice_w_t const& src
)
{
    return STLSoft_C_string_copy_with_nul_w(&dest[0], cchDest, src.ptr, src.len);
}

# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template<
    ss_size_t   N_dest
,   ss_size_t   N_src
>
inline
ss_size_t
string_copy_with_nul(
    ss_char_a_t           (&dest)[N_dest]
,   ss_char_a_t const     (&src)[N_src]
)
{
    return STLSoft_C_string_copy_with_nul_a(&dest[0], N_dest, &src[0], N_src);
}

template<
    ss_size_t   N_dest
,   ss_size_t   N_src
>
inline
ss_size_t
string_copy_with_nul(
    ss_char_w_t           (&dest)[N_dest]
,   ss_char_w_t const     (&src)[N_src]
)
{
    return STLSoft_C_string_copy_with_nul_w(&dest[0], N_dest, &src[0], N_src);
}

template<
    ss_size_t   N_dest
>
inline
ss_size_t
string_copy_with_nul(
    ss_char_a_t           (&dest)[N_dest]
,   string_slice_a_t const& src
)
{
    return STLSoft_C_string_copy_with_nul_a(&dest[0], N_dest, src.ptr, src.len);
}

template<
    ss_size_t   N_dest
>
inline
ss_size_t
string_copy_with_nul(
    ss_char_w_t           (&dest)[N_dest]
,   string_slice_w_t const& src
)
{
    return STLSoft_C_string_copy_with_nul_w(&dest[0], N_dest, src.ptr, src.len);
}

# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#endif /* __cplusplus */

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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_COPY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

