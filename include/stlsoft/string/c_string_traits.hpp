/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/c_string_traits.hpp
 *
 * Purpose:     Contains the c_string_traits class template.
 *
 * Created:     15th November 2002
 * Updated:     2nd January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/c_string_traits.hpp
 *
 * \brief [C++] Definition of the stlsoft::c_string_traits traits
 *  class template
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_C_STRING_TRAITS_MAJOR       6
# define STLSOFT_VER_STLSOFT_STRING_HPP_C_STRING_TRAITS_MINOR       0
# define STLSOFT_VER_STLSOFT_STRING_HPP_C_STRING_TRAITS_REVISION    2
# define STLSOFT_VER_STLSOFT_STRING_HPP_C_STRING_TRAITS_EDIT        162
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_WINSTL
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

#if 0
#elif defined(STLSOFT_MIN_CRT) && \
      defined(_WIN32)

# ifndef STLSOFT_INCL_H_WINDOWS
#  define STLSOFT_INCL_H_WINDOWS
#  include <windows.h>   /* Windows base header */
# endif /* !STLSOFT_INCL_H_WINDOWS */
#endif /* STLSOFT_MIN_CRT */

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

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** Traits for accessing the correct system functions for a given
 *   character type.
 *
 * \ingroup group__library__System
 *
 * c_string_traits is a traits class for determining the correct system
 * structures and functions for a given character type.
 *
 * \param C The character type (e.g. \c char, \c wchar_t)
 */
template <ss_typename_param_k C>
struct c_string_traits
{
/// \name Types
/// @{
public:
    /// The character type
    typedef C                                               char_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The difference type
    typedef ss_ptrdiff_t                                    difference_type;
    /// The current instantion of the type
    typedef c_string_traits<C>                              class_type;
    /// The (signed) integer type
    typedef ss_int_t                                        int_type;
    /// The Boolean type
    typedef ss_bool_t                                       bool_type;
/// @}

/// \name General string handling
/// @{
public:
    /// Copies a specific number of characters from the source to the destination
    static char_type*   char_copy(char_type* dest, char_type const* src, size_type n);
    /// Compares the contents of \c src and \c dest
    static int_type     str_compare(char_type const* s1, char_type const* s2);
    /// Compares the contents of \c src and \c dest in a case-insensitive fashion
    static int_type     str_compare_no_case(char_type const* s1, char_type const* s2);
    /// Compares the contents of \c src and \c dest up to \c cch characters
    static int_type     str_n_compare(char_type const* s1, char_type const* s2, size_type cch);
    /// Compares the contents of \c src and \c dest up to \c cch characters
    static int_type     str_n_compare_no_case(char_type const* s1, char_type const* s2, size_type cch);
    /// Evaluates the length of \c src
    static size_type    str_len(char_type const* src);
    /// Finds the given character \c ch in \c s
    static char_type*   str_chr(char_type const* s, char_type ch);
    /// Finds the rightmost instance \c ch in \c s
    static char_type*   str_rchr(char_type const* s, char_type ch);
    /// Finds the given substring \c sub in \c s
    static char_type*   str_str(char_type const* s, char_type const* sub);
    /// Finds one of a set of characters in \c s
    static char_type*   str_pbrk(char_type const* s, char_type const* charSet);
    /// Returns a pointer to the end of the string
    static char_type*   str_end(char_type const* s);
    /// Sets each character in \c s to the character \c c
    ///
    /// \return s + n
    static char_type*   str_set(char_type* s, size_type n, char_type c);
/// @}
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct c_string_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct c_string_traits<ss_char_a_t>
{
public:
    typedef ss_char_a_t                                     char_type;
    typedef ss_size_t                                       size_type;
    typedef ss_ptrdiff_t                                    difference_type;
    typedef c_string_traits<char_type>                      class_type;
    typedef ss_int_t                                        int_type;
    typedef ss_bool_t                                       bool_type;

public:
    static char_type* char_copy(char_type* dest, char_type const* src, size_type n)
    {
        STLSOFT_ASSERT(NULL != dest);
        STLSOFT_ASSERT(0 == n || NULL != src);

        return static_cast<char_type*>(STLSOFT_API_INTERNAL_memfns_memcpy(dest, src, sizeof(char_type) * n));
    }

    static int_type str_compare(char_type const* s1, char_type const* s2)
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

#if defined(STLSOFT_MIN_CRT) && \
      defined(_WIN32)
        return ::lstrcmpA(s1, s2);
#else /*? STLSOFT_MIN_CRT */
        return ::strcmp(s1, s2);
#endif /* STLSOFT_MIN_CRT */
    }

    static int_type str_compare_no_case(char_type const* s1, char_type const* s2)
#ifdef STLSOFT_API_EXTERNAL_string_stricmp
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

        return STLSOFT_API_EXTERNAL_string_stricmp(s1, s2);
    }
#else
    ;
#endif

    static int_type str_n_compare(char_type const* s1, char_type const* s2, size_type cch)
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

        return ::strncmp(s1, s2, cch);
    }

    static int_type str_n_compare_no_case(char_type const* s1, char_type const* s2, size_type cch)
#ifdef STLSOFT_API_EXTERNAL_string_strnicmp
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

        return STLSOFT_API_EXTERNAL_string_strnicmp(s1, s2, cch);
    }
#else
    ;
