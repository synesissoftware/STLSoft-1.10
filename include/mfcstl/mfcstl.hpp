/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/mfcstl.hpp
 *
 * Purpose:     Root header for the MFCSTL libraries. Performs various
 *              compiler and platform discriminations, and definitions of
 *              types.
 *
 * Created:     15th January 2002
 * Updated:     22nd January 2024
 *
 * Thanks:      To Cláudio Albuquerque for suggesting the inclusion of
 *              atlstr.h.
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


#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
#define MFCSTL_INCL_MFCSTL_HPP_MFCSTL
#define MFCSTL_INCL_H_MFCSTL    /* Define the old header include guard */

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_HPP_MFCSTL_MAJOR     3
# define MFCSTL_VER_MFCSTL_HPP_MFCSTL_MINOR     5
# define MFCSTL_VER_MFCSTL_HPP_MFCSTL_REVISION  6
# define MFCSTL_VER_MFCSTL_HPP_MFCSTL_EDIT      108
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file mfcstl/mfcstl.hpp
 *
 * \brief [C++; requires MFC library] Root header for the
 * \ref group__project__mfcstl "MFCSTL" project.
 */

/* /////////////////////////////////////////////////////////////////////////
 * MFCSTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * The major version is denoted by the _MFCSTL_VER_MAJOR preprocessor symbol.
 * A changes to the major version component implies that a dramatic change has
 * occurred in the libraries, such that considerable changes to source dependent
 * on previous versions would need to be effected.
 *
 * The minor version is denoted by the _MFCSTL_VER_MINOR preprocessor symbol.
 * Changes to the minor version component imply that a significant change has
 * occurred to the libraries, either in the addition of new functionality or in
 * the destructive change to one or more components such that recomplilation and
 * code change may be necessitated.
 *
 * The revision version is denoted by the _MFCSTL_VER_REVISION preprocessor
 * symbol. Changes to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the changes.
 *
 * In addition to the individual version symbols - _MFCSTL_VER_MAJOR,
 * _MFCSTL_VER_MINOR and _MFCSTL_VER_REVISION - a composite symbol _MFCSTL_VER
 * is defined, where the upper 8 bits are 0, bits 16-23 represent the major
 * component,  bits 8-15 represent the minor component, and bits 0-7 represent
 * the revision component.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _MFCSTL_VER_1_0_1.
 *
 * Thus the symbol _MFCSTL_VER may be compared meaningfully with a specific
 * version symbol, e.g. #if _MFCSTL_VER >= _MFCSTL_VER_1_0_1
 */

/** \def _MFCSTL_VER_MAJOR
 * The major version number of MFCSTL
 */

/** \def _MFCSTL_VER_MINOR
 * The minor version number of MFCSTL
 */

/** \def _MFCSTL_VER_REVISION
 * The revision version number of MFCSTL
 */

/** \def _MFCSTL_VER
 * The current composite version number of MFCSTL
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _MFCSTL_VER_1_0_1      0x00010001  /*!< Version 1.0.1 */
# define _MFCSTL_VER_1_1_1      0x00010101  /*!< Version 1.1.1 */
# define _MFCSTL_VER_1_2_1      0x00010201  /*!< Version 1.2.1 */
# define _MFCSTL_VER_1_2_2      0x00010202  /*!< Version 1.2.2 */
# define _MFCSTL_VER_1_2_3      0x00010203  /*!< Version 1.2.3 */
# define _MFCSTL_VER_1_3_1      0x00010301  /*!< Version 1.3.1 */
# define _MFCSTL_VER_1_3_2      0x00010302  /*!< Version 1.3.2 */
# define _MFCSTL_VER_1_3_3      0x00010303  /*!< Version 1.3.3 */
# define _MFCSTL_VER_1_3_4      0x00010304  /*!< Version 1.3.4 */
# define _MFCSTL_VER_1_3_5      0x00010305  /*!< Version 1.3.5 */
# define _MFCSTL_VER_1_4_1      0x00010401  /*!< Version 1.4.1 */
# define _MFCSTL_VER_1_4_2      0x00010402  /*!< Version 1.4.2 */
# define _MFCSTL_VER_1_4_3      0x00010403  /*!< Version 1.4.3 */
# define _MFCSTL_VER_1_5_1      0x00010501  /*!< Version 1.5.1 (with STLSoft 1.9.1) */
# define _MFCSTL_VER_1_5_2      0x00010502  /*!< Version 1.5.2 (with STLSoft 1.9.10) */
# define _MFCSTL_VER_1_5_3      0x00010503  /*!< Version 1.5.3 (with STLSoft 1.9.25) */
# define _MFCSTL_VER_1_5_4      0x010504ff  /*!< Version 1.5.4 (with STLSoft 1.9.113) */
# define _MFCSTL_VER_1_6_1_B01  0x01060181  /*!< Version 1.6.1 beta 1 (with STLSoft 1.10.1 beta 1) */
# define _MFCSTL_VER_1_6_1_B02  0x01060182  /*!< Version 1.6.1 beta 2 (with STLSoft 1.10.1 beta 26) */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _MFCSTL_VER_MAJOR       1
#define _MFCSTL_VER_MINOR       6
#define _MFCSTL_VER_REVISION    1
#define _MFCSTL_VER             _MFCSTL_VER_1_6_1_B02

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8022 /* Suppresses "'f()' hides virtual function 'g()'" */
# pragma warn -8084 /* Suppresses "Suggest parentheses to clarify precedence in function 'f()'" */
#endif /* compiler */

