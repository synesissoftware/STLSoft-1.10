/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/pipe.hpp
 *
 * Purpose:     pipe class, based on Windows anonymous pipe.
 *
 * Created:     19th June 2004
 * Updated:     22nd January 2024
 *
 * Thanks:      iceboy for reporting a defect in close_write()
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


/** \file winstl/filesystem/pipe.hpp
 *
 * \brief [C++] Definition of the winstl::pipe class
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PIPE
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PIPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PIPE_MAJOR    4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PIPE_MINOR    1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PIPE_REVISION 11
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PIPE_EDIT     54
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

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES
# include <winstl/exception/throw_policies.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
# include <winstl/api/external/HandleAndObject.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */

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

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This needs to be parameterised with a winstl::system_resource_policy, which would control whether to throw if MX create fails"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

/** Class which wraps the Win32 pipe kernel object
 *
 * \ingroup group__library__FileSystem
 */
class pipe
{
/// \name Member Types
/// @{
public:
    /// The class type
    typedef pipe                        class_type;
    /// The exception policy type
    typedef windows_exception_policy    exception_policy_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k pipe(ws_uint32_t size = 0, ws_bool_t bInheritHandles = true)
        : m_hReadHandle(NULL)
        , m_hWriteHandle(NULL)
    {
        SECURITY_ATTRIBUTES sa;

        sa.nLength              =   sizeof(sa);
        sa.lpSecurityDescriptor =   NULL;
        sa.bInheritHandle       =   bInheritHandles;

        if (!::CreatePipe(&m_hReadHandle, &m_hWriteHandle, &sa, size))
        {
            exception_policy_type()(WINSTL_API_EXTERNAL_ErrorHandling_GetLastError());
        }
    }

    ~pipe() STLSOFT_NOEXCEPT
    {
        if (NULL != m_hReadHandle)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(m_hReadHandle);
        }
        if (NULL != m_hWriteHandle)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(m_hWriteHandle);
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Returns the read handle of the pipe
    HANDLE read_handle() const
    {
        return m_hReadHandle;
    }
    HANDLE write_handle() const
    {
        return m_hWriteHandle;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Closes the read handle, if not already closed
    void close_read()
    {
        if (NULL != m_hReadHandle)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(m_hReadHandle);

            m_hReadHandle = NULL;
        }

        WINSTL_ASSERT(NULL == m_hReadHandle);
    }
    /// Closes the write handle, if not already closed
    void close_write()
    {
        if (NULL != m_hWriteHandle)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(m_hWriteHandle);

            m_hWriteHandle = NULL;
        }

        WINSTL_ASSERT(NULL == m_hWriteHandle);
    }
    /// Closes the read and write handles, if not already closed
    void close()
    {
        close_read();
        close_write();
    }
/// @}

/// \name Members
/// @{
private:
    HANDLE  m_hReadHandle;
    HANDLE  m_hWriteHandle;
/// @}

/// \name Not to be implemented
/// @{
private:
    pipe(class_type const&);
    class_type& operator =(class_type const&);
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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PIPE */

/* ///////////////////////////// end of file //////////////////////////// */

