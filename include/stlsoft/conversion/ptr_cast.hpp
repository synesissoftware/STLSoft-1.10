/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/ptr_cast.hpp
 *
 * Purpose:     A cast that throws bad_cast for dynamic pointer casting, as well
 *              as references.
 *
 * Created:     28th December 2002
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


/** \file stlsoft/conversion/ptr_cast.hpp
 *
 * \brief [C++] Definition of the stlsoft::ptr_cast cast class
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_PTR_CAST
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_PTR_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_PTR_CAST_MAJOR      4
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_PTR_CAST_MINOR      0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_PTR_CAST_REVISION   13
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_PTR_CAST_EDIT       53
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

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS
# include <stlsoft/meta/base_type_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_BASE_TYPE_TRAITS */

#ifndef STLSOFT_INCL_TYPEINFO
# define STLSOFT_INCL_TYPEINFO
# include <typeinfo>
#endif /* !STLSOFT_INCL_TYPEINFO */

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

/** A cast that throws bad_cast for pointer cast failures, as well as
 *   for reference casts.
 *
 * \ingroup group__library__Conversion
 *
 * Assume the following class hierarchy, and variables:
\code
class Parent
{
public:
  virtual ~Parent();
};

class A
  : public Parent
{
public:
  ~A();
};

class B
  : public Parent
{
public:
  ~B();
};

. . .

A   a;
B   b;
\endcode
 *
 * The following code segments illustrate the similarities and differences
 * between dynamic_cast and ptr_cast:
 *
 * (i) dynamic cast of reference that succeeds
\code
A   &ra1 = dynamic_cast<A&>(a);
A   &ra2 = stlsoft::ptr_cast<A&>(a);

assert(&ra1 == &ra2);
\endcode
 *
 * (ii) dynamic cast of pointer that succeeds
\code
A   *pa = dynamic_cast<A*>(&a);

assert(NULL != pa);
assert(stlsoft::ptr_cast<A*>(&a) == pa);
\endcode
 *
 * (iii) dynamic cast of reference that fails
\code
bool bCastFailed1 = false;

try
{
  B &b1 = dynamic_cast<B&>(a);

  . . . // Will never get here
}
catch(std::bad_cast &)
{
  bCastFailed1 = true;
}
assert(bCastFailed1);

bool bCastFailed2 = false;

try
{
  B &rb = stlsoft::ptr_cast<B&>(a);

  . . . // Will never get here
}
catch(std::bad_cast &)
{
  bCastFailed2 = true;
}
assert(bCastFailed2);
\endcode
 *
 * (iv) dynamic cast of pointer that fails
\code
assert(NULL == dynamic_cast<B*>(&a));

bool bCastFailed = false;

try
{
  B &rb = stlsoft::ptr_cast<B&>(&a);

  . . . // Will never get here
}
catch(std::bad_cast &)
{
  bCastFailed = true;
}
assert(bCastFailed);
\endcode
 *
 * \note This is described in detail in chapter 19 of
 *  <a href = "http://www.imperfectcplusplus.com/">Imperfect C++</a>.
 */
template <ss_typename_param_k Target>
struct ptr_cast
{
public:
    /// The target type
    typedef Target                                                          target_type;
    /// The current instantiation of the type
    typedef ptr_cast<Target>                                                class_type;
    /// The target base type
    typedef ss_typename_type_k stlsoft::base_type_traits<Target>::cv_type   target_base_type;
    /// The reference type
    typedef target_base_type&                                               reference_type;
    /// The pointer type
    typedef target_base_type*                                               pointer_type;

private:
    typedef ss_typename_type_k stlsoft::base_type_traits<Target>::base_type target_base_type_;
    static target_base_type_* manage_const(target_base_type_* p)
    {
        return p;
    }
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    static target_base_type_* manage_const(target_base_type_ const* p)
    {
        return const_cast<target_base_type_*>(p);
    }
#else /* ? compiler */
    static target_base_type_ const* manage_const(target_base_type_ const* p)
    {
        return p;
    }
#endif /* compiler */

public:
    /// Constructor used when casting a reference
    template <ss_typename_param_k Source>
    ptr_cast(Source &s)
        : m_p(manage_const(&dynamic_cast<Target>(s)))
    {
        // Nothing to do: dynamic_cast throws for reference types
    }

    /// Constructor used when casting a pointer
    template <ss_typename_param_k Source>
# if 0 || \
     defined(STLSOFT_COMPILER_IS_BORLAND) || \
     defined(STLSOFT_COMPILER_IS_CLANG) || \
     defined(STLSOFT_COMPILER_IS_GCC) || \
     defined(STLSOFT_COMPILER_IS_MWERKS) || \
     0
    ptr_cast(Source*& s)
#else /* ? compiler */
    ptr_cast(Source* s)
#endif /* compiler */
        : m_p(manage_const(dynamic_cast<Target>(s)))
    {
        if(NULL == m_p)
        {
            STLSOFT_THROW_X(STLSOFT_NS_QUAL_STD(bad_cast)());
        }
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    ptr_cast(pointer_type pt)
        : m_p(pt)
    {}
    ptr_cast(reference_type t)
        : m_p(&t)
    {}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

public:
    /// Converts an instance of the cast class to a reference
    operator reference_type () const
    {
        return const_cast<reference_type>(*m_p);
    }
    /// Converts an instance of the cast class to a pointer
    operator pointer_type () const
    {
        return const_cast<pointer_type>(m_p);
    }

private:
    pointer_type  m_p;

// Not to be implemented
private:
    ptr_cast(class_type const&);
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

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_PTR_CAST */

/* ///////////////////////////// end of file //////////////////////////// */

