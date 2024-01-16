/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/logical/is_null/std/auto_ptr.hpp
 *
 * Purpose:     Generic adapted case of is_null shim std::auto_ptr<>.
 *
 * Created:     31st March 2007
 * Updated:     16th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/* STLSOFT:C++17:FILE_DEPRECATED */

/** \file stlsoft/shims/logical/is_null/std/auto_ptr.hpp
 *
 * \brief [C++] Generic adapted case of is_null shim std::auto_ptr<>
 *   (\ref group__concept__Shim__Logical__is_null "is_null Logical Shim").
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR
#define STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR_MAJOR       2
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR_MINOR       0
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR_REVISION    3
# define STLSOFT_VER_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR_EDIT        20
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

#include <stlsoft/internal/std/has/auto_ptr_.hpp>

#ifndef STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_
# error std::auto_ptr not supported on this compiler
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_ */

#ifndef STLSOFT_INCL_MEMORY
# define STLSOFT_INCL_MEMORY
# include <memory>
#endif /* !STLSOFT_INCL_MEMORY */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** is_null shim
 *
 * \ingroup group__library__SmartPointer
 */
template <ss_typename_param_k T>
inline
bool
is_null(
    STLSOFT_NS_QUAL_STD(auto_ptr)<T> const& p
) STLSOFT_NOEXCEPT
{
    return NULL == p.get();
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_NULL_STD_HPP_AUTO_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

