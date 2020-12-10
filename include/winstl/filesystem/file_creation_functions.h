/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/file_creation_functions.h
 *
 * Purpose:     File creation functions.
 *
 * Created:     12th September 2005
 * Updated:     3rd December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/file_creation_functions.h
 *
 * \brief [C, C++] File creation functions
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_MAJOR      3
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_MINOR      1
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_REVISION   2
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_EDIT       27
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_FileManagement
# include <winstl/api/external/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_FileManagement */
#ifndef WINSTL_INCL_WINSTL_API_internal_h_FileManagement
# include <winstl/api/internal/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_internal_h_FileManagement */

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
 * API functions
 */

/* file : create or open */

/** A short-cut for <code>CreateFileA()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be
 *   created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_create_or_open_m(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileA(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   creationDisposition
    ,   flagsAndAttributes
    ,   NULL
    );
}

/** A short-cut for <code>CreateFileW()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be
 *   created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_create_or_open_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileW(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   creationDisposition
    ,   flagsAndAttributes
    ,   NULL
    );
}


/* file : create new (or fail) */

/** Creates a new file, according to the given access, share and flags
 * parameters, specifying \c CREATE_NEW for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_create_new_m(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileA(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   CREATE_NEW
    ,   flagsAndAttributes
    ,   NULL
    );
}

/** Creates a new file, according to the given access, share and flags
 * parameters, specifying \c CREATE_NEW for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_create_new_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileW(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   CREATE_NEW
    ,   flagsAndAttributes
    ,   NULL
    );
}


/* file : create/truncate */

/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_create_always_m(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileA(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   CREATE_ALWAYS
    ,   flagsAndAttributes
    ,   NULL
    );
}

/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_create_always_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileW(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   CREATE_ALWAYS
    ,   flagsAndAttributes
    ,   NULL
    );
}


/* file : open existing (or fail) */

/** Opens an existing file, according to the given access, share and flags
 * parameters, specifying \c OPEN_EXISTING for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_open_existing_m(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileA(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   OPEN_EXISTING
    ,   flagsAndAttributes
    ,   NULL
    );
}

/** Opens an existing file, according to the given access, share and flags
 * parameters, specifying \c OPEN_EXISTING for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_open_existing_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileW(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   OPEN_EXISTING
    ,   flagsAndAttributes
    ,   NULL
    );
}


/* file : open/create */

/** Opens/creates a file, according to the given access, share and flags
 * parameters, specifying \c OPEN_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_open_always_m(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileA(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   OPEN_ALWAYS
    ,   flagsAndAttributes
    ,   NULL
    );
}

/** Opens/creates a file, according to the given access, share and flags
 * parameters, specifying \c OPEN_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_open_always_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileW(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   OPEN_ALWAYS
    ,   flagsAndAttributes
    ,   NULL
    );
}


/* file : truncate existing (or fail) */

/** Truncates an existing file, according to the given access, share and
 * flags parameters, specifying \c TRUNCATE_EXISTING for the creation
 * distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_truncate_existing_m(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileA(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   TRUNCATE_EXISTING
    ,   flagsAndAttributes
    ,   NULL
    );
}

/** Truncates an existing file, according to the given access, share and
 * flags parameters, specifying \c TRUNCATE_EXISTING for the creation
 * distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
STLSOFT_INLINE
HANDLE
winstl_C_file_truncate_existing_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return WINSTL_API_INTERNAL_FileManagement_CreateFileW(
        path
    ,   desiredAccess
    ,   shareMode
    ,   NULL
    ,   TRUNCATE_EXISTING
    ,   flagsAndAttributes
    ,   NULL
    );
}


#ifdef __cplusplus

/** A short-cut for <code>CreateFileA()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be
 *   created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_create_or_open(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_or_open_m(
        path
    ,   desiredAccess
    ,   shareMode
    ,   creationDisposition
    ,   flagsAndAttributes
    );
}

/** A short-cut for <code>CreateFileA()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be
 *   created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_create_or_open(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_or_open_w(
        path
    ,   desiredAccess
    ,   shareMode
    ,   creationDisposition
    ,   flagsAndAttributes
    );
}

/* file : create new (or fail) */

/** Creates a new file, according to the given access, share and flags
 * parameters, specifying \c CREATE_NEW for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_create_new(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_new_m(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Creates a new file, according to the given access, share and flags
 * parameters, specifying \c CREATE_NEW for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_create_new(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_new_w(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/* file : create/truncate */

