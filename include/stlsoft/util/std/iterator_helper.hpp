/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/std/iterator_helper.hpp
 *
 * Purpose:     Definition of iterator class templates and macros for
 *              abstracting away standard library inconsistencies.
 *
 * Created:     2nd January 2000
 * Updated:     6th February 2024
 *
 * Thanks:      To Cláudio Albuquerque for assisting with VC++ 12 & 14
 *              support.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2000-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/std/iterator_helper.hpp
 *
 * \brief [C++] Definition of iterator class templates and macros for
 *    abstracting away standard library inconsistencies
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
#define STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER_MAJOR     5
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER_MINOR     8
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER_REVISION  8
# define STLSOFT_VER_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER_EDIT      125
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR
# include <stlsoft/util/std/library_discriminator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_LIBRARY_DISCRIMINATOR */

#ifndef STLSOFT_INCL_ITERATOR
# define STLSOFT_INCL_ITERATOR
# include <iterator>    // for std::iterator, std::reverse_iterator, std::reverse_bidirectional_iterator
#endif /* !STLSOFT_INCL_ITERATOR */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES
# include <stlsoft/meta/capabilities.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES */
#ifdef STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED_XXXX
# ifndef STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_POINTER
#  include <stlsoft/meta/typefixer/pointer.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_POINTER */
# ifndef STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_POINTER_TYPE
#  include <stlsoft/meta/typefixer/pointer_type.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_POINTER_TYPE */
# ifndef STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_REFERENCE
#  include <stlsoft/meta/typefixer/reference.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_REFERENCE */
# ifndef STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_REFERENCE_TYPE
#  include <stlsoft/meta/typefixer/reference_type.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_TYPEFIXER_HPP_REFERENCE_TYPE */
#endif /* STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED */

/* /////////////////////////////////////////////////////////////////////////
 * warnings
 */

/* This is here temporarily, until a better solution can be found. */
#ifdef STLSOFT_COMPILER_IS_MSVC
# pragma warning(disable : 4097)    // suppresses: typedef-name 'identifier1' used as synonym for class-name 'identifier2'
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * tested compatibilities
 */

#if !defined(STLSOFT_OVERRIDE_COMPILER_STD_LIBRARY_CHECK)

# if 0
    /* Now we Must be either Dinkumware or STLport if compiling with Intel or Visual C++
     */

#    if (   defined(STLSOFT_COMPILER_IS_INTEL) || \
            (   defined(STLSOFT_COMPILER_IS_MSVC) && \
                _MSC_VER >= 1200 && \
                _MSC_VER < 1310)) && \
        (   !defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
            !defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT))
#     error When compiling with Intel C/C++ or Microsoft Visual C++, only the Dinkumware or STLport STL implementations are currently supported.
#     error  Please contact Synesis Software (www.synesis.com.au) if you need to support a different STL implementation with these compilers.
#    endif /* (Intel || MSVC) && !DinkumWare && !STLport */
# endif /* 0 */

#endif /* !STLSOFT_OVERRIDE_COMPILER_STD_LIBRARY_CHECK */

/* /////////////////////////////////////////////////////////////////////////
 * iterator macros
 */

/* iterator
 *
 * There are three recognised forms:
 *
 * 0. Form Cxx17 (STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT). From C++17
 *    onwards, std::iterator is deprecated, and instead iterator classes
 *    should define their member types directly.
 *
 *
 * 1. Form 1 (STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT). This is the standard
 *    (C++-98: 24.2) form, and looks like the following:
 *
 *    template<
 *        typename C
 *    ,   typename V
 *    ,   typename D = ptrdiff_t
 *    ,   typename P = V*
 *    ,   typename R = V&
 *    >
 *    struct iterator
 *    {
 *        typedef C             iterator_category;
 *        typedef V             value_type;
 *        typedef D             difference_type;
 *        typedef P             pointer;
 *        typedef R             reference;
 *    };
 *
 * 2. Form 2 (STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT). This is found with
 *    Dinkumware / Visual C++ (versions 4.2, 5.0, 6.0), and looks like the
 *    following:
 *
 *    template<
 *        typename C
 *    ,   typename V
 *    ,   typename D = ptrdiff_t
 *    >
 *    struct iterator
 *    {
 *        typedef C             iterator_category;
 *        typedef V             value_type;
 *        typedef D             distance_type;
 *    };
 *
 * 3. Form 3 (STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT). This is found in
 *    quite old versions of the STL, and in fact does not define an iterator
 *    template at all. Each container has its own iterator type
 */


