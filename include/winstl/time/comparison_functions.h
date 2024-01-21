/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/comparison_functions.h
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


/** \file winstl/time/comparison_functions.h
 *
 * \brief [C, C++] Comparison functions for Windows time types
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_COMPARISON_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_COMPARISON_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_COMPARISON_FUNCTIONS_MAJOR    4
# define WINSTL_VER_WINSTL_TIME_H_COMPARISON_FUNCTIONS_MINOR    2
# define WINSTL_VER_WINSTL_TIME_H_COMPARISON_FUNCTIONS_REVISION 2
# define WINSTL_VER_WINSTL_TIME_H_COMPARISON_FUNCTIONS_EDIT     63
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

#ifndef WINSTL_INCL_WINSTL_TIME_H_VALIDATION_FUNCTIONS
# include <winstl/time/validation_functions.h>
#endif /* !WINSTL_INCL_WINSTL_TIME_H_VALIDATION_FUNCTIONS */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR
#  include <winstl/error/conversion_error.hpp>
# endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_Time
# include <winstl/api/external/Time.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Time */

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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_INLINE
ws_sint_t
winstl_C_compare_SYSTEMTIMEs(
    SYSTEMTIME const* lhs
,   SYSTEMTIME const* rhs
);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** Compares two <code>FILETIME</code> instances
 *
 * \ingroup group__library__Time
 */
STLSOFT_INLINE
ws_sint_t
winstl_C_compare_FILETIMEs(
    FILETIME const* lhs
,   FILETIME const* rhs
)
{
    WINSTL_ASSERT(NULL != lhs);
    WINSTL_ASSERT(NULL != rhs);

    if (lhs->dwHighDateTime < rhs->dwHighDateTime)
    {
        return -1;
    }
    else if (rhs->dwHighDateTime < lhs->dwHighDateTime)
    {
        return +1;
    }
    else
    {
        if (lhs->dwLowDateTime < rhs->dwLowDateTime)
        {
            return -1;
        }
        else if (rhs->dwLowDateTime < lhs->dwLowDateTime)
        {
            return +1;
        }
        else
        {
            return 0;
        }
    }
}

/** Compares a <code>FILETIME</code> instance with a <code>SYSTEMTIME</code> instance.
 *
 * \ingroup group__library__Time
 */
STLSOFT_INLINE
ws_sint_t
winstl_C_compare_FILETIME_with_SYSTEMTIME(
    FILETIME const*     lhs
,   SYSTEMTIME const*   rhs
)
{
    FILETIME    ft2;

    WINSTL_ASSERT(NULL != lhs);
    WINSTL_ASSERT(NULL != rhs);

    if (!WINSTL_API_EXTERNAL_Time_SystemTimeToFileTime(rhs, &ft2))
    {
        /* rhs is probably invalid, so gamble on lhs
         * being valid, and convert it to FILETIME and
         * then call compare both as such.
         */

        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();
        SYSTEMTIME  st1;

        if (WINSTL_API_EXTERNAL_Time_FileTimeToSystemTime(lhs, &st1))
        {
            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_SUCCESS);

            return winstl_C_compare_SYSTEMTIMEs(&st1, rhs);
        }

        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(e);

        return -1;
    }

    return winstl_C_compare_FILETIMEs(lhs, &ft2);
}

/** Compares a <code>SYSTEMTIME</code> instance with a <code>FILETIME</code> instance.
 *
 * \ingroup group__library__Time
 */
STLSOFT_INLINE
ws_sint_t
winstl_C_compare_SYSTEMTIME_with_FILETIME(
    SYSTEMTIME const*   lhs
,   FILETIME const*     rhs
)
{
    return -winstl_C_compare_FILETIME_with_SYSTEMTIME(rhs, lhs);
}

/** Compares two <code>SYSTEMTIME</code> instances
 *
 * \ingroup group__library__Time
 */
