/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/memory/allocator_base.hpp
 *
 * Purpose:     Allocator commmon features.
 *
 * Created:     20th August 2003
 * Updated:     30th November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/memory/allocator_base.hpp
 *
 * \brief [C++] Definition of the stlsoft::allocator_base class
 *  template
 *   (\ref group__library__Memory "Memory" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
#define STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE_MAJOR    4
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE_MINOR    1
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE_REVISION 14
# define STLSOFT_VER_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE_EDIT     63
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

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION
# include <stlsoft/exception/out_of_memory_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES
# include <stlsoft/memory/util/allocator_features.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES */
#ifdef STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD
# ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
#  include <stlsoft/conversion/sap_cast.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */
#endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */
#if defined(STLSOFT_CF_THROW_BAD_ALLOC) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1100)
# include <new>         // for placement new, std::bad_alloc
#endif /* STLSOFT_CF_THROW_BAD_ALLOC || _MSC_VER < 1100) */

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

/** STL Allocator base class adaptor, providing much of the boilerplate
 * functionality of an STL-compliant Allocator class.
 *
 * \param T The allocator value_type
 * \param A The adapted/derived allocator type
 *
 * \ingroup group__library__Memory
 *
 * This class template abstracts away much of the common boilerplate
 * functionality of allocator classes, requiring that a derived type defines
 * only a simple set of non-static member functions:
 *
 * - <code>void* do_allocate(size_type n, void const* hint);</code> - allocates
 *    <code>n</code> bytes, optionally taking into account the locality
 *    <code>hint</code>. Return <code>NULL</code> or throw
 *    <code>std::bad_alloc</code> if the allocation fails.
 * - <code>void do_deallocate(void* pv, size_type n);</code> - deallocates
 *    the memory block pointed to by <code>pv</code>, which is <code>n</code>
 *    bytes in size.
 * - <code>void do_deallocate(void* pv);</code> - deallocates the memory block
 *    pointed to by <code>pv</code>.
 *
 * \see stlsoft::malloc_allocator |
 *      stlsoft::new_allocator |
 *      stlsoft::null_allocator |
 *      comstl::task_allocator |
 *      mfcstl::afx_allocator |
 *      winstl::global_allocator |
 *      winstl::netapi_allocator |
 *      winstl::processheap_allocator |
 *      winstl::shell_allocator
 *
 * \remarks This uses the SCTP/CRTP (Simulated Compile-time Polymorphism / Curiously
 * Recurring Template Pattern) technique, such that derived classes inherit from
 * parameterisations of the adaptor template which specify their fully derived
 * template-id as the first parameter
 *
 * \note By default, an allocation failure results in a thrown std::bad_alloc. If
 * the compiler does not throwing std::bad_alloc by default, this behaviour can be
 * forced by defining STLSOFT_FORCE_ATORS_THROW_BAD_ALLOC. std::bad_alloc can be
 * suppressed in all circumstances by defining STLSOFT_FORCE_ATORS_RETURN_NULL.
 */

template<   ss_typename_param_k T
        ,   ss_typename_param_k A
        >
class allocator_base
{
/// \name Types
/// @{
public:
    /// The value type
    typedef T                                   value_type;
    /// The type of the current parameterisation
    typedef allocator_base<T, A>                class_type;
    /// The pointer type
    typedef value_type*                         pointer;
    /// The non-mutating (const) pointer type
    typedef value_type const*                   const_pointer;
    /// The reference type
    typedef value_type&                         reference;
    /// The non-mutating (const) reference type
    typedef value_type const&                   const_reference;
    /// The difference type
    typedef ss_ptrdiff_t                        difference_type;
    /// The size type
    typedef ss_size_t                           size_type;
private:
    /// The type used in deallocate()
#ifdef STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER
    typedef pointer                             deallocate_pointer;
#else /* ? STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER */
    typedef void*                               deallocate_pointer;
#endif /* STLSOFT_CF_ALLOCATOR_TYPED_DEALLOCATE_POINTER */
private:
#if defined(STLSOFT_CF_COMPILER_SUPPORTS_CRTP)
    typedef A                                   concrete_allocator_type;
#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_CRTP */
    typedef class_type                          concrete_allocator_type;
private:
    virtual void    *do_allocate(size_type n, void const* hint) = 0;
    virtual void    do_deallocate(void* pv, size_type n) = 0;
    virtual void    do_deallocate(void* pv) = 0;
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_CRTP */
/// @}

/// \name Attributes
/// @{
public:
    /// Returns the maximum number of allocatable entities
    size_type max_size() const STLSOFT_NOEXCEPT
    {
        return static_cast<size_type>(-1) / sizeof(value_type);
    }
/// @}

/// \name Conversion functions
/// @{
public:
    /// Returns the address corresponding to the given reference
    ///
    /// \param x A reference to a \c value_type instance whose address will be calculated
    pointer address(reference x) STLSOFT_NOEXCEPT
    {
        return &x;
    }
    /// Returns the address corresponding to the given non-mutable (const) reference
    ///
    /// \param x A non-mutable (const) reference to a \c value_type instance whose address will be calculated
    const_pointer address(const_reference x) const STLSOFT_NOEXCEPT
    {
        return &x;
    }
/// @}

/// \name Allocation
/// @{
public:
    /// Allocates a block of memory sufficient to store \c n elements of type \c value_type
    ///
    /// \param n The number of elements to allocate
    /// \param hint A hint to enhance localisation
    /// \return The allocated block, or the null pointer (if the allocation fails and the
    ///   translator does not support throwing exceptions upon memory exhaustion)
    pointer allocate(size_type n, void const* hint = NULL)
    {
        void* p = static_cast<concrete_allocator_type*>(this)->do_allocate(n, hint);

#if !defined(STLSOFT_FORCE_ATORS_RETURN_NULL) && \
    (   defined(STLSOFT_FORCE_ATORS_THROW_BAD_ALLOC) || \
        defined(STLSOFT_CF_THROW_BAD_ALLOC))
        if (p == NULL)
        {
            STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_STLSoft, STLSoftLibraryIdentifier_Memory));
        }
#endif /* bad_alloc ?  */

        return static_cast<pointer>(p);
    }

