/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/filesystem/path_buffer.hpp
 *
 * Purpose:     Contains the basic_path_buffer template class.
 *
 * Created:     27th May 2020
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020-2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/filesystem/path_buffer.hpp
 *
 * \brief [C++] Definition of the stlsoft::basic_path_buffer class
 *  template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER
#define STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER_MAJOR       1
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER_MINOR       3
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER_REVISION    3
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER_EDIT        9
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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE
# include <stlsoft/meta/is_same_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS
# include <stlsoft/string/copy_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

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

/** A class template that provides resizable instances of path-buffer
 *
 * \note All sizes _include_ space for the terminating NUL-character
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalBufferSize
>
class basic_path_buffer
{
private: // constants
    enum
    {
        internalBufferSize = V_internalBufferSize
    };

public: // types
    /// The character type
    typedef T_character                                     char_type;
    // The allocator type
    typedef T_allocator                                     allocator_type;
#ifdef STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT

    /// The allocator traits type
    typedef std::allocator_traits<allocator_type>           allocator_traits_type;
#endif /* STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT */
    // This type
    typedef basic_path_buffer<
        char_type
    ,   allocator_type
    ,   V_internalBufferSize
    >                                                       class_type;
    /// The size type
    typedef size_t                                          size_type;
    /// The value type
    typedef char_type                                       value_type;
#ifdef STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT
    /// The reference type
    typedef ss_typename_type_k allocator_traits_type::value_type&
                                                            reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k allocator_traits_type::value_type const&
                                                            const_reference;
    /// The pointer type
    typedef ss_typename_type_k allocator_traits_type::pointer
                                                            pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k allocator_traits_type::const_pointer
                                                            const_pointer;
#else /* ? STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT */
    /// The mutating (non-const) reference type
    typedef ss_typename_type_k allocator_type::reference    reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k allocator_type::const_reference
                                                            const_reference;
    /// The mutating (non-const) pointer type
    typedef ss_typename_type_k allocator_type::pointer      pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k allocator_type::const_pointer
                                                            const_pointer;
#endif /* STLSOFT_LF_ALLOCATOR_TRAITS_SUPPORT */
private:
    typedef STLSOFT_NS_QUAL(auto_buffer)<

        char_type
    ,   internalBufferSize
    ,   allocator_type
    >                                                       buffer_type_;
public:
    /// The buffer type
    typedef buffer_type_                                    buffer_type;

public: // construction
    /// Constructs an empty instance
    basic_path_buffer()
        : m_buffer(1)
        , m_len(0)
    {
        m_buffer[0] = char_type(0);
    }
    /// Constructs an instance with an unitialised size of \c n
    ///
    /// \param n The resulting length of the buffer
    ///
    /// \post char_type(0) == (*this)[0]
    /// \post char_type(0) == (*this)[n]
    ss_explicit_k
    basic_path_buffer(
        size_type           n
    )
        : m_buffer(n + 1)
        , m_len(n)
    {
        m_buffer[0] = char_type(0);
        m_buffer[n] = char_type(0);
    }
    /// Constructs an instance containing a copy of \c s
    ///
    /// \param s A C-style string
    ss_explicit_k
    basic_path_buffer(
        char_type const*    s
    )
        : m_buffer(1 + STLSOFT_NS_QUAL(c_str_len)(s))
        , m_len(0)
    {
        m_len = m_buffer.size() - 1;

        memcpy_(m_buffer, 0, s, m_len);
        m_buffer[m_len] = char_type(0);
    }
    /// Constructs an instance containing a copy of \c s of length \c n
    ///
    /// \param s A C-style string
    /// \param n The resulting length of the buffer
    ///
    basic_path_buffer(
        char_type const*    s
    ,   size_type           n
    )
        : m_buffer(n + 1)
        , m_len(n)
    {
        memcpy_(m_buffer, 0, s, m_len);
        m_buffer[m_len] = char_type(0);
    }
    /// Constructs an instance as a copy of \c rhs
    basic_path_buffer(class_type const& rhs)
        : m_buffer(rhs.m_buffer.size())
        , m_len(rhs.m_len)
    {
        memcpy_(m_buffer, 0, rhs.m_buffer.data(), rhs.m_buffer.size());

        STLSOFT_ASSERT(char_type(0) == m_buffer[m_len]);
    }
#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    /// Constructs an auto_buffer instance by taking over the state of the
    /// instance \c rhs
    ///
    /// \param rhs The instance whose state will be taken over. Upon return
    ///   \c rhs will be <code>empty()</code>
    ///
    /// \note When \c rhs is using external memory, this is a (fast)
    ///   constant-time operation; when using internal memory, a memory copy
    ///   operation is required
    basic_path_buffer(class_type&& rhs) STLSOFT_NOEXCEPT
        : m_buffer(std::move(rhs.m_buffer))
        , m_len(rhs.m_len)
    {
        rhs.m_buffer.resize(1);
        rhs.m_len = 0;
    }

    basic_path_buffer(
        buffer_type&&       buffer
    ,   size_type           n
    )
        : m_buffer(std::move(buffer))
        , m_len(n)
    {
        m_buffer[m_len] = char_type(0);
    }
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */
    /// Releases all resources associated with the instance
    ~basic_path_buffer() STLSOFT_NOEXCEPT
    {}

