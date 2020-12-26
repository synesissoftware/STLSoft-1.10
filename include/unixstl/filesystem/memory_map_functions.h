/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/memory_map_functions.h (based on MMFile.h, ::SynesisWin)
 *
 * Purpose:     UNIX memory mapping functions.
 *
 * Created:     15th December 1996
 * Updated:     24th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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

/** \file unixstl/filesystem/memory_map_functions.h
 *
 * \brief [C, C++] Memory-mapping functions.
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_MAJOR    3
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_MINOR    1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_REVISION 2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_EDIT     106
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_SYS_H_MMAN
# define STLSOFT_INCL_SYS_H_MMAN
# include <sys/mman.h>
#endif /* !STLSOFT_INCL_SYS_H_MMAN */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(UNIXSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions (C)
 */

STLSOFT_INLINE
void
unixstl_C_unmap_view_of_file(
    void*       view
,   us_size_t   length
)
{
    if (NULL != view)
    {
        STLSOFT_NS_GLOBAL(munmap)(view, length);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * functions (C++)
 */

#ifndef UNIXSTL_NO_NAMESPACE

inline
void
unmap_view_of_file(
    void*       view
,   us_size_t   length
)
{
    unixstl_C_unmap_view_of_file(view, length);
}

#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

