/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/console_ctrl_handler_scope.hpp
 *
 * Purpose:     Contains the basic_console_ctrl_handler_scope class.
 *
 * Created:     8th August 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/system/console_ctrl_handler_scope.hpp
 *
 * \brief [C++] Definition of the winstl::console_ctrl_handler_scope
 *  class
 *   (\ref group__library__System "System" Library).
 */


#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE_MAJOR      4
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE_MINOR      0
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE_REVISION   9
# define WINSTL_VER_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE_EDIT       42
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_Console
# include <winstl/api/external/Console.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Console */

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

/** Scopes the registration of a console control handler.
 *
 * \ingroup group__library__System
 */
class console_ctrl_handler_scope
{
/// \name
/// @{
public:
    typedef console_ctrl_handler_scope  class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Registers a console control handler
    ///
    /// \param handler The handler function to register
    ss_explicit_k console_ctrl_handler_scope(PHANDLER_ROUTINE handler)
        : m_handler(handler)
        , m_bRegistered(WINSTL_API_EXTERNAL_Console_SetConsoleCtrlHandler(handler, true))
    {}
    /// Revokes registration of the console control handler
    ~console_ctrl_handler_scope() STLSOFT_NOEXCEPT
    {
        if (m_bRegistered)
        {
            WINSTL_API_EXTERNAL_Console_SetConsoleCtrlHandler(m_handler, false);
        }
    }

private:
    console_ctrl_handler_scope(class_type const&);  // copy-construction proscribed
    void operator =(class_type const&);             // copy-assignment proscribed
/// @}

/// \name Members
/// @{
private:
    const PHANDLER_ROUTINE  m_handler;
    const BOOL              m_bRegistered;
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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_CONSOLE_CTRL_HANDLER_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

