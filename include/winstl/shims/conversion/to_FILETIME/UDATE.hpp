/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/conversion/to_FILETIME/UDATE.hpp
 *
 * Purpose:     winstl::to_FILETIME(UDATE const&) overload.
 *
 * Created:     15th January 2007
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/shims/conversion/to_FILETIME/UDATE.hpp
 *
 * \brief [C++] Definition of the winstl::to_FILETIME(UDATE const&)
 *   overload
 *   (\ref group__concept__Shim__Conversion__to_FILETIME "winstl::to_FILETIME" Time Conversion Shim).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE
#define WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE_MAJOR     1
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE_MINOR     0
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE_REVISION  7
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE_EDIT      16
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

#ifndef WINSTL_UDATE_DEFINED
# error UDATE is not defined. If you are certain that the Windows header files of your compiler define this type, #define the symbol WINSTL_FORCE_UDATE
#endif /* !WINSTL_UDATE_DEFINED */
#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_SYSTEMTIME
# include <winstl/shims/conversion/to_FILETIME/SYSTEMTIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_SYSTEMTIME */
#ifdef WINSTL_UDATE_DEFINED
# include <objbase.h>
# include <oleauto.h>
#endif /* WINSTL_UDATE_DEFINED */

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
 * functions
 */

/** Converts an instance of UDATE to an instance of FILETIME.
 *
 * \ingroup group__concept__Shim__Conversion__to_FILETIME
 *
 * \param rhs A valid date, of type <code>UDATE</code>
 * \return A valid date, of type <code>FILETIME</code>
 *
 * \exception winstl::conversion_error If the conversion fails, e.g. the
 *   <code>UDATE</code> instance does not contain a valid date. When
 *   compiling absent exception support, a zero-initialised instance of
 *   <code>FILETIME</code> is returned.
 */
inline const FILETIME to_FILETIME(UDATE const& rhs)
{
    return to_FILETIME(rhs.st);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace stlsoft::winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_FILETIME_HPP_UDATE */

/* ///////////////////////////// end of file //////////////////////////// */

