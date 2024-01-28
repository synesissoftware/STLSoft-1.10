/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/obsolete/address_hiding_veneer.hpp
 *
 * Purpose:     Contains the address_hiding_veneer template class.
 *
 * Created:     9th July 2004
 * Updated:     20th January 2024
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


/// \file stlsoft/obsolete/address_hiding_veneer.hpp
///
/// Contains the address_hiding_veneer template class.

#ifndef STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_ADDRESS_HIDING_VENEER
#define STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_ADDRESS_HIDING_VENEER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_ADDRESS_HIDING_VENEER_MAJOR       3
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_ADDRESS_HIDING_VENEER_MINOR       0
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_ADDRESS_HIDING_VENEER_REVISION    4
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_ADDRESS_HIDING_VENEER_EDIT        27
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

// class address_hiding_veneer

/** Veneer which hides the address-of operator of its parameterising type
 *
 * \ingroup concepts_veneer
 * \ingroup group__library__Utility
 *
 */
template<   ss_typename_param_k T
        >
class address_hiding_veneer
    : public T
{
public:
    /// The veneer type
    typedef T                           parent_class_type;
    /// The current specialisation of the type
    typedef address_hiding_veneer<T>    class_type;

public:
    /// Default constructor
    address_hiding_veneer()
    {}
    /// Copy constructor
    ss_explicit_k address_hiding_veneer(class_type const& rhs)
        : parent_class_type(rhs)
    {}
    /// Conversion constructor
    ss_explicit_k address_hiding_veneer(parent_class_type const& rhs)
        : parent_class_type(rhs)
    {}

private:
    void operator &();
    void operator &() const;
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

#endif /* !STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_ADDRESS_HIDING_VENEER */

/* ///////////////////////////// end of file //////////////////////////// */

