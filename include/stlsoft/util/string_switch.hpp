/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/string_switch.hpp
 *
 * Purpose:     String-switch functions.
 *
 * Created:     10th May 2010
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/string_switch.hpp
 *
 * \brief [C++] String-switch functions
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH
#define STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_MINOR    3
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_REVISION 4
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_EDIT     31
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS
# include <stlsoft/string/string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace ximpl
{

    template<
        ss_typename_param_k C
    ,   ss_typename_param_k E
    >
    struct string_case_item_t
    {
        C const*   name;
        E          value;
    };

    template<
        ss_typename_param_k C
    ,   ss_typename_param_k E
    ,   ss_size_t           N
    >
    struct string_case_item_array_t
    {
    public:
        typedef string_case_item_array_t<C, E, N>   class_type;

    public:
        string_case_item_array_t(string_case_item_t<C, E> const* p, ss_size_t n)
            : len(n)
        {
            STLSOFT_ASSERT(N == n);

            STLSOFT_COVER_MARK_LINE();

            { for (ss_size_t i = 0; i != n; ++i, ++p)
            {
                STLSOFT_COVER_MARK_LINE();

                ptr[i].name   = p->name;
                ptr[i].value  = p->value;
            }}
        }
    protected:
        void operator =(class_type const&);

    public:
        ss_size_t size() const
        {
            STLSOFT_COVER_MARK_LINE();

            return N;
        }

        string_case_item_t<C, E> const& operator [](ss_size_t i) const
        {
            STLSOFT_ASSERT(i < N);

            STLSOFT_COVER_MARK_LINE();

            return ptr[i];
        }

    private:
        ss_size_t const             len;
        string_case_item_t<C, E>    ptr[N];
    };

} /* namespace ximpl */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Defines a set of one string-switch case, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 1>
string_cases(
    C const*  name0
,   E         value0
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
      { name0, value0 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of two string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 2>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of three string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 3>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of four string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 4>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of five string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 5>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of six string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 6>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of seven string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 7>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of eight string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 8>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of nine string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 9>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of ten string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 10>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of eleven string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 * \param name10 The name of the eleventh case
 * \param value10 The value of the eleventh case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 11>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
,   C const*  name10
,   E         value10
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
      , { name10, value10 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of twelve string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 * \param name10 The name of the eleventh case
 * \param value10 The value of the eleventh case
 * \param name11 The name of the twelfth case
 * \param value11 The value of the twelfth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 12>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
,   C const*  name10
,   E         value10
,   C const*  name11
,   E         value11
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
      , { name10, value10 }
      , { name11, value11 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of thirteen string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 * \param name10 The name of the eleventh case
 * \param value10 The value of the eleventh case
 * \param name11 The name of the twelfth case
 * \param value11 The value of the twelfth case
 * \param name12 The name of the thirteenth case
 * \param value12 The value of the thirteenth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 13>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
,   C const*  name10
,   E         value10
,   C const*  name11
,   E         value11
,   C const*  name12
,   E         value12
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
      , { name10, value10 }
      , { name11, value11 }
      , { name12, value12 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of fourteen string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 * \param name10 The name of the eleventh case
 * \param value10 The value of the eleventh case
 * \param name11 The name of the twelfth case
 * \param value11 The value of the twelfth case
 * \param name12 The name of the thirteenth case
 * \param value12 The value of the thirteenth case
 * \param name13 The name of the fourteenth case
 * \param value13 The value of the fourteenth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 14>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
,   C const*  name10
,   E         value10
,   C const*  name11
,   E         value11
,   C const*  name12
,   E         value12
,   C const*  name13
,   E         value13
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
      , { name10, value10 }
      , { name11, value11 }
      , { name12, value12 }
      , { name13, value13 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of fifteen string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 * \param name10 The name of the eleventh case
 * \param value10 The value of the eleventh case
 * \param name11 The name of the twelfth case
 * \param value11 The value of the twelfth case
 * \param name12 The name of the thirteenth case
 * \param value12 The value of the thirteenth case
 * \param name13 The name of the fourteenth case
 * \param value13 The value of the fourteenth case
 * \param name14 The name of the fifteenth case
 * \param value14 The value of the fifteenth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 15>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
,   C const*  name10
,   E         value10
,   C const*  name11
,   E         value11
,   C const*  name12
,   E         value12
,   C const*  name13
,   E         value13
,   C const*  name14
,   E         value14
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
      , { name10, value10 }
      , { name11, value11 }
      , { name12, value12 }
      , { name13, value13 }
      , { name14, value14 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of sixteen string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 * \param name10 The name of the eleventh case
 * \param value10 The value of the eleventh case
 * \param name11 The name of the twelfth case
 * \param value11 The value of the twelfth case
 * \param name12 The name of the thirteenth case
 * \param value12 The value of the thirteenth case
 * \param name13 The name of the fourteenth case
 * \param value13 The value of the fourteenth case
 * \param name14 The name of the fifteenth case
 * \param value14 The value of the fifteenth case
 * \param name15 The name of the sixteenth case
 * \param value15 The value of the sixteenth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline
ximpl::string_case_item_array_t<C, E, 16>
string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
,   C const*  name10
,   E         value10
,   C const*  name11
,   E         value11
,   C const*  name12
,   E         value12
,   C const*  name13
,   E         value13
,   C const*  name14
,   E         value14
,   C const*  name15
,   E         value15
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
      , { name10, value10 }
      , { name11, value11 }
      , { name12, value12 }
      , { name13, value13 }
      , { name14, value14 }
      , { name15, value15 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k C
,   ss_typename_param_k R
,   ss_size_t           N
,   ss_typename_param_k V
>
inline
bool
string_switch_(
    C const*                                        s
,   size_t                                          len
,   R*                                              result
,   ximpl::string_case_item_array_t<C, V, N> const& cases
,   R                                               resultBase
)
;

template<
    ss_typename_param_k C
,   ss_typename_param_k R
,   ss_size_t           N
,   ss_typename_param_k V
>
inline
bool
string_switch_(
    C const*                                        s
,   size_t                                          len
,   R*                                              result
,   ximpl::string_case_item_array_t<C, V, N> const& cases
)
;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Conducts a string-switch over the given string \c s, according to the
 * given cases, putting the matching value into the given \c result
 *
 * \param s The string whose value is to be tested
 * \param result Pointer to the variable to receive the result, if any of
 *   the cases are matched
 * \param cases The sequence of cases, created via string_cases(), to be
 *   tested against
 * \param resultBase The value to which the result is set before being
 *   combined with the result, if any, of the matched cases. This allows
 *   the function to act in a bit-flag combination mode
 *
 * \retval true <code>*result</code> is assigned to a combination of the
 *   matching case's value and <code>resultBase</code>
 * \retval true <code>*result</code> is assigned to <code>resultBase</code>
 *
 * \warning If this function is used with an enumeration type that does not
 *   have flag-semantics, the use of the value of <code>resultBase</code>
 *   in evaluating the value of the out-parameter <code>result<code>,
 *   regardless of whether match occurs, can lead to confusing results.
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k R
,   ss_typename_param_k C
>
inline
bool
string_switch(
    S const&                                        s
,   R*                                              result
,   C const&                                        cases
,   R                                               resultBase
)
{
    return string_switch_(
        stlsoft::c_str_data(s)
    ,   stlsoft::c_str_len(s)
    ,   result
    ,   cases
    ,   resultBase
    );
}

/** Conducts a string-switch over the given string \c s, according to the
 * given cases, putting the matching value into the given \c result
 *
 * \param s The string whose value is to be tested
 * \param result Pointer to the variable to receive the result, if any of
 *   the cases are matched
 * \param cases The sequence of cases, created via string_cases(), to be
 *   tested against
 *
 * \retval true <code>*result</code> is assigned to the matching case's
 *   value and <code>resultBase</code>
 * \retval true <code>*result</code> is not assigned
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k R
,   ss_typename_param_k C
>
inline
bool
string_switch(
    S const&                                        s
,   R*                                              result
,   C const&                                        cases
)
{
    return string_switch_(
        stlsoft::c_str_data(s)
    ,   stlsoft::c_str_len(s)
    ,   result
    ,   cases
    );
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k C
,   ss_typename_param_k R
,   ss_size_t           N
,   ss_typename_param_k V
>
inline
bool
string_switch_(
    C const*                                        s
,   size_t                                          len
,   R*                                              result
,   ximpl::string_case_item_array_t<C, V, N> const& cases
,   R                                               resultBase
)
{
    STLSOFT_ASSERT(NULL != s);

    STLSOFT_COVER_MARK_LINE();

    typedef stlsoft_char_traits<C> char_traits_t;

    { for (ss_size_t i = 0; i != cases.size(); ++i)
    {
        STLSOFT_COVER_MARK_LINE();

        ximpl::string_case_item_t<C, V> const&  case_   =   cases[i];
        size_t const                            caselen =   char_traits_t::length(case_.name);

        if (caselen == len &&
            0 == char_traits_t::compare(case_.name, s, len))
        {
            STLSOFT_COVER_MARK_LINE();

            *result = static_cast<R>(resultBase | case_.value);

            return true;
        }
    }}

    STLSOFT_COVER_MARK_LINE();

    *result = resultBase;

    return false;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k R
,   ss_size_t           N
,   ss_typename_param_k V
>
inline
bool
string_switch_(
    C const*                                        s
,   size_t                                          len
,   R*                                              result
,   ximpl::string_case_item_array_t<C, V, N> const& cases
)
{
    STLSOFT_ASSERT(NULL != s);

    STLSOFT_COVER_MARK_LINE();

    typedef stlsoft_char_traits<C> char_traits_t;

    { for (ss_size_t i = 0; i != cases.size(); ++i)
    {
        STLSOFT_COVER_MARK_LINE();

        ximpl::string_case_item_t<C, V> const&  case_   =   cases[i];
        size_t const                            caselen =   char_traits_t::length(case_.name);

        if (caselen == len &&
            0 == char_traits_t::compare(case_.name, s, len))
        {
            STLSOFT_COVER_MARK_LINE();

            *result = case_.value;

            return true;
        }
    }}

    STLSOFT_COVER_MARK_LINE();

    return false;
}
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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH */

/* ///////////////////////////// end of file //////////////////////////// */

