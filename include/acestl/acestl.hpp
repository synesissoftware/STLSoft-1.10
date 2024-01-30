/* /////////////////////////////////////////////////////////////////////////
 * File:        acestl/acestl.hpp
 *
 * Purpose:     Root header for the ACESTL libraries. Performs compiler
 *              and platform discriminations, and definitions of types.
 *
 * Created:     15th September 2004
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


#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
#define ACESTL_INCL_ACESTL_HPP_ACESTL

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_HPP_ACESTL_MAJOR     1
# define ACESTL_VER_ACESTL_HPP_ACESTL_MINOR     8
# define ACESTL_VER_ACESTL_HPP_ACESTL_REVISION  2
# define ACESTL_VER_ACESTL_HPP_ACESTL_EDIT      54
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file acestl/acestl.hpp
 *
 * \brief [C++] Root header for the
 * \ref group__project__acestl "ACESTL" project.
 */

/* /////////////////////////////////////////////////////////////////////////
 * ACESTL version
 *
 * The libraries version information is comprised of major, minor and revision
 * components.
 *
 * Each release of the libraries will bear a different version, and that version
 * will also have its own symbol: Version 1.0.1 specifies _ACESTL_VER_1_0_1.
 */

/** \def _ACESTL_VER_MAJOR
 * The major version number of ACESTL
 *
 * A change to the major version component implies that a dramatic change
 * has occurred in the libraries, such that considerable changes to source
 * dependent on previous versions would need to be effected.
 */

/** \def _ACESTL_VER_MINOR
 * The minor version number of ACESTL
 *
 * A change to the minor version component imply that a significant change
 * has occurred to the libraries, either in the addition of new functionality
 * or in the destructive change to one or more components such that
 * recompilation and code change may be necessitated.
 */

/** \def _ACESTL_VER_REVISION
 * The revision version number of ACESTL
 *
 * A change to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the
 * changes.
 */

/** \def _ACESTL_VER
 * The current composite version number of ACESTL
 *
 * Thus the symbol _ACESTL_VER may be compared meaningfully with a specific
 * version symbol, e.g.# if _ACESTL_VER >= _ACESTL_VER_1_0_1
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _ACESTL_VER_0_9_1     0x00000901  /*!< Version 0.9.1 */
# define _ACESTL_VER_1_0_1     0x00010001  /*!< Version 1.0.1 */
# define _ACESTL_VER_1_0_2     0x00010002  /*!< Version 1.0.2 */
# define _ACESTL_VER_1_0_3     0x00010003  /*!< Version 1.0.3 */
# define _ACESTL_VER_1_0_4     0x00010004  /*!< Version 1.0.4 */
# define _ACESTL_VER_1_1_1     0x00010101  /*!< Version 1.1.1 (STLSoft 1.9.1) */
# define _ACESTL_VER_1_1_2     0x00010102  /*!< Version 1.1.2 (STLSoft 1.9.25) */
# define _ACESTL_VER_1_2_1_B01 0x01020181  /*!< Version 1.2.1 beta 1 (STLSoft 1.10.1 b1) */
# define _ACESTL_VER_1_2_1_B02 0x01020182  /*!< Version 1.2.1 beta 2 (STLSoft 1.10.1 beta 26) */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _ACESTL_VER_MAJOR      1
#define _ACESTL_VER_MINOR      1
#define _ACESTL_VER_REVISION   1
#define _ACESTL_VER            _ACESTL_VER_1_2_1_B02

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_ACE_H_LOG_MSG
# define STLSOFT_INCL_ACE_H_LOG_MSG
# include <ace/Log_Msg.h>
#endif /* !STLSOFT_INCL_ACE_H_LOG_MSG */
#ifndef STLSOFT_INCL_ACE_H_VERSION
# define STLSOFT_INCL_ACE_H_VERSION
# include <ace/Version.h>
#endif /* !STLSOFT_INCL_ACE_H_VERSION */

