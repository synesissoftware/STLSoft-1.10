/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/obsolete/container_base.hpp
 *
 * Purpose:     Allocator commmon features.
 *
 * Created:     17th February 2004
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/// \file stlsoft/obsolete/container_base.hpp
///
/// Allocator commmon features.

#ifndef STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_CONTAINER_BASE
#define STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_CONTAINER_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_CONTAINER_BASE_MAJOR      2
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_CONTAINER_BASE_MINOR      2
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_CONTAINER_BASE_REVISION   4
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_CONTAINER_BASE_EDIT       28
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

/** Base template for STL allocators
 *
 * \ingroup group__library__Memory
 *
 * \obsolete
 */
template <ss_typename_param_k A>
struct container_base
#ifndef STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE
    : public A
#endif /* STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
{
    typedef A                   allocator_type;
    typedef container_base<A>   class_type;

protected:
    container_base()
    {}
    container_base(class_type const&)
    {}

    operator allocator_type &()
    {
        return get_allocator_();
    }
    operator allocator_type const& () const
    {
        return get_allocator_();
    }

private:
#ifndef STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE
    allocator_type &get_allocator_()
    {
        return *this;
    }
    allocator_type const& get_allocator_() const
    {
        return *this;
    }
#else /* ? STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
    static allocator_type &get_allocator_()
    {
        static allocator_type   s_allocator;

        return s_allocator;
    }
#endif /* STLSOFT_CF_ALLOCATOR_BASE_EXPENSIVE */
};

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

#endif /* !STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_CONTAINER_BASE */

/* ///////////////////////////// end of file //////////////////////////// */

