/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/security/security_initialisers.hpp (originally MOSecFns.h, ::SynesisCom)
 *
 * Purpose:     Contains classes for initialising COM/OLE.
 *
 * Created:     1st February 1998
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/security/security_initialisers.hpp
 *
 * \brief [C++] Functions for initialising COM security
 *   (\ref group__library__Security "Security" Library).
 */

#ifndef COMSTL_INCL_COMSTL_SECURITY_HPP_SECURITY_INITIALISERS
#define COMSTL_INCL_COMSTL_SECURITY_HPP_SECURITY_INITIALISERS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_SECURITY_HPP_SECURITY_INITIALISERS_MAJOR      4
# define COMSTL_VER_COMSTL_SECURITY_HPP_SECURITY_INITIALISERS_MINOR      1
# define COMSTL_VER_COMSTL_SECURITY_HPP_SECURITY_INITIALISERS_REVISION   7
# define COMSTL_VER_COMSTL_SECURITY_HPP_SECURITY_INITIALISERS_EDIT       60
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

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_UNION_CAST
# include <stlsoft/conversion/union_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_UNION_CAST */

#if (   !defined(_WIN32_WINNT) || \
        (_WIN32_WINNT < 0x0400)) && \
    !defined(_WIN32_DCOM)
# error This file can only be used in the context of DCOM compilations.
#endif /* _WIN32_WINNT < 0x0400 && !_WIN32_DCOM */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1200
# include <iaccess.h>
#endif /* compiler */

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
 * Constants & definitions.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
const DWORD _EOAC_SEC_DESC          =   0x0;
const DWORD _EOAC_ACCESS_CONTROL    =   0x4;
const DWORD _EOAC_APPID             =   0x8;
const DWORD _EOAC_SECURITY_MASK     =   (   _EOAC_SEC_DESC |
                                            _EOAC_APPID |
                                            _EOAC_ACCESS_CONTROL);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

// function CoInitSecurity
//
// The three overloaded CoInitSecurity functions
// provide a type-safe interface to the CoInitializeSecurity
// API, discriminating between IAccessControl, AppID, and
// SECURITY_DESCRIPTOR security information parameters.

/** Initialises the COM security libraries with an IAccessControl instance
 *
 * \ingroup group__library__Security
 *
 */
#ifdef __IAccessControl_INTERFACE_DEFINED__
inline HRESULT CoInitSecurity(  LPUNKNOWN                   punkAccessControl,
                                LONG                        cAuthSvc,
                                SOLE_AUTHENTICATION_SERVICE *asAuthSvc,
                                DWORD                       dwAuthnLevel,
                                DWORD                       dwImpLevel,
                                RPC_AUTH_IDENTITY_HANDLE    pAuthInfo,
                                DWORD                       dwCapabilities)
{
    // Use a "fake" IID constant, to avoid linker errors with compilers with old UUID.lib
    static const CLSID  IID_IAccessControl__ = { 0xEEDD23E0, 0x8410, 0x11CE, { 0xA1, 0xC3, 0x08, 0x00, 0x2B, 0x2B, 0x8D, 0x8F } };

    HRESULT         hr;
    IAccessControl  *pac;

    /* Ensure correct flag. */
    dwCapabilities &= ~_EOAC_SECURITY_MASK;
    dwCapabilities |= _EOAC_ACCESS_CONTROL;

    hr = punkAccessControl->QueryInterface(IID_IAccessControl__, (void**)&pac);

    if (SUCCEEDED(hr))
    {
        hr = ::CoInitializeSecurity(pac, cAuthSvc, asAuthSvc, NULL, dwAuthnLevel, dwImpLevel, pAuthInfo, dwCapabilities, NULL);

        pac->Release();
    }

    return hr;
}
#endif // __IAccessControl_INTERFACE_DEFINED__

/** Initialises the COM security libraries with an APPID
 *
 * \ingroup group__library__Security
 *
 */
inline HRESULT CoInitSecurity(  GUID const                  &appid,
                                LONG                        cAuthSvc,
                                SOLE_AUTHENTICATION_SERVICE *asAuthSvc,
                                DWORD                       dwAuthnLevel,
                                DWORD                       dwImpLevel,
                                RPC_AUTH_IDENTITY_HANDLE    pAuthInfo,
                                DWORD                       dwCapabilities)
{
    /* Ensure correct flag. */
    dwCapabilities &= ~_EOAC_SECURITY_MASK;
    dwCapabilities |= _EOAC_APPID;

    // Since some compilers define CIS to take SECURITY_DESCRIPTOR*, we need to
    // do better than just cast the address of appid to void*

    return ::CoInitializeSecurity(STLSOFT_NS_QUAL(union_cast)<SECURITY_DESCRIPTOR*>(&appid), cAuthSvc, asAuthSvc, NULL, dwAuthnLevel, dwImpLevel, pAuthInfo, dwCapabilities, NULL);
}

/** Initialises the COM security libraries with a security descriptor
 *
 * \ingroup group__library__Security
 *
 */
inline HRESULT CoInitSecurity(  SECURITY_DESCRIPTOR         *psd,
                                LONG                        cAuthSvc,
                                SOLE_AUTHENTICATION_SERVICE *asAuthSvc,
                                DWORD                       dwAuthnLevel,
                                DWORD                       dwImpLevel,
                                RPC_AUTH_IDENTITY_HANDLE    pAuthInfo,
                                DWORD                       dwCapabilities)
{
    /* Ensure correct flag. */
    dwCapabilities &= ~_EOAC_SECURITY_MASK;
    dwCapabilities |= _EOAC_SEC_DESC;

    return ::CoInitializeSecurity(psd, cAuthSvc, asAuthSvc, NULL, dwAuthnLevel, dwImpLevel, pAuthInfo, dwCapabilities, NULL);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace stlsoft::comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_SECURITY_HPP_SECURITY_INITIALISERS */

/* ///////////////////////////// end of file //////////////////////////// */

