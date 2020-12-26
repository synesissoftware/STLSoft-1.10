/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/diagnostics/processtimes_stopwatch.hpp (formerly platformstl::processtimes_counter, platformstl/performance/processtimes_counter.hpp)
 *
 * Purpose:     Platform header for the processtimes_stopwatch components.
 *
 * Created:     9th June 2006
 * Updated:     24th December 2020
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


#ifndef PLATFORMSTL_INCL_PLATFORMSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH
#define PLATFORMSTL_INCL_PLATFORMSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_MAJOR       2
# define PLATFORMSTL_VER_PLATFORMSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_MINOR       0
# define PLATFORMSTL_VER_PLATFORMSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_REVISION    2
# define PLATFORMSTL_VER_PLATFORMSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_EDIT        17
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file platformstl/diagnostics/processtimes_stopwatch.hpp
 *
 * \brief [C++] Definition of the <code>platformstl::processtimes_stopwatch</code>
 *  type
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 *
 * When compiling on UNIX platforms, the platformstl::processtimes_stopwatch
 * type resolves to the unixstl::processtimes_stopwatch class. On Windows
 * platforms it resolves to the winstl::processtimes_stopwatch class. It is
 * not defined for other platforms.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH
#  include <unixstl/diagnostics/processtimes_stopwatch.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH
#  include <winstl/diagnostics/processtimes_stopwatch.hpp>
# endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

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

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

    /** A stopwatch class that measures kernel and user activity.
     *
     * The class is not actually defined in the
     * \link ::platformstl platformstl\endlink namespace. Rather, it
     * resolves to the appropriate type for the given platform, relying on
     * \ref section__principle__conformance__intersecting_conformance "Intersecting Conformance"
     * of the resolved platform-specific types.
     *
     * When compiling on UNIX platforms, the platformstl::processtimes_stopwatch
     * type resolves to the unixstl::processtimes_stopwatch class. On Windows
     * platforms it resolves to the winstl::processtimes_stopwatch class. It
     * is not defined for other platforms.
     */
    class processtimes_stopwatch
    {};

#elif defined(PLATFORMSTL_OS_IS_UNIX)

# ifdef UNIXSTL_NO_NAMESPACE
    using ::processtimes_stopwatch;
# else /* ? UNIXSTL_NO_NAMESPACE */
    using ::unixstl::processtimes_stopwatch;
# endif /* UNIXSTL_NO_NAMESPACE */

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

# ifdef WINSTL_NO_NAMESPACE
    using ::processtimes_stopwatch;
# else /* ? WINSTL_NO_NAMESPACE */
    using ::winstl::processtimes_stopwatch;
# endif /* WINSTL_NO_NAMESPACE */

#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

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

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

