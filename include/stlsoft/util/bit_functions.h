/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/bit_functions.h
 *
 * Purpose:     Functions to manipulate bit patterns.
 *
 * Created:     2nd June 2010
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/bit_functions.h
 *
 * \brief [C++] Functions to manipulate bit patterns
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_INCL_H_BIT_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_UTIL_INCL_H_BIT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_BIT_FUNCTIONS_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_BIT_FUNCTIONS_MINOR    2
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_BIT_FUNCTIONS_REVISION 2
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_BIT_FUNCTIONS_EDIT     11
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS
# include <stlsoft/util/bits/count_functions.h>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_BITS_H_COUNT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS
# include <stlsoft/util/bits/xor_functions.h>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS
# include <stlsoft/util/bits/test_functions.h>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_BITS_H_TEST_FUNCTIONS */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_INCL_H_BIT_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