STLSOFT_INLINE
ws_sint_t
winstl_C_compare_SYSTEMTIMEs(
    SYSTEMTIME const*   lhs
,   SYSTEMTIME const*   rhs
)
{
    WINSTL_ASSERT(NULL != lhs);
    WINSTL_ASSERT(NULL != rhs);

    if (0 == STLSOFT_NS_GLOBAL(memcmp(lhs, rhs, sizeof(SYSTEMTIME))))
    {
        return 0;
    }

    /* Year */

    if (lhs->wYear < rhs->wYear)
    {
        return -1;
    }
    else
    if (lhs->wYear > rhs->wYear)
    {
        return +1;
    }

    /* Month */

    if (lhs->wMonth < rhs->wMonth)
    {
        return -1;
    }
    else
    if (lhs->wMonth > rhs->wMonth)
    {
        return +1;
    }

    /* Day */

    if (lhs->wDay < rhs->wDay)
    {
        return -1;
    }
    else
    if (lhs->wDay > rhs->wDay)
    {
        return +1;
    }

    /* Hour */

    if (lhs->wHour < rhs->wHour)
    {
        return -1;
    }
    else
    if (lhs->wHour > rhs->wHour)
    {
        return +1;
    }

    /* Minute */

    if (lhs->wMinute < rhs->wMinute)
    {
        return -1;
    }
    else
    if (lhs->wMinute > rhs->wMinute)
    {
        return +1;
    }

    /* Second */

    if (lhs->wSecond < rhs->wSecond)
    {
        return -1;
    }
    else
    if (lhs->wSecond > rhs->wSecond)
    {
        return +1;
    }

    /* Milliseconds */

    if (lhs->wMilliseconds < rhs->wMilliseconds)
    {
        return -1;
    }
    else
    if (lhs->wMilliseconds > rhs->wMilliseconds)
    {
        return +1;
    }

    return 0;
}

STLSOFT_INLINE
ss_uint64_t
winstl_C_absolute_difference_in_microseconds_FILETIMEs(
    FILETIME const* t1
,   FILETIME const* t2
)
{
    ss_uint64_t n1;
    ss_uint64_t n2;

    WINSTL_ASSERT(NULL != t1);
    WINSTL_ASSERT(NULL != t2);

    n1 = (stlsoft_static_cast(ss_uint64_t, t1->dwHighDateTime) << 32) + (stlsoft_static_cast(ss_uint64_t, t1->dwLowDateTime) << 0);
    n2 = (stlsoft_static_cast(ss_uint64_t, t2->dwHighDateTime) << 32) + (stlsoft_static_cast(ss_uint64_t, t2->dwLowDateTime) << 0);

    if (n1 < n2)
    {
        return (n2 - n1) / 10;
    }
    else
    {
        return (n1 - n2) / 10;
    }
}

STLSOFT_INLINE
ss_uint64_t
winstl_C_absolute_difference_in_microseconds_SYSTEMTIMEs(
    SYSTEMTIME const*   t1
,   SYSTEMTIME const*   t2
)
{
    FILETIME ft1;
    FILETIME ft2;

    WINSTL_ASSERT(NULL != t1);
    WINSTL_ASSERT(NULL != t2);

    if (0 == STLSOFT_NS_GLOBAL(memcmp(t1, t2, sizeof(SYSTEMTIME))))
    {
        return 0;
    }

    if (t1->wYear == t2->wYear &&
        t1->wMonth == t2->wMonth)
    {
        HRESULT const hr1 = winstl_C_time_validate_SYSTEMTIME(t1, NULL);
        HRESULT const hr2 = winstl_C_time_validate_SYSTEMTIME(t2, NULL);

        if (ERROR_SUCCESS != hr1 ||
            ERROR_SUCCESS != hr2)
        {
            return ~stlsoft_static_cast(ss_uint64_t, 0);
        }
        else
        {
            ss_uint64_t const   us_in_ms    =   1000;
            ss_uint64_t const   us_in_s     =   us_in_ms * 1000;
            ss_uint64_t const   us_in_m     =   us_in_s * 60;
            ss_uint64_t const   us_in_h     =   us_in_m * 60;
            ss_uint64_t const   us_in_d     =   us_in_h * 24;

            ss_uint64_t const   t1_us   =   0
                                        +   t1->wMilliseconds * us_in_ms
                                        +   t1->wSecond * us_in_s
                                        +   t1->wMinute * us_in_m
                                        +   t1->wHour * us_in_h
                                        +   t1->wDay * us_in_d
                                        ;

            ss_uint64_t const   t2_us   =   0
                                        +   t2->wMilliseconds * us_in_ms
                                        +   t2->wSecond * us_in_s
                                        +   t2->wMinute * us_in_m
                                        +   t2->wHour * us_in_h
                                        +   t2->wDay * us_in_d
                                        ;

            if (t1_us < t2_us)
            {
                return t2_us - t1_us;
            }
            else
            {
                return t1_us - t2_us;
            }
        }
    }

    if (!WINSTL_API_EXTERNAL_Time_SystemTimeToFileTime(t1, &ft1))
    {
        return ~stlsoft_static_cast(ss_uint64_t, 0);
    }
    if (!WINSTL_API_EXTERNAL_Time_SystemTimeToFileTime(t2, &ft2))
    {
        return ~stlsoft_static_cast(ss_uint64_t, 0);
    }

    return winstl_C_absolute_difference_in_microseconds_FILETIMEs(&ft1, &ft2);
}

