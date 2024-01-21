/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/resource/resource_functions.h (originally in STLSoft+)
 *
 * Purpose:     Message functions.
 *
 * Created:     9th March 2010
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/** \file winstl/resource/resource_functions.h
 *
 * \brief [C, C++] Message functions
 *   (\ref group__library__Windows_Resource "Windows Resource" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_RESOURCE_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_RESOURCE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_RESOURCE_FUNCTIONS_MAJOR    1
# define WINSTL_VER_WINSTL_WINDOW_H_RESOURCE_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_H_RESOURCE_FUNCTIONS_REVISION 5
# define WINSTL_VER_WINSTL_WINDOW_H_RESOURCE_FUNCTIONS_EDIT     22
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
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
LPVOID
winstl_C_Resource_loadLockAndSizeResource_(
    HMODULE     hModule
,   HRSRC       hrsrc
,   LPDWORD     pcbResource
)
{
    if (NULL == pcbResource)
    {
        DWORD   dummy;

        return winstl_C_Resource_loadLockAndSizeResource_(hModule, hrsrc, &dummy);
    }

    *pcbResource = 0;

    if (NULL != hrsrc)
    {
        HGLOBAL const hglbl = STLSOFT_NS_GLOBAL(LoadResource)(hModule, hrsrc);

        if (NULL != hglbl)
        {
            *pcbResource = STLSOFT_NS_GLOBAL(SizeofResource)(hModule, hrsrc);

            return STLSOFT_NS_GLOBAL(LockResource)(hglbl);
        }
    }

    return NULL;
}


#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** Finds, loads, locks and returns the resource matching the given type and
 * name from the given module
 *
 * \pre NULL != hModule
 * \pre NULL != resourceName
 * \pre NULL != resourceType
 *
 * \ingroup group__library__Windows_Resource
 */
STLSOFT_INLINE
LPVOID
winstl_C_Resource_loadCustomResource_A(
    HMODULE     hModule
,   LPCSTR      resourceName
,   LPCSTR      resourceType
,   LPDWORD     pcbResource
)
{
    WINSTL_MESSAGE_ASSERT("module handle may not be null", NULL != hModule);
    WINSTL_MESSAGE_ASSERT("resource name may not be null", NULL != resourceName);
    WINSTL_MESSAGE_ASSERT("resource type may not be null", NULL != resourceType);

    return winstl_C_Resource_loadLockAndSizeResource_(
        hModule
    ,   STLSOFT_NS_GLOBAL(FindResourceA)(hModule, resourceName, resourceType)
    ,   pcbResource
    );
}

STLSOFT_INLINE
LPVOID
winstl_C_Resource_loadCustomResource_W(
    HMODULE     hModule
,   LPCWSTR     resourceName
,   LPCWSTR     resourceType
,   LPDWORD     pcbResource
)
{
    WINSTL_MESSAGE_ASSERT("module handle may not be null", NULL != hModule);
    WINSTL_MESSAGE_ASSERT("resource name may not be null", NULL != resourceName);
    WINSTL_MESSAGE_ASSERT("resource type may not be null", NULL != resourceType);

    return winstl_C_Resource_loadLockAndSizeResource_(
        hModule
    ,   STLSOFT_NS_GLOBAL(FindResourceW)(hModule, resourceName, resourceType)
    ,   pcbResource
    );
}

# ifdef UNICODE
#  define winstl_C_Resource_loadCustomResource              winstl_C_Resource_loadCustomResource_W
# else /* ? UNICODE */
#  define winstl_C_Resource_loadCustomResource              winstl_C_Resource_loadCustomResource_A
# endif /* UNICODE */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

inline
LPVOID
load_custom_resource(
    HMODULE     hModule
,   LPCSTR      resourceName
,   LPCSTR      resourceType
,   LPDWORD     pcbResource =   NULL
)
{
    return winstl_C_Resource_loadCustomResource_A(hModule, resourceName, resourceType, pcbResource);
}

inline
LPVOID
load_custom_resource(
    HMODULE     hModule
,   LPCWSTR     resourceName
,   LPCWSTR     resourceType
,   LPDWORD     pcbResource =   NULL
)
{
    return winstl_C_Resource_loadCustomResource_W(hModule, resourceName, resourceType, pcbResource);
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_RESOURCE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

