/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/containers/frequency_map.hpp
 *
 * Purpose:     A container that measures the frequency of the unique elements it contains.
 *
 * Created:     1st October 2005
 * Updated:     12th February 2024
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
 * \brief [C++] Definition of the stlsoft::frequency_map container class
 *   template
 *   (\ref group__library__Container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_MAJOR     2
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_MINOR     8
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_REVISION  1
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_FREQUENCY_MAP_EDIT      51
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * auto-generation and compatibility
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

#ifndef STLSOFT_INCL_FUNCTIONAL
# define STLSOFT_INCL_FUNCTIONAL
# include <functional>
#endif /* !STLSOFT_INCL_FUNCTIONAL */
#ifndef STLSOFT_INCL_MAP
# define STLSOFT_INCL_MAP
# include <map>
#endif /* !STLSOFT_INCL_MAP */
#if __cplusplus >= 201103L
# ifndef STLSOFT_INCL_UNORDERED_MAP
#  define STLSOFT_INCL_UNORDERED_MAP
#  include <unordered_map>
# endif /* !STLSOFT_INCL_UNORDERED_MAP */
#endif /* C++11+ */


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

/** @brief Base-traits for stlsoft::frequency_map
 *
 * @tparam T_value The value type of the  specialisation of
 *   stlsoft::frequency_map
 */
template <
    ss_typename_param_k T_value
>
struct frequency_map_traits_base
{
    /// The value type
    typedef T_value                                         value_type;
    /// The count type
#if 0
#elif defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1300
    typedef unsigned int                                    count_type;

#elif defined(STLSOFT_UPTR_T_BASE_TYPE)

    typedef uintptr_t                                       count_type;
#else

    typedef uint32_t                                        count_type;
#endif
};

template <
    ss_typename_param_k T_value
>
struct frequency_map_traits;

/** @brief Ordered traits for stlsoft::frequency_map
 *
 * @tparam T_value The value type of the  specialisation of
 *   stlsoft::frequency_map
 * @tparam T_count The count type of the  specialisation of
 *   stlsoft::frequency_map
 */
template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_count = ss_typename_type_k frequency_map_traits_base<T_value>::count_type
>
struct frequency_map_traits_ordered
{
    /// The value type
    typedef T_value                                         value_type;
    /// The count type
    typedef T_count                                         count_type;
    /// The compare type
    typedef STLSOFT_NS_QUAL_STD(less)<T_value>              compare_type;
    /// The map type
    typedef STLSOFT_NS_QUAL_STD(map)<
        value_type
    ,   count_type
    ,   compare_type
    >                                                       map_type;
    /// The non-mutating (const) reverse iterator type
    typedef ss_typename_type_k map_type::const_reverse_iterator
                                                            const_reverse_iterator;
};

#if __cplusplus >= 201103L

/** @brief Unordered traits for stlsoft::frequency_map
 *
 * @tparam T_value The value type of the  specialisation of
 *   stlsoft::frequency_map
 * @tparam T_count The count type of the  specialisation of
 *   stlsoft::frequency_map
 */
template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_count = ss_typename_type_k frequency_map_traits_base<T_value>::count_type
>
struct frequency_map_traits_unordered
{
    /// The value type
    typedef T_value                                         value_type;
    /// The count type
    typedef T_count                                         count_type;
    /// The hash type
    typedef STLSOFT_NS_QUAL_STD(hash)<T_value>              hash_type;
    /// The key-equal type
    typedef STLSOFT_NS_QUAL_STD(equal_to)<T_value>          key_equal_type;
    /// The map type
    typedef STLSOFT_NS_QUAL_STD(unordered_map)<
        value_type
    ,   count_type
    ,   hash_type
    ,   key_equal_type
    >                                                       map_type;
    /// The non-mutating (const) reverse iterator type
    typedef void                                            const_reverse_iterator;
};
#endif /* C++11+ */


/** A container that measures the frequencies of the unique elements it
 *    contains.
 *
 * \ingroup group__library__Container
 *
 * \tparam T_value The value type of the container
 * \tparam T_traits The traits type, such as frequency_map_traits_ordered
 *   or frequency_map_traits_unordered
 */
template<
    ss_typename_param_k T_value
,   ss_typename_param_k T_traits = frequency_map_traits_ordered<T_value>
>
class frequency_map
    : public stl_collection_tag
{
private: // types
    typedef ss_typename_type_k T_traits::map_type           map_type_;
public:
    /// This type
    typedef frequency_map<
        T_value
    ,   T_traits
    >                                                       class_type;
    /// The value type
    typedef ss_typename_type_k map_type_::value_type        value_type;
    /// The non-mutating (const) iterator type
    typedef ss_typename_type_k map_type_::const_iterator    const_iterator;
    /// The non-mutating (const) reverse iterator type
    typedef ss_typename_type_k T_traits::const_reverse_iterator
                                                            const_reverse_iterator;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k map_type_::const_reference   const_reference;
    /// The key type
    typedef ss_typename_type_k map_type_::key_type          key_type;
    /// The count type
    typedef ss_typename_type_k T_traits::count_type         count_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The difference type
    typedef ss_ptrdiff_t                                    difference_type;
    /// The boolean type
    typedef ss_bool_t                                       bool_type;

public: // construction
    /// Creates an instance of the map
    frequency_map()
        : m_map()
        , m_total(0)
    {
        STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<count_type>::value);

        STLSOFT_ASSERT(is_valid());
    }

public: // operations
    /// Pushes an entry onto the map
    ///
    /// \param key The record key
    ///
    /// If the entry already exists in the map, its count will be increased
    /// by 1. If it does not previously exist, it will be added with an
    /// initial count of one
    ///
    /// \note <b>Thread-safety</b>: it is strongly exception-safe - if an
    ///   entry cannot be added, the state of the instance will be unchanged
    count_type push(key_type const& key)
    {
        STLSOFT_ASSERT(is_valid());

        count_type r = ++m_map[key];

#if 0
        // NOTE: Because the count type T_count must be an integer, the code above
        // is equivalent to the following "full" exception-safe implementation.
        ss_typename_type_k map_type_::iterator it = m_map.find(key);
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

    /// Pushes an entry onto the map with a count of \c n
    ///
    /// If the entry already exists in the map, its count will be increased
    /// by \c n. If it does not previously exist, it will be added with an
    /// initial count of \c n
    ///
    /// \param key The record key
    /// \param n The number by which to to insert/increase the count
    ///   associated with \c key
    ///
    /// \note <b>Thread-safety</b>: it is strongly exception-safe - if an
    ///   entry cannot be added, the state of the instance will be unchanged
    void push_n(
        key_type const&     key
    ,   count_type          n
    )
    {
        STLSOFT_ASSERT(is_valid());

        m_map[key] += n;

#if 0
        // NOTE: Because the count type T_count must be an integer, the code above
        // is equivalent to the following "full" exception-safe implementation.
        ss_typename_type_k map_type_::iterator it = m_map.find(key);
        if (m_map.end() == it)
        {
            value_type value(key, n);

            m_map.insert(value);
        }
        else
        {
            value_type& value = *it;

            (*it).second += n;
        }
#endif /* 0 */

        m_total += n;

        STLSOFT_ASSERT(is_valid());
    }

    /// Removes all entries from the map
    void clear() STLSOFT_NOEXCEPT
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

        { for (const_iterator i = rhs.begin(); rhs.end() != i; ++i)
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

public: // accessors
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

public: // attributes
    /// Indicates whether the map is empty
    bool_type empty() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.empty();
    }

    /// The number of unique entries in the map
    ///
    /// \remarks This may not be the same as the number of calls to
    ///   <code>push()</code>
    size_type size() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.size();
    }

    /// The number of non-unique entries in the map
    ///
    /// \remarks This may not be the same as the number of calls to
    ///   <code>push()</code>
    count_type total() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        return m_total;
    }

