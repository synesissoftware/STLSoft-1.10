/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/exception/inetstl_exception.hpp (formerly inetstl/error/exceptions.hpp)
 *
 * Purpose:     inetstl::inetstl_exception class
 *
 * Created:     25th April 2004
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file inetstl/exception/inetstl_exception.hpp
 *
 * \brief [C++] Definition of the inetstl::inetstl_exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef INETSTL_INCL_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION
#define INETSTL_INCL_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION_MAJOR     4
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION_MINOR     5
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION_REVISION  2
# define INETSTL_VER_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION_EDIT      56
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef INETSTL_INCL_INETSTL_H_INETSTL
# include <inetstl/inetstl.h>
#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error This file cannot be included when exception-handling is not supported
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION
# include <stlsoft/exception/project_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE
# include <stlsoft/exception/util/status_code_translating_exception_base.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_UTIL_HPP_STATUS_CODE_TRANSLATING_EXCEPTION_BASE */
#if 0
#elif defined(INETSTL_OS_IS_UNIX)
# ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY
#  include <stlsoft/exception/policy/errno_to_string_translation_policy.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY */
#elif defined(INETSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY
#  include <winstl/exception/policy/windows_status_code_to_string_translation_policy.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY */
#else /*  ? platform */
# error Platform not discriminated
#endif /* platform */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */
namespace stlsoft
{
namespace inetstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

#if 0
#elif defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

/** The root InetSTL exception type
 */
class inetstl_exception
    : public stlsoft::project_exception
{};
#elif defined(INETSTL_OS_IS_UNIX)

typedef STLSOFT_NS_QUAL(status_code_translating_exception_base)<
    STLSOFT_NS_QUAL(project_exception)
,   STLSoftProjectIdentifier_InetSTL
,   STLSOFT_NS_QUAL(errno_to_string_translation_policy)
>                                                           inetstl_exception;
#elif defined(INETSTL_OS_IS_WINDOWS)

typedef STLSOFT_NS_QUAL(status_code_translating_exception_base)<
    STLSOFT_NS_QUAL(project_exception)
,   STLSoftProjectIdentifier_InetSTL
,   WINSTL_NS_QUAL(windows_status_code_to_string_translation_policy)
>                                                           inetstl_exception;
#else /*  ? platform */

# error Platform not discriminated
#endif /* platform */



#if _STLSOFT_VER < 0x010a0200
typedef inetstl_exception                                   internet_exception;
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace inetstl */
# else
} /* namespace inetstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !INETSTL_INCL_INETSTL_EXCEPTION_HPP_INETSTL_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