#ifdef STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT
# undef STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT
#endif /* !STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT */

#ifdef STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
# undef STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#endif /* !STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT */

#ifdef STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT
# undef STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT
#endif /* !STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT */

#ifdef STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT
# undef STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT
#endif /* !STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT */


#if 0
#elif __cplusplus >= 201703L
# define STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_LIBCPP)
# define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#elif defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 3
 /* GCC 2.95 */
# define STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_BORLAND)
#  define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC)
# if  STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_4_2 || \
      STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_5_0 || \
      STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_6_0
 /* Visual C++ + Dinkumware (pre v7.0) */
#  define STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT
# else
#  define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
# endif /* STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC */
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_MSL)
# define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT)
# define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI)
# ifdef __STL_USE_NAMESPACES
#  define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
# else /* ? __STL_USE_NAMESPACES */
#  define STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT
# endif /* __STL_USE_NAMESPACES */
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI_GNU)
# define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_RW)
# define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_SUNPRO_RW)
# define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#elif defined(STLSOFT_CF_STD_LIBRARY_IS_WATCOM_PATCH)
# define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
#else
# error Library version not recognised
#endif /* library */


/* reverse_iterator
 *
 * There are four known forms for reverse_iterators:
 *
 * 0. Form Cxx14 (STLSOFT_ITERATOR_REVERSE_ITERATOR_FORMcxx14_SUPPORT). From
 *    C++14 onwards, we assume the following:
 *
 *    template <typename I>
 *    class reverse_iterator
 *    {
 *        . . . // inferential definition of `iterator_category`, etc.
 *    };
 *
 * 1. Form 1 (STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT). This is the
 *    standard (C++-98: 24.4.1.1) form, and looks like the following:
 *
 *    template <typename I>
 *    class reverse_iterator
 *      : public iterator<  typename iterator_traits<I>::iterator_category,
 *                          typename iterator_traits<I>::value_type,
 *                          typename iterator_traits<I>::difference_type,
 *                          typename iterator_traits<I>::pointer,
 *                          typename iterator_traits<I>::reference>
 *    {
 *      . . .
 *      typedef I                                               iterator_type;
 *      typedef typename iterator_traits<I>::difference_type    difference_type;
 *      typedef typename iterator_traits<I>::reference          reference;
 *      typedef typename iterator_traits<I>::pointer            pointer;
 *      . . .
 *    };
 *
 *
 * 2. Form 2 (STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM2_SUPPORT). This is
 *    effectively standard, but does not derive from std::iterator. It looks
 *    like the following:
 *
 *    template <typename I>
 *    class reverse_iterator
 *    {
 *      typedef typename iterator_traits<I>::iterator_category  iterator_category;
 *      typedef typename iterator_traits<I>::value_type         value_type;
 *      typedef typename iterator_traits<I>::difference_type    difference_type;
 *      typedef typename iterator_traits<I>::pointer            pointer;
 *      typedef typename iterator_traits<I>::reference          reference;
 *      . . .
 *    };
 *
 * 3. Form 3 (STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT).
 *
 *    template< typename I
 *            , typename V
 *            , typename R = V&
 *            , typename P = V*
 *            , typename D = ptrdiff_t
 *            >
 *    class reverse_iterator
 *      : public _Ranit<V, D>
 *    {
 *      . . .
 *      typedef _Rt             reference_type;
 *      typedef _Pt             pointer_type;
 *      . . .
 *    };
 *
 *
 * 4. Form 4 (STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM4_SUPPORT).
 *
 *    template< typename I
 *            , typename IC
 *            , typename V
 *            , typename R = V&
 *            , typename P = V*
 *            , typename D = ptrdiff_t
 *            >
 *    class reverse_iterator
 *      : public iterator<IC, V, D, P, R>
 *    {
 *      typedef D               difference_type;
 *      typedef V               value_type;
 *      typedef R               reference;
 *      typedef P               pointer;
 *      . . .
 *    };
 *
 *
 * 5. Form 5 (STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM5_SUPPORT).
 *
 *    template< typename I
 *            , typename V
 *            , typename R = V&
 *            , typename D = ptrdiff_t
 *            >
 *    class reverse_iterator
 *      : public iterator<I, V, R, D>
 *    {
 *      typedef random_access_iterator_tag  iterator_category;
 *      typedef V                           value_type;
 *      typedef D                           difference_type;
 *      typedef V*                          pointer;
 *      typedef R                           reference;
 *      . . .
 *    };
 *
 */

