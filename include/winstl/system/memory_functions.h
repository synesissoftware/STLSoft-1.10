/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/memory_functions.h
 *
 * Purpose:     Memory functions.
 *
 * Created:     5th November 2014
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


/** \file winstl/system/memory_functions.h
 *
 * \brief [C, C++] Memory functions
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_MEMORY_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYSTEM_H_MEMORY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_MEMORY_FUNCTIONS_MAJOR      1
# define WINSTL_VER_WINSTL_SYSTEM_H_MEMORY_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_SYSTEM_H_MEMORY_FUNCTIONS_REVISION   6
# define WINSTL_VER_WINSTL_SYSTEM_H_MEMORY_FUNCTIONS_EDIT       12
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary
# include <winstl/api/external/DynamicLinkLibrary.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary */
#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

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
 * functions
 */

/**
 *
 * \retval 0xFFFFFFFFFFFFFFFF The function failed. Qualifying information is
 *   available via <code>::GetLastError()</code>
 * \return The number of bytes of physical memory available on the system.
 *
 * \note If the kernel symbol <code>GlobalMemoryStatusEx()</code> cannot be
 *   accessed, the returned value is obtained from
 *   <code>GlobalMemoryStatus</code> instead, which may truncate the actual
 *   physical memory size to its limit of 32-bits. This is detectable by use
 *   of <code>::GetLastError()</code> (which would return
 *   <code>ERROR_PROC_NOT_FOUND</code> if
 *   <code>GlobalMemoryStatusEx()</code> cannot be accessed), since
 *   <code>::GetLastError(0)</code> is invoked before attempting to load the
 *   symbol.
 */
STLSOFT_INLINE
ws_uint64_t
winstl_C_get_physical_memory_size(void)
{
#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0501

    MEMORYSTATUSEX msex;

    msex.dwLength = sizeof(msex);

    if (GlobalMemoryStatusEx(&msex))
    {
        return msex.ullTotalPhys;
    }
#else

    typedef struct MEMORYSTATUSEX_
    {
        DWORD       dwLength;
        DWORD       dwMemoryLoad;
        ws_uint64_t ullTotalPhys;
        ws_uint64_t ullAvailPhys;
        ws_uint64_t ullTotalPageFile;
        ws_uint64_t ullAvailPageFile;
        ws_uint64_t ullTotalVirtual;
        ws_uint64_t ullAvailVirtual;
        ws_uint64_t ullAvailExtendedVirtual;
    } MEMORYSTATUSEX_;

    typedef BOOL (WINAPI *GMSEx_fn_t)(MEMORYSTATUSEX_*);

    HMODULE         hModule                 =   (WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(0), WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryA("KERNEL32"));
    GMSEx_fn_t      GlobalMemoryStatusEx    =   (NULL != hModule) ? (GMSEx_fn_t)WINSTL_API_EXTERNAL_DynamicLinkLibrary_GetProcAddress(hModule, "GlobalMemoryStatusEx") : NULL;
    MEMORYSTATUSEX_ msex = { 0 };

    if (NULL != GlobalMemoryStatusEx)
    {
        msex.dwLength = sizeof(msex);

        if (!GlobalMemoryStatusEx(&msex))
        {
            GlobalMemoryStatusEx = NULL;
        }
    }

    if (NULL != hModule)
    {
        WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(hModule);
    }

    if (NULL != GlobalMemoryStatusEx)
    {
        return msex.ullTotalPhys;
    }
#endif
    else
    {
        DWORD const   e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();
        MEMORYSTATUS  ms;

        STLSOFT_NS_GLOBAL(GlobalMemoryStatus)(&ms);

        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(e);

        return ms.dwTotalPhys;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#if defined(__cplusplus)

/**
 *
 * \retval 0xFFFFFFFFFFFFFFFF The function failed. Qualifying information is
 *   available via <code>::GetLastError()</code>
 * \return The number of bytes of physical memory available on the system.
 */
inline
ws_uint64_t
get_physical_memory_size()
{
    return winstl_C_get_physical_memory_size();
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_MEMORY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

