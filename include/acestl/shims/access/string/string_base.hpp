/* /////////////////////////////////////////////////////////////////////////
 * File:        acestl/shims/access/string/string_base.hpp
 *
 * Purpose:     Helper functions for the ACE_String_XXXX classes.
 *
 * Created:     2nd December 2004
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file acestl/shims/access/string/string_base.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   <code>ACE_String_Base</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE
#define ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE_MAJOR       2
# define ACESTL_VER_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE_MINOR       0
# define ACESTL_VER_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE_REVISION    6
# define ACESTL_VER_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE_EDIT        40
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

#ifndef STLSOFT_INCL_ACE_H_STRING_BASE
# define STLSOFT_INCL_ACE_H_STRING_BASE
# include <ace/String_Base.h>               // for ACE_String_Base
#endif /* !STLSOFT_INCL_ACE_H_STRING_BASE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */
namespace stlsoft
{
namespace acestl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

// c_str_data

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline as_char_a_t const* c_str_data_a(ACE_String_Base<as_char_a_t> const& s)
{
    return s.c_str();
}
inline as_char_w_t const* c_str_data_w(ACE_String_Base<as_char_w_t> const& s)
{
    return s.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** An overload of \ref group__concept__Shim__string_access__c_str_data for ACE_INET_Addr
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
template <ss_typename_param_k C>
inline C const* c_str_data(ACE_String_Base<C> const& s)
{
    return s.c_str();
}

// c_str_len

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline as_size_t c_str_len_a(ACE_String_Base<as_char_a_t> const& s)
{
    return s.length();
}
inline as_size_t c_str_len_w(ACE_String_Base<as_char_w_t> const& s)
{
    return s.length();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** An overload of \ref group__concept__Shim__string_access__c_str_len for ACE_INET_Addr
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
template <ss_typename_param_k C>
inline as_size_t c_str_len(ACE_String_Base<C> const& s)
{
    return s.length();
}

// c_str_ptr

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline as_char_a_t const* c_str_ptr_a(ACE_String_Base<as_char_a_t> const& s)
{
    return s.c_str();
}
inline as_char_w_t const* c_str_ptr_w(ACE_String_Base<as_char_w_t> const& s)
{
    return s.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** An overload of \ref group__concept__Shim__string_access__c_str_ptr for ACE_INET_Addr
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
template <ss_typename_param_k C>
inline C const* c_str_ptr(ACE_String_Base<C> const& s)
{
    return s.c_str();
}

// c_str_ptr_null

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline as_char_a_t const* c_str_ptr_null_a(ACE_String_Base<as_char_a_t> const& s)
{
    return (0 != s.length()) ? s.c_str() : NULL;
}
inline as_char_w_t const* c_str_ptr_null_w(ACE_String_Base<as_char_w_t> const& s)
{
    return (0 != s.length()) ? s.c_str() : NULL;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** An overload of \ref group__concept__Shim__string_access__c_str_ptr_null for ACE_INET_Addr
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
template <ss_typename_param_k C>
inline C const* c_str_ptr_null(ACE_String_Base<C> const& s)
{
    return (0 != s.length()) ? s.c_str() : NULL;
}



/** A \ref group__concept__Shim__stream_insertion "stream insertion shim" for ACE_String_Base
 *
 * \ingroup group__concept__Shim__stream_insertion
 *
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S& operator <<(S& s, ACE_String_Base<C> const& str)
{
    s.write(str.fast_rep(), str.length());

    return s;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace acestl */
# else
} /* namespace acestl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */

/** A \ref group__concept__Shim__stream_insertion "stream insertion shim" for ACE_String_Base
 *
 * \ingroup group__concept__Shim__stream_insertion
 *
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        >
inline S& operator <<(S& s, ACE_String_Base<C> const& str)
{
    s.write(str.fast_rep(), str.length());

    return s;
}

namespace stlsoft
{

    using ::acestl::c_str_data;
    using ::acestl::c_str_data_a;
    using ::acestl::c_str_data_w;

    using ::acestl::c_str_len;
    using ::acestl::c_str_len_a;
    using ::acestl::c_str_len_w;

    using ::acestl::c_str_ptr;
    using ::acestl::c_str_ptr_a;
    using ::acestl::c_str_ptr_w;

    using ::acestl::c_str_ptr_null;
    using ::acestl::c_str_ptr_null_a;
    using ::acestl::c_str_ptr_null_w;

} /* namespace stlsoft */

#endif /* !ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE */

/* ///////////////////////////// end of file //////////////////////////// */

