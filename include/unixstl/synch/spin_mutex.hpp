/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/spin_mutex.hpp (originally MWSpinMx.h, ::SynesisWin)
 *
 * Purpose:     Intra-process mutex, based on spin waits.
 *
 * Created:     27th August 1997
 * Updated:     22nd January 2024
 *
 * Thanks:      To Rupert Kittinger, for pointing out that the prior
 *              implementation that always yielded was not really "spinning".
 *
 *              Brad Cox, for helping out in testing and fixing the
 *              implementation for MAC OSX (Intel).
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file unixstl/synch/spin_mutex.hpp
 *
 * \brief [C++] Definition of the unixstl::spin_mutex class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX
#define UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_MAJOR     6
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_MINOR     0
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_REVISION  2
# define UNIXSTL_VER_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_EDIT      76
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

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES
# include <unixstl/synch/spin_mutex_policies.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX_POLICIES */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE
# include <stlsoft/synch/spin_mutex_base.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_SPIN_MUTEX_BASE */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility & feature control
 */

#ifndef UNIXSTL_SYNCH_SPIN_MUTEX_DEFAULT_YIELD_COUNT
# define UNIXSTL_SYNCH_SPIN_MUTEX_DEFAULT_YIELD_COUNT       (1000)
#endif /* !UNIXSTL_SYNCH_SPIN_MUTEX_DEFAULT_YIELD_COUNT */

#if defined(STLSOFT_DEBUG)
# define UNIXSTL_SPINMUTEX_COUNT_LOCKS
#endif /* STLSOFT_DEBUG */

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
 * types
 */

typedef STLSOFT_NS_QUAL(spin_mutex_base)<
    yield_on_N_spin_mutex_policy<1>
>                                                           spin_mutex_yield;
typedef STLSOFT_NS_QUAL(spin_mutex_base)<
    no_yield_spin_mutex_policy
>                                                           spin_mutex_no_yield;

typedef STLSOFT_NS_QUAL(spin_mutex_base)<
    yield_on_N_spin_mutex_policy<UNIXSTL_SYNCH_SPIN_MUTEX_DEFAULT_YIELD_COUNT>
>                                                           spin_mutex;

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

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX */

/* ///////////////////////////// end of file //////////////////////////// */

