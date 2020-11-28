/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/c_string/strnchr.h
 *
 * Purpose:     Definition of stlsoft_C_strnchr() and stlsoft_C_wcsnchr()
 *
 * Created:     1st October 2020
 * Updated:     25th November 2020
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


/** \file stlsoft/string/c_string/strnchr.h
 *
 * \brief [C, C++] Definition of stlsoft_C_strnchr() and stlsoft_C_wcsnchr()
 *
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR
#define STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNCHR_MAJOR    1
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNCHR_MINOR    0
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNCHR_REVISION 1
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNCHR_EDIT     1
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
stlsoft_C_strnchr(
    char const* s
,   size_t      n
,   int         ch
)
{
    for (; 0 != n; --n, ++s)
    {
        if (ch == *s)
        {
            return s;
        }
    }

    return ss_nullptr_k;
}

STLSOFT_INLINE
wchar_t const*
stlsoft_C_wcsnchr(
    wchar_t const*  s
,   size_t          n
,   int             ch
)
{
    for (; 0 != n; --n, ++s)
    {
        if (ch == *s)
        {
            return s;
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
strnchr(
    char const* s
,   size_t      n
,   int         ch
)
{
    return stlsoft_C_strnchr(s, n, ch);
}

inline
wchar_t const*
strnchr(
    wchar_t const*  s
,   size_t          n
,   int             ch
)
{
    return stlsoft_C_wcsnchr(s, n, ch);
}

inline
wchar_t const*
wcsnchr(
    wchar_t const*  s
,   size_t          n
,   int             ch
)
{
    return stlsoft_C_wcsnchr(s, n, ch);
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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR */

/* ///////////////////////////// end of file //////////////////////////// */

