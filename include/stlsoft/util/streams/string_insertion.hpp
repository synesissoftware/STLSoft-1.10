/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/streams/string_insertion.hpp
 *
 * Purpose:     Contains equivalents to contents of std's <utility>.
 *
 * Created:     29th January 2024
 * Updated:     30th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/util/streams/string_insertion.hpp
 *
 * \brief [C++] Contains ;
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION
#define STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION_MINOR    0
# define STLSOFT_VER_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION_REVISION 1
# define STLSOFT_VER_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION_EDIT     1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_ALGORITHM_STD_HPP_ALT
# include <stlsoft/algorithms/std/alt.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHM_STD_HPP_ALT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX
# include <stlsoft/util/minmax.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX */

#ifndef STLSOFT_INCL_IOS
# define STLSOFT_INCL_IOS
# include <ios>
#endif /* !STLSOFT_INCL_IOS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
namespace util
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#ifndef STLSOFT_NO_NAMESPACE

namespace impl
{
#endif /* STLSOFT_NO_NAMESPACE */


template <
    ss_typename_param_k T_stream
,   ss_typename_param_k T_character
>
inline
void
string_insert_3_(
    T_character const*              s
,   ss_size_t                       cch
,   T_stream&                       stm
)
{
    stm.write(s, static_cast<ss_streamoff_t>(cch));
}

template <
    ss_typename_param_k T_stream
,   ss_typename_param_k T_character
>
inline
void
string_insert_4_(
    T_character const*              s
,   ss_size_t                       cch
,   T_stream&                       stm
,   std::basic_ios<T_character>*
)
{
    T_character const   c_fill  =   stm.fill();
    ss_ptrdiff_t const  n_width =   stm.width();

    if (0 == n_width ||
        static_cast<ss_ptrdiff_t>(cch) >= n_width ||
        T_character(0) == c_fill)
    {
        string_insert_3_(s, cch, stm);
    }
    else
    {
        std::ios_base::fmtflags flags = stm.flags();

        bool const is_right_justified = 0 != (std::ios_base::right & flags);

        if (!is_right_justified)
        {
            stm.write(s, static_cast<ss_streamoff_t>(cch));
        }

        // do padding

        {
            T_character padding[256];

            std_fill_n(padding, STLSOFT_NUM_ELEMENTS(padding), c_fill);

            ss_size_t num_to_write = n_width - cch;

            for ( ; 0 != num_to_write; )
            {
                ss_size_t n = STLSOFT_NS_QUAL(minimum(num_to_write, STLSOFT_NUM_ELEMENTS(padding)));

                stm.write(padding, n);

                num_to_write -= n;
            }
        }

        if (is_right_justified)
        {
            string_insert_3_(s, cch, stm);
        }
    }
}

template <
    ss_typename_param_k T_stream
,   ss_typename_param_k T_character
>
inline
void
string_insert_4_(
    T_character const*              s
,   ss_size_t                       cch
,   T_stream&                       stm
,   ...
)
{
    string_insert_3_(s, cch, stm);
}


#ifndef STLSOFT_NO_NAMESPACE

} /* namespace impl */
#endif /* STLSOFT_NO_NAMESPACE */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */


template <
    ss_typename_param_k T_stream
,   ss_typename_param_k T_character
>
inline
void
string_insert(
    T_stream&               stm
,   T_character const*      s
,   ss_size_t               cch
)
{
    impl::string_insert_4_(
        s
    ,   cch
    ,   stm
    ,   &stm
    );
}

template <
    ss_typename_param_k T_stream
>
inline
void
string_insert_m(
    T_stream&               stm
,   ss_char_a_t const*      s
,   ss_size_t               cch
)
{
    impl::string_insert_4_(
        s
    ,   cch
    ,   stm
    ,   &stm
    );
}

template <
    ss_typename_param_k T_stream
>
inline
void
string_insert_w(
    T_stream&               stm
,   ss_char_w_t const*      s
,   ss_size_t               cch
)
{
    impl::string_insert_4_(
        s
    ,   cch
    ,   stm
    ,   &stm
    );
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace util */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STREAMS_HPP_STRING_INSERTION */

/* ///////////////////////////// end of file //////////////////////////// */

