/* /////////////////////////////////////////////////////////////////////////
 * File:        atlstl/shims/access/string/CWindow.hpp
 *
 * Purpose:     String access shims for CWindow
 *
 * Created:     27th May 2002
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


/** \file atlstl/shims/access/string/CWindow.hpp
 *
 * \brief [C++] String access shims for <code>CWindow</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW
#define ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW_MAJOR    4
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW_MINOR    0
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW_REVISION 12
# define ATLSTL_VER_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW_EDIT     117
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ATLSTL_INCL_ATLSTL_HPP_ATLSTL
# include <atlstl/atlstl.hpp>
#endif /* !ATLSTL_INCL_ATLSTL_HPP_ATLSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER
# include <stlsoft/string/cstring_maker.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER */

#ifndef STRICT
# error ATL window components are not compatible with non-STRICT configuration
#endif

#ifndef STLSOFT_INCL_SYS_H_ATLWIN
# define STLSOFT_INCL_SYS_H_ATLWIN
# include <atlwin.h>
#endif /* !STLSOFT_INCL_SYS_H_ATLWIN */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::atlstl */
namespace atlstl
{
# else
/* Define stlsoft::atlstl_project */
namespace stlsoft
{
namespace atlstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/* CWindow */

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_null() function, such that the window text of a given window
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
struct c_str_ptr_null_CWindow_proxy
{
private: // types
    typedef cstring_maker<TCHAR>                            cstring_maker_type_;
    typedef cstring_maker_type_::block                      block_type_;
public:
    typedef c_str_ptr_null_CWindow_proxy                    class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWindow instance
    ///
    /// \param w The CWindow instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_null_CWindow_proxy(CWindow const& w)
        : m_block(make_block_(w))
    {}

