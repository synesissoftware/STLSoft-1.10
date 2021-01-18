/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/resizeable_buffer_helpers.hpp
 *
 * Purpose:     Utility functions for working with resizeable-buffers.
 *
 * Created:     24th December 2020
 * Updated:     16th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020-2021, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/util/resizeable_buffer_helpers.hpp
 *
 * \brief [C++] Utility functions for working with resizeable-buffers
 *   templates
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS_MAJOR       1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS_MINOR       0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS_REVISION    3
# define STLSOFT_VER_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS_EDIT        4
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

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_SIZE_OF
# include <stlsoft/meta/size_of.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SIZE_OF */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_OPEN_WORKER_NS_(ximpl_stlsoft_util_rb_helpers_)

#if 0
#elif defined(STLSOFT_COMPILER_IS_MSVC) && \
      _MSC_VER < 1310

 /* Have to muck around with state here to get the old girl to work */

template<
    ss_typename_param_k T_rb
>
struct rb_helper_traits_vc6
{
private:
    T_rb* prb;

public:
    ss_explicit_k
    rb_helper_traits_vc6(
        T_rb& rb
    )
        : prb(&rb)
    {}

    bool
    do_resize(
        size_t              newSize
    ,   bool (T_rb::*pfn)(size_t)
    )
    {
        return (prb->*pfn)(newSize);
    }

    bool
    do_resize(
        size_t              newSize
    ,   void (T_rb::*pfn)(size_t)
    )
    {
        (prb->*pfn)(newSize);

        return true;
    }
};

template<
    ss_typename_param_k T
>
inline
rb_helper_traits_vc6<T>
traits_for(
    T& rb
)
{
    return rb_helper_traits_vc6<T>(rb);
}
#else

template<
    ss_typename_param_k T_resizeableBuffer
,   ss_typename_param_k T_character
>
struct rb_helper_traits
{
    typedef T_character                                     char_type;
    typedef T_resizeableBuffer                              buffer_type;

    typedef bool                             (buffer_type::*pfn_b)(size_t);
    typedef void                             (buffer_type::*pfn_v)(size_t);

    static
    bool
    do_resize(
        buffer_type&    buffer
    ,   size_t          newSize
    ,   pfn_b           pfn
    )
    {
        return (buffer.*pfn)(newSize);
    }

    static
    bool
    do_resize(
        buffer_type&    buffer
    ,   size_t          newSize
    ,   pfn_v           pfn
    )
    {
        (buffer.*pfn)(newSize);

        return true;
    }
};
#endif
STLSOFT_CLOSE_WORKER_NS_(ximpl_stlsoft_util_rb_helpers_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Invokes <code>resize()</code> on the given buffer, regardless of
 *  whether the buffer's type's method returns \c bool or \c void
 *
 * \param rb Reference to the resizeable buffer instance
 * \param newSize The new size
 */
template<
    ss_typename_param_k T_resizeableBuffer
>
bool
resizeable_buffer_resize(
    T_resizeableBuffer& rb
,   ss_size_t           newSize
)
{
#if 0
#elif defined(STLSOFT_COMPILER_IS_MSVC) && \
      _MSC_VER < 1310

    STLSOFT_WORKER_NS_USING_(ximpl_stlsoft_util_rb_helpers_, traits_for);

    return traits_for(rb).do_resize(newSize, &T_resizeableBuffer::resize);
#else
    typedef T_resizeableBuffer                              buffer_t;
    typedef ss_typename_type_k buffer_t::value_type         value_t;

    STLSOFT_WORKER_NS_USING_(ximpl_stlsoft_util_rb_helpers_, rb_helper_traits);

    typedef rb_helper_traits<
        buffer_t
    ,   value_t
    >                                                       traits_t;

    return traits_t::do_resize(rb, newSize, &T_resizeableBuffer::resize);
#endif
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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS */

/* ///////////////////////////// end of file //////////////////////////// */

