/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/smartptr/scoped_method.hpp
 *
 * Purpose:     scoped_method - specialisable RAII class for arbitrary
 *              type methods.
 *
 * Created:     1st January 2004
 * Updated:     29th January 2024
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


/** \file stlsoft/smartptr/scoped_method.hpp
 *
 * \brief [C++] Definition of the stlsoft::scoped_method smart
 *   pointer class template
 *   (\ref group__library__SmartPointer "Smart Pointer" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_METHOD
#define STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_METHOD

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_METHOD_MAJOR       1
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_METHOD_MINOR       0
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_METHOD_REVISION    4
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_METHOD_EDIT        11
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
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace impl
{

    template <typename C>
    struct method_invoker
    {
    public:
        virtual void invoke(C* instance) = 0;
    };

    template <typename C>
    struct method_invoker_0
        : public method_invoker<C>
    {
    public:
        ss_explicit_k
        method_invoker_0(void (C::*method)())
            : m_method(method)
        {}

    public:
        virtual void invoke(C* instance)
        {
            (instance->*m_method)();
        }

    private:
        void    (C::*m_method)();
    };

    template <typename C, typename A0>
    struct method_invoker_1
        : public method_invoker<C>
    {
    public:
        ss_explicit_k
        method_invoker_1(void (C::*method)(A0), A0 a0)
            : m_method(method)
            , m_a0(a0)
        {}

    public:
        virtual void invoke(C* instance)
        {
            (instance->*m_method)(m_a0);
        }

    private:
        void   (C::*m_method)(A0);
        A0          m_a0;
    };

#ifndef STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT

    template <typename C, typename A0, typename A1>
    struct method_invoker_2
        : public method_invoker<C>
    {
    public:
        ss_explicit_k
        method_invoker_2(void (C::*method)(A0, A1), A0 a0, A1 a1)
            : m_method(method)
            , m_a0(a0)
            , m_a1(a1)
        {}

    public:
        virtual void invoke(C* instance)
        {
            (instance->*m_method)(m_a0, m_a1);
        }

    private:
        void   (C::*m_method)(A0, A1);
        A0          m_a0;
        A1          m_a1;
    };

#endif /* !STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT */

    template <typename C>
    inline method_invoker<C>* make_invoker(void (C::*method)())
    {
        return new method_invoker_0<C>(method);
    }

    template <typename C, typename A0>
    inline method_invoker<C>* make_invoker(void (C::*method)(A0), A0 a0)
    {
        return new method_invoker_1<C, A0>(method, a0);
    }

#ifndef STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT

    template <typename C, typename A0, typename A1>
    inline method_invoker<C>* make_invoker(void (C::*method)(A0, A1), A0 a0, A1 a1)
    {
        return new method_invoker_2<C, A0, A1>(method, a0, a1);
    }

#endif /* !STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT */


} /* namespace impl */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This class provides RAII over the invocation of an instance method.
 *
 * \ingroup group__library__SmartPointer
 *
 * \param C The type of the class whose method is to be scoped
 */
template <typename C>
class scoped_method
{
public: // types
    /// This type
    typedef scoped_method<C>            class_type;
private:
    /// The invoker type
    typedef impl::method_invoker<C>     invoker_type;

public: // construction
    scoped_method(C* instance, void (C::*method)())
        : m_instance(instance)
        , m_invoker(impl::make_invoker<C>(method))
    {}
    scoped_method(C& instance, void (C::*method)())
        : m_instance(&instance)
        , m_invoker(impl::make_invoker<C>(method))
    {}

    template <typename A0>
    scoped_method(C* instance, void (C::*method)(A0), A0 a0)
        : m_instance(instance)
        , m_invoker(impl::make_invoker<C>(method, a0))
    {}
    template <typename A0>
    scoped_method(C& instance, void (C::*method)(A0), A0 a0)
        : m_instance(&instance)
        , m_invoker(impl::make_invoker<C>(method, a0))
    {}

#ifndef STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT

    template <typename A0, typename A1>
    scoped_method(C* instance, void (C::*method)(A0, A1), A0 a0, A1 a1)
        : m_instance(instance)
        , m_invoker(impl::make_invoker<C>(method, a0, a1))
    {}
    template <typename A0, typename A1>
    scoped_method(C& instance, void (C::*method)(A0, A1), A0 a0, A1 a1)
        : m_instance(&instance)
        , m_invoker(impl::make_invoker<C>(method, a0, a1))
    {}

#endif /* !STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT */

    ~scoped_method() STLSOFT_NOEXCEPT
    {
        if (NULL != m_instance)
        {
            m_invoker->invoke(m_instance);
        }

        delete m_invoker;
    }

private:
    scoped_method(class_type const&);           // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed

public: // attributes
    bool empty() const STLSOFT_NOEXCEPT
    {
        return NULL == m_instance;
    }

public: // operations
    void detach()
    {
        m_instance = NULL;
    }

    void reset() STLSOFT_NOEXCEPT
    {
        if (NULL != m_instance)
        {
            C* const instance = m_instance;

            m_instance = NULL;

            m_invoker->invoke(instance);
        }
    }

private: // Fields
    C*              m_instance;
    invoker_type*   m_invoker;
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** is_null shim
 *
 * \ingroup group__library__SmartPointer
 */
template <ss_typename_param_k C>
inline
bool
is_null(
    scoped_method<C> const& m
) STLSOFT_NOEXCEPT
{
    return m.empty();
}

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

#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_METHOD */

/* ///////////////////////////// end of file //////////////////////////// */

