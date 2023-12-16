/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/conversion/to_uint64/degenerate.hpp
 *
 * Purpose:     Contains the to_uint64 access shim.
 *
 * Created:     4th July 2007
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


/** \file stlsoft/shims/conversion/to_uint64/degenerate.hpp
 *
 * \brief [C++] Degenerate case for the
 *   \ref group__concept__Shim__Conversion__to_uint64 "to_uint64 Integer Attribute Shim".
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE
#define STLSOFT_INCL_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE_MAJOR    1
# define STLSOFT_VER_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE_MINOR    0
# define STLSOFT_VER_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE_REVISION 5
# define STLSOFT_VER_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE_EDIT     11
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
 * to_uint64 functions
 */

/* VC++ 6 mixes this with specific shim function overloads. */
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1310

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
struct to_uint64_shim_does_not_provide_a_degenerate_case
{};
# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** The degenerate case, which proscribes the use of the shim with
 *    arbitrary types; only those types with specific shim functions.
 * \ingroup group__concept__Shim__Conversion__to_uint64
 */
template <ss_typename_param_k T>
inline to_uint64_shim_does_not_provide_a_degenerate_case to_uint64(T const&)
{
    return to_uint64_shim_does_not_provide_a_degenerate_case();
}

#endif /* compiler */

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

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_CONVERSION_TO_UINT64_HPP_DEGENERATE */

/* ///////////////////////////// end of file //////////////////////////// */

