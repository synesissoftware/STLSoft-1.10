/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/char2str.hpp
 *
 * Purpose:     Conversion from character(s) to string.
 *
 * Created:     12th November 2020
 * Updated:     12th November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020, Matthew Wilson and Synesis Information Systems
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


/** \file stlsoft/conversion/char2str.hpp
 *
 * \brief [C++] Conversion from character(s) to string
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CHAR2STR
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CHAR2STR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_CHAR2STR_MAJOR     1
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_CHAR2STR_MINOR     0
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_CHAR2STR_REVISION  1
# define STLSOFT_VER_INCL_STLSOFT_CONVERSION_HPP_CHAR2STR_EDIT      1
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

#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_OPEN_WORKER_NS_(ximpl_conversion_char2str_)

STLSOFT_CLOSE_WORKER_NS_(ximpl_conversion_char2str_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

template<
    ss_typename_param_k T_s
,   ss_typename_param_k T_c
>
inline
T_s
char2str(
    T_c     ch
,   size_t  n
)
{
    return T_s(n, ch);
}

inline
std::string
char2str(
    char    ch
,   size_t  n
)
{
    return std::string(n, ch);
}

template<
    ss_typename_param_k T_s
,   ss_typename_param_k T_c
>
inline
T_s
char2str(
    T_c     ch
)
{
    return T_s(1u, ch);
}

inline
std::string
char2str(
    char ch
)
{
    return std::string(1u, ch);
}

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

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CHAR2STR */

/* ///////////////////////////// end of file //////////////////////////// */

