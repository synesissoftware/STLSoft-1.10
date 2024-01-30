/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/exception/policy/windows_status_code_to_string_translation_policy.hpp (formerly in winstl/error/exceptions.hpp)
 *
 * Purpose:     winstl::windows_status_code_to_string_translation_policy
 *              policy class
 *
 * Created:     19th June 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/exception/policy/windows_status_code_to_string_translation_policy.hpp
 *
 * \brief [C++] Definition of the
 *   winstl::windows_status_code_to_string_translation_policy policy class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY
#define WINSTL_INCL_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY_MAJOR      6
# define WINSTL_VER_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY_MINOR      0
# define WINSTL_VER_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY_REVISION   1
# define WINSTL_VER_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY_EDIT       81
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_ERROR_H_ERROR_FUNCTIONS
# include <winstl/error/error_functions.h>
#endif /* !WINSTL_INCL_WINSTL_ERROR_H_ERROR_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING
# include <stlsoft/util/exception_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR
# include <stlsoft/util/exception_string_creator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Policy class for Window status code to string translation
 *
 * \ingroup group__library__Exception
 */
struct windows_status_code_to_string_translation_policy
{
public:
    /// The status code type
    typedef DWORD                                           status_code_type;
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
        size_type const                             cchMessage  =   STLSOFT_NS_QUAL(c_str_len)(message);
        STLSOFT_NS_QUAL(exception_string_creator)   creator(cchMessage + 2 + 100);

        creator.append(message, cchMessage);

        if (0 != cchMessage)
        {
            creator.append(": ", 2);
        }

        char        num[21];
        char*       s;
        size_type   n;

        if (0 != (n = WINSTL_NS_QUAL(format_message)(FORMAT_MESSAGE_IGNORE_INSERTS, NULL, sc, &s)))
        {
            try
            {
                creator.append(s, n);

                WINSTL_NS_QUAL(winstl_C_format_message_free_buff)(s);
            }
            catch(...)
            {
                WINSTL_NS_QUAL(winstl_C_format_message_free_buff)(s);

                throw;
            }
        }
        else
        {
            s = const_cast<char*>(STLSOFT_NS_QUAL(integer_to_decimal_string)(&num[0], STLSOFT_NUM_ELEMENTS(num), sc, &n));

            creator.append(s, n);
        }

        return creator.create();
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_POLICY_HPP_WINDOWS_STATUS_CODE_TO_STRING_TRANSLATION_POLICY */

/* ///////////////////////////// end of file //////////////////////////// */

