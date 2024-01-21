/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/util/ident_.hpp
 *
 * Purpose:     Windows identification.
 *
 * Created:     11th March 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/window/util/ident_.hpp
 *
 * \brief [C++] Windows identification
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_UTIL_HPP_IDENT_
#define WINSTL_INCL_WINSTL_WINDOW_UTIL_HPP_IDENT_

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_UTIL_HPP_IDENT__MAJOR      4
# define WINSTL_VER_WINSTL_WINDOW_UTIL_HPP_IDENT__MINOR      1
# define WINSTL_VER_WINSTL_WINDOW_UTIL_HPP_IDENT__REVISION   3
# define WINSTL_VER_WINSTL_WINDOW_UTIL_HPP_IDENT__EDIT       59
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

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

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
 * namespace
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_winstl_window_ident
{

/* /////////////////////////////////////////////////////////////////////////
 * enumerations
 */

enum WindowIdent
{
        WindowIdent_Unknown
    ,   WindowIdent_Generic
    ,   WindowIdent_ListBox     =   11
    ,   WindowIdent_ComboBox    =   12
    ,   WindowIdent_ListView    =   13
};

/* /////////////////////////////////////////////////////////////////////////
 * enumerations
 */

inline
WindowIdent
GetWindowIdent(
    HWND hwnd
)
{
    struct Ident
    {
        WindowIdent ident;
        char const* name;
    };

    WindowIdent         ident       =   WindowIdent_Generic;
    char                buffer[256];
    static Ident const  s_idents[]  =
    {
        {   WindowIdent_ListBox,    "LISTBOX"       },
        {   WindowIdent_ComboBox,   "COMBOBOX"      },
        {   WindowIdent_ListView,   "SysListView32" },

        {   WindowIdent_Unknown,    NULL            }
    };

    ws_size_t const     cch = static_cast<ws_size_t>(::GetClassNameA(hwnd, &buffer[0], STLSOFT_NUM_ELEMENTS(buffer)));

    if (cch < STLSOFT_NUM_ELEMENTS(buffer))
    {
        for (ws_size_t index = 0; WindowIdent_Unknown != s_idents[index].ident; ++index)
        {
            WINSTL_ASSERT(::lstrlenA(s_idents[index].name) < int(STLSOFT_NUM_ELEMENTS(buffer)));

            if (0 == STLSOFT_API_EXTERNAL_string_stricmp(s_idents[index].name, &buffer[0]))
            {
                ident = s_idents[index].ident;
                break;
            }
        }
    }

    return ident;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace ximpl_winstl_window_ident */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_UTIL_HPP_IDENT_ */

/* ///////////////////////////// end of file //////////////////////////// */

