/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/synch/null_mutex.hpp (originally MLMutex.h, ::SynesisStd)
 *
 * Purpose:     Mutual exclusion model class.
 *
 * Created:     19th December 1997
 * Updated:     23rd November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1997-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/synch/null_mutex.hpp
 *
 * \brief [C++] Definition of stlsoft::null_mutex class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_NULL_MUTEX
#define STLSOFT_INCL_STLSOFT_SYNCH_HPP_NULL_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_NULL_MUTEX_MAJOR     4
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_NULL_MUTEX_MINOR     0
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_NULL_MUTEX_REVISION  7
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_NULL_MUTEX_EDIT      55
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

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */

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

// class null_mutex

/** This class provides a null implementation of the mutex model.
 *
 * \ingroup group__library__Synch
 */
class null_mutex
    : public critical_section<  STLSOFT_CRITICAL_SECTION_IS_RECURSIVE
                            ,   STLSOFT_CRITICAL_SECTION_ISNOT_TRYABLE
                            >
{
/// \name Member Types
/// @{
public:
    typedef null_mutex class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Creates an instance of the mutex
    null_mutex() STLSOFT_NOEXCEPT
    {}
/// @}

/// \name Operations
/// @{
public:
    /// Acquires a lock on the mutex, pending the thread until the lock is acquired
    void lock() STLSOFT_NOEXCEPT
    {}
    /// Releases an acquired lock on the mutex
    void unlock() STLSOFT_NOEXCEPT
    {}
/// @}

/// \name Not to be implemented
/// @{
private:
    null_mutex(class_type const& rhs);
    null_mutex& operator =(class_type const& rhs);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * control shims
 */

/** This \ref group__concept__Shim "control shim" acquires a lock on the given mutex
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param mx The mutex on which to acquire the lock.
 */
inline void lock_instance(STLSOFT_NS_QUAL(null_mutex) &mx)
{
    STLSOFT_SUPPRESS_UNUSED(mx); // This is used, instead of the preferred omission of parameter, since it upsets the documentation
}

/** This \ref group__concept__Shim "control shim" releases a lock on the given mutex
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param mx The mutex on which to release the lock
 */
inline void unlock_instance(STLSOFT_NS_QUAL(null_mutex) &mx)
{
    STLSOFT_SUPPRESS_UNUSED(mx); // This is used, instead of the preferred omission of parameter, since it upsets the documentation
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

#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_NULL_MUTEX */

/* ///////////////////////////// end of file //////////////////////////// */

