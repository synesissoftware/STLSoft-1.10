/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/exception/policy/HRESULT_to_string_translation_policy.hpp
 *
 * Purpose:     comstl::HRESULT_to_string_translation_policy
 *              policy class
 *
 * Created:     8th January 2017
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2017-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/exception/policy/HRESULT_to_string_translation_policy.hpp
 *
 * \brief [C++] Definition of the
 *   comstl::HRESULT_to_string_translation_policy policy class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef COMSTL_INCL_COMSTL_EXCEPTION_POLICY_HPP_HRESULT_TO_STRING_TRANSLATION_POLICY
#define COMSTL_INCL_COMSTL_EXCEPTION_POLICY_HPP_HRESULT_TO_STRING_TRANSLATION_POLICY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_EXCEPTION_POLICY_HPP_HRESULT_TO_STRING_TRANSLATION_POLICY_MAJOR      1
# define COMSTL_VER_COMSTL_EXCEPTION_POLICY_HPP_HRESULT_TO_STRING_TRANSLATION_POLICY_MINOR      0
# define COMSTL_VER_COMSTL_EXCEPTION_POLICY_HPP_HRESULT_TO_STRING_TRANSLATION_POLICY_REVISION   1
# define COMSTL_VER_COMSTL_EXCEPTION_POLICY_HPP_HRESULT_TO_STRING_TRANSLATION_POLICY_EDIT       4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_WINSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY
# include <winstl/exception/policy/windows_status_code_to_string_translation_policy.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY */

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

/** Policy class for Window status code to string translation
 *
 * \ingroup group__library__Exception
 */
struct HRESULT_to_string_translation_policy
{
public:
    /// The status code type
    typedef HRESULT                                         status_code_type;
    /// The string type
    typedef STLSOFT_NS_QUAL(exception_string)               string_type;
    /// The size type
    typedef ss_size_t                                       size_type;

public:
    /// Creates a message from the given status code and message
    static
    string_type
    create_message(
        status_code_type    sc
    ,   char const*         message
    )
    {
        typedef WINSTL_NS_QUAL(windows_status_code_to_string_translation_policy)    windows_policy_t;

        return windows_policy_t::create_message(static_cast<windows_policy_t::status_code_type>(sc), message);
    }
};

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_POLICY_HPP_HRESULT_TO_STRING_TRANSLATION_POLICY */

/* ///////////////////////////// end of file //////////////////////////// */