#ifndef STLSOFT_INCL_H_AFX
# define STLSOFT_INCL_H_AFX
# include <afx.h>        // MFC base header
#endif /* !STLSOFT_INCL_H_AFX */

#if _MFC_VER >= 0x0700
# include <atlstr.h>
#endif /* _MFC_VER */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn .8022 /* Suppresses "'f()' hides virtual function 'g()'" */
# pragma warn .8084 /* Suppresses "Suggest parentheses to clarify precedence in function 'f()'" */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * STLSoft version compatibility check(s)
 */

#if _STLSOFT_VER < 0x010a019a
# error This version of the MFCSTL libraries requires STLSoft version 1.10.1 beta 26, or later
#endif /* _STLSOFT_VER */

/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 *
 * Currently the only compilers supported by the MFCSTL libraries are
 *
 * Borland C++ 5.5, 5.51, 5.6
 * Digital Mars C/C++ 8.26 - 8.32
 * Metrowerks 2.4 & 3.0 (CodeWarrior 7.0 & 8.0)
 * Intel C/C++ 6.0
 * Visual C++ 4.2, 5.0, 6.0, 7.0
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
/* Borland C++ */
# if __BORLANDC__ < 0x0550
#  error Versions of Borland C++ prior to 5.5 are not supported by the MFCSTL libraries
# endif /* __BORLANDC__ */

#elif defined(STLSOFT_COMPILER_IS_DMC)
/* Digital Mars C/C++ */
# if __DMC__ < 0x0826
#  error Versions of Digital Mars C/C++ prior to 8.26 are not supported by the MFCSTL libraries
# endif /* __DMC__ */

#elif defined(STLSOFT_COMPILER_IS_INTEL)
/* Intel C++ */
# if (__INTEL_COMPILER < 600)
#  error Versions of Intel C++ prior to 6.0 are not supported by the MFCSTL libraries
# endif /* __INTEL_COMPILER */

#elif defined(STLSOFT_COMPILER_IS_MWERKS)
/* Metrowerks C++ */
# if (__MWERKS__ & 0xFF00) < 0x2400
#  error Versions of Metrowerks CodeWarrior C++ prior to 7.0 are not supported by the MFCSTL libraries
# endif /* __MWERKS__ */

#elif defined(STLSOFT_COMPILER_IS_MSVC)
/* Visual C++ */
# if _MSC_VER < 1020
#  error Versions of Visual C++ prior to 4.2 are not supported by the MFCSTL libraries
# endif /* _MSC_VER */

#else /* ? compiler */
/* No recognised compiler */
# ifdef _STLSOFT_FORCE_ANY_COMPILER
#  define _MFCSTL_COMPILER_IS_UNKNOWN
#  ifdef STLSOFT_COMPILE_VERBOSE
#   pragma message("Compiler is unknown to MFCSTL")
#  endif /* STLSOFT_COMPILE_VERBOSE */
# else /* ? _STLSOFT_FORCE_ANY_COMPILER */
#  error Currently only Borland C++, Digital Mars C/C++, Intel C/C++, Metrowerks CodeWarrior and Visual C++ compilers are supported by the MFCSTL libraries
# endif /* _STLSOFT_FORCE_ANY_COMPILER */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * contract enforcement
 *
 * The macro mfcstl_assert provides standard debug-mode assert functionality.
 */

