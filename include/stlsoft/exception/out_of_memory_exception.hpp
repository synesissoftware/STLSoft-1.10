/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/out_of_memory_exception.hpp
 *
 * Purpose:     Definition of the stlsoft::out_of_memory_exception class.
 *
 * Created:     13th May 2010
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/exception/out_of_memory_exception.hpp
 *
 * \brief [C++] Definition of the stlsoft::out_of_memory_exception
 *   exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION
#define STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION_MAJOR    2
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION_MINOR    0
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION_REVISION 4
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION_EDIT     22
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

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_LIBRARY_IDENTIFIER_PROVIDER
# include <stlsoft/exception/library_identifier_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_LIBRARY_IDENTIFIER_PROVIDER */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_IDENTIFIER_PROVIDER
# include <stlsoft/exception/project_identifier_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_PROJECT_IDENTIFIER_PROVIDER */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER
# include <stlsoft/exception/status_code_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER */

#ifndef STLSOFT_INCL_NEW
# define STLSOFT_INCL_NEW
# include <new>
#endif /* !STLSOFT_INCL_NEW */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

#if 0 || \
    defined(STLSOFT_COMPILER_IS_DMC) || \
    0
typedef std::bad_alloc                                      stlsoft_out_of_memory_exception_parent_t;
#else /* ? compiler */
typedef STLSOFT_NS_QUAL_STD(bad_alloc)                      stlsoft_out_of_memory_exception_parent_t;
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Qualifying out-of-memory exception to be thrown in all STLSoft library
 * code for out-of-memory conditions
 *
 * \ingroup group__library__Exception
 *
 */
class out_of_memory_exception
    : public stlsoft_out_of_memory_exception_parent_t
    , public project_identifier_provider
    , public library_identifier_provider
    , public status_code_provider<int>
{
public: // Member Types
    /// The parent class type
    typedef stlsoft_out_of_memory_exception_parent_t        parent_class_type;
    /// The class type
    typedef out_of_memory_exception                         class_type;
private:
    typedef status_code_provider<int>                       status_code_provider_type_;
public:
    typedef status_code_provider_type_::status_code_type    status_code_type;
#ifdef STLSOFT_NO_NAMESPACE
    typedef STLSoftProjectIdentifier_t                      ProjectIdentifier_t;
    typedef STLSoftLibraryIdentifier_t                      LibraryIdentifier_t;
#endif /* STLSOFT_NO_NAMESPACE */

public: // Construction
    out_of_memory_exception()
        : parent_class_type()
        , m_projectId(STLSoftProjectIdentifier_Unspecified)
        , m_libraryId(STLSoftLibraryIdentifier_Unspecified)
        , m_statusCode(ENOMEM)
    {}
    ss_explicit_k
    out_of_memory_exception(
        ProjectIdentifier_t projectId
    )
        : parent_class_type()
        , m_projectId(projectId)
        , m_libraryId(STLSoftLibraryIdentifier_Unspecified)
        , m_statusCode(ENOMEM)
    {}
    out_of_memory_exception(
        ProjectIdentifier_t projectId
    ,   LibraryIdentifier_t libraryId
    )
        : parent_class_type()
        , m_projectId(projectId)
        , m_libraryId(libraryId)
        , m_statusCode(ENOMEM)
    {}
    out_of_memory_exception(
        ProjectIdentifier_t projectId
    ,   LibraryIdentifier_t libraryId
    ,   int                 statusCode
    )
        : parent_class_type()
        , m_projectId(projectId)
        , m_libraryId(libraryId)
        , m_statusCode(statusCode)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed

public: // Overrides
    /* virtual */ project_identifier_type
    project_identifier() const ss_override_k
    {
        return m_projectId;
    }

    /* virtual */ library_identifier_type
    library_identifier() const ss_override_k
    {
        return m_libraryId;
    }

    /* virtual */ status_code_type
    status_code() const ss_override_k
    {
        return m_statusCode;
    }

    /* virtual */ char const*
    what() const STLSOFT_NOEXCEPT ss_override_k
    {
        return "out of memory";
    }

private:
    ProjectIdentifier_t const   m_projectId;
    LibraryIdentifier_t const   m_libraryId;
    int const                   m_statusCode;
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

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

