/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/c_string/strnpbrkn.h
 *
 * Purpose:     Definition of stlsoft_C_strnpbrkn() and stlsoft_C_wcsnpbrkn()
 *
 * Created:     11th December 2020
 * Updated:     18th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/string/c_string/strnpbrkn.h
 *
 * \brief [C, C++] Definition of stlsoft_C_strnpbrkn() and stlsoft_C_wcsnpbrkn()
 *
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNPBRKN
#define STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNPBRKN

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNPBRKN_MAJOR      1
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNPBRKN_MINOR      0
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNPBRKN_REVISION   2
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNPBRKN_EDIT       3
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

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

STLSOFT_INLINE
char const*
stlsoft_C_strnpbrkn(
    char const* str
,   size_t      cchStr
,   char const* charSet
,   size_t      cchCharSet
)
{
    for (; 0 != cchStr; ++str, --cchStr)
    {
        char const* s   =   charSet;
        size_t      n   =   cchCharSet;

        for (; 0 != n; ++s, --n)
        {
            if (*s == *str)
            {
                return str;
            }
        }
    }

    return ss_nullptr_k;
}

STLSOFT_INLINE
wchar_t const*
stlsoft_C_wcsnpbrkn(
    wchar_t const*  str
,   size_t          cchStr
,   wchar_t const*  charSet
,   size_t          cchCharSet
)
{
    for (; 0 != cchStr; ++str, --cchStr)
    {
        wchar_t const*  s   =   charSet;
        size_t          n   =   cchCharSet;

        for (; 0 != n; ++s, --n)
        {
            if (*s == *str)
            {
                return str;
            }
        }
    }

    return ss_nullptr_k;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
namespace c_string
{

/* /////////////////////////////////////////////////////////////////////////
 * API functions (C++)
 */

inline
char const*
strnpbrkn(
    char const* str
,   size_t      cchStr
,   char const* charSet
,   size_t      cchCharSet
)
{
    return stlsoft_C_strnpbrkn(str, cchStr, charSet, cchCharSet);
}

inline
wchar_t const*
strnpbrkn(
    wchar_t const*  str
,   size_t          cchStr
,   wchar_t const*  charSet
,   size_t          cchCharSet
)
{
    return stlsoft_C_wcsnpbrkn(str, cchStr, charSet, cchCharSet);
}

inline
wchar_t const*
wcsnpbrkn(
    wchar_t const*  str
,   size_t          cchStr
,   wchar_t const*  charSet
,   size_t          cchCharSet
)
{
    return stlsoft_C_wcsnpbrkn(str, cchStr, charSet, cchCharSet);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace c_string */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNPBRKN */

/* ///////////////////////////// end of file //////////////////////////// */

