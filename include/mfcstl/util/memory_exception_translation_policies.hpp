/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/util/memory_exception_translation_policies.hpp
 *
 * Purpose:     .
 *
 * Created:     2nd February 2006
 * Updated:     26th December 2020
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


/** \file mfcstl/util/memory_exception_translation_policies.hpp
 *
 * \brief [C++] Definition of the mfcstl::bad_alloc_throwing_policy
 *   and mfcstl::CMemoryException_throwing_policy exception translation
 *   policy classes
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef MFCSTL_INCL_MFCSTL_UTIL_HPP_MEMORY_EXCEPTION_TRANSLATION_POLICIES
#define MFCSTL_INCL_MFCSTL_UTIL_HPP_MEMORY_EXCEPTION_TRANSLATION_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_UTIL_HPP_MEMORY_EXCEPTION_TRANSLATION_POLICIES_MAJOR     1
# define MFCSTL_VER_MFCSTL_UTIL_HPP_MEMORY_EXCEPTION_TRANSLATION_POLICIES_MINOR     0
# define MFCSTL_VER_MFCSTL_UTIL_HPP_MEMORY_EXCEPTION_TRANSLATION_POLICIES_REVISION  9
# define MFCSTL_VER_MFCSTL_UTIL_HPP_MEMORY_EXCEPTION_TRANSLATION_POLICIES_EDIT      24
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

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION
# include <stlsoft/exception/out_of_memory_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION */

#ifndef STLSOFT_INCL_NEW
# define STLSOFT_INCL_NEW
# include <new>  // for std::bad_alloc
#endif /* !STLSOFT_INCL_NEW */

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

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Memory exception translation policy that ensures CMemoryException* is the thrown type in all cases
 *
 * \ingroup group__library__Utility
 */
struct CMemoryException_throwing_policy
{
public:
    /// <i>Translates</i> a CMemoryException* into a CMemoryException*, by simply rethrowing via a <code>throw;</code> statement
    static void handle(CMemoryException *)
    {
        throw;
    }
    /// Translates a std::bad_alloc& into a CMemoryException*
    static void handle(STLSOFT_NS_QUAL_STD(bad_alloc) &)
    {
        AfxThrowMemoryException();
    }
};

/** Memory exception translation policy that ensures std::bad_alloc is the thrown type in all cases
 *
 * \ingroup group__library__Utility
 */
struct bad_alloc_throwing_policy
{
public:
    /// Translates a CMemoryException* into a std::bad_alloc&
    static void handle(CMemoryException *)
    {
        STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_MFCSTL, STLSoftLibraryIdentifier_Unspecified));
    }
    /// <i>Translates</i> a std::bad_alloc& into a std::bad_alloc&, by simply rethrowing via a <code>throw;</code> statement
    static void handle(STLSOFT_NS_QUAL_STD(bad_alloc) &)
    {
        throw;
    }
};

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !MFCSTL_INCL_MFCSTL_UTIL_HPP_MEMORY_EXCEPTION_TRANSLATION_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

