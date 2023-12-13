/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/access/string/LSA_UNICODE_STRING.hpp
 *
 * Purpose:     String access shims for LSA strings.
 *
 * Created:     24th May 2002
 * Updated:     23rd November 2020
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


/** \file winstl/shims/access/string/LSA_UNICODE_STRING.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   <code>LSA_UNICODE_STRING</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING
#define WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING_MAJOR     4
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING_MINOR     2
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING_REVISION  1
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING_EDIT      130
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

#ifndef _NTSECAPI_
# error This file can only be used when the Windows NT Security API has already been included (#include <ntsecapi.h>)
#endif /* !_NTSECAPI_ */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS
# include <winstl/window/functions.h>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_WINDOW_UTIL_HPP_IDENT_
# include <winstl/window/util/ident_.hpp>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_UTIL_HPP_IDENT_ */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER
# include <stlsoft/string/cstring_maker.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER */

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
 * classes
 */

/* Windows Policy Management LSA_UNICODE_STRING string */
/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_null() function, such that the text of a given LSA_UNICODE_STRING
 * string may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_ptr_LSA_UNICODE_STRING_proxy
{
private: // types
    typedef cstring_maker<WCHAR>                            cstring_maker_type_;
    typedef cstring_maker_type_::block                      block_type_;
public:
    /// This type
    typedef c_str_ptr_LSA_UNICODE_STRING_proxy              class_type;

public: // construction
    /// Constructs an instance of the proxy from the given LSA_UNICODE_STRING instance
    ///
    /// \param s The LSA_UNICODE_STRING instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_LSA_UNICODE_STRING_proxy(LSA_UNICODE_STRING const& s)
        : m_block(cstring_maker_type_::alloc(s.Buffer, s.Length))
    {}

    // Copy constructor
    c_str_ptr_LSA_UNICODE_STRING_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_LSA_UNICODE_STRING_proxy() STLSOFT_NOEXCEPT
    {
        cstring_maker_type_::free(m_block);
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

public: // accessors
    /// Returns a null-terminated string representing the string contents, or
    /// the empty string "" if the string has no contents.
    operator LPCWSTR () const
    {
        return &m_block->data[0];
    }

private: // fields
    block_type_* const  m_block;
};

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_null() function, such that the text of a given LSA_UNICODE_STRING
 * string may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_ptr_null_LSA_UNICODE_STRING_proxy
{
private: // types
    typedef cstring_maker<WCHAR>                            cstring_maker_type_;
    typedef cstring_maker_type_::block                      block_type_;
public:
    /// This type
    typedef c_str_ptr_null_LSA_UNICODE_STRING_proxy         class_type;

public: // construction
    /// Constructs an instance of the proxy from the given LSA_UNICODE_STRING instance
    ///
    /// \param s The LSA_UNICODE_STRING instance from which the text will be retrieved
    ss_explicit_k c_str_ptr_null_LSA_UNICODE_STRING_proxy(LSA_UNICODE_STRING const& s)
        : m_block(cstring_maker_type_::alloc_null(s.Buffer, s.Length))
    {}

    // Copy constructor
    c_str_ptr_null_LSA_UNICODE_STRING_proxy(class_type const& rhs)
        : m_block(cstring_maker_type_::share(rhs.m_block))
    {}

    /// Releases any storage acquired by the proxy
    ~c_str_ptr_null_LSA_UNICODE_STRING_proxy() STLSOFT_NOEXCEPT
    {
        cstring_maker_type_::free(m_block);
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

public: // accessors
    /// Returns a null-terminated string representing the string contents, or
    /// NULL if the string has no contents.
    operator LPCWSTR () const
    {
        if (NULL == m_block)
        {
            return NULL;
        }

        return &m_block->data[0];
    }

private: // fields
    block_type_* const  m_block;
};

/* /////////////////////////////////////////////////////////////////////////
 * iostream compatibility
 */

template<ss_typename_param_k S>
inline S& operator <<(S& s, c_str_ptr_LSA_UNICODE_STRING_proxy const& shim)
{
    s << static_cast<LPCWSTR>(shim);

    return s;
}

template<ss_typename_param_k S>
inline S& operator <<(S& s, c_str_ptr_null_LSA_UNICODE_STRING_proxy const& shim)
{
    s << static_cast<LPCWSTR>(shim);

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* LSA_UNICODE_STRING */
# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline LPCWSTR c_str_data_w(LSA_UNICODE_STRING const& s)
{
    return s.Buffer;
}
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for LSA_UNICODE_STRING
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline LPCWSTR c_str_data(LSA_UNICODE_STRING const& s)
{
    return s.Buffer;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* LSA_UNICODE_STRING */
# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline ws_size_t c_str_len_w(LSA_UNICODE_STRING const& s)
{
    return s.Length;
}
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for LSA_UNICODE_STRING
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline ws_size_t c_str_len(LSA_UNICODE_STRING const& s)
{
    return s.Length;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* LSA_UNICODE_STRING */
# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline c_str_ptr_LSA_UNICODE_STRING_proxy c_str_ptr_w(LSA_UNICODE_STRING const& s)
{
    return c_str_ptr_LSA_UNICODE_STRING_proxy(s);
}
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for LSA_UNICODE_STRING
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_LSA_UNICODE_STRING_proxy c_str_ptr(LSA_UNICODE_STRING const& s)
{
    return c_str_ptr_LSA_UNICODE_STRING_proxy(s);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* LSA_UNICODE_STRING */
# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline c_str_ptr_null_LSA_UNICODE_STRING_proxy c_str_ptr_null_w(LSA_UNICODE_STRING const& s)
{
    return c_str_ptr_null_LSA_UNICODE_STRING_proxy(s);
}
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for LSA_UNICODE_STRING
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline c_str_ptr_null_LSA_UNICODE_STRING_proxy c_str_ptr_null(LSA_UNICODE_STRING const& s)
{
    return c_str_ptr_null_LSA_UNICODE_STRING_proxy(s);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace stlsoft::winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef WINSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::winstl::c_str_data;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;
using ::winstl::c_str_len_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_w;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_LSA_UNICODE_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

