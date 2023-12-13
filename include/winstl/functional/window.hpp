/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/functional/window.hpp
 *
 * Purpose:     Window function classes and predicates.
 *
 * Created:     19th January 2001
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2001-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/functional/window.hpp
 *
 * \brief [C++] Window function classes and predicates
 *   (\ref group__library__Functional "Functional" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FUNCTIONAL_HPP_WINDOW
#define WINSTL_INCL_WINSTL_FUNCTIONAL_HPP_WINDOW

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FUNCTIONAL_HPP_WINDOW_MAJOR      4
# define WINSTL_VER_WINSTL_FUNCTIONAL_HPP_WINDOW_MINOR      1
# define WINSTL_VER_WINSTL_FUNCTIONAL_HPP_WINDOW_REVISION   6
# define WINSTL_VER_WINSTL_FUNCTIONAL_HPP_WINDOW_EDIT       55
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

#ifndef WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND
# include <winstl/shims/attribute/get_HWND.hpp>
#endif /* !WINSTL_INCL_SHIMS_ATTRIBUTE_HPP_GET_HWND */
#ifndef _WINSTL_WINDOW_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _WINSTL_WINDOW_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _WINSTL_WINDOW_FUNCTIONALS_NO_STD */

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
 * predicate classes
 */

/** Predicate used to determine whether windows are visible
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:unary-predicate: is_visible]]
struct is_visible
    : public STLSOFT_NS_QUAL_STD(unary_function)<HWND, BOOL>
{
private:
    typedef STLSOFT_NS_QUAL_STD(unary_function)<HWND, BOOL> parent_class_type;
public:
    /// The argument type
    typedef parent_class_type::argument_type                argument_type;
    /// The result type
    typedef parent_class_type::result_type                  result_type;

// Operations
public:
    /// Function call operator which evaluates whether the given window is visible
    result_type operator ()(HWND hwnd) const
    {
        return ::IsWindowVisible(hwnd);
    }
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator which evaluates whether the given window is visible
    template <ss_typename_param_k W>
    result_type operator ()(W const& w) const
    {
        return ::IsWindowVisible(WINSTL_NS_QUAL(get_HWND)(w));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
};

/** Predicate used to determine whether windows are enabled
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:unary-predicate: is_enabled]]
struct is_enabled
    : public STLSOFT_NS_QUAL_STD(unary_function)<HWND, BOOL>
{
private:
    typedef STLSOFT_NS_QUAL_STD(unary_function)<HWND, BOOL> parent_class_type;
public:
    /// The argument type
    typedef parent_class_type::argument_type                argument_type;
    /// The result type
    typedef parent_class_type::result_type                  result_type;

// Operations
public:
    /// Function call operator which evaluates whether the given window is enabled
    result_type operator ()(HWND hwnd) const
    {
        return ::IsWindowEnabled(hwnd);
    }
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Function call operator which evaluates whether the given window is enabled
    template <ss_typename_param_k W>
    result_type operator ()(W const& w) const
    {
        return ::IsWindowEnabled(WINSTL_NS_QUAL(get_HWND)(w));
    }
#endif // STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
};

/* /////////////////////////////////////////////////////////////////////////
 * functor classes
 */

/** Functor used to show or hide windows
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:unary-functor: window_show]]
struct window_show
    : public std::unary_function<HWND, void>
{
public:
    /// This type
    typedef window_show     class_type;
public:
    ss_explicit_k window_show(ws_bool_t bShow = true)
        : m_bShow(bShow)
    {}
    window_show(window_show const& rhs)
        : m_bShow(rhs.m_bShow)
    {}
public:
    void operator ()(HWND hwnd) const
    {
        show_(hwnd, m_bShow);
    }
    template <ss_typename_param_k W>
    void operator ()(W &wnd) const
    {
        show_(WINSTL_NS_QUAL(get_HWND)(wnd), m_bShow);
    }
private:
    static void show_(HWND hwnd, ws_bool_t bShow)
    {
        ::ShowWindow(hwnd, bShow ? SW_SHOW : SW_HIDE);
    }
private:
    const ws_bool_t m_bShow;

private:
    class_type& operator =(class_type const&);
};

/** Functor used to enable or disable windows
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:unary-functor: window_enable]]
struct window_enable
    : public std::unary_function<HWND, void>
{
public:
    /// This type
    typedef window_enable   class_type;
public:
    ss_explicit_k window_enable(ws_bool_t bEnable = true)
        : m_bEnable(bEnable)
    {}
    window_enable(window_enable const& rhs)
        : m_bEnable(rhs.m_bEnable)
    {}
public:
    void operator ()(HWND hwnd) const
    {
        enable_(hwnd, m_bEnable);
    }
    template <ss_typename_param_k W>
    void operator ()(W &wnd) const
    {
        enable_(WINSTL_NS_QUAL(get_HWND)(wnd), m_bEnable);
    }
private:
    static void enable_(HWND hwnd, ws_bool_t bEnable)
    {
        ::EnableWindow(hwnd, bEnable);
    }
private:
    const ws_bool_t m_bEnable;

private:
    class_type& operator =(class_type const&);
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

#endif /* !WINSTL_INCL_WINSTL_FUNCTIONAL_HPP_WINDOW */

/* ///////////////////////////// end of file //////////////////////////// */

