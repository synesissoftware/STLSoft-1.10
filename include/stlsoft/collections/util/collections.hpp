/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/collections/util/collections.hpp
 *
 * Purpose:     Collection types.
 *
 * Created:     10th January 2006
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/collections/util/collections.hpp
 *
 * \brief [C++] Definition of collection tag types
 *   (\ref group__library__Collection "Collection" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
#define STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS_MAJOR     2
# define STLSOFT_VER_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS_MINOR     0
# define STLSOFT_VER_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS_REVISION  6
# define STLSOFT_VER_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS_EDIT      22
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

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup collections Collections
 * STL-extension collections
 *
 * \ingroup group__library__Collection
 */

/** \weakgroup pod_collections POD Collections
 * Collections for manipulating POD types
 * \ingroup collections
 * @{
 */

/* /////////////////////////////////////////////////////////////////////////
 * collections
 */

/** Rootmost tag for a collection
 *
 * \ingroup group__library__Collection
 */
struct collection_tag
{};

/** Indentifies a collection as being an STL collection: it has begin() and end()
 *
 * \ingroup group__library__Collection
 */
struct stl_collection_tag
    : public collection_tag
{};

#if 0
template<   ss_typename_param_k V
        ,   int                 R
        ,   int                 W
        ,   int                 C
        >
struct collection
    : public collection_tag
{
public:
    enum { is_read          =   R   };
    enum { is_write         =   W   };
    enum { is_contiguous    =   C   };

    typedef V               value_type;
};
#endif /* 0 */

////////////////////////////////////////////////////////////////////////////

/** @} // end of group pod_collections
 *
 * \ingroup group__library__Collection
 */

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

#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

