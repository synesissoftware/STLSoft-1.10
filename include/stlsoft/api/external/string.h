/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/api/external/string.h
 *
 * Purpose:     External preprocessor aliases for string functions.
 *
 * Created:     15th November 2002
 * Updated:     25th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
#define STLSOFT_INCL_STLSOFT_API_external_h_string

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */

#if 0 ||\
    defined(__MINGW32__)||\
    defined(__MINGW64__)||\
    0
# ifndef STLSOFT_INCL_H_STRINGS
#  define STLSOFT_INCL_H_STRINGS
#  include <strings.h>
# endif /* !STLSOFT_INCL_H_STRINGS */
#endif

#if 0 ||\
    defined(STLSOFT_COMPILER_IS_BORLAND)||\
    0
# ifndef STLSOFT_INCL_H_TCHAR
#  include <tchar.h>
# endif /* !STLSOFT_INCL_H_TCHAR */
#endif /* compiler */

#ifndef STLSOFT_INCL_H_WCHAR
# define STLSOFT_INCL_H_WCHAR
# include <wchar.h>
#endif /* !STLSOFT_INCL_H_WCHAR */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if 0
#elif defined(STLSOFT_COMPILER_IS_MSVC)

# ifdef STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_
#  undef STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_
# endif

  // Whether we use ANSI

  // If __STDC__ is defined then we use compiler-extension forms
  // If VC++ 10+ and neither "secure" deprecation nor CRT deprecation is
  //  suppressed then we use compiler-extension forms

# if 0
# elif defined(__STDC__)

#  define STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_
# elif 1 &&\
       _MSC_VER >= 1500 &&\
       !defined(_CRT_SECURE_NO_WARNINGS) &&\
       !defined(_CRT_NONSTDC_NO_WARNINGS) &&\
       1

#  define STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_
# else

# endif

#else

#endif

/* /////////////////////////////////////////////////////////////////////////
 * string functions
 */

/* *************************************
 * stricmp
 */

#ifndef STLSOFT_API_EXTERNAL_string_stricmp
# if 0

  /* Borland */
# elif defined(STLSOFT_COMPILER_IS_BORLAND)

#  if 0
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_stricmp              STLSOFT_NS_GLOBAL_(stricmp)
#  elif !defined(__MFC_COMPAT__)
#   define STLSOFT_API_EXTERNAL_string_stricmp              STLSOFT_NS_GLOBAL_(_stricmp)
#  endif

  /* Digital Mars */
# elif defined(STLSOFT_COMPILER_IS_DMC)

#  define STLSOFT_API_EXTERNAL_string_stricmp               STLSOFT_NS_GLOBAL_(stricmp)

  /* GCC */
# elif defined(STLSOFT_COMPILER_IS_GCC)

#  if 0
#  elif !defined(__STRICT_ANSI__)
#   define STLSOFT_API_EXTERNAL_string_stricmp              STLSOFT_NS_GLOBAL_(_stricmp)
#  endif

  /* Intel */
# elif defined(STLSOFT_COMPILER_IS_INTEL) && \
       defined(_WIN32)

