/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/sleep_functions.h
 *
 * Purpose:     UNIXSTL time functions.
 *
 * Created:     2nd September 2005
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/synch/sleep_functions.h
 *
 * \brief [C, C++] Various time functions
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS_MAJOR      3
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS_MINOR      0
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS_REVISION   7
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS_EDIT       33
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if 0
#elif defined(_WIN32) && \
      defined(_STLSOFT_FORCE_ANY_COMPILER)
# include <unixstl/synch/util/windows_api_.h>
#endif

#ifndef STLSOFT_INCL_SYS_H_SELECT
# ifndef _WIN32
#  define STLSOFT_INCL_SYS_H_SELECT
#  include <sys/select.h>
# endif /* !_WIN32 */
#endif /* !STLSOFT_INCL_SYS_H_SELECT */
#ifndef STLSOFT_INCL_SYS_H_TIME
# define STLSOFT_INCL_SYS_H_TIME
# include <sys/time.h>
#endif /* !STLSOFT_INCL_SYS_H_TIME */

#ifdef _WIN32
# ifndef WINSTL_INCL_WINSTL_API_external_h_ProcessAndThread
#  include <winstl/api/external/ProcessAndThread.h>
# endif /* !WINSTL_INCL_WINSTL_API_external_h_ProcessAndThread */
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(UNIXSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** [C, C++] Puts the calling thread to sleep for the given number of
 *   microseconds.
\code
  unixstl_C_micro_sleep(100000);  // Sleep for 0.1 seconds
  unixstl_C_micro_sleep(100);     // Sleep for 0.1 milliseconds
\endcode
 *
 * \param microseconds The number of microseconds to wait
 *
 * \return A boolean value indicating whether the operation was
 *   successful. If not, <code>errno</code> will contain an error code
 *   representing the reason for failure.
 *
 * \see unixstl::micro_sleep
 */
STLSOFT_INLINE
us_int_t
unixstl_C_micro_sleep(
    us_uint_t microseconds
) STLSOFT_NOEXCEPT
{
#ifdef _WIN32

    return (WINSTL_API_EXTERNAL_ProcessAndThread_Sleep(microseconds / 1000), us_true_v);
#else /* ? _WIN32 */

    struct timeval  ts;

    ts.tv_sec   =   stlsoft_static_cast(long, microseconds / 1000000);
    ts.tv_usec  =   stlsoft_static_cast(long, microseconds % 1000000);

    return -1 != STLSOFT_NS_GLOBAL(select)(0, NULL, NULL, NULL, &ts);
#endif /* _WIN32 */
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace unixstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** [C++] Puts the calling thread to sleep for the given number of
 *   microseconds.
\code
  unixstl::micro_sleep(100000); // Sleep for 0.1 seconds
  unixstl::micro_sleep(100);    // Sleep for 0.1 milliseconds
\endcode
 *
 * \param microseconds The number of microseconds to wait
 *
 * \return A boolean value indicating whether the operation was
 *   successful. If not, <code>errno</code> will contain an error code
 *   representing the reason for failure.
 */
inline
us_int_t
micro_sleep(
    us_uint_t microseconds
)
{
    return unixstl_C_micro_sleep(microseconds);
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

