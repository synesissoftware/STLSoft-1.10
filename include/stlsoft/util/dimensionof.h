/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/dimensionof.h
 *
 * Purpose:     Definition of the macro dimensionof().
 *
 * Created:     10th February 2010
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


/** \file stlsoft/util/dimensionof.h
 *
 * \brief [C++] Definition of the macro dimensionof()
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_H_DIMENSIONOF
#define STLSOFT_INCL_STLSOFT_UTIL_H_DIMENSIONOF

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_H_DIMENSIONOF_MAJOR       1
# define STLSOFT_VER_STLSOFT_UTIL_H_DIMENSIONOF_MINOR       0
# define STLSOFT_VER_STLSOFT_UTIL_H_DIMENSIONOF_REVISION    7
# define STLSOFT_VER_STLSOFT_UTIL_H_DIMENSIONOF_EDIT        17
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
 * macros
 */

/** \def dimensionof(ar)
 *
 * Evaluates, at compile time, to the number of elements within the
 *   given vector entity, but rejects application to pointers and (in C++
 *   compilation) instances of types that define the subscript operator.
 *
 * \param ar The literal array whose size is to be determined
 *
 * Is it used as follows:
 *
\htmlonly
<pre>
int               ai[20];
int               i     = 32;
int*              pi   = &i;
std::vector<int>  vi;
size_t            s_ai  = dimensionof(ai);   // Ok
size_t            s_i   = dimensionof(i);    // Error
size_t            s_pi  = dimensionof(pi);   // Error
size_t            s_vi  = dimensionof(vi);   // Error
</pre>
\endhtmlonly
 *
 * \note This macro is equivalent to STLSOFT_NUM_ELEMENTS(). It is defined
 *   in an explicit way, by inclusion of stlsoft/util/dimensionof.h, to
 *   avoid conflict with any macros (or other symbols) that may share the
 *   same name.
 */
#define dimensionof(ar)             STLSOFT_NUM_ELEMENTS(ar)

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_H_DIMENSIONOF */

/* ///////////////////////////// end of file //////////////////////////// */

