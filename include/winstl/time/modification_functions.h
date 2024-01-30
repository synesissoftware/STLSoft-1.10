/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/modification_functions.h
 *
 * Purpose:     Modification functions for Windows time structures.
 *
 * Created:     2nd February 2011
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


/** \file winstl/time/modification_functions.h
 *
 * \brief [C, C++] Modification functions for Windows time types
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_MODIFICATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_MODIFICATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_MODIFICATION_FUNCTIONS_MAJOR    2
# define WINSTL_VER_WINSTL_TIME_H_MODIFICATION_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_TIME_H_MODIFICATION_FUNCTIONS_REVISION 1
# define WINSTL_VER_WINSTL_TIME_H_MODIFICATION_FUNCTIONS_EDIT     12
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

/** Increments the time in a <code>FILETIME</code> instance by the given
 * number of days, hours, minutes, seconds, and microseconds, any of which
 * can be negative, and stores the result in a new instance.
 *
 * \ingroup group__library__Time
 *
 * \param result Pointer to a <code>FILETIME</code> instance in which the
 *   result will be written. <code>result == origin</code> is valid.
 * \param origin Pointer to a <code>FILETIME</code> instance from which the
 *   origin time will be read. <code>result == origin</code> is valid.
 * \param days The number of days to add. May be negative, in which case a
 *   subtraction is effected.
 * \param hours The number of hours to add. May be negative, in which case a
 *   subtraction is effected.
 * \param minutes The number of minutes to add. May be negative, in which
 *   case a subtraction is effected.
 * \param seconds The number of seconds to add. May be negative, in which
 *   case a subtraction is effected.
 * \param microseconds The number of microseconds to add. May be negative,
 *   in which case a subtraction is effected.
 *
 * \return The function does not return a value. The pointers must not be
 *   <code>NULL</code>, and no validity checking is performed on the offset
 *   parameter values.
 *
 * \pre (NULL != result)
 * \pre (NULL != origin)
 */
STLSOFT_INLINE
void
winstl_C_increment_FILETIME_us(
    FILETIME*       result
,   FILETIME const* origin
,   int             days
,   int             hours
,   int             minutes
,   ws_sint64_t     seconds
,   ws_sint64_t     microseconds
)
{
    ULARGE_INTEGER const* const puliOrigin = stlsoft_c_cast(ULARGE_INTEGER*, origin);
    ULARGE_INTEGER* const       puliResult = stlsoft_c_cast(ULARGE_INTEGER*, result);

    WINSTL_ASSERT(NULL != result);
    WINSTL_ASSERT(NULL != origin);

    puliResult->QuadPart = puliOrigin->QuadPart;

    if (0 != microseconds)
    {
        puliResult->QuadPart += stlsoft_static_cast(ULONGLONG, 10) * microseconds;
    }
    if (0 != seconds)
    {
        puliResult->QuadPart += stlsoft_static_cast(ULONGLONG, 10000) * 1000 * seconds;
    }
    if (0 != minutes)
    {
        puliResult->QuadPart += stlsoft_static_cast(ULONGLONG, 10000) * 1000 * 60 * minutes;
    }
    if (0 != hours)
    {
        puliResult->QuadPart += stlsoft_static_cast(ULONGLONG, 10000) * 1000 * 60 * 60 * hours;
    }
    if (0 != days)
    {
        puliResult->QuadPart += stlsoft_static_cast(ULONGLONG, 10000) * 1000 * 60 * 60 * 24 * days;
    }
}

/** Increments the time in a <code>FILETIME</code> instance by the given
 * number of days, hours, minutes, seconds, and milliseconds, any of which
 * can be negative, and stores the result in a new instance.
 *
 * \ingroup group__library__Time
 *
 * \param result Pointer to a <code>FILETIME</code> instance in which the
 *   result will be written. <code>result == origin</code> is valid.
 * \param origin Pointer to a <code>FILETIME</code> instance from which the
 *   origin time will be read. <code>result == origin</code> is valid.
 * \param days The number of days to add. May be negative, in which case a
 *   subtraction is effected.
 * \param hours The number of hours to add. May be negative, in which case a
 *   subtraction is effected.
 * \param minutes The number of minutes to add. May be negative, in which
 *   case a subtraction is effected.
 * \param seconds The number of seconds to add. May be negative, in which
 *   case a subtraction is effected.
 * \param milliseconds The number of milliseconds to add. May be negative,
 *   in which case a subtraction is effected.
 *
 * \return The function does not return a value. The pointers must not be
 *   <code>NULL</code>, and no validity checking is performed on the offset
 *   parameter values.
 *
 * \pre (NULL != result)
 * \pre (NULL != origin)
 */
