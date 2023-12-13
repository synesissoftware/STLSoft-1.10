/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/diagnostics/stopwatch_initialiser.hpp (formerly stlsoft::performance_counter_init, stlsoft/performance/performance_counter_init.hpp)
 *
 * Purpose:     Stopwatch initialising class.
 *
 * Created:     30th July 2002
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


/** \file stlsoft/diagnostics/stopwatch_initialiser.hpp
 *
 * \brief [C++] Definition of the stlsoft::stopwatch_initialiser
 *  class template
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_INITIALISER
#define STLSOFT_INCL_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_INITIALISER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_INITIALISER_MAJOR    5
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_INITIALISER_MINOR    0
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_INITIALISER_REVISION 1
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_INITIALISER_EDIT     46
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

// class stlsoft::stopwatch_initialiser
/** A \ref group__pattern__class_adaptor "class adaptor" that
 *   initialises a stopwatch
 *
 * \ingroup group__library__Diagnostic
 *
 * \tparam T_stopwatch The stopwatch type.
 */
template <ss_typename_param_k T_stopwatch>
class stopwatch_initialiser
    : public T_stopwatch
{
public: // Types
    /// The stopwatch type
    typedef T_stopwatch                                         stopwatch_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef stopwatch_type                                      counter_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// The class type
    typedef stopwatch_initialiser<T_stopwatch>                  class_type;
    /// The interval type
    typedef ss_typename_type_k stopwatch_type::interval_type    interval_type;

public: // Construction
    /// Initialises the stopwatch by calling start() and stop() on it.
    stopwatch_initialiser()
    {
        stopwatch_type::start();
        stopwatch_type::stop();
    }

public: // Operations
    /// Terminates and measures the current sampling period, and commences
    /// another.
    interval_type
    get_period_and_restart(
        interval_type (class_type::*pmfn)(void) const
    )
    {
        stopwatch_type::stop();

        interval_type r = (this->*pmfn)();

        stopwatch_type::start();

        return r;
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_DIAGNOSTICS_HPP_STOPWATCH_INITIALISER */

/* ///////////////////////////// end of file //////////////////////////// */

