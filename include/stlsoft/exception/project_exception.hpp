/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/error/project_exception.hpp (formerly stlsoft/error/project_exception.hpp)
 *
 * Purpose:     Basic exception classes.
 *
 * Created:     19th January 2002
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


/** \file stlsoft/error/project_exception.hpp
 *
 * \brief [C++] Definition of the stlsoft::project_exception root
 *   exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION
#define STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION_MAJOR      6
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION_MINOR      0
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION_REVISION   2
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION_EDIT       60
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

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_IDENTIFIER_PROVIDER
# include <stlsoft/exception/project_identifier_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_IDENTIFIER_PROVIDER */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION
# include <stlsoft/exception/root_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_H_PROJECTIDENTIFIER
# include <stlsoft/diagnostics/ProjectIdentifier.h>
#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_H_PROJECTIDENTIFIER */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Root exception class for sub-project platform-specific
 *    exceptions.
 *
 * \ingroup group__library__Exception
 *
 */
class project_exception
    : public stlsoft_root_exception
    , public project_identifier_provider
{
/// \name Types
/// @{
public:
    /// This class type
    typedef project_exception                               class_type;
    /// The parent class type
    typedef stlsoft_root_exception                          parent_class_type;
    /// The project identifier type
    typedef STLSoftProjectIdentifier_t                      project_identifier_type;
/// @}

/// \name Construction
/// @{
protected:
    /// Default constructor
    explicit
    project_exception(
        project_identifier_type projectId
    )
        : parent_class_type()
        , ProjectIdentifier(projectId)
    {}
    // Copy constructor
    project_exception(class_type const& rhs)
        : parent_class_type(rhs)
        , ProjectIdentifier(rhs.ProjectIdentifier)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Accessors
/// @{
public:
    /// Returns a human-readable string describing the exception condition
    /*virtual*/ char const*
    what() const STLSOFT_NOEXCEPT ss_override_k = 0;

    /*virtual*/ project_identifier_type
    project_identifier() const ss_override_k
    {
        return ProjectIdentifier;
    }
/// @}

/// \name Fields
/// @{
public:
    /// The project identifier of the exception
    project_identifier_type const       ProjectIdentifier;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

