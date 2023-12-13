/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/semaphore.hpp
 *
 * Purpose:     Semaphore class, based on POSIX semaphore object.
 *
 * Created:     30th May 2006
 * Updated:     23rd November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/synch/semaphore.hpp
 *
 * \brief [C++] Definition of unixstl::semaphore class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SEMAPHORE
#define UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SEMAPHORE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SEMAPHORE_MAJOR    1
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SEMAPHORE_MINOR    2
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SEMAPHORE_REVISION 13
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SEMAPHORE_EDIT     37
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

#ifndef STLSOFT_INCL_H_LIMITS
# define STLSOFT_INCL_H_LIMITS
# include <limits.h>
#endif /* !STLSOFT_INCL_H_LIMITS */
#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_PTHREAD
# define STLSOFT_INCL_H_PTHREAD
# include <pthread.h>
#endif /* !STLSOFT_INCL_H_PTHREAD */
#ifndef STLSOFT_INCL_H_SEMAPHORE
# define STLSOFT_INCL_H_SEMAPHORE
# include <semaphore.h>
#endif /* !STLSOFT_INCL_H_SEMAPHORE */

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

// class semaphore
/** This class acts as a semaphore based on the POSIX
 *   semaphore object
 *
 * \ingroup group__library__Synch
 */
class semaphore
    : public STLSOFT_NS_QUAL(critical_section)< STLSOFT_CRITICAL_SECTION_ISNOT_RECURSIVE
                                            ,   STLSOFT_CRITICAL_SECTION_IS_TRYABLE
                                            >
    , public STLSOFT_NS_QUAL(synchronisable_object_tag)
{
/// \name Member Types
/// @{
public:
    typedef semaphore       class_type;
    typedef sem_t*          handle_type;
    typedef us_bool_t       bool_type;
    typedef unsigned int    count_type;

    typedef sem_t*          resource_type;
/// @}

/// \name Member Constants
/// @{
public:
    enum
    {
        maxCountValue   =   _POSIX_SEM_VALUE_MAX    // Borrowed from PThreads-win32
    };
/// @}

/// \name Construction
/// @{
public:
    /// Conversion constructor
    semaphore(handle_type sem, bool_type bTakeOwnership)
        : m_sem(sem)
        , m_bOwnHandle(bTakeOwnership)
    {
        UNIXSTL_ASSERT(NULL != sem);
    }
    /// Creates an instance of the semaphore
    ss_explicit_k semaphore(count_type initialCount, bool_type bInterProcessShared = false)
        : m_sem(create_semaphore_(&m_semInternal, initialCount, bInterProcessShared))
        , m_bOwnHandle(true)
    {}

    /// Destroys an instance of the semaphore
    ~semaphore() STLSOFT_NOEXCEPT
    {
        if( NULL != m_sem &&
            m_bOwnHandle)
        {
            ::sem_destroy(m_sem);
        }
    }

// Not to be implemented
private:
    semaphore(class_type const&);               // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed

#if 0
    void close() STLSOFT_NOEXCEPT
    {
        if( NULL != m_sem &&
            m_bOwnHandle)
        {
            ::sem_destroy(m_sem);
            m_sem = NULL;
        }
    }
#endif /* 0 */

/// @}

/// \name Operations
/// @{
public:
    /// Acquires a lock on the semaphore, pending the thread until the lock is acquired
    void lock()
    {
        UNIXSTL_ASSERT(NULL != m_sem);

        if(::sem_wait(m_sem) < 0)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_exception("semaphore wait failed", errno));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    /// Attempts to lock the semaphore
    ///
    /// \return <b>true</b> if the semaphore was acquired, or <b>false</b> if not
    bool_type try_lock()
    {
        UNIXSTL_ASSERT(NULL != m_sem);

        int res =   ::sem_trywait(m_sem);

        if(0 == res)
        {
            return true;
        }
        else
        {
            if(EAGAIN != res)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                STLSOFT_THROW_X(synchronisation_exception("semaphore wait failed", errno));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }

        return false;
    }
    /// Releases an acquired lock on the semaphore, increasing the
    ///  semaphore's counter by one.
    void unlock()
    {
        UNIXSTL_ASSERT(NULL != m_sem);

        if(::sem_post(m_sem) < 0)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_exception("semaphore release failed", errno));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// The underlying kernel object handle
    handle_type handle() STLSOFT_NOEXCEPT
    {
        return m_sem;
    }
    /// The underlying kernel object handle
    handle_type get() STLSOFT_NOEXCEPT
    {
        return m_sem;
    }
/// @}

// Implementation
private:
    static handle_type create_semaphore_(sem_t* internal, count_type initialCount, bool_type bInterProcessShared)
    {
        UNIXSTL_ASSERT(initialCount <= maxCountValue);

        handle_type sem = NULL;

        if(::sem_init(internal, bInterProcessShared, initialCount) < 0)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

            STLSOFT_THROW_X(synchronisation_exception("failed to create kernel semaphore object", errno));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            sem = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            sem = internal;
        }

        return sem;
    }

// Members
private:
    sem_t               m_semInternal;  // The actual object if internally initialised
    handle_type         m_sem;          // Handle to the underlying semaphore object
    const bool_type     m_bOwnHandle;   // Does the instance own the handle?
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/** This \ref group__concept__Shim "control shim" acquires a lock on the given semaphore
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param sem The semaphore on which to acquire the lock.
 */
inline void lock_instance(UNIXSTL_NS_QUAL(semaphore) &sem)
{
    sem.lock();
}

/** This \ref group__concept__Shim "control shim" releases a lock on the given semaphore
 *
 * \ingroup group__concept__Shim__synchronisation_control
 *
 * \param sem The semaphore on which to release the lock
 */
inline void unlock_instance(UNIXSTL_NS_QUAL(semaphore) &sem)
{
    sem.unlock();
}

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace unixstl {
# else
namespace unixstl_project {
#  if defined(STLSOFT_COMPILER_IS_BORLAND)
using ::stlsoft::lock_instance;
using ::stlsoft::unlock_instance;
#  endif /* compiler */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * lock_traits
 */

// class lock_traits
/** Traits for the semaphore class
 *
 * \ingroup group__library__Synch
 */
struct semaphore_lock_traits
{
public:
    /// The lockable type
    typedef semaphore                lock_type;
    typedef semaphore_lock_traits    class_type;

// Operations
public:
    /// Lock the given semaphore instance
    static void lock(semaphore &c)
    {
        lock_instance(c);
    }

    /// Unlock the given semaphore instance
    static void unlock(semaphore &c)
    {
        unlock_instance(c);
    }
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

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SEMAPHORE */

/* ///////////////////////////// end of file //////////////////////////// */