#ifdef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORMcxx14_SUPPORT
# undef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORMcxx14_SUPPORT
#endif /* !STLSOFT_ITERATOR_REVERSE_ITERATOR_FORMcxx14_SUPPORT */

#ifdef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
# undef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
#endif /* !STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT */

#ifdef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM2_SUPPORT
# undef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM2_SUPPORT
#endif /* !STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM2_SUPPORT */

#ifdef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT
# undef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT
#endif /* !STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT */

#ifdef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM4_SUPPORT
# undef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM4_SUPPORT
#endif /* !STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM4_SUPPORT */

#ifdef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM5_SUPPORT
# undef STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM5_SUPPORT
#endif /* !STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM5_SUPPORT */




/* Determine whether we can support bidirectional iterators
 *
 * This used to be in each compiler's capability file
 * (include/stlsoft/internal/cccap/xxxx.h), but is moved here because it is
 * actually a library feature (somewhat dependent on compilers's abilities).
 */

#if 0
#elif defined(STLSOFT_COMPILER_IS_BORLAND)
# define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
#elif defined(STLSOFT_COMPILER_IS_CLANG)
# define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
#elif defined(STLSOFT_COMPILER_IS_COMO)
# define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
#elif defined(STLSOFT_COMPILER_IS_DMC)
# if (__DMC__ >= 0x0829)
#  define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
# endif /* __DMC__ >= 0x0829 */
#elif defined(STLSOFT_COMPILER_IS_GCC)
# define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
#elif defined(STLSOFT_COMPILER_IS_INTEL)
# define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
#elif defined(STLSOFT_COMPILER_IS_MSVC)
# if _MSC_VER >= 1200
#  define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
# endif /* _MSC_VER */
#elif defined(STLSOFT_COMPILER_IS_MWERKS)
# define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
#elif defined(STLSOFT_COMPILER_IS_SUNPRO)
# if !defined(STLSOFT_CF_STD_LIBRARY_IS_SUNPRO_RW)
#  define STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT
# endif /* !STLSOFT_CF_STD_LIBRARY_IS_SUNPRO_RW */
/* #elif defined(STLSOFT_COMPILER_IS_UNKNOWN) */
/* # define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#elif defined(STLSOFT_COMPILER_IS_VECTORC)
/* #define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#elif defined(STLSOFT_COMPILER_IS_WATCOM)
/* #define STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#else /* ? compiler/library */
# error Compiler/library configuration not recognised. Contact Synesis Software
#endif /* compiler/library */


/* Obsolete definition: STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
# define STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT
#else /* ? STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
# ifdef STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT
#  undef STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT
# endif /* STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT */
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */


#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT

/* Form 1 / Form 5 */

# if 0
# elif __cplusplus >= 201402L
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORMcxx14_SUPPORT
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_LIBCPP)
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT)
 /* STLport is form 1 when not using the old form */
#  if /* defined(__STL_CLASS_PARTIAL_SPECIALIZATION) || \
       */defined(_STLP_CLASS_PARTIAL_SPECIALIZATION)
#   define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
#  else /* ?_STLP_CLASS_PARTIAL_SPECIALIZATION */
#   define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM5_SUPPORT
#  endif /* _STLP_CLASS_PARTIAL_SPECIALIZATION */
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_RW)
 /* Borland + HP/RogueWave standard library */
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI_GNU)
 /* GCC + Gnu/FSF standard library */
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_MSL)
 /* CodeWarrior + MSL */
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_BORLAND)
 /* Borland C++ + Dinkumware */
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
       ( \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_7_0 || \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_7_1 || \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_8_0 || \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_9_0 || \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_10_0 || \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_11_0 || \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_12_0 || \
           STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_14_0 || \
           0 \
       )
 /* Visual C++ + Dinkumware */
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT
# endif /* compiler / library */

/* Form 2 / Form 5 */
# if 0
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_HP_SGI)
 /* HP/SGI or HP/SGI/Comeau */
#  ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
#   define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM2_SUPPORT
#  else /* ?__STL_CLASS_PARTIAL_SPECIALIZATION */
#   define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM5_SUPPORT
#  endif /* __STL_CLASS_PARTIAL_SPECIALIZATION */
# endif /* compiler / library */

/* Form 3 */
# if 0
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
     ( \
         STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_4_2 || \
         STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_5_0 || \
         STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_6_0 || \
         0 \
     )
 /* Visual C++ + Dinkumware */
#  define STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT
# endif /* compiler / library */

/* Form 4 */


