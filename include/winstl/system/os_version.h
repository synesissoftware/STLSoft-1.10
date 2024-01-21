/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/os_version.h
 *
 * Purpose:     winstl_C_identify_operating_system() function.
 *
 * Created:     18th May 1995
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1995-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/system/os_version.h
 *
 * \brief [C++] winstl_C_identify_operating_system() function
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_OS_VERSION
#define WINSTL_INCL_WINSTL_SYSTEM_H_OS_VERSION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_OS_VERSION_MAJOR    1
# define WINSTL_VER_WINSTL_SYSTEM_H_OS_VERSION_MINOR    0
# define WINSTL_VER_WINSTL_SYSTEM_H_OS_VERSION_REVISION 8
# define WINSTL_VER_WINSTL_SYSTEM_H_OS_VERSION_EDIT     15
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

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

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
 * constants
 */

#ifdef __cplusplus
namespace os_version_constants
{
#endif /* __cplusplus */

enum WinSTL_OperatingSystemIdentifier_t
{
        WinSTL_OperatingSystemIdentifier_Invalid  = -1
    ,   WinSTL_OperatingSystemIdentifier_Unknown  = 0

    ,   WinSTL_OperatingSystemIdentifier_Windows_95
    ,   WinSTL_OperatingSystemIdentifier_Windows_98
    ,   WinSTL_OperatingSystemIdentifier_Windows_ME
    ,   WinSTL_OperatingSystemIdentifier_Windows_NT4

    ,   WinSTL_OperatingSystemIdentifier_Windows_2000
    ,   WinSTL_OperatingSystemIdentifier_Windows_XP
    ,   WinSTL_OperatingSystemIdentifier_Windows_XP_Professional_x64
    ,   WinSTL_OperatingSystemIdentifier_Windows_Home_Server
    ,   WinSTL_OperatingSystemIdentifier_Windows_Server_2003
    ,   WinSTL_OperatingSystemIdentifier_Windows_Server_2003_R2
    ,   WinSTL_OperatingSystemIdentifier_Windows_Vista
    ,   WinSTL_OperatingSystemIdentifier_Windows_Server_2008
    ,   WinSTL_OperatingSystemIdentifier_Windows_Server_2008_R2
    ,   WinSTL_OperatingSystemIdentifier_Windows_7
    ,   WinSTL_OperatingSystemIdentifier_Windows_Server_2012
    ,   WinSTL_OperatingSystemIdentifier_Windows_8
    ,   WinSTL_OperatingSystemIdentifier_Windows_Server_2012_R2
    ,   WinSTL_OperatingSystemIdentifier_Windows_8_1

#if 0
    ,   WinSTL_OperatingSystemIdentifier_Windows_
    ,   WinSTL_OperatingSystemIdentifier_Windows_
    ,   WinSTL_OperatingSystemIdentifier_Windows_
    ,   WinSTL_OperatingSystemIdentifier_Windows_
    ,   WinSTL_OperatingSystemIdentifier_Windows_
    ,   WinSTL_OperatingSystemIdentifier_Windows_
    ,   WinSTL_OperatingSystemIdentifier_Windows_
    ,   WinSTL_OperatingSystemIdentifier_Windows_
#endif /* 0 */
};

#ifdef __cplusplus

} /* namespace os_version_constants */
/* typedef os_version_constants::WinSTL_OperatingSystemIdentifier_t      WinSTL_OperatingSystemIdentifier_t; */
    using namespace ::winstl::os_version_constants;
# ifndef WINSTL_NO_NAMESPACE

typedef WinSTL_OperatingSystemIdentifier_t                            OperatingSystemIdentifier_t;
# endif /* !WINSTL_NO_NAMESPACE */
#else /* ? __cplusplus */

typedef enum WinSTL_OperatingSystemIdentifier_t                       WinSTL_OperatingSystemIdentifier_t;
#endif /* __cplusplus */





