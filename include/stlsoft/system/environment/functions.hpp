/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/system/environment/functions.hpp
 *
 * Purpose:     Environment functions.
 *
 * Created:     31st October 2019
 * Updated:     26th December 2020
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


/** \file stlsoft/system/cmdargs.hpp
 *
 * \brief [C++] Environment functions
 *   (\ref group__library__System "System" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYSTEM_ENVIRONMENT_HPP_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_SYSTEM_ENVIRONMENT_HPP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYSTEM_ENVIRONMENT_HPP_FUNCTIONS_MAJOR     1
# define STLSOFT_VER_STLSOFT_SYSTEM_ENVIRONMENT_HPP_FUNCTIONS_MINOR     0
# define STLSOFT_VER_STLSOFT_SYSTEM_ENVIRONMENT_HPP_FUNCTIONS_REVISION  1
# define STLSOFT_VER_STLSOFT_SYSTEM_ENVIRONMENT_HPP_FUNCTIONS_EDIT      2
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_SYSTEM_ENVIRONMENT_H_FUNCTIONS
# include <stlsoft/system/environment/functions.h>
#endif /* !STLSOFT_INCL_STLSOFT_SYSTEM_ENVIRONMENT_H_FUNCTIONS */

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

struct ximpl_stlsoft_environment_functions_hpp_
{
    static
    ss_truthy_t
    env_var_exists_(
        char const* name
    )
    {
        return stlsoft_C_environment_variable_exists_a(name);
    }
#if 0

    static
    ss_truthy_t
    env_var_exists_(
        wchar_t const* name
    )
    {
        return stlsoft_C_environment_variable_exists_w(name);
    }
#endif
}; /* struct ximpl_stlsoft_environment_functions_hpp_ */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Indicates whether the named environment variable exists
 *
 * \retval 0 The environment variable does not exist
 * \retval !0 The environment variable does exist
 *
 * \pre (NULL != name)
 */
template <ss_typename_param_k T>
inline
ss_truthy_t
environment_variable_exists(
    T const& name
)
{
    return ximpl_stlsoft_environment_functions_hpp_::env_var_exists_(STLSOFT_NS_QUAL(c_str_ptr)(name));
}

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

#endif /* !STLSOFT_INCL_STLSOFT_SYSTEM_ENVIRONMENT_HPP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

