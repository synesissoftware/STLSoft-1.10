/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/access/string/std/basic_string_view.hpp
 *
 * Purpose:     Contains the c_str_data and c_str_len accessors.
 *
 * Created:     21st October 2020
 * Updated:     26th October 2020
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


/** \file stlsoft/shims/access/string/std/basic_string_view.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   std::basic_string_view
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING_VIEW
#define STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING_VIEW

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING_VIEW_MAJOR    1
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING_VIEW_MINOR    0
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING_VIEW_REVISION 2
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING_VIEW_EDIT     2
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

#ifndef STLSOFT_INCL_STRING_VIEW
# include <string_view>
#endif /* !STLSOFT_INCL_STRING_VIEW */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

inline
ss_char_a_t const*
c_str_data_a(
    std::string_view const& v
) STLSOFT_NOEXCEPT
{
    return v.data();
}

inline
ss_char_w_t const*
c_str_data_w(
    std::wstring_view const& v
) STLSOFT_NOEXCEPT
{
    return v.data();
}

template <ss_typename_param_k T_char>
inline
T_char const*
c_str_data(
    std::basic_string_view<T_char> const& v
) STLSOFT_NOEXCEPT
{
    return v.data();
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

inline
ss_size_t
c_str_len_a(
    std::string_view const& v
) STLSOFT_NOEXCEPT
{
    return v.size();
}

inline
ss_size_t
c_str_len_w(
    std::wstring_view const& v
) STLSOFT_NOEXCEPT
{
    return v.size();
}

template <ss_typename_param_k T_char>
inline
ss_size_t
c_str_len(
    std::basic_string_view<T_char> const& v
) STLSOFT_NOEXCEPT
{
    return v.size();
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

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_STRING_VIEW */

/* ///////////////////////////// end of file //////////////////////////// */

