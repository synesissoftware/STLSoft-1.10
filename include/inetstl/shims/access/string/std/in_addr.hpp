/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/shims/access/string/std/in_addr.hpp
 *
 * Purpose:     String access shims for Internet types
 *
 * Created:     21st October 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file inetstl/shims/access/string/std/in_addr.hpp
 *
 * \brief [C++] Definition of the string access shims for
 *   <code>in_addr</code>
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef INETSTL_INCL_INETSTL_SHIMS_ACCESS_STRING_STD_HPP_IN_ADDR
#define INETSTL_INCL_INETSTL_SHIMS_ACCESS_STRING_STD_HPP_IN_ADDR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_SHIMS_ACCESS_STRING_STD_HPP_IN_ADDR_MAJOR      1
# define INETSTL_VER_INETSTL_SHIMS_ACCESS_STRING_STD_HPP_IN_ADDR_MINOR      1
# define INETSTL_VER_INETSTL_SHIMS_ACCESS_STRING_STD_HPP_IN_ADDR_REVISION   3
# define INETSTL_VER_INETSTL_SHIMS_ACCESS_STRING_STD_HPP_IN_ADDR_EDIT       25
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef INETSTL_INCL_INETSTL_H_INETSTL
# include <inetstl/inetstl.h>
#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef INETSTL_INCL_INETSTL_INTERNAL_STD_H_IN_ADDR_
# include <inetstl/internal/std/in_addr_.h>
#endif /* !INETSTL_INCL_INETSTL_INTERNAL_STD_H_IN_ADDR_ */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */
namespace stlsoft
{
namespace inetstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
struct ximpl_inetstl_shims_access_string_in_addr_
{
public:
    template <ss_typename_type_k T_character>
    static
    stlsoft::basic_shim_string<T_character, 16>
    in_addr_to_shim_string(
        struct in_addr const& addr
    )
    {
        typedef T_character char_t;

        stlsoft::basic_shim_string<char_t, 16>     s;

        s.resize(15);

        is_uint32_t     laddr = ntohl(addr.s_addr);
        unsigned const  b3  =   (laddr & 0x000000ff) >>  0;
        unsigned const  b2  =   (laddr & 0x0000ff00) >>  8;
        unsigned const  b1  =   (laddr & 0x00ff0000) >> 16;
        unsigned const  b0  =   (laddr & 0xff000000) >> 24;

        size_t          n1;
        size_t          n2;
        char_t*         s1;
        union
        {
            char_t const*   ccp;
            char_t*         cp;
        }               s2;
        char_t*         s3;
        size_t          n   =   3;

        n1      =   s.size() + 1;
        s1      =   s.data();

        s2.ccp  =   STLSOFT_NS_QUAL(integer_to_decimal_string)(s1, n1, static_cast<ss_uint8_t>(b3), &n2);
        n1      -=  n2;
        n       +=  n2;

        s3      =   --s2.cp;
        --n1;

        s2.ccp  =   STLSOFT_NS_QUAL(integer_to_decimal_string)(s1, n1, static_cast<ss_uint8_t>(b2), &n2);
        n1      -=  n2;
        n       +=  n2;

        *s3     =   '.';
        s3      =   --s2.cp;
        --n1;

        s2.ccp  =   STLSOFT_NS_QUAL(integer_to_decimal_string)(s1, n1, static_cast<ss_uint8_t>(b1), &n2);
        n1      -=  n2;
        n       +=  n2;

        *s3     =   '.';
        s3      =   --s2.cp;
        --n1;

        s2.ccp  =   STLSOFT_NS_QUAL(integer_to_decimal_string)(s1, n1, static_cast<ss_uint8_t>(b0), &n2);
        n1      -=  n2;
        n       +=  n2;

        *s3     =   '.';

        is_size_t   spare   =   s2.ccp - s.data();

        ::memmove(s.data(), s.data() + spare, sizeof(char_t) * n);

        s.truncate(n);

        return s;
    }

