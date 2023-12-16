/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/creation_functions.h
 *
 * Purpose:     Creation functions for Windows time structures.
 *
 * Created:     25th February 2017
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2017-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/time/creation_functions.h
 *
 * \brief [C, C++] Creation functions for Windows time types
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_CREATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_CREATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_CREATION_FUNCTIONS_MAJOR      1
# define WINSTL_VER_WINSTL_TIME_H_CREATION_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_TIME_H_CREATION_FUNCTIONS_REVISION   2
# define WINSTL_VER_WINSTL_TIME_H_CREATION_FUNCTIONS_EDIT       4
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

/** Creates an instance of a SYSTEMTIME from individual date/time unit
 * values
 *
 * \param year The year unit value
 * \param month The month unit value
 * \param day The day unit value
 * \param hour The hour unit value
 * \param minute The minute unit value
 * \param second The second unit value
 * \param millisecond The millisecond unit value
 *
 * \note No validation on values is performed
 *
 * \pre (year >= 1601 && year <= 30827)
 * \pre (month >= 1 && month <= 12)
 * \pre (day >= 1 && day <= 31)
 * \pre hour < 24
 * \pre minute < 60
 * \pre second < 60
 * \pre millisecond < 1000
 */
STLSOFT_INLINE
SYSTEMTIME
winstl_C_create_SYSTEMTIME_ms(
    unsigned        year
,   unsigned        month
,   unsigned        day
,   unsigned        hour
,   unsigned        minute
,   unsigned        second
,   unsigned        millisecond
) STLSOFT_NOEXCEPT
{
    SYSTEMTIME st = { 0 };

    WINSTL_ASSERT(year >= 1601 && year <= 30827);
    WINSTL_ASSERT(month >= 1 && month <= 12);
    WINSTL_ASSERT(day >= 1 && day <= 31);
    WINSTL_ASSERT(hour < 24);
    WINSTL_ASSERT(minute < 60);
    WINSTL_ASSERT(second < 60);
    WINSTL_ASSERT(millisecond < 1000);

    st.wYear            =   STLSOFT_STATIC_CAST(WORD, year);
    st.wMonth           =   STLSOFT_STATIC_CAST(WORD, month);
    st.wDay             =   STLSOFT_STATIC_CAST(WORD, day);
    st.wHour            =   STLSOFT_STATIC_CAST(WORD, hour);
    st.wMinute          =   STLSOFT_STATIC_CAST(WORD, minute);
    st.wSecond          =   STLSOFT_STATIC_CAST(WORD, second);
    st.wMilliseconds    =   STLSOFT_STATIC_CAST(WORD, millisecond);

    return st;
}

/** Initialises an instance of a FILETIME from individual date/time unit
 * values
 *
 * \param ft Pointer to FILETIME instance to be initialised. May not be
 *   NULL
 * \param year The year unit value
 * \param month The month unit value
 * \param day The day unit value
 * \param hour The hour unit value
 * \param minute The minute unit value
 * \param second The second unit value
 * \param millisecond The millisecond unit value
 *
 * \note No validation on values is performed
 *
 * \pre NULL != ft
 * \pre (year >= 1601 && year <= 30827)
 * \pre (month >= 1 && month <= 12)
 * \pre (day >= 1 && day <= 31)
 * \pre hour < 24
 * \pre minute < 60
 * \pre second < 60
 * \pre millisecond < 1000
 */
STLSOFT_INLINE
BOOL
winstl_C_create_FILETIME_ms(
    FILETIME*       ft
,   unsigned        year
,   unsigned        month
,   unsigned        day
,   unsigned        hour
,   unsigned        minute
,   unsigned        second
,   unsigned        millisecond
) STLSOFT_NOEXCEPT
{
    SYSTEMTIME const st = winstl_C_create_SYSTEMTIME_ms(year, month, day, hour, minute, second, millisecond);

    WINSTL_ASSERT(NULL != ft);

    return STLSOFT_NS_GLOBAL(SystemTimeToFileTime)(&st, ft);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** \see winstl_C_create_SYSTEMTIME_ms()
 */
STLSOFT_INLINE
SYSTEMTIME
create_SYSTEMTIME_ms(
    unsigned        year
,   unsigned        month
,   unsigned        day
,   unsigned        hour
,   unsigned        minute
,   unsigned        second
,   unsigned        millisecond
) STLSOFT_NOEXCEPT
{
    return winstl_C_create_SYSTEMTIME_ms(year, month, day, hour, minute, second, millisecond);
}

/** \see winstl_C_create_FILETIME_ms()
 */
STLSOFT_INLINE
BOOL
create_FILETIME_ms(
    FILETIME*       ft
,   unsigned        year
,   unsigned        month
,   unsigned        day
,   unsigned        hour
,   unsigned        minute
,   unsigned        second
,   unsigned        millisecond
) STLSOFT_NOEXCEPT
{
    return winstl_C_create_FILETIME_ms(ft, year, month, day, hour, minute, second, millisecond);
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

#endif /* !WINSTL_INCL_WINSTL_TIME_H_CREATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

