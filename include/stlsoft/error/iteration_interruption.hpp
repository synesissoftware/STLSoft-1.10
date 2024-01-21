/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/error/iteration_interruption.hpp
 *
 * Purpose:     An exception thrown when an active end iterator is exhausted.
 *
 * Created:     30th November 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/error/iteration_interruption.hpp
 *
 * \brief [C++] Definition of the stlsoft::iteration_interruption
 *   exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION
#define STLSOFT_INCL_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION_MAJOR     2
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION_MINOR     0
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION_REVISION  9
# define STLSOFT_VER_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION_EDIT      29
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>
#endif /* !STLSOFT_INCL_STDEXCEPT */

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

/** An exception thrown when an active iterator is interrupted, by the underlying range
 * changing outside direct control by the current thread of execution
 *
 * \ingroup group__library__Exception
 */
class iteration_interruption
    : public STLSOFT_NS_QUAL_STD(runtime_error)
{
/// \name Member Types
/// @{
public:
    typedef STLSOFT_NS_QUAL_STD(runtime_error)  parent_class_type;
    typedef iteration_interruption              class_type;
/// @}

/// \name Construction
/// @{
public:
    iteration_interruption()
        : parent_class_type("")
        , m_errorCode(0)
    {}
    ss_explicit_k iteration_interruption(char const* message)
        : parent_class_type(message)
        , m_errorCode(0)
    {}
    iteration_interruption(char const* message, long errorCode)
        : parent_class_type(message)
        , m_errorCode(errorCode)
    {}

    virtual ~iteration_interruption() STLSOFT_NOEXCEPT_STDOVR
    {}
/// @}

/// \name Accessors
/// @{
public:
    virtual char const* what() const STLSOFT_NOEXCEPT_STDOVR
    {
        char const* message = parent_class_type::what();

        if (NULL == message ||
            '\0' == *message)
        {
            message = this->real_what_();
        }

        return message;
    }

    /// The error code associated with the exception
    virtual long get_error_code() const STLSOFT_NOEXCEPT
    {
        return m_errorCode;
    }

    /// [DEPRECATED] The error code associated with the exception
    ///
    /// \deprecated Use get_error_code() instead.
    virtual long errorCode() const STLSOFT_NOEXCEPT
    {
        return get_error_code();
    }
/// @}

/// \name Implementation
/// @{
private:
    virtual char const* real_what_() const STLSOFT_NOEXCEPT
    {
        return "iteration interruption";
    }
/// @}

/// \name Members
/// @{
private:
    const long  m_errorCode;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type& operator =(class_type const&);
/// @}
};

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

#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION */

/* ///////////////////////////// end of file //////////////////////////// */

