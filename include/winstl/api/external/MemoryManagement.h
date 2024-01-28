/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/external/MemoryManagement.h
 *
 * Purpose:     External preprocessor aliases for external Windows' Memory
 *              Management Functions API.
 *
 * Created:     18th July 2014
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef WINSTL_INCL_WINSTL_API_external_h_MemoryManagement
#define WINSTL_INCL_WINSTL_API_external_h_MemoryManagement

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

/* /////////////////////////////////////////////////////////////////////////
 * Windows' Memory Management Functions
 */


/* *************************************
 * General Memory functions
 */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_CopyMemory
# define WINSTL_API_EXTERNAL_MemoryManagement_CopyMemory    STLSOFT_NS_GLOBAL_(CopyMemory)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_CopyMemory */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_FillMemory
# define WINSTL_API_EXTERNAL_MemoryManagement_FillMemory    STLSOFT_NS_GLOBAL_(FillMemory)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_FillMemory */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GetWriteWatch
# define WINSTL_API_EXTERNAL_MemoryManagement_GetWriteWatch STLSOFT_NS_GLOBAL_(GetWriteWatch)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GetWriteWatch */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalMemoryStatus
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalMemoryStatus                STLSOFT_NS_GLOBAL_(GlobalMemoryStatus)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalMemoryStatus */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalMemoryStatusEx
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalMemoryStatusEx              STLSOFT_NS_GLOBAL_(GlobalMemoryStatusEx)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalMemoryStatusEx */

/* IsBad???Ptr never used! */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_MoveMemory
# define WINSTL_API_EXTERNAL_MemoryManagement_MoveMemory    STLSOFT_NS_GLOBAL_(MoveMemory)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_MoveMemory */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_ResetWriteWatch
# define WINSTL_API_EXTERNAL_MemoryManagement_ResetWriteWatch                   STLSOFT_NS_GLOBAL_(ResetWriteWatch)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_ResetWriteWatch */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_ZeroMemory
# define WINSTL_API_EXTERNAL_MemoryManagement_ZeroMemory    STLSOFT_NS_GLOBAL_(ZeroMemory)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_ZeroMemory */


/* *************************************
 * Data Execution Prevention functions
 */


/* *************************************
 * File Mapping functions
 */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingA
# define WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingA                STLSOFT_NS_GLOBAL_(CreateFileMappingA)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingA */
#ifndef WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingW
# define WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingW                STLSOFT_NS_GLOBAL_(CreateFileMappingW)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingW */

#if _WIN32_WINNT >= 0x0602
#ifndef WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingFromAppA
# define WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingFromAppA         STLSOFT_NS_GLOBAL_(CreateFileMappingFromAppA)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingFromAppA */
#ifndef WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingFromAppW
# define WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingFromAppW         STLSOFT_NS_GLOBAL_(CreateFileMappingFromAppW)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingFromAppW */
#endif /* !_WIN32_WINNT */

#if _WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingNumaA
#  define WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingNumaA           STLSOFT_NS_GLOBAL_(CreateFileMappingNumaA)
# endif /* !WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingNumaA */
# ifndef WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingNumaW
#  define WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingNumaW           STLSOFT_NS_GLOBAL_(CreateFileMappingNumaW)
# endif /* !WINSTL_API_EXTERNAL_MemoryManagement_CreateFileMappingNumaW */
#endif /* !_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_FlushViewOfFile
# define WINSTL_API_EXTERNAL_MemoryManagement_FlushViewOfFile                   STLSOFT_NS_GLOBAL_(FlushViewOfFile)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_FlushViewOfFile */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GetMappedFileNameA
# define WINSTL_API_EXTERNAL_MemoryManagement_GetMappedFileNameA                STLSOFT_NS_GLOBAL_(GetMappedFileNameA)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GetMappedFileNameA */
#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GetMappedFileNameW
# define WINSTL_API_EXTERNAL_MemoryManagement_GetMappedFileNameW                STLSOFT_NS_GLOBAL_(GetMappedFileNameW)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GetMappedFileNameW */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFile
# define WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFile STLSOFT_NS_GLOBAL_(MapViewOfFile)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFile */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileEx
# define WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileEx                   STLSOFT_NS_GLOBAL_(MapViewOfFileEx)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileEx */

