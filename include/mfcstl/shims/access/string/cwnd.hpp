/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/shims/access/string/CWnd.hpp
 *
 * Purpose:     String access shims for CWnd
 *
 * Created:     24th May 2002
 * Updated:     28th November 2020
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


/** \file mfcstl/shims/access/string/CWnd.hpp
 *
 * \brief [C++] String access shims for <code>CWnd</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef MFCSTL_INCL_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND
#define MFCSTL_INCL_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND_MAJOR       4
# define MFCSTL_VER_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND_MINOR       0
# define MFCSTL_VER_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND_REVISION    14
# define MFCSTL_VER_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND_EDIT        107
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS
# include <stlsoft/util/constraints.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER
# include <stlsoft/string/cstring_maker.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR
# include <stlsoft/util/std/library_discriminator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8022 /* Suppresses "'f()' hides virtual function 'g()'" */
# pragma warn -8084 /* Suppresses "Suggest parentheses to clarify precedence in function 'f()'" */
#endif /* compiler */

#ifndef STLSOFT_INCL_H_AFXWIN
# define STLSOFT_INCL_H_AFXWIN
# include <afxwin.h>     // for CWnd, CListBox
#endif /* !STLSOFT_INCL_H_AFXWIN */
#if !defined(__AFXCMN_H__) && \
    !defined(MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCMN)
# ifndef STLSOFT_INCL_H_AFXCMN
#  define STLSOFT_INCL_H_AFXCMN
#  include <afxcmn.h>    // for CListCtrl
# endif /* !STLSOFT_INCL_H_AFXCMN */
#endif /* !__AFXCMN_H__ && !MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCMN */
#if !defined(__AFXCVIEW_H__) && \
    !defined(MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCVIEW)
# ifndef STLSOFT_INCL_H_AFXCVIEW
#  define STLSOFT_INCL_H_AFXCVIEW
#  include <afxcview.h> // for CListView
# endif /* !STLSOFT_INCL_H_AFXCVIEW */
#endif /* !__AFXCVIEW_H__ && !MFCSTL_STRING_ACCESS_NO_INCLUDE_AFXCMN */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn .8022 /* Suppresses "'f()' hides virtual function 'g()'" */
# pragma warn .8084 /* Suppresses "Suggest parentheses to clarify precedence in function 'f()'" */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */
namespace stlsoft
{
namespace mfcstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_OPEN_WORKER_NS_(ximpl_mfcstl_CWnd_)

inline ms_size_t GetWindowTextLength_T_(CWnd const& w)
{
    return (NULL != w.m_hWnd) ? static_cast<ms_size_t>(w.GetWindowTextLength()) : 0;
}

inline ms_size_t GetWindowText_T_(CWnd const& w, LPTSTR buffer, ms_size_t cchBuffer)
{
    MFCSTL_ASSERT(NULL != w.m_hWnd);

    return static_cast<ms_size_t>(w.GetWindowText(buffer, static_cast<int>(cchBuffer)));
}

inline ms_size_t GetWindowTextLength_T_(CListBox const& w)
{
    int sel;

    if (0 == (w.GetStyle() & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)) &&
        LB_ERR != (sel = w.GetCurSel()))
    {
        return static_cast<ms_size_t>(w.GetTextLen(sel));
    }
    else
    {
        return static_cast<ms_size_t>(w.GetWindowTextLength());
    }
}

inline ms_size_t GetWindowText_T_(CListBox const& w, LPTSTR buffer, ms_size_t cchBuffer)
{
    int sel = -1;

    if (0 == (w.GetStyle() & (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)) &&
        LB_ERR != (sel = w.GetCurSel()))
    {
        ms_size_t cch = static_cast<ms_size_t>(w.GetText(sel, buffer));

        MFCSTL_MESSAGE_ASSERT("Invalid item", LB_ERR != cch);
        MFCSTL_MESSAGE_ASSERT("Buffer overwrite", !(cchBuffer < cch));

        return static_cast<ms_size_t>(cch);
    }
    else
    {
        return w.GetWindowText(buffer, static_cast<int>(cchBuffer));
    }
}

