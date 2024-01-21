/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/spin_mutex_policies.hpp
 *
 * Purpose:     Policies for spin mutexes.
 *
 * Created:     25th November 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file unixstl/synch/spin_mutex_policies.hpp
 *
 * \brief [C++]
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES
#define UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES

#ifndef UNIXSTL_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_MAJOR      2
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_MINOR      0
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_REVISION   4
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_EDIT       18
#endif /* !UNIXSTL_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS
# include <unixstl/synch/atomic_functions.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS */

#if 0
#elif defined(UNIXSTL_FORCE_ATOMIC_INTEGER_OPERATIONS)

 /* Nothing to include here; UNIXSTL_FORCED_ATOMIC_INTEGER_IMPLEMENTATIONS will be included inside unixstl namespace */
#elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_GCC_BUILTINS)

 /* Nothing to include, since using built-ins */
#elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_MACOSX)

# include <libkern/OSAtomic.h>
#elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED)

# include <unixstl/synch/util/windows_api_.h>
# include <stlsoft/conversion/sap_cast.hpp>
#else

# error Atomic integer operations not supported: see unixstl/synch/util/features.h for details
#endif /* ? */

#if 0
#elif defined(_STLSOFT_FORCE_ANY_COMPILER) && \
      defined(_WIN32)
# include <unixstl/synch/util/windows_api_.h>
#else
# ifndef STLSOFT_INCL_H_SCHED
#  define STLSOFT_INCL_H_SCHED
#  include <sched.h>
# endif /* !STLSOFT_INCL_H_SCHED */
#endif

#ifdef _WIN32
# ifndef WINSTL_INCL_WINSTL_API_external_h_ProcessAndThread
#  include <winstl/api/external/ProcessAndThread.h>
# endif /* !WINSTL_INCL_WINSTL_API_external_h_ProcessAndThread */
#endif

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
 * compatibility & feature control
 */

#if defined(STLSOFT_DEBUG)
# define UNIXSTL_SPINMUTEX_COUNT_LOCKS
#endif /* STLSOFT_DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifndef UNIXSTL_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k T_atomicInteger
>
struct spin_mutex_policy_base
{
protected: // Types
    typedef T_atomicInteger                                 atomic_int_type;

protected: // Operations
#if 0
#elif 0 ||\
      defined(UNIXSTL_HAS_atomic_exchange) ||\
      defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED) ||\
      0
    static
    atomic_int_type
    atomic_exchange_(
        atomic_int_type volatile*   pv
    ,   atomic_int_type             value
    )
    {
# if 0
# elif defined(UNIXSTL_HAS_atomic_exchange)

        return atomic_exchange(pv, value);
# elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED)

        return atomic_exchange_Windows_(pv, value);
# elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_MACOSX)

# else

#  error Atomic integer operations not supported: see unixstl/synch/util/features.h for details
# endif
    }
#endif
#if 0
#elif 0 ||\
      defined(UNIXSTL_HAS_atomic_exchange) ||\
      defined(UNIXSTL_HAS_atomic_write) ||\
      defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED) ||\
      0
    static
    void
    atomic_write_(
        atomic_int_type volatile*   pv
    ,   atomic_int_type             value
    )
    {
# if 0
# elif defined(UNIXSTL_HAS_atomic_write)

        atomic_write(pv, value);
# elif defined(UNIXSTL_HAS_atomic_exchange)

        atomic_exchange(pv, value);
# elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED)

        atomic_write_Windows_(pv, value);
# else

#  error Atomic integer operations not supported: see unixstl/synch/util/features.h for details
# endif
    }
#endif

protected:
#if defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED)
    static
    us_sint32_t
    atomic_exchange_Windows_(
        us_sint32_t volatile*   pv
    ,   us_sint32_t             v
    )
    {
        return STLSOFT_NS_GLOBAL(InterlockedExchange)(stlsoft::sap_cast<long volatile*>(pv), v);
    }
    static
    void
    atomic_write_Windows_(
        us_sint32_t volatile*   pv
    ,   us_sint32_t             v
    )
    {
        STLSOFT_NS_GLOBAL(InterlockedExchange)(stlsoft::sap_cast<long volatile*>(pv), v);
    }
