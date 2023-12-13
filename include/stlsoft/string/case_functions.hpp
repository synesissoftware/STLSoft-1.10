/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/case_functions.hpp
 *
 * Purpose:     String utility functions for manipulating case.
 *
 * Created:     1st April 2005
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/string/case_functions.hpp
 *
 * \brief [C++] String utility functions for manipulating case
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CASE_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_CASE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CASE_FUNCTIONS_MAJOR       2
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CASE_FUNCTIONS_MINOR       0
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CASE_FUNCTIONS_REVISION    5
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CASE_FUNCTIONS_EDIT        29
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CTYPE_TRAITS
# include <stlsoft/string/ctype_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CTYPE_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS
# include <stlsoft/string/string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_ALGORITHM_STD_HPP_ALT
# include <stlsoft/algorithms/std/alt.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHM_STD_HPP_ALT */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k S
        ,   ss_typename_param_k F
        >
inline S& transform_impl(S& s, F f)
{
    std_transform(s.begin(), s.end(), s.begin(), f);

    return s;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Converts all characters in the string to upper case.
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
inline S& make_upper(S& s)
{
    typedef string_traits<S>                                string_traits_t;
    typedef ss_typename_type_k string_traits_t::char_type   char_t;
    typedef ctype_traits<char_t>                            ctype_traits_t;

    return transform_impl(s, &ctype_traits_t::to_upper);
}

/** Converts all characters in the string to lower case.
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
inline S& make_lower(S& s)
{
    typedef string_traits<S>                                string_traits_t;
    typedef ss_typename_type_k string_traits_t::char_type   char_t;
    typedef ctype_traits<char_t>                            ctype_traits_t;

    return transform_impl(s, &ctype_traits_t::to_lower);
}

/** Returns a copy of the source string in which all characters have
 *   been converted to upper case.
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
inline S to_upper(S const& s)
{
    S   r(s);

    make_upper(r);

    return r;
}

/** Returns a copy of the source string in which all characters have
 *   been converted to lower case.
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
inline S to_lower(S const& s)
{
    S   r(s);

    make_lower(r);

    return r;
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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CASE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

