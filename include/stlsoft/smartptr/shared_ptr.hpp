/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/smartptr/shared_ptr.hpp (originally MLShrPtr.h, ::SynesisStd)
 *
 * Purpose:     Contains the shared_ptr template class.
 *
 * Created:     17th June 2002
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/smartptr/shared_ptr.hpp
 *
 * \brief [C++] Definition of the stlsoft::shared_ptr smart
 *   pointer class template
 *   (\ref group__library__SmartPointer "Smart Pointer" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SHARED_PTR
#define STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SHARED_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SHARED_PTR_MAJOR       3
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SHARED_PTR_MINOR       5
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SHARED_PTR_REVISION    4
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SHARED_PTR_EDIT        60
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

/* /////////////////////////////////////////////////////////////////////////
 * feature detection
 *
 * Thread-safety in shared_ptr is that atomic operations are used in every
 * circumstance except where used on Windows in explicitly single-threaded
 * contexts. In that case, the symbol STLSOFT_SHARED_PTR_SINGLE_THREADED
 * is defined.
 *
 * Also, the symbol STLSOFT_SHARED_PTR_USE_std_atomic may be defined by the
 * user, as well as it being inferred in absence of GCC built-in atomics
 * and Windows' interlocked functions.
 */

#if (   0 ||\
        defined(_WIN32) ||\
        defined(_WIN64) ||\
        0) &&\
    (   0 || \
        defined(STLSOFT_COMPILER_IS_BORLAND) || \
        defined(STLSOFT_COMPILER_IS_DMC) ||\
        defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC) || \
        0) &&\
    (   1 &&\
        !defined(_MT) &&\
        !defined(__MT__) &&\
        1)

# define STLSOFT_SHARED_PTR_SINGLE_THREADED
#endif

/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#if 0
#elif defined(STLSOFT_SHARED_PTR_USE_std_atomic)

# include <atomic>
#elif defined(STLSOFT_SHARED_PTR_SINGLE_THREADED)

#elif defined(STLSOFT_CF_SUPPORT_ATOMIC_GCC_BUILTINS)

# include <stlsoft/internal/atomic/gcc_builtins_.h>
#elif defined(_WIN32) ||\
      defined(_WIN64)

# include <stlsoft/synch/util/windows_api_.h>
#else

# include <atomic>
# define STLSOFT_SHARED_PTR_USE_std_atomic
#endif

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

/** This class enables sharing of arbitrary types.
 *
 * \ingroup group__library__SmartPointer
 *
 * \param T The value type
 */
template<
    ss_typename_param_k T
>
class shared_ptr
{
/// \name Types
/// @{
public:
    /// The value type
    typedef T                                               value_type;
    typedef value_type*                                     pointer;
    typedef value_type const*                               const_pointer;
    typedef value_type&                                     reference;
    typedef value_type const&                               const_reference;
    typedef shared_ptr<T>                                   class_type;

    typedef pointer                                         resource_type;
    typedef const_pointer                                   const_resource_type;
private:
#if 0
#elif defined(_WIN32) ||\
      defined(_WIN64)
    typedef long                                            internal_count_type_;
#else
    // NOTE: for some reason yet to be tracked down, cannot use long with
    // Clang on Mac OSX (as it leads to UB insofar as atomic operations
    // produce random contents - actually appears to manipulate only the low
    // 32-bits, leaving the upper containing sort-of junk)
    typedef ss_sint32_t                                     internal_count_type_;
#endif

#if 0
#elif defined(STLSOFT_SHARED_PTR_USE_std_atomic) &&\
      ( (ATOMIC_LONG_LOCK_FREE > 1) ||\
        (ATOMIC_INT_LOCK_FREE > 1))

    typedef STLSOFT_NS_QUAL_STD(atomic)<
        internal_count_type_
    >                                                       internal_counter_type_;
#else

    typedef internal_count_type_                            internal_counter_type_;
#endif

/// @}

/// \name Construction
/// @{
public:
    shared_ptr()
        : m_p(NULL)
        , m_pc(NULL)
    {
        STLSOFT_ASSERT(is_valid());
    }
    /// Conversion constructor
    ///
    /// \note If exception handling is not enabled and memory cannot be
    ///   acquired to hold the sharing resource the object represented
    ///   by \c p will be deleted, and get() will return \c NULL
    ///
    /// \exception std::bad_alloc If exception support is enabled,
    ///   an instance of <code>std::bad_alloc</code> will be thrown if
    ///   memory cannot be acquired to hold the sharing resource. In this
    ///   case, the object represented by \c p will be deleted
    ss_explicit_k
    shared_ptr(
        T* p
    )
        : m_p(p)
        , m_pc(NULL)
    {
        // This code prevents leaks in the following case:
        //
        //   shared_ptr<Class>  p(new Class());
        //
        // if the count cannot be allocated

        if (NULL != p)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            try
            {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

                m_pc = new internal_counter_type_(1);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            }
            catch(std::bad_alloc&)
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            if (NULL == m_pc)
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            {
                delete m_p;

                m_p = NULL; // benign for X; necessary for NoX

                throw;
            }
        }