/* stlsoft_reverse_iterator() */
# if 0
# elif 0 || \
       defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM1_SUPPORT) || \
       defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM2_SUPPORT) || \
       defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORMcxx14_SUPPORT) || \
       0
#  define stlsoft_reverse_iterator(I, V, R, P, D)           STLSOFT_NS_QUAL_STD(reverse_iterator)<I>
# elif defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT)
#  define stlsoft_reverse_iterator(I, V, R, P, D)           STLSOFT_NS_QUAL_STD(reverse_iterator)<I, V, R, P, D>
//# elif defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM4_SUPPORT)
//#  define stlsoft_reverse_iterator(I, V, R, P, D)           STLSOFT_NS_QUAL_STD(reverse_iterator)<I, C, V, R, P, D>
# elif defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM5_SUPPORT)
#  define stlsoft_reverse_iterator(I, V, R, P, D)           STLSOFT_NS_QUAL_STD(reverse_iterator)<I, V, R, D>
# else
#  error reverse_iterator form not recognised
# endif /* compiler */

/* stlsoft_reverse_bidirectional_iterator() */

# if 0
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
     (   STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_4_2 || \
         STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_5_0 || \
         STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION == STLSOFT_CF_DINKUMWARE_VC_VERSION_6_0)
#  define stlsoft_reverse_bidirectional_iterator(I, V, R, P, D)      STLSOFT_NS_QUAL_STD(reverse_bidirectional_iterator)<I, V, R, P, D>
# elif defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT) && \
       !defined(_STLP_CLASS_PARTIAL_SPECIALIZATION)
#  define stlsoft_reverse_bidirectional_iterator(I, V, R, P, D)      STLSOFT_NS_QUAL_STD(reverse_bidirectional_iterator)<I, V, R, P, D>
# else
#  define stlsoft_reverse_bidirectional_iterator(I, V, R, P, D)      stlsoft_reverse_iterator(I, V, R, P, D)
# endif /*  */

#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * iterators
 */

// class iterator_base
/** Base type for <b><code>iterator</code></b> types
 *
 * \ingroup group__library__Utility
 */
//
/** This class abstract std::iterator functionality for deriving classes, hiding
 * the inconsistencies and incompatibilities of the various compilers and/or
 * libraries supported by the STLSoft libraries.
 *
 * \ingroup group__library__Utility
 *
 * \param C The iterator category
 * \param V The value type
 * \param D The distance type
 * \param P The pointer type
 * \param R The reference type
 */
template<
    ss_typename_param_k C   /* iterator category */
,   ss_typename_param_k V   /* value type */
,   ss_typename_param_k D   /* distance type */
,   ss_typename_param_k P   /* pointer */
,   ss_typename_param_k R   /* reference */
>
struct iterator_base
#if 0
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT)
    /* Form Cxx17 does not provide an iterator from which we can derive */
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT)
    : public STLSOFT_NS_QUAL_STD(iterator)<C, V, D, P, R>
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT)
    : public STLSOFT_NS_QUAL_STD(iterator)<C, V, D>
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT)
    /* Form 3 does not provide an iterator from which we can derive */
#else
# error Further iterator form discrimination required
#endif /* STLSOFT_ITERATOR_ITERATOR_FORM?_SUPPORT */
{
private:
#if 0
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT)
    /* Form Cxx17 does not provide an iterator from which we can derive */
    typedef void                                            parent_class_type;
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT)
    typedef STLSOFT_NS_QUAL_STD(iterator)<C, V, D, P, R>    parent_class_type;
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT)
    typedef STLSOFT_NS_QUAL_STD(iterator)<C, V, D>          parent_class_type;
#elif defined(STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT)
    /* Form 3 does not provide an iterator from which we can derive */
    typedef void                                            parent_class_type;
#else
# error Further iterator form discrimination required
#endif /* STLSOFT_ITERATOR_ITERATOR_FORM?_SUPPORT */


# ifdef STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED_XXXX
private:
    // iterator_category
    enum { has_member_iterator_category     =   0 != has_iterator_category<parent_class_type>::value    };

    // value_type
    enum { has_member_value_type            =   0 != has_value_type<parent_class_type>::value           };

    // distance_type
    enum { has_member_distance_type         =   0 != has_distance_type<parent_class_type>::value        };

    // pointer
    enum { has_member_pointer               =   0 != has_pointer<parent_class_type>::value              };
    enum { has_member_pointer_type          =   0 != has_pointer_type<parent_class_type>::value         };

    // reference
    enum { has_member_reference             =   0 != has_reference<parent_class_type>::value            };
    enum { has_member_reference_type        =   0 != has_reference_type<parent_class_type>::value       };

    typedef C                                               iterator_category_candidate;
    typedef V                                               value_type_candidate;
    typedef D                                               distance_candidate;
    typedef P                                               pointer_candidate;
    typedef R                                               reference_candidate;