STLSOFT_INLINE
void
winstl_C_increment_FILETIME(
    FILETIME*       result
,   FILETIME const* origin
,   int             days
,   int             hours
,   int             minutes
,   ws_sint64_t     seconds
,   ws_sint64_t     milliseconds
)
{
    WINSTL_ASSERT(NULL != result);
    WINSTL_ASSERT(NULL != origin);

    winstl_C_increment_FILETIME_us(result, origin, days, hours, minutes, seconds, milliseconds * 1000);
}

STLSOFT_INLINE
BOOL
winstl_C_increment_SYSTEMTIME(
    SYSTEMTIME*         result
,   SYSTEMTIME const*   origin
,   int                 days
,   int                 hours
,   int                 minutes
,   ws_sint64_t         seconds
,   ws_sint64_t         milliseconds
)
{
    FILETIME ftOrigin;

    if (STLSOFT_NS_GLOBAL(SystemTimeToFileTime(origin, &ftOrigin)))
    {
        FILETIME ftResult;

        winstl_C_increment_FILETIME(
            &ftResult
        ,   &ftOrigin
        ,   days
        ,   hours
        ,   minutes
        ,   seconds
        ,   milliseconds
        );

        if (STLSOFT_NS_GLOBAL(FileTimeToSystemTime(&ftResult, result)))
        {
            return TRUE;
        }
    }

    return FALSE;
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** Increments the time in a <code>FILETIME</code> instance by the given
 * number of days, hours, minutes, seconds, and microseconds, any of which
 * can be negative, and stores the result in a new instance.
 *
 * Implemented in terms of winstl_C_increment_FILETIME()
 *
 * \ingroup group__library__Time
 */
inline
void
increment_FILETIME_us(
    FILETIME*       result
,   FILETIME const* origin
,   int             days
,   int             hours
,   int             minutes
,   ws_sint64_t     seconds
,   ws_sint64_t     microseconds
)
{
    winstl_C_increment_FILETIME_us(
        result
    ,   origin
    ,   days
    ,   hours
    ,   minutes
    ,   seconds
    ,   microseconds
    );
}

/** Increments the time in a <code>FILETIME</code> instance by the given
 * number of days, hours, minutes, seconds, and milliseconds, any of which
 * can be negative, and stores the result in a new instance.
 *
 * Implemented in terms of winstl_C_increment_FILETIME()
 *
 * \ingroup group__library__Time
 */
inline
void
increment_FILETIME(
    FILETIME*       result
,   FILETIME const* origin
,   int             days
,   int             hours
,   int             minutes
,   ws_sint64_t     seconds
,   ws_sint64_t     milliseconds
)
{
    winstl_C_increment_FILETIME(
        result
    ,   origin
    ,   days
    ,   hours
    ,   minutes
    ,   seconds
    ,   milliseconds
    );
}

/** Increments the time in a <code>SYSTEMTIME</code> instance by the given
 * number of days, hours, minutes, seconds, and milliseconds, any of which
 * can be negative, and stores the result in a new instance.
 *
 * Implemented in terms of winstl_C_increment_SYSTEMTIME()
 *
 * \ingroup group__library__Time
 */
inline
BOOL
increment_SYSTEMTIME(
    SYSTEMTIME*         result
,   SYSTEMTIME const*   origin
,   int                 days
,   int                 hours
,   int                 minutes
,   ws_sint64_t         seconds
,   ws_sint64_t         milliseconds
)
{
    return winstl_C_increment_SYSTEMTIME(
        result
    ,   origin
    ,   days
    ,   hours
    ,   minutes
    ,   seconds
    ,   milliseconds
    );
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * backwards compatibility
 */

#ifdef STLSOFT_OBSOLETE

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

#endif /* !WINSTL_INCL_WINSTL_TIME_H_MODIFICATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

