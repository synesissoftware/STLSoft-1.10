/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/push_insert_iterator.hpp
 *
 * Purpose:     Push insert iterator for sequence containers.
 *
 * Created:     6th April 2005
 * Updated:     16th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/iterator/push_insert_iterator.hpp
 *
 * \brief [C++] Definition of the stlsoft::push_insert_iterator
 *   class template
 *   (\ref group__library__Iterator "Iterator" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_MAJOR      2
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_MINOR      0
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_REVISION   5
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_EDIT       29
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This iterator adaptor allows for adding elements to a container via a
 * <code>push()</code> method.
 *
 * \ingroup group__library__Iterator
 *
 * It would be used as shown in the following example, which copies all files
 * found in the local directory to the vector of strings:
 *
\code
#include <stlsoft/util/dimensionof.h>

#include <queue>

. . .

std::queue<int>  q;

int const ints[] = {

  -2,
  -1,
  0,
  1,
  +2,
  +3,
};

std::copy(
    &ints[0]
, &ints[0] + dimensionof(ints)
, stlsoft::push_inserter(q)
);
\endcode
 */

template <ss_typename_param_k T_class>
class push_insert_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name member types
/// @{
public:
    /// The container type
    typedef T_class                                         container_type;
    /// This type
    typedef push_insert_iterator<container_type>            class_type;
private:
    typedef class_type                                      insert_iterator_type_;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name construction
/// @{
public:
    ss_explicit_k
    push_insert_iterator(
        container_type& container
    )
        : m_container(&container)
    {}
/// @}

/// \name implementation
/// @{
private:
    class deref_proxy
    {
    public:
        deref_proxy(insert_iterator_type_* it)
            : m_it(it)
        {}

    public:
        template <ss_typename_param_k A>
        void operator =(A const& value)
        {
            m_it->invoke_(value);
        }

    private:
        insert_iterator_type_* const m_it;

    // Not to be implemented
    private:
        void operator =(deref_proxy const&);    // copy-assignment proscribed
    };

    template <ss_typename_param_k A>
    void invoke_(A const& value)
    {
        m_container->push(value);
    }
/// @}

/// \name ouput iterator methods
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

/// \name Members
/// @{
private:
    // sadly, this can't be a reference, because Dinkumware's library does
    // copy-assignment in its type discrimination / debug
    container_type* m_container;
/// @}
};

/** Creator function for push_insert_iterator
 *
 * \ingroup group__library__Iterator
 *
 * \see push_inserter()
 */
template <ss_typename_param_k T_class>
inline
push_insert_iterator<T_class> make_push_insert_iterator(
    T_class& container
)
{
    return push_insert_iterator<T_class>(container);
}

/** Creator function for push_insert_iterator
 *
 * \ingroup group__library__Iterator
 *
 * \see make_push_insert_iterator()
 */
template <ss_typename_param_k T_class>
inline
push_insert_iterator<T_class> push_inserter(
    T_class& container
)
{
    return make_push_insert_iterator(container);
}

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

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */

