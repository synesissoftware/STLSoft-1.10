/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/systemtime_stopwatch.hpp (formerly winstl::systemtime_counter, winstl/performance/systemtime_counter.hpp)
 *
 * Purpose:     WinSTL system-time stopwatch class.
 *
 * Created:     22nd March 2002
 * Updated:     24th December 2020
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


/** \file winstl/diagnostics/systemtime_stopwatch.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::systemtime_stopwatch systemtime_stopwatch\endlink class
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_SYSTEMTIME_STOPWATCH
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_SYSTEMTIME_STOPWATCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_SYSTEMTIME_STOPWATCH_MAJOR       5
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_SYSTEMTIME_STOPWATCH_MINOR       0
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_SYSTEMTIME_STOPWATCH_REVISION    2
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_SYSTEMTIME_STOPWATCH_EDIT        57
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Performance counter that uses the Windows <code>GetSystemTime()</code> function
 *
 * \ingroup group__library__Diagnostic
 */
class systemtime_stopwatch
{
public:
    /// This type
    typedef systemtime_stopwatch    class_type;

private:
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef ws_sint64_t             epoch_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef ws_sint32_t             epoch_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
public:
    /// The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef epoch_type              interval_type;

// Construction
public:
    systemtime_stopwatch();

// Operations
public:
    /// Starts measurement
    ///
    /// Begins the measurement period
    void        start();
    /// Ends measurement
    ///
    /// Ends the measurement period
    void        stop();

// Attributes
public:
    /// The elapsed count in the measurement period
    ///
    /// This represents the extent, in machine-specific increments, of the measurement period
    interval_type   get_period_count() const;
    /// The number of whole seconds in the measurement period
    ///
    /// This represents the extent, in whole seconds, of the measurement period
    interval_type   get_seconds() const;
    /// The number of whole milliseconds in the measurement period
    ///
    /// This represents the extent, in whole milliseconds, of the measurement period
    interval_type   get_milliseconds() const;
    /// The number of whole microseconds in the measurement period
    ///
    /// This represents the extent, in whole microseconds, of the measurement period
    interval_type   get_microseconds() const;
    /// The number of whole nanoseconds in the measurement period
    ///
    /// This represents the extent, in whole nanoseconds, of the measurement period
    interval_type   get_nanoseconds() const;

// Members
private:
    epoch_type  m_start;
    epoch_type  m_end;
};

////////////////////////////////////////////////////////////////////////////
// Implementation

inline
systemtime_stopwatch::systemtime_stopwatch()
{
    // Note that the constructor does nothing, for performance reasons. Calling
    // any of the Attribute methods before having gone through a start()-stop()
    // cycle will yield undefined results.
}

// Operations
inline
void
systemtime_stopwatch::start()
{
    ::GetSystemTimeAsFileTime(reinterpret_cast<LPFILETIME>(&m_start));
}

inline
void
systemtime_stopwatch::stop()
{
    ::GetSystemTimeAsFileTime(reinterpret_cast<LPFILETIME>(&m_end));
}

// Attributes
inline
systemtime_stopwatch::interval_type
systemtime_stopwatch::get_period_count() const
{
    return static_cast<interval_type>(m_end - m_start);
}

inline
systemtime_stopwatch::interval_type
systemtime_stopwatch::get_seconds() const
{
    return get_period_count() / interval_type(10000000);
}

inline
systemtime_stopwatch::interval_type
systemtime_stopwatch::get_milliseconds() const
{
    return get_period_count() / interval_type(10000);
}

inline
systemtime_stopwatch::interval_type
systemtime_stopwatch::get_microseconds() const
{
    return get_period_count() / interval_type(10);
}

inline
systemtime_stopwatch::interval_type
systemtime_stopwatch::get_nanoseconds() const
{
    return get_period_count() * interval_type(100);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_SYSTEMTIME_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

