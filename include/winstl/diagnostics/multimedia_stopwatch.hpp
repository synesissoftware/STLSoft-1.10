/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/multimedia_stopwatch.hpp (formerly winstl::multimedia_counter, winstl/performance/multimedia_counter.hpp)
 *
 * Purpose:     WinSTL multimedia stopwatch class.
 *
 * Created:     31st July 2002
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


/** \file winstl/diagnostics/multimedia_stopwatch.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::multimedia_stopwatch multimedia_stopwatch\endlink class
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_MULTIMEDIA_STOPWATCH
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_MULTIMEDIA_STOPWATCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_MULTIMEDIA_STOPWATCH_MAJOR       5
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_MULTIMEDIA_STOPWATCH_MINOR       0
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_MULTIMEDIA_STOPWATCH_REVISION    2
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_MULTIMEDIA_STOPWATCH_EDIT        54
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

#ifndef STLSOFT_INCL_H_MMSYSTEM
# define STLSOFT_INCL_H_MMSYSTEM
# include <mmsystem.h>   // Windows MultiMedia API
#endif /* !STLSOFT_INCL_H_MMSYSTEM */

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

// class winstl::multimedia_stopwatch
/** A low-cost, low-resolution stopwatch
 *
 * \ingroup group__library__Diagnostic
 *
 * This class provides low-resolution, but low-latency, performance monitoring
 * based on the multimedia timer.
 */
class multimedia_stopwatch
{
public:
    /// This type
    typedef multimedia_stopwatch                            class_type;

private:
    typedef ws_sint64_t                                     epoch_type;
public:
    /// The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef ws_sint64_t                                     interval_type;

// Construction
public:
    multimedia_stopwatch();

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
    /// The number of whole nanonseconds in the measurement period
    ///
    /// This represents the extent, in whole nanoseconds, of the measurement period
    interval_type   get_nanoseconds() const;

// Members
private:
    ws_dword_t  m_start;    // start of measurement period
    ws_dword_t  m_end;      // End of measurement period
};

////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
multimedia_stopwatch::multimedia_stopwatch()
{
    // Note that the constructor does nothing, for performance reasons. Calling
    // any of the Attribute methods before having gone through a start()-stop()
    // cycle will yield undefined results.
}

// Operations
inline
void
multimedia_stopwatch::start()
{
    m_start = ::timeGetTime();
}

inline
void
multimedia_stopwatch::stop()
{
    m_end = ::timeGetTime();
}

// Attributes
inline
multimedia_stopwatch::interval_type
multimedia_stopwatch::get_period_count() const
{
    return static_cast<interval_type>(m_end - m_start);
}

inline
multimedia_stopwatch::interval_type
multimedia_stopwatch::get_seconds() const
{
    return get_period_count() / interval_type(1000);
}

inline
multimedia_stopwatch::interval_type
multimedia_stopwatch::get_milliseconds() const
{
    return get_period_count();
}

inline
multimedia_stopwatch::interval_type
multimedia_stopwatch::get_microseconds() const
{
    return get_period_count() * interval_type(1000);
}

inline
multimedia_stopwatch::interval_type
multimedia_stopwatch::get_nanoseconds() const
{
    return get_period_count() * interval_type(1000000);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_MULTIMEDIA_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

