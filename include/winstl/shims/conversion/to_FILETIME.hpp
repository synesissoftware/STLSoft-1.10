/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/conversion/to_FILETIME.hpp
 *
 * Purpose:     Includes all winstl::to_FILETIME conversion shims.
 *
 * Created:     15th December 2006
 * Updated:     26th December 2020
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


/** \file winstl/shims/conversion/to_FILETIME.hpp
 *
 * \brief [C++] Includes all winstl::to_FILETIME conversion shims
 *   (\ref group__concept__Shim__Conversion__to_FILETIME "winstl::to_FILETIME" Time Conversion Shim).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_HPP_TO_FILETIME
#define WINSTL_INCL_WINSTL_SHIMS_CONVERSION_HPP_TO_FILETIME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_HPP_TO_FILETIME_MAJOR       1
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_HPP_TO_FILETIME_MINOR       1
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_HPP_TO_FILETIME_REVISION    5
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_HPP_TO_FILETIME_EDIT        14
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_DATE
# include <winstl/shims/conversion/to_FILETIME/DATE.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_DATE */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_FILETIME
# include <winstl/shims/conversion/to_FILETIME/FILETIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_FILETIME */
#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_SYSTEMTIME
# include <winstl/shims/conversion/to_FILETIME/SYSTEMTIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_SYSTEMTIME */
#ifdef WINSTL_UDATE_DEFINED
# ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE
#  include <winstl/shims/conversion/to_FILETIME/UDATE.hpp>
# endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE */
#endif /* WINSTL_UDATE_DEFINED */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_HPP_TO_FILETIME */

/* ///////////////////////////// end of file //////////////////////////// */

