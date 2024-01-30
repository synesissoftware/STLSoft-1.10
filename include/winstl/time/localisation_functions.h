/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/localisation_functions.h
 *
 * Purpose:     Localisation functions for Windows time structures.
 *
 * Created:     9th October 2014
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


/** \file winstl/time/localisation_functions.h
 *
 * \brief [C, C++] Localisation functions for Windows time structures
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_LOCALISATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_LOCALISATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_LOCALISATION_FUNCTIONS_MAJOR      2
# define WINSTL_VER_WINSTL_TIME_H_LOCALISATION_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_TIME_H_LOCALISATION_FUNCTIONS_REVISION   2
# define WINSTL_VER_WINSTL_TIME_H_LOCALISATION_FUNCTIONS_EDIT       12
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

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR
#  include <winstl/error/conversion_error.hpp>
# endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

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
 * C functions
 */

/** Localises a UTC time to the ambient local time
 *
 * \ingroup group__library__Time
 *
 * \param utcTime Pointer to the source \c FILETIME instance, which is
 *   assumed to be in UTC
 * \param localTime Pointer to the destination \c FILETIME instance, which
 *   is to be given the local value of \c *utcTime
 *
 * \return Boolean indicating the function success
 * \retval false The function failed
 * \retval !false The function succeeded
 *
 * \pre (NULL != utcTime)
 * \pre (NULL != localTime)
 *
 * \note The caller may pass pointers to the same structure, in which case
 *   the instance is converted in place
 */
STLSOFT_INLINE
BOOL
winstl_C_localise_UTC_FILETIME_to_local_FILETIME(
    FILETIME const* utcTime
,   FILETIME*       localTime
)
{
    WINSTL_ASSERT(NULL != utcTime);
    WINSTL_ASSERT(NULL != localTime);

    if (utcTime == localTime)
    {
        FILETIME    local;
        DWORD const r = winstl_C_localise_UTC_FILETIME_to_local_FILETIME(utcTime, &local);

        if (ERROR_SUCCESS == r)
        {
            *localTime = local;
        }

        return r;
    }
    else
    {
        return STLSOFT_NS_GLOBAL(FileTimeToLocalFileTime)(utcTime, localTime);
    }
}

/** Localises an ambient local time to UTC time
 *
 * \ingroup group__library__Time
 *
 * \param localTime Pointer to the source \c FILETIME instance, which is
 *   assumed to be local
 * \param utcTime Pointer to the destination \c FILETIME instance, which
 *   is to be given the UTC value of \c *localTime
 *
 * \return Boolean indicating the function success
 * \retval false The function failed
 * \retval !false The function succeeded
 *
 * \pre (NULL != localTime)
 * \pre (NULL != utcTime)
 *
 * \note The caller may pass pointers to the same structure, in which case
 *   the instance is converted in place
 */
