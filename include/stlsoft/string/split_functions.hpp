/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/split_functions.hpp
 *
 * Purpose:     String split functions.
 *
 * Created:     28th January 2005
 * Updated:     22nd January 2024
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


/** \file stlsoft/string/split_functions.hpp
 *
 * \brief [C++] String split functions
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_MAJOR      2
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_MINOR      5
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_REVISION   1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS_EDIT       62
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

#if (   defined(STLSOFT_COMPILER_IS_BORLAND) && \
        __BORLANDC__ < 0x0560) || \
    (   defined(STLSOFT_COMPILER_IS_DMC) && \
        __DMC__ < 0x0844) || \
    (   defined(STLSOFT_COMPILER_IS_GCC) && \
        __GNUC__ < 3) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1200) || \
    defined(STLSOFT_COMPILER_IS_SUNPRO)
# define STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
# ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_STATIC_ARRAY
#  include <stlsoft/containers/static_array.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_STATIC_ARRAY */
#else /* ? STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
# include <vector>
#endif /* STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */

#ifndef STLSOFT_INCL_ALGORITHM
# define STLSOFT_INCL_ALGORITHM
# include <algorithm>
#endif /* !STLSOFT_INCL_ALGORITHM */
#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */
#ifndef STLSOFT_INCL_VECTOR
# define STLSOFT_INCL_VECTOR
# include <vector>
#endif /* !STLSOFT_INCL_VECTOR */

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

STLSOFT_OPEN_WORKER_NS_(ximpl_split_functions)

class flexible_integer
{
public:
    flexible_integer(ss_ptrdiff_t d)
        : d(d)
    {}
private:
    void operator =(flexible_integer const&);

public:
    operator ss_size_t() const STLSOFT_NOEXCEPT
    {
        return ss_size_t(d);
    }
    operator int() const STLSOFT_NOEXCEPT
    {
        return int(d);
    }

public: // fields
    ss_ptrdiff_t const  d;
};

template<
    ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
>
inline
ss_uint_t
split_impl_2(
    C const*    s
,   ss_size_t   cch
,   C           delim
,   S0&         s0
,   S1&         s1
)
{
    C const* const  b   =   s;
    C const* const  e   =   s + cch;
    C const*        it0 =   b;
    C const*        it1 =   STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    ss_uint_t       n   =   b != e;

    s0 = S0(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = e;
    }
    else
    {
        it0 = it1;
    }

    s1 = S1(it0, flexible_integer(it1 - it0));

    return n;
}

template<
    ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
