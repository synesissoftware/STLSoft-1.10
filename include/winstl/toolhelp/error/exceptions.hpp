/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/toolhelp/error/exceptions.hpp
 *
 * Purpose:     Exception classes for TOOLHELP components.
 *
 * Created:     21st May 2005
 * Updated:     26th December 2020
 *
 * Thanks:      To Pablo for contributing this great library.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2007, Pablo Aguilar
 * Copyright (c) 2006-2007, Matthew Wilson
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
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems,
 *   nor Pablo Aguilar,  nor the names of any contributors may be used to
 *   endorse or promote products derived from this software without
 *   specific prior written permission.
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


/** \file winstl/toolhelp/error/exceptions.hpp
 *
 * \brief [C++] Exception classes for the
 *   (\ref group__library__Windows_Toolhelp "Windows ToolHelp" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TOOLHELP_ERROR_HPP_SEQUENCE_EXCEPTION
#define WINSTL_INCL_WINSTL_TOOLHELP_ERROR_HPP_SEQUENCE_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TOOLHELP_ERROR_HPP_SEQUENCE_EXCEPTION_MAJOR      2
# define WINSTL_VER_WINSTL_TOOLHELP_ERROR_HPP_SEQUENCE_EXCEPTION_MINOR      0
# define WINSTL_VER_WINSTL_TOOLHELP_ERROR_HPP_SEQUENCE_EXCEPTION_REVISION   5
# define WINSTL_VER_WINSTL_TOOLHELP_ERROR_HPP_SEQUENCE_EXCEPTION_EDIT       25
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

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
# include <winstl/exception/winstl_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */

#ifndef STLSOFT_INCL_H_TLHELP32
# define STLSOFT_INCL_H_TLHELP32
# include <tlhelp32.h>
#endif /* !STLSOFT_INCL_H_TLHELP32 */

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

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Root exception thrown by
 *   the \ref group__library__Windows_Toolhelp "Windows ToolHelp" library.
 *
 * \ingroup group__library__Windows_Toolhelp
 */
struct toolhelp_exception
    : public winstl_exception
{
/// \name Member Types
/// @{
public:
    typedef winstl_exception                                parent_class_type;
    typedef toolhelp_exception                              class_type;
    typedef parent_class_type::status_code_type             status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef status_code_type                                error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance from the given error code
    ///
    /// \param sc The error code that is passed to the parent class (winstl::winstl_exception) constructor
    ss_explicit_k
    toolhelp_exception(status_code_type sc)
        : parent_class_type(sc)
    {}
    /// Constructs an instance from the given message and error code
    ///
    /// \param reason The reason that is passed to the parent class (winstl::winstl_exception) constructor
    /// \param sc The error code that is passed to the parent class (winstl::winstl_exception) constructor
    toolhelp_exception(char const* reason, status_code_type sc)
        : parent_class_type(reason, sc)
    {}
/// @}
};

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_TOOLHELP_ERROR_HPP_SEQUENCE_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

