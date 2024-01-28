/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/containers/frequency_map.hpp
 *
 * Purpose:     A container that measures the frequency of the unique elements it contains.
 *
 * Created:     1st October 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/containers/frequency_map.hpp
 *
 * \brief [C++] Definition of the stlsoft::frequency_map container
 *   class template
 *   (\ref group__library__Container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_MAJOR    2
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_MINOR    6
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_REVISION 7
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_EDIT     44
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

#ifndef STLSOFT_INCL_MAP
# define STLSOFT_INCL_MAP
# include <map>
#endif /* !STLSOFT_INCL_MAP */

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

/** A container that measures the frequency of the unique elements it
 *    contains.
 *
 * \ingroup group__library__Container
 *
 * \param T The value type of the container
 * \param N The count integer type. Defaults to uint32_t
 */
template<
    ss_typename_param_k T
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1300
,   ss_typename_param_k N = unsigned int
#else
,   ss_typename_param_k N = uint32_t
#endif
,   ss_typename_param_k P = STLSOFT_NS_QUAL_STD(less)<T>
>
class frequency_map
    : public stl_collection_tag
{
private: // Member Types
    typedef STLSOFT_NS_QUAL_STD(map)<T, N, P>                       map_type_;
public:
    /// This type
    typedef frequency_map<T, N, P>                                  class_type;
    /// The value type
    typedef ss_typename_param_k map_type_::value_type               value_type;
    /// The non-mutating (const) iterator type
    typedef ss_typename_param_k map_type_::const_iterator           const_iterator;
//    typedef ss_typename_param_k map_type_::const_pointer            const_pointer;
    /// The non-mutating (const) reverse iterator type
    typedef ss_typename_param_k map_type_::const_reverse_iterator   const_reverse_iterator;
    /// The non-mutating (const) reference type
    typedef ss_typename_param_k map_type_::const_reference          const_reference;
    /// The key type
    typedef ss_typename_param_k map_type_::key_type                 key_type;
//    typedef ss_typename_param_k map_type_::mapped_type              mapped_type
    /// The count type
    typedef N                                                       count_type;
    /// The size type
    typedef ss_size_t                                               size_type;
    /// The difference type
    typedef ss_ptrdiff_t                                            difference_type;
    /// The boolean type
    typedef ss_bool_t                                               bool_type;

public: // Construction
    /// Creates an instance of the map
    frequency_map()
        : m_map()
        , m_total(0)
    {
        STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<N>::value);

        STLSOFT_ASSERT(is_valid());
    }

public: // Modifiers
    /// Pushes an entry onto the map
    ///
    /// If the entry already exists in the map, its count will be increased
    /// by 1. If it does not previously exist, it will be added with an
    /// initial count of one
    ///
    /// \note <b>Thread-safety</b>: it is strongly exception-safe - if an
    ///   entry cannot be added,
    count_type push(key_type const& key)
    {
        STLSOFT_ASSERT(is_valid());

        count_type r = ++m_map[key];

#if 0
        // NOTE: Because the count type N must be an integer, the code above
        // is equivalent to the following "full" exception-safe implementation.
        ss_typename_param_k map_type_::iterator it = m_map.find(key);
        if (m_map.end() == it)
        {
            value_type value(key, 1);

            m_map.insert(value);

            return 1;
        }
        else
        {
            value_type& value = *it;

            return ++(*it).second;
        }
#endif /* 0 */

        ++m_total;

        STLSOFT_ASSERT(is_valid());

        return r;
    }

    void push_n(
        key_type const&     key
    ,   count_type          n
    )
    {
        // TODO: update this to a single action
        { for (count_type i = 0; i != n; ++i)
        {
            push(key);
        }}
    }

    /// Removes all entries from the map
    void clear()
    {
        STLSOFT_ASSERT(is_valid());

        m_map.clear();
        m_total = 0u;

        STLSOFT_ASSERT(is_valid());
    }

    /// Merges in all entries from the given map
    class_type& merge(class_type const& rhs)
    {
        STLSOFT_ASSERT(is_valid());

        class_type t(*this);

        { for (const_iterator i = rhs.begin(); i != rhs.end(); ++i)
        {
            t.m_map[(*i).first] += (*i).second;
        }}
        t.m_total += rhs.m_total;

        t.swap(*this);

        STLSOFT_ASSERT(is_valid());

        return *this;
    }

    class_type& operator +=(class_type const& rhs)
    {
        return merge(rhs);
    }

    /// Swaps the state of the given instance with this instance
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        std_swap(m_map, rhs.m_map);
        std_swap(m_total, rhs.m_total);

        STLSOFT_ASSERT(is_valid());
    }

