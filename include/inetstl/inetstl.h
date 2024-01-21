/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/inetstl.h
 *
 * Purpose:     Root header for the InetSTL libraries. Performs compiler
 *              and platform discriminations, and definitions of types.
 *
 * Created:     24th April 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


#ifndef INETSTL_INCL_INETSTL_H_INETSTL
#define INETSTL_INCL_INETSTL_H_INETSTL
#define INETSTL_INCL_H_INETSTL

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_H_INETSTL_MAJOR    3
# define INETSTL_VER_INETSTL_H_INETSTL_MINOR    10
# define INETSTL_VER_INETSTL_H_INETSTL_REVISION 3
# define INETSTL_VER_INETSTL_H_INETSTL_EDIT     570
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file inetstl/inetstl.h
 *
 * \brief [C, C++] Root header for the
 * \ref group__project__inetstl "InetSTL" project.
 */

/* /////////////////////////////////////////////////////////////////////////
 * InetSTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the _INETSTL_VER_MAJOR preprocessor symbol.
 * A changes to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the _INETSTL_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the _INETSTL_VER_REVISION preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - _INETSTL_VER_MAJOR,
 * _INETSTL_VER_MINOR and _INETSTL_VER_REVISION - a composite symbol _INETSTL_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _INETSTL_VER_1_0_1.
 *
 * Thus the symbol _INETSTL_VER may be compared meaningfully with a specific
 * version symbol, e.g. #if _INETSTL_VER >= _INETSTL_VER_1_0_1
 */

/** \def _INETSTL_VER_MAJOR
 * The major version number of InetSTL
 */

/** \def _INETSTL_VER_MINOR
 * The minor version number of InetSTL
 */

/** \def _INETSTL_VER_REVISION
 * The revision version number of InetSTL
 */

/** \def _INETSTL_VER
 * The current composite version number of InetSTL
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _INETSTL_VER_1_0_1      0x00010001  /*!< Version 1.0.1 */
# define _INETSTL_VER_1_0_2      0x00010002  /*!< Version 1.0.2 */
# define _INETSTL_VER_1_1_1      0x00010101  /*!< Version 1.1.1 */
# define _INETSTL_VER_1_1_2      0x00010102  /*!< Version 1.1.2 */
# define _INETSTL_VER_1_1_3      0x00010103  /*!< Version 1.1.3 */
# define _INETSTL_VER_1_1_4      0x00010104  /*!< Version 1.1.4 */
# define _INETSTL_VER_1_2_1      0x00010201  /*!< Version 1.2.1 (with STLSoft 1.9.1) */
# define _INETSTL_VER_1_2_2      0x00010202  /*!< Version 1.2.2 (with STLSoft 1.9.25) */
# define _INETSTL_VER_1_2_3      0x010203ff  /*!< Version 1.2.3 (with STLSoft 1.9.46) */
# define _INETSTL_VER_1_3_1      0x010301ff  /*!< Version 1.3.1 (with STLSoft 1.9.79) */
# define _INETSTL_VER_1_3_2      0x010302ff  /*!< Version 1.3.2 (with STLSoft 1.9.80) */
# define _INETSTL_VER_1_3_3      0x010303ff  /*!< Version 1.3.3 (with STLSoft 1.9.86) */
# define _INETSTL_VER_1_3_4      0x010304ff  /*!< Version 1.3.4 (with STLSoft 1.9.91) */
# define _INETSTL_VER_1_3_5      0x010305ff  /*!< Version 1.3.5 (with STLSoft 1.9.92) */
# define _INETSTL_VER_1_3_6      0x010306ff  /*!< Version 1.3.6 (with STLSoft 1.9.113) */
# define _INETSTL_VER_1_3_7      0x010307ff  /*!< Version 1.3.7 (with STLSoft 1.9.119) */
# define _INETSTL_VER_1_3_8      0x010308ff  /*!< Version 1.3.8 (with STLSoft 1.9.121) */
# define _INETSTL_VER_1_4_1_B01  0x01040181  /*!< Version 1.4.1 beta 1 (with STLSoft 1.10.1 beta 1) */
# define _INETSTL_VER_1_4_1_B02  0x01040182  /*!< Version 1.4.1 beta 2 (with STLSoft 1.10.1 beta 10) */
# define _INETSTL_VER_1_4_1_B03  0x01040183  /*!< Version 1.4.1 beta 3 (with STLSoft 1.10.1 beta 26) */
# define _INETSTL_VER_1_4_1      0x010401ff  /*!< Version 1.4.1 (with STLSoft 1.10.3) */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _INETSTL_VER_MAJOR       1
#define _INETSTL_VER_MINOR       4
#define _INETSTL_VER_REVISION    1
#define _INETSTL_VER             _INETSTL_VER_1_4_1

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Strict */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if 1 &&\
     !defined(STRICT) &&\
     !defined(_INETSTL_NO_STRICT) &&\
     !defined(NO_STRICT) &&\
     1
