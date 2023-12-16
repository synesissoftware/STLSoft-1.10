/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/system/console_functions.h
 *
 * Purpose:     Windows console functions.
 *
 * Created:     6th August 2015
 * Updated:     23rd January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2015-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/system/console_functions.h
 *
 * \brief [C, C++] Windows console functions.
 *   (\ref group__library__System "System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_H_CONSOLE_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_SYSTEM_H_CONSOLE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MAJOR       1
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MINOR       0
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_CONSOLE_FUNCTIONS_REVISION    9
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_CONSOLE_FUNCTIONS_EDIT        13
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

#ifndef STLSOFT_INCL_H_UNISTD
# define STLSOFT_INCL_H_UNISTD
# include <unistd.h>                    /* for istty() */
#endif /* !STLSOFT_INCL_H_UNISTD */

#if !defined(_WIN32)
# ifndef STLSOFT_INCL_SYS_H_IOCTL
#  define STLSOFT_INCL_SYS_H_IOCTL
#  include <sys/ioctl.h>                /* for ioctl() */
# endif /* !STLSOFT_INCL_SYS_H_IOCTL */
#endif

#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>                     /* for fileno(), stdout */
#endif /* !STLSOFT_INCL_H_STDIO */

#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>                    /* for atoi(), getenv() */
#endif /* !STLSOFT_INCL_H_STDLIB */

#if defined(_MSC_VER) && \
    defined(_STLSOFT_FORCE_ANY_COMPILER)
# include <io.h>
#endif

#if 0
#elif defined(_WIN32) && \
      defined(_STLSOFT_FORCE_ANY_COMPILER)
# ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
#  include <winstl/api/winstl_win32_winnt_.h>
# endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */
# ifndef WINSTL_INCL_WINSTL_API_external_h_Console
#  include <winstl/api/external/Console.h>
# endif /* !WINSTL_INCL_WINSTL_API_external_h_Console */
# include <windows.h>
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

/** Evalutes the current width of the console.
 *
 * \ingroup group__library__System
 */
STLSOFT_INLINE
us_size_t
unixstl_C_get_console_width(void)
{
    /* Algorithm:
     *
     * 1. Try the environment variable COLUMNS, if we're a tty
     * 2. get TIOCGWINSZ from ioctl
     *
     */

    int (*pfn_fileno)(FILE*);
    int (*pfn_isatty)(int);
    char* (*pfn_getenv)(char const*);

#if defined(_MSC_VER) && \
    defined(_STLSOFT_FORCE_ANY_COMPILER)

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>

    pfn_fileno  =   STLSOFT_NS_GLOBAL(_fileno);
    pfn_isatty  =   STLSOFT_NS_GLOBAL(_isatty);
    pfn_getenv  =   STLSOFT_NS_GLOBAL(getenv);

# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
#else

    pfn_fileno  =   STLSOFT_NS_GLOBAL(fileno);
    pfn_isatty  =   STLSOFT_NS_GLOBAL(isatty);
    pfn_getenv  =   STLSOFT_NS_GLOBAL(getenv);
#endif

    int const fn_stdout = (*pfn_fileno)(stdout);



    /* 1. Try the environment variable COLUMNS, if we're a tty */

    if ((*pfn_isatty)(fn_stdout))
    {
        char const* const columns = (*pfn_getenv)("COLUMNS");

        if (NULL != columns)
        {
            char *      ep  =   NULL;
            long const  n   =   STLSOFT_NS_GLOBAL(strtol)(columns, &ep, 10);

            if (NULL != ep &&
                '\0' == *ep)
            {
                return STLSOFT_STATIC_CAST(us_size_t, n);
            }
        }
    }


#if 0
#elif defined(_WIN32) && \
      defined(_STLSOFT_FORCE_ANY_COMPILER)

    /* 2. get x from Windows' screen buffer */
    {
        HANDLE hStdOut = WINSTL_API_EXTERNAL_Console_GetStdHandle(STD_OUTPUT_HANDLE);

        if (INVALID_HANDLE_VALUE != hStdOut)
        {
            CONSOLE_SCREEN_BUFFER_INFO csbi;

            if (WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfo(hStdOut, &csbi))
            {
                return csbi.dwMaximumWindowSize.X;
            }
        }
    }
#else

    /* 2. get TIOCGWINSZ from ioctl */
    {
        struct winsize ws;

        if (-1 != STLSOFT_NS_GLOBAL(ioctl)(STDOUT_FILENO, TIOCGWINSZ, &ws))
        {
            return STLSOFT_STATIC_CAST(us_size_t, ws.ws_col);
        }
    }
#endif



    return ~stlsoft_static_cast(us_size_t, 0);
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

#if defined(__cplusplus)

/** Evalutes the current width of the console.
 *
 * \ingroup group__library__System
 */
inline
us_size_t
get_console_width()
{
    return unixstl_C_get_console_width();
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_H_CONSOLE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