#endif

    static size_type str_len(char_type const* src)
    {
        STLSOFT_ASSERT(NULL != src);

#if defined(STLSOFT_MIN_CRT) && \
      defined(_WIN32)
        return static_cast<size_type>(::lstrlenA(src));
#else /*? STLSOFT_MIN_CRT */
        return ::strlen(src);
#endif /* STLSOFT_MIN_CRT */
    }

    static char_type* str_chr(char_type const* s, char_type ch)
    {
        STLSOFT_ASSERT(NULL != s);

        return const_cast<char_type*>(::strchr(s, ch));
    }

    static char_type* str_rchr(char_type const* s, char_type ch)
    {
        STLSOFT_ASSERT(NULL != s);

        return const_cast<char_type*>(::strrchr(s, ch));
    }

    static char_type* str_str(char_type const* s, char_type const* sub)
    {
        STLSOFT_ASSERT(NULL != s);
        STLSOFT_ASSERT(NULL != sub);

        return const_cast<char_type*>(::strstr(s, sub));
    }

    static char_type* str_pbrk(char_type const* s, char_type const* charSet)
    {
        STLSOFT_ASSERT(NULL != s);
        STLSOFT_ASSERT(NULL != charSet);

        return const_cast<char_type*>(::strpbrk(s, charSet));
    }

    static char_type* str_end(char_type const* s)
    {
        STLSOFT_ASSERT(NULL != s);

        for (; *s != '\0'; ++s)
        {}

        return const_cast<char_type*>(s);
    }

    static char_type* str_set(char_type* s, size_type n, char_type c)
    {
        STLSOFT_ASSERT(NULL != s || 0u == n);

        for (; 0u != n; --n, ++s)
        {
            *s = c;
        }

        return s;
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct c_string_traits<ss_char_w_t>
{
public:
    typedef ss_char_w_t                                     char_type;
    typedef ss_size_t                                       size_type;
    typedef ss_ptrdiff_t                                    difference_type;
    typedef c_string_traits<char_type>                      class_type;
    typedef ss_int_t                                        int_type;
    typedef ss_bool_t                                       bool_type;

public:
    static char_type* char_copy(char_type* dest, char_type const* src, size_type n)
    {
        STLSOFT_ASSERT(NULL != dest);
        STLSOFT_ASSERT(0 == n || NULL != src);

        return static_cast<char_type*>(STLSOFT_API_INTERNAL_memfns_memcpy(dest, src, sizeof(char_type) * n));
    }

    static int_type str_compare(char_type const* s1, char_type const* s2)
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

#if defined(STLSOFT_MIN_CRT) && \
      defined(_WIN32)
        return ::lstrcmpW(s1, s2);
#else /*? STLSOFT_MIN_CRT */
        return ::wcscmp(s1, s2);
#endif /* STLSOFT_MIN_CRT */
    }

    static int_type str_compare_no_case(char_type const* s1, char_type const* s2)
#ifdef STLSOFT_API_EXTERNAL_string_wcsicmp
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

        return STLSOFT_API_EXTERNAL_string_wcsicmp(s1, s2);
    }
#else
    ;
#endif

    static int_type str_n_compare(char_type const* s1, char_type const* s2, size_type cch)
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

        return ::wcsncmp(s1, s2, cch);
    }

    static int_type str_n_compare_no_case(char_type const* s1, char_type const* s2, size_type cch)
#ifdef STLSOFT_API_EXTERNAL_string_wcsnicmp
    {
        STLSOFT_ASSERT(NULL != s1);
        STLSOFT_ASSERT(NULL != s2);

        return STLSOFT_API_EXTERNAL_string_wcsnicmp(s1, s2, cch);
    }
#else
    ;
#endif

    static size_type str_len(char_type const* src)
    {
        STLSOFT_ASSERT(NULL != src);

#if defined(STLSOFT_MIN_CRT) && \
      defined(_WIN32)
        return static_cast<size_type>(::lstrlenW(src));
#else /*? STLSOFT_MIN_CRT */
        return ::wcslen(src);
#endif /* STLSOFT_MIN_CRT */
    }

    static char_type* str_chr(char_type const* s, char_type ch)
    {
        STLSOFT_ASSERT(NULL != s);

        return const_cast<char_type*>(::wcschr(s, ch));
    }

    static char_type* str_rchr(char_type const* s, char_type ch)
    {
        STLSOFT_ASSERT(NULL != s);

        return const_cast<char_type*>(::wcsrchr(s, ch));
    }

    static char_type* str_str(char_type const* s, char_type const* sub)
    {
        STLSOFT_ASSERT(NULL != s);
        STLSOFT_ASSERT(NULL != sub);

        return const_cast<char_type*>(::wcsstr(s, sub));
    }

    static char_type* str_pbrk(char_type const* s, char_type const* charSet)
    {
        STLSOFT_ASSERT(NULL != s);
        STLSOFT_ASSERT(NULL != charSet);

        return const_cast<char_type*>(::wcspbrk(s, charSet));
    }

    static char_type* str_end(char_type const* s)
    {
        STLSOFT_ASSERT(NULL != s);

        for (; *s != L'\0'; ++s)
        {}

        return const_cast<char_type*>(s);
    }

    static char_type* str_set(char_type* s, size_type n, char_type c)
    {
        STLSOFT_ASSERT(NULL != s || 0u == n);

        for (; 0u != n; --n, ++s)
        {
            *s = c;
        }

        return s;
    }
};

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

