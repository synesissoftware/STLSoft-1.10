/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/string_to_integer_range.hpp
 *
 * Purpose:     String to integer conversions.
 *
 * Created:     28th October 2020
 * Updated:     7th February 2021
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


/** \file stlsoft/conversion/string_to_integer_range.hpp
 *
 * \brief [C++] Definition of the stlsoft::string_to_integer_range
 *   conversion function suite
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_RANGE
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_RANGE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_RANGE_MAJOR       1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_RANGE_MINOR       0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_RANGE_REVISION    1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_RANGE_EDIT        2
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

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER
# include <stlsoft/conversion/string_to_integer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER */
#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE
# include <stlsoft/meta/is_signed_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_UTILITY
# define STLSOFT_INCL_UTILITY
# include <utility>
#endif /* !STLSOFT_INCL_UTILITY */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct ximpl_string_to_integer_range_util_
{
    template<ss_typename_param_k I>
    static bool is_negative_(I const* v, yes_type)
    {
        return *v < 0;
    }

    template<ss_typename_param_k I>
    static bool is_negative_(I const* /* v */, no_type)
    {
        return false;
    }

    template<ss_typename_param_k I>
    static I negate_(I const* v, yes_type)
    {
        return -*v;
    }

    template<ss_typename_param_k I>
    static I negate_(I const* v, no_type)
    {
        return *v;
    }


    template<
        ss_typename_param_k T_integer
    ,   ss_typename_param_k T_character0
    ,   ss_typename_param_k T_character1
    >
    static
    bool
    string_to_integer_range_len_5_(
        T_character0 const*     s
    ,   size_t                  len
    ,   T_character1 const**    endptr
    ,   T_integer*              pfrom
    ,   T_integer*              pto
    )
    {
        typedef integral_limits<T_integer> limits_t;

        enum { T_integer_is_signed = is_signed_type<T_integer>::value };

        typedef ss_typename_type_k value_to_yesno_type<T_integer_is_signed>::type   T_integer_is_signed_t_;

        T_character1 const* dummy_;

        if (NULL == endptr)
        {
            endptr = &dummy_;
        }

        if (0 == len)
        {
            *endptr = NULL;

            return false;
        }

        if (ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, len, pfrom, endptr))
        {
            if (is_negative_(pfrom, T_integer_is_signed_t_()))
            {
                *pto    =   negate_(pfrom, T_integer_is_signed_t_());
                *pfrom  =   limits_t::minimum();

                return true;
            }

            return false;
        }
        else
        {
            size_t const len_from = *endptr - s;

#if 0
            if (len_from == len)
            {
                if (*pfrom < 0)
                {
                    *pto    =   -*pfrom;
                    *pto    =   limits_t::minimum();

                    return true;
                }
            }
            else
#endif
            {
                if ('+' == *endptr[0])
                {
                    return false;
                }

                if (s == *endptr)
                {
                    *pfrom = limits_t::minimum();
                }

                if ('-' == *endptr[0])
                {
                    s   +=  1 + len_from;
                    len -=  1 + len_from;

                    if (0 == len)
                    {
                        *pto    =   limits_t::maximum();
                        *endptr =   s;

                        return true;
                    }

                    if (ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, len, pto, endptr))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

#if 0

    template<
        ss_typename_param_k T_integer
    ,   ss_typename_param_k T_character0
    ,   ss_typename_param_k T_character1
    ,   ss_typename_param_k T_character2
    >
    static
    bool
    string_to_integer_range_len_7_(
        T_character0 const*     s
    ,   size_t                  len
    ,   T_character1 const**    endptr
    ,   T_integer*              pfrom
    ,   T_integer*              pto
    ,   T_character2 const*     validEndChars
    ,   size_t                  validEndCharsLen
    )
    {
        typedef integral_limits<T_integer> limits_t;

        T_character1 const* dummy_;

        if (NULL == endptr)
        {
            endptr = &dummy_;
        }

        *pfrom  =   limits_t::maximum();
        *pto    =   limits_t::minimum();

        if (0 == len)
        {
            *endptr = NULL;

            return false;
        }

        if (ximpl_string_to_integer_util_::try_string_to_integer_len_6_(s, len, pfrom, endptr, validEndChars, validEndCharsLen))
        {
            return false;
        }
        else
        {
            size_t const len_from = *endptr - s;

            if (len_from == len)
            {
                if (*pfrom < 0)
                {
                    *pto    =   -*pfrom;
                    *pto    =   limits_t::minimum();

                    return true;
                }
            }
            else
            {
                if ('-' == *endptr[0])
                {
                    s   +=  1 + len_from;
                    len -=  1 + len_from;

                    if (0 == len)
                    {
                        *pto    =   limits_t::maximum();

                        return true;
                    }

                    if (ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, len, pto, endptr))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
#endif

    template<
        ss_typename_param_k T_integer
    ,   ss_typename_param_k T_character
    >
    static
    bool
    string_to_integer_range_len_4_(
        T_character const*  s
    ,   size_t              len
    ,   T_integer*          pfrom
    ,   T_integer*          pto
    )
    {
        T_character const* endptr = NULL;

        return string_to_integer_range_len_5_(s, len, &endptr, pfrom, pto);
    }

#if 0

    template<
        ss_typename_param_k T_integer
    ,   ss_typename_param_k T_character0
    ,   ss_typename_param_k T_character1
    >
    static
    bool
    string_to_integer_range_len_6_(
        T_character0 const* s
    ,   size_t              len
    ,   T_integer*          pfrom
    ,   T_integer*          pto
    ,   T_character1 const* validEndChars
    ,   size_t              validEndCharsLen
    )
    {
        T_character0 const* endptr = NULL;

        return string_to_integer_range_len_7_(s, len, &endptr, pfrom, pto, validEndChars, validEndCharsLen);
    }
#endif
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/**
 */
inline
std::pair<int, int>
string_to_integer_range(
    char const*     s
,   char const**    endptr
)
{
    typedef integral_limits<int> limits_t;

    int from = limits_t::maximum();
    int to = limits_t::minimum();

    ximpl_string_to_integer_range_util_::string_to_integer_range_len_5_(s, STLSOFT_NS_QUAL(c_str_len)(s), endptr, &from, &to);

    return std::make_pair(from, to);
}

/**
 */
inline
std::pair<int, int>
string_to_integer_range(
    wchar_t const*  s
,   wchar_t const** endptr
)
{
    typedef integral_limits<int> limits_t;

    int from = limits_t::maximum();
    int to = limits_t::minimum();

    ximpl_string_to_integer_range_util_::string_to_integer_range_len_5_(s, STLSOFT_NS_QUAL(c_str_len)(s), endptr, &from, &to);

    return std::make_pair(from, to);
}

/**
 */
inline
std::pair<int, int>
string_to_integer_range(
    char const*     s
,   size_t          len
,   char const**    endptr
)
{
    typedef integral_limits<int> limits_t;

    int from = limits_t::maximum();
    int to = limits_t::minimum();

    ximpl_string_to_integer_range_util_::string_to_integer_range_len_5_(s, len, endptr, &from, &to);

    return std::make_pair(from, to);
}

/**
 */
inline
std::pair<int, int>
string_to_integer_range(
    wchar_t const*  s
,   size_t          len
,   wchar_t const** endptr
)
{
    typedef integral_limits<int> limits_t;

    int from = limits_t::maximum();
    int to = limits_t::minimum();

    ximpl_string_to_integer_range_util_::string_to_integer_range_len_5_(s, len, endptr, &from, &to);

    return std::make_pair(from, to);
}





template<
    ss_typename_param_k T_integer
,   ss_typename_param_k T_character
>
inline
bool
try_parse_range_of(
    T_character const*      s
,   size_t                  len
,   T_integer*              pfrom
,   T_integer*              pto
)
{
    return ximpl_string_to_integer_range_util_::string_to_integer_range_len_4_(
        s
    ,   len
    ,   pfrom
    ,   pto
    );
}

template<
    ss_typename_param_k T_integer
,   ss_typename_param_k T_input_string
>
inline
bool
try_parse_range_of(
    T_input_string const&   s
,   T_integer*              pfrom
,   T_integer*              pto
)
{
    return ximpl_string_to_integer_range_util_::string_to_integer_range_len_4_(
        STLSOFT_NS_QUAL(c_str_data)(s)
    ,   STLSOFT_NS_QUAL(c_str_len)(s)
    ,   pfrom
    ,   pto
    );
}

template<
    ss_typename_param_k T_integer
,   ss_typename_param_k T_character
>
inline
bool
try_parse_range_of(
    T_character const*      s
,   size_t                  len
,   T_integer*              pfrom
,   T_integer*              pto
,   T_character const**     endptr
)
{
    return ximpl_string_to_integer_range_util_::string_to_integer_range_len_5_(
        s
    ,   len
    ,   endptr
    ,   pfrom
    ,   pto
    );
}

template<
    ss_typename_param_k T_integer
,   ss_typename_param_k T_input_string
,   ss_typename_param_k T_character
>
inline
bool
try_parse_range_of(
    T_input_string const&   s
,   T_integer*              pfrom
,   T_integer*              pto
,   T_character const**     endptr
)
{
    return ximpl_string_to_integer_range_util_::string_to_integer_range_len_5_(
        STLSOFT_NS_QUAL(c_str_data)(s)
    ,   STLSOFT_NS_QUAL(c_str_len)(s)
    ,   endptr
    ,   pfrom
    ,   pto
    );
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_RANGE */

/* ///////////////////////////// end of file //////////////////////////// */

