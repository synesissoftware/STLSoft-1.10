/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/eraser_iterator.hpp
 *
 * Purpose:     Eraser iterator.
 *
 * Created:     16th June 2010
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/iterator/eraser_iterator.hpp
 *
 * \brief [C++] Definition of the stlsoft::erase_iterator class
 *   template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_ERASER_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_ERASER_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ERASER_ITERATOR_MAJOR     1
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ERASER_ITERATOR_MINOR     0
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ERASER_ITERATOR_REVISION  5
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_ERASER_ITERATOR_EDIT      11
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

#ifndef STLSOFT_INCL_ALGORITHM
# define STLSOFT_INCL_ALGORITHM
# include <algorithm>
#endif /* !STLSOFT_INCL_ALGORITHM */


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
struct ximpl_eraser_iterator_
{
    template<
        ss_typename_param_k C
    ,   ss_typename_param_k A
    >
    struct erase_helper_
    {
    private:
        typedef ss_typename_type_k C::iterator      iterator_type_;
        typedef ss_typename_type_k C::value_type    value_type_;

    private:
        static void erase_(C& container, A const& value, yes_type)
        {
            iterator_type_ i = std::find(container.begin(), container.end(), value);

            if (container.end() != i)
            {
                container.erase(i);
            }
        }
        static void erase_(C& container, A const& value, no_type)
        {
            iterator_type_ i = container.find(value);

            if (container.end() != i)
            {
                container.erase(i);
            }
        }

    public:
        static void erase(C& container, A const& value)
        {
            // Comparing sizes of value type and value passed to erase
            enum { A_PROBABLY_IS_value_type = sizeof(A) == sizeof(value_type_) };

            typedef ss_typename_type_k value_to_yesno_type<A_PROBABLY_IS_value_type>::type  yesno_t_;

            erase_(container, value, yesno_t_());
        }
    };
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

template <ss_typename_param_k C>
class erase_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    /// The container type
    typedef C                                               container_type;
    /// The value type
    typedef ss_typename_type_k container_type::value_type   value_type;
    /// This type
    typedef erase_iterator<container_type>                  class_type;
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
    erase_iterator(container_type& container)
        : m_container(&container)
    {}
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
        STLSOFT_ASSERT(NULL != m_container);

        ximpl_eraser_iterator_::erase_helper_<C, A>::erase(*m_container, value);
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
    // sadly, this can't be a reference, because Dinkumware's library does
    // copy-assignment in its type discrimination / debug
    container_type* m_container;
/// @}
};

/** Creator function for erase_iterator
 *
 * \param container The container whose elements will be erased
 */
template <ss_typename_param_k C>
inline erase_iterator<C> eraser(C& container)
{
    return erase_iterator<C>(container);
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

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_ERASER_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */

