/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/exception_string_creator.hpp
 *
 * Purpose:     Contains the exception_string_creator class.
 *
 * Created:     25th May 2010
 * Updated:     16th February 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/exception_string_creator.hpp
 *
 * \brief [C++] Definition of the stlsoft::exception_string_creator class
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR_MINOR    1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR_REVISION 8
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR_EDIT     28
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

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR
#  include <stlsoft/error/conversion_error.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING
# include <stlsoft/util/exception_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>                     // for wcstombs()
#endif /* !STLSOFT_INCL_H_STDLIB */

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

/** Minimalist string class for use within exception classes.
 *
 * \ingroup group__library__String
 */
template<
    ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T = stlsoft_char_traits<C>
,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = stlsoft_char_traits<C> */
,   ss_typename_param_k A /* = allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class basic_exception_string_creator
{
/// \name Member Types
/// @{
public:
    /// The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// This type
    typedef basic_exception_string_creator<C, T, A>         class_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The exception string type
    typedef exception_string                                exception_string_type;
private:
    typedef STLSOFT_NS_QUAL_STD(basic_string)<C, T, A>      string_type_;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an empty exception
    basic_exception_string_creator()
        : m_message()
    {}
    /// Constructs an empty exception, with the given capacity reserved
    ///
    /// \param capacity Specifies an initial capacity
    ss_explicit_k
    basic_exception_string_creator(size_type capacity)
        : m_message()
    {
        m_message.reserve(capacity);
    }
    /// Constructs an exception from the given message
    ///
    /// \param message The message from which to construct
    ss_explicit_k
    basic_exception_string_creator(char_type const* message)
        : m_message(message)
    {}
    /// Constructs an exception from the given message, to the given length
    basic_exception_string_creator(char_type const* message, size_type n)
        : m_message(message, n)
    {}
    /// Copies the message from the given instance
    basic_exception_string_creator(class_type const& rhs)
        : m_message(rhs.m_message)
    {}
private:
    class_type& operator =(class_type const&);
public:

    /// Truncates the string to the given length
    ///
    /// \param n The length to which the string's contents will be truncated
    ///
    /// \remarks This method is a no-op if the length specified is greater
    ///  than the current length
    class_type& truncate(size_type n)
    {
        if (n < m_message.size())
        {
            m_message.resize(n);
        }

        return *this;
    }

    /// Causes the internal storage to be at least as large as the given
    /// capacity
    class_type& reserve(size_type capacity)
    {
        m_message.reserve(capacity);

        return *this;
    }

    /// Creates an instance of the exception string containing all the
    /// string components that have been added to the creator
    exception_string_type create() const
    {
        return create_(m_message.data(), m_message.size());
    }
/// @}

/// \name Operations
/// @{
public:
    /// Appends a multibyte C-style string
    class_type& append(ss_char_a_t const* s)
    {
        return append_(s, STLSOFT_NS_QUAL(c_str_len_a)(s));
    }
    /// Appends \c n characters of the multibyte C-style string \c s
    class_type& append(ss_char_a_t const* s, size_type n)
    {
        return append_(s, n);
    }
    /// Appends a wide C-style string
    ///
    /// \exception stlsoft::conversion_error If \c s points to a wide-string
    ///    that contains a character that cannot be converted.
    class_type& append(ss_char_w_t const* s)
    {
        return append_(s, STLSOFT_NS_QUAL(c_str_len_w)(s));
    }
    /// Appends \c n characters of the wide C-style string \c s
    ///
    /// \exception stlsoft::conversion_error If \c s points to a wide-string
    ///    that contains a character that cannot be converted (within the
    ///    range <code>[0, n)</code>).
    class_type& append(ss_char_w_t const* s, size_type n)
    {
        return append_(s, n);
    }
    /// Appends a single multibyte character
    class_type& append(ss_char_a_t ch)
    {
        return append_(&ch, 1u);
    }
    /// Appends a single wide character
    class_type& append(ss_char_w_t ch)
    {
        return append_(&ch, 1u);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append(int i)
    {
        return append_integer_(i);
    }
    /// Appends the string form of the given parameter, which is accessed
    /// via application of the string access shims
    /// <strong>stlsoft::c_str_data</strong> and
    /// <strong>stlsoft::c_str_len</strong>.
    template <ss_typename_param_k S>
    class_type& append(S const& s)
    {
        // NOTE: if the compiler brings you here, it's probably because you've
        // passed a numeric type that is not int. You may try one of:
        //
        // - converting your value to int
        // - using one of the append_number() overloads
        // - doing your own conversion to string and appending the result

        return append_(STLSOFT_NS_QUAL(c_str_data)(s), STLSOFT_NS_QUAL(c_str_len)(s));
    }

#ifdef STLSOFT_CF_8BIT_INT_EXTENDED_TYPE_IS_DISTINCT
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_sint8_t const& i)
    {
        return append_integer_(i);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_uint8_t const& i)
    {
        return append_integer_(i);
    }
#endif // STLSOFT_CF_8BIT_INT_EXTENDED_TYPE_IS_DISTINCT
#ifdef STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_sint16_t const& i)
    {
        return append_integer_(i);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_uint16_t const& i)
    {
        return append_integer_(i);
    }
#endif // STLSOFT_CF_16BIT_INT_EXTENDED_TYPE_IS_DISTINCT
#if defined(STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT) || \
    ( defined(STLSOFT_COMPILER_IS_MSVC) && \
      _MSC_VER == 1200) /* NOTE: This is a hack, and should be updated when STLSoft 1.10 is released */
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_sint32_t const& i)
    {
        return append_integer_(i);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_uint32_t const& i)
    {
        return append_integer_(i);
    }
