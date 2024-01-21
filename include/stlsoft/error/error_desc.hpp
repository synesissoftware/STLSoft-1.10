/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/error/error_desc.hpp
 *
 * Purpose:     Converts a standard rerror code (errno) to a printable string.
 *
 * Created:     18th July 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/error/error_desc.hpp
 *
 * \brief [C++] Definition of the stlsoft::basic_error_desc class
 *  template
 *   (\ref group__library__error "Error" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC
#define STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_MAJOR     1
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_MINOR     3
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_REVISION  1
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERROR_DESC_EDIT      45
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS
# include <stlsoft/string/cstring_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>                    // for mbstowcs()
#endif /* !STLSOFT_INCL_H_STDLIB */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */

#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if (   defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_INTEL)) && \
    _MSC_VER >= 1300
# define STLSOFT_ERROR_DESC_wcserror                        ::_wcserror
#endif /* compiler */

#if (   defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_INTEL)) && \
    _MSC_VER >= 1400
# define STLSOFT_ERROR_DESC_wcserror_s                      ::_wcserror_s
#endif /* compiler */

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
# ifdef STLSOFT_ERROR_DESC_wcserror_s
#  define STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_
# endif /* STLSOFT_ERROR_DESC_wcserror_s */
#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
# ifdef STLSOFT_ERROR_DESC_wcserror
#  define STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_
# endif /* STLSOFT_ERROR_DESC_wcserror */
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */

#if !defined(STLSOFT_ERROR_DESC_wcserror_s) && \
    !defined(STLSOFT_ERROR_DESC_wcserror)
# include <stlsoft/string/shim_string.hpp>
# include <string>
#endif /* !STLSOFT_ERROR_DESC_wcserror_s && !STLSOFT_ERROR_DESC_wcserror */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_OPEN_WORKER_NS_(ximpl_stlsoft_error_desc_)

template <ss_typename_param_k C>
struct error_desc_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct error_desc_traits<ss_char_a_t>
{
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

    static int invoke_strerror_s_(ss_char_a_t* buff, size_t n, int code)
    {
        return ::strerror_s(buff, n, code);
    }

# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */

    static ss_char_a_t const* invoke_strerror_(int code, ss_char_a_t const*)
    {
        return ::strerror(code);
    }

# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
};

# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

#  ifdef STLSOFT_ERROR_DESC_wcserror_s

STLSOFT_TEMPLATE_SPECIALISATION
struct error_desc_traits<ss_char_w_t>
{
    static int invoke_strerror_s_(ss_char_w_t* buff, size_t n, int code)
    {
        return STLSOFT_ERROR_DESC_wcserror_s(buff, n, code);
    }
};

#  else /* ? STLSOFT_ERROR_DESC_wcserror_s */

STLSOFT_TEMPLATE_SPECIALISATION
struct error_desc_traits<ss_char_w_t>;

#  endif /* STLSOFT_ERROR_DESC_wcserror_s */

# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */

#  ifdef STLSOFT_ERROR_DESC_wcserror

STLSOFT_TEMPLATE_SPECIALISATION
struct error_desc_traits<ss_char_w_t>
{
    static ss_char_w_t const* invoke_strerror_(int code, ss_char_w_t const*)
    {
        return STLSOFT_ERROR_DESC_wcserror(code);
    }
};

#  else /* ? STLSOFT_ERROR_DESC_wcserror_s */

STLSOFT_TEMPLATE_SPECIALISATION
struct error_desc_traits<ss_char_w_t>
{
    static basic_shim_string<ss_char_w_t, 64> invoke_strerror_(int code, ss_char_w_t const*)
    {
        typedef basic_shim_string<ss_char_w_t, 64>  return_t;

        std::string const   s(::strerror(code));
        return_t            ss(s.size());
        size_t const        n = ::mbstowcs(ss.data(), s.data(), s.size());

        if (size_t(-1) == n)
        {
            return return_t(L"could not determine error");
        }

        return ss;
    }
};

#  endif /* STLSOFT_ERROR_DESC_wcserror */

# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */

STLSOFT_CLOSE_WORKER_NS_(ximpl_stlsoft_error_desc_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Utility class that loads the system string representation
 *   corresponding to a given error code.
 *
 * \ingroup group__library__error
 *
 * Consider the following example:
\code
  stlsoft::error_desc_a  ed1(ENOMEM);
  stlsoft::error_desc    ed3(ENOMEM);

  assert(0 == ::strcmp("Access is denied", ed1.c_str()));
  assert(0 == ::wcscmp(L"Access is denied", ed2.c_str()));
  assert(0 == ::_tcscmp(_T("Access is denied"), ed3.c_str()));
\endcode
 *
 * By default, the strings are looked up from the Windows system DLLs. To
 * use a specific message-string DLL, simply specify this as the second
 * argument to the constructor, as in (assuming <b>MyCustomDll.DLL</b> maps
 * <code>ERROR_ACCESS_DENIED</code> to <code>"No Access!"</code>):
 *
\code
  stlsoft::error_desc_a  ed1(ERROR_ACCESS_DENIED, "MyCustomDll.DLL");

  assert(0 == ::strcmp("No Access!", ed1.c_str()));
\endcode
 *
 * \note Naturally, \ref group__concept__Shim__string_access "String Access
 *  Shim" functions <b>c_str_ptr</b>, <b>c_str_data</b>, <b>c_str_len</b>
 *  are defined for the class template, so it may be manipulated
 *  generically. (This is very handy when used with the
 *  <a href = "http://pantheios.org/">Pantheios</a> logging library.)
 */
template <ss_typename_param_k C>
class basic_error_desc
#if defined(STLSOFT_COMPILER_IS_DMC)
    : protected allocator_selector<C>::allocator_type
#else /* ? compiler */
    : private allocator_selector<C>::allocator_type
#endif /* compiler */
{
private: // types
    typedef ss_typename_type_k allocator_selector<
        C
    >::allocator_type                                       parent_class_type;
    typedef ss_typename_type_k allocator_selector<
        C
    >::allocator_type                                       allocator_type;
public:
    /// The character type
    typedef C                                               char_type;
    /// The current specialisation of the type
    typedef basic_error_desc<C>                             class_type;
    /// The error type
    typedef int                                             error_type;
    /// The size type
    typedef ss_size_t                                       size_type;
private:
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_stlsoft_error_desc_, error_desc_traits)<
        char_type
    >                                                       traits_type;

public: // construction
    /// Loads the error string associated with the given code.
    ///
    /// \param error The errno value whose string equivalent will be searched
    ss_explicit_k basic_error_desc(error_type error = errno);
    /// Releases any resources.
    ~basic_error_desc() STLSOFT_NOEXCEPT;

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if 0 || \
     defined(STLSOFT_COMPILER_IS_CLANG) || \
     defined(STLSOFT_COMPILER_IS_GCC) || \
     0
    basic_error_desc(class_type const& rhs)
        : m_str(string_dup(rhs.m_str, rhs.m_length, get_allocator_()))
        , m_length(rhs.m_length)
    {}
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
private:
# if 1 && \
     !defined(STLSOFT_COMPILER_IS_CLANG) && \
     !defined(STLSOFT_COMPILER_IS_GCC) && \
     1
    basic_error_desc(class_type const&);    // copy-construction proscribed
#endif /* compiler */
    void operator =(class_type const&);     // copy-assignment proscribed

public: // attributes
    /// The error description
    char_type const* get_description() const STLSOFT_NOEXCEPT;

public: // comparison
    /// Determines whether the instance contains the same contents
    /// as \c rhs
    bool
    equal(
        char_type const* rhs
    ) const STLSOFT_NOEXCEPT;

public: // accessors
    /// The error description
    char_type const*    c_str() const STLSOFT_NOEXCEPT;
    /// The length of the error description
    size_type           length() const STLSOFT_NOEXCEPT;
    /// The length of the error description
    size_type           size() const STLSOFT_NOEXCEPT;

private: // implementation
    allocator_type& get_allocator_();

private: // members
    char_type*  m_str;
    size_type   m_length;
};

/* Typedefs to commonly encountered types. */
/** Specialisation of the basic_error_desc template for the multibyte character type \c char
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<ss_char_a_t>                       error_desc_a;
/** Specialisation of the basic_error_desc template for the wide character type \c wchar_t
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<ss_char_w_t>                       error_desc_w;
/** Specialisation of the basic_error_desc template for the character type \c char
 *
 * \ingroup group__library__error
 */
typedef basic_error_desc<char>                              error_desc;

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C>
inline
ss_typename_type_ret_k basic_error_desc<C>::allocator_type&
basic_error_desc<C>::get_allocator_()
{
    return *this;
}

template <ss_typename_param_k C>
inline
basic_error_desc<C>::basic_error_desc(
    ss_typename_type_k basic_error_desc<C>::error_type error /* = errno */
)
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
    : m_length(0)
{
    stlsoft::auto_buffer<char_type, 128, allocator_type>    buff(128);

    for (;;)
    {
        // If you get compiler errors on the following line, it may be because
        // you are trying to use a wide char specialisation of basic_error_desc
        // with a compiler for which a definition for
        // STLSOFT_ERROR_DESC_wcserror_s does not exist. If your platform has an
        // equivalental function, as does Microsoft's with _wcserror_s(), then
        // define STLSOFT_ERROR_DESC_wcserror_s to the name of your function
        int n = traits_type::invoke_strerror_s_(&buff[0], buff.size() - 1, error);

        buff[buff.size() - 1u] = '\0';

        if (0 == n)
        {
            size_t cch = c_str_len(buff.data());

            if (cch < buff.size() - 2u)
            {
                m_length = cch;
                buff.resize(cch + 1u);
                break;
            }
        }

        if (!buff.resize(1u + buff.size() * 2u))
        {
            buff.resize(1u);
            break;
        }
    }

    m_str = string_dup(buff.data(), m_length, get_allocator_());
}
#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
    // If you get compiler errors on the following line, it may be because
    // you are trying to use a wide char specialisation of basic_error_desc
    // with a compiler for which a definition for
    // STLSOFT_ERROR_DESC_wcserror does not exist. If your platform has an
    // equivalental function, as does Microsoft's with _wcserror(), then
    // define STLSOFT_ERROR_DESC_wcserror to the name of your function
    : m_str(string_dup(static_cast<char_type const*>(traits_type::invoke_strerror_(error, static_cast<char_type const*>(0))), get_allocator_(), &m_length))
{}
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */

template <ss_typename_param_k C>
inline
basic_error_desc<C>::~basic_error_desc() STLSOFT_NOEXCEPT
{
    get_allocator_().deallocate(m_str, m_length);
}

template <ss_typename_param_k C>
inline
ss_typename_type_ret_k basic_error_desc<C>::char_type const*
basic_error_desc<C>::get_description() const STLSOFT_NOEXCEPT
{
    static char_type const s_nullMessage[1] = { '\0' };

    return (NULL != m_str) ? m_str : s_nullMessage;
}

template <ss_typename_param_k C>
inline
bool
basic_error_desc<C>::equal(
    C const* rhs
) const STLSOFT_NOEXCEPT
{
    if (NULL == rhs)
    {
        return false;
    }

    return 0 == ::strcmp(c_str(), rhs);
}

template <ss_typename_param_k C>
inline
ss_typename_type_ret_k basic_error_desc<C>::char_type const*
basic_error_desc<C>::c_str() const STLSOFT_NOEXCEPT
{
    return get_description();
}

template <ss_typename_param_k C>
inline
ss_typename_type_ret_k basic_error_desc<C>::size_type
basic_error_desc<C>::length() const STLSOFT_NOEXCEPT
{
    return m_length;
}

template <ss_typename_param_k C>
inline
ss_typename_type_ret_k basic_error_desc<C>::size_type
basic_error_desc<C>::size() const STLSOFT_NOEXCEPT
{
    return length();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

#ifndef STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED

/** \ref group__concept__Shim__string_access__c_str_ptr_null for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C>
inline
C const*
c_str_ptr_null(
    STLSOFT_NS_QUAL(basic_error_desc)<C> const& e
)
{
    return (0 != e.length()) ? e.c_str() : NULL;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline
ss_char_a_t const*
c_str_ptr_null_a(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_a_t> const& e
)
{
    return (0 != e.length()) ? e.c_str() : NULL;
}
inline
ss_char_w_t const*
c_str_ptr_null_w(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_w_t> const& e
)
{
    return (0 != e.length()) ? e.c_str() : NULL;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C>
inline
C const*
c_str_ptr(
    STLSOFT_NS_QUAL(basic_error_desc)<C> const& e
)
{
    return e.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline
ss_char_a_t const*
c_str_ptr_a(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_a_t> const& e
)
{
    return e.c_str();
}
inline
ss_char_w_t const*
c_str_ptr_w(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_w_t> const& e
)
{
    return e.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C>
inline
C const*
c_str_data(
    STLSOFT_NS_QUAL(basic_error_desc)<C> const& e
)
{
    return e.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline
ss_char_a_t const*
c_str_data_a(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_a_t> const& e
)
{
    return e.c_str();
}
inline
ss_char_w_t const*
c_str_data_w(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_w_t> const& e
)
{
    return e.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__Shim__string_access
 */
template <ss_typename_param_k C>
inline
ss_size_t
c_str_len(
    STLSOFT_NS_QUAL(basic_error_desc)<C> const& e
)
{
    return e.length();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline
ss_size_t
c_str_len_a(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_a_t> const& e
)
{
    return e.length();
}
inline
ss_size_t
c_str_len_w(
    STLSOFT_NS_QUAL(basic_error_desc)<ss_char_w_t> const& e
)
{
    return e.length();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \ref group__concept__Shim__Attribute__get_ptr for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__Shim__Attribute__get_ptr
 */
template <ss_typename_param_k C>
inline
C const* get_ptr(
    STLSOFT_NS_QUAL(basic_error_desc)<C> const& e
)
{
    return e;
}

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template <ss_typename_param_k C>
inline
bool
operator ==(
    STLSOFT_NS_QUAL(basic_error_desc)<C> const& lhs
,   C const*                                    rhs
)
{
    return lhs.equal(rhs);
}

template <ss_typename_param_k C>
inline
bool
operator ==(
    C const*                                    lhs
,   STLSOFT_NS_QUAL(basic_error_desc)<C> const& rhs
)
{
    return rhs.equal(lhs);
}

template <ss_typename_param_k C>
inline
bool
operator !=(
    STLSOFT_NS_QUAL(basic_error_desc)<C> const& lhs
,   C const*                                    rhs
)
{
    return !lhs.equal(rhs);
}

template <ss_typename_param_k C>
inline
bool
operator !=(
    C const*                                    lhs
,   STLSOFT_NS_QUAL(basic_error_desc)<C> const& rhs
)
{
    return !rhs.equal(lhs);
}


/** \ref group__concept__Shim__stream_insertion "stream insertion shim" for stlsoft::basic_error_desc
 *
 * \ingroup group__concept__Shim__stream_insertion
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k C
>
inline
S&
operator <<(
    S&                                          s
,   STLSOFT_NS_QUAL(basic_error_desc)<C> const& e
)
{
    s << e.get_description();

    return s;
}

#endif /* !STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * global namespace shims
 */

/* This defines stream inserter shim function templates for the converters
 * for use with the Visual C++ <7.1 standard library.
 */

#if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
    STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_1

# include <iosfwd>

#if 0
template<
    ss_typename_param_k C
>
inline
STLSOFT_NS_QUAL_STD(basic_ostream)<C>&
operator <<(
    STLSOFT_NS_QUAL_STD(basic_ostream)<C>&      stm
,   STLSOFT_NS_QUAL(basic_error_desc)<C> const& desc
)
{
    return stm << desc.c_str();
}
#endif /* 0 */

#endif /* library */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_ERROR_DESC */

/* ///////////////////////////// end of file //////////////////////////// */

