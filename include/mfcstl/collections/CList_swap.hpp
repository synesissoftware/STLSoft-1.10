/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/collections/CList_swap.hpp
 *
 * Purpose:     Contains the CList_swap utility function.
 *
 * Created:     15th September 2006
 * Updated:     28th November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file mfcstl/collections/CList_swap.hpp
 *
 * \brief [C++] Definition of the mfcstl::CList_swap utility function
 *   (\ref group__library__Collection "Collection" Library).
 */

#ifndef MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_LIST_SWAP
#define MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_LIST_SWAP

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_LIST_SWAP_MAJOR      1
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_LIST_SWAP_MINOR      0
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_LIST_SWAP_REVISION   6
# define MFCSTL_VER_MFCSTL_COLLECTIONS_HPP_LIST_SWAP_EDIT       22
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

/* /////////////////////////////////////////////////////////////////////////
 * version compatibility
 */

// All version of MFC up to and including 8.0 support swap-by-members
#if _MFC_VER <= 0x0800 && \
    !defined(MFCSTL_CLIST_SWAP_MEMBERS_SUPPORT)
# define MFCSTL_CLIST_SWAP_MEMBERS_SUPPORT
#endif /* _MFC_VER <= 0x0800 && !MFCSTL_CLIST_SWAP_MEMBERS_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */
namespace stlsoft
{
namespace mfcstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#ifdef MFCSTL_CLIST_SWAP_MEMBERS_SUPPORT

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
namespace list_impl
{
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */

/** Helper class that facilitates safe swapping of the state of CList<>
 * instances
 */
template <class A>
class CList_swap_veneer
    : public A
{
/// \name Member Types
/// @{
public:
    typedef CList_swap_veneer<A>   class_type;
/// @}

/// \name Operations
/// @{
public:
    static void swap(class_type& lhs, class_type& rhs)
    {
        std_swap(lhs.m_pNodeHead, rhs.m_pNodeHead);
        std_swap(lhs.m_pNodeTail, rhs.m_pNodeTail);
        std_swap(lhs.m_nCount, rhs.m_nCount);
        std_swap(lhs.m_pNodeFree, rhs.m_pNodeFree);
        std_swap(lhs.m_pBlocks, rhs.m_pBlocks);
        std_swap(lhs.m_nBlockSize, rhs.m_nBlockSize);
    }
/// @}
};

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
} /* namespace list_impl */
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */

/** Swaps the contents of two instances of CList-family
 *    containers.
 *
 * \ingroup group__library__Collection
 */
template <class A>
void CList_swap(A& lhs, A& rhs)
{
#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
    using list_impl::CList_swap_veneer;
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */

    typedef CList_swap_veneer<A>   swapper_t;

    swapper_t::swap(static_cast<swapper_t&>(lhs), static_cast<swapper_t&>(rhs));
}

#endif /* MFCSTL_CLIST_SWAP_MEMBERS_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace mfcstl */
# else
} /* namespace mfcstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !MFCSTL_INCL_MFCSTL_COLLECTIONS_HPP_LIST_SWAP */

/* ///////////////////////////// end of file //////////////////////////// */