>
inline
ss_uint_t
split_impl_3(
    C const*    s
,   ss_size_t   cch
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
)
{
    C const* const  b   =   s;
    C const* const  e   =   s + cch;
    C const*        it0 =   b;
    C const*        it1 =   STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    ss_uint_t       n   =   b != e;

    s0 = S0(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s1 = S1(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = e;
    }
    else
    {
        it0 = it1;
    }

    s2 = S2(it0, flexible_integer(it1 - it0));

    return n;
}

template<
    ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k S3
,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
>
inline
ss_uint_t
split_impl_4(
    C const*    s
,   ss_size_t   cch
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
,   S3&         s3
)
{
    C const* const  b   =   s;
    C const* const  e   =   s + cch;
    C const*        it0 =   b;
    C const*        it1 =   STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    ss_uint_t       n   =   b != e;

    s0 = S0(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s1 = S1(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s2 = S2(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = e;
    }
    else
    {
        it0 = it1;
    }

    s3 = S3(it0, flexible_integer(it1 - it0));

    return n;
}

template<
    ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k S3
,   ss_typename_param_k S4
,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
>
inline
ss_uint_t
split_impl_5(
    C const*    s
,   ss_size_t   cch
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
,   S3&         s3
,   S4&         s4
)
{
    C const* const  b   =   s;
    C const* const  e   =   s + cch;
    C const*        it0 =   b;
    C const*        it1 =   STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    ss_uint_t       n   =   b != e;

    s0 = S0(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s1 = S1(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s2 = S2(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s3 = S3(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = e;
    }
    else
    {
        it0 = it1;
    }

    s4 = S4(it0, flexible_integer(it1 - it0));

    return n;
}

template<
    ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k S3
,   ss_typename_param_k S4
,   ss_typename_param_k S5
,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
>
inline
ss_uint_t
split_impl_6(
    C const*    s
,   ss_size_t   cch
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
,   S3&         s3
,   S4&         s4
,   S5&         s5
)
{
    C const* const  b   =   s;
    C const* const  e   =   s + cch;
    C const*        it0 =   b;
    C const*        it1 =   STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    ss_uint_t       n   =   b != e;

    s0 = S0(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s1 = S1(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s2 = S2(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s3 = S3(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = STLSOFT_NS_QUAL_STD(find)(it0, e, delim);
    }
    else
    {
        it0 = it1;
    }

    s4 = S4(it0, flexible_integer(it1 - it0));

    if (e != it1)
    {
        ++n;
        it0 = ++it1;
        it1 = e;
    }
    else
    {
        it0 = it1;
    }

    s5 = S5(it0, flexible_integer(it1 - it0));

    return n;
}

STLSOFT_CLOSE_WORKER_NS_(ximpl_split_functions)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Splits a string into two, at the first incidence of a delimiter
 *
 * \ingroup group__library__String
 *
 * \warning The behaviour is undefined if the string instance being split is
 *        passed as one or both recipients
 *
 * \param s The input string to be split
 * \param delim The delimiter
 * \param s0 Mutating reference to the first split
 * \param s1 Mutating reference to the second split
 *
 * \return The number of splits detected
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k C /* = ss_typename_type_def_k S2::value_type */
>
inline
ss_uint_t
split(
    S const&    s
,   C           delim
,   S0&         s0
,   S1&         s1
)
{
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s0));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s1));

    return STLSOFT_WORKER_NS_QUAL_(ximpl_split_functions, split_impl_2)(c_str_data(s), c_str_len(s), delim, s0, s1);
}

/** Splits a string into three, at first two incidences of a delimiter
 *
 * \ingroup group__library__String
 *
 * \warning The behaviour is undefined if the string instance being split is
 *        passed as one or both recipients
 *
 * \param s The input string to be split
 * \param delim The delimiter
 * \param s0 Mutating reference to the first split
 * \param s1 Mutating reference to the second split
 * \param s2 Mutating reference to the third split
 *
 * \return The number of splits detected
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k C /* = ss_typename_type_def_k S2::value_type */
>
inline
ss_uint_t
split(
    S const&    s
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
)
{
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s0));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s1));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s2));

    return STLSOFT_WORKER_NS_QUAL_(ximpl_split_functions, split_impl_3)(c_str_data(s), c_str_len(s), delim, s0, s1, s2);
}

/** Splits a string into four, at first three incidences of a delimiter
 *
 * \ingroup group__library__String
 *
 * \warning The behaviour is undefined if the string instance being split is
 *        passed as one or both recipients
 *
 * \param s The input string to be split
 * \param delim The delimiter
 * \param s0 Mutating reference to the first split
 * \param s1 Mutating reference to the second split
 * \param s2 Mutating reference to the third split
 * \param s3 Mutating reference to the fourth split
 *
 * \return The number of splits detected
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k S3
,   ss_typename_param_k C /* = ss_typename_type_def_k S2::value_type */
>
inline
ss_uint_t
split(
    S const&    s
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
,   S3&         s3
)
{
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s0));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s1));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s2));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s3));

    return STLSOFT_WORKER_NS_QUAL_(ximpl_split_functions, split_impl_4)(c_str_data(s), c_str_len(s), delim, s0, s1, s2, s3);
}

/** Splits a string into five, at first four incidences of a delimiter
 *
 * \ingroup group__library__String
 *
 * \warning The behaviour is undefined if the string instance being split is
 *        passed as one or both recipients
 *
 * \param s The input string to be split
 * \param delim The delimiter
 * \param s0 Mutating reference to the first split
 * \param s1 Mutating reference to the second split
 * \param s2 Mutating reference to the third split
 * \param s3 Mutating reference to the fourth split
 * \param s4 Mutating reference to the fifth split
 *
 * \return The number of splits detected
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k S3
,   ss_typename_param_k S4
,   ss_typename_param_k C /* = ss_typename_type_def_k S2::value_type */
>
inline
ss_uint_t
split(
    S const&    s
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
,   S3&         s3
,   S4&         s4
)
{
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s0));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s1));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s2));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s3));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s4));

    return STLSOFT_WORKER_NS_QUAL_(ximpl_split_functions, split_impl_5)(c_str_data(s), c_str_len(s), delim, s0, s1, s2, s3, s4);
}

/** Splits a string into six, at first five incidences of a delimiter
 *
 * \ingroup group__library__String
 *
 * \warning The behaviour is undefined if the string instance being split is
 *        passed as one or both recipients
 *
 * \param s The input string to be split
 * \param delim The delimiter
 * \param s0 Mutating reference to the first split
 * \param s1 Mutating reference to the second split
 * \param s2 Mutating reference to the third split
 * \param s3 Mutating reference to the fourth split
 * \param s4 Mutating reference to the fifth split
 * \param s5 Mutating reference to the sixth split
 *
 * \return The number of splits detected
 *
| Input                | Return value  |  s0 |  s1 |  s2 |  s3 |  s4 |             s5 |
| -------------------- | ------------: | --- | --- | --- | --- | --- | -------------- |
| ""                   |             0 |  "" |  "" |  "" |  "" |  "" | ""             |
| "a"                  |             1 | "a" |  "" |  "" |  "" |  "" | ""             |
| "a,"                 |             2 | "a" |  "" |  "" |  "" |  "" | ""             |
| "a,b"                |             2 | "a" | "b" |  "" |  "" |  "" | ""             |
| "a,b,"               |             3 | "a" | "b" |  "" |  "" |  "" | ""             |
| "a,b,c"              |             3 | "a" | "b" | "c" |  "" |  "" | ""             |
| "a,b,c,"             |             4 | "a" | "b" | "c" |  "" |  "" | ""             |
| "a,b,c,d"            |             4 | "a" | "b" | "c" | "d" |  "" | ""             |
| "a,b,c,d,"           |             5 | "a" | "b" | "c" | "d" |  "" | ""             |
| "a,b,c,d,"           |             5 | "a" | "b" | "c" | "d" |  "" | ""             |
| "a,b,c,d,e"          |             5 | "a" | "b" | "c" | "d" | "e" | ""             |
| "a,b,c,d,e,"         |             6 | "a" | "b" | "c" | "d" | "e" | ""             |
| "a,b,c,d,e,f"        |             6 | "a" | "b" | "c" | "d" | "e" | "f"            |
| "a,b,c,d,e,f,"       |             6 | "a" | "b" | "c" | "d" | "e" | "f,"           |
| "a,b,c,d,e,f,,"      |             6 | "a" | "b" | "c" | "d" | "e" | "f,,"          |
| "a,b,c,d,e,f,g"      |             6 | "a" | "b" | "c" | "d" | "e" | "f,g"          |
| "a,b,c,d,e,f,g,"     |             6 | "a" | "b" | "c" | "d" | "e" | "f,g,"         |
| ","                  |             2 |  "" |  "" |  "" |  "" |  "" | ""             |
| ",,"                 |             3 |  "" |  "" |  "" |  "" |  "" | ""             |
| ",,,"                |             4 |  "" |  "" |  "" |  "" |  "" | ""             |
| ",,,,"               |             5 |  "" |  "" |  "" |  "" |  "" | ""             |
| ",,,,,"              |             6 |  "" |  "" |  "" |  "" |  "" | ""             |
| ",,,,,,"             |             6 |  "" |  "" |  "" |  "" |  "" | ","            |
| ",,,,,,,"            |             6 |  "" |  "" |  "" |  "" |  "" | ",,"           |
| ",,,,,,,,"           |             6 |  "" |  "" |  "" |  "" |  "" | ",,,"          |
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k S0
,   ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k S3
,   ss_typename_param_k S4
,   ss_typename_param_k S5
,   ss_typename_param_k C /* = ss_typename_type_def_k S2::value_type */
>
inline
ss_uint_t
split(
    S const&    s
,   C           delim
,   S0&         s0
,   S1&         s1
,   S2&         s2
,   S3&         s3
,   S4&         s4
,   S5&         s5
)
{
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s0));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s1));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s2));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s3));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s4));
    STLSOFT_MESSAGE_ASSERT("Source string specified as recipient!", static_cast<void const*>(&s) != static_cast<void const*>(&s5));

    return STLSOFT_WORKER_NS_QUAL_(ximpl_split_functions, split_impl_6)(c_str_data(s), c_str_len(s), delim, s0, s1, s2, s3, s4, s5);
}

#if STLSOFT_SPLIT_FUNCTION_OLD_FORM_N

/** Splits a string into two, at the first incidence of a delimiter
 *
 * \ingroup group__library__String
 *
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k C /* = ss_typename_type_def_k S::value_type */
>
inline
#ifndef STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
static_array_1d<S, 2>
#else /* ? STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
stlsoft_ns_qual_std_(vector)<S>
#endif /* STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
    split(S const& s, C delim)
{
#ifndef STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY
    static_array_1d<S, 2>           r;
#else /* ? STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */
    stlsoft_ns_qual_std_(vector)<S> r(2);
#endif /* STLSOFT_STRING_SPLIT_FUNCTIONS_CANNOT_USE_STATIC_ARRAY */

    STLSOFT_WORKER_NS_QUAL_(ximpl_split_functions, split_impl_2)(c_str_data(s), c_str_len(s), delim, r[0], r[1]);

    return r;
}
#else /* ? STLSOFT_SPLIT_FUNCTION_OLD_FORM_N */

template<
    ss_typename_param_k T_string_result
,   ss_typename_param_k T_input_string
,   ss_typename_param_k T_character /* = ss_typename_type_def_k S::value_type */
>
std::vector<T_string_result>
split(
    T_input_string const&   s
,   T_character             delimiter
)
{
    std::vector<T_string_result>    r;

    T_string_result s0, s1, s2, s3, s4, s5;

    ss_uint_t const n0 = split(s, delimiter, s0, s1, s2, s3, s4, s5);

    if (6 == n0)
    {
        r.resize(5);
    }
    else
    {
        r.resize(n0);
    }

    T_string_result  t;

    switch (n0)
    {
    default:

        STLSOFT_MESSAGE_ASSERT("unexpected", false);
        break;

    case 6:

        t = s5;
    case 5:

        r[4] = s4;
    case 4:

        r[3] = s3;
    case 3:

        r[2] = s2;
    case 2:

        r[1] = s1;
    case 1:

        r[0] = s0;
    case 0:

        break;
    }

    if (6 == n0)
    {
        for (;;)
        {
            ss_uint_t const n = split(t, delimiter, s0, s1, s2, s3, s4, s5);
            ss_size_t const z = r.size();

            if (0 == n)
            {
                r.resize(z + 1);

                break;
            }

            if (6 == n)
            {
                r.resize(z + 5);
            }
            else
            {
                r.resize(z+ n);
            }

            switch (n)
            {
            default:

                STLSOFT_MESSAGE_ASSERT("unexpected", false);
                break;

            case 6:

                t = s5;
            case 5:

                r[z + 4] = s4;
            case 4:

                r[z + 3] = s3;
            case 3:

                r[z + 2] = s2;
            case 2:

                r[z + 1] = s1;
            case 1:

                r[z + 0] = s0;
            case 0:

                break;
            }

            if (6 != n)
            {
                break;
            }
        }
    }

    return r;
}
#endif /* !STLSOFT_SPLIT_FUNCTION_OLD_FORM_N */

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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