# if 0 ||\
     defined(UNIXSTL_ARCH_IS_IA64) ||\
     defined(UNIXSTL_ARCH_IS_X64) ||\
     0
    static
    us_sint64_t
    atomic_exchange_Windows_(
        us_sint64_t volatile*   pv
    ,   us_sint64_t             v
    )
    {
        return STLSOFT_NS_GLOBAL(InterlockedExchange64)(pv, v);
    }
    static
    void
    atomic_write_Windows_(
        us_sint64_t volatile*   pv
    ,   us_sint64_t             v
    )
    {
        STLSOFT_NS_GLOBAL(InterlockedExchange64)(pv, v);
    }
# endif
#endif
};

#endif /* !UNIXSTL_DOCUMENTATION_SKIP_SECTION */





struct no_yield_spin_mutex_policy
    : public spin_mutex_policy_base<atomic_int_t>
{
private: // Types
    typedef spin_mutex_policy_base<atomic_int_t>            parent_class_type_;
public:
    typedef parent_class_type_::atomic_int_type             atomic_int_type;

public: // Operations
    static
    ss_truthy_t
    try_acquire_lock(
        void*                        /* yieldContext */
    ,   atomic_int_type volatile*       spinCount
    ,   ss_sint32_t                  /* spunCount */
    )
    {
        // NOTE: if the following line results in a compile-error, then you
        // are translating with a compiler for which atomics are not (fully)
        // defined
        return 0 == parent_class_type_::atomic_exchange_(spinCount, 1);
    }
    static
    void
    on_spin(
        void*                        /* yieldContext */
    ,   ss_sint32_t                  /* spunCount */
    )
    {
    }
    static
    void
    on_acquire(
        void*                        /* yieldCount */
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef UNIXSTL_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 < cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif
    }
    static
    void
    release_lock(
        void*                        /* yieldContext */
    ,   atomic_int_type volatile*       spinCount
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef UNIXSTL_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 < cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif

        // NOTE: if the following line results in a compile-error, then you
        // are translating with a compiler for which atomics are not (fully)
        // defined
#if 0
#elif defined(UNIXSTL_HAS_atomic_clear)
        atomic_clear(spinCount);
#else
        parent_class_type_::atomic_write_(spinCount, 0);
#endif
    }
    static
    void
    on_destroy(
        void*                        /* yieldCount */
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef UNIXSTL_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 == cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif
    }
};

template<
    ss_sint32_t N_yieldThreshold
>
struct yield_on_N_spin_mutex_policy
    : public spin_mutex_policy_base<atomic_int_t>
{
private: // Types
    typedef spin_mutex_policy_base<atomic_int_t>            parent_class_type_;
public:
    typedef parent_class_type_::atomic_int_type             atomic_int_type;

public: // Operations
    static
    ss_truthy_t
    try_acquire_lock(
        void*                        /* yieldContext */
    ,   atomic_int_type volatile*       spinCount
    ,   ss_sint32_t                  /* spunCount */
    )
    {
        // NOTE: if the following line results in a compile-error, then you
        // are translating with a compiler for which atomics are not (fully)
        // defined
        return 0 == parent_class_type_::atomic_exchange_(spinCount, 1);
    }
    static
    void
    on_spin(
        void*                        /* yieldContext */
    ,   ss_sint32_t                     spunCount
    )
    {
        UNIXSTL_STATIC_ASSERT(0 != N_yieldThreshold);

        if (0 == (spunCount % N_yieldThreshold))
        {
#if 0
#elif defined(_STLSOFT_FORCE_ANY_COMPILER) && \
      defined(_WIN32)
            WINSTL_API_EXTERNAL_ProcessAndThread_Sleep(1);
#else
            STLSOFT_NS_GLOBAL(sched_yield());
#endif
        }
    }
    static
    void
    on_acquire(
        void*                        /* yieldCount */
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef UNIXSTL_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 < cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif
    }
    static
    void
    release_lock(
        void*                        /* yieldContext */
    ,   atomic_int_type volatile*       spinCount
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef UNIXSTL_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 < cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif

        // NOTE: if the following line results in a compile-error, then you
        // are translating with a compiler for which atomics are not (fully)
        // defined
        parent_class_type_::atomic_write_(spinCount, 0);
    }
    static
    void
    on_destroy(
        void*                        /* yieldCount */
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef UNIXSTL_SPINMUTEX_COUNT_LOCKS
        UNIXSTL_ASSERT(0 == cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif
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

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