STLSOFT_INLINE
WinSTL_OperatingSystemIdentifier_t
winstl_C_identify_operating_system(
    void (WINAPI *pfn)(LPSYSTEM_INFO) /* = NULL */
)
{
#if defined(__cplusplus)

# ifndef WINSTL_NO_NAMESPACE

    using namespace ::winstl::os_version_constants;
# else /* ? WINSTL_NO_NAMESPACE */

    using namespace os_version_constants;
# endif /* !WINSTL_NO_NAMESPACE */
#endif /* __cplusplus */

#ifndef VER_NT_WORKSTATION
    int const VER_NT_WORKSTATION  =   1;
#endif
#ifndef VER_NT_SERVER
    int const VER_NT_SERVER       =   2;
#endif
#ifndef PROCESSOR_ARCHITECTURE_AMD64
    int const PROCESSOR_ARCHITECTURE_AMD64 = 9;
#endif
#ifndef PROCESSOR_ARCHITECTURE_IA64
    int const PROCESSOR_ARCHITECTURE_IA64 = 6;
#endif
#ifndef SM_SERVERR2
    int const SM_SERVERR2         =   89;
#endif
#ifndef VER_SUITE_WH_SERVER
    int const VER_SUITE_WH_SERVER =   0x00008000;
#endif

    int const       smsvrr2     =   STLSOFT_NS_GLOBAL(GetSystemMetrics(SM_SERVERR2));
    SYSTEM_INFO     si          =   { 0 };
    OSVERSIONINFOEX ovix        =   { 0 };
    WORD const*     suiteMask   =   (sizeof(ovix.wReserved) == sizeof(WORD[2])) ? (WORD const*)(&ovix.wServicePackMinor + 1) : (WORD const*)(&ovix.wReserved - 3);
    BYTE const*     productType =   (sizeof(ovix.wReserved) == sizeof(WORD[2])) ? (BYTE const*)(&ovix.wServicePackMinor + 2) : (BYTE const*)(&ovix.wReserved - 1);

    if (NULL == pfn)
    {
#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0501

        STLSOFT_NS_GLOBAL(GetNativeSystemInfo)(&si);
#else /* ? XP+ */
        typedef void (WINAPI *GNSI_fn_t)(LPSYSTEM_INFO);

        HMODULE     h   =   WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryA("KERNEL32");
        GNSI_fn_t   pfn =   NULL;

        if (NULL != h)
        {
            pfn = (GNSI_fn_t)WINSTL_API_EXTERNAL_DynamicLinkLibrary_GetProcAddress(h, "GetNativeSystemInfo");

            if (NULL != pfn)
            {
                (*pfn)(&si);
            }

            WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(h);
        }

        if (NULL == pfn)
        {
            STLSOFT_NS_GLOBAL(GetSystemInfo)(&si);
        }
#endif /* XP+ */
    }
    else
    {
        (*pfn)(&si);
    }

    ovix.dwOSVersionInfoSize  = sizeof(ovix);
    if (!STLSOFT_NS_GLOBAL(GetVersionEx)((LPOSVERSIONINFO)&ovix))
    {
        return WinSTL_OperatingSystemIdentifier_Invalid;
    }
    else
    {
        switch (ovix.dwMajorVersion)
        {
            case    4:
                switch (ovix.dwPlatformId)
                {
                    case    1:
                        switch (ovix.dwMinorVersion)
                        {
                            case    0:
                                return WinSTL_OperatingSystemIdentifier_Windows_95;
                            case    10:
                                return WinSTL_OperatingSystemIdentifier_Windows_98;
                            case    90:
                                return WinSTL_OperatingSystemIdentifier_Windows_ME;
                            default:
                                return WinSTL_OperatingSystemIdentifier_Unknown;
                        }
                        break;
                    case    2:
                        switch (ovix.dwMinorVersion)
                        {
                            case    0:
                                return WinSTL_OperatingSystemIdentifier_Windows_NT4;
                            default:
                                return WinSTL_OperatingSystemIdentifier_Unknown;
                        }
                        break;
                    default:
                        return WinSTL_OperatingSystemIdentifier_Unknown;
                }
                break;
            case    5:
                switch (ovix.dwMinorVersion)
                {
                    case    0:
                        return WinSTL_OperatingSystemIdentifier_Windows_2000;
                    case    1:
                        return WinSTL_OperatingSystemIdentifier_Windows_XP;
                    case    2:
                        if (VER_NT_WORKSTATION == *productType &&
                            PROCESSOR_ARCHITECTURE_AMD64 == si.wProcessorArchitecture)
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_XP_Professional_x64;
                        }
                        else if (VER_SUITE_WH_SERVER == *suiteMask)
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_Home_Server;
                        }
                        else
                        {
                            if (0 != smsvrr2)
                            {
                                return WinSTL_OperatingSystemIdentifier_Windows_Server_2003_R2;
                            }
                            else
                            {
                                return WinSTL_OperatingSystemIdentifier_Windows_Server_2003;
                            }
                        }
                        break;
                    default:
                        return WinSTL_OperatingSystemIdentifier_Unknown;
                }
                break;
            case    6:
                switch (ovix.dwMinorVersion)
                {
                    case    0:
                        if (VER_NT_WORKSTATION == *productType)
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_Vista;
                        }
                        else
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_Server_2008;
                        }
                        break;
                    case    1:
                        if (VER_NT_WORKSTATION == *productType)
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_7;
                        }
                        else
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_Server_2008_R2;
                        }
                        break;
                    case    2:
                        if (VER_NT_WORKSTATION == *productType)
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_8;
                        }
                        else
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_Server_2012;
                        }
                        break;
                    case    3:
                        if (VER_NT_WORKSTATION == *productType)
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_8_1;
                        }
                        else
                        {
                            return WinSTL_OperatingSystemIdentifier_Windows_Server_2012_R2;
                        }
                        break;

                    default:
                        return WinSTL_OperatingSystemIdentifier_Unknown;
                }
                break;
            default:
                return WinSTL_OperatingSystemIdentifier_Unknown;
        }
    }
}



