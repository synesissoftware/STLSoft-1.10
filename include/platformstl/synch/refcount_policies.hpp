/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/synch/refcount_policies.hpp
 *
 * Purpose:     Reference-counting policies.
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


/** \file platformstl/synch/refcount_policies.hpp
 *
 * \brief [C++] Reference-counting policies
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES
#define PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_MAJOR      2
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_MINOR      0
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_REVISION   3
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_EDIT       17
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

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED
# include <stlsoft/synch/refcount_policies/refcount_policy_single_threaded.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
# include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