#ifdef __AFXCMN_H__
# if _MFC_VER >= 0x0600
inline ms_size_t GetWindowTextLength_T_(CListCtrl const& w)
{
    if (1 == w.GetSelectedCount())
    {
        POSITION    pos =   w.GetFirstSelectedItemPosition();
        int         sel =   w.GetNextSelectedItem(pos);

        return static_cast<ms_size_t>(w.GetItemText(sel, 0).GetLength());
    }
    else
    {
        return static_cast<ms_size_t>(w.GetWindowTextLength());
    }
}

inline ms_size_t GetWindowText_T_(CListCtrl const& w, LPTSTR buffer, ms_size_t cchBuffer)
{
    if (1 == w.GetSelectedCount())
    {
        POSITION    pos =   w.GetFirstSelectedItemPosition();
        int         sel =   w.GetNextSelectedItem(pos);

        return static_cast<ms_size_t>(w.GetItemText(sel, 0, buffer, static_cast<int>(cchBuffer)));
    }
    else
    {
        return w.GetWindowText(buffer, static_cast<int>(cchBuffer));
    }
}

#  ifdef __AFXCVIEW_H__
inline ms_size_t GetWindowTextLength_T_(CListView const& w)
{
    return GetWindowTextLength_T_(w.GetListCtrl());
}

inline ms_size_t GetWindowText_T_(CListView const& w, LPTSTR buffer, ms_size_t cchBuffer)
{
    return GetWindowText_T_(w.GetListCtrl(), buffer, cchBuffer);
}
#  endif /* __AFXCVIEW_H__ */
# endif /* _MFC_VER >= 0x0600 */
#endif /* __AFXCMN_H__ */

