/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/containers/pod_vector.hpp
 *
 * Purpose:     Contains the pod_vector class.
 *
 * Created:     23rd December 2003
 * Updated:     28th January 2024
 *
 * Thanks to:   Chris Newcombe for requesting sufficient enhancements to
 *              auto_buffer such that pod_vector was born.
 *
 *              Christian Roessel, for spotting the bug in the copy ctor that
 *              fails an assert if the copied instance is empty
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/containers/pod_vector.hpp
 *
 * \brief [C++] Definition of the stlsoft::pod_vector container class
 *   template
 *   (\ref group__library__Container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_POD_VECTOR
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_POD_VECTOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_POD_VECTOR_MAJOR       4
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_POD_VECTOR_MINOR       3
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_POD_VECTOR_REVISION    2
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_POD_VECTOR_EDIT        97
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
# error stlsoft/containers/pod_vector.hpp is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD
# include <stlsoft/algorithms/pod.hpp>          // for pod_copy_n(), etc.
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_POD */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>                            // for std::out_of_range
#endif /* !STLSOFT_INCL_STDEXCEPT */

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

/** Efficient vector class for use with POD types only
 *
 * \ingroup group__library__Container
 */
template <
    ss_typename_param_k T_value
#if defined(STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT) && \
    defined(STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT)
,   ss_typename_param_k T_allocator         =   ss_typename_type_def_k allocator_selector<T_value>::allocator_type
,   ss_size_t           V_internalSize      =   64
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT && STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT */
,   ss_typename_param_k T_allocator      /* =   ss_typename_type_def_k STLSOFT_NS_QUAL(allocator_selector)<T_value>::allocator_type */
,   ss_size_t           V_internalSize   /* =   64 */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT && STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT */
>
class pod_vector
    : public stl_collection_tag
{
/// \name Typedefs
/// @{
private:
    typedef auto_buffer_old<
        T_value
    ,   T_allocator
    ,   V_internalSize
    >                                                       buffer_type_;
public:
    /// The value type
    typedef ss_typename_type_k buffer_type_::value_type     value_type;
    /// The allocator type
    typedef ss_typename_type_k buffer_type_::allocator_type allocator_type;
    /// The current specialisation of the type
    typedef pod_vector<
        T_value
    ,   T_allocator
    ,   V_internalSize
    >                                                       class_type;
    /// The reference type
    typedef ss_typename_type_k buffer_type_::reference      reference;
    /// The non-mutable (const) reference type
    typedef ss_typename_type_k buffer_type_::const_reference
                                                            const_reference;
    /// The pointer type
    typedef ss_typename_type_k buffer_type_::pointer        pointer;
    /// The non-mutable (const) pointer type
    typedef ss_typename_type_k buffer_type_::const_pointer  const_pointer;
    /// The iterator type
    typedef ss_typename_type_k buffer_type_::iterator       iterator;
    /// The non-mutable (const) iterator type
    typedef ss_typename_type_k buffer_type_::const_iterator const_iterator;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The type of the non-const (mutating) reverse iterator
    typedef ss_typename_type_k buffer_type_::reverse_iterator
                                                            reverse_iterator;
    /// The type of the const (non-mutating) reverse iterator
    typedef ss_typename_type_k buffer_type_::const_reverse_iterator
                                                            const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    /// The size type
    typedef ss_typename_type_k buffer_type_::size_type      size_type;
    /// The difference type
    typedef ss_typename_type_k buffer_type_::difference_type
                                                            difference_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k pod_vector(size_type cItems = 0);
    pod_vector(size_type cItems, value_type const& value);
    pod_vector(class_type const& rhs);
    pod_vector(const_iterator first, const_iterator last);

    pod_vector& operator =(class_type const& rhs);
/// @}

/// \name Iteration
/// @{
public:
    iterator                begin();
    const_iterator          begin() const;
    iterator                end();
    const_iterator          end() const;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Attributes
/// @{
public:
    size_type       size() const;
    size_type       capacity() const;
    size_type       max_size() const;
    ss_bool_t       empty() const;
    allocator_type  get_allocator() const;
/// @}

/// \name Accessors
/// @{
public:
    reference       at(size_type index);
    const_reference at(size_type index) const;
    reference       operator [](size_type index);
    const_reference operator [](size_type index) const;
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;
/// @}

/// \name Operations
/// @{
public:
    void        clear();
    void        swap(class_type& rhs);
    void        reserve(size_type cItems) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */;
// NOTE: resize() is split into two, so the one-param version can be very quick
    void        resize(size_type cItems) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */;
    void        resize(size_type cItems, value_type const& value) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */;
    void        push_back(value_type const& value);
    void        pop_back();

    void        assign(const_iterator first, const_iterator last);
    void        assign(size_type cItems, value_type const& value = value_type());
    iterator    insert(iterator it, value_type const& value = value_type());
    void        insert(iterator it, size_type cItems, value_type const& value);
    void        insert(iterator it, const_iterator first, const_iterator last);
    iterator    erase(iterator it);
    iterator    erase(iterator first, iterator last);
/// @}

/// \name Implementation
/// @{
private:
    pointer         begin_();
    const_pointer   begin_() const;

    void        range_check_(size_type index) const /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(out_of_range) ) */;

    ss_bool_t   resize_(size_type cItems) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */;

    ss_bool_t   is_valid_() const;
/// @}

/// \name Members
/// @{
private:
    size_type       m_cItems;   // A size member is used, rather than m_end (iterator), because some of the state
                                // is maintained in the parent class. Doing it this way makes swap() and other methods
                                // very simple.
    buffer_type_    m_buffer;   // The auto_buffer
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_bool_t
operator ==(
    pod_vector<T_value, T_allocator, V_internalSize> const& lhs
,   pod_vector<T_value, T_allocator, V_internalSize> const& rhs
)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    else
    {
#if 0
        for (ss_typename_type_k pod_vector<T_value, T_allocator, V_internalSize>::size_type i = 0, size = lhs.size(); i < size; ++i)
        {
            if (lhs[i] != rhs[i])
            {
                return false;
            }
        }

        return true;
#else /* ? 0 */
        return 0 == memcmp(&lhs[0], &rhs[0], sizeof(ss_typename_type_k pod_vector<T_value, T_allocator, V_internalSize>::size_type) * lhs.size());
#endif /* 0 */
    }
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_bool_t
operator !=(
    pod_vector<T_value, T_allocator, V_internalSize> const& lhs
,   pod_vector<T_value, T_allocator, V_internalSize> const& rhs
)
{
    return !operator ==(lhs, rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
swap(
    pod_vector<T_value, T_allocator, V_internalSize>&   lhs
,   pod_vector<T_value, T_allocator, V_internalSize>&   rhs
)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1310
#  define STLSOFT_CF_FUNCTION_SIGNATURE_FULL_ARG_QUALIFICATION_REQUIRED_EXCEPT_ARGS
# endif /* compiler */

# if 0 || \
     defined(STLSOFT_CF_FUNCTION_SIGNATURE_FULL_ARG_QUALIFICATION_REQUIRED) || \
     0

#  define STLSOFT_pod_vector_pt_(pt)                        ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::pt
# else

#  define STLSOFT_pod_vector_pt_(pt)                        pt
# endif

# if 0 || \
     defined(STLSOFT_CF_FUNCTION_SIGNATURE_FULL_ARG_QUALIFICATION_REQUIRED) || \
     defined(STLSOFT_CF_FUNCTION_SIGNATURE_FULL_ARG_QUALIFICATION_REQUIRED_EXCEPT_ARGS) || \
     0

#  define STLSOFT_pod_vector_rt_(qrt, rrt)                  ss_typename_type_k pod_vector<T_value, T_allocator, V_internalSize>::qrt
# else

#  define STLSOFT_pod_vector_rt_(qrt, rrt)                  rrt
# endif


template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::pointer
pod_vector<T_value, T_allocator, V_internalSize>::begin_()
{
    return m_buffer.data();
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::const_pointer
pod_vector<T_value, T_allocator, V_internalSize>::begin_() const
{
    return m_buffer.data();
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::range_check_(
    STLSOFT_pod_vector_pt_(size_type) index
) const /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(out_of_range) ) */
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    if (!(index < size()))
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(out_of_range)("pod vector index out of range"));
    }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

    STLSOFT_MESSAGE_ASSERT("pod vector index out of range", index < size());
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_bool_t
pod_vector<T_value, T_allocator, V_internalSize>::resize_(
    STLSOFT_pod_vector_pt_(size_type) cItems
) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */
{
    // This method is only called for insertions, so we can make some assumptions.

    size_type   curr_capacity   =   capacity();

    // We only resize the internal buffer if it is not large enough
    if (cItems > curr_capacity)
    {
        size_type   capacity = m_buffer.internal_size() + cItems;

        capacity -= capacity % m_buffer.internal_size();

        if (!m_buffer.resize(capacity))
        {
            return false;
        }
    }

    m_cItems = cItems;

    return true;
}


template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_bool_t
pod_vector<T_value, T_allocator, V_internalSize>::is_valid_() const
{
    if (m_buffer.size() < m_cItems)
    {
        return false;
    }

    return true;
}


// Construction

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
/* ss_explicit_k */
pod_vector<T_value, T_allocator, V_internalSize>::pod_vector(
    STLSOFT_pod_vector_pt_(size_type) cItems /* = 0 */
)
    : m_buffer(cItems)
{
    m_cItems = m_buffer.size(); // This is done here, since it comes before m_buffer in
                                // the object layout for efficiency (caching) reasons

    pod_fill_n(begin_(), size(), value_type());

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
pod_vector<T_value, T_allocator, V_internalSize>::pod_vector(
    STLSOFT_pod_vector_pt_(size_type)           cItems
,   STLSOFT_pod_vector_pt_(value_type) const&   value
)
    : m_buffer(cItems)
{
    m_cItems = m_buffer.size(); // This is done here, since it comes before m_buffer in
                                // the object layout for efficiency (caching) reasons

    pod_fill_n(begin_(), size(), value);

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
pod_vector<T_value, T_allocator, V_internalSize>::pod_vector(
    STLSOFT_pod_vector_pt_(class_type) const& rhs
)
    : m_buffer(rhs.size())
{
    m_cItems = m_buffer.size(); // This is done here, since it comes before m_buffer in
                                // the object layout for efficiency (caching) reasons

    pod_copy_n(begin_(), rhs.begin_(), size());

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
pod_vector<T_value, T_allocator, V_internalSize>::pod_vector(
    STLSOFT_pod_vector_pt_(const_iterator)  first
,   STLSOFT_pod_vector_pt_(const_iterator)  last
)
    : m_buffer(static_cast<ss_size_t>(last - first))
{
    m_cItems = m_buffer.size(); // This is done here, since it comes before m_buffer in
                                // the object layout for efficiency (caching) reasons

    if (0 != size()) // It will either be the full size requested, or 0
    {
        pod_copy(&*first, &*last, begin_());
    }

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
pod_vector<T_value, T_allocator, V_internalSize>&
pod_vector<T_value, T_allocator, V_internalSize>::operator =(
    STLSOFT_pod_vector_pt_(class_type) const& rhs
)
{
// NOTE: This will be optimised by testing the contents of this and the rhs

    STLSOFT_ASSERT(is_valid_());

    class_type  temp(rhs);

    temp.swap(*this);

    STLSOFT_ASSERT(is_valid_());

    return *this;
}

// Iteration


template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::iterator
pod_vector<T_value, T_allocator, V_internalSize>::begin()
{
    STLSOFT_ASSERT(is_valid_());

    return m_buffer.begin();
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::const_iterator
pod_vector<T_value, T_allocator, V_internalSize>::begin() const
{
    STLSOFT_ASSERT(is_valid_());

    return m_buffer.begin();
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::iterator
pod_vector<T_value, T_allocator, V_internalSize>::end()
{
    STLSOFT_ASSERT(is_valid_());

    return &begin_()[size()];
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::const_iterator
pod_vector<T_value, T_allocator, V_internalSize>::end() const
{
    STLSOFT_ASSERT(is_valid_());

    return &begin_()[size()];
}

#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::reverse_iterator
pod_vector<T_value, T_allocator, V_internalSize>::rbegin()
{
    STLSOFT_ASSERT(is_valid_());

    return reverse_iterator(end());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::const_reverse_iterator
pod_vector<T_value, T_allocator, V_internalSize>::rbegin() const
{
    STLSOFT_ASSERT(is_valid_());

    return const_reverse_iterator(end());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::reverse_iterator
pod_vector<T_value, T_allocator, V_internalSize>::rend()
{
    STLSOFT_ASSERT(is_valid_());

    return reverse_iterator(begin());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::const_reverse_iterator
pod_vector<T_value, T_allocator, V_internalSize>::rend() const
{
    STLSOFT_ASSERT(is_valid_());

    return const_reverse_iterator(begin());
}
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

// Attributes

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(size_type, ss_size_t)
pod_vector<T_value, T_allocator, V_internalSize>::size() const
{
    STLSOFT_ASSERT(is_valid_());

    return m_cItems;
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(size_type, ss_size_t)
pod_vector<T_value, T_allocator, V_internalSize>::capacity() const
{
    STLSOFT_ASSERT(is_valid_());

    return m_buffer.size();
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(size_type, ss_size_t)
pod_vector<T_value, T_allocator, V_internalSize>::max_size() const
{
    STLSOFT_ASSERT(is_valid_());

    return static_cast<size_type>(-1) / sizeof(value_type);
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_bool_t
pod_vector<T_value, T_allocator, V_internalSize>::empty() const
{
    STLSOFT_ASSERT(is_valid_());

    return 0 == size();
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::allocator_type
pod_vector<T_value, T_allocator, V_internalSize>::get_allocator() const
{
    STLSOFT_ASSERT(is_valid_());

    return m_buffer.get_allocator();
}

// Accessors
template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(reference, T_value&)
pod_vector<T_value, T_allocator, V_internalSize>::at(
    STLSOFT_pod_vector_pt_(size_type) index
)
{
    STLSOFT_ASSERT(is_valid_());

    range_check_(index);

    STLSOFT_ASSERT(is_valid_());

    return begin_()[index];
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(const_reference, T_value const&)
pod_vector<T_value, T_allocator, V_internalSize>::at(
    STLSOFT_pod_vector_pt_(size_type) index
) const
{
    STLSOFT_ASSERT(is_valid_());

    range_check_(index);

    STLSOFT_ASSERT(is_valid_());

    return begin_()[index];
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(reference, T_value&)
pod_vector<T_value, T_allocator, V_internalSize>::operator [](
    STLSOFT_pod_vector_pt_(size_type) index
)
{
    STLSOFT_ASSERT(is_valid_());

    // The index must be <= the size(). It is allowed to be equal to the size because
    // we must facilitate the taking of the end() element in order to specify ranges.
    STLSOFT_MESSAGE_ASSERT("requested index is out of range", !(size() < index));

    return begin_()[index];
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(const_reference, T_value const&)
pod_vector<T_value, T_allocator, V_internalSize>::operator [](
    STLSOFT_pod_vector_pt_(size_type) index
) const
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_MESSAGE_ASSERT("requested index is out of range", index < size());

    return begin_()[index];
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(reference, T_value&)
pod_vector<T_value, T_allocator, V_internalSize>::front()
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_MESSAGE_ASSERT("Range is empty!", 0 != size());

    return begin_()[0];
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(const_reference, T_value const&)
pod_vector<T_value, T_allocator, V_internalSize>::front() const
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_MESSAGE_ASSERT("Range is empty!", 0 != size());

    return begin_()[0];
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(reference, T_value&)
pod_vector<T_value, T_allocator, V_internalSize>::back()
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_MESSAGE_ASSERT("Range is empty!", 0 != size());

    return begin_()[size() - 1];
}


template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
STLSOFT_pod_vector_rt_(const_reference, T_value const&)
pod_vector<T_value, T_allocator, V_internalSize>::back() const
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_MESSAGE_ASSERT("Range is empty!", 0 != size());

    return begin_()[size() - 1];
}

// Operations

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::clear()
{
    STLSOFT_ASSERT(is_valid_());

    if (m_buffer.resize(0))
    {
        m_cItems = 0;
    }

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::swap(
    pod_vector<T_value, T_allocator, V_internalSize>& rhs
)
{
    STLSOFT_ASSERT(is_valid_());

    m_buffer.swap(rhs.m_buffer);
    std_swap(m_cItems, rhs.m_cItems);

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::reserve(
    STLSOFT_pod_vector_pt_(size_type) cItems
) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */
{
    STLSOFT_ASSERT(is_valid_());

    // We do not follow vector's much maligned example and refuse to truncate, although
    // we only do so if the requested size is 0.
    if (0 == cItems ||
        cItems > size())
    {
        m_buffer.resize(cItems);
    }

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::resize(
    STLSOFT_pod_vector_pt_(size_type) cItems
) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */
{
    STLSOFT_ASSERT(is_valid_());

    resize(cItems, value_type());

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::resize(
    STLSOFT_pod_vector_pt_(size_type)           cItems
,   STLSOFT_pod_vector_pt_(value_type) const&   value
) /* stlsoft_throw_1(STLSOFT_NS_QUAL_STD(bad_alloc) ) */
{
    STLSOFT_ASSERT(is_valid_());

    if (m_buffer.resize(cItems))
    {
        if (m_cItems < cItems)
        {
            pod_fill_n(begin_() + m_cItems, cItems - m_cItems, value);
        }

        m_cItems = cItems;
    }

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::push_back(
    STLSOFT_pod_vector_pt_(value_type) const& value
)
{
    STLSOFT_ASSERT(is_valid_());

    insert(end(), value);

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::pop_back()
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_MESSAGE_ASSERT("No elements to pop", size() > 0);

    if (0 == --m_cItems)
    {
        m_buffer.resize(0);
    }

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::assign(
    STLSOFT_pod_vector_pt_(const_iterator)  first
,   STLSOFT_pod_vector_pt_(const_iterator)  last
)
{
    STLSOFT_ASSERT(is_valid_());

// NOTE: This will be optimised by testing the contents of this and the rhs

    class_type temp(first, last);

    temp.swap(*this);

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::assign(
    STLSOFT_pod_vector_pt_(size_type)           cItems
,   STLSOFT_pod_vector_pt_(value_type) const&   value /* = value_type() */
)
{
    STLSOFT_ASSERT(is_valid_());

// NOTE: This will be optimised by testing the contents of this and the rhs

    class_type  temp(cItems, value);

    temp.swap(*this);

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::iterator
pod_vector<T_value, T_allocator, V_internalSize>::insert(
    STLSOFT_pod_vector_pt_(iterator)            it
,   STLSOFT_pod_vector_pt_(value_type) const&   value /* = value_type() */
)
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_ASSERT(!(end() < it));
    STLSOFT_ASSERT(!(it < begin()));

    size_type   index = static_cast<size_type>(it - begin());

    insert(it, 1, value);

    STLSOFT_ASSERT(is_valid_());

    return begin() + index;
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::insert(
    STLSOFT_pod_vector_pt_(iterator)            it
,   STLSOFT_pod_vector_pt_(size_type)           cItems
,   STLSOFT_pod_vector_pt_(value_type) const&   value
)
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_ASSERT(!(end() < it));
    STLSOFT_ASSERT(!(it < begin()));

    size_type   curr_size   =   size();
    size_type   index       =   static_cast<size_type>(it - begin());

    if (resize_(size() + cItems))
    {
        size_type cMove = curr_size - index;

        // The resize_ may have invalidated the iterator(s)!!
        it = begin() + index;

        // Move the existing ones up out of the way
        pod_move_n(&it[cItems], &it[0], cMove);

        // And insert the new ones
        pod_fill_n(begin_() + index, cItems, value);
    }

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
void
pod_vector<T_value, T_allocator, V_internalSize>::insert(
    STLSOFT_pod_vector_pt_(iterator)        it
,   STLSOFT_pod_vector_pt_(const_iterator)  first
,   STLSOFT_pod_vector_pt_(const_iterator)  last
)
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_ASSERT(!(end() < it));
    STLSOFT_ASSERT(!(it < begin()));

    size_type   curr_size   =   size();
    size_type   index       =   it - begin();
    size_type   cItems      =   last - first;

    if (resize_(size() + cItems))
    {
        size_type cMove = curr_size - index;

        // The resize_ may have invalidated the iterator(s)!!
        it = begin() + index;

        // Move the existing ones up out of the way
        pod_move_n(&it[cItems], &it[0], cMove);

        // And insert the new ones
        pod_copy_n(it, first, cItems);
    }

    STLSOFT_ASSERT(is_valid_());
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::iterator
pod_vector<T_value, T_allocator, V_internalSize>::erase(
    STLSOFT_pod_vector_pt_(iterator) it
)
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_ASSERT(it < end());
    STLSOFT_ASSERT(!(it < begin()));

    size_type   index = it - begin();
    size_type   cMove = size() - (index + 1);

    pod_move_n(&it[0], &it[1], cMove);

    if (0 == --m_cItems)
    {
        m_buffer.resize(0);

        it = begin();
    }

    STLSOFT_ASSERT(is_valid_());

    return it;
}

template <
    ss_typename_param_k T_value
,   ss_typename_param_k T_allocator
,   ss_size_t           V_internalSize
>
inline
ss_typename_type_ret_k pod_vector<T_value, T_allocator, V_internalSize>::iterator
pod_vector<T_value, T_allocator, V_internalSize>::erase(
    STLSOFT_pod_vector_pt_(iterator)    first
,   STLSOFT_pod_vector_pt_(iterator)    last
)
{
    STLSOFT_ASSERT(is_valid_());

    STLSOFT_ASSERT(first <= end());
    STLSOFT_ASSERT(!(first < begin()));
    STLSOFT_ASSERT(!(end() < last));
    STLSOFT_ASSERT(!(last < begin()));

    size_type   curr_size   =   size();
    size_type   index_first =   first - begin();
    size_type   index_last  =   last - begin();
    size_type   cItems      =   last - first;
    size_type   cMove       =   curr_size - index_last;

    // Move the remaining ones down
    pod_move_n(&first[0], &last[0], cMove);

    resize(curr_size - cItems);

    STLSOFT_ASSERT(is_valid_());

    return begin() + index_first;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template <
        ss_typename_param_k         T_value
    ,   ss_typename_param_k         T_allocator
    ,   STLSOFT_NS_QUAL(ss_size_t)  V_internalSize
    >
    inline
    void
    swap(
        STLSOFT_NS_QUAL(pod_vector)<T_value, T_allocator, V_internalSize>&  lhs
    ,   STLSOFT_NS_QUAL(pod_vector)<T_value, T_allocator, V_internalSize>&  rhs
    )
    {
        lhs.swap(rhs);
    }
} /* namespace std */
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_POD_VECTOR */

/* ///////////////////////////// end of file //////////////////////////// */