        STLSOFT_ASSERT(is_valid());
    }

    /// Copy constructor
    shared_ptr(class_type const& rhs)
        : m_p(rhs.m_p)
        , m_pc(rhs.m_pc)
    {
        STLSOFT_ASSERT(rhs.is_valid());

        if (NULL != m_pc)
        {
            increment_(m_pc);
        }

        STLSOFT_ASSERT(is_valid());
    }

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER > 1200)
    template <ss_typename_param_k T2>
    shared_ptr(shared_ptr<T2> const& rhs)
        : m_p(rhs.m_p)
        , m_pc(rhs.m_pc)
    {
        STLSOFT_ASSERT(rhs.is_valid());

        STLSOFT_ASSERT((NULL == m_p) == (NULL == m_pc));

        if (NULL != m_pc)
        {
            increment_(m_pc);
        }

        STLSOFT_ASSERT(is_valid());
    }
#endif /* member template support? */

    /// Destructor
    ~shared_ptr() STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        STLSOFT_ASSERT((NULL == m_p) == (NULL == m_pc));
        STLSOFT_ASSERT((NULL == m_pc) || (0 < *m_pc));

        if (NULL != m_pc &&
            0 == pre_decrement_(m_pc))
        {
            delete m_p;
            delete m_pc;
        }
    }

    /// Assignment operator
    class_type& operator =(class_type const& rhs)
    {
        STLSOFT_ASSERT(is_valid());

        class_type  this_(rhs);

        this_.swap(*this);

        STLSOFT_ASSERT(is_valid());

        return *this;
    }

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER > 1200)
    template <ss_typename_param_k T2>
    class_type& operator =(shared_ptr<T2> const& rhs)
    {
        STLSOFT_ASSERT(rhs.is_valid());

        STLSOFT_ASSERT(is_valid());

        class_type  this_(rhs);

        this_.swap(*this);

        STLSOFT_ASSERT(is_valid());

        return *this;
    }
#endif /* member template support? */
/// @}

/// \name Operations
/// @{
public:
    /// Releases any managed instance and resets the shared pointer
    /// instance to a default-constructed state
    ///
    /// \exception noexcept
    void close() STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT((NULL == m_p) == (NULL == m_pc));
        STLSOFT_ASSERT((NULL == m_pc) || (0 < *m_pc));

        STLSOFT_ASSERT(is_valid());

        if (NULL != m_pc)
        {
            pointer                 p   =   m_p;
            internal_counter_type_* pc  =   m_pc;

            // Set the members to NULL prior to possibly
            // deleting, in case close() is called on a
            // shared_ptr member which is holding a
            // reference to the enclosing instance.

            m_p     =   NULL;
            m_pc    =   NULL;

            if (0 == pre_decrement_(pc))
            {
                delete p;
                delete pc;
            }
        }

        STLSOFT_ASSERT(is_valid());
    }

#if 1 && !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
    /// Releases any managed instance and resets the shared pointer
    /// instance to a default-constructed state
    ///
    /// \exception noexcept
    void reset()
    {
        close();
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    pointer detach() STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT((NULL == m_p) == (NULL == m_pc));
        STLSOFT_ASSERT((NULL == m_pc) || (0 < *m_pc));

        STLSOFT_ASSERT(is_valid());

        pointer p   =   NULL;

        if (NULL != m_pc)
        {
            if (0 == pre_decrement_(m_pc))
            {
                delete m_pc;

                m_pc = NULL;
            }

            std_swap(p, m_p);
        }

        STLSOFT_ASSERT(is_valid());

        return p;
    }

    /// Swaps entirely the state of two instances
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(rhs.is_valid());

        STLSOFT_ASSERT(is_valid());

        std_swap(m_p, rhs.m_p);
        std_swap(m_pc, rhs.m_pc);

        STLSOFT_ASSERT(is_valid());
    }
/// @}