#  ifdef _INETSTL_STRICT
#   define STRICT                                           1
#  endif /* _INETSTL_STRICT */
# endif /* !NO_STRICT && !_INETSTL_NO_STRICT && !STRICT */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if 0
#elif defined(unix) || \
      defined(UNIX) || \
      defined(__unix__) || \
      defined(__unix)

# define INETSTL_OS_IS_UNIX
#elif defined(WIN32) || \
      defined(WIN64)

# define INETSTL_OS_IS_WINDOWS

# ifndef STLSOFT_INCL_H_WINDOWS
#  define STLSOFT_INCL_H_WINDOWS
#  include <windows.h>
# endif /* !STLSOFT_INCL_H_WINDOWS */
# ifndef STLSOFT_INCL_H_WININET
#  define STLSOFT_INCL_H_WININET
#  include <wininet.h>
# endif /* !STLSOFT_INCL_H_WININET */

#else /* ? OS */

# error Platform not (currently) supported
#endif /* OS */


/* /////////////////////////////////////////////////////////////////////////
 * STLSoft version compatibility check(s)
 */

#if _STLSOFT_VER < 0x010a019a
# error This version of the InetSTL libraries requires STLSoft version 1.10.1 beta 26, or later
#endif /* _STLSOFT_VER */

/* /////////////////////////////////////////////////////////////////////////
 * sanity checks
 */

/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 *
 * Currently the only compilers supported by the InetSTL libraries are
 *
 * Borland C++ 5.5, 5.51, 5.6
 * Clang
 * Digital Mars C/C++ 8.26 - 8.32
 * GCC 2.95+
 * Metrowerks 2.4 & 3.0 (CodeWarrior 7.0 & 8.0)
 * Intel C/C++ 6.0 & 7.0
 * Visual C++ 4.2, 5.0, 6.0, 7.0
 * Watcom C/C++ 11.0
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
/* Borland C++ */
# if __BORLANDC__ < 0x0550
#  error Versions of Borland C++ prior to 5.5 are not supported by the InetSTL libraries
# endif /* __BORLANDC__ */

#elif defined(STLSOFT_COMPILER_IS_CLANG)

#elif defined(STLSOFT_COMPILER_IS_COMO)
/* Comeau C++ */
# if __COMO_VERSION__ < 4300
#  error Versions of Comeau C++ prior to 4.3 are not supported by the InetSTL libraries
# endif /* __COMO_VERSION__ */

#elif defined(STLSOFT_COMPILER_IS_DMC)
/* Digital Mars C/C++ */
# if __DMC__ < 0x0826
#  error Versions of Digital Mars C/C++ prior to 8.26 are not supported by the InetSTL libraries
# endif /* __DMC__ */

#elif defined(STLSOFT_COMPILER_IS_GCC)
/* GNU C/C++ */
# if __GNUC__ < 2 || \
     (  __GNUC__ == 2 && \
        __GNUC_MINOR__ < 95)
#  error Versions of GNU C/C++ prior to 2.95 are not supported by the InetSTL libraries
# endif /* __GNUC__ */

#elif defined(STLSOFT_COMPILER_IS_INTEL)
/* Intel C++ */
# if (__INTEL_COMPILER < 600)
#  error Versions of Intel C++ prior to 6.0 are not supported by the InetSTL libraries
# endif /* __INTEL_COMPILER */

#elif defined(STLSOFT_COMPILER_IS_MWERKS)
/* Metrowerks C++ */
# if (__MWERKS__ & 0xFF00) < 0x2400
#  error Versions of Metrowerks CodeWarrior C++ prior to 7.0 are not supported by the InetSTL libraries
# endif /* __MWERKS__ */