#if defined(STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
    /// A method required by the Dinkumware libraries shipped with
    ///   older versions of Visual C++.
    ///
    /// The method is functionally identical to
    ///    <code>static_cast<char*>(allocate(n, NULL))</code>
    ///
    /// \remarks This method is only defined when the symbol
    ///   \ref STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD is defined.
    char* _Charalloc(size_type n)
    {
        return sap_cast<char*>(allocate(n, NULL));
    }
#endif /* STLSOFT_CF_ALLOCATOR_CHARALLOC_METHOD */

    /// Deallocates a pointer
    ///
    /// \param p The memory block to deallocate
    /// \param n The number of blocks to deallocate
    void deallocate(deallocate_pointer p, size_type n)
    {
        static_cast<concrete_allocator_type*>(this)->do_deallocate(p, n * sizeof(value_type));
    }

    /// Deallocates a pointer
    ///
    /// \param p The memory block to deallocate
    void deallocate(deallocate_pointer p)
    {
        static_cast<concrete_allocator_type*>(this)->do_deallocate(p);
    }
/// @}

/// \name Object initialisation
/// @{
public:
    /// In-place constructs an instance of the \c value_type, with the given value
    ///
    /// \param p The location in which to construct the instance
    /// \param x The value with which to copy construct the instance
    void construct(pointer p, value_type const& x)
    {
        STLSOFT_ASSERT(NULL != p);

        new(p) value_type(x);
    }

    /// In-place constructs an instance of the \c value_type
    ///
    /// \param p The location in which to construct the instance
    void construct(pointer p)
    {
        STLSOFT_ASSERT(NULL != p);

        new(p) value_type();
    }

    /// In-place destroys an instance
    ///
    /// \param p The instance whose destructor is to be called
    void destroy(pointer p) STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != p);

        STLSOFT_DESTROY_INSTANCE(T, value_type, p);
    }
/// @}

/// \name Not to be implemented
/// @{
private:
//    class_type const& operator =(class_type const& rhs);
/// @}
};

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

#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */

/* ///////////////////////////// end of file //////////////////////////// */

