/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/access/string/std/chrono.hpp
 *
 * Purpose:     Contains the c_str_data and c_str_len accessors.
 *
 * Created:     25th October 2020
 * Updated:     18th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020-2021, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/shims/access/string/std/chrono.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   chrono types
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_CHRONO
#define STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_CHRONO

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_CHRONO_MAJOR     1
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_CHRONO_MINOR     0
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_CHRONO_REVISION  3
# define STLSOFT_VER_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_BASIC_CHRONO_EDIT      3
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME
# include<stlsoft/shims/access/string/std/time.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_time
# include <stlsoft/api/internal/time.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_time */

#ifndef STLSOFT_INCL_CHRONO
# define STLSOFT_INCL_CHRONO
# include <chrono>
#endif /* !STLSOFT_INCL_CHRONO */

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

#if 0

template<
    typename T_clock
,   typename T_duration
>
inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    std::chrono::time_point<T_clock, T_duration> const&    tp
);
#else

inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    std::chrono::system_clock::time_point const& tp
)
{
    typedef basic_shim_string<ss_char_a_t>  shim_string_t;

    time_t const    t   =   std::chrono::system_clock::to_time_t(tp);
    struct tm       tm;
    int const       r   =   STLSOFT_API_INTERNAL_Time_localtime(&tm, &t);

    if (0 != r)
    {
        return shim_string_t("(invalid time)");
    }
    else
    {
        return c_str_data_a(&tm);
    }
}
#endif

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

#if 0

template<
    typename T_clock
,   typename T_duration
>
inline
ss_size_t
c_str_len_a(
    std::chrono::time_point<T_clock, T_duration> const&    tp
)
{

}
#else

inline
ss_size_t
c_str_len_a(
    std::chrono::system_clock::time_point const& tp
)
{
    time_t const    t   =   std::chrono::system_clock::to_time_t(tp);
    struct tm       tm;
    int const       r   =   STLSOFT_API_INTERNAL_Time_localtime(&tm, &t);

    if (0 != r)
    {
        return 14u;
    }
    else
    {
        return c_str_len_a(&tm);
    }
}
#endif

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

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_CHRONO */

/* ///////////////////////////// end of file //////////////////////////// */

