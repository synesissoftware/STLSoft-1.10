/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/access/string/std/time.hpp
 *
 * Purpose:     String shims for standard time structures.
 *
 * Created:     25th July 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/shims/access/string/std/time.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   standard time structures
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME
#define STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME_MAJOR     3
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME_MINOR     1
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME_REVISION  0
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME_EDIT      38
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
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */

#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * shims
 *
 * All the struct tm-related conversions assume a format of 20 characters
 */

/* struct tm const* */

/** \ref group__concept__Shim__string_access__c_str_data function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, non-mutating pointer to a C-style string
 *   of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    struct tm const* t
)
{
    typedef basic_shim_string<ss_char_a_t>  shim_string_t;

    if (NULL == t)
    {
        return shim_string_t();
    }
    else
    {
        ss_char_a_t     fmt[101];
        ss_size_t const n0  =   STLSOFT_NS_GLOBAL(strftime)(&fmt[0], STLSOFT_NUM_ELEMENTS(fmt), "%a %b %%d %%H:%%M:%%S %%Y", t);

        if (0 != n0)
        {
            shim_string_t   s(n0 + 2);
            ss_size_t const n1  =   STLSOFT_NS_GLOBAL(strftime)(s.data(), 1 + s.size(), fmt, t);

            if (0 != n1)
            {
                STLSOFT_ASSERT(n1 <= s.size());

                s.truncate(n1);

                return s;
            }
        }
    }

    return shim_string_t("(invalid time)");
}

/* SAS-like conversion function taking time format parameter
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \param t Pointer to time value to be converted
 * \param fmt Custom format string. Must not be \c null
 *
 * \return None-<code>NULL</code>, non-mutating pointer to a C-style string
 *   of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    struct tm const*    t
,   ss_char_a_t const*  fmt
)
{
    STLSOFT_ASSERT(NULL != fmt);

    typedef basic_shim_string<ss_char_a_t>  shim_string_t;

    if (NULL == t)
    {
        return shim_string_t();
    }
    else
    {
        ss_size_t const n   =   c_str_len_a(fmt);
        shim_string_t   s(2 + 7 * n);
        ss_size_t const n1  =   STLSOFT_NS_GLOBAL(strftime)(s.data(), 1 + s.size(), fmt, t);

        if (0 != n1)
        {
            STLSOFT_ASSERT(n1 <= s.size());

            s.truncate(n1);

            return s;
        }
    }

    return shim_string_t("(invalid time)");
}

/** \ref group__concept__Shim__string_access__c_str_data function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, non-mutating pointer to a C-style string
 *   of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data(
    struct tm const* t
)
{
    return c_str_data_a(t);
}


/** \ref group__concept__Shim__string_access__c_str_len function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Length of the string form of <code>t</code>.
 */
inline
ss_size_t
c_str_len_a(
    struct tm const* t
)
{
    if (NULL == t)
    {
        return 0;
    }
    else
    {
        ss_char_a_t     sz[101];
        ss_size_t const n1  =   STLSOFT_NS_GLOBAL(strftime)(&sz[0], STLSOFT_NUM_ELEMENTS(sz), "%a %b", t);

        if (0 != n1)
        {
            // See implementation of c_str_data_a(struct tm const*)
            return 17 + n1;
        }

        return 14;
    }
}

/* SAS-like conversion function taking time format parameter
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \param t Pointer to time value to be converted
 * \param fmt Custom format string. Must not be \c null
 *
 * \return Length of the string form of <code>t</code>.
 */
inline
ss_size_t
c_str_len_a(
    struct tm const*    t
,   ss_char_a_t const*  fmt
)
{
    STLSOFT_ASSERT(NULL != fmt);

    if (NULL == t)
    {
        return 0;
    }
    else
    {
        ss_char_a_t     sz[101];
        ss_size_t const n1  =   STLSOFT_NS_GLOBAL(strftime)(&sz[0], STLSOFT_NUM_ELEMENTS(sz), fmt, t);

        if (0 != n1)
        {
            return n1;
        }

        return 14;
    }
}

/** \ref group__concept__Shim__string_access__c_str_len function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Length of the string form of <code>t</code>.
 */
inline
ss_size_t
c_str_len(
    struct tm const* t
)
{
    return c_str_len_a(t);
}