public:
    /// The pointer type
    typedef ss_typename_type_k select_first_type_if<
        ss_typename_type_k fixer_pointer_type<parent_class_type, has_member_pointer_type>::pointer_type
    ,   ss_typename_type_k fixer_pointer<parent_class_type, has_member_pointer>::pointer
    ,   has_member_pointer_type
    >::type                                                 pointer;
    /// The reference type
    typedef ss_typename_type_k select_first_type_if<
        ss_typename_type_k fixer_reference_type<parent_class_type, has_member_reference_type>::reference_type
    ,   ss_typename_type_k fixer_reference<parent_class_type, has_member_reference>::reference
    ,   has_member_reference_type
    >::type                                                 reference;

# else /* ? STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED */

public:
#if 0
#elif 0 || \
      defined(STLSOFT_ITERATOR_ITERATOR_FORMcxx17_SUPPORT) || \
      defined(STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT) || \
      0
    typedef C                                               iterator_category;
    typedef V                                               value_type;
    typedef D                                               difference_type;
    typedef P                                               pointer;
    typedef R                                               reference;
#else
  /* Forms 1 or 2 */
    typedef ss_typename_type_k parent_class_type::iterator_category iterator_category;
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
# if 0
# elif defined(STLSOFT_ITERATOR_ITERATOR_FORM1_SUPPORT)
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    typedef ss_typename_type_k parent_class_type::pointer           pointer;
    typedef ss_typename_type_k parent_class_type::reference         reference;
# elif defined(STLSOFT_ITERATOR_ITERATOR_FORM2_SUPPORT)
    typedef ss_typename_type_k parent_class_type::distance_type     difference_type;
    typedef P                                                       pointer;
    typedef R                                                       reference;
# else
#  error Further iterator form discrimination required
# endif /* STLSOFT_ITERATOR_ITERATOR_FORM?_SUPPORT */
#endif /* STLSOFT_ITERATOR_ITERATOR_FORM3_SUPPORT */

# endif /* STLSOFT_CF_HAS_MEMBER_TYPE_SUPPORTED */

    /* These two are for compatibility with older non-standard implementations, and
     * will be benignly ignored by anything not requiring them.
     */
    typedef pointer                                                 pointer_type;
    typedef reference                                               reference_type;
};


#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT

// reverse_iterator_base, const_reverse_iterator_base,
// reverse_bidirectional_iterator_base and const_reverse_bidirectional_iterator_base
//
// These classes act as the base for reverse iterators, insulating deriving
// classes from the inconsistencies and incompatibilities of the various
// compilers and/or libraries supported by the STLSoft libraries.

// class reverse_iterator_base
/** This class acts as the base for reverse iterators, insulating deriving
 * classes from the inconsistencies and incompatibilities of the various
 * compilers and/or libraries supported by the STLSoft libraries.
 *
 * \ingroup group__library__Utility
 *
 * \param I The iterator type
 * \param V The value type
 * \param R The reference type
 * \param P The pointer type
 * \param D The distance type
 */
template<
    ss_typename_param_k I   /* iterator */
,   ss_typename_param_k V   /* value type */
,   ss_typename_param_k R   /* reference */
,   ss_typename_param_k P   /* pointer */
,   ss_typename_param_k D   /* distance type */
>
struct reverse_iterator_base
    : public stlsoft_reverse_iterator(I, V, R, P, D)
{
public:
    typedef stlsoft_reverse_iterator(I, V, R, P, D)                 parent_class_type;

    typedef ss_typename_type_k parent_class_type::iterator_category iterator_category;
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
# if 0
# elif defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT)
    typedef ss_typename_type_k parent_class_type::distance_type     difference_type;
    typedef ss_typename_type_k parent_class_type::pointer_type      pointer;
    typedef ss_typename_type_k parent_class_type::reference_type    reference;
# else /* ? STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT */
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    typedef ss_typename_type_k parent_class_type::pointer           pointer;
    typedef ss_typename_type_k parent_class_type::reference         reference;
# endif /* STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT */

    /* These two are for compatibility with older non-standard implementations, and
     * will be benignly ignored by anything not requiring them.
     */
    typedef pointer                                                 pointer_type;
    typedef reference                                               reference_type;

// Construction
public:
    /// Constructor
    ss_explicit_k reverse_iterator_base(I i)
        : parent_class_type(i)
    {}
};