STLSOFT_INLINE
ss_uint64_t
winstl_C_absolute_difference_in_milliseconds_FILETIMEs(
    FILETIME const* t1
,   FILETIME const* t2
)
{
    return winstl_C_absolute_difference_in_microseconds_FILETIMEs(t1, t2) / 1000;
}

STLSOFT_INLINE
ss_uint64_t
winstl_C_absolute_difference_in_milliseconds_SYSTEMTIMEs(
    SYSTEMTIME const*   t1
,   SYSTEMTIME const*   t2
)
{
    return winstl_C_absolute_difference_in_microseconds_SYSTEMTIMEs(t1, t2) / 1000;
}

STLSOFT_INLINE
ss_uint64_t
winstl_C_absolute_difference_in_seconds_FILETIMEs(
    FILETIME const* t1
,   FILETIME const* t2
)
{
    return winstl_C_absolute_difference_in_milliseconds_FILETIMEs(t1, t2) / 1000;
}

STLSOFT_INLINE
ss_uint64_t
winstl_C_absolute_difference_in_seconds_SYSTEMTIMEs(
    SYSTEMTIME const*   t1
,   SYSTEMTIME const*   t2
)
{
    return winstl_C_absolute_difference_in_milliseconds_SYSTEMTIMEs(t1, t2) / 1000;
}

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

/** Compares two <code>FILETIME</code> instances
 *
 * Implemented in terms of winstl_C_compare_FILETIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ws_sint_t
compare(
    FILETIME const& lhs
,   FILETIME const& rhs
)
{
    return winstl_C_compare_FILETIMEs(&lhs, &rhs);
}

/** Compares a <code>FILETIME</code> instance with a <code>SYSTEMTIME</code> instance.
 *
 * Implemented in terms of winstl_C_compare_FILETIME_with_SYSTEMTIME()
 *
 * \ingroup group__library__Time
 */
inline
ws_sint_t
compare(
    FILETIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_SUCCESS);

    ws_sint_t const r   =   winstl_C_compare_FILETIME_with_SYSTEMTIME(&lhs, &rhs);
    DWORD const     e   =   WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

    if (ERROR_SUCCESS != e)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return r;
}

/** Compares a <code>SYSTEMTIME</code> instance with a <code>FILETIME</code> instance.
 *
 * Implemented in terms of winstl_C_compare_SYSTEMTIME_with_FILETIME()
 *
 * \ingroup group__library__Time
 */
inline
ws_sint_t
compare(
    SYSTEMTIME const&   lhs
,   FILETIME const&     rhs
)
{
    WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_SUCCESS);

    ws_sint_t const r   =   winstl_C_compare_SYSTEMTIME_with_FILETIME(&lhs, &rhs);
    DWORD const     e   =   WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

    if (ERROR_SUCCESS != e)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return r;
}

