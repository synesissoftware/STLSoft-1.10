/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/string_slice.h
 *
 * Purpose:     Defines the string_slice class template.
 *
 * Created:     3rd May 2014
 * Updated:     5th February 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2014-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/string_slice.h
 *
 * \brief [C++] Definition of the stlsoft::string_slice_a_t and
 *   stlsoft::string_slice_w_t types
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
#define STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_H_STRING_SLICE_MAJOR    1
# define STLSOFT_VER_STLSOFT_STRING_H_STRING_SLICE_MINOR    6
# define STLSOFT_VER_STLSOFT_STRING_H_STRING_SLICE_REVISION 2
# define STLSOFT_VER_STLSOFT_STRING_H_STRING_SLICE_EDIT     31
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifdef __cplusplus
# ifndef STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION
#  include <stlsoft/util/streams/string_insertion.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION */
#endif /* __cplusplus */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

struct stlsoft_C_string_slice_m_t
{
    size_t          len;    /*!< The length of the slice */
    char const*     ptr;    /*!< The pointer of the slice */

#ifdef __cplusplus
public: /* Construction */
    static
    stlsoft_C_string_slice_m_t
    create(
        char const* s
    ,   size_t      n
    )
    {
        STLSOFT_ASSERT(0u == n || NULL != s);

        stlsoft_C_string_slice_m_t r = { n, s };

        return r;
    }
    static
    stlsoft_C_string_slice_m_t
    create()
    {
        return create(ss_nullptr_k, 0);
    }
#endif /* __cplusplus */
};
#ifndef __cplusplus
typedef struct stlsoft_C_string_slice_m_t                   stlsoft_C_string_slice_m_t;
#endif /* !__cplusplus */

struct stlsoft_C_string_slice_w_t
{
    size_t          len;    /*!< The length of the slice */
    wchar_t const*  ptr;    /*!< The pointer of the slice */

#ifdef __cplusplus
public: /* Construction */
    static
    stlsoft_C_string_slice_w_t
    create(
        wchar_t const*  s
    ,   size_t          n
    )
    {
        STLSOFT_ASSERT(0u == n || NULL != s);

        stlsoft_C_string_slice_w_t r = { n, s };

        return r;
    }
    static
    stlsoft_C_string_slice_w_t
    create()
    {
        return create(ss_nullptr_k, 0);
    }
#endif /* __cplusplus */
};
#ifndef __cplusplus
typedef struct stlsoft_C_string_slice_w_t                   stlsoft_C_string_slice_w_t;
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

#ifdef __cplusplus
# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C>
struct string_slice_selection_traits_t;

STLSOFT_TEMPLATE_SPECIALISATION
struct string_slice_selection_traits_t<char>
{
    typedef stlsoft_C_string_slice_m_t  slice_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct string_slice_selection_traits_t<wchar_t>
{
    typedef stlsoft_C_string_slice_w_t  slice_type;
};
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

typedef STLSOFT_NS_GLOBAL(stlsoft_C_string_slice_m_t)       stlsoft_C_string_slice_a_t;

#ifndef STLSOFT_NO_NAMESPACE

typedef STLSOFT_NS_GLOBAL(stlsoft_C_string_slice_m_t)       string_slice_a_t;
typedef STLSOFT_NS_GLOBAL(stlsoft_C_string_slice_m_t)       string_slice_m_t;
typedef STLSOFT_NS_GLOBAL(stlsoft_C_string_slice_w_t)       string_slice_w_t;

/* stlsoft_C_string_slice_m_t const& */

inline
ss_char_a_t const*
c_str_data_a(
    stlsoft_C_string_slice_m_t const& slice
)
{
    return (0u == slice.len) ? "" : slice.ptr;
}
inline
ss_size_t
c_str_len_a(
    stlsoft_C_string_slice_m_t const& slice
)
{
    return slice.len;
}

inline
ss_char_a_t const*
c_str_data(
    stlsoft_C_string_slice_m_t const& slice
)
{
    return (0u == slice.len) ? "" : slice.ptr;
}
inline
ss_size_t
c_str_len(
    stlsoft_C_string_slice_m_t const& slice
)
{
    return slice.len;
}

inline
ss_char_w_t const*
c_str_data_w(
    stlsoft_C_string_slice_w_t const& slice
)
{
    return (0u == slice.len) ? L"" : slice.ptr;
}
inline
ss_size_t
c_str_len_w(
    stlsoft_C_string_slice_w_t const& slice
)
{
    return slice.len;
}

inline
ss_char_w_t const*
c_str_data(
    stlsoft_C_string_slice_w_t const& slice
)
{
    return (0u == slice.len) ? L"" : slice.ptr;
}
inline
ss_size_t
c_str_len(
    stlsoft_C_string_slice_w_t const& slice
)
{
    return slice.len;
}




/* stlsoft_C_string_slice_m_t const* */

inline
ss_char_a_t const*
c_str_data_a(
    stlsoft_C_string_slice_m_t const* slice
)
{
    return (NULL == slice) ? "" : c_str_data_a(*slice);
}
inline
ss_size_t
c_str_len_a(
    stlsoft_C_string_slice_m_t const* slice
)
{
    return (NULL == slice) ? 0u : c_str_len_a(*slice);
}

inline
ss_char_a_t const*
c_str_data(
    stlsoft_C_string_slice_m_t const* slice
)
{
    return (NULL == slice) ? "" : c_str_data_a(*slice);
}
inline
ss_size_t
c_str_len(
    stlsoft_C_string_slice_m_t const* slice
)
{
    return (NULL == slice) ? 0u : c_str_len_a(*slice);
}

inline
ss_char_w_t const*
c_str_data_w(
    stlsoft_C_string_slice_w_t const* slice
)
{
    return (NULL == slice) ? L"" : c_str_data_w(*slice);
}
inline
ss_size_t
c_str_len_w(
    stlsoft_C_string_slice_w_t const* slice
)
{
    return (NULL == slice) ? 0u : c_str_len_w(*slice);
}

inline
ss_char_w_t const*
c_str_data(
    stlsoft_C_string_slice_w_t const* slice
)
{
    return (NULL == slice) ? L"" : c_str_data_w(*slice);
}
inline
ss_size_t
c_str_len(
    stlsoft_C_string_slice_w_t const* slice
)
{
    return (NULL == slice) ? 0u : c_str_len_w(*slice);
}

#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * stream insertion
 */

#ifdef __cplusplus

/** The \ref group__concept__Shim__stream_insertion "stream insertion shim" for stlsoft_C_string_slice_m_t
 *
 * \ingroup group__concept__Shim__stream_insertion
 *
 */
template <
    ss_typename_param_k T_stream
>
inline
T_stream&
operator <<(
    T_stream&                           stm
,   stlsoft_C_string_slice_m_t const&   slice
)
{
    stlsoft::util::string_insert_m(stm, slice.ptr, slice.len);

    return stm;
}

/** The \ref group__concept__Shim__stream_insertion "stream insertion shim" for stlsoft_C_string_slice_w_t
 *
 * \ingroup group__concept__Shim__stream_insertion
 *
 */
template <
    ss_typename_param_k T_stream
>
inline
T_stream&
operator <<(
    T_stream&                           stm
,   stlsoft_C_string_slice_w_t const&   slice
)
{
    stlsoft::util::string_insert_w(stm, slice.ptr, slice.len);

    return stm;
}
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */

/* ///////////////////////////// end of file //////////////////////////// */

