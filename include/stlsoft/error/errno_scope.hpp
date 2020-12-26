/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/error/errno_scope.hpp (originally MLTErrScp.h, ::SynesisStd)
 *
 * Purpose:     errno scoping class.
 *
 * Created:     28th November 1998
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/error/errno_scope.hpp
 *
 * \brief [C++] Definition of the stlsoft::errno_scope class
 *   (\ref group__library__error "Error" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_ERRNO_SCOPE
#define STLSOFT_INCL_STLSOFT_ERROR_HPP_ERRNO_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERRNO_SCOPE_MAJOR      3
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERRNO_SCOPE_MINOR      0
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERRNO_SCOPE_REVISION   7
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ERRNO_SCOPE_EDIT       51
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
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** A \ref group__pattern__scoping_class "scoping class" that scopes
 *    the thread's last error.
 *
 * \ingroup group__library__error
 *
\code
  DWORD   err = errno;
  { stlsoft::errno_scope  scope; // Scope the error while we change it

    // Some code that changes (or may change) the last error
    . . .

    errno = ENOMEM; // ... we just do this for pedagogical purposes

  } // End of scope - error value replaced to former value

  assert(errno == err);
\endcode
 */
class errno_scope
{
public:
    typedef errno_scope    class_type;

/// \name Operations
/// @{
public:
    /// Remembers the current value of <code>errno</code>.
    errno_scope() STLSOFT_NOEXCEPT
        : m_errno(errno)
    {}
    /// Remembers the given value as the value of <code>errno</code>.
    ss_explicit_k errno_scope(int errno_) STLSOFT_NOEXCEPT
        : m_errno(errno_)
    {
        errno = m_errno;
    }
    /// Replaces the remembered value of <code>errno</code>.
    ~errno_scope() STLSOFT_NOEXCEPT
    {
        errno = m_errno;
    }

/// @}

/// \name Operations
/// @{
public:
    /// The remembered value of <code>errno</code>.
    operator int () const
    {
        return m_errno;
    }

/// @}

/// \name Members
/// @{
private:
    int m_errno;
/// @}

/// \name Not to be implemented
/// @{
private:
    errno_scope(errno_scope const&);
    errno_scope& operator =(errno_scope const&);
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* !STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_ERRNO_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

