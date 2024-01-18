/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/itoslice.h
 *
 * Purpose:     integer to string slice conversions.
 *
 * Created:     18th December 2016
 * Updated:     18th January 2024
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


/** \file stlsoft/conversion/itoslice.h
 *
 * \brief [C++] integer to slice conversion
 *   function suite
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_H_ITOSLICE
#define STLSOFT_INCL_STLSOFT_CONVERSION_H_ITOSLICE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_H_ITOSLICE_MAJOR    1
# define STLSOFT_VER_STLSOFT_CONVERSION_H_ITOSLICE_MINOR    0
# define STLSOFT_VER_STLSOFT_CONVERSION_H_ITOSLICE_REVISION 2
# define STLSOFT_VER_STLSOFT_CONVERSION_H_ITOSLICE_EDIT     7
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
# include <stlsoft/string/string_slice.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STRING_H_VSNPRINTF
# include <stlsoft/util/string/snprintf.h>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STRING_H_VSNPRINTF */

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

STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_itoslice_a(
    int             value
,   ss_char_a_t*    dest
,   ss_size_t       cchDest
)
{
    stlsoft_C_string_slice_a_t  r;
    int const                   n = stlsoft_C_snprintf(dest, cchDest, "%d", value);

    if (n < 0)
    {
        r.len   =   0;
        r.ptr   =   NULL;
    }
    else
    {
        r.len   =   STLSOFT_STATIC_CAST(ss_size_t, n);
        r.ptr   =   dest;
    }

    return r;
}

STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_utoslice_a(
    unsigned int    value
,   ss_char_a_t*    dest
,   ss_size_t       cchDest
)
{
    stlsoft_C_string_slice_a_t  r;
    int const                   n = stlsoft_C_snprintf(dest, cchDest, "%u", value);

    if (n < 0)
    {
        r.len   =   0;
        r.ptr   =   NULL;
    }
    else
    {
        r.len   =   STLSOFT_STATIC_CAST(ss_size_t, n);
        r.ptr   =   dest;
    }

    return r;
}

STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_ltoslice_a(
    long            value
,   ss_char_a_t*    dest
,   ss_size_t       cchDest
)
{
    stlsoft_C_string_slice_a_t  r;
    int const                   n = stlsoft_C_snprintf(dest, cchDest, "%ld", value);

    if (n < 0)
    {
        r.len   =   0;
        r.ptr   =   NULL;
    }
    else
    {
        r.len   =   STLSOFT_STATIC_CAST(ss_size_t, n);
        r.ptr   =   dest;
    }

    return r;
}

STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_lutoslice_a(
    unsigned long   value
,   ss_char_a_t*    dest
,   ss_size_t       cchDest
)
{
    stlsoft_C_string_slice_a_t  r;
    int const                   n = stlsoft_C_snprintf(dest, cchDest, "%lu", value);

    if (n < 0)
    {
        r.len   =   0;
        r.ptr   =   NULL;
    }
    else
    {
        r.len   =   STLSOFT_STATIC_CAST(ss_size_t, n);
        r.ptr   =   dest;
    }

    return r;
}


STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_itoslice21_a(
    int     value
,   char  (*ar)[21]
)
{
    STLSOFT_ASSERT(NULL != ar);

    return stlsoft_C_itoslice_a(value, &(*ar)[0], 21);
}

STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_utoslice21_a(
    unsigned int    value
,   char          (*ar)[21]
)
{
    STLSOFT_ASSERT(NULL != ar);

    return stlsoft_C_utoslice_a(value, &(*ar)[0], 21);
}

STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_ltoslice21_a(
    long    value
,   char  (*ar)[21]
)
{
    STLSOFT_ASSERT(NULL != ar);

    return stlsoft_C_ltoslice_a(value, &(*ar)[0], 21);
}

STLSOFT_INLINE
stlsoft_C_string_slice_a_t
stlsoft_C_lutoslice21_a(
    unsigned long   value
,   char          (*ar)[21]
)
{
    STLSOFT_ASSERT(NULL != ar);

    return stlsoft_C_lutoslice_a(value, &(*ar)[0], 21);
}

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

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_H_ITOSLICE */

/* ///////////////////////////// end of file //////////////////////////// */

