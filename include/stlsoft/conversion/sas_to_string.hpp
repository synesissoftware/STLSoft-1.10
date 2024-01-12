/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/sas_to_string.hpp
 *
 * Purpose:     String creation functions (from String Access Shims)
 *
 * Created:     25th December 2018
 * Updated:     12th January 2024
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


/** \file stlsoft/conversion/sas_to_string.hpp
 *
 * \brief [C++] String creation functions (from String Access Shims)
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING_MAJOR    1
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING_MINOR    1
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING_REVISION 3
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING_EDIT     9
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace stlsoft {

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Obtains the string form of a given instance, via the String Access Shims
 * <code>c_str_data_a()</code> and <code>c_str_len_a()</code>.
 *
 * \param arg0 The instance to be converted
 */
template <ss_typename_param_k T_arg>
inline
std::basic_string<char>
sas_to_string_m(
    T_arg const&    arg0
)
{
    return std::basic_string<char>(
        static_cast<char const*>(STLSOFT_NS_QUAL(c_str_data_a)(arg0))
    ,   static_cast<size_t>(STLSOFT_NS_QUAL(c_str_len_a)(arg0))
    );
}

/** Obtains the string form of a given instance, via SAS-like overloads of
 * <code>c_str_data_a()</code> and <code>c_str_len_a()</code>.
 *
 * \param arg0 The instance to be converted
 * \param arg1 The qualifying argument
 */
template<
    ss_typename_param_k T_arg0
#if 1
,   ss_typename_param_k T_arg1
#endif
>
inline
std::basic_string<char>
sas_to_string_m(
    T_arg0 const&       arg0
#if 0
,   ss_char_a_t const*  fmt
#else
,   T_arg1 const&       arg1
#endif
)
{
    return std::basic_string<char>(
        static_cast<char const*>(STLSOFT_NS_QUAL(c_str_data_a)(arg0, arg1))
    ,   static_cast<size_t>(STLSOFT_NS_QUAL(c_str_len_a)(arg0, arg1))
    );
}

/** Obtains the string form of a given instance, via the String Access Shims
 * <code>c_str_data_w()</code> and <code>c_str_len_w()</code>.
 *
 * \param arg0 The instance to be converted
 */
template <ss_typename_param_k T_arg>
inline
std::basic_string<wchar_t>
sas_to_string_w(
    T_arg const&    arg0
)
{
    return std::basic_string<wchar_t>(
        static_cast<wchar_t const*>(STLSOFT_NS_QUAL(c_str_data_w)(arg0))
    ,   static_cast<size_t>(STLSOFT_NS_QUAL(c_str_len_w)(arg0))
    );
}

/** Obtains the string form of a given instance, via the String Access Shims
 * <code>c_str_data_a()</code> and <code>c_str_len_a()</code>.
 *
 * \param arg0 The instance to be converted
 */
template <ss_typename_param_k T_arg>
inline
std::string
sas_to_string(
    T_arg const&    arg0
)
{
    return sas_to_string_m(arg0);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace stlsoft */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

