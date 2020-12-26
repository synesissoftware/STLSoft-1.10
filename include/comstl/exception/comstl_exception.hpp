/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/exception/comstl_exception.hpp (formerly comstl/error/exceptions.hpp)
 *
 * Purpose:     comstl::comstl_exception class
 *
 * Created:     8th December 2004
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


/** \file comstl/exception/comstl_exception.hpp
 *
 * \brief [C++] Definition of the comstl::comstl_exception
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION
#define COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION_MAJOR     3
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION_MINOR     2
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION_REVISION  2
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION_EDIT      59
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
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
#ifndef COMSTL_INCL_COMSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY
# include <comstl/exception/policy/HRESULT_to_string_translation_policy.hpp>
#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** General exception class for COM-related failures.
 *
 * \ingroup group__library__Exception
 *
 */
typedef STLSOFT_NS_QUAL(status_code_translating_exception_base)<
    STLSOFT_NS_QUAL(project_exception)
,   STLSoftProjectIdentifier_COMSTL
,   HRESULT_to_string_translation_policy
>                                                           comstl_exception;

#if _STLSOFT_VER < 0x010a0200
typedef comstl_exception                                    com_exception;
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