#if _WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileExNuma
#  define WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileExNuma              STLSOFT_NS_GLOBAL_(MapViewOfFileExNuma)
# endif /* !WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileExNuma */
#endif /* !_WIN32_WINNT */

#if _WIN32_WINNT >= 0x0602
# ifndef WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileFromApp
#  define WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileFromApp             STLSOFT_NS_GLOBAL_(MapViewOfFileFromApp)
# endif /* !WINSTL_API_EXTERNAL_MemoryManagement_MapViewOfFileFromApp */
#endif /* !_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_OpenFileMappingA
# define WINSTL_API_EXTERNAL_MemoryManagement_OpenFileMappingA                  STLSOFT_NS_GLOBAL_(OpenFileMappingA)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_OpenFileMappingA */
#ifndef WINSTL_API_EXTERNAL_MemoryManagement_OpenFileMappingW
# define WINSTL_API_EXTERNAL_MemoryManagement_OpenFileMappingW                  STLSOFT_NS_GLOBAL_(OpenFileMappingW)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_OpenFileMappingW */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_UnmapViewOfFile
# define WINSTL_API_EXTERNAL_MemoryManagement_UnmapViewOfFile                   STLSOFT_NS_GLOBAL_(UnmapViewOfFile)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_UnmapViewOfFile */

/* *************************************
 * AWE functions
 */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_AllocateUserPhysicalPages
# define WINSTL_API_EXTERNAL_MemoryManagement_AllocateUserPhysicalPages         STLSOFT_NS_GLOBAL_(AllocateUserPhysicalPages)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_AllocateUserPhysicalPages */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_FreeUserPhysicalPages
# define WINSTL_API_EXTERNAL_MemoryManagement_FreeUserPhysicalPages             STLSOFT_NS_GLOBAL_(FreeUserPhysicalPages)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_FreeUserPhysicalPages */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_MapUserPhysicalPages
# define WINSTL_API_EXTERNAL_MemoryManagement_MapUserPhysicalPages              STLSOFT_NS_GLOBAL_(MapUserPhysicalPages)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_MapUserPhysicalPages */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_MapUserPhysicalPagesScatter
# define WINSTL_API_EXTERNAL_MemoryManagement_MapUserPhysicalPagesScatter       STLSOFT_NS_GLOBAL_(MapUserPhysicalPagesScatter)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_MapUserPhysicalPagesScatter  */


/* *************************************
 * Heap functions
 */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GetProcessHeap