/** Defines a runtime assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 */
#define MFCSTL_ASSERT(expr)                 STLSOFT_ASSERT(expr)

/** Defines a runtime assertion, with message
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 * \param msg The literal character string message to be included in the assertion
 */
#define MFCSTL_MESSAGE_ASSERT(msg, expr)    STLSOFT_MESSAGE_ASSERT(msg, expr)

/** Defines a compile-time assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or compilation will fail
 */
#define MFCSTL_STATIC_ASSERT(expr)          STLSOFT_STATIC_ASSERT(expr)



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define mfcstl_assert(expr)                MFCSTL_ASSERT(expr)
# define mfcstl_message_assert(msg, expr)   MFCSTL_MESSAGE_ASSERT(msg, expr)
# define mfcstl_static_assert(expr)         MFCSTL_STATIC_ASSERT(expr)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The MFCSTL components are contained within the mfcstl namespace. This is
 * usually an alias for stlsoft::mfcstl_project,
 *
 * When compilers support namespaces they are defined by default. They can be
 * undefined using a cascasing system, as follows:
 *
 * If STLSOFT_NO_NAMESPACES is defined, then MFCSTL_NO_NAMESPACES is defined.
 *
 * If MFCSTL_NO_NAMESPACES is defined, then MFCSTL_NO_NAMESPACE is defined.
 *
 * If MFCSTL_NO_NAMESPACE is defined, then the MFCSTL constructs are defined
 * in the global scope.
 *
 * If STLSOFT_NO_NAMESPACES, MFCSTL_NO_NAMESPACES and MFCSTL_NO_NAMESPACE are
 * all undefined but the symbol STLSOFT_NO_NAMESPACE is defined (whence the
 * namespace stlsoft does not exist), then the MFCSTL constructs are defined
 * within the mfcstl namespace. The definition matrix is as follows:
 *
 * STLSOFT_NO_NAMESPACE     MFCSTL_NO_NAMESPACE     mfcstl definition
 * ---------------------    --------------------    -----------------
 *  not defined              not defined             = stlsoft::mfcstl_project
 *  not defined              defined                 not defined
 *  defined                  not defined             mfcstl
 *  defined                  defined                 not defined
 *
 *
 *
 * The macro MFCSTL_NS_QUAL() macro can be used to refer to elements in the
 * MFCSTL libraries irrespective of whether they are in the
 * stlsoft::mfcstl_project (or mfcstl) namespace or in the global namespace.
 *
 * Furthermore, some compilers do not support the standard library in the std
 * namespace, so the STLSOFT_NS_QUAL_STD() macro can be used to refer to elements
 * in the standard library irrespective of whether they are in the std namespace
 * or in the global namespace.
 */

/* /////////////////////////////////////
 * obsolete preprocessor symbol detection
 */

#ifdef _MFCSTL_NO_NAMESPACES
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _MFCSTL_NO_NAMESPACES. This symbol is now deprecated, and may be ignored by a future release : instead define MFCSTL_NO_NAMESPACES")
# endif
# if !defined(MFCSTL_NO_NAMESPACES)
#  define MFCSTL_NO_NAMESPACES
# endif /* !MFCSTL_NO_NAMESPACES */
#endif /* _MFCSTL_NO_NAMESPACES */

#ifdef _MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _MFCSTL_NO_NAMESPACE. This symbol is now deprecated, and may be ignored by a future release : instead define MFCSTL_NO_NAMESPACE")
# endif
# if !defined(MFCSTL_NO_NAMESPACE)
#  define MFCSTL_NO_NAMESPACE
# endif /* !MFCSTL_NO_NAMESPACE */
#endif /* _MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////
 * namespace support discrimination
 */

/* No STLSoft namespaces means no MFCSTL namespaces */
#ifdef STLSOFT_NO_NAMESPACES
# define MFCSTL_NO_NAMESPACES
#endif /* STLSOFT_NO_NAMESPACES */