#elif defined(STLSOFT_COMPILER_IS_MSVC)
/* Visual C++ */
# if _MSC_VER < 1020
#  error Versions of Visual C++ prior to 4.2 are not supported by the InetSTL libraries
# endif /* _MSC_VER */

#elif defined(STLSOFT_COMPILER_IS_VECTORC)
/* VectorC C/C++ */

#elif defined(STLSOFT_COMPILER_IS_WATCOM)
/* Watcom C/C++ */
# if (__WATCOMC__ < 1200)
#  error Versions of Watcom C/C++ prior to 12.0 are not supported by the InetSTL libraries
# endif /* __WATCOMC__ */

#else /* ? compiler */
/* No recognised compiler */
# ifdef _STLSOFT_FORCE_ANY_COMPILER
#  define _INETSTL_COMPILER_IS_UNKNOWN
#  ifdef STLSOFT_COMPILE_VERBOSE
#   pragma message("Compiler is unknown to InetSTL")
#  endif /* STLSOFT_COMPILE_VERBOSE */
# else /* ? _STLSOFT_FORCE_ANY_COMPILER */
#  error Currently only Borland C++, CLang, Digital Mars C/C++, GCC, Intel C/C++, Metrowerks CodeWarrior and Visual C++ compilers are supported by the InetSTL libraries
# endif /* _STLSOFT_FORCE_ANY_COMPILER */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * contract enforcement
 *
 * The macro inetstl_assert provides standard debug-mode assert functionality.
 */

/** Defines a runtime assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 */
#define INETSTL_ASSERT(expr)                STLSOFT_ASSERT(expr)

/** Defines a runtime assertion, with message
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 * \param msg The literal character string message to be included in the assertion
 */
#define INETSTL_MESSAGE_ASSERT(msg, expr)   STLSOFT_MESSAGE_ASSERT(msg, expr)

/** Defines a compile-time assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or compilation will fail
 */
#define INETSTL_STATIC_ASSERT(expr)         STLSOFT_STATIC_ASSERT(expr)



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define inetstl_assert(expr)               INETSTL_ASSERT(expr)
# define inetstl_message_assert(msg, expr)  INETSTL_MESSAGE_ASSERT(msg, expr)
# define inetstl_static_assert(expr)        INETSTL_STATIC_ASSERT(expr)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The InetSTL components are contained within the inetstl namespace. This is
 * usually an alias for stlsoft::inetstl_project,
 *
 * When compilers support namespaces they are defined by default. They can be
 * undefined using a cascasing system, as follows:
 *
 * If STLSOFT_NO_NAMESPACES is defined, then INETSTL_NO_NAMESPACES is defined.
 *
 * If INETSTL_NO_NAMESPACES is defined, then INETSTL_NO_NAMESPACE is defined.
 *
 * If INETSTL_NO_NAMESPACE is defined, then the InetSTL constructs are defined
 * in the global scope.
 *
 * If STLSOFT_NO_NAMESPACES, INETSTL_NO_NAMESPACES and INETSTL_NO_NAMESPACE are
 * all undefined but the symbol STLSOFT_NO_NAMESPACE is defined (whence the
 * namespace stlsoft does not exist), then the InetSTL constructs are defined
 * within the inetstl namespace. The definition matrix is as follows:
 *
 * STLSOFT_NO_NAMESPACE     INETSTL_NO_NAMESPACE    inetstl definition
 * ---------------------    --------------------    -----------------
 *  not defined              not defined             = stlsoft::inetstl_project
 *  not defined              defined                 not defined
 *  defined                  not defined             inetstl
 *  defined                  defined                 not defined
 *
 *
 *
 * The macro inetstl_ns_qual() macro can be used to refer to elements in the
 * InetSTL libraries irrespective of whether they are in the
 * stlsoft::inetstl_project (or inetstl) namespace or in the global namespace.
 *
 * Furthermore, some compilers do not support the standard library in the std
 * namespace, so the STLSOFT_NS_QUAL_STD() macro can be used to refer to elements
 * in the standard library irrespective of whether they are in the std namespace
 * or in the global namespace.
 */

/* /////////////////////////////////////
 * obsolete preprocessor symbol detection
 */

