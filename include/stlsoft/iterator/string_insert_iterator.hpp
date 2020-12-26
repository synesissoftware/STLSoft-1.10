/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/string_insert_iterator.hpp
 *
 * Purpose:     Insert iterator for elements that can be expressed in string
 *              form via string access shims.
 *
 * Created:     6th April 2005
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/iterator/string_insert_iterator.hpp
 *
 * \brief [C++] Definition of the stlsoft::string_insert_iterator
 *   class template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_STRING_INSERT_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_STRING_INSERT_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_STRING_INSERT_ITERATOR_MAJOR      2
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_STRING_INSERT_ITERATOR_MINOR      0
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_STRING_INSERT_ITERATOR_REVISION   7
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_STRING_INSERT_ITERATOR_EDIT       30
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
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

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

template <ss_typename_param_k T_container>
class string_insert_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    /// The container type
    typedef T_container                                     container_type;
    /// This type
    typedef string_insert_iterator<container_type>          class_type;
private:
    typedef ss_typename_type_k container_type::value_type   string_type_;
    typedef class_type                                      insert_iterator_type_;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k
    string_insert_iterator(
        container_type& container
    )
        : m_container(&container)
    {}
/// @}

/// \name Implementation
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
        void operator =(deref_proxy const&);
    };

    template <ss_typename_param_k A>
    void invoke_(A const& value)
    {
        STLSOFT_ASSERT(NULL != m_container);

        m_container->insert(string_type_(stlsoft::c_str_data(value), stlsoft::c_str_len(value)));
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

/// \name Members
/// @{
private:
    container_type* m_container;
/// @}
};

/** Creator function for string_insert_iterator
 */
template <ss_typename_param_k T_container>
inline
string_insert_iterator<T_container>
make_string_insert_iterator(
    T_container& container
)
{
    return string_insert_iterator<T_container>(container);
}

/** Creator function for string_insert_iterator
 */
template <ss_typename_param_k T_container>
inline
string_insert_iterator<T_container>
string_inserter(
    T_container& container
)
{
    return make_string_insert_iterator(container);
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

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_STRING_INSERT_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */

