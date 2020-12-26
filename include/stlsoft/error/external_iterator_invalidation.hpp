/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/error/external_iterator_invalidation.hpp
 *
 * Purpose:     An exception thrown when an active end iterator is exhausted.
 *
 * Created:     13th January 2006
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/error/external_iterator_invalidation.hpp
 *
 * \brief [C++] Definition of the stlsoft::external_iterator_invalidation
 *   exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION
#define STLSOFT_INCL_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION_MAJOR     2
# define STLSOFT_VER_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION_MINOR     0
# define STLSOFT_VER_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION_REVISION  5
# define STLSOFT_VER_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION_EDIT      20
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

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION
# include <stlsoft/error/iteration_interruption.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_ITERATION_INTERRUPTION */

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

/** An exception thrown when an active end iterator is exhausted
 *
 * \ingroup group__library__Exception
 */
class external_iterator_invalidation
    : public iteration_interruption
{
/// \name Member Types
/// @{
public:
    typedef iteration_interruption          parent_class_type;
    typedef external_iterator_invalidation  class_type;
/// @}

/// \name Construction
/// @{
public:
    external_iterator_invalidation()
        : parent_class_type()
    {}
    ss_explicit_k external_iterator_invalidation(char const* message)
        : parent_class_type(message)
    {}
    external_iterator_invalidation(char const* message, long errorCode)
        : parent_class_type(message, errorCode)
    {}
    virtual ~external_iterator_invalidation() throw()
    {}
/// @}

/// \name Implementation
/// @{
private:
    virtual char const* real_what_() const throw()
    {
        return "external iterator invalidation";
    }
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

#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_EXTERNAL_ITERATOR_INVALIDATION */

/* ///////////////////////////// end of file //////////////////////////// */

