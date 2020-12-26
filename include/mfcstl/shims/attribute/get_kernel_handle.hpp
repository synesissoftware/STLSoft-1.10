/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/shims/attribute/get_kernel_handle.hpp
 *
 * Purpose:     Contains classes and functions for dealing with Win32 handles.
 *
 * Created:     24th December 2006
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


/** \file mfcstl/shims/attribute/get_kernel_handle.hpp
 *
 * \brief [C++] Definition of stlsoft::get_kernel_handle attribute shim
 *   functions for MFC synchronisation types
 *   (\ref group__library__Shims_Attribute_Windows_KernelHandle "Kernel Handle Attribute Shims").
 */

#ifndef MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE
#define MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE_MAJOR      1
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE_MINOR      1
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE_REVISION   7
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE_EDIT       23
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

#ifndef WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE
# include <winstl/shims/attribute/get_kernel_handle.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE */

#ifndef STLSOFT_INCL_H_AFXMT
# define STLSOFT_INCL_H_AFXMT
# include <afxmt.h>
#endif /* !STLSOFT_INCL_H_AFXMT */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Overload of the WinSTL get_kernel_handle() shim for MFC's
 *    CEvent.
 *
 * \ingroup group__library__Shims_Attribute_SynchHandle
 *
 * \param ev The event instance
 *
 * \retval The handle \c h
 *
 * \remarks We cannot simply define the shim overload in terms of
 *    <code>CEvent</code> for two reasons. First, the template
 *    mechanism requires a precise shim when the
 *
 */
inline HANDLE get_kernel_handle(CEvent &ev)
{
    return static_cast<HANDLE>(ev);
}

/** Overload of the WinSTL get_kernel_handle() shim for MFC's
 *    CMutex.
 *
 * \ingroup group__library__Shims_Attribute_SynchHandle
 *
 * \param mx The mutex instance
 *
 * \retval The handle \c h
 *
 * \remarks We cannot simply define the shim overload in terms of
 *    <code>CMutex</code> for two reasons. First, the template
 *    mechanism requires a precise shim when the
 *
 */
inline HANDLE get_kernel_handle(CMutex &mx)
{
    return static_cast<HANDLE>(mx);
}

/** Overload of the WinSTL get_kernel_handle() shim for MFC's
 *    CSemaphore.
 *
 * \ingroup group__library__Shims_Attribute_SynchHandle
 *
 * \param sem The semaphore instance
 *
 * \retval The handle \c h
 *
 * \remarks We cannot simply define the shim overload in terms of
 *    <code>CSemaphore</code> for two reasons. First, the template
 *    mechanism requires a precise shim when the
 *
 */
inline HANDLE get_kernel_handle(CSemaphore &sem)
{
    return static_cast<HANDLE>(sem);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace stlsoft::winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_KERNEL_HANDLE */

/* ///////////////////////////// end of file //////////////////////////// */