/* Intel is super pernickety about conversions, so we need to bring out the union_cast. */
#if defined(STLSOFT_COMPILER_IS_INTEL)
# ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_UNION_CAST
#  include <stlsoft/conversion/union_cast.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_UNION_CAST */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * STLSoft version compatibility check(s)
 */

#if _STLSOFT_VER < 0x010a019a
# error This version of the ACESTL libraries requires STLSoft version 1.10.1 beta 26, or later
#endif /* _STLSOFT_VER */

/* /////////////////////////////////////////////////////////////////////////
 * ACE version
 */

/** \def ACESTL_ACE_VERSION
 *
 * Composite version describing the version of ACE being compiled. The
 * upper 16 bits correspond to ACE_MAJOR_VERSION. The lower 16 bits
 * correspond to ACE_MINOR_VERSION.
 */
#define ACESTL_ACE_VERSION  ((ACE_MAJOR_VERSION << 16) | ACE_MINOR_VERSION)

/* /////////////////////////////////////////////////////////////////////////
 * Proper C++ casting
 */

#ifdef __cplusplus
# ifdef ACE_WIN32
#  undef     ACE_INVALID_HANDLE
#  if defined(STLSOFT_COMPILER_IS_INTEL)
#   define    ACE_INVALID_HANDLE                            STLSOFT_NS_QUAL(union_cast)<HANDLE>(-1)
#  else /* ? compiler */
#   define    ACE_INVALID_HANDLE                            reinterpret_cast<HANDLE>(-1)
#  endif /* compiler */
# endif /* ACE_WIN32 */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 *
 * Currently the only compilers supported by the ACESTL libraries are
 *
 */

/* /////////////////////////////////////////////////////////////////////////
 * contract enforcement
 *
 * The macro acestl_assert provides standard debug-mode assert functionality.
 */

/** Defines a runtime assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 */
#define ACESTL_ASSERT(expr)                STLSOFT_ASSERT(expr)

/** Defines a runtime assertion, with message
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or an assertion will be fired
 * \param msg The literal character string message to be included in the assertion
 */
#define ACESTL_MESSAGE_ASSERT(msg, expr)   STLSOFT_MESSAGE_ASSERT(msg, expr)

/** Defines a compile-time assertion
 *
 * \ingroup group__library__ContractEnforcement
 *
 * \param expr Must be non-zero, or compilation will fail
 */
#define ACESTL_STATIC_ASSERT(expr)         STLSOFT_STATIC_ASSERT(expr)



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define acestl_assert(expr)                ACESTL_ASSERT(expr)
# define acestl_message_assert(msg, expr)   ACESTL_MESSAGE_ASSERT(msg, expr)
# define acestl_static_assert(expr)         ACESTL_STATIC_ASSERT(expr)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The ACESTL components are contained within the acestl namespace. This is
 * usually an alias for stlsoft::acestl_project,
 *
 * When compilers support namespaces they are defined by default. They can be
 * undefined using a cascasing system, as follows:
 *
 * If STLSOFT_NO_NAMESPACES is defined, then ACESTL_NO_NAMESPACES is defined.
 *
 * If ACESTL_NO_NAMESPACES is defined, then ACESTL_NO_NAMESPACE is defined.
 *
 * If ACESTL_NO_NAMESPACE is defined, then the ACESTL constructs are defined
 * in the global scope.
 *
 * If STLSOFT_NO_NAMESPACES, ACESTL_NO_NAMESPACES and ACESTL_NO_NAMESPACE are
 * all undefined but the symbol STLSOFT_NO_NAMESPACE is defined (whence the
 * namespace stlsoft does not exist), then the ACESTL constructs are defined
 * within the acestl namespace. The definition matrix is as follows:
 *
 * STLSOFT_NO_NAMESPACE     ACESTL_NO_NAMESPACE     acestl definition
 * ---------------------    --------------------    -----------------
 *  not defined              not defined             = stlsoft::acestl_project
 *  not defined              defined                 not defined
 *  defined                  not defined             acestl
 *  defined                  defined                 not defined
 *
 *
 *
 * The macro acestl_ns_qual() macro can be used to refer to elements in the
 * ACESTL libraries irrespective of whether they are in the
 * stlsoft::acestl_project (or acestl) namespace or in the global namespace.
 *
 * Furthermore, some compilers do not support the standard library in the std
 * namespace, so the STLSOFT_NS_QUAL_STD() macro can be used to refer to elements
 * in the standard library irrespective of whether they are in the std namespace
 * or in the global namespace.
 */

/* /////////////////////////////////////
 * obsolete preprocessor symbol detection
 */

#ifdef _ACESTL_NO_NAMESPACES
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _ACESTL_NO_NAMESPACES. This symbol is now deprecated, and may be ignored by a future release : instead define ACESTL_NO_NAMESPACES")
# endif
# if !defined(ACESTL_NO_NAMESPACES)
#  define ACESTL_NO_NAMESPACES
# endif /* !ACESTL_NO_NAMESPACES */
#endif /* _ACESTL_NO_NAMESPACES */

#ifdef _ACESTL_NO_NAMESPACE
# if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#  pragma message("You have defined _ACESTL_NO_NAMESPACE. This symbol is now deprecated, and may be ignored by a future release : instead define ACESTL_NO_NAMESPACE")
# endif
# if !defined(ACESTL_NO_NAMESPACE)
#  define ACESTL_NO_NAMESPACE
# endif /* !ACESTL_NO_NAMESPACE */
#endif /* _ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////
 * namespace support discrimination
 */

/* No STLSoft namespaces means no ACESTL namespaces */
#ifdef STLSOFT_NO_NAMESPACES
# define ACESTL_NO_NAMESPACES
#endif /* STLSOFT_NO_NAMESPACES */

/* No ACESTL namespaces means no acestl namespace */
#ifdef ACESTL_NO_NAMESPACES
# define ACESTL_NO_NAMESPACE
#endif /* ACESTL_NO_NAMESPACES */

#ifdef ACESTL_NO_NAMESPACES
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_ACESTL_NO_NAMESPACES)
#   define _ACESTL_NO_NAMESPACES
#  endif /* !_ACESTL_NO_NAMESPACES */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* ACESTL_NO_NAMESPACES */

#ifdef ACESTL_NO_NAMESPACE
# ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
#  if !defined(_ACESTL_NO_NAMESPACE)
#   define _ACESTL_NO_NAMESPACE
#  endif /* !_ACESTL_NO_NAMESPACE */
# endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */
#endif /* ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////
 * declaration '*stl*' namespace
 */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
/** The \c acestl namespace contains all components
 *   in the \ref group__project__acestl "ACESTL" project.
 *
 * By default, the \c acestl namespace is actually an alias for
 * the namespace <code>stlsoft::acestl_project</code>, which is where all
 * the \ref group__project__acestl "ACESTL" components actually reside. This
 * measure allows all components within the main the
 * \ref group__project__stlsoft "STLSoft" project (which are defined within
 * the \c stlsoft namespace) to be visible to all components
 * "within" the \c acestl namespace. (Otherwise, there would be a
 * whole lot of onerous qualification throughout the code of all
 * \ref group__projects "sub-projects".)
 *
 * \note If either/both of the symbols \c STLSOFT_NO_NAMESPACES
 * and \c ACESTL_NO_NAMESPACE are defined, all
 * \ref group__project__acestl "ACESTL" components will be defined in the
 * global namespace. Conversely, if the \c STLSOFT_NO_NAMESPACE
 * symbol (not to be confused with the
 * \c STLSOFT_NO_NAMESPACES symbol!) is defined - meaning that
 * all \ref group__project__stlsoft "main project" components are to be
 * defined in the global namespace, and \c ACESTL_NO_NAMESPACE
 * is <b>not</b> defined, then all \ref group__project__acestl "ACESTL"
 * components will be defined within a bona fide \c acestl
 * namespace.
 *
 * \note This is a vestige of compatibility with compilers with
 * no (or no sensible) namespace support that is maintained for reasons of
 * backwards compatiblity and because it is, in <i>rare circumstances</i>, a
 * useful facility.
 */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */
namespace stlsoft
{
namespace acestl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#else
STLSOFT_NS_USING(move_lhs_from_rhs)
#endif /* !ACESTL_NO_NAMESPACE */

/** \def ACESTL_NS_QUAL(x)
 * Qualifies with <b>acestl::</b> if ACESTL is using namespaces or, if not, does not qualify
 */

/** \def ACESTL_NS_USING(x)
 * Declares a using directive (with respect to <b>acestl</b>) if ACESTL is using namespaces or, if not, does nothing
 */

#ifndef ACESTL_NO_NAMESPACE
# define ACESTL_NS_QUAL(x)             ::acestl::x
# define ACESTL_NS_USING(x)            using ::acestl::x;
#else /* ? ACESTL_NO_NAMESPACE */
# define ACESTL_NS_QUAL(x)             x
# define ACESTL_NS_USING(x)
#endif /* !ACESTL_NO_NAMESPACE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define acestl_ns_qual(x)                                  ACESTL_NS_QUAL(x)
# define acestl_ns_using(x)                                 ACESTL_NS_USING(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

#ifndef STLSOFT_NO_PRE_1_10_BAGGAGE
# define acestl_ns_qual_std(x)                              STLSOFT_NS_QUAL_STD(x)
# define acestl_ns_using_std(x)                             STLSOFT_NS_USING_STD(x)
#endif /* !STLSOFT_NO_PRE_1_10_BAGGAGE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 *
 * The ACESTL uses a number of typedefs to aid in compiler-independence in the
 * libraries' main code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

typedef STLSOFT_NS_QUAL(ss_char_a_t)        as_char_a_t;    //!< Ansi char type
typedef STLSOFT_NS_QUAL(ss_char_w_t)        as_char_w_t;    //!< Unicode char type
typedef STLSOFT_NS_QUAL(ss_sint8_t)         as_sint8_t;     //!< 8-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint8_t)         as_uint8_t;     //!< 8-bit unsigned integer
typedef STLSOFT_NS_QUAL(ss_int16_t)         as_int16_t;     //!< 16-bit integer
typedef STLSOFT_NS_QUAL(ss_sint16_t)        as_sint16_t;    //!< 16-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint16_t)        as_uint16_t;    //!< 16-bit unsigned integer
typedef STLSOFT_NS_QUAL(ss_int32_t)         as_int32_t;     //!< 32-bit integer
typedef STLSOFT_NS_QUAL(ss_sint32_t)        as_sint32_t;    //!< 32-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint32_t)        as_uint32_t;    //!< 32-bit unsigned integer
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
typedef STLSOFT_NS_QUAL(ss_int64_t)         as_int64_t;     //!< 64-bit integer
typedef STLSOFT_NS_QUAL(ss_sint64_t)        as_sint64_t;    //!< 64-bit signed integer
typedef STLSOFT_NS_QUAL(ss_uint64_t)        as_uint64_t;    //!< 64-bit unsigned integer
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
typedef STLSOFT_NS_QUAL(ss_int_t)           as_int_t;       //!< integer
typedef STLSOFT_NS_QUAL(ss_sint_t)          as_sint_t;      //!< signed integer
typedef STLSOFT_NS_QUAL(ss_uint_t)          as_uint_t;      //!< unsigned integer
typedef STLSOFT_NS_QUAL(ss_long_t)          as_long_t;      //!< long
typedef STLSOFT_NS_QUAL(ss_bool_t)          as_bool_t;      //!< bool
typedef STLSOFT_NS_QUAL(ss_size_t)          as_size_t;      //!< size
typedef STLSOFT_NS_QUAL(ss_ptrdiff_t)       as_ptrdiff_t;   //!< ptr diff
typedef STLSOFT_NS_QUAL(ss_streampos_t)     as_streampos_t; //!< streampos
typedef STLSOFT_NS_QUAL(ss_streamoff_t)     as_streamoff_t; //!< streamoff

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef ACESTL_NO_NAMESPACE
typedef as_char_a_t         char_a_t;           //!< Ansi char type
typedef as_char_w_t         char_w_t;           //!< Unicode char type
//typedef as_int8_t           int8_t;             //!< 8-bit integer
typedef as_sint8_t          sint8_t;            //!< 8-bit signed integer
typedef as_uint8_t          uint8_t;            //!< 8-bit unsigned integer
typedef as_int16_t          int16_t;            //!< 16-bit integer
typedef as_sint16_t         sint16_t;           //!< 16-bit signed integer
typedef as_uint16_t         uint16_t;           //!< 16-bit unsigned integer
typedef as_int32_t          int32_t;            //!< 32-bit integer
typedef as_sint32_t         sint32_t;           //!< 32-bit signed integer
typedef as_uint32_t         uint32_t;           //!< 32-bit unsigned integer
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
 typedef as_int64_t         int64_t;            //!< 64-bit integer
 typedef as_sint64_t        sint64_t;           //!< 64-bit signed integer
 typedef as_uint64_t        uint64_t;           //!< 64-bit unsigned integer
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
//typedef as_short_t          short_t;            //!< short integer
typedef as_int_t            int_t;              //!< integer
typedef as_sint_t           sint_t;             //!< signed integer
typedef as_uint_t           uint_t;             //!< unsigned integer
typedef as_long_t           long_t;             //!< long integer
//typedef as_byte_t           byte_t;             //!< Byte
typedef as_bool_t           bool_t;             //!< bool
# if !defined(STLSOFT_COMPILER_IS_DMC)
typedef as_streampos_t      streampos_t;        //!< streampos
typedef as_streamoff_t      streamoff_t;        //!< streamoff
# endif /* compiler */
#endif /* !ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * values
 *
 * Since the boolean type may not be supported natively on all compilers, the
 * values of true and false may also not be provided. Hence the values of
 * as_true_v and as_false_v are defined, and are used in all code.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#define as_true_v                                           ss_true_v
#define as_false_v                                          ss_false_v

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/* /////////////////////////////////////////////////////////////////////////
 * code modification macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/* Exception signatures. */
# define acestl_throw_0()                               stlsoft_throw_0()
# define acestl_throw_1(x1)                             stlsoft_throw_1(x1)
# define acestl_throw_2(x1, x2)                         stlsoft_throw_2(x1, x2)
# define acestl_throw_3(x1, x2, x3)                     stlsoft_throw_3(x1, x2, x3)
# define acestl_throw_4(x1, x2, x3, x4)                 stlsoft_throw_4(x1, x2, x3, x4)
# define acestl_throw_5(x1, x2, x3, x4, x5)             stlsoft_throw_5(x1, x2, x3, x4, x5)
# define acestl_throw_6(x1, x2, x3, x4, x5, x6)         stlsoft_throw_6(x1, x2, x3, x4, x5, x6)
# define acestl_throw_7(x1, x2, x3, x4, x5, x6, x7)     stlsoft_throw_7(x1, x2, x3, x4, x5, x6, x7)
# define acestl_throw_8(x1, x2, x3, x4, x5, x6, x7, x8) stlsoft_throw_8(x1, x2, x3, x4, x5, x6, x7, x8)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_NUM_ELEMENTS(ar)                        STLSOFT_NUM_ELEMENTS(ar)
# define acestl_num_elements(ar)                        ACESTL_NUM_ELEMENTS(ar)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** [DEPRECATED] Destroys the given instance \c p of the given type (\c t and \c type)
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_DESTROY_INSTANCE().
 */
#define acestl_destroy_instance(t, type, p)            STLSOFT_DESTROY_INSTANCE(t, type, p)

/** [DEPRECATED] Generates an opaque type with the name \c _htype
 *
 * \deprecated This is <b>heavily</b> deprecated in favour of \ref STLSOFT_GEN_OPAQUE().
 */
#define acestl_gen_opaque(htype)                       STLSOFT_GEN_OPAQUE(htype)

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace acestl */
# else
} /* namespace acestl_project */
} /* namespace stlsoft */
namespace acestl = ::stlsoft::acestl_project;
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */

/* ///////////////////////////// end of file //////////////////////////// */