STLSOFT_INLINE
BOOL
winstl_C_localise_local_FILETIME_to_UTC_FILETIME(
    FILETIME const* localTime
,   FILETIME*       utcTime
)
{
    WINSTL_ASSERT(NULL != localTime);
    WINSTL_ASSERT(NULL != utcTime);

    if (utcTime == localTime)
    {
        FILETIME    utc;
        DWORD const r = winstl_C_localise_local_FILETIME_to_UTC_FILETIME(localTime, &utc);

        if (ERROR_SUCCESS == r)
        {
            *utcTime = utc;
        }

        return r;
    }
    else
    {
        return STLSOFT_NS_GLOBAL(LocalFileTimeToFileTime)(localTime, utcTime);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus


/** Localises a UTC time to the ambient local time
 *
 * \ingroup group__library__Time
 *
 * \param utcTime Pointer to the source \c FILETIME instance, which is
 *   assumed to be in UTC
 * \param localTime Pointer to the destination \c FILETIME instance, which
 *   is to be given the local value of \c *utcTime
 *
 * \return Boolean indicating the function success
 * \retval false The function failed
 * \retval !false The function succeeded
 *
 * \pre (NULL != utcTime)
 * \pre (NULL != localTime)
 *
 * \note The caller may pass pointers to the same structure, in which case
 *   the instance is converted in place
 */
inline
BOOL
localise_UTC_time_to_local_time(
    FILETIME const* utcTime
,   FILETIME*       localTime
)
{
    WINSTL_ASSERT(NULL != utcTime);
    WINSTL_ASSERT(NULL != localTime);

    return winstl_C_localise_UTC_FILETIME_to_local_FILETIME(utcTime, localTime);
}

/** \see localise_UTC_time_to_local_time(FILETIME const* , FILETIME* )
 */
inline
BOOL
localise_UTC_time_to_local_time(
    FILETIME const& utcTime
,   FILETIME*       localTime
)
{
    WINSTL_ASSERT(NULL != localTime);

    return winstl_C_localise_UTC_FILETIME_to_local_FILETIME(&utcTime, localTime);
}

/** Localises an ambient local time to UTC time
 *
 * \ingroup group__library__Time
 *
 * \param localTime Pointer to the source \c FILETIME instance, which is
 *   assumed to be local
 * \param utcTime Pointer to the destination \c FILETIME instance, which
 *   is to be given the UTC value of \c *localTime
 *
 * \return Boolean indicating the function success
 * \retval false The function failed
 * \retval !false The function succeeded
 *
 * \pre (NULL != localTime)
 * \pre (NULL != utcTime)
 *
 * \note The caller may pass pointers to the same structure, in which case
 *   the instance is converted in place
 */
inline
BOOL
localise_local_time_to_UTC_time(
    FILETIME const* localTime
,   FILETIME*       utcTime
)
{
    WINSTL_ASSERT(NULL != localTime);
    WINSTL_ASSERT(NULL != utcTime);

    return winstl_C_localise_local_FILETIME_to_UTC_FILETIME(localTime, utcTime);
}

/** \see localise_UTC_time_to_local_time(FILETIME const* , FILETIME* )
 */
inline
BOOL
localise_local_time_to_UTC_time(
    FILETIME const& localTime
,   FILETIME*       utcTime
)
{
    WINSTL_ASSERT(NULL != utcTime);

    return winstl_C_localise_local_FILETIME_to_UTC_FILETIME(&localTime, utcTime);
}



# if defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/** Localises a UTC time to the ambient local time
 *
 * \ingroup group__library__Time
 *
 * \param utcTime Pointer to the source \c FILETIME instance, which is
 *   assumed to be in UTC
 *
 * \return The local time
 *
 * \pre (NULL != utcTime)
 *
 * \exception winstl::conversion_error Thrown if the conversion cannot be
 *   performed
 */
inline
FILETIME
localise_UTC_time_to_local_time(
    FILETIME const* utcTime
)
{
    WINSTL_ASSERT(NULL != utcTime);

    FILETIME localTime;

    if (!winstl_C_localise_UTC_FILETIME_to_local_FILETIME(utcTime, &localTime))
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
    }

    return localTime;
}

inline
FILETIME
localise_UTC_time_to_local_time(
    FILETIME const& utcTime
)
{
    return localise_UTC_time_to_local_time(&utcTime);
}


/** Localises a UTC time to the ambient local time
 *
 * \ingroup group__library__Time
 *
 * \param localTime Pointer to the source \c FILETIME instance, which is
 *   assumed to be in local time
 *
 * \return The local time
 *
 * \pre (NULL != utcTime)
 *
 * \exception winstl::conversion_error Thrown if the conversion cannot be
 *   performed
 */
inline
FILETIME
localise_local_time_to_UTC_time(
    FILETIME const* localTime
)
{
    WINSTL_ASSERT(NULL != localTime);

    FILETIME utcTime;

    if (!winstl_C_localise_local_FILETIME_to_UTC_FILETIME(localTime, &utcTime))
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        STLSOFT_THROW_X(conversion_error("failed to convert time value", e));
    }

    return utcTime;
}

inline
FILETIME
localise_local_time_to_UTC_time(
    FILETIME const& localTime
)
{
    return localise_local_time_to_UTC_time(&localTime);
}

# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#endif /* __cplusplus */

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

#endif /* !WINSTL_INCL_WINSTL_TIME_H_LOCALISATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

