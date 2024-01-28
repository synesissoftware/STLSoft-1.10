/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/associative_eraser_iterator.hpp
 *
 * Purpose:     Eraser iterator for associative containers.
 *
 * Created:     28th January 2005
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


/** \file stlsoft/iterator/associative_eraser_iterator.hpp
 *
 * \brief [C++] Definition of the stlsoft::associative_eraser_iterator
 *   class template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_ASSOCIATIVE_ERASE_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_ASSOCIATIVE_ERASE_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ASSOCIATIVE_ERASE_ITERATOR_MAJOR      1
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ASSOCIATIVE_ERASE_ITERATOR_MINOR      3
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ASSOCIATIVE_ERASE_ITERATOR_REVISION   2
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ASSOCIATIVE_ERASE_ITERATOR_EDIT       27
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
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */

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

/** Iterator class that erases from an associative container an entry, if it
 * exists, that is applied to the dereference operator, and therefore may be
 * used with <code>std::copy()</code> to erase matching elements from a
 * range, as in:
\htmlonly
<pre>
  static char const* contained_strings[] =
  {
    "abc",
    "def",
    "ghi",
    "jkl",
  };

  static char const* erased_strings[] =
  {
    "abc",
    "ghi",
    "mno",
  };

  std::set<std::string>  c;

  // insert some strings

  std::copy(
    contained_strings, contained_strings + dimensionof(contained_strings)
  , std::inserter(c, c.end())
  );

  assert(4 == c.size();

  // now erase some other strings

  std::copy(
    erased_strings, erased_strings + dimensionof(erased_strings)
  , stlsoft::assoc_eraser(c, nullptr, nullptr)
  );

  assert(2 == c.size();
</pre>
\endhtmlonly
 *
 */
template <ss_typename_param_k T_container>
class associative_eraser_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    /// The container type
    typedef T_container                                     container_type;
    /// The value type
    typedef ss_typename_type_k container_type::value_type   value_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// This type
    typedef associative_eraser_iterator<container_type>     class_type;
private:
    typedef class_type                                      erase_iterator_type_;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k
    associative_eraser_iterator(
        container_type& container
    ,   size_type*      hits
    ,   size_type*      misses
    )
        : m_container(&container)
        , m_hits(hits)
        , m_misses(misses)
    {
        STLSOFT_ASSERT(NULL != hits);
        STLSOFT_ASSERT(NULL != misses);

        *m_hits     =   0u;
        *m_misses   =   0u;
    }
/// @}

/// \name Implementation
/// @{
private:
    class deref_proxy
    {
    public:
        deref_proxy(erase_iterator_type_* it)
            : m_it(it)
        {}

    public:
        template <ss_typename_param_k A>
        void operator =(A const& value)
        {
            m_it->invoke_(value);
        }

    private:
        erase_iterator_type_* const m_it;

    // Not to be implemented
    private:
        void operator =(deref_proxy const&);
    };

    template <ss_typename_param_k A>
    void invoke_(A const& value)
    {
        size_type n = m_container->erase(value);

        if (0u == n)
        {
            ++*m_misses;
        }
        else
        {
            *m_hits += n;
        }
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
    size_type*      m_hits;
    size_type*      m_misses;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * creator functions
 */

/** Creator function for associative_eraser_iterator
 */
template <ss_typename_param_k T_container>
inline associative_eraser_iterator<T_container> make_associative_eraser_iterator(
    T_container&  container
,   ss_size_t*    hits    =   NULL
,   ss_size_t*    misses  =   NULL
)
{
    static ss_size_t dummy;

    if (NULL == hits)
    {
        hits = &dummy;
    }
    if (NULL == misses)
    {
        misses = &dummy;
    }

    return associative_eraser_iterator<T_container>(container, hits, misses);
}

/** Creator function for associative_eraser_iterator
 */
template <ss_typename_param_k T_container>
inline associative_eraser_iterator<T_container> assoc_eraser(
    T_container&  container
,   ss_size_t*    hits    =   NULL
,   ss_size_t*    misses  =   NULL
)
{
    static ss_size_t dummy;

    if (NULL == hits)
    {
        hits = &dummy;
    }
    if (NULL == misses)
    {
        misses = &dummy;
    }

    return associative_eraser_iterator<T_container>(container, hits, misses);
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

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_ASSOCIATIVE_ERASE_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */

