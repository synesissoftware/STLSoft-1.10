/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/system_information_functions.h
 *
 * Purpose:     System information functions.
 *
 * Created:     5th November 2014
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


/** \file winstl/system/system_information_functions.h
 *
 * \brief [C++] System information functions
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS_MAJOR      1
# define WINSTL_VER_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS_MINOR      1
# define WINSTL_VER_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS_REVISION   4
# define WINSTL_VER_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS_EDIT       12
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_SystemInformation
# include <winstl/api/external/SystemInformation.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_SystemInformation */

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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# ifdef UNLEN

#  define WINSTL_SYSTEM_SIF_UNLEN_                          UNLEN
# else

#  define WINSTL_SYSTEM_SIF_UNLEN_                          (256)
# endif
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
ss_truthy_t
winstl_C_system_information_functions_MORE_DATA_(
    DWORD e
)
{
    switch (e)
    {
    case ERROR_BUFFER_OVERFLOW:
    case ERROR_INSUFFICIENT_BUFFER:
    case ERROR_MORE_DATA:
        return 1;
    default:
        return 0;
    }
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Obtains the computer name
 *
 * \param buffer A pointer to an array into which the computer name will be
 *   written
 * \param cchBuffer Number of character spaces available in \c buffer
 *
 * \return The number of characters excluding the nul-terminator written if
 *   cchBuffer is sufficient; the number of characters including the
 *   nul-terminator if cchBuffer is insufficient.
 *
 * \note There is a defect in GetComputerNameA(), in that the required size
 *   is not returned when the buffer is insufficient. This is handled by
 *   providing an empty buffer of maximum size and then returning the actual
 *   length (+1)
 *
 * \pre 0 == cchBuffer || NULL != buffer
 */
STLSOFT_INLINE
ws_size_t
winstl_C_get_computer_name_a(
    ws_char_a_t buffer[]
,   ws_size_t   cchBuffer
)
{
    DWORD cch;

    WINSTL_ASSERT(0 == cchBuffer || NULL != buffer);

    if (0 == cchBuffer)
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_BUFFER_OVERFLOW);
    }

    cch = STLSOFT_STATIC_CAST(DWORD, cchBuffer);
    if (0 != cchBuffer &&
        WINSTL_API_EXTERNAL_SystemInformation_GetComputerNameA(buffer, &cch))
    {
        return cch;
    }
    else
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        if (winstl_C_system_information_functions_MORE_DATA_(e))
        {
            ws_char_a_t name_[MAX_COMPUTERNAME_LENGTH + 1];

            cch = STLSOFT_NUM_ELEMENTS(name_);

            if (WINSTL_API_EXTERNAL_SystemInformation_GetComputerNameA(&name_[0], &cch))
            {
                ++cch;
            }

            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(e);
        }

        return cch;
    }
}

/** Widestring form of winstl_C_get_computer_name_a()
 *
 * \see winstl_C_get_computer_name_a()
 */
STLSOFT_INLINE
ws_size_t
winstl_C_get_computer_name_w(
    ws_char_w_t buffer[]
,   ws_size_t   cchBuffer
)
{
    DWORD cch;

    WINSTL_ASSERT(0 == cchBuffer || NULL != buffer);

    if (0 == cchBuffer)
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_BUFFER_OVERFLOW);
    }

    cch = STLSOFT_STATIC_CAST(DWORD, cchBuffer);
    if (0 != cchBuffer &&
        WINSTL_API_EXTERNAL_SystemInformation_GetComputerNameW(buffer, &cch))
    {
        return cch;
    }
    else
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        if (winstl_C_system_information_functions_MORE_DATA_(e))
        {
            ws_char_w_t name_[MAX_COMPUTERNAME_LENGTH + 1];

            cch = STLSOFT_NUM_ELEMENTS(name_);

            if (WINSTL_API_EXTERNAL_SystemInformation_GetComputerNameW(&name_[0], &cch))
            {
                ++cch;
            }

            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(e);
        }

        return cch;
    }
}


/** Obtains the user name
 *
 * \param buffer A pointer to an array into which the user name will be
 *   written
 * \param cchBuffer Number of character spaces available in \c buffer
 *
 * \return The number of characters excluding the nul-terminator written if
 *   cchBuffer is sufficient; the number of characters including the
 *   nul-terminator if cchBuffer is insufficient.
 *
 * \note GetUserNameA() has the unpleasant semantics that it returns double
 *   the required number of characters when \c buffer is insufficient. This
 *   is corrected in this implementation
 *
 * \pre 0 == cchBuffer || NULL != buffer
 */
STLSOFT_INLINE
ws_size_t
winstl_C_get_user_name_a(
    ws_char_a_t buffer[]
,   ws_size_t   cchBuffer
)
{
    DWORD cch;

    WINSTL_ASSERT(0 == cchBuffer || NULL != buffer);

    if (0 == cchBuffer)
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INSUFFICIENT_BUFFER);
    }

    cch = STLSOFT_STATIC_CAST(DWORD, cchBuffer);
    if (0 != cchBuffer &&
        WINSTL_API_EXTERNAL_SystemInformation_GetUserNameA(buffer, &cch))
    {
        return cch - 1;
    }
    else
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        if (winstl_C_system_information_functions_MORE_DATA_(e))
        {
            ws_char_a_t name_[WINSTL_SYSTEM_SIF_UNLEN_ + 1];

            cch = STLSOFT_NUM_ELEMENTS(name_);

            WINSTL_API_EXTERNAL_SystemInformation_GetUserNameA(&name_[0], &cch);

            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(e);
        }

        return cch;
    }
}

/** Widestring form of winstl_C_get_user_name_a()
 *
 * \see winstl_C_get_user_name_a()
 */
STLSOFT_INLINE
ws_size_t
winstl_C_get_user_name_w(
    ws_char_w_t buffer[]
,   ws_size_t   cchBuffer
)
{
    DWORD cch;

    WINSTL_ASSERT(0 == cchBuffer || NULL != buffer);

    if (0 == cchBuffer)
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INSUFFICIENT_BUFFER);
    }

    cch = STLSOFT_STATIC_CAST(DWORD, cchBuffer);
    if (0 != cchBuffer &&
        WINSTL_API_EXTERNAL_SystemInformation_GetUserNameW(buffer, &cch))
    {
        return cch - 1;
    }
    else
    {
        DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        if (winstl_C_system_information_functions_MORE_DATA_(e))
        {
            ws_char_w_t name_[WINSTL_SYSTEM_SIF_UNLEN_ + 1];

            cch = STLSOFT_NUM_ELEMENTS(name_);

            WINSTL_API_EXTERNAL_SystemInformation_GetUserNameW(&name_[0], &cch);

            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(e);
        }

        return cch;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

inline
ws_size_t
get_computer_name(
    ws_char_a_t buffer[]
,   ws_size_t   cchBuffer
)
{
    return winstl_C_get_computer_name_a(buffer, cchBuffer);
}

# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template <size_t N>
inline
ws_size_t
get_computer_name(
    ws_char_a_t (&buffer)[N]
)
{
    return winstl_C_get_computer_name_a(buffer, N);
}
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

inline
ws_size_t
get_computer_name(
    ws_char_w_t buffer[]
,   ws_size_t   cchBuffer
)
{
    return winstl_C_get_computer_name_w(buffer, cchBuffer);
}

# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template <size_t N>
inline
ws_size_t
get_computer_name(
    ws_char_w_t (&buffer)[N]
)
{
    return winstl_C_get_computer_name_w(buffer, N);
}
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */


inline
ws_size_t
get_user_name(
    ws_char_a_t buffer[]
,   ws_size_t   cchBuffer
)
{
    return winstl_C_get_user_name_a(buffer, cchBuffer);
}

# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template <size_t N>
inline
ws_size_t
get_user_name(
    ws_char_a_t (&buffer)[N]
)
{
    return winstl_C_get_user_name_a(buffer, N);
}
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

inline
ws_size_t
get_user_name(
    ws_char_w_t buffer[]
,   ws_size_t   cchBuffer
)
{
    return winstl_C_get_user_name_w(buffer, cchBuffer);
}

# ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

template <size_t N>
inline
ws_size_t
get_user_name(
    ws_char_w_t (&buffer)[N]
)
{
    return winstl_C_get_user_name_w(buffer, N);
}
# endif /* !STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