#  if 0
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_stricmp              STLSOFT_NS_GLOBAL_(stricmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_stricmp              STLSOFT_NS_GLOBAL_(_stricmp)
#  endif

  /* Microsoft Visual C++ */
# elif defined(STLSOFT_COMPILER_IS_MSVC)

#  if 0
#  elif !defined(STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_)
#   define STLSOFT_API_EXTERNAL_string_stricmp              STLSOFT_NS_GLOBAL_(stricmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_stricmp              STLSOFT_NS_GLOBAL_(_stricmp)
#  endif

  /* Metrowerks CodeWarrior */
# elif defined(STLSOFT_COMPILER_IS_MWERKS)

#  define STLSOFT_API_EXTERNAL_string_stricmp               STLSOFT_NS_GLOBAL_(stricmp)

  /* Watcom */
# elif defined(STLSOFT_COMPILER_IS_WATCOM)

#  define STLSOFT_API_EXTERNAL_string_stricmp               STLSOFT_NS_GLOBAL_(_stricmp)
# endif
#endif /* !STLSOFT_API_EXTERNAL_string_stricmp */

#ifndef STLSOFT_API_EXTERNAL_string_stricmp
# ifdef _WIN32
#  define STLSOFT_API_EXTERNAL_string_stricmp               STLSOFT_NS_GLOBAL_(lstrcmpiA)
# endif
#endif /* !STLSOFT_API_EXTERNAL_string_stricmp */


/* *************************************
 * wcsicmp
 */

#ifndef STLSOFT_API_EXTERNAL_string_wcsicmp
# if 0

  /* Borland */
# elif defined(STLSOFT_COMPILER_IS_BORLAND)

#  if 0
#  elif (0x0620 == (__BORLANDC__ & 0xfff0))
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL(_wcsicmp)
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL_(wcsicmp)
#  elif !defined(__MFC_COMPAT__)
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL_(_wcsicmp)
#  endif

  /* Digital Mars */
# elif defined(STLSOFT_COMPILER_IS_DMC)

#  define STLSOFT_API_EXTERNAL_string_wcsicmp               STLSOFT_NS_GLOBAL_(wcsicmp)

  /* GCC */
# elif defined(STLSOFT_COMPILER_IS_GCC)

#  if 0
#  elif !defined(__STRICT_ANSI__)
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL_(_wcsicmp)
#  endif

  /* Intel */
# elif defined(STLSOFT_COMPILER_IS_INTEL) && \
       defined(_WIN32)

#  if 0
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL_(wcsicmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL_(_wcsicmp)
#  endif

  /* Microsoft Visual C++ */
# elif defined(STLSOFT_COMPILER_IS_MSVC)

#  if 0
#  elif !defined(STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_)
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL_(wcsicmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_wcsicmp              STLSOFT_NS_GLOBAL_(_wcsicmp)
#  endif

  /* Metrowerks CodeWarrior */
# elif defined(STLSOFT_COMPILER_IS_MWERKS)

#  define STLSOFT_API_EXTERNAL_string_wcsicmp               STLSOFT_NS_GLOBAL_(wcsicmp)

  /* Watcom */
# elif defined(STLSOFT_COMPILER_IS_WATCOM)

#  define STLSOFT_API_EXTERNAL_string_wcsicmp               STLSOFT_NS_GLOBAL_(_wcsicmp)
# endif
#endif /* !STLSOFT_API_EXTERNAL_string_wcsicmp */

#ifndef STLSOFT_API_EXTERNAL_string_wcsicmp
# ifdef _WIN32
#  define STLSOFT_API_EXTERNAL_string_wcsicmp               STLSOFT_NS_GLOBAL_(lstrcmpiW)
# endif
#endif /* !STLSOFT_API_EXTERNAL_string_wcsicmp */


/* *************************************
 * strnicmp
 */

#ifndef STLSOFT_API_EXTERNAL_string_strnicmp
# if 0

  /* Borland */
# elif defined(STLSOFT_COMPILER_IS_BORLAND)

#  if 0
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(strnicmp)
#  elif !defined(__MFC_COMPAT__)
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(_strnicmp)
#  endif

  /* Digital Mars */
# elif defined(STLSOFT_COMPILER_IS_DMC)

#  define STLSOFT_API_EXTERNAL_string_strnicmp              STLSOFT_NS_GLOBAL_(strnicmp)

  /* GCC */
# elif defined(STLSOFT_COMPILER_IS_GCC)

#  if 0
#  elif 0 || \
        defined(__MINGW32__)||\
        defined(__MINGW64__)||\
        0
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(strncasecmp)
#  elif !defined(__STRICT_ANSI__)
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(_strnicmp)
#  endif

  /* Intel */
# elif defined(STLSOFT_COMPILER_IS_INTEL) && \
       defined(_WIN32)

#  if 0
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(strnicmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(_strnicmp)
#  endif

  /* Microsoft Visual C++ */
# elif defined(STLSOFT_COMPILER_IS_MSVC)

#  if 0
#  elif !defined(STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_)
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(strnicmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_strnicmp             STLSOFT_NS_GLOBAL_(_strnicmp)
#  endif

  /* Metrowerks CodeWarrior */
# elif defined(STLSOFT_COMPILER_IS_MWERKS)

#  define STLSOFT_API_EXTERNAL_string_strnicmp              STLSOFT_NS_GLOBAL_(strnicmp)

  /* Watcom */
# elif defined(STLSOFT_COMPILER_IS_WATCOM)

#  define STLSOFT_API_EXTERNAL_string_strnicmp              STLSOFT_NS_GLOBAL_(_strnicmp)
# endif
#endif /* !STLSOFT_API_EXTERNAL_string_strnicmp */


/* *************************************
 * wcsnicmp
 */

#ifndef STLSOFT_API_EXTERNAL_string_wcsnicmp
# if 0

  /* Borland */
# elif defined(STLSOFT_COMPILER_IS_BORLAND)

#  if 0
#  elif (0x0620 == (__BORLANDC__ & 0xfff0))
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL(_wcsnicmp)
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL_(wcsnicmp)
#  elif !defined(__MFC_COMPAT__)
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL_(_wcsnicmp)
#  endif

  /* Digital Mars */
# elif defined(STLSOFT_COMPILER_IS_DMC)

#  define STLSOFT_API_EXTERNAL_string_wcsnicmp              STLSOFT_NS_GLOBAL_(wcsnicmp)

  /* GCC */
# elif defined(STLSOFT_COMPILER_IS_GCC)

#  if 0
#  elif !defined(__STRICT_ANSI__)
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL_(_wcsnicmp)
#  endif

  /* Intel */
# elif defined(STLSOFT_COMPILER_IS_INTEL) && \
       defined(_WIN32)

#  if 0
#  elif !defined(__STDC__)
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL_(wcsnicmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL_(_wcsnicmp)
#  endif

  /* Microsoft Visual C++ */
# elif defined(STLSOFT_COMPILER_IS_MSVC)

#  if 0
#  elif !defined(STLSOFT_API_EXTERNAL_string_USE_MSVC_COMPILER_EXTENSION_FORMS_)
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL_(wcsnicmp)
#  else
#   define STLSOFT_API_EXTERNAL_string_wcsnicmp             STLSOFT_NS_GLOBAL_(_wcsnicmp)
#  endif

  /* Metrowerks CodeWarrior */
# elif defined(STLSOFT_COMPILER_IS_MWERKS)

#  define STLSOFT_API_EXTERNAL_string_wcsnicmp              STLSOFT_NS_GLOBAL_(wcsnicmp)

  /* Watcom */
# elif defined(STLSOFT_COMPILER_IS_WATCOM)

#  define STLSOFT_API_EXTERNAL_string_wcsnicmp              STLSOFT_NS_GLOBAL_(_wcsnicmp)
# endif
#endif /* !STLSOFT_API_EXTERNAL_string_wcsnicmp */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifndef STLSOFT_API_EXTERNAL_string_strnicmp

# define STLSOFT_API_EXTERNAL_string_strnicmp               stlsoft_C_strnicmp

# ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNICMP
#  include <stlsoft/string/c_string/strnicmp.h>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNICMP */
#endif /* !STLSOFT_API_EXTERNAL_string_strnicmp */

#ifndef STLSOFT_API_EXTERNAL_string_wcsnicmp

# define STLSOFT_API_EXTERNAL_string_wcsnicmp               stlsoft_C_wcsnicmp

# ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNICMP
#  include <stlsoft/string/c_string/strnicmp.h>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNICMP */
#endif /* !STLSOFT_API_EXTERNAL_string_strnicmp */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

/* ///////////////////////////// end of file //////////////////////////// */

