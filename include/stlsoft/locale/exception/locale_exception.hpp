/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/locale/exception/locale_exception.hpp
 *
 * Purpose:     Defines the locale_exception exception class.
 *
 * Created:     25th December 2018
 * Updated:     26th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2018-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/locale/exception/locale_exception.hpp
 *
 * \brief [C++] Defines the locale_scope class
 *   (\ref group__library__Locale "Locale" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION
#define STLSOFT_INCL_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION_MAJOR      1
# define STLSOFT_VER_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION_MINOR      0
# define STLSOFT_VER_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION_REVISION   3
# define STLSOFT_VER_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION_EDIT       6
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

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION
# include <stlsoft/exception/special/errno_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION */

#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */

#ifndef STLSOFT_INCL_H_LOCALE
# define STLSOFT_INCL_H_LOCALE
# include <locale.h>
#endif /* !STLSOFT_INCL_H_LOCALE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

class locale_exception
    : public errno_exception
{
public: // types
    typedef errno_exception                                 parent_class_type;
    typedef errno_exception                                 class_type;
    typedef std::basic_string<
        char
    >                                                       string_type;

public: // construction
    ss_explicit_k
    locale_exception(
        char const* localeName
    ,   int         e
    )
        : parent_class_type(e)
        , LocaleName(stlsoft::c_str_ptr(localeName))
    {}
    /// Constructs an instance from the given errno value and message
    template <ss_typename_param_k S>
    locale_exception(
        char const* localeName
    ,   int         e
    ,   S const&    message
    )
        : parent_class_type(e, message)
        , LocaleName(stlsoft::c_str_ptr(localeName))
    {}
#if 0
#elif defined(__GNUC__)
    ~locale_exception() STLSOFT_NOEXCEPT_STDOVR
    {}
#endif

private:
    void operator =(class_type const&); // copy-assignment proscribed

public: // fields
    string_type const     LocaleName;
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

