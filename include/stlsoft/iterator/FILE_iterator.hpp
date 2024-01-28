/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/FILE_iterator.hpp
 *
 * Purpose:     FILE* output iterator.
 *
 * Created:     21st April 2009
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2009-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/iterator/FILE_iterator.hpp
 *
 * \brief [C++] Definition of the stlsoft::FILE_iterator class
 *   template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_FILE_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_FILE_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILE_ITERATOR_MAJOR       1
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILE_ITERATOR_MINOR       0
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILE_ITERATOR_REVISION    8
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILE_ITERATOR_EDIT        16
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

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_PRINTF_TYPE
# include <stlsoft/meta/is_printf_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_PRINTF_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS
# include <stlsoft/util/constraints.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS */

#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */
#ifndef STLSOFT_INCL_H_STDARG
# define STLSOFT_INCL_H_STDARG
# include <stdarg.h>
#endif /* !STLSOFT_INCL_H_STDARG */
#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>
#endif /* !STLSOFT_INCL_H_STDIO */

/* For some reason, VC++ 6.0 has an ICE if the following is not included */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1200
# include <iterator>
# include <stlsoft/string/char_traits.hpp>
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** \brief Enhanced functionality over std::FILE_iterator
 *
 * \ingroup group__library__iterators
 *
 * This class template provides full backwards-compatibility with
 * std::FILE_iterator, but offers the additional capability to supply both
 * prefix <i>and</i> suffix to each delimited item.
 *
 * For example, the following code indents each entry in the sequence as well
 * as appending a carriage return.
 *
\code

std::vector<int>  ints(10);

{ for (size_t i = 0; i < ints.size(); ++i)
{
  ints[i] = i;
}}

std::cout << "Elements:" << std::endl;
std::copy(ints.begin(), ints.end()
        , stlsoft::FILE_iterator<int>(stdout, "\t%d\n"));
\endcode
 *
 * This gives the following output:
 *
\code
        0
        1
        2
        3
        4
        5
        6
        7
        8
\endcode
 *
 * \param V The value type.
 * \param C The character type. Defaults to <code>char</code>.
 * \param T The traits type. Defaults to <code>std::char_traits&lt;C></code>.
 * \param S The string type. Defaults to <code>std::basic_string&lt;C></code>.
 *
 * \remarks The class template avoids fatuous assignment syntax by using the
 *  \ref group__pattern__dereference_proxy "Dereference Proxy" pattern.
 *
 * \warn There is no protection against a mismatched format string. You must
 *   ensure that the assigned type matches the format string.
 */
template<   ss_typename_param_k V
        ,   ss_typename_param_k C = char
        ,   ss_typename_param_k T = stlsoft_ns_qual_std(char_traits)<C>
        ,   ss_typename_param_k S = stlsoft_ns_qual_std(basic_string)<C, T>
        >
// [[synesis:class:iterator: FILE_iterator<T<V>, T<C>, T<T>, T<S>>]]
class FILE_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    /// The value type
    typedef V                           assigned_type;
    /// The character type
    typedef C                           char_type;
    /// The traits type
    typedef T                           traits_type;
    /// The string type
    typedef S                           string_type;
    /// The class type
    typedef FILE_iterator<V, C, T, S>   class_type;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance holding a reference to the given stream, with a suffix
    ///
    /// \note This is 100% functionally compatible with FILE_iterator
    template <ss_typename_param_k S1>
    FILE_iterator(FILE* stm, S1 const& format)
        : m_stm(stm)
        , m_format(stlsoft::c_str_data(format), stlsoft::c_str_len(format))
    {}
    /// Creates a copy of an FILE_iterator instance
    ///
    /// \param rhs The instance to copy
    FILE_iterator(class_type const& rhs)
        : m_stm(rhs.m_stm)
        , m_format(rhs.m_format)
    {}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    ~FILE_iterator() STLSOFT_NOEXCEPT
    {
        // If this static assertion fires, you are attempting to specialise
        // <code>FILE_iterator</code> with a type that is not:
        //
        // - a character, or
        // - a floating-point, or
        // - an integer, or
        // - a pointer
        STLSOFT_STATIC_ASSERT(is_printf_type<assigned_type>::value);
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Implementation
/// @{
private:
    class deref_proxy
    {
    public:
        deref_proxy(FILE_iterator* it)
            : m_it(it)
        {}

    public:
        void operator =(assigned_type const& value)
        {
            m_it->invoke_(value);
        }

    private:
        FILE_iterator* const m_it;

    // Not to be implemented
    private:
        void operator =(deref_proxy const&);
    };

    void invoke_(assigned_type const& value)
    {
        fprintf_(m_stm, m_format.c_str(), value);
    }

    static int fprintf_(FILE* stm, ss_char_a_t const* fmt, ...)
    {
        STLSOFT_STATIC_ASSERT(sizeof(char_type) == sizeof(ss_char_a_t));

        va_list args;
        int     r;

        va_start(args, fmt);
        r = ::vfprintf(stm, fmt, args);
        va_end(args);

        return r;
    }
    static int fprintf_(FILE* stm, ss_char_w_t const* fmt, ...)
    {
        STLSOFT_STATIC_ASSERT(sizeof(char_type) == sizeof(ss_char_w_t));

        va_list args;
        int     r;

        va_start(args, fmt);
        r = ::vfwprintf(stm, fmt, args);
        va_end(args);

        return r;
    }

/// @}

/// \name Ouput Iterator Methods
/// @{
public:
    /// Dereference operator
    deref_proxy operator *()
    {
        return deref_proxy(this);
    }
    /// Pre-increment operator
    class_type& operator ++()
    {
        return *this;
    }
    /// Post-increment operator
    class_type& operator ++(int)
    {
        return *this;
    }
/// @}

/// \name Implementation
/// @{
private:
    template <ss_typename_param_k S2>
    static string_type get_string_(S2 const& s)
    {
        return stlsoft::c_str_ptr(s);
    }
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER > 1300
    static string_type const& get_string_(string_type const& s)
    {
        return s;
    }
#endif /* compiler */
/// @}

/// \name Members
/// @{
private:
    FILE*       m_stm;
    string_type m_format;
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_FILE_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */

