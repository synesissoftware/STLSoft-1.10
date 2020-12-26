/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/pair.hpp (originally MTPair.h, ::SynesisStl)
 *
 * Purpose:     Contains the pair template.
 *
 * Created:     19th November 1998
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/pair.hpp
 *
 * \brief [C++] Definition of the stlsoft::pair class template
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_PAIR
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_PAIR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PAIR_MAJOR     5
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PAIR_MINOR     0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PAIR_REVISION  7
# define STLSOFT_VER_STLSOFT_UTIL_HPP_PAIR_EDIT      66
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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Represents a pair
 *
 * \ingroup group__library__Utility
 *
 * \param T1 The type of the \c first member
 * \param T2 The type of the \c second member
 */
template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
struct pair
{
public:
    /// The first type
    typedef T1      first_type;
    /// The second type
    typedef T2      second_type;

/// \name Construction
/// @{
public:
    /// Default constructor
    pair()
        : first(first_type())
        , second(second_type())
    {}
    /// Converstion constructor
    pair(first_type const& v1, second_type const& v2)
        : first(v1)
        , second(v2)
    {}
/// @}

/// \name Members
/// @{
public:
    first_type  first;  //!< The first member
    second_type second; //!< The second member
/// @}
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<ss_typename_param_k T1, ss_typename_param_k T2>
inline ss_bool_t operator ==(pair<T1, T2> const& x, pair<T1, T2> const& y)
{
    return x.first == y.first && x.second == y.second;
}

template<ss_typename_param_k T1, ss_typename_param_k T2>
inline ss_bool_t operator !=(pair<T1, T2> const& x, pair<T1, T2> const& y)
{
    return !(x == y);
}

template<ss_typename_param_k T1, ss_typename_param_k T2>
inline ss_bool_t operator <(pair<T1, T2> const& x, pair<T1, T2> const& y)
{
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template<ss_typename_param_k T1, ss_typename_param_k T2>
inline ss_bool_t operator >(pair<T1, T2> const& x, pair<T1, T2> const& y)
{
    return y < x;
}

template<ss_typename_param_k T1, ss_typename_param_k T2>
inline ss_bool_t operator <=(pair<T1, T2> const& x, pair<T1, T2> const& y)
{
    return !(y < x);
}

template<ss_typename_param_k T1, ss_typename_param_k T2>
inline ss_bool_t operator >=(pair<T1, T2> const& x, pair<T1, T2> const& y)
{
    return !(x < y);
}

template<ss_typename_param_k T1, ss_typename_param_k T2>
inline pair<T1, T2> make_pair(T1 const& x, T2 const& y)
{
    return pair<T1, T2>(x, y);
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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_PAIR */

/* ///////////////////////////// end of file //////////////////////////// */

