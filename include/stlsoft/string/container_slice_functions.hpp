/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/container_slice_functions.hpp
 *
 * Purpose:     String container slice functions.
 *
 * Created:     25th April 2005
 * Updated:     22nd January 2024
 *
 * Thanks:      To Pablo Aguilar for inspiration for these functions.
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


/** \file stlsoft/string/container_slice_functions.hpp
 *
 * \brief [C++] String container slice functions
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS_MAJOR    2
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS_MINOR    1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS_REVISION 8
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS_EDIT     39
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS
# include <stlsoft/string/string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_TRAITS */
#if !defined(STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE)
# if defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_std_basic_string) || \
     defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_STD_BASIC_STRING)
#  include <string>
# else /* ? std::basic_string */
#  ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
#   include <stlsoft/string/simple_string.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */
# endif /* std::basic_string */
#endif /* !STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX
# include <stlsoft/util/minmax.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k S>
inline ss_size_t left_len(S const& s, ss_size_t n)
{
    const ss_size_t len = STLSOFT_NS_QUAL(c_str_len)(s);

    if (n > len)
    {
        n = len;
    }

    return n;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * string class functions
 */

/**
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
inline S left(S const& s, ss_size_t n)
{
    typedef string_traits<S>    traits_t;

    return traits_t::construct(s, 0, left_len(s, n));
}

/**
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
inline S right(S const& s, ss_size_t n)
{
    typedef string_traits<S>    traits_t;

    const ss_size_t len = STLSOFT_NS_QUAL(c_str_len)(s);

    if (n > len)
    {
        n = len;
    }

    return traits_t::construct(s, len - n, n);
}

/**
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
inline S mid(S const& s, ss_size_t pos, ss_size_t n)
{
    typedef string_traits<S>    traits_t;

    const ss_size_t len = STLSOFT_NS_QUAL(c_str_len)(s);

    if (pos > len)
    {
        pos = len;
    }

    if (n > len - pos)
    {
        n = len - pos;
    }

    return traits_t::construct(s, pos, n);
}

/* /////////////////////////////////////////////////////////////////////////
 * C-style string slice functions
 */

#if defined(STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE)
# define _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE  STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE
#elif defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_std_basic_string) || \
      defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_STD_BASIC_STRING)
# define _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE  STLSOFT_NS_QUAL_STD(basic_string)
#else /* ? STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE */
# define _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE  STLSOFT_NS_QUAL(basic_simple_string)
#endif /* !STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE */


/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> left(ss_char_a_t const* s, ss_size_t n)
{
    typedef _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> string_t;

    return string_t(s, left_len(s, n));
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> left(ss_char_a_t *s, ss_size_t n)
{
    return left(const_cast<ss_char_a_t const*>(s), n);
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> left(ss_char_w_t const* s, ss_size_t n)
{
    typedef _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> string_t;

    return string_t(s, left_len(s, n));
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> left(ss_char_w_t *s, ss_size_t n)
{
    return left(const_cast<ss_char_w_t const*>(s), n);
}


/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> right(ss_char_a_t const* s, ss_size_t n)
{
    typedef _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> string_t;

    const ss_size_t len = STLSOFT_NS_QUAL(c_str_len)(s);

    if (n > len)
    {
        n = len;
    }

    return string_t(s + (len - n), n);
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> right(ss_char_a_t *s, ss_size_t n)
{
    return right(const_cast<ss_char_a_t const*>(s), n);
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> right(ss_char_w_t const* s, ss_size_t n)
{
    typedef _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> string_t;

    const ss_size_t len = STLSOFT_NS_QUAL(c_str_len)(s);

    if (n > len)
    {
        n = len;
    }

    return string_t(s + (len - n), n);
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> right(ss_char_w_t *s, ss_size_t n)
{
    return right(const_cast<ss_char_w_t const*>(s), n);
}


/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> mid(ss_char_a_t const* s, ss_size_t pos, ss_size_t n)
{
    typedef _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> string_t;

    const ss_size_t len = STLSOFT_NS_QUAL(c_str_len)(s);

    if (pos > len)
    {
        pos = len;
    }

    if (n > len - pos)
    {
        n = len - pos;
    }

    return string_t(s + pos, n);
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_a_t> mid(ss_char_a_t *s, ss_size_t pos, ss_size_t n)
{
    return mid(const_cast<ss_char_a_t const*>(s), pos, n);
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> mid(ss_char_w_t const* s, ss_size_t pos, ss_size_t n)
{
    typedef _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> string_t;

    const ss_size_t len = STLSOFT_NS_QUAL(c_str_len)(s);

    if (pos > len)
    {
        pos = len;
    }

    if (n > len - pos)
    {
        n = len - pos;
    }

    return string_t(s + pos, n);
}

/**
 *
 * \ingroup group__library__String
 */
inline _STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE<ss_char_w_t> mid(ss_char_w_t *s, ss_size_t pos, ss_size_t n)
{
    return mid(const_cast<ss_char_w_t const*>(s), pos, n);
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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CONTAINER_SLICE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

