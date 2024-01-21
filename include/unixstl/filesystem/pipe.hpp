/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/pipe.hpp
 *
 * Purpose:     pipe class, based on UNIX pipe.
 *
 * Created:     19th June 2004
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


/** \file unixstl/filesystem/pipe.hpp
 *
 * \brief [C++] Definition of the unixstl::pipe class
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PIPE
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PIPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PIPE_MAJOR      4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PIPE_MINOR      1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PIPE_REVISION   10
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PIPE_EDIT       57
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTION_THROW_POLICIES
# include <unixstl/exception/throw_policies.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTION_THROW_POLICIES */

#ifndef STLSOFT_INCL_H_FCNTL
# define STLSOFT_INCL_H_FCNTL
# include <fcntl.h>
#endif /* !STLSOFT_INCL_H_FCNTL */
#ifndef STLSOFT_INCL_H_UNISTD
# define STLSOFT_INCL_H_UNISTD
# include <unistd.h>
#endif /* !STLSOFT_INCL_H_UNISTD */

#if defined(_WIN32) && \
    (   defined(_MSC_VER) || \
        defined(STLSOFT_COMPILER_IS_DMC))
# include <io.h>
#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This needs to be parameterised with a unixstl::system_resource_policy, which would control whether to throw if MX create fails"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

/** Class which wraps the UNIX pipe() function
 *
 * \ingroup group__library__FileSystem
 */
class pipe
{
/// \name Member Types
/// @{
public:
    /// The class type
    typedef pipe                    class_type;
    /// The exception policy type
    typedef unix_exception_policy   exception_policy_type;
/// @}

/// \name Construction
/// @{
public:
    pipe()
    {
#if defined(_WIN32) && \
    (   defined(_MSC_VER) || \
        defined(STLSOFT_COMPILER_IS_DMC))
        if (0 != ::_pipe(&m_handles[0], 10240, _O_TEXT))
#else /* ? _WIN32 */
        if (0 != ::pipe(&m_handles[0]))
#endif /* _WIN32 */
        {
            exception_policy_type()(errno);

            m_handles[0] = -1;
            m_handles[1] = -1;
        }
    }

    ~pipe() STLSOFT_NOEXCEPT
    {
        if (-1 != read_handle())
        {
            close_(m_handles[0]);
        }
        if (-1 != write_handle())
        {
            close_(m_handles[1]);
        }
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Returns the read handle of the pipe
    int read_handle() const
    {
        return m_handles[0];
    }
    int write_handle() const
    {
        return m_handles[1];
    }
/// @}

/// \name Operations
/// @{
public:
    /// Closes the read handle, if not already closed
    void close_read()
    {
        if (-1 != read_handle())
        {
            close_(m_handles[0]);
            m_handles[0] = -1;
        }
    }
    /// Closes the write handle, if not already closed
    void close_write()
    {
        if (-1 != write_handle())
        {
            close_(m_handles[1]);
            m_handles[1] = -1;
        }
    }
    /// Closes the read and write handles, if not already closed
    void close()
    {
        close_read();
        close_write();
    }
/// @}

/// \name Implementation
/// @{
private:
    static
    void
    close_(
        int h
    )
    {
#if _STLSOFT_VER < 0x01100000

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>
#endif

        ::close(h);

#if _STLSOFT_VER < 0x01100000

# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
#endif
    }
/// @}

/// \name Members
/// @{
private:
    int m_handles[2];
/// @}

/// \name Not to be implemented
/// @{
private:
    pipe(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PIPE */

/* ///////////////////////////// end of file //////////////////////////// */