    // Copy constructor
    c_str_ptr_null_CWindow_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_null_CWindow_proxy() STLSOFT_NOEXCEPT
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
    static
    block_type_*
    make_block_(CWindow const& w)
    {
        int length  =   (NULL == w.m_hWnd) ? 0 : w.GetWindowTextLength();

        if (length == 0)
        {
            return NULL;
        }
        else
        {
            block_type_* const block = cstring_maker_type_::alloc(NULL, length);

            if (NULL != block)
            {
                w.GetWindowText(&block->data[0], length + 1);
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
struct c_str_ptr_CWindow_proxy
{
private: // types
    typedef cstring_maker<TCHAR>                            cstring_maker_type_;
    typedef cstring_maker_type_::block                      block_type_;
public:
    typedef c_str_ptr_CWindow_proxy                         class_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given CWindow instance
    ///
    /// \param w The CWindow instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_CWindow_proxy(CWindow const& w)
        : m_block(make_block_(w))
    {}

    // Copy constructor
    c_str_ptr_CWindow_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_CWindow_proxy() STLSOFT_NOEXCEPT
    {
        cstring_maker_type_::free(m_block);
    }
private:
    void operator =(class_type const&); // copy-assignment operator proscribed

// Accessors
public:
    /// Returns a null-terminated string representing the window contents, or
    /// the empty string "" if the window contains no text.
    operator LPCTSTR () const
    {
        return &m_block->data[0];
    }

private: // implementation
    static
    block_type_*
    make_block_(CWindow const& w)
    {
        int length  =   (NULL == w.m_hWnd) ? 0 : w.GetWindowTextLength();

        block_type_* const block = cstring_maker_type_::alloc(NULL, length);

        if (NULL != block &&
            length != 0)
        {
            w.GetWindowText(&block->data[0], length + 1);
        }

        return block;
    }

private: // fields
    block_type_* const  m_block;
};

/* /////////////////////////////////////////////////////////////////////////
 * equivalence testing
 */

inline as_bool_t operator ==(LPCTSTR lhs, c_str_ptr_null_CWindow_proxy const& rhs)
{
    return lhs == static_cast<LPCTSTR>(rhs);
}

inline as_bool_t operator ==(c_str_ptr_null_CWindow_proxy const& lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) == rhs;
}

inline as_bool_t operator !=(LPCTSTR lhs, c_str_ptr_null_CWindow_proxy const& rhs)
{
    return lhs != static_cast<LPCTSTR>(rhs);
}

inline as_bool_t operator !=(c_str_ptr_null_CWindow_proxy const& lhs, LPCTSTR rhs)
{
    return static_cast<LPCTSTR>(lhs) != rhs;
}

/* /////////////////////////////////////////////////////////////////////////
 * iostream compatibility
 */

template<ss_typename_param_k S>
inline S& operator <<(S& s, c_str_ptr_null_CWindow_proxy const& shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}

template <ss_typename_param_k S>
inline S& operator <<(S& s, c_str_ptr_CWindow_proxy const& shim)
{
    s << static_cast<LPCTSTR>(shim);

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWindow */

/** \ref group__concept__Shim__string_access__c_str_data for CWindow
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
c_str_ptr_CWindow_proxy
c_str_data(
    ATLSTL_NS_QUAL_ATL(CWindow) const& w
)
{
    return c_str_ptr_CWindow_proxy(w);
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef UNICODE
inline c_str_ptr_CWindow_proxy c_str_data_w(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
# else /* ? UNICODE */
inline c_str_ptr_CWindow_proxy c_str_data_a(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
# endif /* UNICODE */
{
    return c_str_data(w);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number
 * of characters in the character string in the expression.
 */

/* CWindow */

/** \ref group__concept__Shim__string_access__c_str_len for CWindow
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline as_size_t c_str_len(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
{
    return static_cast<as_size_t>(w.GetWindowTextLength());
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef UNICODE
inline as_size_t c_str_len_w(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
# else /* ? UNICODE */
inline as_size_t c_str_len_a(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
# endif /* UNICODE */
{
    return c_str_len(w);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* CWindow */

/** \ref group__concept__Shim__string_access__c_str_ptr for CWindow
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_CWindow_proxy c_str_ptr(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
{
    return c_str_ptr_CWindow_proxy(w);
}

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#  ifdef UNICODE
inline c_str_ptr_CWindow_proxy c_str_ptr_w(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
#  else /* ? UNICODE */
inline c_str_ptr_CWindow_proxy c_str_ptr_a(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
#  endif /* UNICODE */
{
    return c_str_ptr(w);
}
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* CWindow */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for CWindow
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_null_CWindow_proxy c_str_ptr_null(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
{
    return c_str_ptr_null_CWindow_proxy(w);
}

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#  ifdef UNICODE
inline c_str_ptr_null_CWindow_proxy c_str_ptr_null_w(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
#  else /* ? UNICODE */
inline c_str_ptr_null_CWindow_proxy c_str_ptr_null_a(ATLSTL_NS_QUAL_ATL(CWindow) const& w)
#  endif /* UNICODE */
{
    return c_str_ptr_null(w);
}
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ATLSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace atlstl */
# else
} /* namespace stlsoft::atlstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef ATLSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::atlstl::c_str_data;
#if defined(UNICODE)
using ::atlstl::c_str_data_w;
#else /* ? UNICODE*/
using ::atlstl::c_str_data_a;
#endif /* UNICODE*/

using ::atlstl::c_str_len;
#if defined(UNICODE)
using ::atlstl::c_str_len_w;
#else /* ? UNICODE*/
using ::atlstl::c_str_len_a;
#endif /* UNICODE*/

using ::atlstl::c_str_ptr;
#if defined(UNICODE)
using ::atlstl::c_str_ptr_w;
#else /* ? UNICODE*/
using ::atlstl::c_str_ptr_a;
#endif /* UNICODE*/

using ::atlstl::c_str_ptr_null;
#if defined(UNICODE)
using ::atlstl::c_str_ptr_null_w;
#else /* ? UNICODE*/
using ::atlstl::c_str_ptr_null_a;
#endif /* UNICODE*/

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !ATLSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ATLSTL_INCL_ATLSTL_SHIMS_ACCESS_STRING_HPP_CWINDOW */

/* ///////////////////////////// end of file //////////////////////////// */

