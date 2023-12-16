/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/diagnostics/stopwatch_scope.hpp (formerly stlsoft::performance_counter_scope.hpp, stlsoft/performance/performance_counter_scope.hpp)
 *
 * Purpose:     Stopwatch scope class.
 *
 * Created:     20th July 2002
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


/** \file stlsoft/diagnostics/stopwatch_scope.hpp
 *
 * \brief [C++] Definition of the stlsoft::stopwatch_scope
 *  class template
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_SCOPE
#define STLSOFT_INCL_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_SCOPE_MAJOR      5
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_SCOPE_MINOR      0
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_SCOPE_REVISION   2
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_SCOPE_EDIT       53
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

// class stlsoft::stopwatch_scope
/** Scopes the measurement period for a stopwatch
 *
 * \ingroup group__library__Diagnostic
 *
 * \param T_stopwatch The stopwatch type
 */
template <ss_typename_param_k T_stopwatch>
class stopwatch_scope
{
public: // Types
    /// The stopwatch type
    typedef T_stopwatch                                     stopwatch_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    // Obsolete: backwards-compatible
    typedef stopwatch_type                                  counter_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// The class type
    typedef stopwatch_scope<T_stopwatch>                    class_type;

public: // Construction
    /// Constructs with the stopwatch instance to manage, on which start() is called
    ss_explicit_k
    stopwatch_scope(
        stopwatch_type& stopwatch
    )
        : m_stopwatch(stopwatch)
    {
        m_stopwatch.start();
    }
    /// Calls stop() on the managed stopwatch
    ~stopwatch_scope() STLSOFT_NOEXCEPT
    {
        m_stopwatch.stop();
    }
private:
    stopwatch_scope(class_type const& rhs);         // copy-construction proscribed
    class_type& operator =(class_type const& rhs);  // copy-assignment proscribed

public: // Operations
    /// Calls stop() on the managed stopwatch
    void stop()
    {
        m_stopwatch.stop();
    }

    // This method is non-mutating, to ensure that only the stop operation
    // (via stopwatch_scope::stop()) is accessible on the managed stopwatch.
    /// Returns a non-mutable (const) reference to the managed stopwatch
    stopwatch_type const&
    get_stopwatch() const
    {
        return m_stopwatch;
    }
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    // Obsolete: backwards-compatible
    stopwatch_type const&
    get_counter() const
    {
        return get_stopwatch();
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

private: // Fields
    stopwatch_type& m_stopwatch;
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

