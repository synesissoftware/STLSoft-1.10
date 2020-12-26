/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/comparison_operators.hpp
 *
 * Purpose:     Comparison operators for Windows time structures.
 *
 * Created:     21st November 2003
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/time/comparison_operators.hpp
 *
 * \brief [C, C++] Comparison operators for Windows time types
 *   (\ref group__library__Time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_HPP_COMPARISON_OPERATORS
#define WINSTL_INCL_WINSTL_TIME_HPP_COMPARISON_OPERATORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_HPP_COMPARISON_OPERATORS_MAJOR      5
# define WINSTL_VER_WINSTL_TIME_HPP_COMPARISON_OPERATORS_MINOR      0
# define WINSTL_VER_WINSTL_TIME_HPP_COMPARISON_OPERATORS_REVISION   1
# define WINSTL_VER_WINSTL_TIME_HPP_COMPARISON_OPERATORS_EDIT       60
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

#ifndef WINSTL_INCL_WINSTL_TIME_H_COMPARISON_FUNCTIONS
# include <winstl/time/comparison_functions.h>
#endif /* !WINSTL_INCL_WINSTL_TIME_H_COMPARISON_FUNCTIONS */

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
 * operators
 */

/* operator == */

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator ==(
    FILETIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 == compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator ==(
    FILETIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 == compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator ==(
    SYSTEMTIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 == compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator ==(
    SYSTEMTIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 == compare(lhs, rhs);
}

/* operator != */

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator !=(
    FILETIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 != compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator !=(
    FILETIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 != compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator !=(
    SYSTEMTIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 != compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator !=(
    SYSTEMTIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 != compare(lhs, rhs);
}

/* operator < */

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <(
    FILETIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 > compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <(
    FILETIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 > compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <(
    SYSTEMTIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 > compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <(
    SYSTEMTIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 > compare(lhs, rhs);
}

/* operator > */

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >(
    FILETIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 < compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >(
    FILETIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 < compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >(
    SYSTEMTIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 < compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >(
    SYSTEMTIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 < compare(lhs, rhs);
}

/* operator <= */

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <=(
    FILETIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 >= compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <=(
    FILETIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 >= compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <=(
    SYSTEMTIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 >= compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator <=(
    SYSTEMTIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 >= compare(lhs, rhs);
}

/* operator >= */

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >=(
    FILETIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 <= compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >=(
    FILETIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 <= compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >=(
    SYSTEMTIME const& lhs
,   FILETIME const& rhs
)
{
    return 0 <= compare(lhs, rhs);
}

/**
 *
 * \ingroup group__library__Time
 */
inline
ws_bool_t
operator >=(
    SYSTEMTIME const& lhs
,   SYSTEMTIME const& rhs
)
{
    return 0 <= compare(lhs, rhs);
}

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

#endif /* !WINSTL_INCL_WINSTL_TIME_HPP_COMPARISON_OPERATORS */

/* ///////////////////////////// end of file //////////////////////////// */

