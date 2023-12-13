/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp
 *
 * Purpose:     Definition of the stlsoft::refcount_policy_multi_threaded
 *              policy class.
 *
 * Created:     31st May 2009
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2009-2019, Matthew Wilson and Synesis Software
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


/** \file platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp
 *
 * \brief [C++] Definition of the stlsoft::refcount_policy_multi_threaded
 *   policy class (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
#define PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED_MAJOR       2
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED_MINOR       0
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED_REVISION    3
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED_EDIT        18
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_ATOMIC_FUNCTIONS
# include <platformstl/synch/atomic_functions.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_ATOMIC_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR
# include <stlsoft/smartptr/ref_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */

namespace stlsoft
{
namespace platformstl_project
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Policy for adding/incrementing and releasing/decrementing reference
 * counts that is appropriate for use in a multi-threaded program.
 */
struct refcount_policy_multi_threaded
{
public:
    /** Adds/increments a reference
     */
    static
    void
    addref(
        atomic_int_t& refCount
    )
    {
        PLATFORMSTL_NS_QUAL(atomic_increment)(&refCount);
    }
    /** Releases/decrements a reference
     */
    static
    atomic_int_t
    release(
        atomic_int_t& refCount
    )
    {
        return PLATFORMSTL_NS_QUAL(atomic_predecrement)(&refCount);
    }
};

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
#else
} /* namespace platformstl_project */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */

/* ///////////////////////////// end of file //////////////////////////// */

