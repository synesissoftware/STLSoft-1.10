/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/memory/new_allocator.hpp
 *
 * Purpose:     stlsoft_new_allocator class - use new & delete operators.
 *
 * Created:     2nd January 2001
 * Updated:     30th November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2001-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/memory/new_allocator.hpp
 *
 * \brief [C++] Definition of the stlsoft::new_allocator class
 *   (\ref group__library__Memory "Memory" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_NEW_ALLOCATOR
#define STLSOFT_INCL_STLSOFT_MEMORY_HPP_NEW_ALLOCATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_NEW_ALLOCATOR_MAJOR     4
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_NEW_ALLOCATOR_MINOR     0
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_NEW_ALLOCATOR_REVISION  8
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_NEW_ALLOCATOR_EDIT      95
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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */

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

/** STL Allocator based on operators \c new and \c delete
 *
 * \ingroup group__library__Memory
 *
 * \param T The value_type of the allocator
 */
template <ss_typename_param_k T>
class new_allocator
    : public allocator_base<T, new_allocator<T> >
{
private:
    typedef allocator_base<T, new_allocator<T> >                    parent_class_type;
public:
    /// The parameterisation of the class
    typedef new_allocator<T>                                        class_type;
    /// The value type
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
    /// The pointer type
    typedef ss_typename_type_k parent_class_type::pointer           pointer;
    /// The non-mutating (const) pointer type
    typedef ss_typename_type_k parent_class_type::const_pointer     const_pointer;
    /// The reference type
    typedef ss_typename_type_k parent_class_type::reference         reference;
    /// The non-mutating (const) reference type
    typedef ss_typename_type_k parent_class_type::const_reference   const_reference;
    /// The difference type
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    /// The size type
    typedef ss_typename_type_k parent_class_type::size_type         size_type;

public:
#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
    /// The allocator's <b><code>rebind</code></b> structure
    template <ss_typename_param_k U>
    struct rebind
    {
        typedef new_allocator<U>                                    other;
    };
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */

/// \name Construction
/// @{
public:
    /// Default constructor
    new_allocator() STLSOFT_NOEXCEPT
    {}
    /// Copy constructor
#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
    template <ss_typename_param_k U>
    new_allocator(new_allocator<U> const&)
    {}
#else /* ? STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */
    new_allocator(class_type const&)
    {}
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */
/// @}

private:
    friend class allocator_base<T, new_allocator<T> >;

    void* do_allocate(size_type n, void const* hint)
    {
        STLSOFT_SUPPRESS_UNUSED(hint);

#if defined(new) || \
    defined(delete)
        return new ss_byte_t[n * sizeof(value_type)];
#else /* ? new || delete */
        return ::operator new (n * sizeof(value_type));
#endif /* new || delete */
    }
    void do_deallocate(void* pv, size_type n)
    {
        STLSOFT_SUPPRESS_UNUSED(n);

#if defined(new) || \
    defined(delete)
        delete [] static_cast<ss_byte_t*>(pv);
#else /* ? new || delete */
        ::operator delete (pv);
#endif /* new || delete */
    }
    void do_deallocate(void* pv)
    {
#if defined(new) || \
    defined(delete)
        delete [] static_cast<ss_byte_t*>(pv);
#else /* ? new || delete */
        ::operator delete (pv);
#endif /* new || delete */
    }

private:
//    class_type& operator =(class_type const&);
};



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// Specialisation for void
STLSOFT_TEMPLATE_SPECIALISATION
class new_allocator<void>
{
public:
    typedef void                    value_type;
    typedef new_allocator<void>     class_type;
    typedef void*                   pointer;
    typedef void const*             const_pointer;
    typedef ss_ptrdiff_t            difference_type;
    typedef ss_size_t               size_type;

#ifdef STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT
    /// The allocator <b><code>rebind</code></b> structure
    template <ss_typename_param_k U>
    struct rebind
    {
        typedef new_allocator<U>    other;
    };
#endif /* STLSOFT_CF_ALLOCATOR_REBIND_SUPPORT */
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k T>
inline ss_bool_t operator ==(const new_allocator<T> &/* lhs */, const new_allocator<T> &/* rhs */)
{
    return ss_true_v;
}

template <ss_typename_param_k T>
inline ss_bool_t operator !=(const new_allocator<T> &/* lhs */, const new_allocator<T> &/* rhs */)
{
    return ss_false_v;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_NEW_ALLOCATOR */

/* ///////////////////////////// end of file //////////////////////////// */

