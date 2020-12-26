/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/control_panel/error/exceptions.hpp
 *
 * Purpose:     Control Panel Library exception classes.
 *
 * Created:     1st April 2006
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


/** \file winstl/control_panel/error/exceptions.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::control_panel_exception control_panel_exception\endlink
 *  and
 *  \link winstl::applet_entry_not_found_exception applet_entry_not_found_exception\endlink
 *  classes
 *   (\ref group__library__Windows_ControlPanel "Windows Control Panel" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS
#define WINSTL_INCL_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS_MAJOR     2
# define WINSTL_VER_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS_MINOR     0
# define WINSTL_VER_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS_REVISION  6
# define WINSTL_VER_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS_EDIT      29
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

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
# include <winstl/exception/winstl_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */

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

/** Exception thrown by
 *   the \ref group__library__Windows_ControlPanel "Windows Control Panel" library.
 *
 * \ingroup group__library__Windows_ControlPanel
 */
class control_panel_exception
    : public winstl_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef winstl_exception                                parent_class_type;
    /// The class type
    typedef control_panel_exception                         class_type;
/// @}

/// \name Construction
/// @{
public:
    /** Contructs an instance from the given reason and error code.
     */
    control_panel_exception(char const* reason, status_code_type sc)
        : parent_class_type(reason, sc)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}
};

/** Indicates that the control panel entry point cannot be found in
 *    the control panel library.
 *
 * \ingroup group__library__Windows_ControlPanel
 */
class applet_entry_not_found_exception
    : public control_panel_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef control_panel_exception                         parent_class_type;
    /// The class type
    typedef applet_entry_not_found_exception                class_type;
/// @}

/// \name Construction
/// @{
public:
    /** Contructs an instance from the given reason and error code.
     */
    applet_entry_not_found_exception(char const* reason, status_code_type sc)
        : control_panel_exception(reason, sc)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
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

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_CONTROL_PANEL_ERROR_HPP_EXCEPTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

