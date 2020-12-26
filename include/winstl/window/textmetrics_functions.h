/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/textmetrics_functions.h (originally MWGdi.h, ::SynesisWin)
 *
 * Purpose:     TEXTMETRICS functions.
 *
 * Created:     20th October 1994
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1994-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/window/textmetrics_functions.h
 *
 * \brief [C, C++] TEXTMETRICS functions
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_TEXTMETRICS_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_TEXTMETRICS_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_TEXTMETRICS_FUNCTIONS_MAJOR    3
# define WINSTL_VER_WINSTL_WINDOW_H_TEXTMETRICS_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_H_TEXTMETRICS_FUNCTIONS_REVISION 4
# define WINSTL_VER_WINSTL_WINDOW_H_TEXTMETRICS_FUNCTIONS_EDIT     48
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
# ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_HDC_SCOPE
#  include <winstl/window/hdc_scope.hpp>
# endif /* !WINSTL_INCL_WINSTL_WINDOW_HPP_HDC_SCOPE */
#endif /* __cplusplus */

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
 * C functions
 */

STLSOFT_INLINE TEXTMETRICA winstl__get_textmetrics_a(HDC hdc)
{
    static TEXTMETRICA  s_tm;
    TEXTMETRICA         tm;

    return STLSOFT_NS_GLOBAL(GetTextMetricsA)(hdc, &tm) ? tm : s_tm;
}

STLSOFT_INLINE TEXTMETRICW winstl__get_textmetrics_w(HDC hdc)
{
    static TEXTMETRICW  s_tm;
    TEXTMETRICW         tm;

    return STLSOFT_NS_GLOBAL(GetTextMetricsW)(hdc, &tm) ? tm : s_tm;
}

STLSOFT_INLINE TEXTMETRIC winstl__get_textmetrics(HDC hdc)
{
# ifdef UNICODE
    return winstl__get_textmetrics_w(hdc);
# else /* ? UNICODE */
    return winstl__get_textmetrics_a(hdc);
# endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

inline TEXTMETRICA get_textmetrics_a(HDC hdc)
{
    return winstl__get_textmetrics_a(hdc);
}

inline TEXTMETRICW get_textmetrics_w(HDC hdc)
{
    return winstl__get_textmetrics_w(hdc);
}

inline TEXTMETRIC get_textmetrics(HDC hdc)
{
    return winstl__get_textmetrics(hdc);
}

inline TEXTMETRICA get_window_textmetrics_a(HWND hwnd)
{
    HDC_scope   hdc(::GetWindowDC(hwnd), hwnd);

    return winstl__get_textmetrics_a(hdc.get_hdc());
}

inline TEXTMETRICW get_window_textmetrics_w(HWND hwnd)
{
    HDC_scope   hdc(::GetWindowDC(hwnd), hwnd);

    return winstl__get_textmetrics_w(hdc.get_hdc());
}

inline TEXTMETRIC get_window_textmetrics(HWND hwnd)
{
# ifdef UNICODE
    return get_window_textmetrics_w(hwnd);
# else /* ? UNICODE */
    return get_window_textmetrics_a(hwnd);
# endif /* UNICODE */
}

inline TEXTMETRICA get_client_textmetrics_a(HWND hwnd)
{
    HDC_scope   hdc(::GetDC(hwnd), hwnd);

    return winstl__get_textmetrics_a(hdc.get_hdc());
}

inline TEXTMETRICW get_client_textmetrics_w(HWND hwnd)
{
    HDC_scope   hdc(::GetDC(hwnd), hwnd);

    return winstl__get_textmetrics_w(hdc.get_hdc());
}

inline TEXTMETRIC get_client_textmetrics(HWND hwnd)
{
# ifdef UNICODE
    return get_client_textmetrics_w(hwnd);
# else /* ? UNICODE */
    return get_client_textmetrics_a(hwnd);
# endif /* UNICODE */
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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_TEXTMETRICS_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

