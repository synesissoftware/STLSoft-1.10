/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/smartptr/proxy_ptr.hpp
 *
 * Purpose:     Contains the proxy_ptr template class.
 *
 * Created:     17th January 1999
 * Updated:     20th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1999-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/smartptr/proxy_ptr.hpp
 *
 * \brief [C++] Definition of the stlsoft::proxy_ptr smart
 *   pointer class template
 *   (\ref group__library__SmartPointer "Smart Pointer" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PROXY_PTR
#define STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PROXY_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PROXY_PTR_MAJOR       5
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PROXY_PTR_MINOR       2
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PROXY_PTR_REVISION    1
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_PROXY_PTR_EDIT        86
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
 * classes
 */

// class proxy_ptr
/** This class emulates a pointer in all respects, and is useful as
 *    a generic code testing tool, and is simply an aid to
 *    self-documentation.
 *
 * \ingroup group__library__SmartPointer
 *
 * \param T The value type
 */
template <ss_typename_param_k T>
class proxy_ptr
{
public:
    /// The value type
    typedef T                       value_type;
    /// The current specialisation of the type
    typedef proxy_ptr<T>            class_type;

    typedef value_type*             resource_type;
    typedef value_type const*       const_resource_type;

// Construction
public:
    /// Construct from a pointer to "borrow"
    ss_explicit_k proxy_ptr(value_type *t)
        : m_value(t)
    {}
    /// Assignment from a new pointer
    proxy_ptr& operator =(value_type *t)
    {
        m_value = t;

        return *this;
    }

// Conversion
public:
    /// Implicit conversion to pointer to the underlying pointer
    operator value_type *()
    {
        return m_value;
    }
    /// Implicit conversion to pointer-to-const to the underlying pointer
    operator value_type const* () const
    {
        return m_value;
    }

    /// Indirection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type& operator *() // indirection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return *m_value;
    }
    /// Indirection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type const& operator *() const // indirection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return *m_value;
    }
    /// Member-selection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type* operator ->() // member-selection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return m_value;
    }
    /// Member-selection operator
    ///
    /// \note This method does a debug-time assertion that the underlying pointer is non-null
    value_type const* operator ->() const // member-selection
    {
        STLSOFT_MESSAGE_ASSERT("Dereferencing a null pointer!", NULL != m_value);

        return m_value;
    }

    /// Returns the underlying pointer value
    ///
    /// \deprecated This function will be removed in a future release. Users
    ///   should instead invoke get()
    value_type* get_ptr() const STLSOFT_NOEXCEPT
    {
        return get();
    }

    /// Returns the underlying pointer value
    value_type* get() const STLSOFT_NOEXCEPT
    {
        return m_value;
    }

    /// Returns the underlying pointer value
    ///
    /// \deprecated This method will be removed in a future version
    value_type* GetPointer() const STLSOFT_NOEXCEPT
    {
        return m_value;
    }

    /// Sets the underlying pointer value to null
    void clear() STLSOFT_NOEXCEPT
    {
        m_value = NULL;
    }

// Members
private:
    value_type  *m_value;
};


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** get_ptr shim
 *
 * \ingroup group__library__SmartPointer
 */
template <ss_typename_param_k T>
inline
T*
get_ptr(
    proxy_ptr<T> const& p
) STLSOFT_NOEXCEPT
{
    return p.get();
}

/** is_null shim
 *
 * \ingroup group__library__SmartPointer
 */
template <ss_typename_param_k T>
inline
bool
is_null(
    proxy_ptr<T> const& p
) STLSOFT_NOEXCEPT
{
    return NULL == p.get();
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_PROXY_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

