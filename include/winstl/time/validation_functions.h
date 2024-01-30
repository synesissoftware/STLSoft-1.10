/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/validation_functions.h
 *
 * Purpose:     Validation functions for Windows time structures.
 *
 * Created:     1st June 2014
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


/** \file winstl/time/validation_functions.h
 *
 * \brief [C, C++] Validation functions for Windows time structures
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_H_VALIDATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_TIME_H_VALIDATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_H_VALIDATION_FUNCTIONS_MAJOR    2
# define WINSTL_VER_WINSTL_TIME_H_VALIDATION_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_TIME_H_VALIDATION_FUNCTIONS_REVISION 2
# define WINSTL_VER_WINSTL_TIME_H_VALIDATION_FUNCTIONS_EDIT     13
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
 * macros
 */

/** \ingroup group__library__Time
 * \defgroup subgroup__library__Time__ValidationFlags "Time Validation Flags"
 * @{
 */

/** \def WINSTL_INVALID_TIME_MILLISECONDS
 * The time has an invalid milliseconds value
 */

/** \def WINSTL_INVALID_TIME_SECONDS
 * The time has an invalid seconds value
 */

/** \def WINSTL_INVALID_TIME_MINUTES
 * The time has an invalid minutes value
 */

/** \def WINSTL_INVALID_TIME_HOURS
 * The time has an invalid hours value
 */

/** \def WINSTL_INVALID_TIME_MASK
 * Mask of invalid time flags
 */

#define WINSTL_INVALID_TIME_MILLISECONDS                    (0x0010)
#define WINSTL_INVALID_TIME_SECONDS                         (0x0020)
#define WINSTL_INVALID_TIME_MINUTES                         (0x0040)
#define WINSTL_INVALID_TIME_HOURS                           (0x0080)
#define WINSTL_INVALID_TIME_MASK                            (0x00f0)

/** \def WINSTL_INVALID_DATE_DAYS
 * The time has an invalid days value
 */

/** \def WINSTL_INVALID_DATE_MONTHS
 * The time has an invalid months value
 */

/** \def WINSTL_INVALID_DATE_YEARS
 * The time has an invalid years value
 */

/** \def WINSTL_INVALID_DATE_MASK
 * Mask of invalid date flags
 */

#define WINSTL_INVALID_DATE_DAYS                            (0x0100)
#define WINSTL_INVALID_DATE_MONTHS                          (0x0200)
#define WINSTL_INVALID_DATE_YEARS                           (0x0400)
#define WINSTL_INVALID_DATE_MASK                            (0x0700)

/** @} */


/** \ingroup group__library__Time
 * \defgroup subgroup__library__Time__ValidationStatusCodes "Time Validation Status Codes"
 * @{
 */

/** \def WINSTL_E_TIME_INVALIDDATE
 * Mask of invalid date flags
 */

#define WINSTL_E_TIME_INVALIDDATE                           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, ERROR_INVALID_PARAMETER)
#define WINSTL_E_TIME_INVALIDTIME                           HRESULT_FROM_WIN32(ERROR_INVALID_TIME)

/** @} */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */


/** Validates the elements of a date structure
 *
 * \param st Non-mutating pointer to a SYSTEMTIME structure
 * \param details Optional mutating pointer to a variable into which
 *   the details of the validation are written
 *
 * \return A \c HRESULT value that indicates the validationm result
 * \retval S_OK The \c st parameter points to a valid date
 * \retval E_POINTER The \c st parameter is \c null
 * \retval E_INVALIDARG The \c st parameter points to a value with invalid
 *   date component(s)
 * \retval HRESULT_FROM_WIN32(ERROR_INVALID_TIME) The \c st parameter points
 *   to a value with invalid time component(s)
 */
STLSOFT_INLINE
HRESULT
winstl_C_time_validate_SYSTEMTIME(
    SYSTEMTIME const*   st
,   DWORD*              details
) STLSOFT_NOEXCEPT
{
    DWORD dummy;

    if (NULL == details)
    {
        details = &dummy;
    }

    if (NULL == st)
    {
        return E_POINTER;
    }

    *details = 0;

    if (st->wMilliseconds > 999)
    {
        *details |= WINSTL_INVALID_TIME_MILLISECONDS;
    }
    if (st->wSecond > 59)
    {
        *details |= WINSTL_INVALID_TIME_SECONDS;
    }
    if (st->wMinute > 59)
    {
        *details |= WINSTL_INVALID_TIME_MINUTES;
    }
    if (st->wHour > 23)
    {
        *details |= WINSTL_INVALID_TIME_HOURS;
    }

    if (st->wMonth <  1 ||
        st->wMonth > 12)
    {
        *details |= WINSTL_INVALID_DATE_MONTHS;
    }
    if (0 == st->wDay)
    {
        *details |= WINSTL_INVALID_DATE_DAYS;
    }
    else
    {
        int isLeap;

        if (0 != (st->wYear % 4))
        {
            isLeap = 0;
        }
        else
        if (0 != (st->wYear % 100))
        {
            isLeap = 1;
        }
        else
        if (0 == (st->wYear % 400))
        {
            isLeap = 1;
        }
        else
        {
            isLeap = 0;
        }

        switch (st->wMonth)
        {
            default:
                if (st->wDay > 31)
                {
                    *details |= WINSTL_INVALID_DATE_DAYS;
                }
                break;
                break;
            case    4:
            case    6:
            case    9:
            case    11:
                if (st->wDay > 30)
                {
                    *details |= WINSTL_INVALID_DATE_DAYS;
                }
                break;
            case    2:
                if (isLeap)
                {
                    if (st->wDay > 29)
                    {
                        *details |= WINSTL_INVALID_DATE_DAYS;
                    }
                }
                else
                {
                    if (st->wDay > 28)
                    {
                        *details |= WINSTL_INVALID_DATE_DAYS;
                    }
                }
                break;
        }
    }

    if (0 != (WINSTL_INVALID_DATE_MASK & *details))
    {
        return WINSTL_E_TIME_INVALIDDATE;
    }

    if (0 != (WINSTL_INVALID_TIME_MASK & *details))
    {
        return HRESULT_FROM_WIN32(ERROR_INVALID_TIME);
    }

    return S_OK;
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

inline
HRESULT
time_validate(
    SYSTEMTIME const*   st
,   DWORD*              details = NULL
) STLSOFT_NOEXCEPT
{
    return winstl_C_time_validate_SYSTEMTIME(st, details);
}

inline
HRESULT
time_validate(
    SYSTEMTIME const&   st
,   DWORD*              details = NULL
) STLSOFT_NOEXCEPT
{
    return winstl_C_time_validate_SYSTEMTIME(&st, details);
}

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

#endif /* !WINSTL_INCL_WINSTL_TIME_H_VALIDATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

