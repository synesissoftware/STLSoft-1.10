/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/locale/locale_scope.hpp
 *
 * Purpose:     Defines the locale_scope class.
 *
 * Created:     23rd December 2018
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/locale/locale_scope.hpp
 *
 * \brief [C++] Defines the locale_scope class
 *   (\ref group__library__Locale "Locale" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_LOCALE_HPP_LOCALE_SCOPE
#define STLSOFT_INCL_STLSOFT_LOCALE_HPP_LOCALE_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_LOCALE_HPP_LOCALE_SCOPE_MAJOR      1
# define STLSOFT_VER_STLSOFT_LOCALE_HPP_LOCALE_SCOPE_MINOR      0
# define STLSOFT_VER_STLSOFT_LOCALE_HPP_LOCALE_SCOPE_REVISION   1
# define STLSOFT_VER_STLSOFT_LOCALE_HPP_LOCALE_SCOPE_EDIT       5
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

#ifndef STLSOFT_INCL_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION
# include <stlsoft/locale/exception/locale_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_LOCALE_EXCEPTION_HPP_LOCALE_EXCEPTION */

#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
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

class locale_scope
{
public: // types
    typedef locale_scope                                    class_type;
    typedef std::basic_string<
        char
    >                                                       string_type;

public: // construction
    ss_explicit_k
    locale_scope(
        int             category
    ,   char const*     localeName
    )
        : m_category(category)
        , m_previousLocale(obtain_or_throw_(category, ss_nullptr_k))
    {
        set_or_throw_(m_category, localeName);
    }
    /// NOTE: this dtor may throw an exception (except during unwind) if
    /// the original locale cannot be restored.
    ~locale_scope()
    {
        if (!std::uncaught_exception())
        {
            set_or_throw_(m_category, m_previousLocale.c_str());
        }
    }
private:
    locale_scope(class_type const&);    // copy-construction proscribed
    void operator =(class_type const&); // copy-assignment proscribed

public: // accessors
    string_type const&  previous() const STLSOFT_NOEXCEPT
    {
        return m_previousLocale;
    }

private: // implementation
    static
    string_type
    obtain_or_throw_(
        int         category
    ,   char const* localeName
    )
    {
        char* const r = ::setlocale(category, localeName);

        if (ss_nullptr_k == r)
        {
            int const e = errno;

            STLSOFT_THROW_X(locale_exception(localeName, e));
        }

        return string_type(r);
    }
    static
    void
    set_or_throw_(
        int         category
    ,   char const* localeName
    )
    {
        char* const r = ::setlocale(category, localeName);

        if (ss_nullptr_k == r)
        {
            int const e = errno;

            STLSOFT_THROW_X(locale_exception(localeName, e));
        }
    }

private: // fields
    int const           m_category;
    string_type const   m_previousLocale;
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

#endif /* !STLSOFT_INCL_STLSOFT_LOCALE_HPP_LOCALE_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

