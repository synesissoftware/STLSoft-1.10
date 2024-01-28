/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/system/directory_functions.h
 *
 * Purpose:     Directory functions.
 *
 * Created:     1st October 2016
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file unixstl/system/directory_functions.h
 *
 * \brief [C++] Directory functions
 *   (\ref group__library__System "System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_MAJOR       1
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_MINOR       0
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_REVISION    9
# define UNIXSTL_VER_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS_EDIT        19
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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_H_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.h>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_H_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_H_COPY_FUNCTIONS
# include <stlsoft/string/copy_functions.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_COPY_FUNCTIONS */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */

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
 * helpers functions
 */

#ifdef _WIN32

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>

STLSOFT_INLINE
char*
unixstl_C_get_home_directory_invoke_getenv_a_(
    char const* ev
)
{
    static char const s_szHomeUnique[] = "HOME_A4029A4F_7199_4181_8CC3_96ED2B319FE3";

    char* r = STLSOFT_NS_GLOBAL(getenv)(ev);

    STLSOFT_ASSERT(NULL != ev);

    if (NULL == r &&
        0 == STLSOFT_API_EXTERNAL_string_stricmp("HOME", ev))
    {
        /* See if the synthetic home is present */

        r = STLSOFT_NS_GLOBAL(getenv)(s_szHomeUnique);

        if (NULL != r)
        {
            return r;
        }
        else
        {
            /* (Attempt to) synthesise the HOME directory */

            char const* const   homeDrive   =   STLSOFT_NS_GLOBAL(getenv)("HOMEDRIVE");
            char const* const   homePath    =   STLSOFT_NS_GLOBAL(getenv)("HOMEPATH");

            if (NULL != homeDrive &&
                NULL != homePath)
            {
                us_size_t const cchHomeUnique   =   STLSOFT_NUM_ELEMENTS(s_szHomeUnique) - 1;
                us_size_t const cchHomeDrive    =   STLSOFT_NS_GLOBAL(strlen)(homeDrive);
                us_size_t const cchHomePath     =   STLSOFT_NS_GLOBAL(strlen)(homePath);
                us_size_t const cchTotal        =   cchHomeUnique + 1 + cchHomeDrive + cchHomePath;

                STLSOFT_C_AUTO_BUFFER_DECLARE(char, 100, buff);

                STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL(buff);

                if (0 != STLSOFT_C_AUTO_BUFFER_RESIZE(buff, 1 + cchTotal))
                {
                    errno = ENOMEM;

                    return 0;
                }
                else
                {
                    char*       p   =   buff.ptr;
                    us_size_t   s   =   buff.size;
                    us_size_t   n;

                    n = STLSoft_C_string_copy_a(p, s, s_szHomeUnique, cchHomeUnique);
                    p += n;
                    s -= n;

                    *p++ = '=';
                    --s;

                    n = STLSoft_C_string_copy_a(p, s, homeDrive, cchHomeDrive);
                    p += n;
                    s -= n;

                    n = STLSoft_C_string_copy_a(p, s, homePath, cchHomePath);
                    p += n;
                    s -= n;

                    STLSOFT_NS_GLOBAL(putenv)(buff.ptr);

                    STLSOFT_C_AUTO_BUFFER_FREE(buff);

                    r = STLSOFT_NS_GLOBAL(getenv)(s_szHomeUnique);
                }
            }
        }
    }

    return r;
}

# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
#else

# define unixstl_C_get_home_directory_invoke_getenv_a_      STLSOFT_NS_GLOBAL(getenv)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

STLSOFT_INLINE
us_size_t
unixstl_C_get_home_directory_a(
    us_char_a_t*    buffer
,   us_size_t       cchBuffer
)
{
    us_char_a_t const* const home = unixstl_C_get_home_directory_invoke_getenv_a_("HOME");

    if (NULL == home)
    {
        return 0;
    }
    else
    {
        us_size_t const cchHome = STLSOFT_NS_GLOBAL(strlen)(home);

        if (0 == cchBuffer)
        {
            return cchHome + 1;
        }

        return STLSoft_C_string_copy_with_nul_a(buffer, cchBuffer, home, cchHome);
    }
}

#if 0 /* TODO: implement this */
STLSOFT_INLINE
#endif
us_size_t
unixstl_C_get_home_directory_w(
    us_char_w_t*    buffer
,   us_size_t       cchBuffer
);

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#if defined(__cplusplus)

inline
us_size_t
get_home_directory(
    us_char_a_t*    buffer
,   us_size_t       cchBuffer
)
{
    return unixstl_C_get_home_directory_a(buffer, cchBuffer);
}

inline
us_size_t
get_home_directory(
    us_char_w_t*    buffer
,   us_size_t       cchBuffer
)
{
    return unixstl_C_get_home_directory_w(buffer, cchBuffer);
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

