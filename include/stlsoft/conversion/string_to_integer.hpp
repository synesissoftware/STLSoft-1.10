/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/string_to_integer.hpp
 *
 * Purpose:     String to integer conversions.
 *
 * Created:     18th November 2008
 * Updated:     22nd January 2024
 *
 * Thanks to:   Chris Oldwood for righteous criticism of one of my hastily-
 *              written articles, which led to the creation of the
 *              try_parse_to<>() functions.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/string_to_integer.hpp
 *
 * \brief [C++] Definition of the stlsoft::string_to_integer conversion
 *   function suite
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_MAJOR     3
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_MINOR     0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_REVISION  1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER_EDIT      72
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX
# include <stlsoft/util/minmax.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX */
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

#ifndef STLSOFT_INCL_H_CTYPE
# define STLSOFT_INCL_H_CTYPE
# include <ctype.h>
#endif /* !STLSOFT_INCL_H_CTYPE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * code coverage
 */

#ifdef STLSOFT_USE_XCOVER
namespace
{
    class register_with_xcover
    {
    public:
        register_with_xcover()
        {
            XCOVER_CREATE_FILE_ALIAS("string_to_integer");
            XCOVER_MARK_FILE_START();
        }

    } instance;
}
#endif

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct ximpl_string_to_integer_util_
{
    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    I
    string_to_integer_raw_2_(
        C const*    s
    ,   C const**   endptr
    ,   I
    )
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_ASSERT(NULL != endptr);

        I result = 0;

        for (;; ++s)
        {
            STLSOFT_COVER_MARK_LINE();

            switch (*s)
            {
                case    '0':
                case    '1':
                case    '2':
                case    '3':
                case    '4':
                case    '5':
                case    '6':
                case    '7':
                case    '8':
                case    '9':
                    STLSOFT_COVER_MARK_LINE();
                    result = 10 * result + (*s - '0');
                    continue;
                default:
                    STLSOFT_COVER_MARK_LINE();
                    *endptr = s;
                    break;
            }
            break;
        }

        return result;
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    hex_string_to_integer_len_raw_4_(
        C const*    s
    ,   ss_size_t   len
    ,   C const**   endptr
    ,   I*          result
    ,   I        /* fail_value */
    )
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_ASSERT(0 != len);
        STLSOFT_ASSERT(NULL != endptr);

        *result = 0;

        for (; 0 != len; ++s, --len)
        {
            STLSOFT_COVER_MARK_LINE();

            C c = *s;

            switch (c)
            {
                case    'a':
                case    'A':
                    c = 10;
                    goto calc;
                case    'b':
                case    'B':
                    c = 11;
                    goto calc;
                case    'c':
                case    'C':
                    c = 12;
                    goto calc;
                case    'd':
                case    'D':
                    c = 13;
                    goto calc;
                case    'e':
                case    'E':
                    c = 14;
                    goto calc;
                case    'f':
                case    'F':
                    c = 15;
                    goto calc;

                case    '0':
                case    '1':
                case    '2':
                case    '3':
                case    '4':
                case    '5':
                case    '6':
                case    '7':
                case    '8':
                case    '9':
                    c = c - '0';
calc:
                    STLSOFT_COVER_MARK_LINE();
                    *result = I(16 * *result + c);
                    continue;
                default:
                    STLSOFT_COVER_MARK_LINE();
                    break;
            }
            break;
        }

        *endptr = s;

        return true;
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    string_to_integer_len_raw_5_(
        C const*    s
    ,   ss_size_t   len
    ,   C const**   endptr
    ,   I*          result
    ,   I           fail_value
    )
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_ASSERT(0 != len);
        STLSOFT_ASSERT(NULL != endptr);

        if ('0' == s[0])
        {
            STLSOFT_COVER_MARK_LINE();

            if (1 == len)
            {
                STLSOFT_COVER_MARK_LINE();

                *result = 0;

                *endptr = s + 1;

                return true;
            }
            else
            if ('x' == s[1] ||
                'X' == s[1])
            {
                STLSOFT_COVER_MARK_LINE();

                if (2 == len)
                {
                    STLSOFT_COVER_MARK_LINE();

                    *endptr = s + 1;

                    return false;
                }
                else
                {
                    STLSOFT_COVER_MARK_LINE();

                    return hex_string_to_integer_len_raw_4_(s + 2, len - 2, endptr, result, fail_value);
                }
            }

            // fall through

            STLSOFT_COVER_MARK_LINE();
        }

        *result = 0;

        for (; 0 != len; ++s, --len)
        {
            STLSOFT_COVER_MARK_LINE();

            switch (*s)
            {
                case    '0':
                case    '1':
                case    '2':
                case    '3':
                case    '4':
                case    '5':
                case    '6':
                case    '7':
                case    '8':
                case    '9':
                    STLSOFT_COVER_MARK_LINE();
                    *result = I(10 * *result + (*s - '0'));
                    continue;
                default:
                    STLSOFT_COVER_MARK_LINE();
                    break;
            }
            break;
        }

        *endptr = s;

        return true;
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_read_minus_(
        C const*    s
    ,   C const**   endptr
    ,   I*          v
    ,   yes_type
    )
    {
        *v = -string_to_integer_raw_2_(s, endptr, I());

        return true;
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_read_minus_(
        C const*    /* s */
    ,   C const**   /* endptr */
    ,   I*          /* v */
    ,   no_type
    )
    {
        return false;
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_read_minus_len_(
        C const*    s
    ,   ss_size_t   len
    ,   C const**   endptr
    ,   I*          v
    ,   yes_type
    )
    {
        if (string_to_integer_len_raw_5_(s, len, endptr, v, I(0)))
        {
            *v = -*v;

            return true;
        }

        return false;
    }

    template
        <   ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_read_minus_len_(
        C const*    /* s */
    ,   ss_size_t   /* len */
    ,   C const**   /* endptr */
    ,   I*          /* v */
    ,   no_type
    )
    {
        return false;
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    I
    string_to_integer_2_(
        C const*    s
    ,   C const**   endptr
    ,   I
    )
    {
        STLSOFT_COVER_MARK_LINE();

        enum { I_IS_SIGNED = is_signed_type<I>::value };

        typedef ss_typename_type_k value_to_yesno_type<I_IS_SIGNED>::type   I_is_signed_type_;

        // apply Null Object pattern
        C const* endptr_;

        if (NULL == endptr)
        {
            STLSOFT_COVER_MARK_LINE();

            endptr = &endptr_;
        }

        // skip whitespace
        for (;; ++s)
        {
            STLSOFT_COVER_MARK_LINE();

            switch (*s)
            {
                case    ' ':
                case    '\t':
                case    '\b':
                case    '\r':
                case    '\n':
                case    '\v':
                    STLSOFT_COVER_MARK_LINE();
                    continue;
                default:
                    STLSOFT_COVER_MARK_LINE();
                    break;
            }
            break;
        }

        switch (*s)
        {
            case    '+':
                STLSOFT_COVER_MARK_LINE();
                ++s;
                // Fall through
            case    '0':
            case    '1':
            case    '2':
            case    '3':
            case    '4':
            case    '5':
            case    '6':
            case    '7':
            case    '8':
            case    '9':
                STLSOFT_COVER_MARK_LINE();
                return string_to_integer_raw_2_(s, endptr, I());
            case    '-':
                STLSOFT_COVER_MARK_LINE();
                {
                    STLSOFT_COVER_MARK_LINE();

                    I   v;
                    if (try_read_minus_(s + 1, endptr, &v, I_is_signed_type_()))
                    {
                        return v;
                    }
                }
                // Fall through
                STLSOFT_COVER_MARK_LINE();
            default:
                STLSOFT_COVER_MARK_LINE();
                *endptr = s;
                return 0;
        }
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    string_to_integer_len_5_(
        C const*    s
    ,   ss_size_t   len
    ,   C const**   endptr
    ,   I*          result
    ,   I           fail_value
    )
    {
        STLSOFT_COVER_MARK_LINE();

        enum { I_IS_SIGNED = is_signed_type<I>::value };

        typedef ss_typename_type_k value_to_yesno_type<I_IS_SIGNED>::type   I_is_signed_type_;

        // apply Null Object pattern
        C const* endptr_;

        if (NULL == endptr)
        {
            STLSOFT_COVER_MARK_LINE();

            endptr = &endptr_;
        }

        *endptr = NULL;

        if (0 == len)
        {
            STLSOFT_COVER_MARK_LINE();

            *endptr = NULL;

            return false;
        }

        // skip whitespace
        for (; 0 != len; ++s, --len)
        {
            STLSOFT_COVER_MARK_LINE();

            switch (*s)
            {
                case    ' ':
                case    '\t':
                case    '\b':
                case    '\r':
                case    '\n':
                case    '\v':
                    STLSOFT_COVER_MARK_LINE();
                    continue;
                default:
                    STLSOFT_COVER_MARK_LINE();
                    break;
            }
            break;
        }

        if (0 == len)
        {
            STLSOFT_COVER_MARK_LINE();

            *endptr = s;

            return false;
        }

        switch (*s)
        {
            case    '+':
                STLSOFT_COVER_MARK_LINE();
                if (len < 2 || !isdigit(char(s[1])))
                {
                    *endptr = s;

                    return false;
                }
                ++s;
                --len;
                // fall through
            case    '0':
            case    '1':
            case    '2':
            case    '3':
            case    '4':
            case    '5':
            case    '6':
            case    '7':
            case    '8':
            case    '9':
                STLSOFT_COVER_MARK_LINE();
                return string_to_integer_len_raw_5_(s, len, endptr, result, fail_value);
            case    '-':
                if (len < 2 || !isdigit(char(s[1])))
                {
                    *endptr = s;

                    return false;
                }

                STLSOFT_COVER_MARK_LINE();
                {
                    STLSOFT_COVER_MARK_LINE();

                    if (try_read_minus_len_(s + 1, len - 1, endptr, result, I_is_signed_type_()))
                    {
                        return true;
                    }
                }
                // Fall through
                STLSOFT_COVER_MARK_LINE();
            default:
                STLSOFT_COVER_MARK_LINE();
                *endptr = s;
                return false;
        }
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C1
    ,   ss_typename_param_k C2
    ,   ss_typename_param_k C3
    >
    static
    bool
    try_string_to_integer_len_6_(
        C1 const*   s
    ,   ss_size_t   len
    ,   I*          pi
    ,   C2 const*   validEndChars
    ,   ss_size_t   validEndCharsLen
    ,   C3 const**  ep
    )
    {
        if (0 == len)
        {
            return false;
        }

        C3 const* dummy_;

        if (NULL == ep)
        {
            ep = &dummy_;
        }

        if (!string_to_integer_len_5_(s, len, ep, pi, I()))
        {
            return false;
        }

        STLSOFT_ASSERT(NULL != *ep);

        if ((*ep - s) < ss_ptrdiff_t(len))
        {
            C2 const* const endCharsEnd = validEndChars + validEndCharsLen;

            for ( ; endCharsEnd != validEndChars; ++validEndChars)
            {
                if (*validEndChars == **ep)
                {
                    return true;
                }
            }

            return false;
        }
        else
        {
            return true;
        }
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_string_to_integer_len_4_(
        C const*    s
    ,   ss_size_t   len
    ,   I*          pi
    ,   C const**   endptr
    )
    {
        if (0 == len)
        {
            *endptr = NULL;

            return false;
        }

        C const* ep;

        if (!string_to_integer_len_5_(s, len, &ep, pi, I()))
        {
            *endptr = ep;

            return false;
        }

        STLSOFT_ASSERT(NULL != ep);

        if (NULL != endptr)
        {
            *endptr = ep;
        }

        if ((ep - s) < ss_ptrdiff_t(len))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_string_to_integer_len_3n_(
        C const*    s
    ,   ss_size_t   len
    ,   I*          pi
    )
    {
        if (0 == len)
        {
            return false;
        }

        C const* ep;

        if (!string_to_integer_len_5_(s, len, &ep, pi, I()))
        {
            return false;
        }

        STLSOFT_ASSERT(NULL != ep);

        if ((ep - s) < ss_ptrdiff_t(len))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_string_to_integer_len_3e_(
        C const*    s
    ,   I*          pi
    ,   C const**   ep
    )
    {
        ss_size_t const len = c_str_len(s);

        if (0 == len)
        {
            return false;
        }

        C const* dummy_;

        if (NULL == ep)
        {
            ep = &dummy_;
        }

        if (!string_to_integer_len_5_(s, len, ep, pi, I()))
        {
            return false;
        }

        STLSOFT_ASSERT(NULL != *ep);

        if ((*ep - s) < ss_ptrdiff_t(len))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k C
    >
    static
    bool
    try_string_to_integer_len_2_(
        C const*    s
    ,   I*          pi
    )
    {
        ss_size_t const len = c_str_len(s);

        if (0 == len)
        {
            return false;
        }

        C const* ep;

        if (!string_to_integer_len_5_(s, len, &ep, pi, I()))
        {
            return false;
        }

        STLSOFT_ASSERT(NULL != ep);

        if ((ep - s) < ss_ptrdiff_t(len))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Converts a decimal numeric string to an integer
 *
 * Some examples:
<pre>
  const char*  endptr;

  stlsoft::string_to_integer("1234", NULL); // returns 1234

  stlsoft::string_to_integer("  1234", NULL); // returns 1234

  stlsoft::string_to_integer("  +1234", NULL); // returns 1234

  stlsoft::string_to_integer("  -1234", NULL); // returns -1234

  stlsoft::string_to_integer("  +1234abc", &endptr); // returns 1234, endptr -> "abc"
</pre>
 */
inline
int
string_to_integer(
    char const*     s
,   char const**    endptr
)
{
    STLSOFT_COVER_MARK_LINE();

    return ximpl_string_to_integer_util_::string_to_integer_2_(s, endptr, int());
}
/** Converts a decimal numeric string to an integer
 */
inline
int
string_to_integer(
    wchar_t const*  s
,   wchar_t const** endptr
)
{
    STLSOFT_COVER_MARK_LINE();

    return ximpl_string_to_integer_util_::string_to_integer_2_(s, endptr, int());
}


/** Converts a decimal numeric string to an integer
 *
 * \note If the length is exhaused, *endptr will be NULL
 */
inline
int
string_to_integer(
    char const*     s
,   size_t          len
,   char const**    endptr
)
{
    STLSOFT_COVER_MARK_LINE();

    int r;

    if (!ximpl_string_to_integer_util_::string_to_integer_len_5_(s, len, endptr, &r, int()))
    {
        return 0;
    }

    return r;
}
/** Converts a decimal numeric string to an integer
 *
 * \note If the length is exhaused, *endptr will be NULL
 */
inline
int
string_to_integer(
    wchar_t const*  s
,   size_t          len
,   wchar_t const** endptr
)
{
    STLSOFT_COVER_MARK_LINE();

    int r;

    if (!ximpl_string_to_integer_util_::string_to_integer_len_5_(s, len, endptr, &r, int()))
    {
        return 0;
    }

    return r;
}



/* try_parse_to(S const&, I*) */

/** Attempts to converts a decimal numeric string to an integer
 *
 * \retval true The string \c s contains a decimal number and ends with
 * \retval false
 */
template <
    ss_typename_param_k I
,   ss_typename_param_k S
>
inline
bool
try_parse_to(
    S const&    s
,   I*          pi
)
{
    return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(STLSOFT_NS_QUAL(c_str_data)(s), STLSOFT_NS_QUAL(c_str_len)(s), pi);
}

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

inline bool try_parse_to(char    const* s, ss_sint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(char    const* s, ss_uint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_sint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_uint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }

inline bool try_parse_to(char    const* s, ss_sint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(char    const* s, ss_uint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_sint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_uint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }

inline bool try_parse_to(char    const* s, ss_sint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(char    const* s, ss_uint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_sint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_uint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT

inline bool try_parse_to(char    const* s, ss_sint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(char    const* s, ss_uint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_sint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, ss_uint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
# endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */

# ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s,   signed int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(char    const* s, unsigned int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s,   signed int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, unsigned int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
# endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

# ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s,   signed long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(char    const* s, unsigned long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s,   signed long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
inline bool try_parse_to(wchar_t const* s, unsigned long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_2_(s, pi); }
# endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/* try_parse_to(C const*, size_t, I*) */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** Attempts to converts a decimal numeric string to an integer
 *
 * \retval true The string \c s contains a decimal number and ends with
 * \retval false
 */
template <
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
bool
try_parse_to(
    C const*    s
,   ss_size_t   cch
,   I*          pi
)
;
#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

inline bool try_parse_to(char    const* s, ss_size_t cch, ss_sint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(char    const* s, ss_size_t cch, ss_uint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_sint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_uint8_t*    pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }

inline bool try_parse_to(char    const* s, ss_size_t cch, ss_sint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(char    const* s, ss_size_t cch, ss_uint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_sint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_uint16_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }

inline bool try_parse_to(char    const* s, ss_size_t cch, ss_sint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(char    const* s, ss_size_t cch, ss_uint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_sint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_uint32_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT

inline bool try_parse_to(char    const* s, ss_size_t cch, ss_sint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(char    const* s, ss_size_t cch, ss_uint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_sint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, ss_uint64_t*   pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
# endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */

# ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s, ss_size_t cch,   signed int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(char    const* s, ss_size_t cch, unsigned int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch,   signed int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, unsigned int*  pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
# endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

# ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s, ss_size_t cch,   signed long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(char    const* s, ss_size_t cch, unsigned long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch,   signed long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
inline bool try_parse_to(wchar_t const* s, ss_size_t cch, unsigned long* pi) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3n_(s, cch, pi); }
# endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/* try_parse_to(C const*, I*, C const**) */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** Attempts to converts a decimal numeric string to an integer
 *
 * \retval true The string \c s contains a decimal number and ends with
 * \retval false
 */
template <
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
bool
try_parse_to(
    C const*    s
,   I*          pi
,   C const**   endptr
)
;
#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

inline bool try_parse_to(char    const* s, ss_sint8_t*    pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(char    const* s, ss_uint8_t*    pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_sint8_t*    pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_uint8_t*    pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }

inline bool try_parse_to(char    const* s, ss_sint16_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(char    const* s, ss_uint16_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_sint16_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_uint16_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }

inline bool try_parse_to(char    const* s, ss_sint32_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(char    const* s, ss_uint32_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_sint32_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_uint32_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT

inline bool try_parse_to(char    const* s, ss_sint64_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(char    const* s, ss_uint64_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_sint64_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, ss_uint64_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
# endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */

# ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s,   signed int*  pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(char    const* s, unsigned int*  pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s,   signed int*  pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, unsigned int*  pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
# endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

# ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s,   signed long* pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(char    const* s, unsigned long* pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s,   signed long* pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, unsigned long* pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_3e_(s, pi, endptr); }
# endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/* try_parse_to(C const*, size_t, I*, C const**) */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** Attempts to converts a decimal numeric string to an integer
 *
 * \retval true The string \c s contains a decimal number and ends with
 * \retval false
 */
template <
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
bool
try_parse_to(
    C const*    s
,   I*          pi
,   C const**   endptr
)
;
#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

inline bool try_parse_to(char    const* s, size_t n, ss_sint8_t*    pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(char    const* s, size_t n, ss_uint8_t*    pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_sint8_t*    pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_uint8_t*    pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }

inline bool try_parse_to(char    const* s, size_t n, ss_sint16_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(char    const* s, size_t n, ss_uint16_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_sint16_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_uint16_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }

inline bool try_parse_to(char    const* s, size_t n, ss_sint32_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(char    const* s, size_t n, ss_uint32_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_sint32_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_uint32_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT

inline bool try_parse_to(char    const* s, size_t n, ss_sint64_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(char    const* s, size_t n, ss_uint64_t*   pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_sint64_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, ss_uint64_t*   pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
# endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */

# ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s, size_t n,   signed int*  pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(char    const* s, size_t n, unsigned int*  pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n,   signed int*  pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, unsigned int*  pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
# endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

# ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE

inline bool try_parse_to(char    const* s, size_t n,   signed long* pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(char    const* s, size_t n, unsigned long* pi,  char   const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n,   signed long* pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
inline bool try_parse_to(wchar_t const* s, size_t n, unsigned long* pi, wchar_t const** endptr) { return ximpl_string_to_integer_util_::try_string_to_integer_len_4_(s, n, pi, endptr); }
# endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/* try_parse_to(C const*, size_t, C const*, I*, C const**) */

/** Attempts to convert a decimal numeric string to an integer, against the
 *
 * \param s

 */
template <
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
bool
try_parse_to(
    C const*        s
,   ss_size_t       len
,   C const*        validEndChars
,   I*              pi
,   C const**       endptr
)
{
    return ximpl_string_to_integer_util_::try_string_to_integer_len_6_(s, len, pi, STLSOFT_NS_QUAL(c_str_data)(validEndChars), STLSOFT_NS_QUAL(c_str_len)(validEndChars), endptr);
}

/* /////////////////////////////////////////////////////////////////////////
 * code coverage
 */

#ifdef STLSOFT_USE_XCOVER
namespace
{
    class register_with_xcover_posterior
    {
    public:
        register_with_xcover_posterior()
        {
            XCOVER_MARK_FILE_END();
        }

    } instance_posterior;
}
#endif

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

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER */

/* ///////////////////////////// end of file //////////////////////////// */