#endif // STLSOFT_CF_32BIT_INT_EXTENDED_TYPE_IS_DISTINCT
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_sint64_t const& i)
    {
        return append_integer_(i);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(ss_uint64_t const& i)
    {
        return append_integer_(i);
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(int i)
    {
        return append_integer_(i);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(unsigned int i)
    {
        return append_integer_(i);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(long i)
    {
        return append_integer_(i);
    }
    /// Appends the string-ified form of the integer \c i
    class_type& append_number(unsigned long i)
    {
        return append_integer_(i);
    }

    /// Appends the given value to the message,
    template <ss_typename_param_k V>
    void operator += (V const& v)
    {
        append(v);
    }
/// @}

/// \name Attributes
/// @{
public:
    /// Returns a null-terminated c-style string string representing
    /// the message
    char_type const* c_str() const
    {
        return m_message.c_str();
    }
    /// Returns a null-terminated c-style string string representing
    /// the message
    char_type const* data() const
    {
        return m_message.data();
    }
    /// Indicates whether or not the message is blank
    ss_bool_t   empty() const
    {
        return 0 == this->length();
    }
    /// Returns the number of characters in the message
    size_type   length() const
    {
        return size();
    }
    /// Returns the number of characters in the message
    size_type   size() const
    {
        return m_message.size();
    }
    size_type   capacity() const
    {
        return m_message.capacity();
    }
/// @}

/// \name Implementation
/// @{
private:
    enum { UnicodeMaxMultiplier = (2 == sizeof(ss_char_w_t)) ? 3 : 6 };

    class_type& append_(ss_char_a_t const* s, size_type n)
    {
        m_message.append(s, n);

        return *this;
    }
    class_type& append_(ss_char_w_t const* s, size_type n)
    {
        stlsoft::auto_buffer<ss_char_a_t, 256>  buff(n * UnicodeMaxMultiplier);

        return append_(buff.data(), wide_to_multibyte_or_throw_(s, n, &buff[0], buff.size()));
    }
    template <ss_typename_param_k I>
    class_type& append_integer_(I const& i)
    {
        char_type           num[21];
        size_type           n;
        char_type const*    r = integer_to_decimal_string(&num[0], STLSOFT_NUM_ELEMENTS(num), i, &n);

        return append_(r, n);
    }

    static exception_string_type create_(
        ss_char_a_t const*  s
    ,   size_type           n
    )
    {
        return exception_string_type(s, n);
    }
    static exception_string_type create_(
        ss_char_w_t const*  s
    ,   size_type           n
    )
    {
        stlsoft::auto_buffer<ss_char_a_t, 256>  buff(n * UnicodeMaxMultiplier);

        return create_(buff.data(), wide_to_multibyte_or_throw_(s, n, &buff[0], buff.size()));
    }
    static size_t wide_to_multibyte_or_throw_(
        ss_char_w_t const*  src
    ,   size_type           cchSrc
    ,   ss_char_a_t*        dest
    ,   size_type           cbDest
    )
    {
        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(cbDest >= cchSrc * UnicodeMaxMultiplier, "insufficient destination buffer size");

        int         err;
        ss_size_t   numConverted;
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

        err = ::wcstombs_s(&numConverted, dest, cbDest, src, cchSrc);

        if (0 == err)
        {
            // wcstombs_s() always included nul-terminator in count
            --numConverted;
        }
        else
        {
#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */

        numConverted = ::wcstombs(dest, src, cchSrc);

        STLSOFT_SUPPRESS_UNUSED(cbDest);

        if (static_cast<ss_size_t>(-1) == numConverted)
        {
            err = errno;
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(conversion_error("failed to convert wide string to multibyte string", err));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            return 0u;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return numConverted;
    }
/// @}

/// \name Fields
/// @{
private:
    string_type_ m_message;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

typedef basic_exception_string_creator<
    ss_char_a_t
#ifndef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   stlsoft_char_traits<ss_char_a_t>
,   ss_typename_type_k allocator_selector<ss_char_a_t>::allocator_type
#endif /* !STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>                                                           exception_string_creator_a;

typedef basic_exception_string_creator<
    ss_char_w_t
#ifndef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   stlsoft_char_traits<ss_char_w_t>
,   ss_typename_type_k allocator_selector<ss_char_w_t>::allocator_type
#endif /* !STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>                                                           exception_string_creator_w;

typedef exception_string_creator_a                          exception_string_creator;
typedef exception_string_creator_w                          exception_wstring_creator;

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<C, T, A>::char_type const*
c_str_data(
    basic_exception_string_creator<C, T, A> const& xs
)
{
    return xs.data();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<C, T, A>::size_type
c_str_len(
    basic_exception_string_creator<C, T, A> const& xs
)
{
    return xs.size();
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<C, T, A>::char_type const*
c_str_ptr(
    basic_exception_string_creator<C, T, A> const& xs
)
{
    return xs.c_str();
}

template <ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<ss_char_a_t, T, A>::char_type const*
c_str_data_a(
    basic_exception_string_creator<ss_char_a_t, T, A> const& xs
)
{
    return xs.data();
}

template <ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<ss_char_a_t, T, A>::size_type
c_str_len_a(
    basic_exception_string_creator<ss_char_a_t, T, A> const& xs
)
{
    return xs.size();
}

template <ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<ss_char_a_t, T, A>::char_type const*
c_str_ptr_a(
    basic_exception_string_creator<ss_char_a_t, T, A> const& xs
)
{
    return xs.c_str();
}

template <ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<ss_char_w_t, T, A>::char_type const*
c_str_data_w(
    basic_exception_string_creator<ss_char_w_t, T, A> const& xs
)
{
    return xs.data();
}

template <ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<ss_char_w_t, T, A>::size_type
c_str_len_w(
    basic_exception_string_creator<ss_char_w_t, T, A> const& xs
)
{
    return xs.size();
}

template <ss_typename_param_k T, ss_typename_param_k A>
inline
ss_typename_type_ret_k basic_exception_string_creator<ss_char_w_t, T, A>::char_type const*
c_str_ptr_w(
    basic_exception_string_creator<ss_char_w_t, T, A> const& xs
)
{
    return xs.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR */

/* ///////////////////////////// end of file //////////////////////////// */

