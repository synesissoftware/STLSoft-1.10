/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/setcursor_scope.hpp
 *
 * Purpose:     Cursor scoping class.
 *
 * Created:     12th May 2003
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/window/setcursor_scope.hpp
 *
 * \brief [C++] Definition of the winstl::setcursor_scope class
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_SETCURSOR_SCOPE
#define WINSTL_INCL_WINSTL_WINDOW_HPP_SETCURSOR_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_HPP_SETCURSOR_SCOPE_MAJOR      4
# define WINSTL_VER_WINSTL_WINDOW_HPP_SETCURSOR_SCOPE_MINOR      0
# define WINSTL_VER_WINSTL_WINDOW_HPP_SETCURSOR_SCOPE_REVISION   6
# define WINSTL_VER_WINSTL_WINDOW_HPP_SETCURSOR_SCOPE_EDIT       58
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING
# include <winstl/shims/access/string.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING */

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
 * classes
 */

// setcursor_scope
/** Provides scoping of a window's cursor.
 *
 * \ingroup group__library__Windows_Window
 *
 * This class provides scoping of the cursor of a window via the API
 * function SetCursor().
 */
class setcursor_scope
{
public:
    /// This type
    typedef setcursor_scope class_type;

// Construction
public:
    /// Toggles the current cursor
    ///
    /// Sets the given cursor.
    ss_explicit_k setcursor_scope(HCURSOR hcur)
        : m_hcurLast(::SetCursor(hcur))
    {}
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Toggles the current cursor
    ///
    /// Sets the given cursor resource from the given instance.
    template <ss_typename_param_k S>
    setcursor_scope(HINSTANCE hinst, S const& name)
        : m_hcurLast(::SetCursor(load_(hinst, STLSOFT_NS_QUAL(c_str_ptr)(name))))
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    /// Toggles the current cursor
    ///
    /// Sets the given cursor resource from the given instance.
    setcursor_scope(HINSTANCE hinst, ws_char_a_t const* name)
        : m_hcurLast(::SetCursor(load_(hinst, name)))
    {}
    /// Toggles the current cursor
    ///
    /// Sets the given cursor resource from the given instance.
    setcursor_scope(HINSTANCE hinst, ws_char_w_t const* name)
        : m_hcurLast(::SetCursor(load_(hinst, name)))
    {}
    /// Toggles the current cursor
    ///
    /// Sets the given cursor resource from the given instance.
    setcursor_scope(HINSTANCE hinst, int id)
        : m_hcurLast(::SetCursor(::LoadCursor(hinst, MAKEINTRESOURCE(id))))
    {}
    /// Resets the original cursor
    ~setcursor_scope() STLSOFT_NOEXCEPT
    {
        ::SetCursor(m_hcurLast);
    }

/// \name Implementation
/// @{
private:
    static HCURSOR load_(HINSTANCE hinst, ws_char_a_t const* name)
    {
        return ::LoadCursorA(hinst, name);
    }
    static HCURSOR load_(HINSTANCE hinst, ws_char_w_t const* name)
    {
        return ::LoadCursorW(hinst, name);
    }
/// @}

/// \name Members
/// @{
private:
    HCURSOR m_hcurLast;
/// @}

/// \name Not to be implemented
/// @{
private:
    setcursor_scope(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_HPP_SETCURSOR_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

