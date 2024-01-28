/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/policy/errno_to_string_translation_policy.hpp (formerly unixstl/error/exceptions.hpp)
 *
 * Purpose:     stlsoft::errno_to_string_translation_policy policy class
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


/** \file stlsoft/exception/policy/errno_to_string_translation_policy.hpp
 *
 * \brief [C++] Definition of the
 *   errno_to_string_translation_policy policy class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY
#define STLSOFT_INCL_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY_MAJOR      5
# define STLSOFT_VER_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY_MINOR      0
# define STLSOFT_VER_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY_REVISION   1
# define STLSOFT_VER_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY_EDIT       67
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING
# include <stlsoft/util/exception_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR
# include <stlsoft/util/exception_string_creator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Policy class for errno to string translation
 *
 * \ingroup group__library__Exception
 */
struct errno_to_string_translation_policy
{
public:
    /// The status code type
    typedef int                                             status_code_type;
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
        char const* s;
        size_type   n;

        strerror_(0);  // need to flush the errno

        s   =   strerror_(sc);
        n   =   STLSOFT_NS_QUAL(c_str_len)(s);

        if (0 == n)
        {
            s = STLSOFT_NS_QUAL(integer_to_decimal_string)(&num[0], STLSOFT_NUM_ELEMENTS(num), sc, &n);
        }

        creator.append(s, n);

        return creator.create();
    }

private:
    static char const* strerror_(int code)
    {
# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>

        return STLSOFT_NS_GLOBAL(strerror)(code);

# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_POLICY_HPP_ERRNO_TO_STRING_TRANSLATION_POLICY */

/* ///////////////////////////// end of file //////////////////////////// */