public: // iteration
    /// A non-mutating (const) iterator representing the start of the
    /// sequence
    const_iterator begin() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.begin();
    }
    /// A non-mutating (const) iterator representing the end-point of the
    /// sequence
    const_iterator end() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.end();
    }

    /// A non-mutating (const) iterator representing the start of the
    /// sequence
    const_iterator cbegin() const
    {
        return begin();
    }
    /// A non-mutating (const) iterator representing the end-point of the
    /// sequence
    const_iterator cend() const
    {
        return end();
    }

    /// A non-mutating (const) iterator representing the start of the
    /// reverse sequence
    ///
    /// @note This method will not instantiate when the class template is
    ///  specialised for unordered storage
    const_reverse_iterator rbegin() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.rbegin();
    }
    /// A non-mutating (const) iterator representing the end of the reverse
    /// sequence
    ///
    /// @note This method will not instantiate when the class template is
    ///  specialised for unordered storage
    const_reverse_iterator rend() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_map.rend();
    }

    /// A non-mutating (const) iterator representing the start of the
    /// reverse sequence
    ///
    /// @note This method will not instantiate when the class template is
    ///  specialised for unordered storage
    const_reverse_iterator crbegin() const
    {
        return rbegin();
    }
    /// A non-mutating (const) iterator representing the end of the reverse
    /// sequence
    ///
    /// @note This method will not instantiate when the class template is
    ///  specialised for unordered storage
    const_reverse_iterator crend() const
    {
        return rend();
    }

private: // implementation
    bool is_valid() const STLSOFT_NOEXCEPT
    {
        return m_map.empty() == (0u == m_total);
    }

private: // fields
    map_type_   m_map;
    count_type  m_total;
};


/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template<
    ss_typename_param_k T_value
,   ss_typename_param_k T_traits
>
inline
frequency_map<T_value, T_traits>
operator +(
    frequency_map<T_value, T_traits> const& lhs
,   frequency_map<T_value, T_traits> const& rhs
)
{
    frequency_map<T_value, T_traits> r(lhs);

    r += rhs;

    return r;
}


/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)

template<
    ss_typename_param_k T_value
,   ss_typename_param_k T_traits
>
inline void swap(
    frequency_map<T_value, T_traits>& lhs
,   frequency_map<T_value, T_traits>& rhs
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
        ss_typename_param_k T_value
    ,   ss_typename_param_k T_traits
    >
    inline void swap(
        STLSOFT_NS_QUAL(frequency_map)<T_value, T_traits>& lhs
    ,   STLSOFT_NS_QUAL(frequency_map)<T_value, T_traits>& rhs
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