    static
    is_size_t
    length(
        struct in_addr const& addr
    )
    {
        // Don't care about the byte order of the address, as we're only
        // calculating length
        is_uint32_t laddr = addr.s_addr;

        unsigned    b0  =   (laddr & 0x000000ff) >>  0;
        unsigned    b1  =   (laddr & 0x0000ff00) >>  8;
        unsigned    b2  =   (laddr & 0x00ff0000) >> 16;
        unsigned    b3  =   (laddr & 0xff000000) >> 24;

        int         cch =   3   // The dot separators
                        +   1 + (b0 > 9) + (b0 > 99)
                        +   1 + (b1 > 9) + (b1 > 99)
                        +   1 + (b2 > 9) + (b2 > 99)
                        +   1 + (b3 > 9) + (b3 > 99)
                        ;

        return static_cast<is_size_t>(cch);
    }

};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/* struct in_addr const& */

inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_data_a(
    struct in_addr const& addr
)
{
    return ximpl_inetstl_shims_access_string_in_addr_::in_addr_to_shim_string<is_char_a_t>(addr);
}

inline
stlsoft::basic_shim_string<is_char_w_t, 16>
c_str_data_w(
    struct in_addr const& addr
)
{
    return ximpl_inetstl_shims_access_string_in_addr_::in_addr_to_shim_string<is_char_w_t>(addr);
}

#if 0
#elif defined(INETSTL_OS_IS_UNIX)

inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_data(
    struct in_addr const& addr
)
{
    return c_str_data_a(addr);
}
#elif defined(INETSTL_OS_IS_WINDOWS)

inline
stlsoft::basic_shim_string<TCHAR, 16>
c_str_data(
    struct in_addr const& addr
)
{
# ifdef UNICODE
    return c_str_data_w(addr);
# else /* ? UNICODE */
    return c_str_data_a(addr);
# endif /* UNICODE */
}
#endif



inline
is_size_t
c_str_len_a(
    struct in_addr const& addr
)
{
    return ximpl_inetstl_shims_access_string_in_addr_::length(addr);
}

inline
is_size_t
c_str_len_w(
    struct in_addr const& addr
)
{
    return ximpl_inetstl_shims_access_string_in_addr_::length(addr);
}

inline
is_size_t
c_str_len(
    struct in_addr const& addr
)
{
#ifdef UNICODE
    return c_str_len_w(addr);
#else /* ? UNICODE */
    return c_str_len_a(addr);
#endif /* UNICODE */
}


inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_ptr_a(
    struct in_addr const& addr
)
{
    return c_str_data_a(addr);
}

inline
stlsoft::basic_shim_string<is_char_w_t, 16>
c_str_ptr_w(
    struct in_addr const& addr
)
{
    return c_str_data_w(addr);
}

#if 0
#elif defined(INETSTL_OS_IS_UNIX)

inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_ptr(
    struct in_addr const& addr
)
{
    return c_str_data(addr);
}
#elif defined(INETSTL_OS_IS_WINDOWS)

inline
stlsoft::basic_shim_string<TCHAR, 16>
c_str_ptr(
    struct in_addr const& addr
)
{
    return c_str_data(addr);
}
#endif


/* struct in_addr const* */

inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_data_a(
    struct in_addr const* addr
)
{
    typedef stlsoft::basic_shim_string<is_char_a_t, 16> shim_string_t;

    if (NULL != addr)
    {
        return c_str_data_a(*addr);
    }
    else
    {
        return shim_string_t(is_size_t(0));
    }
}

inline
stlsoft::basic_shim_string<is_char_w_t, 16>
c_str_data_w(
    struct in_addr const* addr
)
{
    typedef stlsoft::basic_shim_string<is_char_w_t, 16> shim_string_t;

    if (NULL != addr)
    {
        return c_str_data_w(*addr);
    }
    else
    {
        return shim_string_t(is_size_t(0));
    }
}

#if 0
#elif defined(INETSTL_OS_IS_UNIX)

inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_data(
    struct in_addr const* addr
)
{
    return c_str_data_a(addr);
}
#elif defined(INETSTL_OS_IS_WINDOWS)

inline
stlsoft::basic_shim_string<TCHAR, 16>
c_str_data(
    struct in_addr const* addr
)
{
# ifdef UNICODE
    return c_str_data_w(addr);
# else /* ? UNICODE */
    return c_str_data_a(addr);
# endif /* UNICODE */
}
#endif


inline
is_size_t
c_str_len_a(
    struct in_addr const* addr
)
{
    if (NULL != addr)
    {
        return c_str_len_a(*addr);
    }
    else
    {
        return 0;
    }
}

inline
is_size_t
c_str_len_w(
    struct in_addr const* addr
)
{
    if (NULL != addr)
    {
        return c_str_len_w(*addr);
    }
    else
    {
        return 0;
    }
}

inline
is_size_t
c_str_len(
    struct in_addr const* addr
)
{
#ifdef UNICODE
    return c_str_len_w(addr);
#else /* ? UNICODE */
    return c_str_len_a(addr);
#endif /* UNICODE */
}


inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_ptr_a(
    struct in_addr const* addr
)
{
    return c_str_data_a(addr);
}

inline
stlsoft::basic_shim_string<is_char_w_t, 16>
c_str_ptr_w(
    struct in_addr const* addr
)
{
    return c_str_data_w(addr);
}

#if 0
#elif defined(INETSTL_OS_IS_UNIX)

inline
stlsoft::basic_shim_string<is_char_a_t, 16>
c_str_ptr(
    struct in_addr const* addr
)
{
    return c_str_data(addr);
}
#elif defined(INETSTL_OS_IS_WINDOWS)

inline
stlsoft::basic_shim_string<TCHAR, 16>
c_str_ptr(
    struct in_addr const* addr
)
{
    return c_str_data(addr);
}
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace inetstl */
# else
} /* namespace inetstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef INETSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::inetstl::c_str_data_a;
using ::inetstl::c_str_len_a;
using ::inetstl::c_str_ptr_a;

using ::inetstl::c_str_data_w;
using ::inetstl::c_str_len_w;
using ::inetstl::c_str_ptr_w;

using ::inetstl::c_str_data;
using ::inetstl::c_str_len;
using ::inetstl::c_str_ptr;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !INETSTL_INCL_INETSTL_SHIMS_ACCESS_STRING_STD_HPP_IN_ADDR */

/* ///////////////////////////// end of file //////////////////////////// */

