/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/memory_map_sparse_region_functions.h
 *
 * Purpose:     Windows memory mapping functions.
 *
 * Created:     15th December 1996
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1996-2019, Matthew Wilson and Synesis Software
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

/** \file winstl/filesystem/memory_map_functions.h
 *
 * \brief [C, C++] Memory-mapping functions.
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_SPARSE_REGION_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_SPARSE_REGION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_SPARSE_REGION_FUNCTIONS_MAJOR    5
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_SPARSE_REGION_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_SPARSE_REGION_FUNCTIONS_REVISION 5
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_SPARSE_REGION_FUNCTIONS_EDIT     120
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

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef WINSTL_INCL_WINSTL_API_internal_h_MemoryManagement
# include <winstl/api/internal/MemoryManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_internal_h_MemoryManagement */

#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
# include <winstl/api/external/HandleAndObject.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */
#ifndef WINSTL_INCL_WINSTL_API_external_h_MemoryManagement
# include <winstl/api/external/MemoryManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_MemoryManagement */

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
 * types
 */

/** Describes a sparse region
 */
struct winstl_C_SparseRegion_t
{
    HANDLE      hFileMap;
    LPVOID      view;
    ws_uint64_t size;
};

#if 0
#elif !defined(WINSTL_NO_NAMESPACE)

typedef winstl_C_SparseRegion_t                             SparseRegion_t;
#elif !defined(__cplusplus)

typedef struct winstl_C_SparseRegion_t                      winstl_C_SparseRegion_t;
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
winstl_C_SparseRegion_t
winstl_C_sparse_region_map_view_or_close_mapping_(
    HANDLE          hFileMap
,   ws_uint64_t     requestSize
)
{
    winstl_C_SparseRegion_t sr = { 0 };

    STLSOFT_SUPPRESS_UNUSED(requestSize);   /* Can pass 0 to MVOF */

    sr.size = requestSize;

    if (NULL != hFileMap)
    {
        void* const view = WINSTL_API_INTERNAL_MemoryManagement_MapViewOfFile(hFileMap, FILE_MAP_WRITE, 0, 0);

        if (NULL == view)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(hFileMap);
        }
        else
        {
            sr.hFileMap =   hFileMap;
            sr.view     =   view;
        }
    }

    return sr;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions (C)
 */

STLSOFT_INLINE
winstl_C_SparseRegion_t
winstl_C_created_named_sparse_shared_region_on_pagefile_a(
    ws_uint64_t         requestSize
,   ws_char_a_t const*  name
)
{
    HANDLE hFileMap =
    WINSTL_API_INTERNAL_MemoryManagement_CreateFileMappingA(
        INVALID_HANDLE_VALUE
    ,   NULL
    ,   PAGE_READWRITE | SEC_RESERVE
    ,   requestSize
    ,   name
    );

    return winstl_C_sparse_region_map_view_or_close_mapping_(hFileMap, requestSize);
}

STLSOFT_INLINE
winstl_C_SparseRegion_t
winstl_C_created_named_sparse_shared_region_on_pagefile_w(
    ws_uint64_t         requestSize
,   ws_char_w_t const*  name
)
{
    HANDLE hFileMap =
    WINSTL_API_INTERNAL_MemoryManagement_CreateFileMappingW(
        INVALID_HANDLE_VALUE
    ,   NULL
    ,   PAGE_READWRITE | SEC_RESERVE
    ,   requestSize
    ,   name
    );

    return winstl_C_sparse_region_map_view_or_close_mapping_(hFileMap, requestSize);
}

#ifdef __cplusplus

inline
winstl_C_SparseRegion_t
winstl_C_created_named_sparse_shared_region_on_pagefile(
    ws_uint64_t         requestSize
,   ws_char_a_t const*  name
) STLSOFT_NOEXCEPT
{
    return winstl_C_created_named_sparse_shared_region_on_pagefile_a(requestSize, name);
}

inline
winstl_C_SparseRegion_t
winstl_C_created_named_sparse_shared_region_on_pagefile(
    ws_uint64_t         requestSize
,   ws_char_w_t const*  name
) STLSOFT_NOEXCEPT
{
    return winstl_C_created_named_sparse_shared_region_on_pagefile_w(requestSize, name);
}

#else /* ? __cplusplus */

# ifdef UNICODE

#  define winstl_C_created_named_sparse_shared_region_on_pagefile   winstl_C_created_named_sparse_shared_region_on_pagefile_w

# else /* ? UNICODE */

#  define winstl_C_created_named_sparse_shared_region_on_pagefile   winstl_C_created_named_sparse_shared_region_on_pagefile_a

# endif /* UNICODE */

#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * functions (C++)
 */

#ifndef WINSTL_NO_NAMESPACE

inline
SparseRegion_t
create_named_sparse_shared_region_on_pagefile(
    ws_uint64_t         requestSize
,   ws_char_a_t const*  name
)
{
    return winstl_C_created_named_sparse_shared_region_on_pagefile_a(requestSize, name);
}

inline
SparseRegion_t
create_named_sparse_shared_region_on_pagefile(
    ws_uint64_t         requestSize
,   ws_char_w_t const*  name
)
{
    return winstl_C_created_named_sparse_shared_region_on_pagefile_w(requestSize, name);
}

#endif /* !WINSTL_NO_NAMESPACE */

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_SPARSE_REGION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

