/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/conversion_functions.h
 *
 * Purpose:     Comparison functions for Windows time structures.
 *
 * Created:     21st November 2003
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/time/conversion_functions.h
 *
 * \brief [C, C++] Conversion functions for Windows time types
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_MAJOR    4
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_MINOR    1
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_REVISION 7
# define WINSTL_VER_WINSTL_TIME_H_CONVERSION_FUNCTIONS_EDIT     67
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.h>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS */

#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** Converts a time_t into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 *
 * \pre (NULL != ft)
 */
STLSOFT_INLINE
void
winstl_C_UNIXTimeToFILETIME(
    time_t      t
,   FILETIME*   ft
)
{
    ws_uint64_t const i = UInt32x32To64(t, 10000000) + STLSOFT_GEN_UINT64_SUFFIX(116444736000000000);

    WINSTL_ASSERT(NULL != ft);

    ft->dwLowDateTime = (DWORD)i;
    ft->dwHighDateTime = (DWORD)(i >> 32);
}

/** Converts a time_t and a microseconds value into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 *
 * \pre (NULL != ft)
 */
STLSOFT_INLINE
void
winstl_C_UNIXTimeToFILETIME_us(
    time_t      t
,   ws_sint32_t usec
,   FILETIME*   ft
)
{
    ws_uint64_t const i = UInt32x32To64(t, 10000000) + Int32x32To64(usec, 10) + STLSOFT_GEN_UINT64_SUFFIX(116444736000000000);

    WINSTL_ASSERT(NULL != ft);

    ft->dwLowDateTime = (DWORD)i;
    ft->dwHighDateTime = (DWORD)(i >> 32);
}

/** Converts a FILETIME into a time_t
 *
 * \ingroup group__library__Time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 *
 * \pre (NULL != ft)
 */
STLSOFT_INLINE
time_t
winstl_C_FILETIMEToUNIXTime(
    FILETIME const* ft
,   ws_sint32_t*    microseconds
)
{
    ws_sint64_t i;

    WINSTL_ASSERT(NULL != ft);

    i = ft->dwHighDateTime;
    i <<= 32;
    i |= ft->dwLowDateTime;

    i -= STLSOFT_GEN_UINT64_SUFFIX(116444736000000000);
    if (NULL != microseconds)
    {
        *microseconds = stlsoft_static_cast(ws_sint32_t, (i % 10000000) / 10);

        WINSTL_ASSERT(*microseconds >= 0 && *microseconds <= 999999);
    }
    i /= 10000000;

    return stlsoft_static_cast(time_t, i);
}

/* /////////////////////////////////////////////////////////////////////////
 * obsolete symbols
 *
 * NOTE: these are only defined if:
 *
 * - we're generating documentation, or
 * - STLSOFT_OBSOLETE is specified, or
 * - it's STLSoft 1.9 (or earlier)
 */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION) || \
    defined(STLSOFT_OBSOLETE) || \
    _STLSOFT_VER < 0x010a0000

/** \def winstl__UNIXTimeToFILETIME
 *
 * \deprecated Use winstl_C_UNIXTimeToFILETIME
 */
# define winstl__UNIXTimeToFILETIME                         winstl_C_UNIXTimeToFILETIME
/** \def winstl__UNIXTimeToFILETIME_us
 *
 * \deprecated Use winstl_C_UNIXTimeToFILETIME_us
 */
# define winstl__UNIXTimeToFILETIME_us                      winstl_C_UNIXTimeToFILETIME_us
/** \def winstl__FILETIMEToUNIXTime
 *
 * \deprecated Use winstl_C_FILETIMEToUNIXTime
 */
# define winstl__FILETIMEToUNIXTime                         winstl_C_FILETIMEToUNIXTime

#endif /* obsolete || 1.9 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT

/** Converts a time_t into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline
void
UNIXTimeToFILETIME(
    time_t      t
,   FILETIME&   ft
)
{
    winstl_C_UNIXTimeToFILETIME(t, &ft);
}

/** Converts a time_t into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline
FILETIME
UNIXTimeToFILETIME(
    time_t  t
)
{
    FILETIME ft;

    winstl_C_UNIXTimeToFILETIME(t, &ft);

    return ft;
}

/** Converts a time_t + microseconds into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline
void
UNIXTimeToFILETIME(
    time_t      t
,   ws_sint32_t usec
,   FILETIME&   ft
)
{
    winstl_C_UNIXTimeToFILETIME_us(t, usec, &ft);
}

/** Converts a time_t + microseconds into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \note This follows the algorithm provided in MSDN Q167296
 */
inline
FILETIME
UNIXTimeToFILETIME(
    time_t      t
,   ws_sint32_t usec
)
{
    FILETIME ft;

    winstl_C_UNIXTimeToFILETIME_us(t, usec, &ft);

    return ft;
}

/** Converts a FILETIME into a time_t
 *
 * \ingroup group__library__Time
 */
inline
time_t
FILETIMEToUNIXTime(
    FILETIME const& ft
,   ws_sint32_t*    microseconds = NULL
)
{
    return winstl_C_FILETIMEToUNIXTime(&ft, microseconds);
}

/** Converts a FILETIME into a time_t
 *
 * \ingroup group__library__Time
 */
inline
void
FILETIMEToUNIXTime(
    FILETIME const& ft
,   time_t&         t
)
{
    t = winstl_C_FILETIMEToUNIXTime(&ft, NULL);
}

/** Converts a FILETIME into a time_t
 *
 * \ingroup group__library__Time
 */
inline
void
FILETIMEToUNIXTime(
    FILETIME const& ft
,   time_t&         t
,   ws_sint32_t&    microseconds
)
{
    t = winstl_C_FILETIMEToUNIXTime(&ft, &microseconds);
}

# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

