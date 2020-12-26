/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/creation_functions.h (originally MWBase.h, ::SynesisWin)
 *
 * Purpose:     Window creation functions.
 *
 * Created:     7th May 2000
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2000-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/window/creation_functions.h
 *
 * \brief [C, C++] Control creation functions
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_CREATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_CREATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_CREATION_FUNCTIONS_MAJOR    2
# define WINSTL_VER_WINSTL_WINDOW_H_CREATION_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_H_CREATION_FUNCTIONS_REVISION 6
# define WINSTL_VER_WINSTL_WINDOW_H_CREATION_FUNCTIONS_EDIT     28
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

#ifdef __cplusplus
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
#  include <stlsoft/shims/access/string/fwd.h>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#endif /* __cplusplus */

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

STLSOFT_INLINE HWND winstl__CreateWindowA(  LPCSTR      lpClassName
                                        ,   LPCSTR      lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowA)(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowW(  LPCWSTR     lpClassName
                                        ,   LPCWSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowW)(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindow(   LPCTSTR     lpClassName
                                        ,   LPCTSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindow)(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowExA(DWORD       dwExStyle
                                        ,   LPCSTR      lpClassName
                                        ,   LPCSTR      lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowExA)(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowExW(DWORD       dwExStyle
                                        ,   LPCWSTR     lpClassName
                                        ,   LPCWSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowExW)(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

STLSOFT_INLINE HWND winstl__CreateWindowEx( DWORD       dwExStyle
                                        ,   LPCTSTR     lpClassName
                                        ,   LPCTSTR     lpWindowName
                                        ,   DWORD       dwStyle
                                        ,   int         X
                                        ,   int         Y
                                        ,   int         nWidth
                                        ,   int         nHeight
                                        ,   HWND        hWndParent
                                        ,   HMENU       hMenu
                                        ,   HINSTANCE   hInstance
                                        ,   LPVOID      lpParam)
{
    return STLSOFT_NS_GLOBAL(CreateWindowEx)(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
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
# ifndef WINSTL_NO_NAMESPACE
/*
inline HWND CreateWindowA(  LPCSTR      lpClassName
                        ,   LPCSTR      lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

inline HWND CreateWindowW(  LPCWSTR     lpClassName
                        ,   LPCWSTR     lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

inline HWND CreateWindow(   LPCTSTR     lpClassName
                        ,   LPCTSTR     lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindow(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}
 */
inline HWND CreateWindowExA(DWORD       dwExStyle
                        ,   LPCSTR      lpClassName
                        ,   LPCSTR      lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

inline HWND CreateWindowExW(DWORD       dwExStyle
                        ,   LPCWSTR     lpClassName
                        ,   LPCWSTR     lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

/*
inline HWND CreateWindowEx( DWORD       dwExStyle
                        ,   LPCTSTR     lpClassName
                        ,   LPCTSTR     lpWindowName
                        ,   DWORD       dwStyle
                        ,   int         X
                        ,   int         Y
                        ,   int         nWidth
                        ,   int         nHeight
                        ,   HWND        hWndParent
                        ,   HMENU       hMenu
                        ,   HINSTANCE   hInstance
                        ,   LPVOID      lpParam)
{
    return winstl__CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}
 */

# endif /* !WINSTL_NO_NAMESPACE */
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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_CREATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

