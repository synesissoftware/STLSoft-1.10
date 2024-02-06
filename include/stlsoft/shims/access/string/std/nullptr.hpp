/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/access/string/std/nullptr.hpp
 *
 * Purpose:     Primary include file for string access shims for nullptr.
 *
 * Created:     12th November 2020
 * Updated:     6th February 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/* STLSOFT:C++98:FILE_DEPRECATED */
/* STLSOFT:C++03:FILE_DEPRECATED */

/** \file stlsoft/shims/access/string/std/nullptr.hpp
 *
 * \brief [C++] Primary include file for string access shims for nullptr
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_NULLPTR
#define STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_NULLPTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_NULLPTR_MAJOR      1
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_NULLPTR_MINOR      0
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_NULLPTR_REVISION   3
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_NULLPTR_EDIT       3
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

#ifndef STLSOFT_CF_nullptr_KEYWORD_SUPPORT
# error This file can only be included when compiler supports nullptr
#endif

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

#ifndef STLSOFT_INCL_H_CSTDDEF
# define STLSOFT_INCL_H_CSTDDEF
# include <cstddef>
#endif /* !STLSOFT_INCL_H_CSTDDEF */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 */

inline
char const*
c_str_data_a(
    std::nullptr_t
)
{
    return "";
}

inline
wchar_t const*
c_str_data_w(
    std::nullptr_t
)
{
    return L"";
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 */

inline
std::size_t
c_str_len_a(
    std::nullptr_t
)
{
    return 0;
}

inline
std::size_t
c_str_len_w(
    std::nullptr_t
)
{
    return 0;
}

inline
std::size_t
c_str_len(
    std::nullptr_t
)
{
    return 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 */

inline
char const*
c_str_ptr_a(
    std::nullptr_t
)
{
    return "";
}

inline
wchar_t const*
c_str_ptr_w(
    std::nullptr_t
)
{
    return L"";
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 */

inline
char const*
c_str_ptr_null_a(
    std::nullptr_t
)
{
    return ss_nullptr_k;
}

inline
wchar_t const*
c_str_ptr_null_w(
    std::nullptr_t
)
{
    return ss_nullptr_k;
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

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_NULLPTR */

/* ///////////////////////////// end of file //////////////////////////// */

