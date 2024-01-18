/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/algorithms/collection.hpp
 *
 * Purpose:     Whole collection algorithms.
 *
 * Created:     17th January 2002
 * Updated:     17th January 2024
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


/** \file stlsoft/algorithms/collection.hpp
 *
 * \brief [C++] Whole collection algorithms
 *   (\ref group__library__Algorithm "Algorithm" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_COLLECTION
#define STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_COLLECTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_COLLECTION_MAJOR    3
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_COLLECTION_MINOR    1
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_COLLECTION_REVISION 6
# define STLSOFT_VER_STLSOFT_ALGORITHMS_HPP_COLLECTION_EDIT     83
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

#ifndef STLSOFT_INCL_STLSOFT_ALGORITHM_STD_HPP_ALT
# include <stlsoft/algorithms/std/alt.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHM_STD_HPP_ALT */

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

/** Invokes std::for_each() on the range of items in a container
 *
 * \ingroup group__library__Algorithm
 *
 * \param container The container instance
 * \param value The value that to assign to each element in the container
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k V
        >
// [[synesis:function:algorithm: fill_all(T<C> &container, T<T> const& value)]]
inline void fill_all(C &container, V const& value)
{
    fill(container.begin(), container.end(), value);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
/** Invokes std::for_each() on the range of items in an array
 *
 * \ingroup group__library__Algorithm
 *
 * \param ar The array
 * \param value The value to set to each element in the array
 */
// [[synesis:function:algorithm: fill_all(T-A<T, V_dimension> ar, T<T> const& value)]]
template<
    ss_typename_param_k T
,   ss_size_t           V_dimension
,   ss_typename_param_k V
>
inline void fill_all(T (&ar)[V_dimension], V const& value)
{
    fill(&ar[0], &ar[V_dimension], value);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */



/** Invokes std::for_each() on the range of items in a container
 *
 * \ingroup group__library__Algorithm
 *
 * \param container The container instance
 * \param func The function to be applied to each element in the container
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k UF
        >
// [[synesis:function:algorithm: for_all(T<C> &container, T<UF> func)]]
inline UF for_all(C &container, UF func)
{
    return std_for_each(container.begin(), container.end(), func);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
/** Invokes std::for_each() on the range of items in an array
 *
 * \ingroup group__library__Algorithm
 *
 * \param ar The array
 * \param func The function to be applied to each element in the array
 */
// [[synesis:function:algorithm: for_all(T-A<T, V_dimension> ar, T<UF> func)]]
template<
    ss_typename_param_k T
,   ss_size_t           V_dimension
,   ss_typename_param_k UF
>
inline UF for_all(T (&ar)[V_dimension], UF func)
{
    return std_for_each(&ar[0], &ar[V_dimension], func);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */



/** Invokes std::for_each() on the reverse range of items in a container
 *
 * \ingroup group__library__Algorithm
 *
 * \param container The container instance
 * \param func The function to be applied to each element in the container
 */
// [[synesis:function:algorithm: for_all_r(T<C> &container, T<UF> func)]]
template<   ss_typename_param_k C
        ,   ss_typename_param_k UF
        >
inline UF for_all_r(C &container, UF func)
{
    return std_for_each(container.rbegin(), container.rend(), func);
}



/** Invokes std::copy() on all the items in a container
 *
 * \ingroup group__library__Algorithm
 *
 * \param container The container instance
 * \param dest The output iterator to which each element will be copied
 */
// [[synesis:function:algorithm: copy_all(T<C> &container, T<O> dest)]]
template<   ss_typename_param_k C
        ,   ss_typename_param_k O
        >
inline O copy_all(C &container, O dest)
{
    return std_copy(container.begin(), container.end(), dest);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
/** Invokes std::copy() on the range of items in an array
 *
 * \ingroup group__library__Algorithm
 *
 * \param ar The array
 * \param dest The output iterator to which each element will be copied
 */
template<
    ss_typename_param_k T
,   ss_size_t           V_dimension
,   ss_typename_param_k O
>
// [[synesis:function:algorithm: copy_all(T-A<T, V_dimension> ar, T<O> dest)]]
inline O copy_all(T (&ar)[V_dimension], O dest)
{
    return std_copy(&ar[0], &ar[V_dimension], dest);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

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

#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHMS_HPP_COLLECTION */

/* ///////////////////////////// end of file //////////////////////////// */

