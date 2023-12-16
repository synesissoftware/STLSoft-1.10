/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/attribute/get_HWND.hpp
 *
 * Purpose:     Contains access shims for windows.
 *
 * Created:     7th October 2002
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/shims/attribute/get_HWND.hpp
 *
 * \brief [C++] Definition of stlsoft::get_HWND attribute shim
 *   functions for Win32 types
 *   (\ref group__library__Shims_Attribute_Windows_Window "Window Attribute Shims").
 */

#ifndef WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND
#define WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_SHIMS_ATTRIBUTE_HPP_GET_HWND_MAJOR     4
# define WINSTL_VER_SHIMS_ATTRIBUTE_HPP_GET_HWND_MINOR     1
# define WINSTL_VER_SHIMS_ATTRIBUTE_HPP_GET_HWND_REVISION  5
# define WINSTL_VER_SHIMS_ATTRIBUTE_HPP_GET_HWND_EDIT      58
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
 * get_HWND
 *
 * This can be applied to an expression, and the return value is the
 * corresponding HWND.
 */

/* HWND */

/** Access the HWND of the given HWND
 *
 * \ingroup group__library__Shims_Attribute_Windows_Window
 *
 * This access <a href = "http://stlsoft.org/white_papers.html#shims">shim</a>
 * retrieves the HWND window handle for the given HWND handle.
 *
 * \param h A HWND whose corresponding HWND will be retrieved
 * \return The HWND corresponding to the given HWND \c h
 */
inline HWND get_HWND(HWND h)
{
    return h;
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline HWND get_hwnd(HWND h)
{
    return get_HWND(h);
}

template <typename W>
inline HWND get_hwnd(W const& h)
{
    return get_HWND(h);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND */

/* ///////////////////////////// end of file //////////////////////////// */