// class const_reverse_iterator_base
/** Base type for <b><code>const_reverse_iterator</code></b> types
 *
 * \ingroup group__library__Utility
 */
//
/** This class acts as the base for const reverse iterators, insulating deriving
 * classes from the inconsistencies and incompatibilities of the various
 * compilers and/or libraries supported by the STLSoft libraries.
 *
 * \ingroup group__library__Utility
 *
 * \param I The iterator type
 * \param V The value type
 * \param R The reference type
 * \param P The pointer type
 * \param D The distance type
 */
template<
    ss_typename_param_k I   /* iterator */
,   ss_typename_param_k V   /* value type */
,   ss_typename_param_k R   /* reference */
,   ss_typename_param_k P   /* pointer */
,   ss_typename_param_k D   /* distance type */
>
struct const_reverse_iterator_base                  // For all current compilers/libraries, ...
    : public reverse_iterator_base<I, V, R, P, D>   // ... this is the same as reverse_iterator_base
{
public:
    typedef reverse_iterator_base<I, V, R, P, D>                    parent_class_type;

    /// The iterator category type
    typedef ss_typename_type_k parent_class_type::iterator_category iterator_category;
    /// The value type
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
    /// The difference type
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    /// The pointer type
    typedef ss_typename_type_k parent_class_type::pointer           pointer;
    /// The reference type
    typedef ss_typename_type_k parent_class_type::reference         reference;

    /* These two are for compatibility with older non-standard implementations, and
     * will be benignly ignored by anything not requiring them.
     */
    /// The alternate pointer type (for backwards compatibility)
    typedef ss_typename_type_k parent_class_type::pointer_type      pointer_type;
    /// The alternate reference type (for backwards compatibility)
    typedef ss_typename_type_k parent_class_type::reference_type    reference_type;

// Construction
public:
    /// Constructor
    ss_explicit_k const_reverse_iterator_base(I i)
        : parent_class_type(i)
    {}

    // This constructor facilitates conversion from mutable (non-const)
    // reverse iterators
    template<
        ss_typename_param_k I2
    ,   ss_typename_param_k V2
    ,   ss_typename_param_k R2
    ,   ss_typename_param_k P2
    ,   ss_typename_param_k D2
    >
    const_reverse_iterator_base(reverse_iterator_base<I2, V2, R2, P2, D2> const& rhs)
        : parent_class_type(rhs.base())
    {}
};

template<
    ss_typename_param_k I1
,   ss_typename_param_k V1
,   ss_typename_param_k R1
,   ss_typename_param_k P1
,   ss_typename_param_k D
,   ss_typename_param_k I2
,   ss_typename_param_k V2
,   ss_typename_param_k R2
,   ss_typename_param_k P2
>
inline
bool
operator !=(
    const_reverse_iterator_base<I1, V1, R1, P1, D> const&   lhs
,   reverse_iterator_base<I2, V2, R2, P2, D> const&         rhs
)
{
    return lhs.base() != rhs.base();
}

template<
    ss_typename_param_k I1
,   ss_typename_param_k V1
,   ss_typename_param_k R1
,   ss_typename_param_k P1
,   ss_typename_param_k D
,   ss_typename_param_k I2
,   ss_typename_param_k V2
,   ss_typename_param_k R2
,   ss_typename_param_k P2
>
inline
bool
operator !=(
    reverse_iterator_base<I1, V1, R1, P1, D> const&         lhs
,   const_reverse_iterator_base<I2, V2, R2, P2, D> const&   rhs
)
{
    return lhs.base() != rhs.base();
}

template<
    ss_typename_param_k I1
,   ss_typename_param_k V1
,   ss_typename_param_k R1
,   ss_typename_param_k P1
,   ss_typename_param_k D
>
inline
bool
operator !=(
    const_reverse_iterator_base<I1, V1, R1, P1, D> const&   lhs
,   const_reverse_iterator_base<I1, V1, R1, P1, D> const&   rhs
)
{
    return lhs.base() != rhs.base();
}


// class reverse_bidirectional_iterator_base
/** Base type for <b><code>reverse_bidirectional_iterator</code></b> types
 *
 * \ingroup group__library__Utility
 */
//
/** This class acts as the base for reverse bidirectional iterators,
 * insulating deriving classes from the inconsistencies and incompatibilities
 * of the various compilers and/or libraries supported by the STLSoft libraries.
 *
 * \ingroup group__library__Utility
 *
 * \param I The iterator type
 * \param V The value type
 * \param R The reference type
 * \param P The pointer type
 * \param D The distance type
 */
template<
    ss_typename_param_k I   /* iterator */
