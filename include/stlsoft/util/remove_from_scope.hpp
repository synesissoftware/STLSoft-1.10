/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/remove_from_scope.hpp
 *
 * Purpose:     Contains the STLSOFT_REMOVE_FROM_SCOPE() macro.
 *
 * Created:     10th June 2002
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


/** \file stlsoft/util/remove_from_scope.hpp
 *
 * \brief [C++] Definition of the STLSOFT_REMOVE_FROM_SCOPE() macro
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_REMOVE_FROM_SCOPE
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_REMOVE_FROM_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_REMOVE_FROM_SCOPE_MAJOR       4
# define STLSOFT_VER_STLSOFT_UTIL_HPP_REMOVE_FROM_SCOPE_MINOR       0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_REMOVE_FROM_SCOPE_REVISION    5
# define STLSOFT_VER_STLSOFT_UTIL_HPP_REMOVE_FROM_SCOPE_EDIT        49
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_INERT
# include <stlsoft/util/inert.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_INERT */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def STLSOFT_REMOVE_FROM_SCOPE(name)
 *
 * Removes a name from the current scope (and enclosed scopes).
 *
 * \param name The name to be removed.
 */
#define STLSOFT_REMOVE_FROM_SCOPE(name)     STLSOFT_NS_QUAL(inert) name

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_REMOVE_FROM_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

