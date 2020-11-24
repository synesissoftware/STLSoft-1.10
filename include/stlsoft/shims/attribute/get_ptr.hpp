/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/attribute/get_ptr.hpp
 *
 * Purpose:     Contains the get_ptr attribute shim.
 *
 * Created:     10th January 2002
 * Updated:     24th November 2020
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


/** \file stlsoft/shims/attribute/get_ptr.hpp
 *
 * \brief [C++] Primary include file for pointer attribute shims
 *   representing built-in and standard smart pointer class types
 *   (\ref group__concept__Shim__Attribute__get_ptr "Pointer Attribute Shims").
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR
#define STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR_MAJOR      4
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR_MINOR      1
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR_REVISION   1
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR_EDIT       53
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

#include <stlsoft/internal/std/has/auto_ptr_.hpp>
#include <stlsoft/internal/std/has/shared_ptr_.hpp>
#include <stlsoft/internal/std/has/unique_ptr_.hpp>

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_FUNDAMENTAL
# include <stlsoft/shims/attribute/get_ptr/std/fundamental.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_FUNDAMENTAL */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_AUTO_PTR
#  include <stlsoft/shims/attribute/get_ptr/std/auto_ptr.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_AUTO_PTR */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_ */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_shared_ptr_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_SHARED_PTR
#  include <stlsoft/shims/attribute/get_ptr/std/shared_ptr.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_SHARED_PTR */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_shared_ptr_ */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_unique_ptr_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_UNIQUE_PTR
#  include <stlsoft/shims/attribute/get_ptr/std/unique_ptr.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_PTR_STD_HPP_UNIQUE_PTR */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_unique_ptr_ */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

