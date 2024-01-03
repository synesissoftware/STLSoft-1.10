/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/conversion/number/grouping_functions.hpp
 *
 * Purpose:     Number formatting functions.
 *
 * Created:     28th August 2005
 * Updated:     16th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/conversion/number/grouping_functions.hpp
 *
 * \brief [C++] Definition of the winstl::format_thousands() formatting
 *   function
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS
#define WINSTL_INCL_WINSTL_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_REVISION    9
# define WINSTL_VER_WINSTL_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS_EDIT        26
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS
# include <stlsoft/conversion/number/grouping_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#if 0
template<
    ss_typename_param_k C
,   ss_typename_param_k N
>
ws_size_t
format_thousands(
    C*                  dest
,   ws_size_t           cchDest
,   N const&            number
);
#endif /* 0 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k C
,   ss_typename_param_k I
>
inline
ws_size_t
format_thousands_3_impl(
    C*                  dest
,   ws_size_t           cchDest
,   I const&            number
,   stlsoft::yes_type
)
{
    typedef system_traits<C>    traits_t;

    int                     cch =   traits_t::get_locale_info(LOCALE_USER_DEFAULT, LOCALE_SGROUPING, NULL, 0);
    stlsoft::auto_buffer<C> picture(1 + cch);

    cch = traits_t::get_locale_info(LOCALE_USER_DEFAULT, LOCALE_SGROUPING, &picture[0], int(picture.size()));

    return stlsoft::format_thousands(dest, cchDest, picture.data(), number);
}

template <ss_typename_param_k C>
inline
ws_size_t
format_thousands_3_impl(
    C*                  dest
,   ws_size_t           cchDest
,   C const*            number
,   stlsoft::no_type
)
{
    typedef system_traits<C>    traits_t;

    int                     cch =   traits_t::get_locale_info(LOCALE_USER_DEFAULT, LOCALE_SGROUPING, NULL, 0);
    stlsoft::auto_buffer<C> picture(1 + cch);

    cch = traits_t::get_locale_info(LOCALE_USER_DEFAULT, LOCALE_SGROUPING, &picture[0], picture.size());

    return stlsoft::translate_thousands(dest, cchDest, picture.data(), number);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

template<
    ss_typename_param_k C
,   ss_typename_param_k N
>
inline
ws_size_t
format_thousands(
    C*                  dest
,   ws_size_t           cchDest
,   N const&            number
)
{
    typedef ss_typename_type_k stlsoft::is_integral_type<N>::type   yesno_t;

    return format_thousands_3_impl(dest, cchDest, number, yesno_t());
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_CONVERSION_NUMBER_HPP_GROUPING_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

