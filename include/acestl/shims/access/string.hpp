/* /////////////////////////////////////////////////////////////////////////
 * File:        acestl/shims/access/string.hpp
 *
 * Purpose:     Helper functions for ACE classes.
 *
 * Created:     2nd December 2004
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file acestl/shims/access/string.hpp
 *
 * \brief [C++] Primary include file for string access shims representing
 *   ACE types
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef ACESTL_INCL_SHIMS_ACCESS_HPP_STRING
#define ACESTL_INCL_SHIMS_ACCESS_HPP_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_SHIMS_ACCESS_HPP_STRING_MAJOR      2
# define ACESTL_VER_SHIMS_ACCESS_HPP_STRING_MINOR      0
# define ACESTL_VER_SHIMS_ACCESS_HPP_STRING_REVISION   3
# define ACESTL_VER_SHIMS_ACCESS_HPP_STRING_EDIT       20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_INET_ADDR
# include <acestl/shims/access/string/inet_addr.hpp>
#endif /* !ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_INET_ADDR */
#ifndef ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE
# include <acestl/shims/access/string/string_base.hpp>
#endif /* !ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_STRING_BASE */
#ifndef ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_TIME_VALUE
# include <acestl/shims/access/string/time_value.hpp>
#endif /* !ACESTL_INCL_ACESTL_SHIMS_ACCESS_STRING_HPP_TIME_VALUE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ACESTL_INCL_SHIMS_ACCESS_HPP_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

