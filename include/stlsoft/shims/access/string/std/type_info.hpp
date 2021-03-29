/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/access/string/std/type_info.hpp
 *
 * Purpose:     Contains the string access shims for std::type_info.
 *
 * Created:     19th December 2011
 * Updated:     16th February 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/shims/access/string/std/type_info.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   <code>std::type_info</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TYPE_INFO
#define STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TYPE_INFO

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TYPE_INFO_MAJOR       2
# define _STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TYPE_INFO_MINOR       3
# define _STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TYPE_INFO_REVISION    3
# define _STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TYPE_INFO_EDIT        54
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR
#  include <stlsoft/error/conversion_error.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_TYPE_INFO
# define STLSOFT_INCL_TYPE_INFO
#  include <typeinfo>               // for std::type_info
#endif /* !STLSOFT_INCL_TYPE_INFO */

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
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct ximpl_stlsoft_shims_access_string_std_type_info_
{
public:
    //
    // *numConverted excludes the nul-terminator
    static
    int
    mbstowcs_(
        ss_char_a_t const*  mbs
    ,   ss_size_t           mbsLen
    ,   ss_char_w_t*        ws
    ,   ss_size_t           wsSizeInChars
    ,   ss_size_t*          numConverted
    )
    {
        // Always assume the nul-terminator
        STLSOFT_ASSERT(NULL != mbs);

        STLSOFT_ASSERT(NULL != numConverted);

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

        int r = ::mbstowcs_s(numConverted, ws, wsSizeInChars, mbs, mbsLen);

        if (0 == r)
        {
            STLSOFT_ASSERT(0 != *numConverted);

            --*numConverted; // mbstowcs_s() always adds one for nul-terminator
        }

        return r;

#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */

        STLSOFT_SUPPRESS_UNUSED(mbsLen);
        STLSOFT_SUPPRESS_UNUSED(wsSizeInChars);

        *numConverted = ::mbstowcs(ws, mbs, mbsLen);
        if (static_cast<ss_size_t>(-1) == *numConverted)
        {
            return errno;
        }

        return 0;
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    }

    //
    // *numConverted excludes the nul-terminator
    static
    int
    mbstowcs_len(
        ss_char_a_t const*  s
    ,   ss_size_t*          len
    )
    {
        STLSOFT_ASSERT(NULL != len);

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

        int r = ::mbstowcs_s(len, NULL, 0, s, 0);

        if (0 == r)
        {
            STLSOFT_ASSERT(0 != *len);

            --*len; // mbstowcs_s() always adds one for nul-terminator
        }

        return r;

#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */

        *len = ::mbstowcs(NULL, s, 0);
        if (static_cast<ss_size_t>(-1) == *len)
        {
            return errno;
        }

        return 0;

#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    }

    static
    int
    throw_conversion_error_or_return_(
        int         err
    ,   char const* message
    )
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(conversion_error(message, err));
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
        STLSOFT_SUPPRESS_UNUSED(message);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return err;
    }
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/** \ref group__concept__Shim__string_access__c_str_data function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
ss_char_a_t const*
c_str_data_a(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_data_a(ti.name());
}

/** \ref group__concept__Shim__string_access__c_str_data function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a C-style
 *   string of <code>wchar_t</code>.
 */
inline
basic_shim_string<ss_char_w_t, 100>
c_str_data_w(STLSOFT_NS_QUAL_STD(type_info) const& ti)
{
    // C-string pointer and length
    ss_char_a_t const* const    s   = ti.name();
    ss_size_t const             len = ::strlen(s);

    // Calculate the wide-string length
    ss_size_t   wlen;
    int         err = ximpl_stlsoft_shims_access_string_std_type_info_::mbstowcs_len(s, &wlen);

    // handle failure to get length
    if (0 != err)
    {
        ximpl_stlsoft_shims_access_string_std_type_info_::throw_conversion_error_or_return_(err, "cannot elicit wide-string length of type_info message");
    }

    // Create the shim string, which will be returned
    basic_shim_string<ss_char_w_t, 100> r(wlen);
    ss_size_t                           wlen2;

    err = ximpl_stlsoft_shims_access_string_std_type_info_::mbstowcs_(s, len, r.data(), 1u + r.size(), &wlen2);

    // Sanity checks
    STLSOFT_ASSERT(wlen2 == r.size());
    STLSOFT_SUPPRESS_UNUSED(wlen2);

    // handle failure to convert
    if (0 != err)
    {
        ximpl_stlsoft_shims_access_string_std_type_info_::throw_conversion_error_or_return_(err, "cannot elicit wide-string equivalent of type_info message");
    }

    return r;
}

/** \ref group__concept__Shim__string_access__c_str_data function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a C-style string.
 */
inline
ss_char_a_t const*
c_str_data(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_data_a(ti);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/** \ref group__concept__Shim__string_access__c_str_len function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Length (in bytes) of the string <code>s</code>.
 */
inline
ss_size_t
c_str_len_a(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_len_a(ti.name());
}

/** \ref group__concept__Shim__string_access__c_str_len function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Length (in bytes) of the string <code>s</code>.
 */
inline
ss_size_t
c_str_len_w(STLSOFT_NS_QUAL_STD(type_info) const& ti)
{
    ss_size_t   len;
    int         err = ximpl_stlsoft_shims_access_string_std_type_info_::mbstowcs_len(ti.name(), &len);

    if (0 != err)
    {
        ximpl_stlsoft_shims_access_string_std_type_info_::throw_conversion_error_or_return_(err, "failed to elicit length of multibyte string");

        len = 0;
    }

    return len;
}

/** \ref group__concept__Shim__string_access__c_str_len function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Length of the string <code>s</code>.
 */
inline
ss_size_t
c_str_len(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_len_a(ti);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/** \ref group__concept__Shim__string_access__c_str_ptr function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a nul-terminated C-style
 *   string of <code>char</code>.
 */
inline
ss_char_a_t const*
c_str_ptr_a(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_ptr_a(ti.name());
}

/** \ref group__concept__Shim__string_access__c_str_ptr function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a nul-terminated C-style
 *   string of <code>wchar_t</code>.
 */
inline
basic_shim_string<ss_char_w_t, 100>
c_str_ptr_w(STLSOFT_NS_QUAL_STD(type_info) const& ti)
{
    return c_str_data_w(ti);
}

/** \ref group__concept__Shim__string_access__c_str_ptr function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a nul-terminated C-style
 *   string.
 */
inline
ss_char_a_t const*
c_str_ptr(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_ptr_a(ti);
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/** \ref group__concept__Shim__string_access__c_str_ptr_null function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Possibly NULL, non-mutating pointer to a nul-terminated C-style
 *   string of <code>char</code>.
 */
inline
ss_char_a_t const*
c_str_ptr_null_a(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_ptr_null_a(ti.name());
}

/** \ref group__concept__Shim__string_access__c_str_ptr_null function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Possibly NULL, non-mutating pointer to a nul-terminated C-style
 *   string of <code>wchar_t</code>.
 */
inline
basic_shim_string<ss_char_w_t, 100, true>
c_str_ptr_null_w(STLSOFT_NS_QUAL_STD(type_info) const& ti)
{
    // C-string pointer and length
    ss_char_a_t const* const    s   = ti.name();
    ss_size_t const             len = ::strlen(s);

    // Calculate the wide-string length
    ss_size_t   wlen;
    int         err = ximpl_stlsoft_shims_access_string_std_type_info_::mbstowcs_len(s, &wlen);

    // handle failure to get length
    if (0 != err)
    {
        ximpl_stlsoft_shims_access_string_std_type_info_::throw_conversion_error_or_return_(err, "cannot elicit wide-string length of type_info message");
    }

    // Create the shim string, which will be returned
    basic_shim_string<ss_char_w_t, 100, true>  r(wlen);
    ss_size_t                                  wlen2;

    err = ximpl_stlsoft_shims_access_string_std_type_info_::mbstowcs_(s, len, r.data(), 1u + r.size(), &wlen2);

    // Sanity checks
    STLSOFT_ASSERT(wlen2 == r.size());
    STLSOFT_SUPPRESS_UNUSED(wlen2);

    // handle failure to convert
    if (0 != err)
    {
        ximpl_stlsoft_shims_access_string_std_type_info_::throw_conversion_error_or_return_(err, "cannot elicit wide-string equivalent of type_info message");
    }

    return r;
}

/** \ref group__concept__Shim__string_access__c_str_ptr_null function
 *    for <code>std::type_info</code>.
 *
 * \ingroup group__concept__Shim__string_access
 *
 * \return Possibly NULL, non-mutating pointer to a nul-terminated C-style
 *   string.
 */
inline
ss_char_a_t const*
c_str_ptr_null(
    STLSOFT_NS_QUAL_STD(type_info) const& ti
)
{
    return c_str_ptr_null_a(ti);
}

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

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TYPE_INFO */

/* ///////////////////////////// end of file //////////////////////////// */