public: // Search
    /// Returns an iterator for the entry representing the given key, or
    /// <code>end()</code> if no such entry exists.
    const_iterator find(key_type const& key) const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.find(key);
    }

public: // Element Access
    /// Returns the count associated with the entry representing the given
    /// key, or 0 if no such entry exists.
    count_type operator [](key_type const& key) const
    {
        STLSOFT_ASSERT(is_valid());

        return count(key);
    }

    /// Returns the count associated with the entry representing the given
    /// key, or 0 if no such entry exists.
    count_type count(key_type const& key) const
    {
        STLSOFT_ASSERT(is_valid());

        const_iterator it = m_map.find(key);

        return (m_map.end() != it) ? (*it).second : 0;
    }

public: // Size
    /// Indicates whether the map is empty
    bool_type empty() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.empty();
    }

    /// The number of unique entries in the map
    ///
    /// \remarks This may not be the same as the number of calls to
    ///   <code>push()</code>
    size_type size() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.size();
    }

    /// The number of non-unique entries in the map
    ///
    /// \remarks This may not be the same as the number of calls to
    ///   <code>push()</code>
    count_type total() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_total;
    }

public: // Iteration
    /// A non-mutating (const) iterator representing the start of the sequence
    const_iterator begin() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.begin();
    }
    /// A non-mutating (const) iterator representing the end-point of the sequence
    const_iterator end() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.end();
    }

    /// A non-mutating (const) iterator representing the start of the reverse sequence
    const_reverse_iterator rbegin() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.rbegin();
    }
    /// A non-mutating (const) iterator representing the end of the reverse sequence
    const_reverse_iterator rend() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.rend();
    }

private:
    bool is_valid() const
    {
        return m_map.empty() == (0u == m_total);
    }

private: // Member Variables
    map_type_   m_map;
    count_type  m_total;
};

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template<
    ss_typename_param_k T
,   ss_typename_param_k N
,   ss_typename_param_k P
>
inline
frequency_map<T, N, P>
operator +(
    frequency_map<T, N, P> const& lhs
,   frequency_map<T, N, P> const& rhs
)
{
    frequency_map<T, N, P> r(lhs);

    r += rhs;

    return r;
}

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)

template<
    ss_typename_param_k T
,   ss_typename_param_k N
,   ss_typename_param_k P
>
inline void swap(
    frequency_map<T, N, P>& lhs
,   frequency_map<T, N, P>& rhs
)
{
    lhs.swap(rhs);
}

#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

#if defined(STLSOFT_CF_std_NAMESPACE)
namespace std
{

# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
       _MSC_VER >= 1310
    template<
        ss_typename_param_k T
    ,   ss_typename_param_k N
    ,   ss_typename_param_k P
    >
    inline void swap(
        STLSOFT_NS_QUAL(frequency_map)<T, N, P>& lhs
    ,   STLSOFT_NS_QUAL(frequency_map)<T, N, P>& rhs
    )
    {
        lhs.swap(rhs);
    }
# endif

} /* namespace std */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP */

/* ///////////////////////////// end of file //////////////////////////// */

