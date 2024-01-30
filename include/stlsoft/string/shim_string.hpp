/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/shim_string.hpp
 *
 * Purpose:     Contains the basic_shim_string template class.
 *
 * Created:     9th July 2004
 * Updated:     30th January 2024
 *
 * Thanks to:   Dimitri Kaparis, for spotting a typo in the string access
 *              shims.
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


/** \file stlsoft/string/shim_string.hpp
 *
 * \brief [C++] Definition of the stlsoft::basic_shim_string class
 *   template
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
#define STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_SHIM_STRING_MAJOR       3
# define STLSOFT_VER_STLSOFT_STRING_HPP_SHIM_STRING_MINOR       7
# define STLSOFT_VER_STLSOFT_STRING_HPP_SHIM_STRING_REVISION    1
# define STLSOFT_VER_STLSOFT_STRING_HPP_SHIM_STRING_EDIT        68
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

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# include <stlsoft/string/shim_string_vc5_.hpp>
#else /* ? compiler */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION
# include <stlsoft/util/streams/string_insertion.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
# include <iosfwd>
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * code coverage
 */

#ifdef STLSOFT_USE_XCOVER
namespace
{
    class register_with_xcover
    {
    public:
        register_with_xcover()
        {
            XCOVER_CREATE_FILE_ALIAS("shim_string");
        }

    } instance;
}
#endif

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** An implementation class, which provides efficient intermediate
 * string objects for conversion shims.
 *
 * \param C The character type
 * \param N The number of characters in the internal auto_buffer
 * \param U The nUll indicator. If true, the implicit conversion operator
 *   returns NULL for an empty string, otherwise it returns the empty string
 * \param A The allocator
 * \param T The char traits type
 *
 * \ingroup group__library__String
 */
template <
    ss_typename_param_k C
,   ss_size_t           N   = 64
,   ss_bool_t           U   = false
,   ss_typename_param_k A   = ss_typename_type_def_k allocator_selector<C>::allocator_type
,   ss_typename_param_k T   = stlsoft_char_traits<C>
>
class basic_shim_string
{
/// \name Types
/// @{
public:
    /// The value type
    typedef C                                                   char_type;
    /// The allocator type
    typedef A                                                   allocator_type;
    /// The traits type
    typedef T                                                   traits_type;
    /// The current specialisation of the type
    typedef basic_shim_string<C, N, U, A, T>                    class_type;
    /// The size type
    typedef ss_size_t                                           size_type;
    /// The buffer type
    typedef auto_buffer_old<char_type, allocator_type, N + 1>   buffer_type;
    /// The boolean type
    typedef ss_bool_t                                           bool_type;
/// @}

/// \name Construction
/// @{
public:
    /// Creates an empty instance
    ///
    /// \remarks the 0th element is assigned the nul terminator
    basic_shim_string()
        : m_len(0)
        , m_buffer(1)
    {
        STLSOFT_COVER_MARK_LINE();

        m_buffer[0] = '\0';

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");
    }

    /// Creates an instance with the given number of characters
    ///
    /// \remarks the 0th and <code>n</code>th elements are assigned
    ///   the nul terminator
    ss_explicit_k
    basic_shim_string(
        size_type n
    )
        : m_len(n)
        , m_buffer(1 + n)
    {
        STLSOFT_COVER_MARK_LINE();

        m_buffer[0] = '\0';
        m_buffer[m_len] = '\0';

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");
    }

    /// Creates an instance containing the given number of characters from
    /// the given string
    ///
    /// \remarks the <code>n</code>th element is assigned the nul terminator
    basic_shim_string(
        char_type const*    s
    ,   size_type           n
    )
        : m_len(n)
        , m_buffer(1 + n)
    {
        STLSOFT_COVER_MARK_LINE();

        traits_type::copy(&m_buffer[0], s, m_len);
        m_buffer[m_len] = '\0';

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");
    }

    /// Creates an instance containing the given string
    basic_shim_string(
        char_type const* s
    )
        : m_len(~size_type(0))
        , m_buffer(1 + ((NULL == s) ? 0 : traits_type::length(s)))
    {
        STLSOFT_COVER_MARK_LINE();

        m_len = m_buffer.size() - 1;

        traits_type::copy(&m_buffer[0], s, m_len);
        m_buffer[m_len] = '\0';

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");
    }

    /// Copy constructor
    basic_shim_string(class_type const& rhs)
        : m_len(rhs.m_len)
        , m_buffer(rhs.m_buffer.size())
    {
        STLSOFT_COVER_MARK_LINE();

        traits_type::copy(&m_buffer[0], &rhs.m_buffer[0], rhs.m_len + 1);

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");
    }

