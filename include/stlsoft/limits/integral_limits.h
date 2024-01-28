/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/limits/integral_limits.h (formerly stlsoft/util/limit_traits.h; originally MLLimits.h; ::SynesisStd)
 *
 * Purpose:     Integral constants.
 *
 * Created:     16th January 2002
 * Updated:     22nd January 2024
 *
 * Thanks:      To Jonathan Wakely for help with Solaris compatibility.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/limits/integral_limits.h
 *
 * \brief [C, C++] Integral constants
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS
#define STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_LIMITS_H_INTEGRAL_LIMITS_MAJOR     5
# define STLSOFT_VER_STLSOFT_LIMITS_H_INTEGRAL_LIMITS_MINOR     0
# define STLSOFT_VER_STLSOFT_LIMITS_H_INTEGRAL_LIMITS_REVISION  6
# define STLSOFT_VER_STLSOFT_LIMITS_H_INTEGRAL_LIMITS_EDIT      71
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Constants & definitions
 */

/* 8-bit */

/** \def STLSOFT_GEN_SINT8_SUFFIX(i)
 *
 * Applies appropriate suffix to raw signed 8-bit integer constant
 */

/** \def STLSOFT_GEN_UINT8_SUFFIX(i)
 *
 * Applies appropriate suffix to raw unsigned 8-bit integer constant
 */

#define STLSOFT_GEN_SINT8_SUFFIX(i)                         (i)
#define STLSOFT_GEN_UINT8_SUFFIX(i)                         (i ## U)

/* 16-bit */

/** \def STLSOFT_GEN_SINT16_SUFFIX(i)
 *
 * Applies appropriate suffix to raw signed 16-bit integer constant
 */

/** \def STLSOFT_GEN_UINT16_SUFFIX(i)
 *
 * Applies appropriate suffix to raw unsigned 16-bit integer constant
 */

#define STLSOFT_GEN_SINT16_SUFFIX(i)                        (i)
#define STLSOFT_GEN_UINT16_SUFFIX(i)                        (i ## U)

/* 32-bit */

/** \def STLSOFT_GEN_SINT32_SUFFIX(i)
 *
 * Applies appropriate suffix to raw signed 32-bit integer constant
 */

/** \def STLSOFT_GEN_UINT32_SUFFIX(i)
 *
 * Applies appropriate suffix to raw unsigned 32-bit integer constant
 */

#if _STLSOFT_SIZEOF_LONG == 4
# define STLSOFT_GEN_SINT32_SUFFIX(i)                       (i ## L)
# define STLSOFT_GEN_UINT32_SUFFIX(i)                       (i ## UL)
#else /* ? _STLSOFT_SIZEOF_LONG */
# define STLSOFT_GEN_SINT32_SUFFIX(i)                       (i)
# define STLSOFT_GEN_UINT32_SUFFIX(i)                       (i ## U)
#endif /* _STLSOFT_SIZEOF_LONG */

/* 64-bit */

/** \def STLSOFT_GEN_SINT64_SUFFIX(i)
 *
 * Applies appropriate suffix to raw signed 64-bit integer constant
 */

/** \def STLSOFT_GEN_UINT64_SUFFIX(i)
 *
 * Applies appropriate suffix to raw unsigned 64-bit integer constant
 */

#if 0
#elif defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

# define STLSOFT_GEN_SINT64_SUFFIX(i)                       (i ## L)
# define STLSOFT_GEN_UINT64_SUFFIX(i)                       (i ## UL)
#elif ( (   defined(STLSOFT_COMPILER_IS_BORLAND) && \
            __BORLANDC__ >= 0x0582) || \
        defined(STLSOFT_COMPILER_IS_CLANG) || \
        defined(STLSOFT_COMPILER_IS_COMO) || \
        defined(STLSOFT_COMPILER_IS_DMC) || \
        defined(STLSOFT_COMPILER_IS_GCC) || \
        defined(STLSOFT_COMPILER_IS_MWERKS) || \
        defined(STLSOFT_COMPILER_IS_SUNPRO))

# define STLSOFT_GEN_SINT64_SUFFIX(i)                       (i ## LL)
# define STLSOFT_GEN_UINT64_SUFFIX(i)                       (i ## ULL)
#elif ( defined(STLSOFT_COMPILER_IS_BORLAND) || \
        defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_VECTORC) || \
        defined(STLSOFT_COMPILER_IS_WATCOM))

# define STLSOFT_GEN_SINT64_SUFFIX(i)                       (i ## L)
# define STLSOFT_GEN_UINT64_SUFFIX(i)                       (i ## UL)
#else

# error Compiler not discriminated
#endif /* compiler */


