/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/console_functions.h
 *
 * Purpose:     Windows console functions.
 *
 * Created:     3rd December 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/system/console_functions.h
 *
 * \brief [C, C++] Windows console functions.
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MAJOR     2
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MINOR     4
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_REVISION  8
# define WINSTL_VER_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS_EDIT      44
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_Console
# include <winstl/api/external/Console.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Console */
#ifndef WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary
# include <winstl/api/external/DynamicLinkLibrary.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary */
#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_FileManagement
# include <winstl/api/external/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_FileManagement */
#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
# include <winstl/api/external/HandleAndObject.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */

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
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
long
winstl_C_console_read_silent_character_from_(
    HANDLE h
)
{
    DWORD   currMode;

    if (!WINSTL_API_EXTERNAL_Console_GetConsoleMode(h, &currMode) ||
        !WINSTL_API_EXTERNAL_Console_SetConsoleMode(h, 0))
    {
        return -1;
    }
    else
    {
        LONG c = -1;

        for (;;)
        {
            INPUT_RECORD    ir;
            DWORD           numRead;

            if (!WINSTL_API_EXTERNAL_Console_ReadConsoleInput(h, &ir, 1, &numRead))
            {
                c = -1;
                break;
            }
            else
            {
                if (0 == numRead)
                {
                    c = -1;
                    break;
                }
                else
                {
                    if (KEY_EVENT == ir.EventType)
                    {
                        if (ir.Event.KeyEvent.bKeyDown)
                        {
#ifdef UNICODE
                            if (0 != ir.Event.KeyEvent.uChar.UnicodeChar)
                            {
                                c = (long)ir.Event.KeyEvent.uChar.UnicodeChar;
                                break;
                            }
#else /* ? UNICODE */
                            if (0 != ir.Event.KeyEvent.uChar.AsciiChar)
                            {
                                c = (long)ir.Event.KeyEvent.uChar.AsciiChar;
                                break;
                            }
#endif /* UNICODE */
                        }
                    }
                }
            }
        }

        WINSTL_API_EXTERNAL_Console_SetConsoleMode(h, currMode);

        return c;
    }
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Evalutes the current width of the console.
 *
 * \ingroup group__library__System
 */
STLSOFT_INLINE
ws_size_t
winstl_C_get_console_width(void)
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

#ifdef STLSOFT_DEBUG
    WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();
#endif /* STLSOFT_DEBUG */

    return ~stlsoft_static_cast(ws_size_t, 0);
}

#if !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION) && \
    (   !defined(_WIN32_WINNT) || \
        _WIN32_WINNT < 0x0500 || \
        (   defined(STLSOFT_COMPILER_IS_BORLAND) && \
            !defined(CONSOLE_NO_SELECTION)))

STLSOFT_INLINE
HWND
GetConsoleWindow()
{
    typedef HWND (WINAPI *GCW_t)();

    HMODULE Kernel32    =   WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryA("KERNEL32");
    GCW_t   pfn         =   stlsoft_reinterpret_cast(GCW_t, WINSTL_API_EXTERNAL_DynamicLinkLibrary_GetProcAddress(Kernel32, "GetConsoleWindow"));

    if (NULL == pfn)
    {
        return NULL;
    }
    else
    {
        HWND hwnd = (*pfn)();

        WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(Kernel32);

        return hwnd;
    }
}

#endif /* _WIN32_WINNT */

/** Returns the window handle of the current console, or NULL if it cannot
 *    be found
 *
 * \ingroup group__library__System
 *
 * \warning This only works on Windows 2000, or later, operating systems. It
 *    will return NULL on other operating systems.
 */
STLSOFT_INLINE
HWND
winstl_C_get_console_window(void)
{
    return GetConsoleWindow();
}

STLSOFT_INLINE
long
winstl_C_console_read_silent_character_from_stdin(void)
{
    HANDLE h = WINSTL_API_EXTERNAL_Console_GetStdHandle(STD_INPUT_HANDLE);

    return winstl_C_console_read_silent_character_from_(h);
}

STLSOFT_INLINE
long
winstl_C_console_read_silent_character_from_CONIO(void)
{
    HANDLE hConin = WINSTL_API_EXTERNAL_FileManagement_CreateFileA(
                        "CONIN$"
                    ,   GENERIC_READ | GENERIC_WRITE
                    ,   FILE_SHARE_READ | FILE_SHARE_WRITE
                    ,   NULL
                    ,   OPEN_EXISTING
                    ,   0
                    ,   NULL
                    );

    if (INVALID_HANDLE_VALUE == hConin)
    {
        return -1;
    }
    else
    {
        long const  l   =   winstl_C_console_read_silent_character_from_(hConin);
        DWORD const e   =   WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(hConin);

        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(e);

        return l;
    }
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

/** \def winstl__get_console_window
 *
 * \deprecated Use winstl_C_get_console_window
 */
# define winstl__get_console_window                         winstl_C_get_console_window
/** \def winstl__get_console_width
 *
 * \deprecated Use winstl_C_get_console_width
 */
# define winstl__get_console_width                          winstl_C_get_console_width

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

#if defined(__cplusplus)

/** Evalutes the current width of the console.
 *
 * \ingroup group__library__System
 */
inline
ws_size_t
get_console_width()
{
    return winstl_C_get_console_width();
}

/** Returns the window handle of the current console, or NULL if it cannot
 *    be found
 *
 * \ingroup group__library__System
 *
 * \warning This only works on Windows 2000, or later, operating systems. It
 *    will return NULL on other operating systems.
 */
inline
HWND
get_console_window()
{
    return winstl_C_get_console_window();
}

inline
long
console_read_silent_character_from_stdin()
{
    return winstl_C_console_read_silent_character_from_stdin();
}

inline
long
console_read_silent_character_from_CONIO()
{
    return winstl_C_console_read_silent_character_from_CONIO();
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_CONSOLE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

