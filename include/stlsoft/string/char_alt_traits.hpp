/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/char_alt_traits.hpp
 *
 * Purpose:     char_alt_traits traits class.
 *
 * Created:     19th November 1998
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/char_alt_traits.hpp
 *
 * \brief [C++] Definition of the stlsoft::char_alt_traits traits
 *  class
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS_MAJOR    4
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS_MINOR    0
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS_REVISION 4
# define STLSOFT_VER_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS_EDIT     45
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
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * constraints
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** Traits for determining the alternate character type
 *
 * char_alt_traits is a traits class for acquiring the opposite character type
 * eg. char_alt_traits<char>::alt_char_type == wchar_t, and vice versa
 *
 * \param C The char type
 *
 * \ingroup group__library__String
 */
template <class C>
struct char_alt_traits
{
    typedef C               char_type;      //!< The char type
    typedef not C           alt_char_type;  //!< The alternatve char type
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <class C>
struct char_alt_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct char_alt_traits<ss_char_a_t>
{
    typedef ss_char_a_t     char_type;
    typedef ss_char_w_t     alt_char_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct char_alt_traits<ss_char_w_t>
{
    typedef ss_char_w_t     char_type;
    typedef ss_char_a_t     alt_char_type;
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_ALT_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