/* No MFCSTL namespaces means no mfcstl namespace */
#ifdef MFCSTL_NO_NAMESPACES
# define MFCSTL_NO_NAMESPACE
#endif /* MFCSTL_NO_NAMESPACES */

#ifdef MFCSTL_NO_NAMESPACES
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_MFCSTL_NO_NAMESPACES)
#   define _MFCSTL_NO_NAMESPACES
#  endif /* !_MFCSTL_NO_NAMESPACES */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* MFCSTL_NO_NAMESPACES */

#ifdef MFCSTL_NO_NAMESPACE
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_MFCSTL_NO_NAMESPACE)
#   define _MFCSTL_NO_NAMESPACE
#  endif /* !_MFCSTL_NO_NAMESPACE */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////
 * declaration '*stl*' namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
/** The \c mfcstl namespace contains all components
 *   in the \ref group__project__mfcstl "MFCSTL" project.
 *
 * By default, the \c mfcstl namespace is actually an alias for
 * the namespace <code>stlsoft::mfcstl_project</code>, which is where all
 * the \ref group__project__mfcstl "MFCSTL" components actually reside. This
 * measure allows all components within the main the
 * \ref group__project__stlsoft "STLSoft" project (which are defined within
 * the \c stlsoft namespace) to be visible to all components
 * "within" the \c mfcstl namespace. (Otherwise, there would be a
 * whole lot of onerous qualification throughout the code of all
 * \ref group__projects "sub-projects".)
 *
 * \note If either/both of the symbols \c STLSOFT_NO_NAMESPACES
 * and \c MFCSTL_NO_NAMESPACE are defined, all
 * \ref group__project__mfcstl "MFCSTL" components will be defined in the
 * global namespace. Conversely, if the \c STLSOFT_NO_NAMESPACE
 * symbol (not to be confused with the
 * \c STLSOFT_NO_NAMESPACES symbol!) is defined - meaning that
 * all \ref group__project__stlsoft "main project" components are to be
 * defined in the global namespace, and \c MFCSTL_NO_NAMESPACE
 * is <b>not</b> defined, then all \ref group__project__mfcstl "MFCSTL"
 * components will be defined within a bona fide \c mfcstl
 * namespace.
 *
 * \note This is a vestige of compatibility with compilers with
 * no (or no sensible) namespace support that is maintained for reasons of
 * backwards compatiblity and because it is, in <i>rare circumstances</i>, a
 * useful facility.
 */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */
namespace stlsoft
{
namespace mfcstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#else
STLSOFT_NS_USING(move_lhs_from_rhs)
#endif /* !MFCSTL_NO_NAMESPACE */

/** \def MFCSTL_NS_QUAL(x)
 * Qualifies with <b>mfcstl::</b> if MFCSTL is using namespaces or, if not, does not qualify
 */

/** \def MFCSTL_NS_USING(x)
 * Declares a using directive (with respect to <b>mfcstl</b>) if MFCSTL is using namespaces or, if not, does nothing
 */

#ifndef MFCSTL_NO_NAMESPACE
# define MFCSTL_NS_QUAL(x)          ::mfcstl::x
# define MFCSTL_NS_USING(x)         using ::mfcstl::x;
#else /* ? MFCSTL_NO_NAMESPACE */
# define MFCSTL_NS_QUAL(x)          x
# define MFCSTL_NS_USING(x)
#endif /* !MFCSTL_NO_NAMESPACE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define mfcstl_ns_qual(x)                                  MFCSTL_NS_QUAL(x)
# define mfcstl_ns_using(x)                                 MFCSTL_NS_USING(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define mfcstl_ns_qual_std(x)                              STLSOFT_NS_QUAL_STD(x)
# define mfcstl_ns_using_std(x)                             STLSOFT_NS_USING_STD(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 *
 * The MFCSTL uses a number of typedefs to aid in compiler-independence in the
 * libraries' main code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

typedef STLSOFT_NS_QUAL(ss_char_a_t)        ms_char_a_t;    //!< Ansi char type
typedef STLSOFT_NS_QUAL(ss_char_w_t)        ms_char_w_t;    //!< Unicode char type
typedef STLSOFT_NS_QUAL(ss_sint8_t)         ms_sint8_t;     //!< 8-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint8_t)         ms_uint8_t;     //!< 8-bit unsigned integer
typedef STLSOFT_NS_QUAL(ss_int16_t)         ms_int16_t;     //!< 16-bit integer
typedef STLSOFT_NS_QUAL(ss_sint16_t)        ms_sint16_t;    //!< 16-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint16_t)        ms_uint16_t;    //!< 16-bit unsigned integer
typedef STLSOFT_NS_QUAL(ss_int32_t)         ms_int32_t;     //!< 32-bit integer
typedef STLSOFT_NS_QUAL(ss_sint32_t)        ms_sint32_t;    //!< 32-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint32_t)        ms_uint32_t;    //!< 32-bit unsigned integer
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef STLSOFT_NS_QUAL(ss_int64_t)         ms_int64_t;     //!< 64-bit integer
typedef STLSOFT_NS_QUAL(ss_sint64_t)        ms_sint64_t;    //!< 64-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint64_t)        ms_uint64_t;    //!< 64-bit unsigned integer
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef STLSOFT_NS_QUAL(ss_int_t)           ms_int_t;       //!< integer
typedef STLSOFT_NS_QUAL(ss_sint_t)          ms_sint_t;      //!< signed integer
typedef STLSOFT_NS_QUAL(ss_uint_t)          ms_uint_t;      //!< unsigned integer
typedef STLSOFT_NS_QUAL(ss_long_t)          ms_long_t;      //!< long
typedef STLSOFT_NS_QUAL(ss_bool_t)          ms_bool_t;      //!< bool
typedef DWORD                               ms_dword_t;     //!< dword
typedef STLSOFT_NS_QUAL(ss_size_t)          ms_size_t;      //!< size
typedef STLSOFT_NS_QUAL(ss_ptrdiff_t)       ms_ptrdiff_t;   //!< ptr diff
typedef STLSOFT_NS_QUAL(ss_streampos_t)     ms_streampos_t; //!< streampos
typedef STLSOFT_NS_QUAL(ss_streamoff_t)     ms_streamoff_t; //!< streamoff

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * values
 *
 * Since the boolean type may not be supported natively on all compilers, the
 * values of true and false may also not be provided. Hence the values of
 * ms_true_v and ms_false_v are defined, and are used in all code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#define ms_true_v                                           ss_true_v
#define ms_false_v                                          ss_false_v

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/* /////////////////////////////////////////////////////////////////////////
 * code modification macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/* Exception signatures. */
#define mfcstl_throw_0()                                stlsoft_throw_0()
#define mfcstl_throw_1(x1)                              stlsoft_throw_1(x1)
#define mfcstl_throw_2(x1, x2)                          stlsoft_throw_2(x1, x2)
#define mfcstl_throw_3(x1, x2, x3)                      stlsoft_throw_3(x1, x2, x3)
#define mfcstl_throw_4(x1, x2, x3, x4)                  stlsoft_throw_4(x1, x2, x3, x4)
#define mfcstl_throw_5(x1, x2, x3, x4, x5)              stlsoft_throw_5(x1, x2, x3, x4, x5)
#define mfcstl_throw_6(x1, x2, x3, x4, x5, x6)          stlsoft_throw_6(x1, x2, x3, x4, x5, x6)
#define mfcstl_throw_7(x1, x2, x3, x4, x5, x6, x7)      stlsoft_throw_7(x1, x2, x3, x4, x5, x6, x7)
#define mfcstl_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)  stlsoft_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_NUM_ELEMENTS(ar)                        STLSOFT_NUM_ELEMENTS(ar)
# define mfcstl_num_elements(ar)                        MFCSTL_NUM_ELEMENTS(ar)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** [DEPRECATED] Destroys the given instance \c p of the given type (\c t and \c type)
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_DESTROY_INSTANCE().
 */
#define mfcstl_destroy_instance(t, type, p)             STLSOFT_DESTROY_INSTANCE(t, type, p)

/** [DEPRECATED] Generates an opaque type with the name \c _htype
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_GEN_OPAQUE().
 */
#define mfcstl_gen_opaque(htype)                        STLSOFT_GEN_OPAQUE(htype)

/* ////////////////////////////////////////////////////////////////////// */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace mfcstl */
# else
} /* namespace mfcstl_project */
} /* namespace stlsoft */
namespace mfcstl = ::stlsoft::mfcstl_project;
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */

/* ///////////////////////////// end of file //////////////////////////// */

