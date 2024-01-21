/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/algorithms/debug.hpp
 *
 * Purpose:     Debug algorithms.
 *
 * Created:     17th January 2002
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/algorithms/debug.hpp
 *
 * \brief [C++] Debug algorithms
 *   (\ref group__library__Algorithm "Algorithm" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_DEBUG
#define STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_DEBUG

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_DEBUG_MAJOR     3
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_DEBUG_MINOR     1
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_DEBUG_REVISION  5
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_DEBUG_EDIT      82
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
 * algorithms
 */

template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
// [[synesis:function:algorithm: copy_preinc(T<I> first, T<I> last, T<O> o)]]
inline O copy_preinc(
    I   first
,   I   last
,   O   o
)
{
    for (; first != last; ++o, ++first)
    {
        *o = *first;
    }

    return o;
}

// [[synesis:function:algorithm: copy_postinc(T<I> first, T<I> last, T<O> o)]]
template<   ss_typename_param_k I
        ,   ss_typename_param_k O
        >
inline O copy_postinc(
    I   first
,   I   last
,   O   o
)
{
    for (; first != last; o++, first++)
    {
        *o = *first;
    }

    return o;
}



/** Carries out for_each on the range, using pre-increment on the iterator
 *
 * \ingroup group__library__Algorithm
 *
 * \param first The start of the sequence
 * \param last The end of the sequence
 * \param func The function
 */
// [[synesis:function:algorithm: for_each_preinc(T<I> first, T<I> last, T<UF> func)]]
template<   ss_typename_param_k I
        ,   ss_typename_param_k UF
        >
inline UF for_each_preinc(I first, I last, UF func)
{
    for (; first != last; ++first)
    {
        func(*first);
    }

    return func;
}

/** Carries out for_each on the range, using post-increment on the iterator
 *
 * \ingroup group__library__Algorithm
 *
 * \param first The start of the sequence
 * \param last The end of the sequence
 * \param func The function
 */
// [[synesis:function:algorithm: for_each_postinc(T<I> first, T<I> last, T<UF> func)]]
template<   ss_typename_param_k I
        ,   ss_typename_param_k UF
        >
inline UF for_each_postinc(I first, I last, UF func)
{
    for (; first != last; first++)
    {
        func(*first);
    }

    return func;
}

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

#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_DEBUG */

/* ///////////////////////////// end of file //////////////////////////// */

