/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/security/functions.h
 *
 * Purpose:     Security functions.
 *
 * Created:     7th November 2014
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2014-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/security/functions.h
 *
 * \brief [C, C++] Security functions
 *   (\ref group__library__security "Security" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_H_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_H_FUNCTIONS_REVISION    4
# define WINSTL_VER_WINSTL_H_FUNCTIONS_EDIT        6
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */


#ifndef WINSTL_INCL_WINSTL_API_external_h_Authorization
# include <winstl/api/external/Authorization.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Authorization */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
void*
winstl_C_Security_alloc_(
    ws_size_t   cb
)
{
    return STLSOFT_C_CAST(SECURITY_DESCRIPTOR*, STLSOFT_NS_GLOBAL(HeapAlloc)(STLSOFT_NS_GLOBAL(GetProcessHeap)(), 0, cb));
}

STLSOFT_INLINE
void
winstl_C_Security_free_(
    void*       pv
)
{
    STLSOFT_NS_GLOBAL(HeapFree)(STLSOFT_NS_GLOBAL(GetProcessHeap)(), 0, pv);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

STLSOFT_INLINE
void
winstl_C_Security_free_string_m(
    ws_char_a_t*    s
)
{
    winstl_C_Security_free_(s);
}

STLSOFT_INLINE
BOOL
winstl_C_Security_lookup_account_SID_info_m(
    ws_char_a_t const*  systemName
,   PSID                psid
,   ws_char_a_t**       pAccountName
,   ws_size_t*          pcchAccountName
,   ws_char_a_t**       pDomainName
,   ws_size_t*          pcchDomainName
,   SID_NAME_USE*       pNameUse
)
{
    DWORD           accountNameLen  =   0;
    DWORD           domainNameLen   =   0;
    SID_NAME_USE    nameUseDummy_;
    ws_char_a_t*    account;
    ws_char_a_t*    domain;

    if (NULL == pNameUse)
    {
        pNameUse = &nameUseDummy_;
    }

    WINSTL_API_EXTERNAL_Authorization_LookupAccountSid(
        systemName
    ,   psid
    ,   NULL
    ,   &accountNameLen
    ,   NULL
    ,   &domainNameLen
    ,   pNameUse
    );

    switch (STLSOFT_NS_GLOBAL(GetLastError)())
    {
        default:
            return FALSE;
        case    ERROR_INSUFFICIENT_BUFFER:
            break;
    }

    if (NULL == (account = STLSOFT_STATIC_CAST(ws_char_a_t*, winstl_C_Security_alloc_(sizeof(ws_char_a_t) * accountNameLen))))
    {
        return FALSE;
    }

    if (NULL == (domain = STLSOFT_STATIC_CAST(ws_char_a_t*, winstl_C_Security_alloc_(sizeof(ws_char_a_t) * domainNameLen))))
    {
        winstl_C_Security_free_(account);

        return FALSE;
    }

    if (!WINSTL_API_EXTERNAL_Authorization_LookupAccountSid(
            systemName
        ,   psid
        ,   &account[0]
        ,   &accountNameLen
        ,   &domain[0]
        ,   &domainNameLen
        ,   pNameUse
        )
    )
    {
        winstl_C_Security_free_(account);
        winstl_C_Security_free_(domain);

        return FALSE;
    }

    if (NULL != pAccountName)
    {
        *pAccountName   =   account;
        account         =   NULL;
    }

    if (NULL != pcchAccountName)
    {
        *pcchAccountName    =   accountNameLen;
    }

    if (NULL != pDomainName)
    {
        *pDomainName    =   domain;
        domain          =   NULL;
    }

    if (NULL != pcchDomainName)
    {
        *pcchDomainName =   domainNameLen;
    }

    winstl_C_Security_free_(account);
    winstl_C_Security_free_(domain);

    return TRUE;
}


STLSOFT_INLINE
BOOL
winstl_C_Security_lookup_account_SID_info_w(
    ws_char_w_t const*  systemName
,   PSID                psid
,   ws_char_w_t**       pAccountName
,   ws_size_t*          pcchAccountName
,   ws_char_w_t**       pDomainName
,   ws_size_t*          pcchDomainName
,   SID_NAME_USE*       pNameUse
)
;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifndef WINSTL_NO_NAMESPACE
namespace security
{

inline
void
free_string(
    ws_char_a_t*    s
)
{
    winstl_C_Security_free_string_m(s);
}

inline
BOOL
lookup_account_SID_info(
    ws_char_a_t const*  systemName
,   PSID                psid
,   ws_char_a_t**       pAccountName
,   ws_size_t*          pcchAccountName
,   ws_char_a_t**       pDomainName
,   ws_size_t*          pcchDomainName
,   SID_NAME_USE*       pNameUse
)
{
    return winstl_C_Security_lookup_account_SID_info_m(
        systemName
    ,   psid
    ,   pAccountName
    ,   pcchAccountName
    ,   pDomainName
    ,   pcchDomainName
    ,   pNameUse
    );
}

} /* namespace security */
#endif /* !WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* WINSTL_INCL_WINSTL_H_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