    /// Swaps the contents of this instance with another
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
      std_swap(m_len, rhs.m_len);
      m_buffer.swap(rhs.m_buffer);
    }
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Operations
/// @{
public:
    /// Writes a C-style string into space storage already allocated by the
    /// constructor
    ///
    /// \pre size() == strlen(s)
    void write(char_type const* s)
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != s, "the given string may not be null");
        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(traits_type::length(s) == m_len, "the given string must match exactly the space allocated");

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        traits_type::copy(&m_buffer[0], s, m_len);
        m_buffer[m_len] = '\0';
    }

    /// Appends the given number of characters from the given C-style string
    /// to the end of the string
    ///
    /// \param s The C-style string to append
    /// \param n The number of characters to append
    ///
    /// A good use-case where you need to build up a string whose length
    /// is not exactly known is to construct with a large size, and then
    /// immediately call truncate(0u), followed by all required calls to
    /// append(). If the original size is >= than that required, then no
    /// further memory-allocation will take place.
    class_type& append(char_type const* s, size_t n)
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL((0 == n || NULL != s), "the given string may not be null unless the length is zero");
        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(0 != m_buffer.size(), "the internal buffer must have at least one element");

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        size_type newLen = m_len + n;

        if (newLen + 1 > m_buffer.size())
        {
            STLSOFT_COVER_MARK_LINE();

            if (!reserve_(newLen))
            {
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_COVER_MARK_LINE();

                return *this;
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# if defined(STLSOFT_COMPILER_IS_BORLAND)
                newLen = 0u; // Need this fatuous operation, in order to prevent Borland from optimising out the previous statement
# endif /* compiler */
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }

        traits_type::copy(&m_buffer[0] + m_len, s, n);
        m_len += n;
        m_buffer[m_len] = '\0';

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_INTERNAL(m_len >= n, "the resultant string size is too small");

        return *this;
    }

    /// Appends the given C-style string to the end of the string
    ///
    /// \param s The C-style string to append
    class_type& append(char_type const* s)
    {
        STLSOFT_COVER_MARK_LINE();

        return append(s, traits_type::length(s));
    }

    /// Truncates the string to the given length
    ///
    /// \pre The length specified must be less than or equal to the current
    ///   length
    void truncate(size_type n)
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_MESSAGE_ASSERT("shim_string truncation size must be <= current size", n <= m_len);

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");

        m_len = n;
        m_buffer[m_len] = '\0';

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");
    }

    /// Causes the storage to be at least the given size, such that future
    /// calls to append() that total that size (or less) will not cause
    /// reallocation
    ///
    /// \retval true if the requested size is less than the current size, or
    ///   the request can be fulfilled
    /// \retval false if the requested size cannot be fulfilled, and the
    ///   allocator does not throw exceptions on allocation failure
    bool_type reserve(size_type n)
    {
        STLSOFT_COVER_MARK_LINE();

        if (n > m_len)
        {
            STLSOFT_COVER_MARK_LINE();

            if (!reserve_(n))
            {
                return false;
            }
        }

        return true;
    }

    /// Changes the size of the storage to at least the given size, and
    /// applies the nul-terminator
    ///
    /// \note No elements in the range [0, n) are affected, which means that
    ///   the string may contain embedded nuls. It is entirely the user's
    ///   responsibility to ensure that the string contents are consistent
    ///   before returning from a shim overload
    bool_type resize(size_type n)
    {
        STLSOFT_COVER_MARK_LINE();

        if (!reserve(n))
        {
            return false;
        }

        m_len = n;
        m_buffer[m_len] = '\0';

        return true;
    }

#if 0
    /// Returns a reference to the internal buffer
    buffer_type &get_buffer()
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        return m_buffer;
    }
#endif /* 0 */
/// @}

/// \name Accessors
/// @{
public:
    /// The number of characters in the buffer
    size_type size() const
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        return m_len;
    }

    /// The capacity of the buffer
    size_type capacity() const
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        STLSOFT_CONTRACT_ENFORCE_ASSUMPTION(!m_buffer.empty());

        return m_buffer.size() - 1;
    }

    /// Indicates whether the string has zero size
    bool_type empty() const
    {
        STLSOFT_COVER_MARK_LINE();

        return 0u == m_len;
    }

    /// The number of characters in the internal buffer
    static size_type internal_size()
    {
        STLSOFT_COVER_MARK_LINE();

        size_type n = buffer_type::internal_size();

        return (0u == n) ? 0u : (n - 1);
    }

    /// Pointer to the buffer
    char_type* data()
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        return m_buffer.data();
    }

    /// Pointer to the buffer
    char_type const* data() const
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(m_len < m_buffer.size(), "length must be within range of buffer");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL('\0' == m_buffer[m_len], "string must be nul-terminated");

        return m_buffer.data();
    }
