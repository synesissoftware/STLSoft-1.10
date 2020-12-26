/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/argument_proxies.hpp (originally MLRefPrx.h, ::SynesisStd)
 *
 * Purpose:     Const and non-const reference and pointer proxy classes.
 *
 * Created:     28th April 2000
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2000-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/argument_proxies.hpp
 *
 * \brief [C++] Definition of the stlsoft::ptr_proxy(),
 *   stlsoft::const_ptr_proxy(), stlsoft::ref_proxy(),
 *   stlsoft::const_ref_proxy() and stlsoft::val_proxy() argument
 *   proxy creator functions
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES_MAJOR     4
# define STLSOFT_VER_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES_MINOR     0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES_REVISION  7
# define STLSOFT_VER_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES_EDIT      142
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

/** Acts as a proxy for a pointer
 *
 * \ingroup group__library__Utility
 *
 */
// pointer_proxy
template <ss_typename_param_k A>
class pointer_proxy
{
public:
    typedef A                   argument_type;
    typedef argument_type*      argument_pointer_type;
    typedef pointer_proxy<A>    class_type;

// const_ruction
public:
    ss_explicit_k pointer_proxy(argument_pointer_type a)
        : m_a(a)
    {}
    pointer_proxy(class_type const& rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_pointer_type() const
    {
        return m_a;
    }

// Members
private:
    argument_pointer_type   m_a;

// Not to be implemented
private:
    class_type const& operator =(class_type const&);
};

/** Acts as a proxy for a pointer-to-const
 *
 * \ingroup group__library__Utility
 *
 */
// const_pointer_proxy
template <ss_typename_param_k A>
class const_pointer_proxy
{
public:
    typedef A                       argument_type;
    typedef argument_type const*    argument_pointer_type;
    typedef const_pointer_proxy<A>  class_type;

// const_ruction
public:
    ss_explicit_k const_pointer_proxy(argument_pointer_type a)
        : m_a(a)
    {}
    const_pointer_proxy(class_type const& rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_pointer_type() const
    {
        return m_a;
    }

// Members
private:
    argument_pointer_type   m_a;

// Not to be implemented
private:
    class_type const& operator =(class_type const&);
};


/** Acts as a proxy for a reference
 *
 * \ingroup group__library__Utility
 *
 */
// reference_proxy
template <ss_typename_param_k A>
class reference_proxy
{
public:
    typedef A                   argument_type;
    typedef argument_type&      argument_reference_type;
    typedef reference_proxy<A>  class_type;

// const_ruction
public:
    ss_explicit_k reference_proxy(argument_reference_type a)
        : m_a(a)
    {}
    reference_proxy(class_type const& rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_reference_type() const
    {
        return m_a;
    }

// Members
private:
    argument_reference_type m_a;

// Not to be implemented
private:
    class_type const& operator =(class_type const&);
};


/** Acts as a proxy for a reference-to-const
 *
 * \ingroup group__library__Utility
 *
 */
// const_reference_proxy
template <ss_typename_param_k A>
class const_reference_proxy
{
public:
    typedef A                           argument_type;
    typedef argument_type const&        argument_reference_type;
    typedef const_reference_proxy<A>    class_type;

// const_ruction
public:
    ss_explicit_k const_reference_proxy(argument_reference_type a)
        : m_a(a)
    {}
    const_reference_proxy(class_type const& rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_reference_type() const
    {
        return m_a;
    }

// Members
private:
    argument_reference_type m_a;

// Not to be implemented
private:
    class_type const& operator =(class_type const&);
};


/** Acts as a proxy for a value
 *
 * \ingroup group__library__Utility
 *
 */
// value_proxy
template <ss_typename_param_k A>
class value_proxy
{
public:
    typedef A               argument_type;
    typedef value_proxy<A>  class_type;

// const_ruction
public:
    ss_explicit_k value_proxy(argument_type a)
        : m_a(a)
    {}
    value_proxy(class_type const& rhs)
        : m_a(rhs.m_a)
    {}

// Accessors
public:
    operator argument_type() const
    {
        return m_a;
    }

// Members
private:
    argument_type   m_a;

// Not to be implemented
private:
    class_type const& operator =(class_type const&);
};

/* /////////////////////////////////////////////////////////////////////////
 * forwarding functions
 */

/** Creator function for the pointer_proxy
 *
 * \ingroup group__library__Utility
 *
 */
template <ss_typename_param_k A>
inline pointer_proxy<A> ptr_proxy(A* a)
{
    return pointer_proxy<A>(a);
}

/** Creator function for the const_pointer_proxy
 *
 * \ingroup group__library__Utility
 *
 */
template <ss_typename_param_k A>
inline const_pointer_proxy<A> const_ptr_proxy(A const* a)
{
    return const_pointer_proxy<A>(a);
}

/** Creator function for the reference_proxy
 *
 * \ingroup group__library__Utility
 *
 */
template <ss_typename_param_k A>
inline reference_proxy<A> ref_proxy(A& a)
{
    return reference_proxy<A>(a);
}

/** Creator function for the const_reference_proxy
 *
 * \ingroup group__library__Utility
 *
 */
template <ss_typename_param_k A>
inline const_reference_proxy<A> const_ref_proxy(A& a)
{
    return const_reference_proxy<A>(a);
}

/** Creator function for the value_proxy
 *
 * \ingroup group__library__Utility
 *
 */
template <ss_typename_param_k A>
inline value_proxy<A> val_proxy(A a)
{
    return value_proxy<A>(a);
}

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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_ARGUMENT_PROXIES */

/* ///////////////////////////// end of file //////////////////////////// */

