/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/thread_marshal.hpp
 *
 * Purpose:     Thread marshalling functions.
 *
 * Created:     25th May 2002
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file comstl/util/thread_marshal.hpp
 *
 * \brief [C++; requires COM] Thread marshalling functions
 *   (\ref group__library__COM_Utility "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_HPP_THREAD_MARSHAL
#define COMSTL_INCL_COMSTL_UTIL_HPP_THREAD_MARSHAL

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_HPP_THREAD_MARSHAL_MAJOR    4
# define COMSTL_VER_COMSTL_UTIL_HPP_THREAD_MARSHAL_MINOR    0
# define COMSTL_VER_COMSTL_UTIL_HPP_THREAD_MARSHAL_REVISION 7
# define COMSTL_VER_COMSTL_UTIL_HPP_THREAD_MARSHAL_EDIT     69
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef COMSTL_INCL_COMSTL_UTIL_HPP_INTERFACE_TRAITS
# include <comstl/util/interface_traits.hpp>
#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_INTERFACE_TRAITS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Marshal a interface to a stream
 *
 * \ingroup group__library__COM_Utility
 *
 * This function marshals the given interface into a new stream instance, which
 * is returned to the caller. The stream may then be passed directly to another
 * thread in the process, from which GetInterfaceAndReleaseStream() may be
 * called.
 *
 * \param pitf The interface pointer to marshal
 * \param ppstm A pointer to an IStream pointer to receive the stream
 * \return An HRESULT indicating success or failure
 * \retval E_OUTOFMEMORY Sufficient memory could not be acquired
 * \retval S_OK The operation completed successfully
 */
template <ss_typename_param_k I>
inline HRESULT MarshalInterThreadInterfaceInStream(I *pitf, LPSTREAM *ppstm)
{
    return ::CoMarshalInterThreadInterfaceInStream(IID_traits<I>().iid(), pitf, ppstm);
}

/** Retrieve a marshaled interface pointer from a stream
 *
 * \ingroup group__library__COM_Utility
 *
 * This function loads a serialised marshalled interface pointer from the given
 * stream, queries for the interface of the given pointer, and returns the
 * pointer if successful, and an error code if not. The stream is always
 * released, irrespective of the success status of the function as a whole.
 *
 * \param pstm An IStream pointer from which object is to be unmarshaled
 * \param ppitf A pointer to the interface pointer to be unmarshaled
 * \return An HRESULT indicating success or failure
 * \retval E_INVALIDARG The argument was invalid
 * \retval S_OK The operation completed successfully
 */

template <ss_typename_param_k I>
inline HRESULT GetInterfaceAndReleaseStream(LPSTREAM pstm, I **ppitf)
{
    return ::CoGetInterfaceAndReleaseStream(pstm, IID_traits<I>().iid(), reinterpret_cast<void**>(ppitf));
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_UTIL_HPP_THREAD_MARSHAL */

/* ///////////////////////////// end of file //////////////////////////// */

