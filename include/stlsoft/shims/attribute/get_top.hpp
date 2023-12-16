/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/shims/attribute/get_top.hpp
 *
 * Purpose:     Contains the get_top attribute shim.
 *
 * Created:     8th September 2019
 * Updated:     24th November 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/shims/attribute/get_top.hpp
 *
 * \brief [C++] Primary include file for collection-top attribute shims
 *   representing various standard collection class (template) types
 *   (\ref group__concept__Shim__Attribute__get_top "Top Attribute Shims").
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_TOP
#define STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_TOP

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_TOP_MAJOR      1
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_TOP_MINOR      0
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_TOP_REVISION   2
# define STLSOFT_VER_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_TOP_EDIT       2
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

#include <stlsoft/internal/std/has/deque_.hpp>
#include <stlsoft/internal/std/has/list_.hpp>
#include <stlsoft/internal/std/has/priority_queue_.hpp>
#include <stlsoft/internal/std/has/queue_.hpp>
#include <stlsoft/internal/std/has/stack_.hpp>
#include <stlsoft/internal/std/has/vector_.hpp>

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_deque_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_DEQUE
#  include <stlsoft/shims/attribute/get_top/std/deque.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_DEQUE */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_deque_ */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_list_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_LIST
#  include <stlsoft/shims/attribute/get_top/std/list.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_LIST */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_list_ */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_priority_queue_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE
#  include <stlsoft/shims/attribute/get_top/std/priority_queue.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_PRIORITY_QUEUE */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_priority_queue_ */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_queue_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_QUEUE
#  include <stlsoft/shims/attribute/get_top/std/queue.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_QUEUE */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_queue_ */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_stack_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_STACK
#  include <stlsoft/shims/attribute/get_top/std/stack.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_STACK */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_stack_ */

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_vector_
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_VECTOR
#  include <stlsoft/shims/attribute/get_top/std/vector.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_GET_TOP_STD_HPP_VECTOR */
#endif /* !STLSOFT_STANDARD_LIBRARY_HAS_vector_ */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_TOP */

/* ///////////////////////////// end of file //////////////////////////// */

