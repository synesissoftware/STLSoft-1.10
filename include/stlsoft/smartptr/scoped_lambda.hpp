/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/smartptr/scoped_lambda.hpp
 *
 * Purpose:     scoped_lambda - specialisable RAII class for arbitrary
 *              type methods.
 *
 * Created:     1st October 2014
 * Updated:     29th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2014-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/smartptr/scoped_lambda.hpp
 *
 * \brief [C++] Definition of the stlsoft::scoped_lambda smart
 *   pointer class template
 *   (\ref group__library__SmartPointer "Smart Pointer" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_LAMBDA
#define STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_LAMBDA

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_LAMBDA_MAJOR       1
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_LAMBDA_MINOR       0
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_LAMBDA_REVISION    1
# define STLSOFT_VER_STLSOFT_SMARTPTR_HPP_SCOPED_LAMBDA_EDIT        8
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

/** This class provides RAII over the invocation of a lambda.
 *
 * \ingroup group__library__SmartPointer
 */
class scoped_lambda
{
public: // types
    typedef scoped_lambda                                   class_type;
private:
    struct lambda_release_base
    {
        virtual ~lambda_release_base()
        {}
        virtual void process() = 0;
    };

    template <ss_typename_type_k T_lambda>
    struct lambda_releaser
        : public lambda_release_base
    {
    public: // types
        typedef lambda_release_base                         parent_class_type;
        typedef lambda_releaser<T_lambda>                   class_type;

    public: // construction
        explicit
        lambda_releaser(T_lambda l)
            : l(l)
        {}
        virtual ~lambda_releaser()
        {}
    private:
        lambda_releaser(class_type const&);         // copy-construction proscribed
        class_type& operator =(class_type const&);  // copy-assignment proscribed

    public: // overrides
        /*virtual*/ void
        process() ss_override_k
        {
            l();
        }

    private: // fields
        T_lambda    l;
    };

public: // construction
    template <ss_typename_type_k T_lambda>
    explicit
    scoped_lambda(T_lambda l)
        : m_lb(new lambda_releaser<T_lambda>(l))
    {
        size_t const cb = sizeof(lambda_releaser<T_lambda>(l));

        STLSOFT_SUPPRESS_UNUSED(cb);
    }
    ~scoped_lambda() STLSOFT_NOEXCEPT
    {
        reset();
    }
private:
    scoped_lambda(class_type const&);           // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed

public: // attributes
    bool empty() const STLSOFT_NOEXCEPT
    {
        return ss_nullptr_k == m_lb;
    }

public: // operations
    void detach()
    {
        delete m_lb;

        m_lb = ss_nullptr_k;
    }

    void reset() STLSOFT_NOEXCEPT
    {
        if (ss_nullptr_k != m_lb)
        {
            m_lb->process();

            delete m_lb;
        }
    }

private: // fields
    lambda_release_base*    m_lb;
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** is_null shim
 *
 * \ingroup group__library__SmartPointer
 */
inline
bool
is_null(
    scoped_lambda const& m
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

#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_LAMBDA */

/* ///////////////////////////// end of file //////////////////////////// */

