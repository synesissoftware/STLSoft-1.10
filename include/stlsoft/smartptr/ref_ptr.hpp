/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/smartptr/ref_ptr.hpp (originally MLRelItf.h, ::SynesisStd)
 *
 * Purpose:     Contains the ref_ptr template class.
 *
 * Created:     2nd November 1994
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1994-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/smartptr/ref_ptr.hpp
 *
 * \brief [C++] Definition of the stlsoft::ref_ptr smart
 *   pointer class template
 *   (\ref group__library__SmartPointer "Smart Pointer" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR
#define STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_REF_PTR_MAJOR      5
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_REF_PTR_MINOR      5
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_REF_PTR_REVISION   1
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_REF_PTR_EDIT       513
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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper shims
 */

/** Control shim for adding a reference on a reference-counted
 *    interface (RCI)
 *
 * \ingroup group__library__SmartPointer
 *
 * \note The generic shim expects the RCI to have a method named AddRef(), which
 * has either no parameters, or has all default parameters
 *
 * \note The behaviour of the ref_ptr is undefined if this method throws an
 * exception
 */
template<ss_typename_param_k I>
inline void add_reference(I* pi)
{
    STLSOFT_ASSERT(NULL != pi);

    pi->AddRef();
}

/** Control shim for releasing a reference on a reference-counted
 *    interface (RCI)
 *
 * \ingroup group__library__SmartPointer
 *
 * \note The generic shim expects the RCI to have a method named Release(), which
 * has either no parameters, or has all default parameters
 *
 * \note The behaviour of the ref_ptr is undefined if this method throws an
 * exception
 */
template<ss_typename_param_k I>
inline void release_reference(I* pi)
{
    STLSOFT_ASSERT(NULL != pi);

    pi->Release();
}

/** Degenerate implementation of instance borrowing, which adds a reference
 * (via the matched add_reference() overload)
 *
 * \ingroup group__library__SmartPointer
 */
template<ss_typename_param_k I>
inline void borrow_reference(I* pi)
{
    STLSOFT_ASSERT(NULL != pi);

    add_reference(pi);
}

/** Degenerate implementation of instance owning, which DOES NOT add a
 * reference, since the default assumption is that instances are created
 * with an initial reference count of 1
 *
 * \ingroup group__library__SmartPointer
 *
 * \note The assumption of initial reference count of 1 is NOT what ATL does
 */
template<ss_typename_param_k I>
inline void own_reference(I* pi)
{
    STLSOFT_ASSERT(NULL != pi);

    STLSOFT_SUPPRESS_UNUSED(pi);
}

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This class provides RAII-safe handling of reference-counted
 *    interfaces (RCIs). Its notable feature is that it supports forward
 *    declaration of the leaf interface so long as the base counting
 *    interface is visible in the scope of the template specialisation.
 *
 * \ingroup group__library__SmartPointer
 *
 * \param T The counted type (i.e. a concrete class)
 * \param I The interface type
 * \param U The upcast intermediate type
 */
template<
    ss_typename_param_k T
,   ss_typename_param_k I = T
,   ss_typename_param_k U = I
>
class ref_ptr
{
public: // types
    /// The Boolean type
    typedef bool_t              bool_type;
    /// The interface type: the type of the RCI (Reference-Counted Interface)
    typedef I                   interface_type;
    /// The counted type: the concrete type of the objects whose instances will be managed
    typedef T                   counted_type;
    /// The up-cast type: the type used to disambiguate upcasts between T and I
    typedef U                   upcast_type;
    /// The current instantiation of the type
    typedef ref_ptr<T, I, U>    class_type;

    /// This to be member-type-compatible with std::auto_ptr
    typedef I                   element_type;
    /// This is to be compatible with the get_invoker component
    typedef counted_type*       resource_type;
    typedef counted_type const* const_resource_type;

private: // implementation
    /// Helper function to effect downcast from interface type to counted type
    static counted_type* c_from_i(interface_type* i)
    {
        return static_cast<counted_type*>(static_cast<upcast_type*>(i));
    }
    /// Helper function to effect downcast from interface type to counted type
    static counted_type const* c_from_i(interface_type const* i)
    {
        return static_cast<counted_type const*>(static_cast<upcast_type const*>(i));
    }
    /// Helper function to effect upcast from counted type to interface type
    static interface_type* i_from_c(counted_type* c)
    {
        return static_cast<upcast_type*>(c);
    }

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1300

    /// Helper function to effect upcast from const counted type to interface type
    static interface_type* i_from_const_c(counted_type const* cc)
    {
        counted_type* c = const_cast<counted_type*>(cc);

        return i_from_c(c);
    }
#endif /* compiler */

public: // construction
    /// Default constructor
    ///
    /// Constructs and empty instance
    ref_ptr()
        : m_pi(NULL)
    {}
    /// Construct from a raw pointer to the counted type, and a boolean that
    /// indicates whether a reference should be taken on the instance.
    ///
    /// \param c Pointer to a counted_type. May be NULL
    /// \param bAddRef parameter that determines whether reference will be
    ///   <i>consumed</i> (<code>false</code>) or <i>borrowed</i>
    ///   (<code>true</code>).
    ///
    /// \note It is usual that ref_ptr is used to "sink" an instance, i.e. to take
    /// ownership of it. In such a case, \c false should be specified as the second
    /// parameter. If, however, a reference is being "borrowed", then \c true should
    /// be specified.
    ///
    /// \deprecated This is now deprecated in favour of the borrow() and own()
    /// creation methods, for the reasons described in
    /// <a href="https://accu.org/index.php/journals/2183" /> and
    /// <a href="https://martinfowler.com/bliki/FlagArgument.html" />.
    ref_ptr(counted_type* c, bool_type bAddRef)
        : m_pi(i_from_c(c))
    {
        if (bAddRef &&
            NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }

    /// Creates a copy of the given ref_ptr instance, and increments the
    /// reference count on its referent object, if any
    ///
    /// \param rhs The instance to copy
    ref_ptr(class_type const& rhs)
        : m_pi(rhs.m_pi)
    {
        if (NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER > 1100

    /// Copy constructs from an instance with different interface and/or
    ///   counted type
    ///
    /// \note The interface types of the copying and copied instance must be
    ///   compatible
    template<
        ss_typename_param_k T2
    ,   ss_typename_param_k I2
    ,   ss_typename_param_k U2
    >
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER == 1300

    ref_ptr(ref_ptr<T2, I2, U2> const& rhs)
#  if 0

        // We cannot use this form, as it would lead to instances with different
        // counted_type being cross cast invisibly. This would be a *very bad thing*
        : m_pi(rhs.m_pi)
#  else /* ? 0 */

        : m_pi(i_from_const_c(rhs.get()))
#  endif /* 0 */
    {
        if (NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }
# else /* ? compiler */

    ref_ptr(ref_ptr<T2, I2, U2>& rhs)
#  if 0
        // We cannot use this form, as it would lead to instances with different
        // counted_type being cross cast invisibly. This would be a *very bad thing*
        : m_pi(rhs.m_pi)
#  else /* ? 0 */
        : m_pi(i_from_c(rhs.get()))
#  endif /* 0 */
    {
        if (NULL != m_pi)
        {
            add_reference(m_pi);
        }
    }
# endif /* compiler */
#endif /* compiler */

    /// Destructor
    ///
    /// If the ref_ptr instance is still holding a pointer to a managed instance,
    /// it will be released.
    ~ref_ptr() STLSOFT_NOEXCEPT
    {
        if (NULL != m_pi)
        {
            release_reference(m_pi);
        }
    }

    /// Copy assignment from a ref_ptr instance of the same type
    ///
    /// \note It is strongly exception-safe, as long as the implementations of the
    /// add-ref and release functions - as utilised in the \c add_reference() and
    /// \c release_reference() control shims - do not throw (which they must not).
    class_type& operator =(class_type const& rhs)
    {
        class_type  t(rhs);

        t.swap(*this);

        return *this;
    }

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    (   _MSC_VER > 1100 && \
        _MSC_VER != 1300)

    /// Copy assignment from an instance of ref_ptr with a different counted_type (but
    /// the same interface type).
    ///
    /// \note This function template uses the copy constructor template, and has the same
    /// instantiation restrictions
    ///
    /// \note It is strongly exception-safe, as long as the implementations of the
    /// add-ref and release functions - as utilised in the \c add_reference() and
    /// \c release_reference() control shims - do not throw (which they must not).
    template<
        ss_typename_param_k T2
    ,   ss_typename_param_k U2
    >
    class_type& operator =(ref_ptr<T2, I, U2>& rhs)
    {
        class_type  t(rhs);

        t.swap(*this);

        return *this;
    }
#endif /* compiler */

    /// Creates an instance by "borrowing" the given pointer to the counted
    /// type, which means that it is assumed that the instance is already
    /// owned
    ///
    /// \param c Pointer to a counted_type. May be nullptr
    template<
        ss_typename_param_k T_borrowedType
    >
    static
    class_type
    borrow(
        T_borrowedType* c
    )
    {
        class_type r;

        if (ss_nullptr_k != c)
        {
            borrow_reference(c);

            r.m_pi = c;
        }

        return r;
    }

    /// Creates an instance by "owning" the given pointer to the counted
    /// type, which means that it is assumed that the instance is not (yet)
    /// owned elsehwere
    ///
    /// \param c Pointer to a counted_type. May be nullptr
    template<
        ss_typename_param_k T_ownedType
    >
    static
    class_type
    own(
        T_ownedType* c
    )
    {
        class_type r;

        if (ss_nullptr_k != c)
        {
            own_reference(c);

            r.m_pi = c;
        }

        return r;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Swaps the managed instance of \c this with \c rhs
    ///
    /// \note It provides the no-throw guarantee
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        interface_type* t           =   rhs.m_pi;
                        rhs.m_pi    =   m_pi;
                        m_pi        =   t;
    }

    /// Assigns a reference-counted type to the smart pointer.
    ///
    /// \param c Pointer to a counted_type. May be NULL
    /// \param bAddRef parameter that determines whether reference will be
    ///   <i>consumed</i> (<code>false</code>) or <i>borrowed</i>
    ///   (<code>true</code>).
    void set(counted_type* c, bool_type bAddRef)
    {
        class_type  t(c, bAddRef);

        t.swap(*this);
    }

    /// Closes the instance, releasing the managed pointer.
    ///
    /// \note Calling this method more than once has no effect.
    void close() STLSOFT_NOEXCEPT
    {
        if (NULL != m_pi)
        {
            release_reference(m_pi);
            m_pi = NULL;
        }
    }

    /// Detaches the managed instance, and returns it to the caller, which
    /// takes responsibility for ensuring that the resource is not leaked
    counted_type* detach() STLSOFT_NOEXCEPT
    {
        counted_type* r = class_type::c_from_i(m_pi);

        m_pi = NULL;

        return r;
    }

public: // equality comparison
    /// Evaluates whether two instances are equal
    bool_type equal(class_type const& rhs) const STLSOFT_NOEXCEPT
    {
        return m_pi == rhs.m_pi;
    }

public: // accessors
    /// Determines whether the instance is empty
    bool_type empty() const STLSOFT_NOEXCEPT
    {
        return NULL == m_pi;
    }

    /// Determines whether the instance is empty
    bool_type operator !() const STLSOFT_NOEXCEPT
    {
        return empty();
    }

    /// Provides raw-pointer access to the instance
    counted_type* get() const STLSOFT_NOEXCEPT
    {
        return class_type::c_from_i(m_pi);
    }

    /// Returns the interface pointer
    ///
    /// \pre The instance must not be empty; otherwise behaviour is
    ///   undefined
    counted_type* operator ->()
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return class_type::c_from_i(m_pi);
    }

    /// Returns the interface pointer
    ///
    /// \pre The instance must not be empty; otherwise behaviour is
    ///   undefined
    counted_type const* operator ->() const
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return class_type::c_from_i(m_pi);
    }

    /// Returns a reference to the managed instance
    ///
    /// \pre The instance must not be empty; otherwise behaviour is
    ///   undefined
    counted_type& operator *()
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return *class_type::c_from_i(m_pi);
    }

    /// Returns a reference to the managed instance
    ///
    /// \pre The instance must not be empty; otherwise behaviour is
    ///   undefined
    counted_type const& operator *() const
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a NULL pointer!", NULL != m_pi);

        return *class_type::c_from_i(m_pi);
    }

private: // fields
    interface_type* m_pi;
};

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template<
    ss_typename_param_k T
,   ss_typename_param_k I
,   ss_typename_param_k U
>
inline
ss_bool_t
operator ==(
    ref_ptr<T, I, U> const& lhs
,   ref_ptr<T, I, U> const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.equal(rhs);
}

template<
    ss_typename_param_k T
,   ss_typename_param_k I
,   ss_typename_param_k U
>
inline
ss_bool_t
operator !=(
    ref_ptr<T, I, U> const& lhs
,   ref_ptr<T, I, U> const& rhs
) STLSOFT_NOEXCEPT
{
    return !lhs.equal(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<
    ss_typename_param_k T
,   ss_typename_param_k I
,   ss_typename_param_k U
>
inline
void
swap(
    ref_ptr<T, I, U>&   lhs
,   ref_ptr<T, I, U>&   rhs
) STLSOFT_NOEXCEPT
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** is_empty shim
 *
 * \ingroup group__library__SmartPointer
 */
template<
    ss_typename_param_k T
,   ss_typename_param_k I /* = T */
,   ss_typename_param_k U /* = I */
>
inline
ss_bool_t
is_empty(
    ref_ptr<T, I, U> const& p
) STLSOFT_NOEXCEPT
{
    return NULL == p.get();
}

/** get_ptr shim
 *
 * \ingroup group__library__SmartPointer
 */
template<
    ss_typename_param_k T
,   ss_typename_param_k I /* = T */
,   ss_typename_param_k U /* = I */
>
inline
T*
get_ptr(
    ref_ptr<T, I, U> const& p
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
,   ss_typename_param_k I /* = T */
,   ss_typename_param_k U /* = I */
>
inline
bool
is_null(
    ref_ptr<T, I, U> const& p
) STLSOFT_NOEXCEPT
{
    return NULL == p.get();
}

/** Insertion operator shim
 *
 * \ingroup group__library__SmartPointer
 *
 * \pre !p.empty()
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k T
,   ss_typename_param_k I /* = T */
,   ss_typename_param_k U /* = I */
>
inline
S&
operator <<(
    S&                      s
,   ref_ptr<T, I, U> const& p
)
{
    STLSOFT_ASSERT(!p.empty());

    return s << *p;
}

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
    ,   ss_typename_param_k I
    ,   ss_typename_param_k U
    >
    inline
    void
    swap(
        STLSOFT_NS_QUAL(ref_ptr)<T, I, U>&  lhs
    ,   STLSOFT_NS_QUAL(ref_ptr)<T, I, U>&  rhs
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

#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

