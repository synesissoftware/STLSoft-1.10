/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/synch/sleep_functions.h
 *
 * Purpose:     Time functions.
 *
 * Created:     10th June 2006
 * Updated:     26th December 2020
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


/** \file platformstl/synch/sleep_functions.h
 *
 * \brief [C, C++] Various time functions
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_SLEEP_FUNCTIONS
#define PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_SLEEP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_H_SLEEP_FUNCTIONS_MAJOR      1
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_H_SLEEP_FUNCTIONS_MINOR      1
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_H_SLEEP_FUNCTIONS_REVISION   6
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_H_SLEEP_FUNCTIONS_EDIT       17
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# include <platformstl/platformstl.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS
#  include <unixstl/synch/sleep_functions.h>
# endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_SLEEP_FUNCTIONS */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_SYNCH_H_SLEEP_FUNCTIONS
#  include <winstl/synch/sleep_functions.h>
# endif /* !WINSTL_INCL_WINSTL_SYNCH_H_SLEEP_FUNCTIONS */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PLATFORMSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
# else
/* Define stlsoft::platformstl_project */
namespace stlsoft
{
namespace platformstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !PLATFORMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(__cplusplus)

# if defined(PLATFORMSTL_OS_IS_UNIX)

#  if defined(UNIXSTL_NO_NAMESPACE)
    /* There's no unixstl namespace, so we 'use' from the global namespace. */
    using micro_sleep;
#  else /* ? UNIXSTL_NO_NAMESPACE */
    using unixstl::micro_sleep;
#  endif /* UNIXSTL_NO_NAMESPACE */

# elif defined(PLATFORMSTL_OS_IS_WINDOWS)

#  if defined(UNIXSTL_NO_NAMESPACE)
    /* There's no unixstl namespace, so we 'use' from the global namespace. */
    using micro_sleep;
#  else /* ? UNIXSTL_NO_NAMESPACE */
    using winstl::micro_sleep;
#  endif /* UNIXSTL_NO_NAMESPACE */

# else /* ? OS */

#  error Operating system not discriminated

# endif /* OS */

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef PLATFORMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
# else
} /* namespace platformstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !PLATFORMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_SLEEP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

