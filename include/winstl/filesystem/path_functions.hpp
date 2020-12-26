/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path_functions.hpp
 *
 * Purpose:     Helper functions for file handling
 *
 * Created:     6th June 2006
 * Updated:     24th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/path_functions.hpp
 *
 * \brief [C++] Helper functions for path handling
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_MAJOR      2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_MINOR      1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_REVISION   1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS_EDIT       31
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

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS
# include <winstl/filesystem/path_classify_functions.h>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS
# include <winstl/filesystem/path_parse_functions.h>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS
# include <winstl/filesystem/squeeze_functions.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_SQUEEZE_FUNCTIONS */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

