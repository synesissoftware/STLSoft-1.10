/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/integer_to_string/integer_to_string.hpp (formerly stlsoft/conversion/integer_to_string.hpp; originally stlsoft_integer_to_string.h)
 *
 * Purpose:     Very efficient integer to string conversion functions.
 *
 * Created:     7th April 2002
 * Updated:     22nd January 2024
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


/** \file stlsoft/conversion/integer_to_string.hpp
 *
 * \brief [C++; DEPRECATED] Very efficient integer to string conversion functions
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING
#define STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_MAJOR       5
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_MINOR       1
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_REVISION    8
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_EDIT        97
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

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
# error __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT is no longer supported. Instead, define STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
#endif /* __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint8_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint8_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint16_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint16_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint32_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint32_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint64_t const& i)
{
#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if (i < 0x80000000)
    {
        return integer_to_decimal_string(buf, cchBuf, static_cast<ss_sint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint64_t const& i)
{
#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if (i < 0x80000000)
    {
        return integer_to_decimal_string(buf, cchBuf, static_cast<ss_uint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, short i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned short i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, int i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned int i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, long i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned long i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* !STLSOFT_CF_LONG_DISTINCT_INT_TYPE */


#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_sint8_t i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 5));

    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_uint8_t i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 4));

    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_sint16_t i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 7));

    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_uint16_t i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 6));

    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_sint32_t i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 12));

    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_uint32_t i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 11));

    return integer_to_decimal_string(buf, V_dimension, i);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_sint64_t const& i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 21));

#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if (i < 0x80000000)
    {
        return integer_to_decimal_string(buf, V_dimension, static_cast<ss_sint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], ss_uint64_t const& i)
{
    STLSOFT_STATIC_ASSERT(!(V_dimension < 21));

#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if (i < 0x80000000)
    {
        return integer_to_decimal_string(buf, V_dimension, static_cast<ss_uint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, V_dimension, i);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], short i)
{
    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], unsigned short i)
{
    return integer_to_decimal_string(buf, V_dimension, i);
}
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], int i)
{
    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], unsigned int i)
{
    return integer_to_decimal_string(buf, V_dimension, i);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], long i)
{
    return integer_to_decimal_string(buf, V_dimension, i);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template<
    ss_typename_param_k C
,   ss_size_t           V_dimension
>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[V_dimension], unsigned long i)
{
    return integer_to_decimal_string(buf, V_dimension, i);
}
#endif /* !STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#if 0
template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_int_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_bool_t i);

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_char_a_t i);

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_char_w_t i);
#endif /* 0 */



/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint8_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint8_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint8_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint8_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint16_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint16_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint16_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint16_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint32_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint32_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint32_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint32_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint64_t const& i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint64_t const& i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint64_t const& i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint64_t const& i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, signed short i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}
template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, unsigned short i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, int i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, int i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned int i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned int i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, long i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, long i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, cchRes);
}

/** Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__Conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, unsigned long i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, unsigned long i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}
#endif /* !STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

