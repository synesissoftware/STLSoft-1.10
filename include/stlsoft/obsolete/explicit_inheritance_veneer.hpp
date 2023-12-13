/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/obsolete/explicit_inheritance_veneer.hpp
 *
 * Purpose:     Explicit inheritance veneer class.
 *
 * Created:     13th January 2003
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/// \file stlsoft/obsolete/explicit_inheritance_veneer.hpp
///
/// Explicit inheritance veneer class.

#ifndef STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_EXPLICIT_INHERITANCE_VENEER
#define STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_EXPLICIT_INHERITANCE_VENEER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_EXPLICIT_INHERITANCE_VENEER_MAJOR      4
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_EXPLICIT_INHERITANCE_VENEER_MINOR      0
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_EXPLICIT_INHERITANCE_VENEER_REVISION   5
# define STLSOFT_VER_STLSOFT_OBSOLETE_HPP_EXPLICIT_INHERITANCE_VENEER_EDIT       47
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

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS
# include <stlsoft/util/constraints.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_CONSTRAINTS */

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


// class explicit_inheritance_veneer

/** Applies a \c protected veneer over a type, which can be accessed only
 * through conversions to the veneered type
 *
 * \param T The type to be subject to the veneer
 *
 * \obsolete
 */
template <ss_typename_param_k T>
struct explicit_inheritance_veneer
    : protected T
{
public:
    /// The base class type
    typedef T   base_type;

// Conversion
public:
    /// The conversion operator that provides access to the base type
    base_type const* operator &() const
    {
        stlsoft_constraint_must_be_same_size(T, explicit_inheritance_veneer<T>);

        return this;
    }

// Implementation
protected:
    /// Access a mutable reference to the base type
    base_type& base_type_value()
    {
        return *this;
    }
    /// Access a non-mutable reference to the base type
    base_type const& base_type_value() const
    {
        return *this;
    }
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

#endif /* !STLSOFT_INCL_STLSOFT_OBSOLETE_HPP_EXPLICIT_INHERITANCE_VENEER */

/* ///////////////////////////// end of file //////////////////////////// */

