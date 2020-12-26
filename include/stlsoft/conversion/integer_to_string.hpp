/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/integer_to_string.hpp
 *
 * Purpose:     Very efficient integer to string conversion functions.
 *
 * Created:     7th April 2002
 * Updated:     26th December 2020
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


/** \file stlsoft/conversion/integer_to_string.hpp
 *
 * \brief [C++] Very efficient integer to string conversion functions
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING_MAJOR     6
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING_MINOR     0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING_REVISION  3
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING_EDIT      94
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

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_OCTAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_octal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_OCTAL_STRING */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_hexadecimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING */

/* This to be removed in STLSoft 1.11 */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

