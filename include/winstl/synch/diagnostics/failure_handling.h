/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/diagnostics/failure_handling.h
 *
 * Purpose:     WinSTL Synchronisation library diagnostics facilities.
 *
 * Created:     18th December 2016
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


/** \file winstl/synch/diagnostics/failure_handling.h
 *
 * \brief [C, C++] User-customisable diagnostics facilities for the
 *   \ref group__library__Synch "Synchronisation" Library.
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING
#define WINSTL_INCL_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING_MAJOR       1
# define WINSTL_VER_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING_MINOR       0
# define WINSTL_VER_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING_REVISION    3
# define WINSTL_VER_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING_EDIT        7
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef WINSTL_SYNCH_OPERATION_FAILED_IN_NOX

# if 0
# elif defined(PANTHEIOS_VER) && \
       !defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_NO_PANTHEIOS)

#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_pantheios_onBailOut
#  if 0
#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_pantheios_exitProcess
#  else
#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_exit
#  endif
# else

#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_abort
#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_fprintf
#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_output_debug_line
#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_string_slice
# endif
#endif

/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifdef WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_output_debug_line
# ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE
#  include <winstl/diagnostics/output_debug_line.h>
# endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE */
#endif /* WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_output_debug_line */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_H_ITOSLICE
# include <stlsoft/conversion/itoslice.h>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_H_ITOSLICE */

#ifdef WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_string_slice
# ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
#  include <stlsoft/string/string_slice.h>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */
#endif /* !WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_string_slice */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STRING_H_SNPRINTF
# include <stlsoft/util/snprintf.h>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STRING_H_SNPRINTF */

#if 0 || \
    defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_fprintf) || \
    1
# ifndef STLSOFT_INCL_H_STDIO
#  define STLSOFT_INCL_H_STDIO
#  include <stdio.h>
# endif /* !STLSOFT_INCL_H_STDIO */
#endif /* WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_fprintf */
#if 0 || \
    defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_abort) || \
    defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_pantheios_exitProcess) || \
    0
# ifndef STLSOFT_INCL_H_STDLIB
#  define STLSOFT_INCL_H_STDLIB
#  include <stdlib.h>
# endif /* !STLSOFT_INCL_H_STDLIB */
#endif /* ?? */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(syncSC, winSC)
 *
 * \ingroup group__library__Synch
 *
 * Macro invoked when a synchronisation operation fails in a NoX build
 *
 * \param syncSC [Synchronisation_status_code_t] The synchronisation
 *   library status code associated with the operation that failed
 * \param winSC [DWORD / LONG] The Windows thread status code (obtained
 *   from <code>::GetLastError()</code>
 */

#ifndef WINSTL_SYNCH_OPERATION_FAILED_IN_NOX

# if 0
# elif defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_pantheios_onBailOut)
#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_REPORT_(syncSC, winSC)           \
                                                                                \
    do                                                                          \
    {                                                                           \
        char    num_ssc[21];                                                    \
        char    num_wsc[21];                                                    \
        stlsoft_C_string_slice_a_t const    sl_ssc = STLSOFT_NS_QUAL(stlsoft_C_lutoslice21_a)(syncSC, &num_ssc);    \
        stlsoft_C_string_slice_a_t const    sl_wsc = STLSOFT_NS_QUAL(stlsoft_C_lutoslice21_a)(winSC, &num_wsc);     \
        char    qualifier[101];                                                 \
                                                                                \
        stlsoft_C_snprintf(                                                     \
            &qualifier[0], STLSOFT_NUM_ELEMENTS(qualifier)                      \
        ,   "Synchronisation status code: "                                     \
            "%.*s"                                                              \
            "; System status code: "                                            \
            "%.*s"                                                              \
        ,   STLSOFT_STATIC_CAST(int, sl_ssc.len), sl_ssc.ptr                    \
        ,   STLSOFT_STATIC_CAST(int, sl_wsc.len), sl_wsc.ptr                    \
        );                                                                      \
                                                                                \
        PANTHEIOS_NS_QUAL_(util, pantheios_onBailOut4)(                         \
            PANTHEIOS_SEV_ALERT                                                 \
        ,   "synchronisation operation failed"                                  \
        ,   NULL                                                                \
        ,   qualifier                                                           \
        );                                                                      \
    } while (STLSOFT_ALWAYS_FALSE())

# elif defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_output_debug_line)
#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_REPORT_(syncSC, winSC)           \
                                                                                \
    do                                                                          \
    {                                                                           \
        char    num_ssc[21];                                                    \
        char    num_wsc[21];                                                    \
        stlsoft_C_string_slice_a_t const    sl_ssc = STLSOFT_NS_QUAL(stlsoft_C_lutoslice21_a)(syncSC, &num_ssc);    \
        stlsoft_C_string_slice_a_t const    sl_wsc = STLSOFT_NS_QUAL(stlsoft_C_lutoslice21_a)(winSC, &num_wsc);     \
                                                                                \
        winstl_C_diagnostics_output_debug_line_4_m(                             \
            "synchronisation operation failed: Synchronisation status code: "   \
        ,   sl_ssc.ptr                                                          \
        ,   "; System status code: "                                            \
        ,   sl_wsc.ptr                                                          \
        );                                                                      \
    } while (STLSOFT_ALWAYS_FALSE())

# else

#  error No discrimination regarding reporting
# endif

# if 0
# elif defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_pantheios_exitProcess)

#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_RESPONSE_()          PANTHEIOS_NS_QUAL_(core, pantheios_exitProcess)(EXIT_FAILURE)
# elif defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_abort)

#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_RESPONSE_()          STLSOFT_NS_GLOBAL(abort)()
# elif defined(WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_USE_exit)

#  define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_RESPONSE_()          STLSOFT_NS_GLOBAL(exit)(EXIT_FAILURE)
# else

#  error No discrimination regarding response
# endif



# define WINSTL_SYNCH_OPERATION_FAILED_IN_NOX(syncSC, winSC)                \
                                                                            \
    do                                                                      \
    {                                                                       \
        WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_REPORT_((syncSC), (winSC));    \
                                                                            \
        WINSTL_SYNCH_OPERATION_FAILED_IN_NOX_RESPONSE_();                   \
    } while (STLSOFT_ALWAYS_FALSE())

#endif /* !WINSTL_SYNCH_OPERATION_FAILED_IN_NOX */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
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
 * .
 */



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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING */

/* ///////////////////////////// end of file //////////////////////////// */