/// \name Accessors
/// @{
public:
    const_pointer operator ->() const
    {
        STLSOFT_ASSERT(NULL != m_p);
        STLSOFT_ASSERT(is_valid());

        return m_p;
    }
    pointer operator ->()
    {
        STLSOFT_ASSERT(NULL != m_p);
        STLSOFT_ASSERT(is_valid());

        return m_p;
    }

    pointer get() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        return m_p;
    }

    const_reference operator *() const
    {
        STLSOFT_ASSERT(NULL != m_p);
        STLSOFT_ASSERT(is_valid());

        return *m_p;
    }
    reference operator *()
    {
        STLSOFT_ASSERT(NULL != m_p);
        STLSOFT_ASSERT(is_valid());

        return *m_p;
    }
/// @}

/// \name Attributes
/// @{
public:
    /// \see use_count()
    long count() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        return (NULL == m_pc) ? 0 : read_(m_pc);
    }
    /// The number of shared pointer instances managing the same value type
    /// instance
    long use_count() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(is_valid());

        return this->count();
    }
/// @}

/// \name Implementation
/// @{
private:
    static
    void
    increment_(
        internal_counter_type_* p
    )
    {
#if 0
#elif defined(STLSOFT_SHARED_PTR_SINGLE_THREADED)

        ++*p;
#elif defined(STLSOFT_SHARED_PTR_USE_std_atomic)

       STLSOFT_NS_QUAL_STD(atomic_fetch_add)(p, 1);
#elif defined(STLSOFT_CF_SUPPORT_ATOMIC_GCC_BUILTINS)

        STLSOFT_INTERNAL_ATOMIC_GCC_atomic_increment(p);
#elif defined(_WIN32) ||\
      defined(_WIN64)

       InterlockedIncrement(p);
#else

# error Not discriminated
#endif
    }
    static
    internal_count_type_
    pre_decrement_(
        internal_counter_type_* p
    )
    {
#if 0
#elif defined(STLSOFT_SHARED_PTR_SINGLE_THREADED)

        return --*p;
#elif defined(STLSOFT_SHARED_PTR_USE_std_atomic)

        return STLSOFT_NS_QUAL_STD(atomic_fetch_sub)(p, 1) - 1;
#elif defined(STLSOFT_CF_SUPPORT_ATOMIC_GCC_BUILTINS)

        return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_predecrement(p);
#elif defined(_WIN32) ||\
      defined(_WIN64)

       return InterlockedDecrement(p);
#else

# error Not discriminated
#endif
    }
    static
    internal_count_type_
    read_(
        internal_counter_type_* p
    )
    {
#if 0
#elif defined(STLSOFT_SHARED_PTR_SINGLE_THREADED)

        return *p;
#elif defined(STLSOFT_SHARED_PTR_USE_std_atomic)

       return STLSOFT_NS_QUAL_STD(atomic_load)(p);
#elif defined(STLSOFT_CF_SUPPORT_ATOMIC_GCC_BUILTINS)

        return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_read(p);
#elif defined(_WIN32) ||\
      defined(_WIN64)

# ifdef _M_IA64

#  error IA64 not supported
# else

       return *p;
# endif
#else

       return InterlockedDecrement(p);
#endif
    }

    ss_bool_t is_valid() const STLSOFT_NOEXCEPT
    {
        if ((NULL == m_p) != (NULL == m_pc))
        {
            return false;
        }

        if (NULL != m_pc &&
            *m_pc < 1)
        {
            return false;
        }

        return true;
    }
/// @}

/// \name Members
/// @{
private:
    pointer                 m_p;
    internal_counter_type_* m_pc;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<
    ss_typename_param_k T
>
inline
void
swap(
    shared_ptr<T>&  lhs
,   shared_ptr<T>&  rhs
) STLSOFT_NOEXCEPT
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#if !defined(STLSOFT_COMPILER_IS_WATCOM)

/** get_ptr shim
 *
 * \ingroup group__library__SmartPointer
 */
template<
    ss_typename_param_k T
>
inline
T*
get_ptr(
    shared_ptr<T> const& p
) STLSOFT_NOEXCEPT
{
    return p.get();
}

/** is_null shim
 *
 * \ingroup group__library__SmartPointer
 */
template<
    ss_typename_param_k T
>
inline
bool
is_null(
    shared_ptr<T> const& p
) STLSOFT_NOEXCEPT
{
    return NULL == p.get();
}

/** Insertion operator shim
 *
 * \ingroup group__library__SmartPointer
 *
 * \pre NULL != p.get()
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k T
>
inline
S&
operator <<(
    S&                      s
,   shared_ptr<T> const&    p
)
{
    STLSOFT_ASSERT(NULL != p.get());

    return s << *p;
}

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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
    template<
        ss_typename_param_k T
    >
    inline
    void
    swap(
        STLSOFT_NS_QUAL(shared_ptr)<T>& lhs
    ,   STLSOFT_NS_QUAL(shared_ptr)<T>& rhs
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SHARED_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