STLSOFT_CLOSE_WORKER_NS_(ximpl_mfcstl_CWnd_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/* CWnd */

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_null() function, such that the window text of a given window
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_ptr_null_CWnd_proxy
{
private: // types
    typedef TCHAR                                           char_type;
    typedef cstring_maker<char_type>                        cstring_maker_type_;
    typedef cstring_maker_type_::block                      block_type_;
public:
    typedef c_str_ptr_null_CWnd_proxy                       class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWnd instance
    ///
    /// \param w The CWnd instance from which the text will be retrieved
    template<ss_typename_param_k W>
    ss_explicit_k
    c_str_ptr_null_CWnd_proxy(W const& w)
        : m_block(make_block_(w))
    {
        stlsoft_constraint_must_have_base(W, CWnd);
    }

    // Copy constructor
    c_str_ptr_null_CWnd_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_null_CWnd_proxy() STLSOFT_NOEXCEPT
    {
        cstring_maker_type_::free(m_block);
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// NULL if the window contains no text.
    operator LPCTSTR () const
    {
        if (NULL == m_block)
        {
            return NULL;
        }

        return &m_block->data[0];
    }

private: // implementation
    template<ss_typename_param_k W>
    static
    block_type_*
    make_block_(W const& w)
    {
        stlsoft_constraint_must_have_base(W, CWnd);

        ms_size_t length = ximpl_mfcstl_CWnd_::GetWindowTextLength_T_(w);

        if (length == 0)
        {
            return NULL;
        }
        else
        {
            block_type_* const block = cstring_maker_type_::alloc(NULL, length);

            if (NULL != block)
            {
                ximpl_mfcstl_CWnd_::GetWindowText_T_(w, &block->data[0], length + 1);
            }

            return block;
        }
    }

private: // fields
    block_type_* const  m_block;
};

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr() function, such that the window text of a given window may be
 * accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_ptr_CWnd_proxy
{
private: // types
    typedef TCHAR                                           char_type;
    typedef cstring_maker<char_type>                        cstring_maker_type_;
    typedef cstring_maker_type_::block                      block_type_;
public:
    typedef c_str_ptr_CWnd_proxy                            class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWnd instance
    ///
    /// \param w The CWnd instance from which the text will be retrieved
    template<ss_typename_param_k W>
    ss_explicit_k
    c_str_ptr_CWnd_proxy(W const& w)
        : m_block(make_block_(w))
    {
        stlsoft_constraint_must_have_base(W, CWnd);
    }

    // Copy constructor
    c_str_ptr_CWnd_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_CWnd_proxy() STLSOFT_NOEXCEPT
    {
        cstring_maker_type_::free(m_block);
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// the empty string "" if the window contains no text.
    operator LPCTSTR () const
    {
        return &m_block->data[0];
    }

private: // implementation
    template<ss_typename_param_k W>
    static
    block_type_*
    make_block_(W const& w)
    {
        stlsoft_constraint_must_have_base(W, CWnd);

        ms_size_t length = ximpl_mfcstl_CWnd_::GetWindowTextLength_T_(w);

        block_type_* const block = cstring_maker_type_::alloc(NULL, length);

        if (NULL != block &&
            length != 0)
        {
            ximpl_mfcstl_CWnd_::GetWindowText_T_(w, &block->data[0], length + 1);
        }

        return block;
    }

private: // fields
    block_type_* const  m_block;
};

/* /////////////////////////////////////////////////////////////////////////
 * equivalence testing
 */

inline ms_bool_t operator ==(LPCTSTR lhs, c_str_ptr_null_CWnd_proxy const& rhs)
{
    return lhs == static_cast<LPCTSTR>(rhs);
}

inline ms_bool_t operator ==(c_str_ptr_null_CWnd_proxy const& lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) == rhs;
}

inline ms_bool_t operator !=(LPCTSTR lhs, c_str_ptr_null_CWnd_proxy const& rhs)
{
    return lhs != static_cast<LPCTSTR>(rhs);
}

inline ms_bool_t operator !=(c_str_ptr_null_CWnd_proxy const& lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) != rhs;
}

/* /////////////////////////////////////////////////////////////////////////
 * iostream compatibility
 */

template<ss_typename_param_k S>
inline S& operator <<(S& s, c_str_ptr_null_CWnd_proxy const& shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}

template <ss_typename_param_k S>
inline S& operator <<(S& s, c_str_ptr_CWnd_proxy const& shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* CWnd */
/** \ref group__concept__Shim__string_access__c_str_ptr_null for CWnd
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(CWnd const& w)
{
    return c_str_ptr_null_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(CWnd const& w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(CWnd const& w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}

/** \ref group__concept__Shim__string_access__c_str_ptr_null for CListBox
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(CListBox const& w)
{
    return c_str_ptr_null_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(CListBox const& w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(CListBox const& w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}

#ifdef __AFXCMN_H__
/** \ref group__concept__Shim__string_access__c_str_ptr_null for CListCtrl
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(CListCtrl const& w)
{
    return c_str_ptr_null_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(CListCtrl const& w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(CListCtrl const& w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}

# ifdef __AFXCVIEW_H__
/** \ref group__concept__Shim__string_access__c_str_ptr_null for CListView
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null(CListView const& w)
{
    return c_str_ptr_null(w.GetListCtrl());
}
#if defined(UNICODE)
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_w(CListView const& w)
#else /* ? UNICODE */
inline c_str_ptr_null_CWnd_proxy c_str_ptr_null_a(CListView const& w)
#endif /* UNICODE */
{
    return c_str_ptr_null(w);
}
# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWnd */
/** \ref group__concept__Shim__string_access__c_str_ptr for CWnd
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_ptr(CWnd const& w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(CWnd const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(CWnd const& w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}

/** \ref group__concept__Shim__string_access__c_str_ptr for CListBox
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_ptr(CListBox const& w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(CListBox const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(CListBox const& w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}

#ifdef __AFXCMN_H__
/** \ref group__concept__Shim__string_access__c_str_ptr for CListCtrl
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_ptr(CListCtrl const& w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(CListCtrl const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(CListCtrl const& w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}

# ifdef __AFXCVIEW_H__
/** \ref group__concept__Shim__string_access__c_str_ptr for CListView
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_ptr(CListView const& w)
{
    return c_str_ptr(w.GetListCtrl());
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_ptr_w(CListView const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_ptr_a(CListView const& w)
#endif /* UNICODE */
{
    return c_str_ptr(w);
}
# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWnd */
/** \ref group__concept__Shim__string_access__c_str_data for CWnd
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_data(CWnd const& w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(CWnd const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(CWnd const& w)
#endif /* UNICODE */
{
    return c_str_data(w);
}

/** \ref group__concept__Shim__string_access__c_str_data for CListBox
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_data(CListBox const& w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(CListBox const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(CListBox const& w)
#endif /* UNICODE */
{
    return c_str_data(w);
}

#ifdef __AFXCMN_H__
/** \ref group__concept__Shim__string_access__c_str_data for CListCtrl
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_data(CListCtrl const& w)
{
    return c_str_ptr_CWnd_proxy(w);
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(CListCtrl const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(CListCtrl const& w)
#endif /* UNICODE */
{
    return c_str_data(w);
}

# ifdef __AFXCVIEW_H__
/** \ref group__concept__Shim__string_access__c_str_data for CListView
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWnd_proxy c_str_data(CListView const& w)
{
    return c_str_data(w.GetListCtrl());
}
#if defined(UNICODE)
inline c_str_ptr_CWnd_proxy c_str_data_w(CListView const& w)
#else /* ? UNICODE */
inline c_str_ptr_CWnd_proxy c_str_data_a(CListView const& w)
#endif /* UNICODE */
{
    return c_str_data(w);
}
# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* CWnd */
/** \ref group__concept__Shim__string_access__c_str_len for CWnd
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline ms_size_t c_str_len(CWnd const& w)
{
    return ximpl_mfcstl_CWnd_::GetWindowTextLength_T_(w);
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef UNICODE
inline ms_size_t c_str_len_w(CWnd const& w)
# else /* ? UNICODE */
inline ms_size_t c_str_len_a(CWnd const& w)
# endif /* UNICODE */
{
    return c_str_len(w);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for CListBox
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline ms_size_t c_str_len(CListBox const& w)
{
    return ximpl_mfcstl_CWnd_::GetWindowTextLength_T_(w);
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef UNICODE
inline ms_size_t c_str_len_w(CListBox const& w)
# else /* ? UNICODE */
inline ms_size_t c_str_len_a(CListBox const& w)
# endif /* UNICODE */
{
    return c_str_len(w);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


#ifdef __AFXCMN_H__
/** \ref group__concept__Shim__string_access__c_str_len for CListCtrl
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline ms_size_t c_str_len(CListCtrl const& w)
{
    return ximpl_mfcstl_CWnd_::GetWindowTextLength_T_(w);
}
# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#  ifdef UNICODE
inline ms_size_t c_str_len_w(CListCtrl const& w)
#  else /* ? UNICODE */
inline ms_size_t c_str_len_a(CListCtrl const& w)
#  endif /* UNICODE */
{
    return c_str_len(w);
}
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


# ifdef __AFXCVIEW_H__
/** \ref group__concept__Shim__string_access__c_str_len for CListView
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline ms_size_t c_str_len(CListView const& w)
{
    return c_str_len(w.GetListCtrl());
}
#  ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#   ifdef UNICODE
inline ms_size_t c_str_len_w(CListView const& w)
#   else /* ? UNICODE */
inline ms_size_t c_str_len_a(CListView const& w)
#   endif /* UNICODE */
{
    return c_str_len(w);
}
#  endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

# endif /* __AFXCVIEW_H__ */
#endif /* __AFXCMN_H__ */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace mfcstl */
# else
} /* namespace stlsoft::mfcstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef MFCSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::mfcstl::c_str_data;
#if defined(UNICODE)
using ::mfcstl::c_str_data_w;
#else /* ? UNICODE */
using ::mfcstl::c_str_data_a;
#endif /* UNICODE */

using ::mfcstl::c_str_len;
#if defined(UNICODE)
using ::mfcstl::c_str_len_w;
#else /* ? UNICODE */
using ::mfcstl::c_str_len_a;
#endif /* UNICODE */

using ::mfcstl::c_str_ptr;
#if defined(UNICODE)
using ::mfcstl::c_str_ptr_w;
#else /* ? UNICODE */
using ::mfcstl::c_str_ptr_a;
#endif /* UNICODE */

using ::mfcstl::c_str_ptr_null;
#if defined(UNICODE)
using ::mfcstl::c_str_ptr_null_w;
#else /* ? UNICODE */
using ::mfcstl::c_str_ptr_null_a;
#endif /* UNICODE */


# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ACCESS_STRING_HPP_CWND */

/* ///////////////////////////// end of file //////////////////////////// */

