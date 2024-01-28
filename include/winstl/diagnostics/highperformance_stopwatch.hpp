/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/highperformance_stopwatch.hpp (formerly winstl::highperformance_counter, winstl/performance/highperformance_counter.hpp)
 *
 * Purpose:     WinSTL high stopwatch class.
 *
 * Created:     19th October 1998
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/diagnostics/highperformance_stopwatch.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::highperformance_stopwatch highperformance_stopwatch\endlink class
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_HIGHPERFORMANCE_STOPWATCH
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_HIGHPERFORMANCE_STOPWATCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_HIGHPERFORMANCE_STOPWATCH_MAJOR      5
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_HIGHPERFORMANCE_STOPWATCH_MINOR      0
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_HIGHPERFORMANCE_STOPWATCH_REVISION   3
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_HIGHPERFORMANCE_STOPWATCH_EDIT       98
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

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# error winstl/diagnostics/highperformance_stopwatch.hpp is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STATIC_INITIALISERS
# include <stlsoft/util/static_initialisers.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STATIC_INITIALISERS */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Time
# include <winstl/api/external/Time.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Time */

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

// class winstl::highperformance_stopwatch
/** A stopwatch that uses the high performance hardware counter on the host machine
 *
 * \ingroup group__library__Diagnostic
 *
 * This class provides high-resolution performance monitoring using the host machine's high performance
 * hardware counter. This class does not provide meaningful timing information on operating systems
 * that do not provide a high performance hardware counter.
 */
class highperformance_stopwatch
{
public:
    /// This type
    typedef highperformance_stopwatch                       class_type;

private:
    typedef ws_sint64_t                                     epoch_type;
public:
    /// The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef ws_sint64_t                                     interval_type;

/// \name Construction
/// @{
public:
    static void class_init()
    {
        class_type().start();
    }
    static void class_uninit()
    {}
/// @}

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

// Implementation
private:
    static interval_type    frequency_();
    static interval_type    query_frequency_();

// Members
private:
    epoch_type  m_start;    // start of measurement period
    epoch_type  m_end;      // End of measurement period
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if !defined(STLSOFT_COMPILER_IS_DMC) && \
     (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
         _MSC_VER >= 1200)
static STLSOFT_NS_QUAL(class_constructor)<highperformance_stopwatch>  s_highperformance_stopwatch_class_constructor(&highperformance_stopwatch::class_init, NULL);
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
/* static */
highperformance_stopwatch::interval_type
highperformance_stopwatch::query_frequency_()
{
    interval_type   frequency;

    // If no high-performance stopwatch is available ...
    if (!WINSTL_API_EXTERNAL_Time_QueryPerformanceFrequency(sap_cast<LARGE_INTEGER*>(&frequency)) ||
        frequency == 0)
    {
        // ... then set the divisor to be the maximum value, guaranteeing that
        // the timed periods will always evaluate to 0.
        frequency = STLSOFT_NS_QUAL(integral_limits)<interval_type>::maximum();
    }

    return frequency;
}

inline
/* static */
highperformance_stopwatch::interval_type
highperformance_stopwatch::frequency_()
{
#if !defined(STLSOFT_STRICT) && \
    defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(push)
# pragma warning(disable : 4640)   /* "construction of local static object is not thread-safe" - since it is here! (As long as one uses a 'conformant' allocator) - maybe use a spin_mutex in future */
#endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
    interval_type           s_frequency = query_frequency_();
#else /* ? compiler */
    static interval_type    s_frequency = query_frequency_();
#endif /* compiler */

#if !defined(STLSOFT_STRICT) && \
    defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(pop)
#endif /* compiler */

    WINSTL_ASSERT(0 != s_frequency);

    return s_frequency;
}

// Operations
inline
void
highperformance_stopwatch::start()
{
    WINSTL_API_EXTERNAL_Time_QueryPerformanceCounter(sap_cast<LARGE_INTEGER*>(&m_start));
}

inline
void
highperformance_stopwatch::stop()
{
    WINSTL_API_EXTERNAL_Time_QueryPerformanceCounter(sap_cast<LARGE_INTEGER*>(&m_end));
}

// Attributes
inline
highperformance_stopwatch::interval_type
highperformance_stopwatch::get_period_count() const
{
    return static_cast<interval_type>(m_end - m_start);
}

inline
highperformance_stopwatch::interval_type
highperformance_stopwatch::get_seconds() const
{
    return get_period_count() / frequency_();
}

inline
highperformance_stopwatch::interval_type
highperformance_stopwatch::get_milliseconds() const
{
    highperformance_stopwatch::interval_type  result;
    highperformance_stopwatch::interval_type  count   =   get_period_count();

    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x20C49BA5E353F7))
    {
        result = (count * interval_type(1000)) / frequency_();
    }
    else
    {
        result = (count / frequency_()) * interval_type(1000);
    }

    return result;
}

inline
highperformance_stopwatch::interval_type
highperformance_stopwatch::get_microseconds() const
{
    highperformance_stopwatch::interval_type  result;
    highperformance_stopwatch::interval_type  count   =   get_period_count();

    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x8637BD05AF6))
    {
        result = (count * interval_type(1000000)) / frequency_();
    }
    else
    {
        result = (count / frequency_()) * interval_type(1000000);
    }

    return result;
}

inline
highperformance_stopwatch::interval_type
highperformance_stopwatch::get_nanoseconds() const
{
    highperformance_stopwatch::interval_type  result;
    highperformance_stopwatch::interval_type  count   =   get_period_count();

    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x8637BD05AF6))
    {
        result = (count * interval_type(1000000000)) / frequency_();
    }
    else
    {
        result = (count / frequency_()) * interval_type(1000000000);
    }

    return result;
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

#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_HIGHPERFORMANCE_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

