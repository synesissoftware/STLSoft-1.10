/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/tss_index.hpp
 *
 * Purpose:     Wrapper class for UNIX PThreads TSS key.
 *
 * Created:     21st January 1999
 * Updated:     22nd January 2024
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


/** \file unixstl/synch/tss_index.hpp
 *
 * \brief [C++] Definition of the unixstl::tss_index class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_TSS_INDEX
#define UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_TSS_INDEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_TSS_INDEX_MAJOR      3
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_TSS_INDEX_MINOR      1
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_TSS_INDEX_REVISION   9
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_TSS_INDEX_EDIT       62
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_COMMON
# include <unixstl/synch/common.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_COMMON */

#ifndef UNIXSTL_USING_PTHREADS
# error unixstl/synch/tss_index.hpp cannot be included in non-multithreaded compilation. _REENTRANT and/or _POSIX_THREADS must be defined
#endif /* !UNIXSTL_USING_PTHREADS */
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error unixstl/synch/tss_index.hpp cannot be compiled without exception-support enabled
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef STLSOFT_INCL_H_PTHREAD
# define STLSOFT_INCL_H_PTHREAD
# include <pthread.h>
#endif /* !STLSOFT_INCL_H_PTHREAD */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
/** Indicates that a TSS key cannot be allocated.
 *
 * \note This exception indicates an unrecoverable condition.
 *
 * \ingroup group__library__Synch
 */
class tss_exception
    : public synchronisation_exception
{
/// \name Types
/// @{
public:
    /// The parent class type
    typedef synchronisation_exception                       parent_class_type;
    /// The class type
    typedef tss_exception                                   class_type;
    /// The status code type
    typedef parent_class_type::status_code_type             status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k
    tss_exception(
        status_code_type sc
    )
        : parent_class_type("Failed to allocate a TSS key", sc)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}
};
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/** Wrapper for a UNIX PThreads TSS key.
 *
 * \ingroup group__library__Synch
 */
class tss_index
{
/// \name Types
/// @{
public:
    /// This class
    typedef tss_index       class_type;
    /// The type of the TSS key
    typedef pthread_key_t   key_type;
    /// The type of the TSS key
    ///
    /// \deprecated Deprecated in favour of key_type
    typedef key_type        index_type;
    /// The type of the slot values
    typedef void*           value_type;
/// @}

/// \name Construction
/// @{
public:
    /// Allocates a TSS key
    ss_explicit_k tss_index()
        : m_index(index_create_())
    {}
    /// Releases the TSS key
    ~tss_index() STLSOFT_NOEXCEPT
    {
        index_destroy_(m_index);
    }
private:
    tss_index(class_type const&);               // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Operations
/// @{
public:
    /// Sets the value in the slot for the current thread
    void        set_value(value_type value)
    {
        class_type::set_slot_value_(m_index, value);
    }
    /// Gets the value in the slot for the current thread
    value_type  get_value() const
    {
        return class_type::get_slot_value_(m_index);
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Implicit conversion operator to the
    operator key_type () const
    {
        return m_index;
    }
/// @}

/// \name Implementation
/// @{
private:
    static key_type index_create_()
    {
        key_type    key;
        int         res =   ::pthread_key_create(&key, NULL);

        if (0 != res)
        {
            STLSOFT_THROW_X(tss_exception(res));
        }

        return key;
    }

    static void index_destroy_(key_type key)
    {
        ::pthread_key_delete(key);
    }

    static void set_slot_value_(key_type key, value_type value)
    {
        ::pthread_setspecific(key, value);
    }

    static value_type get_slot_value_(key_type key)
    {
        return ::pthread_getspecific(key);
    }
/// @}

/// \name Members
/// @{
private:
    key_type    m_index;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_TSS_INDEX */

/* ///////////////////////////// end of file //////////////////////////// */