,   ss_typename_param_k V   /* value type */
,   ss_typename_param_k R   /* reference */
,   ss_typename_param_k P   /* pointer */
,   ss_typename_param_k D   /* distance type */
>
struct reverse_bidirectional_iterator_base
    : public stlsoft_reverse_bidirectional_iterator(I, V, R, P, D)
{
public:
    typedef stlsoft_reverse_bidirectional_iterator(I, V, R, P, D)               parent_class_type;

    typedef ss_typename_type_k parent_class_type::iterator_category             iterator_category;
    typedef ss_typename_type_k parent_class_type::value_type                    value_type;

# if 0
# elif defined(STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT)
    typedef ss_typename_type_k parent_class_type::distance_type                 difference_type;
    typedef ss_typename_type_k parent_class_type::pointer_type                  pointer;
    typedef ss_typename_type_k parent_class_type::reference_type                reference;
#else /* ? STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT */
    typedef ss_typename_type_k parent_class_type::difference_type               difference_type;
    typedef ss_typename_type_k parent_class_type::pointer                       pointer;
    typedef ss_typename_type_k parent_class_type::reference                     reference;
#endif /* STLSOFT_ITERATOR_REVERSE_ITERATOR_FORM3_SUPPORT */

    /* These two are for compatibility with older non-standard implementations, and
     * will be benignly ignored by anything not requiring them.
     */
    typedef pointer                                                             pointer_type;
    typedef reference                                                           reference_type;

// Construction
public:
    /// Constructor
    ss_explicit_k reverse_bidirectional_iterator_base(I i)
        : parent_class_type(i)
    {}
};

// class const_reverse_bidirectional_iterator_base
/** Base type for <b><code>const_reverse_bidirectional_iterator</code></b> types
 *
 * \ingroup group__library__Utility
 */
//
/** This class acts as the base for const reverse bidirectional iterators,
 * insulating deriving classes from the inconsistencies and incompatibilities
 * of the various compilers and/or libraries supported by the STLSoft libraries.
 *
 * \ingroup group__library__Utility
 *
 * \param I The iterator type
 * \param V The value type
 * \param R The reference type
 * \param P The pointer type
 * \param D The distance type
 */
template<
    ss_typename_param_k I   /* iterator */
,   ss_typename_param_k V   /* value type */
,   ss_typename_param_k R   /* reference */
,   ss_typename_param_k P   /* pointer */
,   ss_typename_param_k D   /* distance type */
>
struct const_reverse_bidirectional_iterator_base                // For all current compilers/libraries, ...
    : public reverse_bidirectional_iterator_base<I, V, R, P, D> // ... this is the same as reverse_iterator_base
{
public:
    typedef reverse_bidirectional_iterator_base<I, V, R, P, D>      parent_class_type;

    typedef ss_typename_type_k parent_class_type::iterator_category iterator_category;
    typedef ss_typename_type_k parent_class_type::value_type        value_type;
    typedef ss_typename_type_k parent_class_type::difference_type   difference_type;
    typedef ss_typename_type_k parent_class_type::pointer_type      pointer;
    typedef ss_typename_type_k parent_class_type::reference_type    reference;

    /* These two are for compatibility with older non-standard implementations, and
     * will be benignly ignored by anything not requiring them.
     */
    typedef ss_typename_type_k parent_class_type::pointer           pointer_type;
    typedef ss_typename_type_k parent_class_type::reference         reference_type;

// Construction
public:
    /// Constructor
    ss_explicit_k const_reverse_bidirectional_iterator_base(I i)
        : parent_class_type(i)
    {}
};

#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * random access iterator support
 */

// This is all some hideous kludge caused by Dinkumware's standard library's
// failure to leave behind any definitive discriminatable vestige of its
// presence.
//
// The discriminators are determined in stlsoft/util/std/library_discriminator.hpp

#ifdef _STLSOFT_CF_MIGHT_BE_DINKUMWARE_MS_NAUGHTIES

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

template<
    ss_typename_param_k _Ty
,   ss_typename_param_k _Diff
,   ss_typename_param_k _Pointer
,   ss_typename_param_k _Reference
,   ss_typename_param_k _Pointer2
,   ss_typename_param_k _Reference2
>
class _Ptrit
{
public:
    typedef _Pointer                                        iterator_type;

private:
    char    x[1024];
};

namespace std
{
    namespace test_dinkumware
    {
        template<
            ss_typename_param_k T1
        ,   ss_typename_param_k T2
        ,   bool S
        >
        struct select_type
        {
            typedef T1                                      selected_type;
        };

#ifdef STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT
        template<
            ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
        struct select_type<T1, T2, false>
        {
            typedef T2                                      selected_type;
        };
#endif // STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT

