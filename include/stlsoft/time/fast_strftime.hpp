/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/time/fast_strftime.hpp
 *
 * Purpose:     Efficient drop-in replacement for strftime().
 *
 * Created:     23rd December 2018
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2018-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/time/fast_strftime.hpp
 *
 * \brief [C++] Efficient drop-in replacement for
 *   <code>strftime()</code>
 *  (\ref group__library__Time "Time" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME
#define STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_TIME_HPP_FAST_STRFTIME_MAJOR       1
# define STLSOFT_VER_STLSOFT_TIME_HPP_FAST_STRFTIME_MINOR       3
# define STLSOFT_VER_STLSOFT_TIME_HPP_FAST_STRFTIME_REVISION    1
# define STLSOFT_VER_STLSOFT_TIME_HPP_FAST_STRFTIME_EDIT        14
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
# include <stlsoft/string/string_slice.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */

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

struct fast_strftime_info_a_t
{
    ss_sint32_t                 flags;
    ss_sint32_t                 flags_ex;
    stlsoft_C_string_slice_a_t  weekdays_long[7];
    stlsoft_C_string_slice_a_t  weekdays_short[7];
    stlsoft_C_string_slice_a_t  months_long[12];
    stlsoft_C_string_slice_a_t  months_short[12];
};

struct fast_strftime_info_w_t
{
    ss_sint32_t                 flags;
    ss_sint32_t                 flags_ex;
    stlsoft_C_string_slice_w_t  weekdays_long[7];
    stlsoft_C_string_slice_w_t  weekdays_short[7];
    stlsoft_C_string_slice_w_t  months_long[12];
    stlsoft_C_string_slice_w_t  months_short[12];
};

/* /////////////////////////////////////////////////////////////////////////
 * worker functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_fast_strftime_
{

template <ss_typename_param_k T>
struct fast_strftime_traits_;

STLSOFT_TEMPLATE_SPECIALISATION
struct fast_strftime_traits_<char>
{
    typedef char                        char_type;
    typedef stlsoft_C_string_slice_a_t  slice_type;

    static char_type const* const* tens_and_units()
    {
        static char_type const* const s_tnu[] =
        {
                "00"
            ,   "01"
            ,   "02"
            ,   "03"
            ,   "04"
            ,   "05"
            ,   "06"
            ,   "07"
            ,   "08"
            ,   "09"
            ,   "10"
            ,   "11"
            ,   "12"
            ,   "13"
            ,   "14"
            ,   "15"
            ,   "16"
            ,   "17"
            ,   "18"
            ,   "19"
            ,   "20"
            ,   "21"
            ,   "22"
            ,   "23"
            ,   "24"
            ,   "25"
            ,   "26"
            ,   "27"
            ,   "28"
            ,   "29"
            ,   "30"
            ,   "31"
            ,   "32"
            ,   "33"
            ,   "34"
            ,   "35"
            ,   "36"
            ,   "37"
            ,   "38"
            ,   "39"
            ,   "40"
            ,   "41"
            ,   "42"
            ,   "43"
            ,   "44"
            ,   "45"
            ,   "46"
            ,   "47"
            ,   "48"
            ,   "49"
            ,   "50"
            ,   "51"
            ,   "52"
            ,   "53"
            ,   "54"
            ,   "55"
            ,   "56"
            ,   "57"
            ,   "58"
            ,   "59"
            ,   "60"
            ,   "61"
            ,   "62"
            ,   "63"
            ,   "64"
            ,   "65"
            ,   "66"
            ,   "67"
            ,   "68"
            ,   "69"
            ,   "70"
            ,   "71"
            ,   "72"
            ,   "73"
            ,   "74"
            ,   "75"
            ,   "76"
            ,   "77"
            ,   "78"
            ,   "79"
            ,   "80"
            ,   "81"
            ,   "82"
            ,   "83"
            ,   "84"
            ,   "85"
            ,   "86"
            ,   "87"
            ,   "88"
            ,   "89"
            ,   "90"
            ,   "91"
            ,   "92"
            ,   "93"
            ,   "94"
            ,   "95"
            ,   "96"
            ,   "97"
            ,   "98"
            ,   "99"
        };

        return s_tnu;
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct fast_strftime_traits_<wchar_t>
{
    typedef wchar_t                     char_type;
    typedef stlsoft_C_string_slice_w_t  slice_type;

    static char_type const* const* tens_and_units()
    {
        static char_type const* const s_tnu[] =
        {
                L"00"
            ,   L"01"
            ,   L"02"
            ,   L"03"
            ,   L"04"
            ,   L"05"
            ,   L"06"
            ,   L"07"
            ,   L"08"
            ,   L"09"
            ,   L"10"
            ,   L"11"
            ,   L"12"
            ,   L"13"
            ,   L"14"
            ,   L"15"
            ,   L"16"
            ,   L"17"
            ,   L"18"
            ,   L"19"
            ,   L"20"
            ,   L"21"
            ,   L"22"
            ,   L"23"
            ,   L"24"
            ,   L"25"
            ,   L"26"
            ,   L"27"
            ,   L"28"
            ,   L"29"
            ,   L"30"
            ,   L"31"
            ,   L"32"
            ,   L"33"
            ,   L"34"
            ,   L"35"
            ,   L"36"
            ,   L"37"
            ,   L"38"
            ,   L"39"
            ,   L"40"
            ,   L"41"
            ,   L"42"
            ,   L"43"
            ,   L"44"
            ,   L"45"
            ,   L"46"
            ,   L"47"
            ,   L"48"
            ,   L"49"
            ,   L"50"
            ,   L"51"
            ,   L"52"
            ,   L"53"
            ,   L"54"
            ,   L"55"
            ,   L"56"
            ,   L"57"
            ,   L"58"
            ,   L"59"
            ,   L"60"
            ,   L"61"
            ,   L"62"
            ,   L"63"
            ,   L"64"
            ,   L"65"
            ,   L"66"
            ,   L"67"
            ,   L"68"
            ,   L"69"
            ,   L"70"
            ,   L"71"
            ,   L"72"
            ,   L"73"
            ,   L"74"
            ,   L"75"
            ,   L"76"
            ,   L"77"
            ,   L"78"
            ,   L"79"
            ,   L"80"
            ,   L"81"
            ,   L"82"
            ,   L"83"
            ,   L"84"
            ,   L"85"
            ,   L"86"
            ,   L"87"
            ,   L"88"
            ,   L"89"
            ,   L"90"
            ,   L"91"
            ,   L"92"
            ,   L"93"
            ,   L"94"
            ,   L"95"
            ,   L"96"
            ,   L"97"
            ,   L"98"
            ,   L"99"
        };

        return s_tnu;
    }
};


template <
    ss_typename_param_k T_char
,   ss_typename_param_k T_info
>
inline
size_t
fast_strftime_(
    T_char              dest[]
,   size_t const        cchDest
,   T_char const*       fmt
,   struct tm const*    tm
,   T_info const&       info
)
{
    typedef fast_strftime_traits_<T_char>           traits_t;
    typedef ss_typename_type_k traits_t::slice_type slice_t;

    // References:
    //
    // - https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l
    // - http://www.cplusplus.com/reference/ctime/strftime/
    // - https://en.cppreference.com/w/cpp/chrono/c/strftime

#ifndef NDEBUG

    STLSOFT_ASSERT(0 == cchDest || NULL != dest);

    STLSOFT_ASSERT(NULL != fmt);

    STLSOFT_ASSERT(NULL != tm);
    STLSOFT_ASSERT(tm->tm_sec >= 0 && tm->tm_sec < 60);
    STLSOFT_ASSERT(tm->tm_min >= 0 && tm->tm_min < 60);
    STLSOFT_ASSERT(tm->tm_hour >= 0 && tm->tm_hour < 24);
    STLSOFT_ASSERT(tm->tm_mday >= 1 && tm->tm_mday <= 31);
    STLSOFT_ASSERT(tm->tm_mon >= 0 && tm->tm_mon < 12);
    STLSOFT_ASSERT(tm->tm_year >= 0 && tm->tm_year < 9900);
    STLSOFT_ASSERT(tm->tm_wday >= 0 && tm->tm_wday < 7);
    STLSOFT_ASSERT(tm->tm_yday >= 0 && tm->tm_yday < 366);

    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(info.weekdays_long); ++i)
    {
        STLSOFT_ASSERT(0 != info.weekdays_long[i].len);
        STLSOFT_ASSERT(NULL != info.weekdays_long[i].ptr);
    }}
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(info.weekdays_short); ++i)
    {
        STLSOFT_ASSERT(0 != info.weekdays_short[i].len);
        STLSOFT_ASSERT(NULL != info.weekdays_short[i].ptr);
    }}
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(info.months_long); ++i)
    {
        STLSOFT_ASSERT(0 != info.months_long[i].len);
        STLSOFT_ASSERT(NULL != info.months_long[i].ptr);
    }}
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(info.months_short); ++i)
    {
        STLSOFT_ASSERT(0 != info.months_short[i].len);
        STLSOFT_ASSERT(NULL != info.months_short[i].ptr);
    }}
#endif

    enum state_t
    {
            state_literal
        ,   state_percent
        ,   state_percent_hash
    };

    static
    T_char const* const* tens_and_units = traits_t::tens_and_units();

    state_t             state   =   state_literal;

    size_t              n       =   0;

    size_t const        cch_fmt =   stlsoft::c_str_len(fmt);
    T_char const*       b_fmt   =   fmt;
    T_char const* const e_fmt   =   b_fmt + cch_fmt;
    bool                hashed  =   false;

    int                 v       =   -1;
    int                 wd      =   -1;
    T_char const*       s;

    slice_t const*      sl;

    for (; b_fmt != e_fmt; ++b_fmt)
    {
        T_char const ch = *b_fmt;

        STLSOFT_ASSERT(n <= cchDest);

        switch (state)
        {
        case state_literal:

            switch (ch)
            {
            case '%':

                state = state_percent;
                break;
            default:

                if (!(n + 1 < cchDest))
                {
                    return 0;
                }

                dest[n++] = ch;
                break;
            }
            break;
        case state_percent:

            if ('%' == ch)
            {

                if (!(n + 1 < cchDest))
                {
                    return 0;
                }

                dest[n++] = ch;
                state = state_literal;
                break;
            }
            else if ('#' == ch)
            {
                state = state_percent_hash;
                break;
            }
            else
            {
        case state_percent_hash:

                hashed = (state_percent_hash == state);

                switch (ch)
                {
                case '%':

                    if (!(n + 1 < cchDest))
                    {
                        return 0;
                    }

                    dest[n++] = ch;
                    break;

                case 0:
week_number_U:

                    if (tm->tm_yday < wd)
                    {
                        v = 0;
                    }
                    else
                    {
                        v = tm->tm_yday / 7;

                        if (wd <= (tm->tm_yday % 7))
                        {
                            ++v;
                        }
                    }

finish_two_digit:

                    if ((cchDest - n) < 3)
                    {
                        return 0;
                    }

                    STLSOFT_ASSERT(v >= 0 && v < 100);

                    s = tens_and_units[v];

                    if (!hashed || '0' != s[0])
                    {
                        if (!(n + 1 < cchDest))
                        {
                            return 0;
                        }

                        dest[n++] = s[0];
                    }

                    if (!(n + 1 < cchDest))
                    {
                        return 0;
                    }

                    dest[n++] = s[1];

                    state = state_literal;

                    break;

finish_three_digit:

                    STLSOFT_ASSERT(v >= 0 && v < 1000);

                    if ((cchDest - n) < 4)
                    {
                        return 0;
                    }

                    if (v > 99)
                    {
                        int const       ix0 = v % 100;
                        int const       ix1 = v / 100;
                        T_char const*   tu0 = tens_and_units[ix0];
                        T_char const*   tu1 = tens_and_units[ix1];

                        if (!(n + 3 < cchDest))
                        {
                            return 0;
                        }

                        dest[n++] = tu1[1];
                        dest[n++] = tu0[0];
                        dest[n++] = tu0[1];
                    }
                    else
                    {
                        T_char const* tu0 = tens_and_units[v];

                        if (hashed)
                        {
                            if (v > 10)
                            {
                                if (!(n + 1 < cchDest))
                                {
                                    return 0;
                                }

                                dest[n++] = tu0[0];
                            }

                            if (!(n + 1 < cchDest))
                            {
                                return 0;
                            }

                            dest[n++] = tu0[1];
                        }
                        else
                        {
                            if (!(n + 3 < cchDest))
                            {
                                return 0;
                            }

                            dest[n++] = '0';
                            dest[n++] = tu0[0];
                            dest[n++] = tu0[1];
                        }
                    }

                    state = state_literal;

                    break;

finish_sliced_item:

                    if ((cchDest - n) < (1 + sl->len))
                    {
                        return 0;
                    }

                    { for (size_t i = 0, l = sl->len; i != l; ++i, ++n)
                    {
                        dest[n] = sl->ptr[i];
                    }}

                    state = state_literal;

                    break;

                case 'A':

                    sl = &info.weekdays_long[tm->tm_wday];

                    goto finish_sliced_item;

                case 'a':

                    sl = &info.weekdays_short[tm->tm_wday];

                    goto finish_sliced_item;

                case 'B':

                    sl = &info.months_long[tm->tm_mon];

                    goto finish_sliced_item;

                case 'b':
                case 'h':

                    sl = &info.months_short[tm->tm_mon];

                    goto finish_sliced_item;

                case 'd':

                    v = tm->tm_mday;

                    goto finish_two_digit;

                case 'H':

                    v = tm->tm_hour;

                    goto finish_two_digit;

                case 'I':

                    v = tm->tm_hour % 12;

                    if (0 == v)
                    {
                        v = 12;
                    }

                    goto finish_two_digit;

                case 'j':

                    v = 1 + tm->tm_yday;

                    goto finish_three_digit;

                case 'M':

                    v = tm->tm_min;

                    goto finish_two_digit;

                case 'm':

                    v = tm->tm_mon + 1;

                    goto finish_two_digit;

                case 'S':

                    v = tm->tm_sec;

                    goto finish_two_digit;

                case 'U':

                    wd = tm->tm_wday;

                    goto week_number_U;

                case 'W':

                    if (0 == tm->tm_wday)
                    {
                        wd = 6;
                    }
                    else
                    {
                        wd = tm->tm_wday - 1;
                    }

                    goto week_number_U;

                case 'w':

                    v = tm->tm_wday;

                    if ((cchDest - n) < 2)
                    {
                        return 0;
                    }

                    dest[n++] = T_char('0' + v);

                    state = state_literal;

                    break;

                case 'Y':

                    v = 1900 + tm->tm_year;

                    if ((cchDest - n) < 5)
                    {
                        return 0;
                    }
                    else
                    {
                        int const       ix0 = v % 100;
                        int const       ix1 = v / 100;
                        T_char const*   tu0 = tens_and_units[ix0];
                        T_char const*   tu1 = tens_and_units[ix1];

                        if (!(n + 4 < cchDest))
                        {
                            return 0;
                        }

                        dest[n++] = tu1[0];
                        dest[n++] = tu1[1];
                        dest[n++] = tu0[0];
                        dest[n++] = tu0[1];
                    }

                    state = state_literal;

                    break;

                case 'y':

                    v = (tm->tm_year % 100);

                    goto finish_two_digit;


                // The extensions

                case 'C': // century (zero-padded)

                    v = (1900 + tm->tm_year) / 100;

                    goto finish_two_digit;

                case 'c': // locale-specific date and time

                    break;

                case 'D': // %m/%d/%y

                    if ((cchDest - n) < 9)
                    {
                        return 0;
                    }
                    else
                    {
                        s = tens_and_units[tm->tm_mon + 1];

                        dest[n++] = s[0];
                        dest[n++] = s[1];

                        dest[n++] = '/';

                        s = tens_and_units[tm->tm_mday];

                        dest[n++] = s[0];
                        dest[n++] = s[1];

                        dest[n++] = '/';

                        s = tens_and_units[tm->tm_year % 100];

                        dest[n++] = s[0];
                        dest[n++] = s[1];

                        state = state_literal;
                    }

                    break;

                case 'e': // space-leading-padded day-of-month

                    if ((cchDest - n) < 3)
                    {
                        return 0;
                    }

                    s = tens_and_units[tm->tm_mday];

                    if ('0' == s[0])
                    {
                        if (!hashed)
                        {
                            dest[n++] = ' ';
                        }
                    }
                    else
                    {
                        dest[n++] = s[0];
                    }

                    dest[n++] = s[1];

                    state = state_literal;

                    break;

                case 'F': // %Y-%m-%d

                    if ((cchDest - n) < 11)
                    {
                        return 0;
                    }
                    else
                    {
                        v = 1900 + tm->tm_year;

                        int const       ix0 = v % 100;
                        int const       ix1 = v / 100;
                        T_char const*   tu0 = tens_and_units[ix0];
                        T_char const*   tu1 = tens_and_units[ix1];

                        dest[n++] = tu1[0];
                        dest[n++] = tu1[1];
                        dest[n++] = tu0[0];
                        dest[n++] = tu0[1];

                        dest[n++] = '-';

                        s = tens_and_units[tm->tm_mon + 1];

                        if (!hashed || '0' != s[0])
                        {
                            dest[n++] = s[0];
                        }

                        dest[n++] = s[1];

                        dest[n++] = '-';

                        s = tens_and_units[tm->tm_mday];

                        if (!hashed || '0' != s[0])
                        {
                            dest[n++] = s[0];
                        }

                        dest[n++] = s[1];

                        state = state_literal;
                    }

                    break;

                case 'G': // week-based year

                    break;

                case 'g': // week-based year - last two digits

                    break;

                case 'n': // a '\n'

                    if ((cchDest - n) < 2)
                    {
                        return 0;
                    }

                    dest[n++] = '\n';

                    state = state_literal;

                    break;

                case 'p': // locale's AM/PM indicator

                    break;

                case 'R': // %H:%M

                    if ((cchDest - n) < 6)
                    {
                        return 0;
                    }
                    else
                    {
                        s = tens_and_units[tm->tm_hour];

                        if (!hashed || '0' != s[0])
                        {
                            dest[n++] = s[0];
                        }

                        dest[n++] = s[1];

                        dest[n++] = ':';

                        s = tens_and_units[tm->tm_min];

                        if (!hashed || '0' != s[0])
                        {
                            dest[n++] = s[0];
                        }

                        dest[n++] = s[1];

                        state = state_literal;
                    }

                    break;

                case 'r': // locale's 12-hr clock time

                    break;

                case 'T': // %H:%M:%S

                    if ((cchDest - n) < 9)
                    {
                        return 0;
                    }
                    else
                    {
                        s = tens_and_units[tm->tm_hour];

                        if (!hashed || '0' != s[0])
                        {
                            dest[n++] = s[0];
                        }

                        dest[n++] = s[1];

                        dest[n++] = ':';

                        s = tens_and_units[tm->tm_min];

                        if (!hashed || '0' != s[0])
                        {
                            dest[n++] = s[0];
                        }

                        dest[n++] = s[1];

                        dest[n++] = ':';

                        s = tens_and_units[tm->tm_sec];

                        if (!hashed || '0' != s[0])
                        {
                            dest[n++] = s[0];
                        }

                        dest[n++] = s[1];

                        state = state_literal;
                    }

                    break;

                case 't': // a '\t'

                    if ((cchDest - n) < 2)
                    {
                        return 0;
                    }

                    dest[n++] = '\t';

                    state = state_literal;

                    break;

                case 'u': // ISO 8601 weekday (1 - 7, Monday == 1)

                    if ((cchDest - n) < 2)
                    {
                        return 0;
                    }

                    v = tm->tm_wday;

                    if (0 == v)
                    {
                        v = 7;
                    }

                    dest[n++] = tens_and_units[v][1];

                    state = state_literal;

                    break;

                case 'V': // ISO 8601 week number

                    break;

                case 'X': // locale-dependent time

                    break;

                case 'x': // locale-dependent date

                    break;

                case 'Z': // Timezone abbreviation

                    break;

                case 'z': // ISO 8601 offset

                    break;
                }
            }
            break;

        default:

            STLSOFT_MESSAGE_ASSERT("should not get here", false);
            break;
        }
    }

    dest[n] = '\0';

    return n;
}

} /* namespace ximpl_fast_strftime_ */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Partial drop-in replacement for <code>std::strftime()</code>
 *
 * \param dest
 * \param cchDest
 * \param fmt Format string. See remarks for details
 * \param tm Pointer to \c tm data structure. May not be \c nullptr
 *
 * \pre nullptr != tm
 * \pre 0 == cchDest || nullptr != dest
 *
 * \remarks The following formatting codes (supported by VC++ 6) are supported:
 * \li \c \% - a percent sign
 * \li \c a - weekday name (abbreviated)
 * \li \c A - weekday name (full)
 * \li \c b - month name (abbreviated) - same as \c h
 * \li \c B - month name (full)
 * \li \c C - century as (two-digit) decimal number [00-99]
 * \li \c d - day of month as decimal number [01-31]
 * \li \c h - month name (abbreviated) - same as \c b
 * \li \c H - hour as 24-hour as decimal number [00-23]
 * \li \c I - hour as 12-hour as decimal number [01-12]
 * \li \c j - day of year as decimal number [001-366]
 * \li \c m - month as decimal number [01-12]
 * \li \c M - minute as decimal number [00-59]
 * \li \c S - second as decimal number [00-59]
 * \li \c U - week of year, with Sunday as first day, as decimal number [0-53]
 * \li \c w - weekday, with Sunday as 0, as decimal number [0-6]
 * \li \c W - week of year, with Monday as first day, as decimal number [0-53]
 * \li \c y - year without century, as decimal number [0-99]
 * \li \c Y - year with century, as decimal number
 *
 * \remarks The following formatting codes (supported by VC++ 10) are supported:
 * \li \c D - equivalent to "%m/%d/%y"
 * \li \c e - day of month as space-padded decimal number [ 1-31]
 * \li \c F - equivalent to "%Y-%m-%d"
 * \li \c n - a carriage return
 * \li \c R - equivalent to "%H:%M"
 * \li \c t - a TAB
 * \li \c T - equivalent to "%H:%M:%S"
 * \li \c u - weekday, with Monday as 1, as decimal number [1-7]
 *
 * \remarks The following formatting codes are not supported
 * \li \c c -
 * \li \c g -
 * \li \c G -
 * \li \c p -
 * \li \c r -
 * \li \c V -
 * \li \c x -
 * \li \c X -
 * \li \c z -
 * \li \c Z -
 *
 * \remarks The following supported codes are modified by the '#'
 *   character - e.g. "%#d" - to remove leading 0, if any:
 * \li \c d
 * \li \c D
 * \li \c e
 * \li \c F
 * \li \c H
 * \li \c I
 * \li \c j
 * \li \c m
 * \li \c M
 * \li \c r
 * \li \c S
 * \li \c T
 * \li \c U
 * \li \c V
 * \li \c w
 * \li \c y
 * \li \c Y
 *
 * \remarks The following supported codes are unmodified by the '#'
 *   character - e.g. "%#a":
 * \li \c \%
 * \li \c a
 * \li \c A
 * \li \c b
 * \li \c B
 * \li \c G
 * \li \c h
 * \li \c n
 * \li \c p
 * \li \c t
 * \li \c u
 * \li \c W
 * \li \c X
 * \li \c z
 * \li \c Z
 */
inline
size_t
fast_strftime(
    char                        dest[]
,   size_t                      cchDest
,   char const*                 fmt
,   struct tm const*            tm
)
{
    static
    fast_strftime_info_a_t const s_info =
    {
            0

        ,   0

        ,   {
                { 6, "Sunday" }
            ,   { 6, "Monday" }
            ,   { 7, "Tuesday" }
            ,   { 9, "Wednesday" }
            ,   { 8, "Thursday" }
            ,   { 6, "Friday" }
            ,   { 8, "Saturday" }
            }

        ,   {
                { 3, "Sun" }
            ,   { 3, "Mon" }
            ,   { 3, "Tue" }
            ,   { 3, "Wed" }
            ,   { 3, "Thu" }
            ,   { 3, "Fri" }
            ,   { 3, "Sat" }
            }

        ,   {
                { 7, "January" }
            ,   { 8, "February" }
            ,   { 5, "March" }
            ,   { 5, "April" }
            ,   { 3, "May" }
            ,   { 4, "June" }
            ,   { 4, "July" }
            ,   { 6, "August" }
            ,   { 9, "September" }
            ,   { 7, "October" }
            ,   { 8, "November" }
            ,   { 8, "December" }
            }

        ,   {
                { 3, "Jan" }
            ,   { 3, "Feb" }
            ,   { 3, "Mar" }
            ,   { 3, "Apr" }
            ,   { 3, "May" }
            ,   { 3, "Jun" }
            ,   { 3, "Jul" }
            ,   { 3, "Aug" }
            ,   { 3, "Sep" }
            ,   { 3, "Oct" }
            ,   { 3, "Nov" }
            ,   { 3, "Dec" }
            }
    };

    return ximpl_fast_strftime_::fast_strftime_(dest, cchDest, fmt, tm, s_info);
}

/** wide-string form */
inline
size_t
fast_wcsftime(
    wchar_t                     dest[]
,   size_t                      cchDest
,   wchar_t const*              fmt
,   struct tm const*            tm
)
{
    static
    fast_strftime_info_w_t const s_info =
    {
            0

        ,   0

        ,   {
                { 6, L"Sunday" }
            ,   { 6, L"Monday" }
            ,   { 7, L"Tuesday" }
            ,   { 9, L"Wednesday" }
            ,   { 8, L"Thursday" }
            ,   { 6, L"Friday" }
            ,   { 8, L"Saturday" }
            }

        ,   {
                { 3, L"Sun" }
            ,   { 3, L"Mon" }
            ,   { 3, L"Tue" }
            ,   { 3, L"Wed" }
            ,   { 3, L"Thu" }
            ,   { 3, L"Fri" }
            ,   { 3, L"Sat" }
            }

        ,   {
                { 7, L"January" }
            ,   { 8, L"February" }
            ,   { 5, L"March" }
            ,   { 5, L"April" }
            ,   { 3, L"May" }
            ,   { 4, L"June" }
            ,   { 4, L"July" }
            ,   { 6, L"August" }
            ,   { 9, L"September" }
            ,   { 7, L"October" }
            ,   { 8, L"November" }
            ,   { 8, L"December" }
            }

        ,   {
                { 3, L"Jan" }
            ,   { 3, L"Feb" }
            ,   { 3, L"Mar" }
            ,   { 3, L"Apr" }
            ,   { 3, L"May" }
            ,   { 3, L"Jun" }
            ,   { 3, L"Jul" }
            ,   { 3, L"Aug" }
            ,   { 3, L"Sep" }
            ,   { 3, L"Oct" }
            ,   { 3, L"Nov" }
            ,   { 3, L"Dec" }
            }
    };

    return ximpl_fast_strftime_::fast_strftime_(dest, cchDest, fmt, tm, s_info);
}

/** wide-string form */
inline
size_t
fast_strftime(
    wchar_t                     dest[]
,   size_t                      cchDest
,   wchar_t const*              fmt
,   struct tm const*            tm
)
{
    return fast_wcsftime(dest, cchDest, fmt, tm);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template<
    ss_typename_param_k T_character
,   ss_size_t           V_dimension
>
inline
size_t
fast_strftime(
    T_character               (&dest)[V_dimension]
,   T_character const*          fmt
,   struct tm const*            tm
)
{
    return fast_strftime(dest, V_dimension, fmt, tm);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

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

#endif /* !STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME */

/* ///////////////////////////// end of file //////////////////////////// */

