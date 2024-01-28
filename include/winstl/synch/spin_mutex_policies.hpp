/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/spin_mutex_policies.hpp
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


/** \file winstl/synch/spin_mutex_policies.hpp
 *
 * \brief [C++]
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES
#define WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES

#ifndef WINSTL_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_MAJOR      2
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_MINOR      1
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_REVISION   3
# define WINSTL_VER_WINSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES_EDIT       17
#endif /* !WINSTL_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS
# include <winstl/synch/atomic_functions.h>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ProcessAndThread
# include <winstl/api/external/ProcessAndThread.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ProcessAndThread */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility & feature control
 */

#if defined(STLSOFT_DEBUG)
# define WINSTL_SPINMUTEX_COUNT_LOCKS
#endif /* STLSOFT_DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

struct no_yield_spin_mutex_policy
{
public: // Types
    typedef atomic_int_t                                    atomic_int_type;

public: // Operations
    static
    ss_truthy_t
    try_acquire_lock(
        void*                        /* yieldContext */
    ,   atomic_int_type volatile*       spinCount
    ,   ss_sint32_t                  /* spunCount */
    )
    {
        return 0 == atomic_exchange(spinCount, 1);
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
#ifdef WINSTL_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 < cLocks);
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
#ifdef WINSTL_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 < cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif

        atomic_write(spinCount, 0);
    }
    static
    void
    on_destroy(
        void*                        /* yieldCount */
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef WINSTL_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 == cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif
    }
};

template<
    ss_sint32_t         N_yieldThreshold
,   ss_typename_param_k T_atomicType    =   atomic_int_t
>
struct yield_on_N_spin_mutex_policy
{
public: // Types
    typedef T_atomicType                                    atomic_int_type;

public: // Operations
    static
    ss_truthy_t
    try_acquire_lock(
        void*                        /* yieldContext */
    ,   atomic_int_type volatile*       spinCount
    ,   ss_sint32_t                  /* spunCount */
    )
    {
        return 0 == atomic_exchange(spinCount, 1);
    }
    static
    void
    on_spin(
        void*                        /* yieldContext */
    ,   ss_sint32_t                     spunCount
    )
    {
        WINSTL_STATIC_ASSERT(0 != N_yieldThreshold);

        if (0 == (spunCount % N_yieldThreshold))
        {
#if 0
#elif _WIN32_WINNT >= 0x0400
            STLSOFT_NS_GLOBAL(SwitchToThread)();
#else /* ? _WIN32_WINNT */
            WINSTL_API_EXTERNAL_ProcessAndThread_Sleep(1);
#endif /* _WIN32_WINNT */
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
#ifdef WINSTL_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 < cLocks);
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
#ifdef WINSTL_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 < cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif

        atomic_write(spinCount, 0);
    }
    static
    void
    on_destroy(
        void*                        /* yieldCount */
    ,   ss_sint32_t                  /* spunCount */
    ,   ss_sint32_t                     cLocks
    )
    {
#ifdef WINSTL_SPINMUTEX_COUNT_LOCKS
        WINSTL_ASSERT(0 == cLocks);
#else
        STLSOFT_SUPPRESS_UNUSED(cLocks);
#endif
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