/// @}

/// \name Implicit Conversions
/// @{
    /// Pointer to the buffer
    operator char_type const* () const
    {
        STLSOFT_COVER_MARK_LINE();

        typedef ss_typename_type_k value_to_yesno_type<U>::type yesno_t;

        return get_ptr_(m_buffer, yesno_t());
    }
    /// The number of characters in the buffer
    operator size_type() const
    {
        STLSOFT_COVER_MARK_LINE();

        return size();
    }
/// @}

/// \name Implementation
/// @{
private:
    static char_type const* get_ptr_(buffer_type const& buffer, yes_type)
    {
        STLSOFT_COVER_MARK_LINE();

        return ('\0' != buffer[0]) ? buffer.data() : NULL;
    }
    static char_type const* get_ptr_(buffer_type const& buffer, no_type)
    {
        STLSOFT_COVER_MARK_LINE();

        return buffer.data();
    }

    bool_type reserve_(size_type newLen)
    {
        STLSOFT_COVER_MARK_LINE();

        size_type newBuffSize;

#if 0
        STLSOFT_ASSERT(newLen >= m_buffer.size());
#else
        if (newLen < m_buffer.size())
        {
            STLSOFT_COVER_MARK_LINE();

            return true;
        }
#endif

        if (newLen < internal_size())
        {
            STLSOFT_COVER_MARK_LINE();

            newBuffSize = internal_size();
        }
        else if (newLen < 16)
        {
            STLSOFT_COVER_MARK_LINE();

            newBuffSize = 2 * (newLen + 1);
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            newBuffSize = (3 * newLen) / 2 + 1;
        }

        return m_buffer.resize(newBuffSize);
    }

/// @}

/// \name Members
/// @{
private:
    size_type   m_len;
    buffer_type m_buffer;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)

template <
    ss_typename_param_k C
,   ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline C const* c_str_data(basic_shim_string<C, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.data();
}

template <
    ss_typename_param_k C
,   ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_size_t c_str_len(basic_shim_string<C, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.size();
}

template <
    ss_typename_param_k C
,   ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline C const* c_str_ptr(basic_shim_string<C, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.data();
}

template <
    ss_typename_param_k C
,   ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline C const* c_str_ptr_null(basic_shim_string<C, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.empty() ? static_cast<C const*>(0) : ss.data();
}

/* c_str_???_a */

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_char_a_t const* c_str_data_a(basic_shim_string<ss_char_a_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.data();
}

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_size_t c_str_len_a(basic_shim_string<ss_char_a_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.size();
}

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_char_a_t const* c_str_ptr_a(basic_shim_string<ss_char_a_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.data();
}

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_char_a_t const* c_str_ptr_null_a(basic_shim_string<ss_char_a_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.empty() ? static_cast<ss_char_a_t const*>(0) : ss.data();
}

/* c_str_???_w */

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_char_w_t const* c_str_data_w(basic_shim_string<ss_char_w_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.data();
}

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_size_t c_str_len_w(basic_shim_string<ss_char_w_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.size();
}

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_char_w_t const* c_str_ptr_w(basic_shim_string<ss_char_w_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.data();
}

template <
    ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline ss_char_w_t const* c_str_ptr_null_w(basic_shim_string<ss_char_w_t, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    return ss.empty() ? static_cast<ss_char_w_t const*>(0) : ss.data();
}


/* stream inserters */

template <
    ss_typename_param_k T_stream
,   ss_typename_param_k C
,   ss_size_t           N
,   ss_bool_t           U
,   ss_typename_param_k A
,   ss_typename_param_k T
>
inline
T_stream&
operator <<(
    T_stream&                               stm
,   basic_shim_string<C, N, U, A, T> const& s
)
{
    STLSOFT_NS_USING(util::string_insert);

    string_insert(stm, s.data(), s.size());

    return stm;
}
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

template <
    ss_typename_param_k         C
,   STLSOFT_NS_QUAL(ss_size_t)  N
,   stlsoft::ss_bool_t          U
,   ss_typename_param_k         A
,   ss_typename_param_k         T
>
inline std::basic_ostream<C>& operator <<(std::basic_ostream<C> &s, stlsoft::basic_shim_string<C, N, U, A, T> const& ss)
{
    STLSOFT_COVER_MARK_LINE();

    s << ss.data();

    return s;
}

# endif /* compiler */

#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* ? compiler */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

