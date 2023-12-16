/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/registry/regfwd.hpp
 *
 * Purpose:     Contains forward declarations for components in the Registry library.
 *
 * Created:     8th February 2006
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/registry/regfwd.hpp
 *
 * \brief [C++] Contains forward declarations for components in
 *   the \ref group__library__Windows_Registry "Windows Registry" Library.
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_HPP_REGFWD
#define WINSTL_INCL_WINSTL_REGISTRY_HPP_REGFWD

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REGFWD_MAJOR    1
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REGFWD_MINOR    1
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REGFWD_REVISION 4
# define WINSTL_VER_WINSTL_REGISTRY_HPP_REGFWD_EDIT     20
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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
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

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<   ss_typename_param_k C // character type
        >
struct reg_traits;


template<   ss_typename_param_k C // character type
        ,   ss_typename_param_k T // registry traits type
        ,   ss_typename_param_k A // allocator type
        >
class basic_reg_key;


template<   ss_typename_param_k C // character type
        ,   ss_typename_param_k T // registry traits type
        ,   ss_typename_param_k A // allocator type
        >
class basic_reg_value;


template<   ss_typename_param_k A // allocator type
        >
class reg_blob;


template<   ss_typename_param_k C // character type
        ,   ss_typename_param_k T // registry traits type
        ,   ss_typename_param_k A // allocator type
        >
class basic_reg_key_sequence;
template<   ss_typename_param_k C // character type
        ,   ss_typename_param_k T // registry traits type
        ,   ss_typename_param_k V // value type
        ,   ss_typename_param_k A // allocator type
        >
class basic_reg_key_sequence_iterator;


template<   ss_typename_param_k C // character type
        ,   ss_typename_param_k T // registry traits type
        ,   ss_typename_param_k A // allocator type
        >
class basic_reg_value_sequence;
template<   ss_typename_param_k C // character type
        ,   ss_typename_param_k T // registry traits type
        ,   ss_typename_param_k V // value type
        ,   ss_typename_param_k A // allocator type
        >
class basic_reg_value_sequence_iterator;


class registry_exception;

class wrong_value_type_exception;

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !WINSTL_INCL_WINSTL_REGISTRY_HPP_REGFWD */

/* ///////////////////////////// end of file //////////////////////////// */