private:
    void operator =(class_type const&);

public:

    /// Swaps the contents of the instance with those of \c rhs
    void
    swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        m_buffer.swap(rhs.m_buffer);
        std_swap(m_len, rhs.m_len);
    }

public: // operations
    ///
    ///
    /// \pre (0 == n || nullptr != s)
    class_type&
    assign(
        char_type const*    s
    ,   size_type           n
    )
    {
        STLSOFT_ASSERT(0 == n || ss_nullptr_k != s);

        if (m_buffer.size() < n + 1)
        {
            m_buffer.resize(n + 1);
        }

        memcpy_(m_buffer, 0, s, n);

        m_len = n;
        m_buffer[m_len] = char_type(0);

        return *this;
    }

    ///
    ///
    class_type&
    assign(
        char_type const*    s
    )
    {
        return assign(s, STLSOFT_NS_QUAL(c_str_len)(s));
    }

    class_type&
    append(
        char_type const*    s
    ,   size_type           cch
    )
    {
        size_type const n = m_len + cch + 1;

        if (m_buffer.size() < n)
        {
            m_buffer.resize(n);
        }

        if (ss_nullptr_k != s)
        {
            memcpy_(m_buffer, m_len, s, cch);
        }
        m_len += cch;
        m_buffer[m_len] = char_type(0);

        return *this;
    }

    class_type&
    append(
        char_type           ch
    )
    {
        STLSOFT_ASSERT(char_type(0) != ch);

        return append(&ch, 1);
    }

    class_type&
    pop_last() STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(!empty());

        m_buffer[--m_len] = char_type(0);

        return *this;
    }

    /// Resizes to a potentially unitialised size of \c n
    void
    resize(
        size_type           n
    )
    {
        if (m_buffer.size() < n + 1)
        {
            m_buffer.resize(n + 1);
        }
        m_len = n;

        m_buffer[n] = char_type(0);
    }

    void
    reserve(
        size_type           n
    )
    {
        if (n + 1 > m_buffer.size())
        {
            m_buffer.resize(n + 1);
        }
    }

    void
    truncate(
        size_type           n
    )
    {
        STLSOFT_ASSERT(m_len < m_buffer.size());

        if (n > size())
        {
            resize(n);
        }
        else if (n != m_len)
        {
            m_buffer.resize(n + 1);
            m_len = n;

            m_buffer[n] = char_type(0);
        }

        STLSOFT_ASSERT(m_len + 1 == m_buffer.size());
    }

public: // accessors

    /** The capacity of the instance
     */
    size_type
    capacity() const STLSOFT_NOEXCEPT
    {
        if (m_buffer.size() < m_buffer.internal_size())
        {
            return m_buffer.internal_size() - 1;
        }

        return m_buffer.size() - 1;
    }

    /* Indicates whether the represent path is empty
     */
    bool empty() const STLSOFT_NOEXCEPT
    {
        return 0 == size();
    }

    /** The size of the represented path
     */
    size_type size() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(0 != m_buffer.size());
        STLSOFT_ASSERT(m_len < m_buffer.size());

        return m_len;
    }

    static
    size_type
    max_size() STLSOFT_NOEXCEPT
    {
        return static_cast<size_type>(-1) / sizeof(char_type);
    }

    reference
    operator [](size_type index) STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(index < m_buffer.size());

        return m_buffer[index];
    }

    const_reference
    operator [](size_type index) const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(index < m_buffer.size());

        return m_buffer[index];
    }

    ///
    ///
    /// \pre !empty()
    char_type
    back() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(!empty());

        return m_buffer[m_len - 1];
    }

    ///
    ///
    /// \pre !empty()
    char_type
    front() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(!empty());

        return m_buffer[0];
    }

    /// \return The number of characters written, including the
    ///   NUL-terminator if included
    size_type
    copy(
        char_type   buffer[]
    ,   size_type   cchBuffer
    ) const STLSOFT_NOEXCEPT
    {
        return stlsoft::copy_contents(
            buffer
        ,   cchBuffer
        ,   m_buffer.data()
        ,   m_len
        );
    }

    const_pointer
    c_str() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(char_type(0) == m_buffer[m_buffer.size() - 1]);

        return m_buffer.data();
    }

    pointer
    data() STLSOFT_NOEXCEPT
    {
        return m_buffer.data();
    }

    const_pointer
    data() const STLSOFT_NOEXCEPT
    {
        return m_buffer.data();
    }

private: // implementation
    static
    void
    memcpy_(
        buffer_type_&       dest
    ,   size_type           offset
    ,   char_type const*    src
    ,   size_type           n
    )
    {
        STLSOFT_ASSERT(0 == n || ss_nullptr_k != src);

        if (0 != n)
        {
            STLSOFT_API_INTERNAL_memfns_memcpy(dest.data() + offset, src, n * sizeof(char_type));
        }
    }

private: // fields
    buffer_type_    m_buffer;
    size_type       m_len;
};

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

#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_PATH_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

