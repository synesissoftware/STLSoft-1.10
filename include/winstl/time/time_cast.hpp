/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/time_cast.hpp
 *
 * Purpose:     winstl::time_cast<>.
 *
 * Created:     26th May 2014
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/time/time_cast.hpp
 *
 * \brief [C, C++] winstl::time_cast<>
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_HPP_TIME_CAST
#define WINSTL_INCL_WINSTL_TIME_HPP_TIME_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_MAJOR     2
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_MINOR     0
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_REVISION  2
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_EDIT      13
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
# error winstl/time/time_cast.hpp cannot be compiled without exception-support enabled
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR
# include <winstl/error/conversion_error.hpp>
#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR */
#ifndef WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS
# include <winstl/time/conversion_functions.h>
#endif /* !WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef __cplusplus
# error This file requires C++ compilation
#endif /* !__cplusplus */

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
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_winstl_time_cast
{

    template <
        typename T_to
    ,   typename T_from
    >
    struct time_cast_traits;

    template <>
    struct time_cast_traits<SYSTEMTIME, SYSTEMTIME>
    {
    public:
        static
        SYSTEMTIME
        convert(
            SYSTEMTIME const& t
        )
        {
            return t;
        }
    };

    template <>
    struct time_cast_traits<FILETIME, FILETIME>
    {
    public:
        static
        FILETIME
        convert(
            FILETIME const& t
        )
        {
            return t;
        }
    };

    template <>
    struct time_cast_traits<FILETIME, SYSTEMTIME>
    {
    public:
        static
        FILETIME
        convert(
            SYSTEMTIME const& t
        )
        {
            FILETIME ft;

            if (!STLSOFT_NS_GLOBAL(SystemTimeToFileTime)(&t, &ft))
            {
                DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

// TODO: implement a bad_time_cast
                STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
            }

            return ft;
        }
    };

    template <>
    struct time_cast_traits<SYSTEMTIME, FILETIME>
    {
    public:
        static
        SYSTEMTIME
        convert(
            FILETIME const& t
        )
        {
            SYSTEMTIME st;

            if (!STLSOFT_NS_GLOBAL(FileTimeToSystemTime)(&t, &st))
            {
                DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

// TODO: implement a bad_time_cast
                STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
            }

            return st;
        }
    };

} /* namespace ximpl_winstl_time_cast */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * casts
 */

template <
    typename T_to
,   typename T_from
>
T_to
time_cast(T_from const& from)
{
    return ximpl_winstl_time_cast::time_cast_traits<T_to, T_from>::convert(from);
}

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

#endif /* !WINSTL_INCL_WINSTL_TIME_HPP_TIME_CAST */

/* ///////////////////////////// end of file //////////////////////////// */