/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_create_always(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_always_m(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_create_always(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_always_w(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/* file : open existing (or fail) */

/** Opens an existing file, according to the given access, share and flags
 * parameters, specifying \c OPEN_EXISTING for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_open_existing(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_existing_m(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Opens an existing file, according to the given access, share and flags
 * parameters, specifying \c OPEN_EXISTING for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_open_existing(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_existing_w(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/* file : open/create */

/** Opens/creates a file, according to the given access, share and flags
 * parameters, specifying \c OPEN_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_open_always(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_always_m(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Opens/creates a file, according to the given access, share and flags
 * parameters, specifying \c OPEN_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_open_always(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_always_w(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/* file : truncate existing (or fail) */

/** Truncates an existing file, according to the given access, share and
 * flags parameters, specifying \c TRUNCATE_EXISTING for the creation
 * distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_truncate_existing(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_truncate_existing_m(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Truncates an existing file, according to the given access, share and
 * flags parameters, specifying \c TRUNCATE_EXISTING for the creation
 * distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
winstl_C_file_truncate_existing(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_truncate_existing_w(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}
#else /* ? __cplusplus */

# ifdef UNICODE

#  define winstl_C_file_create_or_open                      winstl_C_file_create_or_open_w
#  define winstl_C_file_create_new                          winstl_C_file_create_new_w
#  define winstl_C_file_create_always                       winstl_C_file_create_always_w
#  define winstl_C_file_open_existing                       winstl_C_file_open_existing_w
#  define winstl_C_file_open_always                         winstl_C_file_open_always_w
#  define winstl_C_file_truncate_existing                   winstl_C_file_truncate_existing_w
# else /* ? UNICODE */

#  define winstl_C_file_create_or_open                      winstl_C_file_create_or_open_m
#  define winstl_C_file_create_new                          winstl_C_file_create_new_m
#  define winstl_C_file_create_always                       winstl_C_file_create_always_m
#  define winstl_C_file_open_existing                       winstl_C_file_open_existing_m
#  define winstl_C_file_open_always                         winstl_C_file_open_always_m
#  define winstl_C_file_truncate_existing                   winstl_C_file_truncate_existing_m
# endif /* UNICODE */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ API functions
 */

#ifdef __cplusplus

/** A short-cut for <code>CreateFileA()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be
 *   created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_create_or_open(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_or_open(
        path
    ,   desiredAccess
    ,   shareMode
    ,   creationDisposition
    ,   flagsAndAttributes
    );
}

/** A short-cut for <code>CreateFileA()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be
 *   created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_create_or_open(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_or_open(
        path
    ,   desiredAccess
    ,   shareMode
    ,   creationDisposition
    ,   flagsAndAttributes
    );
}


/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_NEW for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_create_new(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_new(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_NEW for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_create_new(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_new(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_create_always(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_always(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Creates/truncates a file, according to the given access, share and flags
 * parameters, specifying \c CREATE_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_create_always(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_create_always(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/** Opens an existing file, according to the given access, share and flags
 * parameters, specifying \c OPEN_EXISTING for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_open_existing(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_existing(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Opens an existing file, according to the given access, share and flags
 * parameters, specifying \c OPEN_EXISTING for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_open_existing(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_existing(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/** Opens/creates a file, according to the given access, share and flags
 * parameters, specifying \c OPEN_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_open_always(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_always(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Opens/creates a file, according to the given access, share and flags
 * parameters, specifying \c OPEN_ALWAYS for the creation distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_open_always(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_open_always(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}


/* file : truncate existing (or fail) */

/** Truncates an existing file, according to the given access, share and
 * flags parameters, specifying \c TRUNCATE_EXISTING for the creation
 * distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_truncate_existing(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_truncate_existing(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
}

/** Truncates an existing file, according to the given access, share and
 * flags parameters, specifying \c TRUNCATE_EXISTING for the creation
 * distribution
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation
 *   and/or the file.
 */
inline
HANDLE
file_truncate_existing(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes      =   0
) STLSOFT_NOEXCEPT
{
    return winstl_C_file_truncate_existing(
        path
    ,   desiredAccess
    ,   shareMode
    ,   flagsAndAttributes
    );
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

#endif /* !WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

