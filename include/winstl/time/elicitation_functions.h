/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/elicitation_functions.h
 *
 * Purpose:     Elicitation functions for Windows time structures.
 *
 * Created:     26th May 2014
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2014-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/time/elicitation_functions.h
 *
 * \brief [C, C++] Elicitation functions for Windows time structures
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_ELICITATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_ELICITATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_ELICITATION_FUNCTIONS_MAJOR       2
# define WINSTL_VER_WINSTL_TIME_H_ELICITATION_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_TIME_H_ELICITATION_FUNCTIONS_REVISION    1
# define WINSTL_VER_WINSTL_TIME_H_ELICITATION_FUNCTIONS_EDIT        11
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

/** Elicits the current time as UTC time, into a SYSTEMTIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != st)
 */
STLSOFT_INLINE
void
winstl_C_get_UTC_time_as_SYSTEMTIME(
    SYSTEMTIME* st
)
{
    WINSTL_ASSERT(NULL != st);

    STLSOFT_NS_GLOBAL(GetSystemTime)(st);
}

/** Elicits the current time as UTC time, into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != ft)
 */
STLSOFT_INLINE
void
winstl_C_get_UTC_time_as_FILETIME(
    FILETIME* ft
)
{
    WINSTL_ASSERT(NULL != ft);

    STLSOFT_NS_GLOBAL(GetSystemTimeAsFileTime)(ft);
}

/** Elicits the current time as local time, into a SYSTEMTIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != st)
 */
STLSOFT_INLINE
void
winstl_C_get_local_time_as_SYSTEMTIME(
    SYSTEMTIME* st
)
{
    WINSTL_ASSERT(NULL != st);

    STLSOFT_NS_GLOBAL(GetLocalTime)(st);
}

/** Elicits the current time as local time, into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != ft)
 */
STLSOFT_INLINE
BOOL
winstl_C_get_local_time_as_FILETIME(
    FILETIME* ft
)
{
    SYSTEMTIME st;

    WINSTL_ASSERT(NULL != ft);

    STLSOFT_NS_GLOBAL(GetLocalTime)(&st);

    return STLSOFT_NS_GLOBAL(SystemTimeToFileTime)(&st, ft);
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

/** Elicits the current time as UTC time, into a SYSTEMTIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != st)
 */
inline
void
get_UTC_time_as_SYSTEMTIME(
    SYSTEMTIME* st
)
{
    winstl_C_get_UTC_time_as_SYSTEMTIME(st);
}

/** Elicits the current time as UTC time, into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != ft)
 */
inline
void
get_UTC_time_as_FILETIME(
    FILETIME* ft
)
{
    winstl_C_get_UTC_time_as_FILETIME(ft);
}

/** Elicits the current time as local time, into a SYSTEMTIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != st)
 */
inline
void
get_local_time_as_SYSTEMTIME(
    SYSTEMTIME* st
)
{
    winstl_C_get_local_time_as_SYSTEMTIME(st);
}

/** Elicits the current time as local time, into a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != ft)
 */
inline
void
get_local_time_as_FILETIME(
    FILETIME* ft
)
{
    winstl_C_get_local_time_as_FILETIME(ft);
}



/** Elicits the current time as UTC time, as a SYSTEMTIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != st)
 */
inline
SYSTEMTIME
get_UTC_time_as_SYSTEMTIME()
{
    SYSTEMTIME st;

    winstl_C_get_UTC_time_as_SYSTEMTIME(&st);

    return st;
}

/** Elicits the current time as UTC time, as a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != ft)
 */
inline
FILETIME
get_UTC_time_as_FILETIME()
{
    FILETIME ft;

    winstl_C_get_UTC_time_as_FILETIME(&ft);

    return ft;
}

/** Elicits the current time as local time, as a SYSTEMTIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != st)
 */
inline
SYSTEMTIME
get_local_time_as_SYSTEMTIME()
{
    SYSTEMTIME st;

    winstl_C_get_local_time_as_SYSTEMTIME(&st);

    return st;
}

/** Elicits the current time as local time, as a FILETIME
 *
 * \ingroup group__library__Time
 *
 * \pre (NULL != ft)
 */
inline
FILETIME
get_local_time_as_FILETIME()
{
    FILETIME ft;

    winstl_C_get_local_time_as_FILETIME(&ft);

    return ft;
}



inline
SYSTEMTIME
get_time(
    void (WINAPI *pfn)(SYSTEMTIME*)
)
{
    SYSTEMTIME st;

    STLSOFT_ASSERT(NULL != pfn);

    (*pfn)(&st);

    return st;
}

inline
FILETIME
get_time(
    void (WINAPI *pfn)(FILETIME*)
)
{
    FILETIME ft;

    STLSOFT_ASSERT(NULL != pfn);

    (*pfn)(&ft);

    return ft;
}

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

#endif /* !WINSTL_INCL_WINSTL_TIME_H_ELICITATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