/** \def STLSOFT_INTEGRAL_LIMIT_SINT8_MIN
 *
 * Integer constant for minimum 8-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_SINT8_MAX
 *
 * Integer constant for maximum 8-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT8_MIN
 *
 * Integer constant for minimum 8-bit unsigned integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT8_MAX
 *
 * Integer constant for maximum 8-bit unsigned integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_SINT16_MIN
 *
 * Integer constant for minimum 16-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_SINT16_MAX
 *
 * Integer constant for maximum 16-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT16_MIN
 *
 * Integer constant for minimum 16-bit unsigned integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT16_MAX
 *
 * Integer constant for maximum 16-bit unsigned integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_SINT32_MIN
 *
 * Integer constant for minimum 32-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_SINT32_MAX
 *
 * Integer constant for maximum 32-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT32_MIN
 *
 * Integer constant for minimum 32-bit unsigned integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT32_MAX
 *
 * Integer constant for maximum 32-bit unsigned integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_SINT64_MIN
 *
 * Integer constant for minimum 64-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_SINT64_MAX
 *
 * Integer constant for maximum 64-bit signed integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT64_MIN
 *
 * Integer constant for minimum 64-bit unsigned integer
 */
/** \def STLSOFT_INTEGRAL_LIMIT_UINT64_MAX
 *
 * Integer constant for maximum 64-bit unsigned integer
 */

#define   STLSOFT_INTEGRAL_LIMIT_SINT8_MIN                  (- STLSOFT_GEN_SINT8_SUFFIX(127) - 1)
#define   STLSOFT_INTEGRAL_LIMIT_SINT8_MAX                  (+ STLSOFT_GEN_SINT8_SUFFIX(127))

#define   STLSOFT_INTEGRAL_LIMIT_UINT8_MIN                  (  STLSOFT_GEN_UINT8_SUFFIX(0))
#define   STLSOFT_INTEGRAL_LIMIT_UINT8_MAX                  (  STLSOFT_GEN_UINT8_SUFFIX(255))

#define   STLSOFT_INTEGRAL_LIMIT_SINT16_MIN                 (- STLSOFT_GEN_SINT16_SUFFIX(32767) - 1)
#define   STLSOFT_INTEGRAL_LIMIT_SINT16_MAX                 (+ STLSOFT_GEN_SINT16_SUFFIX(32767))

#define   STLSOFT_INTEGRAL_LIMIT_UINT16_MIN                 (  STLSOFT_GEN_UINT16_SUFFIX(0))
#define   STLSOFT_INTEGRAL_LIMIT_UINT16_MAX                 (  STLSOFT_GEN_UINT16_SUFFIX(65535))

#define   STLSOFT_INTEGRAL_LIMIT_SINT32_MIN                 (- STLSOFT_GEN_SINT32_SUFFIX(2147483647) - 1)
#define   STLSOFT_INTEGRAL_LIMIT_SINT32_MAX                 (+ STLSOFT_GEN_SINT32_SUFFIX(2147483647))

#define   STLSOFT_INTEGRAL_LIMIT_UINT32_MIN                 (  STLSOFT_GEN_UINT32_SUFFIX(0))
#define   STLSOFT_INTEGRAL_LIMIT_UINT32_MAX                 (  STLSOFT_GEN_UINT32_SUFFIX(4294967295))

#define   STLSOFT_INTEGRAL_LIMIT_SINT64_MIN                 (- STLSOFT_GEN_SINT64_SUFFIX(9223372036854775807) - 1)
#define   STLSOFT_INTEGRAL_LIMIT_SINT64_MAX                 (+ STLSOFT_GEN_SINT64_SUFFIX(9223372036854775807) )

#define   STLSOFT_INTEGRAL_LIMIT_UINT64_MIN                 (  STLSOFT_GEN_UINT64_SUFFIX(0) )
#define   STLSOFT_INTEGRAL_LIMIT_UINT64_MAX                 (  STLSOFT_GEN_UINT64_SUFFIX(18446744073709551615) )

