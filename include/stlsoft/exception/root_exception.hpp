/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/root_exception (formerly stlsoft/error/project_exception.hpp)
 *
 * Purpose:     Definition of the stlsoft::root_exception class.
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


/** \file stlsoft/exception/root_exception.hpp
 *
 * \brief [C++] Definition of the stlsoft::stlsoft_root_exception
 *   exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION
#define STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION_MAJOR     6
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION_MINOR     0
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION_REVISION  1
# define STLSOFT_VER_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION_EDIT      59
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

#ifndef STLSOFT_INCL_EXCEPTION
# define STLSOFT_INCL_EXCEPTION
# include <exception>
#endif /* !STLSOFT_INCL_EXCEPTION */

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
typedef std::exception                                      stlsoft_root_exception_parent_t;
#else /* ? compiler */
typedef STLSOFT_NS_QUAL_STD(exception)                      stlsoft_root_exception_parent_t;
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Root-most exception class for STLSoft projects
 *
 * \ingroup group__library__Exception
 *
 */
class stlsoft_root_exception
    : public stlsoft_root_exception_parent_t
{
/// \name Types
/// @{
public:
    /// This class type
    typedef stlsoft_root_exception                          class_type;
    /// The parent class type
    typedef stlsoft_root_exception_parent_t                 parent_class_type;
/// @}

/// \name Construction
/// @{
protected:
    /// Default constructor
    stlsoft_root_exception()
        : parent_class_type()
    {}
    // Copy constructor
    stlsoft_root_exception(class_type const& rhs)
        : parent_class_type(rhs)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Accessors
/// @{
public:
    /// Returns a human-readable string describing the exception condition
    virtual char const*
    what() const STLSOFT_NOEXCEPT = 0;
/// @}
};

#ifndef STLSOFT_NO_NAMESPACE
typedef stlsoft_root_exception                              root_exception;
#endif /* STLSOFT_NO_NAMESPACE */

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

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_ROOT_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

