/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/external/FileManagement.h
 *
 * Purpose:     External preprocessor aliases for external Windows' File
 *              Management Functions API.
 *
 * Created:     20th August 2017
 * Updated:     9th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2017-2019, Matthew Wilson and Synesis Software
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_FileManagement
#define WINSTL_INCL_WINSTL_API_external_h_FileManagement

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
 * findvolume API declarations
 *
 * The FindVolume API is not visible in the Windows headers unless _WIN32_WINNT
 * is defined as 0x0500 or greater. Where this definition is not present, the
 * functions are declared here, unless _WINSTL_NO_FINDVOLUME_API is defined.
 *
 * Where _WINSTL_NO_FINDVOLUME_API is defined, the requisite members of the
 * traits classes are undeclared.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if !defined(_WINSTL_NO_FINDVOLUME_API)

#  ifndef WINSTL_WIN32_WINNT
#   error winstl_win32_winnt_.h is in error
#  endif

#  if (  0 != WINSTL_WIN32_WINNT && \
         WINSTL_WIN32_WINNT < 0x0500) || \
      !defined(FindFirstVolume) || \
      !defined(FindNextVolume)

#   define WINSTL_FINDVOLUME_API_NOT_DECLARED

HANDLE WINAPI FindFirstVolumeA(
    LPSTR lpszVolumeName,   /* output buffer */
    DWORD cchBufferLength   /* size of output buffer */
);

HANDLE WINAPI FindFirstVolumeW(
    LPWSTR lpszVolumeName,  /* output buffer */
    DWORD cchBufferLength   /* size of output buffer */
);

BOOL WINAPI FindNextVolumeA(
    HANDLE hFindVolume,     /* volume search handle */
    LPSTR lpszVolumeName,   /* output buffer */
    DWORD cchBufferLength   /* size of output buffer */
);

BOOL WINAPI FindNextVolumeW(
    HANDLE hFindVolume,     /* volume search handle */
    LPWSTR lpszVolumeName,  /* output buffer */
    DWORD cchBufferLength   /* size of output buffer */
);

BOOL WINAPI FindVolumeClose(
    HANDLE hFindVolume
);
#  endif
# endif /* !_WINSTL_NO_FINDVOLUME_API */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Windows' File Management Functions
 */

#ifndef WINSTL_API_EXTERNAL_FileManagement_CopyFileA
# define WINSTL_API_EXTERNAL_FileManagement_CopyFileA       STLSOFT_NS_GLOBAL_(CopyFileA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_CopyFileA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_CopyFileW
# define WINSTL_API_EXTERNAL_FileManagement_CopyFileW       STLSOFT_NS_GLOBAL_(CopyFileW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_CopyFileW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryA
# define WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryA                    STLSOFT_NS_GLOBAL_(CreateDirectoryA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryW
# define WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryW                    STLSOFT_NS_GLOBAL_(CreateDirectoryW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_CreateFileA
# define WINSTL_API_EXTERNAL_FileManagement_CreateFileA     STLSOFT_NS_GLOBAL_(CreateFileA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_CreateFileA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_CreateFileW
# define WINSTL_API_EXTERNAL_FileManagement_CreateFileW     STLSOFT_NS_GLOBAL_(CreateFileW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_CreateFileW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_DeleteFileA
# define WINSTL_API_EXTERNAL_FileManagement_DeleteFileA     STLSOFT_NS_GLOBAL_(DeleteFileA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_DeleteFileA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_DeleteFileW
# define WINSTL_API_EXTERNAL_FileManagement_DeleteFileW     STLSOFT_NS_GLOBAL_(DeleteFileW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_DeleteFileW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_FindClose
# define WINSTL_API_EXTERNAL_FileManagement_FindClose       STLSOFT_NS_GLOBAL_(FindClose)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindClose */

#ifndef WINSTL_API_EXTERNAL_FileManagement_FindFirstFileA
# define WINSTL_API_EXTERNAL_FileManagement_FindFirstFileA  STLSOFT_NS_GLOBAL_(FindFirstFileA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindFirstFileA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_FindFirstFileW
# define WINSTL_API_EXTERNAL_FileManagement_FindFirstFileW  STLSOFT_NS_GLOBAL_(FindFirstFileW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindFirstFileW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExA
# define WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExA                    STLSOFT_NS_GLOBAL_(FindFirstFileExA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExW
# define WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExW                    STLSOFT_NS_GLOBAL_(FindFirstFileExW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeA
# define WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeA                    STLSOFT_NS_GLOBAL_(FindFirstVolumeA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeW
# define WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeW                    STLSOFT_NS_GLOBAL_(FindFirstVolumeW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_FindNextFileA
# define WINSTL_API_EXTERNAL_FileManagement_FindNextFileA   STLSOFT_NS_GLOBAL_(FindNextFileA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindNextFileA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_FindNextFileW
# define WINSTL_API_EXTERNAL_FileManagement_FindNextFileW   STLSOFT_NS_GLOBAL_(FindNextFileW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindNextFileW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeA
# define WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeA STLSOFT_NS_GLOBAL_(FindNextVolumeA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeW
# define WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeW STLSOFT_NS_GLOBAL_(FindNextVolumeW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_FindVolumeClose
# define WINSTL_API_EXTERNAL_FileManagement_FindVolumeClose STLSOFT_NS_GLOBAL_(FindVolumeClose)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_FindVolumeClose */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA
# define WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA                STLSOFT_NS_GLOBAL_(GetCurrentDirectoryA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryW
# define WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryW                STLSOFT_NS_GLOBAL_(GetCurrentDirectoryW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeA
# define WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeA   STLSOFT_NS_GLOBAL_(GetDriveTypeA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeW
# define WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeW   STLSOFT_NS_GLOBAL_(GetDriveTypeW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA
# define WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA                  STLSOFT_NS_GLOBAL_(GetFileAttributesA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW
# define WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW                  STLSOFT_NS_GLOBAL_(GetFileAttributesW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetFileInformationByHandle
# define WINSTL_API_EXTERNAL_FileManagement_GetFileInformationByHandle          STLSOFT_NS_GLOBAL_(GetFileInformationByHandle)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetFileInformationByHandle */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetFileSize
# define WINSTL_API_EXTERNAL_FileManagement_GetFileSize     STLSOFT_NS_GLOBAL_(GetFileSize)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetFileSize */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameA
# define WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameA                    STLSOFT_NS_GLOBAL_(GetFullPathNameA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameW
# define WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameW                    STLSOFT_NS_GLOBAL_(GetFullPathNameW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetLogicalDrives
# define WINSTL_API_EXTERNAL_FileManagement_GetLogicalDrives                    STLSOFT_NS_GLOBAL_(GetLogicalDrives)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetLogicalDrives */

#ifndef WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameA
# define WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameA                   STLSOFT_NS_GLOBAL_(GetShortPathNameA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameW
# define WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameW                   STLSOFT_NS_GLOBAL_(GetShortPathNameW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_MoveFileA
# define WINSTL_API_EXTERNAL_FileManagement_MoveFileA       STLSOFT_NS_GLOBAL_(MoveFileA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_MoveFileA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_MoveFileW
# define WINSTL_API_EXTERNAL_FileManagement_MoveFileW       STLSOFT_NS_GLOBAL_(MoveFileW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_MoveFileW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryA
# define WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryA                    STLSOFT_NS_GLOBAL_(RemoveDirectoryA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryW
# define WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryW                    STLSOFT_NS_GLOBAL_(RemoveDirectoryW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryA
# define WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryA                STLSOFT_NS_GLOBAL_(SetCurrentDirectoryA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryW
# define WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryW                STLSOFT_NS_GLOBAL_(SetCurrentDirectoryW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryW */

#ifndef WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesA
# define WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesA                  STLSOFT_NS_GLOBAL_(SetFileAttributesA)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesA */
#ifndef WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesW
# define WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesW                  STLSOFT_NS_GLOBAL_(SetFileAttributesW)
#endif /* !WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesW */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_external_h_FileManagement */

/* ///////////////////////////// end of file //////////////////////////// */

