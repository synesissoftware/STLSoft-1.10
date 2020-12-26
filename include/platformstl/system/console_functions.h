/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/system/console_functions.h
 *
 * Purpose:     Console functions.
 *
 * Created:     6th August 2015
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2015-2019, Matthew Wilson and Synesis Software
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


/** \file platformstl/system/console_functions.h
 *
 * \brief [C, C++] Console functions
 *   (\ref group__library__System "System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_H_CONSOLE_FUNCTIONS
#define PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_H_CONSOLE_FUNCTIONS

#ifndef PLATFORMSTL_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MAJOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_H_CONSOLE_FUNCTIONS_MINOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_H_CONSOLE_FUNCTIONS_REVISION    3
# define PLATFORMSTL_VER_PLATFORMSTL_SYSTEM_H_CONSOLE_FUNCTIONS_EDIT        8
#endif /* !PLATFORMSTL_DOCUMENTATION_SKIP_SECTION */

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

#  include <unixstl/system/console_functions.h>

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

#  include <winstl/system/console_functions.h>

#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

# include <stlsoft/quality/contract.h>

# include <stlsoft/quality/cover.h>

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

/* /////////////////////////////////////////////////////////////////////////
 * functions (C++)
 */

STLSOFT_INLINE
ss_size_t
platformstl_C_get_console_width(void)
{
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
    return UNIXSTL_NS_QUAL(unixstl_C_get_console_width)();
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
    return WINSTL_NS_QUAL(winstl_C_get_console_width)();
#else
# error Platform not discriminated
#endif
}

/* /////////////////////////////////////////////////////////////////////////
 * API functions (C++)
 */

#ifdef __cplusplus

inline
size_t
get_console_width()
{
    return platformstl_C_get_console_width();
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYSTEM_H_CONSOLE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