/** Compares two <code>SYSTEMTIME</code> instances
 *
 * Implemented in terms of winstl_C_compare_SYSTEMTIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ws_sint_t
compare(
    SYSTEMTIME const&   lhs
,   SYSTEMTIME const&   rhs
)
{
    return winstl_C_compare_SYSTEMTIMEs(&lhs, &rhs);
}

/** Compares two <code>SYSTEMTIME</code> instances, and returns the absolute
 * difference in microseconds.
 *
 * Implemented in terms of winstl_C_absolute_difference_in_microseconds_SYSTEMTIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ss_uint64_t
absolute_difference_in_microseconds(
    SYSTEMTIME const&   t1
,   SYSTEMTIME const&   t2
)
{
    ss_uint64_t const r = winstl_C_absolute_difference_in_microseconds_SYSTEMTIMEs(&t1, &t2);

    if (~stlsoft_static_cast(ss_uint64_t, 0) == r)
    {
        DWORD const e = ERROR_INVALID_PARAMETER;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return r;
}

/** Compares two <code>FILETIME</code> instances, and returns the absolute
 * difference in microseconds.
 *
 * Implemented in terms of winstl_C_absolute_difference_in_microseconds_FILETIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ss_uint64_t
absolute_difference_in_microseconds(
    FILETIME const&   t1
,   FILETIME const&   t2
)
{
    return winstl_C_absolute_difference_in_microseconds_FILETIMEs(&t1, &t2);
}

/** Compares two <code>SYSTEMTIME</code> instances, and returns the absolute
 * difference in milliseconds.
 *
 * Implemented in terms of winstl_C_absolute_difference_in_milliseconds_SYSTEMTIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ss_uint64_t
absolute_difference_in_milliseconds(
    SYSTEMTIME const&   t1
,   SYSTEMTIME const&   t2
)
{
    ss_uint64_t const r = winstl_C_absolute_difference_in_milliseconds_SYSTEMTIMEs(&t1, &t2);

    if (~stlsoft_static_cast(ss_uint64_t, 0) == r)
    {
        DWORD const e = ERROR_INVALID_PARAMETER;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return r;
}

/** Compares two <code>FILETIME</code> instances, and returns the absolute
 * difference in milliseconds.
 *
 * Implemented in terms of winstl_C_absolute_difference_in_milliseconds_FILETIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ss_uint64_t
absolute_difference_in_milliseconds(
    FILETIME const&   t1
,   FILETIME const&   t2
)
{
    return winstl_C_absolute_difference_in_milliseconds_FILETIMEs(&t1, &t2);
}

/** Compares two <code>SYSTEMTIME</code> instances, and returns the absolute
 * difference in seconds.
 *
 * Implemented in terms of winstl_C_absolute_difference_in_seconds_SYSTEMTIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ss_uint64_t
absolute_difference_in_seconds(
    SYSTEMTIME const&   t1
,   SYSTEMTIME const&   t2
)
{
    ss_uint64_t const r = winstl_C_absolute_difference_in_seconds_SYSTEMTIMEs(&t1, &t2);

    if (~stlsoft_static_cast(ss_uint64_t, 0) == r)
    {
        DWORD const e = ERROR_INVALID_PARAMETER;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return r;
}

/** Compares two <code>FILETIME</code> instances, and returns the absolute
 * difference in seconds.
 *
 * Implemented in terms of winstl_C_absolute_difference_in_seconds_FILETIMEs()
 *
 * \ingroup group__library__Time
 */
inline
ss_uint64_t
absolute_difference_in_seconds(
    FILETIME const&   t1
,   FILETIME const&   t2
)
{
    return winstl_C_absolute_difference_in_seconds_FILETIMEs(&t1, &t2);
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * backwards compatibility
 */

#ifdef STLSOFT_OBSOLETE

STLSOFT_INLINE ws_sint_t winstl__compare_FILETIMEs(FILETIME const* lhs, FILETIME const* rhs)
{
    return winstl_C_compare_FILETIMEs(lhs, rhs);
}
STLSOFT_INLINE ws_sint_t winstl__compare_FILETIME_with_SYSTEMTIME(FILETIME const* lhs, SYSTEMTIME const* rhs)
{
    return winstl_C_compare_FILETIME_with_SYSTEMTIME(lhs, rhs);
}
STLSOFT_INLINE ws_sint_t winstl__compare_SYSTEMTIME_with_FILETIME(SYSTEMTIME const* lhs, FILETIME const* rhs)
{
    return winstl_C_compare_SYSTEMTIME_with_FILETIME(lhs, rhs);
}
STLSOFT_INLINE ws_sint_t winstl__compare_SYSTEMTIMEs(SYSTEMTIME const* lhs, SYSTEMTIME const* rhs)
{
    return winstl_C_compare_SYSTEMTIMEs(lhs, rhs);
}

#endif /* !STLSOFT_OBSOLETE */

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

#endif /* !WINSTL_INCL_WINSTL_TIME_H_COMPARISON_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

