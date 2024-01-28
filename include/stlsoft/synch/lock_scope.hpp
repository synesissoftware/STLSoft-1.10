/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/synch/lock_scope.hpp (originally MLLock.h, ::SynesisStd)
 *
 * Purpose:     Synchronisation object lock scoping class.
 *
 * Created:     1st October 1994
 * Updated:     20th January 2024
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


/** \file stlsoft/synch/lock_scope.hpp
 *
 * \brief [C++] Definition of the stlsoft::lock_scope class template
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_LOCK_SCOPE
#define STLSOFT_INCL_STLSOFT_SYNCH_HPP_LOCK_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_LOCK_SCOPE_MAJOR     6
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_LOCK_SCOPE_MINOR     0
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_LOCK_SCOPE_REVISION  6
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_LOCK_SCOPE_EDIT      126
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

// class lock_traits

/** Traits class for lockable objects
 *
 * \ingroup group__library__Synch
 *
 * \param L The lockable class
 */
template<ss_typename_param_k L>
struct lock_traits
{
/// \name Member Types
/// @{
public:
    /// The lockable type
    typedef L                                               lock_type;
    /// The current specialisation of the type
    typedef lock_traits<L>                                  class_type;
/// @}

/// \name Operations
/// @{
public:
    /// Locks the given lockable instance
    static void lock(lock_type &c)
    {
        lock_instance(c);
    }

    /// Unlocks the given lockable instance
    static void unlock(lock_type &c)
    {
        unlock_instance(c);
    }
/// @}
};

// class lock_invert_traits

/** Traits class for inverting the lock status of lockable objects
 *
 * \ingroup group__library__Synch
 *
 * \param L The lockable class
 */
template<ss_typename_param_k L>
struct lock_invert_traits
{
/// \name Member Types
/// @{
public:
    /// The lockable type
    typedef L                                               lock_type;
    /// The current specialisation of the type
    typedef lock_invert_traits<L>                           class_type;
/// @}

/// \name Operations
/// @{
public:
    /// Unlocks the given lockable instance
    static void lock(lock_type &c)
    {
        unlock_instance(c);
    }

    /// Locks the given lockable instance
    static void unlock(lock_type &c)
    {
        lock_instance(c);
    }
/// @}
};

// class lock_traits_inverter

/** Traits inverter class for inverting the lock behaviour of lockable traits types
 *
 * \ingroup group__library__Synch
 *
 * \param L The traits class
 */
template<ss_typename_param_k T>
struct lock_traits_inverter
{
/// \name Member Types
/// @{
public:
    /// The traits type
    typedef T                                               traits_type;
    /// The lockable type
    typedef ss_typename_type_k traits_type::lock_type       lock_type;
    /// The current specialisation of the type
    typedef lock_traits_inverter<T>                         class_type;
/// @}

/// \name Operations
/// @{
public:
    /// Unlocks the given lockable instance
    static void lock(lock_type &c)
    {
        traits_type::unlock(c);
    }

    /// Locks the given lockable instance
    static void unlock(lock_type &c)
    {
        traits_type::lock(c);
    }
/// @}
};

// class lock_scope

/** This class scopes the lock status of a lockable type
 *
 * \ingroup group__library__Synch
 *
 * \param L The lockable type, e.g. stlsoft::null_mutex
 * \param T The lock traits. On translators that support default template arguments this defaults to lock_traits<L>
 */
template<   ss_typename_param_k L
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = lock_traits<L>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class lock_scope
{
/// \name Member Types
/// @{
public:
    /// The lockable type
    typedef L                                               lock_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The current specialisation of the type
    typedef lock_scope<L, T>                                class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Locks the lockable instance
    lock_scope(lock_type &l)
        : m_l(l)
    {
        traits_type::lock(m_l);
    }
    /// Unlocks the lockable instance
    ~lock_scope() STLSOFT_NOEXCEPT
    {
        traits_type::unlock(m_l);
    }
private:
    lock_scope(class_type const&);              // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Members
/// @{
private:
    lock_type   &m_l;
/// @}
};

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

#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_LOCK_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

