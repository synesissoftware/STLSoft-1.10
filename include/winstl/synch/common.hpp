/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/common.hpp
 *
 * Purpose:     Common (C++) includes for Synchronisation library.
 *
 * Created:     17th December 2016
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2016-2019, Matthew Wilson and Synesis Software
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

/** \file winstl/synch/common.hpp
 *
 * \brief [C++] Common (C++) includes for Synchronisation library
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON
#define WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_COMMON_MAJOR       1
# define WINSTL_VER_WINSTL_SYNCH_HPP_COMMON_MINOR       0
# define WINSTL_VER_WINSTL_SYNCH_HPP_COMMON_REVISION    3
# define WINSTL_VER_WINSTL_SYNCH_HPP_COMMON_EDIT        7
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

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING
#  include <winstl/synch/diagnostics/failure_handling.h>
# endif /* !WINSTL_INCL_WINSTL_SYNCH_DIAGNOSTICS_H_FAILURE_HANDLING */
#endif

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS
#  include <winstl/synch/exceptions.hpp>
# endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef WINSTL_INCL_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE
# include <winstl/synch/Synchronisation_status_code.h>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Synchronization
# include <winstl/api/external/Synchronization.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Synchronization */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON */

/* ///////////////////////////// end of file //////////////////////////// */

