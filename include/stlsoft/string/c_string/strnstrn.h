/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/c_string/strnstrn.h
 *
 * Purpose:     Definition of stlsoft_C_strnstrn() and stlsoft_C_wcsnstrn()
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


/** \file stlsoft/string/c_string/strnstrn.h
 *
 * \brief [C, C++] Definition of stlsoft_C_strnstrn() and stlsoft_C_wcsnstrn()
 *
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNSTRN
#define STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNSTRN

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNSTRN_MAJOR       1
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNSTRN_MINOR       0
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNSTRN_REVISION    1
# define STLSOFT_VER_STLSOFT_STRING_C_STRING_H_STRNSTRN_EDIT        1
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

/** Finds a specific-length (slice of a) string within a specific-length
 * (slice of a) string
 *
 * \param s1 Pointer to the string in which to search
 * \param n1 Length of the string in which to search
 * \param s2 Pointer to the string to find
 * \param n2 Length of the string to find
 *
 * \retval nullptr The string [s2, s2 + n2) is not found in [s1, s1 + n1)
 */
STLSOFT_INLINE
char const*
stlsoft_C_strnstrn(
    char const* s1
,   size_t      n1
,   char const* s2
,   size_t      n2
)
{
    if (0 == n2)
    {
        return s1;
    }

    for (; n1 >= n2; --n1, ++s1)
    {
        if (*s1 == *s2)
        {
            size_t i;

            for (i = 1; i != n2; ++i)
            {
                if (s1[i] != s2[i])
                {
                    break;
                }
            }

            if (i == n2)
            {
                return s1;
            }
        }
    }

    return ss_nullptr_k;
}

/** Finds a specific-length (slice of a) string within a specific-length
 * (slice of a) string
 *
 * \param s1 Pointer to the string in which to search
 * \param n1 Length of the string in which to search
 * \param s2 Pointer to the string to find
 * \param n2 Length of the string to find
 *
 * \retval nullptr The string [s2, s2 + n2) is not found in [s1, s1 + n1)
 */
STLSOFT_INLINE
wchar_t const*
stlsoft_C_wcsnstrn(
    wchar_t const*  s1
,   size_t          n1
,   wchar_t const*  s2
,   size_t          n2
)
{
    if (0 == n2)
    {
        return s1;
    }

    for (; n1 >= n2; --n1, ++s1)
    {
        if (*s1 == *s2)
        {
            size_t i;

            for (i = 1; i != n2; ++i)
            {
                if (s1[i] != s2[i])
                {
                    break;
                }
            }

            if (i == n2)
            {
                return s1;
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
strnstrn(
    char const* s1
,   size_t      n1
,   char const* s2
,   size_t      n2
)
{
    return stlsoft_C_strnstrn(s1, n1, s2, n2);
}

inline
wchar_t const*
strnstrn(
    wchar_t const*  s1
,   size_t          n1
,   wchar_t const*  s2
,   size_t          n2
)
{
    return stlsoft_C_wcsnstrn(s1, n1, s2, n2);
}

inline
wchar_t const*
wcsnstrn(
    wchar_t const*  s1
,   size_t          n1
,   wchar_t const*  s2
,   size_t          n2
)
{
    return stlsoft_C_wcsnstrn(s1, n1, s2, n2);
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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNSTRN */

/* ///////////////////////////// end of file //////////////////////////// */

