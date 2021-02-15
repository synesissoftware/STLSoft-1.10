/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/logical/is_null.hpp
 *
 * Purpose:     Contains the is_null attribute shim.
 *
 * Created:     31st March 2007
 * Updated:     28th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/shims/logical/is_null.hpp
 *
 * \brief [C++] Primary include file for is_null collection logical shim
 *   for standard and STLSoft types
 *   (\ref group__concept__Shim__Logical__is_null "is_null Logical Shim").
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_HPP_IS_NULL
#define STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_HPP_IS_NULL

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_HPP_IS_NULL_MAJOR       2
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_HPP_IS_NULL_MINOR       0
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_HPP_IS_NULL_REVISION    4
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_HPP_IS_NULL_EDIT        13
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_H_FWD
# include <stlsoft/shims/logical/is_null/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_H_POINTER
# include <stlsoft/shims/logical/is_null/std/pointer.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_H_POINTER */

#ifdef __cplusplus

 /* standard smart pointers */

# ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR
#  include <stlsoft/util/std/library_discriminator.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR */

 /* std::auto_ptr<> */
# include <stlsoft/internal/std/has/auto_ptr_.hpp>

# ifdef STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_
#  ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR
#   include <stlsoft/shims/logical/is_null/std/auto_ptr.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR */
# endif

 /* std::shared_ptr<> */
# if 0 || \
     (  defined(STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION) && \
        STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION >= STLSOFT_CF_DINKUMWARE_VC_VERSION_9_0) || \
     0

#  ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_SHARED_PTR

#   include <stlsoft/shims/logical/is_null/std/shared_ptr.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_SHARED_PTR */
# endif

 /* std::unique_ptr<> */
# if 0 || \
     (  defined(STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION) && \
        STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION >= STLSOFT_CF_DINKUMWARE_VC_VERSION_10_0) || \
     0

#  ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_UNIQUE_PTR

#   include <stlsoft/shims/logical/is_null/std/unique_ptr.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_UNIQUE_PTR */
# endif
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_HPP_IS_NULL */

/* ///////////////////////////// end of file //////////////////////////// */