#ifdef __cplusplus

inline
WinSTL_OperatingSystemIdentifier_t
identify_operating_system(
    void (WINAPI *pfn)(LPSYSTEM_INFO) = NULL
)
{
    return winstl_C_identify_operating_system(pfn);
}
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

#if defined(__cplusplus) && \
    !defined(STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED)

inline
char const*
c_str_data_a(
    WinSTL_OperatingSystemIdentifier_t osid
)
{
#if defined(__cplusplus)

# ifndef WINSTL_NO_NAMESPACE

    using namespace ::winstl::os_version_constants;
# else /* ? WINSTL_NO_NAMESPACE */

    using namespace os_version_constants;
# endif /* !WINSTL_NO_NAMESPACE */
#endif /* __cplusplus */

# define WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(x) case  WinSTL_OperatingSystemIdentifier_##x: return #x

    switch (osid)
    {
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Unknown);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_95);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_98);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_ME);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_NT4);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_2000);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_XP);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_XP_Professional_x64);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Home_Server);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Server_2003);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Server_2003_R2);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Vista);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Server_2008);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Server_2008_R2);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_7);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Server_2012);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_8);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_Server_2012_R2);
WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_(Windows_8_1);

    case WinSTL_OperatingSystemIdentifier_Invalid:

        break;
    }

# undef WINSTL_SYSTEM_OS_VERSION_c_str_data_a_ITEM_

    return "Invalid_Operating_System_Identifier";
}

inline
ws_size_t
c_str_len_a(
    WinSTL_OperatingSystemIdentifier_t osid
)
{
    return STLSOFT_NS_GLOBAL(strlen)(c_str_data_a(osid));
}

#endif /* __cplusplus && !STLSOFT_CF_TEMPLATE_SHIMS_NOT_SUPPORTED */

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

/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
#else /* ? __cplusplus */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_OS_VERSION */

/* ///////////////////////////// end of file //////////////////////////// */