        template<
            class V
        ,   class P
        ,   class R
        >
        class _Ptrit_tdkw
        {
            typedef _Ptrit<
                V
            ,   STLSOFT_NS_QUAL(ss_ptrdiff_t)
            ,   P
            ,   R
            ,   P
            ,   R
            >                                               _Ptrit_type;

        public:
            typedef ss_typename_type_k select_type<
                _Ptrit_type
            ,   P
            ,   sizeof(_Ptrit_type) < 1024
            >::selected_type                                iterator_type;
        };

    } /* namespace test_dinkumware */

} /* namespace std */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

#endif /* !_STLSOFT_CF_MIGHT_BE_DINKUMWARE_MS_NAUGHTIES */

/** Pointer iterator type
 *
 * \ingroup group__library__Utility
 *
 * \param V The value type
 * \param P The pointer type
 * \param R The reference type
 */
template<
    ss_typename_param_k V
,   ss_typename_param_k P
,   ss_typename_param_k R
>
struct pointer_iterator
{
#if 0
#elif defined(_STLSOFT_CF_MIGHT_BE_DINKUMWARE_MS_NAUGHTIES) && \
      !defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT)
# if defined(_STLSOFT_CF_MIGHT_BE_DINKUMWARE_MS_NAUGHTIES_1300)
    typedef std::test_dinkumware::_Ptrit_tdkw<
        V
    ,   P
    ,   R
    >::iterator_type                                        type;
# else
    typedef P                                               type;
# endif /* _STLSOFT_CF_MIGHT_BE_DINKUMWARE_MS_NAUGHTIES_1300 */
#elif defined(STLSOFT_COMPILER_IS_MSVC) && \
      !defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT) && \
      defined(_XUTILITY_) && \
      _MSC_VER == 1300
    typedef std::_Ptrit<
        V
    ,   STLSOFT_NS_QUAL(ss_ptrdiff_t)
    ,   P
    ,   R
    ,   P
    ,   R
    >                                                       type;
#else
    typedef P                                               type;
#endif /* !_STLSOFT_CF_MIGHT_BE_DINKUMWARE_MS_NAUGHTIES */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
public:
    // For backwards compatibility
    typedef type                                            iterator_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
};

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_COMPILER_IS_DMC) && \
    !defined(STLSOFT_CF_STD_LIBRARY_IS_STLPORT)
template<
    ss_typename_param_k V
,   ss_typename_param_k P
,   ss_typename_param_k R
>
inline
random_access_iterator_tag
iterator_category(pointer_iterator<V, P, R>::type const&)
{
    return random_access_iterator_tag();
}

template<
    ss_typename_param_k V
,   ss_typename_param_k P
,   ss_typename_param_k R
>
inline
STLSOFT_NS_QUAL(ss_ptrdiff_t)*
distance_type(pointer_iterator<V, P, R>::type const&)
{
    return static_cast<STLSOFT_NS_QUAL(ss_ptrdiff_t)*>(0);
}
#endif /* STLSOFT_COMPILER_IS_DMC  && !STLSOFT_CF_STD_LIBRARY_IS_STLPORT */

/* ////////////////////////////////////////////////////////////////////// */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** Iterator category obtainer
 *
 * \ingroup group__library__Utility
 *
 * \param I The iterator type
 * \param i The iterator instance
 */

#elif defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
      ( !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER < 1900)
# define stlsoft_iterator_query_category(I, i)              (STLSOFT_NS_QUAL_STD(_Iter_cat)(i))
# define stlsoft_iterator_query_category_ptr(I, i)          (&STLSOFT_NS_QUAL_STD(_Iter_cat)(i))

#elif defined(STLSOFT_COMPILER_IS_CLANG)

# define stlsoft_iterator_query_category(I, i)              (ss_typename_type_k std::iterator_traits<I>::iterator_category())

#else /* ? library */

# define stlsoft_iterator_query_category(I, i)              (*static_cast<ss_typename_type_k std::iterator_traits<I>::iterator_category*>(0))

# if 0
# elif 0 || \
       defined(STLSOFT_COMPILER_IS_DMC) || \
       defined(STLSOFT_COMPILER_IS_MWERKS) || \
       0
#  define stlsoft_iterator_query_category_ptr(I, i)         (static_cast<ss_typename_type_k std::iterator_traits<I>::iterator_category*>(0))
# endif

#endif /* library / compiler */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

/* ///////////////////////////// end of file //////////////////////////// */