#ifdef _INETSTL_NO_NAMESPACES
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _INETSTL_NO_NAMESPACES. This symbol is now deprecated, and may be ignored by a future release : instead define INETSTL_NO_NAMESPACES")
# endif
# if !defined(INETSTL_NO_NAMESPACES)
#  define INETSTL_NO_NAMESPACES
# endif /* !INETSTL_NO_NAMESPACES */
#endif /* _INETSTL_NO_NAMESPACES */

#ifdef _INETSTL_NO_NAMESPACE
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _INETSTL_NO_NAMESPACE. This symbol is now deprecated, and may be ignored by a future release : instead define INETSTL_NO_NAMESPACE")
# endif
# if !defined(INETSTL_NO_NAMESPACE)
#  define INETSTL_NO_NAMESPACE
# endif /* !INETSTL_NO_NAMESPACE */
#endif /* _INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////
 * namespace support discrimination
 */

/* No STLSoft namespaces means no InetSTL namespaces */
#ifdef STLSOFT_NO_NAMESPACES
# define INETSTL_NO_NAMESPACES
#endif /* STLSOFT_NO_NAMESPACES */

/* No InetSTL namespaces means no inetstl namespace */
#ifdef INETSTL_NO_NAMESPACES
# define INETSTL_NO_NAMESPACE
#endif /* INETSTL_NO_NAMESPACES */

#ifdef INETSTL_NO_NAMESPACES
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_INETSTL_NO_NAMESPACES)
#   define _INETSTL_NO_NAMESPACES
#  endif /* !_INETSTL_NO_NAMESPACES */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* INETSTL_NO_NAMESPACES */

#ifdef INETSTL_NO_NAMESPACE
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_INETSTL_NO_NAMESPACE)
#   define _INETSTL_NO_NAMESPACE
#  endif /* !_INETSTL_NO_NAMESPACE */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////
 * declaration '*stl*' namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
/** The \c inetstl namespace contains all components
 *   in the \ref group__project__inetstl "InetSTL" project.
 *
 * By default, the \c inetstl namespace is actually an alias for
 * the namespace <code>stlsoft::inetstl_project</code>, which is where all
 * the \ref group__project__inetstl "InetSTL" components actually reside. This
 * measure allows all components within the main the
 * \ref group__project__stlsoft "STLSoft" project (which are defined within
 * the \c stlsoft namespace) to be visible to all components
 * "within" the \c inetstl namespace. (Otherwise, there would be a
 * whole lot of onerous qualification throughout the code of all
 * \ref group__projects "sub-projects".)
 *
 * \note If either/both of the symbols \c STLSOFT_NO_NAMESPACES
 * and \c INETSTL_NO_NAMESPACE are defined, all
 * \ref group__project__inetstl "InetSTL" components will be defined in the
 * global namespace. Conversely, if the \c STLSOFT_NO_NAMESPACE
 * symbol (not to be confused with the
 * \c STLSOFT_NO_NAMESPACES symbol!) is defined - meaning that
 * all \ref group__project__stlsoft "main project" components are to be
 * defined in the global namespace, and \c INETSTL_NO_NAMESPACE
 * is <b>not</b> defined, then all \ref group__project__inetstl "InetSTL"
 * components will be defined within a bona fide \c inetstl
 * namespace.
 *
 * \note This is a vestige of compatibility with compilers with
 * no (or no sensible) namespace support that is maintained for reasons of
 * backwards compatiblity and because it is, in <i>rare circumstances</i>, a
 * useful facility.
 */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */
namespace stlsoft
{
namespace inetstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#else
STLSOFT_NS_USING(move_lhs_from_rhs)
#endif /* !INETSTL_NO_NAMESPACE */

/** \def INETSTL_NS_QUAL(x)
 * Qualifies with <b>inetstl::</b> if InetSTL is using namespaces or, if not, does not qualify
 */

/** \def INETSTL_NS_USING(x)
 * Declares a using directive (with respect to <b>inetstl</b>) if InetSTL is using namespaces or, if not, does nothing
 */

#ifndef INETSTL_NO_NAMESPACE
# define INETSTL_NS_QUAL(x)          ::inetstl::x
# define INETSTL_NS_USING(x)         using ::inetstl::x;
#else /* ? INETSTL_NO_NAMESPACE */
# define INETSTL_NS_QUAL(x)          x
# define INETSTL_NS_USING(x)
#endif /* !INETSTL_NO_NAMESPACE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define inetstl_ns_qual(x)                                 INETSTL_NS_QUAL(x)
# define inetstl_ns_using(x)                                INETSTL_NS_USING(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define inetstl_ns_qual_std(x)                             STLSOFT_NS_QUAL_STD(x)
# define inetstl_ns_using_std(x)                            STLSOFT_NS_USING_STD(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 *
 * The InetSTL uses a number of typedefs to aid in compiler-independence in the
 * libraries' main code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

typedef STLSOFT_NS_QUAL(ss_char_a_t)        is_char_a_t;    /*!< Ansi char type */
typedef STLSOFT_NS_QUAL(ss_char_w_t)        is_char_w_t;    /*!< Unicode char type */
typedef STLSOFT_NS_QUAL(ss_sint8_t)         is_sint8_t;     /*!< 8-bit signed integer */
typedef STLSOFT_NS_QUAL(ss_uint8_t)         is_uint8_t;     /*!< 8-bit unsigned integer */
typedef STLSOFT_NS_QUAL(ss_int16_t)         is_int16_t;     /*!< 16-bit integer */
typedef STLSOFT_NS_QUAL(ss_sint16_t)        is_sint16_t;    /*!< 16-bit signed integer */
typedef STLSOFT_NS_QUAL(ss_uint16_t)        is_uint16_t;    /*!< 16-bit unsigned integer */
typedef STLSOFT_NS_QUAL(ss_int32_t)         is_int32_t;     /*!< 32-bit integer */
typedef STLSOFT_NS_QUAL(ss_sint32_t)        is_sint32_t;    /*!< 32-bit signed integer */
typedef STLSOFT_NS_QUAL(ss_uint32_t)        is_uint32_t;    /*!< 32-bit unsigned integer */
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
 typedef STLSOFT_NS_QUAL(ss_int64_t)        is_int64_t;     /*!< 64-bit integer */
 typedef STLSOFT_NS_QUAL(ss_sint64_t)       is_sint64_t;    /*!< 64-bit signed integer */
 typedef STLSOFT_NS_QUAL(ss_uint64_t)       is_uint64_t;    /*!< 64-bit unsigned integer */
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef STLSOFT_NS_QUAL(ss_int_t)           is_int_t;       /*!< integer */
typedef STLSOFT_NS_QUAL(ss_sint_t)          is_sint_t;      /*!< signed integer */
typedef STLSOFT_NS_QUAL(ss_uint_t)          is_uint_t;      /*!< unsigned integer */
typedef STLSOFT_NS_QUAL(ss_long_t)          is_long_t;      /*!< long */
typedef STLSOFT_NS_QUAL(ss_byte_t)          is_byte_t;      /*!< byte type */
#ifdef __cplusplus
typedef STLSOFT_NS_QUAL(ss_bool_t)          is_bool_t;      /*!< Boolean type */
#endif /* __cplusplus */
# ifdef INETSTL_OS_IS_WINDOWS
typedef DWORD                               is_dword_t;     /*!< dword */
# endif /* INETSTL_OS_IS_WINDOWS */
typedef STLSOFT_NS_QUAL(ss_size_t)          is_size_t;      /*!< size */
typedef STLSOFT_NS_QUAL(ss_ptrdiff_t)       is_ptrdiff_t;   /*!< ptr diff */
typedef STLSOFT_NS_QUAL(ss_streampos_t)     is_streampos_t; /*!< streampos */
typedef STLSOFT_NS_QUAL(ss_streamoff_t)     is_streamoff_t; /*!< streamoff */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef INETSTL_NO_NAMESPACE
typedef is_char_a_t         char_a_t;           /*!< Ansi char type */
typedef is_char_w_t         char_w_t;           /*!< Unicode char type */
typedef is_sint8_t          sint8_t;            /*!< 8-bit signed integer */
typedef is_uint8_t          uint8_t;            /*!< 8-bit unsigned integer */
typedef is_int16_t          int16_t;            /*!< 16-bit integer */
typedef is_sint16_t         sint16_t;           /*!< 16-bit signed integer */
typedef is_uint16_t         uint16_t;           /*!< 16-bit unsigned integer */
typedef is_int32_t          int32_t;            /*!< 32-bit integer */
typedef is_sint32_t         sint32_t;           /*!< 32-bit signed integer */
typedef is_uint32_t         uint32_t;           /*!< 32-bit unsigned integer */
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
 typedef is_int64_t         int64_t;            /*!< 64-bit integer */
 typedef is_sint64_t        sint64_t;           /*!< 64-bit signed integer */
 typedef is_uint64_t        uint64_t;           /*!< 64-bit unsigned integer */
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef is_int_t            int_t;              /*!< integer */
typedef is_sint_t           sint_t;             /*!< signed integer */
typedef is_uint_t           uint_t;             /*!< unsigned integer */
typedef is_long_t           long_t;             /*!< long integer */
typedef is_byte_t           byte_t;             /*!< byte type */
typedef is_bool_t           bool_t;             /*!< Boolean type */
# ifdef INETSTL_OS_IS_WINDOWS
typedef is_dword_t          dword_t;            /*!< dword */
# endif /* INETSTL_OS_IS_WINDOWS */
# if !defined(STLSOFT_COMPILER_IS_DMC)
typedef is_streampos_t      streampos_t;        /*!< streampos */
typedef is_streamoff_t      streamoff_t;        /*!< streamoff */
# endif /* compiler */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#if 0
#elif 0 || \
      defined(_WIN32) || \
      defined(WIN32) || \
      defined(WIN64) || \
      0

/** \def INETSTL_CONST_MAX_PATH
 *
 */
# if 0
# elif defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

#  define INETSTL_CONST_MAX_PATH                            (260)
# elif defined(_MAX_PATH)

#  define INETSTL_CONST_MAX_PATH                            _MAX_PATH
# elif defined(__CYGWIN__) || \
       defined(__MINGW32__) || \
       defined(__MINGW64__)

#  define INETSTL_CONST_MAX_PATH                            (260)
# else

#  error _MAX_PATH not defined, and not CygWin compiler
# endif

# ifdef __cplusplus

/** C++ constant equivalent to \ref INETSTL_CONST_MAX_PATH.
 */
const is_size_t CONST_MAX_PATH          =   INETSTL_CONST_MAX_PATH;

# endif /* __cplusplus */
#endif

/* /////////////////////////////////////////////////////////////////////////
 * values
 *
 * Since the boolean type may not be supported natively on all compilers, the
 * values of true and false may also not be provided. Hence the values of
 * is_true_v and is_false_v are defined, and are used in all code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#define is_true_v                                           ss_true_v
#define is_false_v                                          ss_false_v

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * code modification macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/* Exception signatures. */
# define inetstl_throw_0()                               stlsoft_throw_0()
# define inetstl_throw_1(x1)                             stlsoft_throw_1(x1)
# define inetstl_throw_2(x1, x2)                         stlsoft_throw_2(x1, x2)
# define inetstl_throw_3(x1, x2, x3)                     stlsoft_throw_3(x1, x2, x3)
# define inetstl_throw_4(x1, x2, x3, x4)                 stlsoft_throw_4(x1, x2, x3, x4)
# define inetstl_throw_5(x1, x2, x3, x4, x5)             stlsoft_throw_5(x1, x2, x3, x4, x5)
# define inetstl_throw_6(x1, x2, x3, x4, x5, x6)         stlsoft_throw_6(x1, x2, x3, x4, x5, x6)
# define inetstl_throw_7(x1, x2, x3, x4, x5, x6, x7)     stlsoft_throw_7(x1, x2, x3, x4, x5, x6, x7)
# define inetstl_throw_8(x1, x2, x3, x4, x5, x6, x7, x8) stlsoft_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_NUM_ELEMENTS(ar)                        STLSOFT_NUM_ELEMENTS(ar)
# define inetstl_num_elements(ar)                        INETSTL_NUM_ELEMENTS(ar)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** [DEPRECATED] Destroys the given instance \c p of the given type (\c t and \c type)
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_DESTROY_INSTANCE().
 */
#define inetstl_destroy_instance(t, type, p)             STLSOFT_DESTROY_INSTANCE(t, type, p)

/** [DEPRECATED] Generates an opaque type with the name \c _htype
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_GEN_OPAQUE().
 */
#define inetstl_gen_opaque(htype)                        STLSOFT_GEN_OPAQUE(htype)

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace inetstl */
# else
} /* namespace inetstl_project */
} /* namespace stlsoft */
namespace inetstl = ::stlsoft::inetstl_project;
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */

/* ///////////////////////////// end of file //////////////////////////// */