/* /////////////////////////////////////////////////////////////////////////
 * obsolete
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#define   STLSOFT_LIMIT_TRAITS__SINT8_MIN                   STLSOFT_INTEGRAL_LIMIT_SINT8_MIN
#define   STLSOFT_LIMIT_TRAITS__SINT8_MAX                   STLSOFT_INTEGRAL_LIMIT_SINT8_MAX

#define   STLSOFT_LIMIT_TRAITS__UINT8_MIN                   STLSOFT_INTEGRAL_LIMIT_UINT8_MIN
#define   STLSOFT_LIMIT_TRAITS__UINT8_MAX                   STLSOFT_INTEGRAL_LIMIT_UINT8_MAX

#define   STLSOFT_LIMIT_TRAITS__SINT16_MIN                  STLSOFT_INTEGRAL_LIMIT_SINT16_MIN
#define   STLSOFT_LIMIT_TRAITS__SINT16_MAX                  STLSOFT_INTEGRAL_LIMIT_SINT16_MAX

#define   STLSOFT_LIMIT_TRAITS__UINT16_MIN                  STLSOFT_INTEGRAL_LIMIT_UINT16_MIN
#define   STLSOFT_LIMIT_TRAITS__UINT16_MAX                  STLSOFT_INTEGRAL_LIMIT_UINT16_MAX

#define   STLSOFT_LIMIT_TRAITS__SINT32_MIN                  STLSOFT_INTEGRAL_LIMIT_SINT32_MIN
#define   STLSOFT_LIMIT_TRAITS__SINT32_MAX                  STLSOFT_INTEGRAL_LIMIT_SINT32_MAX

#define   STLSOFT_LIMIT_TRAITS__UINT32_MIN                  STLSOFT_INTEGRAL_LIMIT_UINT32_MIN
#define   STLSOFT_LIMIT_TRAITS__UINT32_MAX                  STLSOFT_INTEGRAL_LIMIT_UINT32_MAX

#define   STLSOFT_LIMIT_TRAITS__SINT64_MIN                  STLSOFT_INTEGRAL_LIMIT_SINT64_MIN
#define   STLSOFT_LIMIT_TRAITS__SINT64_MAX                  STLSOFT_INTEGRAL_LIMIT_SINT64_MAX

#define   STLSOFT_LIMIT_TRAITS__UINT64_MIN                  STLSOFT_INTEGRAL_LIMIT_UINT64_MIN
#define   STLSOFT_LIMIT_TRAITS__UINT64_MAX                  STLSOFT_INTEGRAL_LIMIT_UINT64_MAX

# define __STLSOFT_GEN_SINT8_SUFFIX(i)                      STLSOFT_GEN_SINT8_SUFFIX(i)
# define __STLSOFT_GEN_UINT8_SUFFIX(i)                      STLSOFT_GEN_UINT8_SUFFIX(i)
# define __STLSOFT_GEN_SINT16_SUFFIX(i)                     STLSOFT_GEN_SINT16_SUFFIX(i)
# define __STLSOFT_GEN_UINT16_SUFFIX(i)                     STLSOFT_GEN_UINT16_SUFFIX(i)
# define __STLSOFT_GEN_SINT32_SUFFIX(i)                     STLSOFT_GEN_SINT32_SUFFIX(i)
# define __STLSOFT_GEN_UINT32_SUFFIX(i)                     STLSOFT_GEN_UINT32_SUFFIX(i)
# define __STLSOFT_GEN_SINT64_SUFFIX(i)                     STLSOFT_GEN_SINT64_SUFFIX(i)
# define __STLSOFT_GEN_UINT64_SUFFIX(i)                     STLSOFT_GEN_UINT64_SUFFIX(i)

# define __STLSOFT_LIMIT_TRAITS__SINT8_MIN                  STLSOFT_LIMIT_TRAITS__SINT8_MIN
# define __STLSOFT_LIMIT_TRAITS__SINT8_MAX                  STLSOFT_LIMIT_TRAITS__SINT8_MAX

# define __STLSOFT_LIMIT_TRAITS__UINT8_MIN                  STLSOFT_LIMIT_TRAITS__UINT8_MIN
# define __STLSOFT_LIMIT_TRAITS__UINT8_MAX                  STLSOFT_LIMIT_TRAITS__UINT8_MAX

# define __STLSOFT_LIMIT_TRAITS__SINT16_MIN                 STLSOFT_LIMIT_TRAITS__SINT16_MIN
# define __STLSOFT_LIMIT_TRAITS__SINT16_MAX                 STLSOFT_LIMIT_TRAITS__SINT16_MAX

# define __STLSOFT_LIMIT_TRAITS__UINT16_MIN                 STLSOFT_LIMIT_TRAITS__UINT16_MIN
# define __STLSOFT_LIMIT_TRAITS__UINT16_MAX                 STLSOFT_LIMIT_TRAITS__UINT16_MAX

# define __STLSOFT_LIMIT_TRAITS__SINT32_MIN                 STLSOFT_LIMIT_TRAITS__SINT32_MIN
# define __STLSOFT_LIMIT_TRAITS__SINT32_MAX                 STLSOFT_LIMIT_TRAITS__SINT32_MAX

# define __STLSOFT_LIMIT_TRAITS__UINT32_MIN                 STLSOFT_LIMIT_TRAITS__UINT32_MIN
# define __STLSOFT_LIMIT_TRAITS__UINT32_MAX                 STLSOFT_LIMIT_TRAITS__UINT32_MAX

# define __STLSOFT_LIMIT_TRAITS__SINT64_MIN                 STLSOFT_LIMIT_TRAITS__SINT64_MIN
# define __STLSOFT_LIMIT_TRAITS__SINT64_MAX                 STLSOFT_LIMIT_TRAITS__SINT64_MAX

# define __STLSOFT_LIMIT_TRAITS__UINT64_MIN                 STLSOFT_LIMIT_TRAITS__UINT64_MIN
# define __STLSOFT_LIMIT_TRAITS__UINT64_MAX                 STLSOFT_LIMIT_TRAITS__UINT64_MAX

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS */

/* ///////////////////////////// end of file //////////////////////////// */

