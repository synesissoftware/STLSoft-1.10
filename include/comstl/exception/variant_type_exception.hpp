/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/exception/variant_type_exception.hpp (formerly comstl/error/exceptions.hpp)
 *
 * Purpose:     COM-related exception classes, and their policy classes
 *
 * Created:     8th December 2004
 * Updated:     26th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
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


/** \file comstl/exception/variant_type_exception.hpp
 *
 * \brief [C++] Definition of the
 *   comstl::variant_type_exception exception class
 *   (\ref group__library__Exception "Exception" Library).
 */

#ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION
#define COMSTL_INCL_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION_MAJOR       3
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION_MINOR       0
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION_REVISION    3
# define COMSTL_VER_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION_EDIT        57
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION
# include <comstl/exception/comstl_exception.hpp>
#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Indicates variant type mismatches.
 *
 * \ingroup group__library__Exception
 *
 * \remarks This is thrown by comstl::safearray_sequence on variant type
 *   mismatches.
 */
class variant_type_exception
    : public comstl_exception
{
public:
    /// The parent class type
    typedef comstl_exception                                parent_class_type;
    /// The class type
    typedef variant_type_exception                          class_type;

/// \name Construction
/// @{
public:
    ss_explicit_k
    variant_type_exception(HRESULT hr)
        : parent_class_type("VARIANT type exception", hr)
    {}
    variant_type_exception(char const* reason, HRESULT hr)
        : parent_class_type(reason, hr)
    {}
    /// Destructor
    ///
    /// \note This does not do have any implementation, but is required to placate
    /// the Comeau and GCC compilers, which otherwise complain about mismatched
    /// exception specifications between this class and its parent
    virtual ~variant_type_exception() STLSOFT_NOEXCEPT_STDOVR
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_VARIANT_TYPE_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