/** \ref group__concept__Shim__string_access__c_str_ptr function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, <code>nul</code>-terminated, non-mutating
 *   pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_a(
    struct tm const* t
)
{
    return c_str_data_a(t);
}

/* SAS-like conversion function taking time format parameter
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \param t Pointer to time value to be converted
 * \param fmt Custom format string. Must not be \c null
 *
 * \return None-<code>NULL</code>, <code>nul</code>-terminated, non-mutating
 *   pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_a(
    struct tm const*    t
,   ss_char_a_t const*  fmt
)
{
    return c_str_data_a(t, fmt);
}

/** \ref group__concept__Shim__string_access__c_str_ptr function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, <code>nul</code>-terminated, non-mutating
 *   pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr(
    struct tm const* t
)
{
    return c_str_data_a(t);
}


/** \ref group__concept__Shim__string_access__c_str_ptr_null function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Possibly <code>NULL</code>, <code>nul</code>-terminated,
 *   non-mutating pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null_a(
    struct tm const* t
)
{
    return c_str_data_a(t);
}

/** \ref group__concept__Shim__string_access__c_str_ptr_null function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Possibly <code>NULL</code>, <code>nul</code>-terminated,
 *   non-mutating pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null(
    struct tm const* t
)
{
    return c_str_data_a(t);
}

/* struct tm const& */

/** \ref group__concept__Shim__string_access__c_str_data function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, non-mutating pointer to a C-style string
 *   of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    struct tm const& t
)
{
    return c_str_data_a(&t);
}

/* SAS-like conversion function taking time format parameter
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \param t Time value to be converted
 * \param fmt Custom format string. Must not be \c null
 *
 * \return None-<code>NULL</code>, non-mutating pointer to a C-style string
 *   of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    struct tm const&    t
,   ss_char_a_t const*  fmt
)
{
    return c_str_data_a(&t, fmt);
}

/** \ref group__concept__Shim__string_access__c_str_data function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, non-mutating pointer to a C-style string
 *   of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data(
    struct tm const& t
)
{
    return c_str_data(&t);
}

/** \ref group__concept__Shim__string_access__c_str_len function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Length of the string form of <code>t</code>.
 */
inline
ss_size_t
c_str_len_a(
    struct tm const& t
)
{
    return c_str_len_a(&t);
}

/* SAS-like conversion function taking time format parameter
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \param t Pointer to time value to be converted
 * \param fmt Custom format string. Must not be \c null
 *
 * \return Length of the string form of <code>t</code>.
 */
inline
ss_size_t
c_str_len_a(
    struct tm const&    t
,   ss_char_a_t const*  fmt
)
{
    return c_str_len_a(&t, fmt);
}

/** \ref group__concept__Shim__string_access__c_str_len function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Length of the string form of <code>t</code>.
 */
inline
ss_size_t
c_str_len(
    struct tm const& t
)
{
    return c_str_len(&t);
}


/** \ref group__concept__Shim__string_access__c_str_ptr function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, <code>nul</code>-terminated, non-mutating
 *   pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_a(
    struct tm const& t
)
{
    return c_str_ptr_a(&t);
}

/* SAS-like conversion function taking time format parameter
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \param t Pointer to time value to be converted
 * \param fmt Custom format string. Must not be \c null
 *
 * \return None-NULL, nul-terminated, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_a(
    struct tm const&    t
,   ss_char_a_t const*  fmt
)
{
    return c_str_data_a(&t, fmt);
}

/** \ref group__concept__Shim__string_access__c_str_ptr function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-<code>NULL</code>, <code>nul</code>-terminated, non-mutating
 *   pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr(
    struct tm const& t
)
{
    return c_str_ptr(&t);
}


/** \ref group__concept__Shim__string_access__c_str_ptr_null function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Possibly <code>NULL</code>, <code>nul</code>-terminated,
 *   non-mutating pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null_a(
    struct tm const& t
)
{
    return c_str_ptr_null_a(&t);
}

/** \ref group__concept__Shim__string_access__c_str_ptr_null function
 *    for <code>struct tm</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Possibly <code>NULL</code>, <code>nul</code>-terminated,
 *   non-mutating pointer to a C-style string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null(
    struct tm const& t
)
{
    return c_str_ptr_null(&t);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME */

/* ///////////////////////////// end of file //////////////////////////// */