# define WINSTL_API_EXTERNAL_MemoryManagement_GetProcessHeap                    STLSOFT_NS_GLOBAL_(GetProcessHeap)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GetProcessHeap */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GetProcessHeaps
# define WINSTL_API_EXTERNAL_MemoryManagement_GetProcessHeaps                   STLSOFT_NS_GLOBAL_(GetProcessHeaps)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GetProcessHeaps */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapAlloc
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapAlloc     STLSOFT_NS_GLOBAL_(HeapAlloc)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapAlloc */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapCompact
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapCompact   STLSOFT_NS_GLOBAL_(HeapCompact)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapCompact */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapCreate
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapCreate    STLSOFT_NS_GLOBAL_(HeapCreate)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapCreate */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapDestroy
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapDestroy   STLSOFT_NS_GLOBAL_(HeapDestroy)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapDestroy */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapFree
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapFree      STLSOFT_NS_GLOBAL_(HeapFree)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapFree */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapLock
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapLock      STLSOFT_NS_GLOBAL_(HeapLock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapLock */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapQueryInformation
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapQueryInformation              STLSOFT_NS_GLOBAL_(HeapQueryInformation)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapQueryInformation */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapReAlloc
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapReAlloc   STLSOFT_NS_GLOBAL_(HeapReAlloc)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapReAlloc */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapSetInformation
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapSetInformation                STLSOFT_NS_GLOBAL_(HeapSetInformation)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapSetInformation */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapSize
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapSize      STLSOFT_NS_GLOBAL_(HeapSize)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapSize */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapUnlock
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapUnlock    STLSOFT_NS_GLOBAL_(HeapUnlock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapUnlock */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapValidate
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapValidate  STLSOFT_NS_GLOBAL_(HeapValidate)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapValidate */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_HeapWalk
# define WINSTL_API_EXTERNAL_MemoryManagement_HeapWalk      STLSOFT_NS_GLOBAL_(HeapWalk)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_HeapWalk */


/* *************************************
 * Virtual Memory functions
 */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualAlloc
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualAlloc  STLSOFT_NS_GLOBAL_(VirtualAlloc)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualAlloc */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualAllocEx
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualAllocEx                    STLSOFT_NS_GLOBAL_(VirtualAllocEx)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualAllocEx */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualFree
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualFree   STLSOFT_NS_GLOBAL_(VirtualFree)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualFree */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualFreeEx
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualFreeEx STLSOFT_NS_GLOBAL_(VirtualFreeEx)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualFreeEx */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualLock
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualLock   STLSOFT_NS_GLOBAL_(VirtualLock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualLock */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualProtect
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualProtect                    STLSOFT_NS_GLOBAL_(VirtualProtect)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualProtect */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualProtectEx
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualProtectEx                  STLSOFT_NS_GLOBAL_(VirtualProtectEx)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualProtectEx */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualQuery
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualQuery  STLSOFT_NS_GLOBAL_(VirtualQuery)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualQuery */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualQueryEx
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualQueryEx                    STLSOFT_NS_GLOBAL_(VirtualQueryEx)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualQueryEx */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_VirtualUnlock
# define WINSTL_API_EXTERNAL_MemoryManagement_VirtualUnlock STLSOFT_NS_GLOBAL_(VirtualUnlock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_VirtualUnlock */


/* *************************************
 * Global and Local functions
 */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalAlloc
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalAlloc   STLSOFT_NS_GLOBAL_(GlobalAlloc)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalAlloc */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalDiscard
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalDiscard STLSOFT_NS_GLOBAL_(GlobalDiscard)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalDiscard */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalFlags
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalFlags   STLSOFT_NS_GLOBAL_(GlobalFlags)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalFlags */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalFree
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalFree    STLSOFT_NS_GLOBAL_(GlobalFree)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalFree */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalHandle
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalHandle  STLSOFT_NS_GLOBAL_(GlobalHandle)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalHandle */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalLock
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalLock    STLSOFT_NS_GLOBAL_(GlobalLock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalLock */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalReAlloc
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalReAlloc STLSOFT_NS_GLOBAL_(GlobalReAlloc)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalReAlloc */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalSize
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalSize    STLSOFT_NS_GLOBAL_(GlobalSize)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalSize */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_GlobalUnlock
# define WINSTL_API_EXTERNAL_MemoryManagement_GlobalUnlock  STLSOFT_NS_GLOBAL_(GlobalUnlock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_GlobalUnlock */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalAlloc
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalAlloc    STLSOFT_NS_GLOBAL_(LocalAlloc)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalAlloc */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalDiscard
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalDiscard  STLSOFT_NS_GLOBAL_(LocalDiscard)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalDiscard */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalFlags
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalFlags    STLSOFT_NS_GLOBAL_(LocalFlags)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalFlags */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalFree
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalFree     STLSOFT_NS_GLOBAL_(LocalFree)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalFree */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalHandle
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalHandle   STLSOFT_NS_GLOBAL_(LocalHandle)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalHandle */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalLock
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalLock     STLSOFT_NS_GLOBAL_(LocalLock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalLock */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalReAlloc
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalReAlloc  STLSOFT_NS_GLOBAL_(LocalReAlloc)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalReAlloc */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalSize
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalSize     STLSOFT_NS_GLOBAL_(LocalSize)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalSize */

#ifndef WINSTL_API_EXTERNAL_MemoryManagement_LocalUnlock
# define WINSTL_API_EXTERNAL_MemoryManagement_LocalUnlock   STLSOFT_NS_GLOBAL_(LocalUnlock)
#endif /* !WINSTL_API_EXTERNAL_MemoryManagement_LocalUnlock */


/* *************************************
 * Bad Memory functions
 */


/* *************************************
 * Enclave functions
 */


/* *************************************
 * Obsolete functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_external_h_MemoryManagement */

/* ///////////////////////////// end of file //////////////////////////// */

