/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/stopwatch.hpp (formerly winstl::performance_counter, winstl/performance/performance_counter.hpp)
 *
 * Purpose:     WinSTL general stopwatch class. This class attempts to
 *              use the built-in high-performance hardware counter if available,
 *              otherwise using the tick-count facilities.
 *
 * Created:     31st July 2002
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/diagnostics/stopwatch.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::stopwatch stopwatch\endlink class
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_STOPWATCH
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_STOPWATCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_STOPWATCH_MAJOR      5
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_STOPWATCH_MINOR      0
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_STOPWATCH_REVISION   3
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_STOPWATCH_EDIT       47
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

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.h>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_H_INTEGRAL_LIMITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STATIC_INITIALISERS
# include <stlsoft/util/static_initialisers.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STATIC_INITIALISERS */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */
#ifndef STLSOFT_CF_64BIT_INT_SUPPORT
# ifndef STLSOFT_INCL_STLSOFT_HPP_64BIT_INTEGERS
#  include <stlsoft/64bit_integers.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_HPP_64BIT_INTEGERS */
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */

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

// class winstl::stopwatch
/** A stopwatch that uses the most accurate measurement
 *   APIs available on the host machine
 *
 * \ingroup group__library__Diagnostic
 *
 * The following example illustrates the use of the counter to measure an
 * interval:
\code
winstl::stopwatch   counter;

counter.start();
for (size_t volatile i = 0; i != 0x7fffffff; ++i)
{}
counter.stop();

std::cout << "Number of seconds:      " << counter.get_seconds() << std::endl;
std::cout << "Number of milliseconds: " << counter.get_milliseconds() << std::endl;
std::cout << "Number of microseconds: " << counter.get_microseconds() << std::endl;
std::cout << "Number of nanoseconds:  " << counter.get_nanoseconds() << std::endl;
\endcode
 *
 * Note: Some standard libraries' IOStreams do not recognise the 64-bit
 * unsigned integer that is the counter class's <code>interval_type</code>
 * (and <code>epoch_type</code>), in which case you should use an
 * appropriate cast. The following code shows a cast to
 * <code>unsigned long</code>, but be aware that this may cause truncation
 * in the case where, say, the <code>unsigned long</code> type for your
 * compiler is 32-bits and the value returned by a given
 * <code>get_???()</code> method is > 4294967295.
\code
winstl::stopwatch   counter;

counter.start();
for (size_t volatile i = 0; i != 0x7fffffff; ++i)
{}
counter.stop();

std::cout << "Number of seconds:      " << static_cast<unsigned long>(counter.get_seconds()) << std::endl;
std::cout << "Number of milliseconds: " << static_cast<unsigned long>(counter.get_milliseconds()) << std::endl;
std::cout << "Number of microseconds: " << static_cast<unsigned long>(counter.get_microseconds()) << std::endl;
std::cout << "Number of nanoseconds:  " << static_cast<unsigned long>(counter.get_nanoseconds()) << std::endl;
\endcode
 *
 *
 * \remarks This class attempts to use the high performance hardware counter
 *  as its measurement resource, but failing that it defaults to less
 *  accurate resources in order to guarantee that meaningful measurements
 *  are always available to application code.
 */
class stopwatch
{
/// \name Member types
/// @{
public:
    /// The epoch type
    ///
    /// The type of the epoch measurement. This will be a 64-bit signed
    /// integer for compilers that such types, or a 32-bit integer
    /// otherwise.
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef ws_sint64_t                                     epoch_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef sinteger64                                      epoch_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    /// The interval type
    ///
    /// The type of the interval measurement. This will be a 64-bit signed
    /// integer for compilers that such types, or a 32-bit integer
    /// otherwise.
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef ws_sint64_t                                     interval_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef sinteger64                                      interval_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    /// The class type
    typedef stopwatch                                       class_type;
/// @}

/// \name Construction
/// @{
public:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    static void class_init()
    {
        class_type  instance;

        instance.start();
    }
    static void class_uninit()
    {}

    stopwatch() // This is needed only to suppress compiler warnings about unused variables
    {}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Operations
/// @{
public:
    /// Starts measurement
    ///
    /// Begins the measurement period
    void    start();
    /// Ends measurement
    ///
    /// Ends the measurement period
    void    stop();
    /// Ends the current measurement period and start the next
    ///
    /// \remarks This is equivalent to an atomic invocation of stop() and
    /// start()
    void    restart();
/// @}

/// \name Attributes
/// @{
public:
    /// The current epoch
    static epoch_type       get_epoch();

    /// The number of whole seconds in the given measurement period
    static interval_type    get_seconds(epoch_type start, epoch_type end);
    /// The number of whole milliseconds in the given measurement period
    static interval_type    get_milliseconds(epoch_type start, epoch_type end);
    /// The number of whole microseconds in the given measurement period
    static interval_type    get_microseconds(epoch_type start, epoch_type end);
    /// The number of whole nanoseconds in the given measurement period
    static interval_type    get_nanoseconds(epoch_type start, epoch_type end);

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

    /// Stops the current period, starts the next, and returns the
    ///  period count for the prior period.
    interval_type   stop_get_period_count_and_restart();

    /// Stops the current period, starts the next, and returns the
    ///  interval, in seconds, for the prior period.
    interval_type   stop_get_seconds_and_restart();

    /// Stops the current period, starts the next, and returns the
    ///  interval, in milliseconds, for the prior period.
    interval_type   stop_get_milliseconds_and_restart();

    /// Stops the current period, starts the next, and returns the
    ///  interval, in microseconds, for the prior period.
    interval_type   stop_get_microseconds_and_restart();

    /// Stops the current period, starts the next, and returns the
    ///  interval, in nanoseconds, for the prior period.
    interval_type   stop_get_nanoseconds_and_restart();
/// @}

/// \name Implementation
/// @{
private:
    typedef void (*measure_fn_type)(epoch_type&);

    static interval_type    frequency_();
    static interval_type    query_frequency_();
    static void             qpc_(epoch_type &epoch);
    static void             gtc_(epoch_type &epoch);
    static measure_fn_type  get_measure_fn_();
    static void             measure_(epoch_type &epoch);
/// @}

/// \name Members
/// @{
private:
    epoch_type  m_start;    // start of measurement period
    epoch_type  m_end;      // End of measurement period
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if !defined(STLSOFT_COMPILER_IS_DMC) && \
     (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
         _MSC_VER >= 1200)
static STLSOFT_NS_QUAL(class_constructor)<stopwatch>  s_stopwatch_class_constructor(&stopwatch::class_init, NULL);
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
/* static */
stopwatch::interval_type
stopwatch::query_frequency_()
{
    interval_type   frequency;

    // If no high-performance counter is available ...
    if (!WINSTL_API_EXTERNAL_Time_QueryPerformanceFrequency(sap_cast<LARGE_INTEGER*>(&frequency)) ||
        frequency == 0)
    {
        // ... then set the divisor to be the frequency for GetTickCount(), which is
        // 1000 since it returns intervals in milliseconds.
        frequency = 1000;
    }

    return frequency;
}

inline
/* static */
stopwatch::interval_type
stopwatch::frequency_()
{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
  // Safe to suppress these warnings, because race-conditions are benign here
# pragma warning(push)
# pragma warning(disable : 4640)
#endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
    interval_type           s_frequency = query_frequency_();
#else /* ? compiler */
    static interval_type    s_frequency = query_frequency_();
#endif /* compiler */

    WINSTL_ASSERT(0 != s_frequency);

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(pop)
#endif /* compiler */

    return s_frequency;
}

inline
/* static */
void
stopwatch::qpc_(
    epoch_type& epoch
)
{
    static_cast<void>(WINSTL_API_EXTERNAL_Time_QueryPerformanceCounter(sap_cast<LARGE_INTEGER*>(&epoch)));
}

inline
/* static */
void
stopwatch::gtc_(
    epoch_type& epoch
)
{
    epoch = static_cast<ws_sint32_t>(WINSTL_API_EXTERNAL_Time_GetTickCount());
}

inline
/* static */
stopwatch::measure_fn_type
stopwatch::get_measure_fn_()
{
    measure_fn_type fn;
    epoch_type      frequency;

    if (WINSTL_API_EXTERNAL_Time_QueryPerformanceFrequency(sap_cast<LARGE_INTEGER*>(&frequency)))
    {
        fn = qpc_;
    }
    else
    {
        fn = gtc_;
    }

    return fn;
}

inline
/* static */
void
stopwatch::measure_(
    epoch_type& epoch
)
{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
  // Safe to suppress these warnings, because race-conditions are benign here
# pragma warning(push)
# pragma warning(disable : 4640)
#endif /* compiler */

    static measure_fn_type  fn  =   get_measure_fn_();

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(pop)
#endif /* compiler */

    fn(epoch);
}

// Operations
inline
void
stopwatch::start()
{
    measure_(m_start);
}

inline
void
stopwatch::stop()
{
    measure_(m_end);
}

inline
void
stopwatch::restart()
{
    measure_(m_start);
    m_end = m_start;
}

// Attributes

inline
/* static */
stopwatch::epoch_type
stopwatch::get_epoch()
{
    epoch_type  epoch;

    measure_(epoch);

    return epoch;
}

inline
/* static */
stopwatch::interval_type
stopwatch::get_seconds(
    stopwatch::epoch_type   start
,   stopwatch::epoch_type   end
)
{
    interval_type   period_count    =   static_cast<interval_type>(end - start);

    return period_count / frequency_();
}

inline
/* static */
stopwatch::interval_type
stopwatch::get_milliseconds(
    stopwatch::epoch_type   start
,   stopwatch::epoch_type   end
)
{
    interval_type   result;
    interval_type   count   =   static_cast<interval_type>(end - start);

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x20C49BA5E353F7))
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    if (count < interval_type(0x20C49B, 0xA5E353F7))
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
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
/* static */
stopwatch::interval_type
stopwatch::get_microseconds(
    stopwatch::epoch_type   start
,   stopwatch::epoch_type   end
)
{
    interval_type   result;
    interval_type   count   =   static_cast<interval_type>(end - start);

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x8637BD05AF6))
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    if (count < interval_type(0x863, 0x7BD05AF6))
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
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
/* static */
stopwatch::interval_type
stopwatch::get_nanoseconds(
    stopwatch::epoch_type   start
,   stopwatch::epoch_type   end
)
{
    interval_type   result;
    interval_type   count   =   static_cast<interval_type>(end - start);

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x8637BD05AF6))
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    if (count < interval_type(0x863, 0x7BD05AF6))
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
    {
        result = (count * interval_type(1000000000)) / frequency_();
    }
    else
    {
        result = (count / frequency_()) * interval_type(1000000000);
    }

    return result;
}

inline
stopwatch::interval_type
stopwatch::get_period_count() const
{
    return static_cast<interval_type>(m_end - m_start);
}

inline
stopwatch::interval_type
stopwatch::get_seconds() const
{
    return get_period_count() / frequency_();
}

inline
stopwatch::interval_type
stopwatch::get_milliseconds() const
{
    interval_type   result;
    interval_type   count   =   get_period_count();

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x20C49BA5E353F7))
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    if (count < interval_type(0x20C49B, 0xA5E353F7))
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
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
stopwatch::interval_type
stopwatch::get_microseconds() const
{
    interval_type   result;
    interval_type   count   =   get_period_count();

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x8637BD05AF6))
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    if (count < interval_type(0x863, 0x7BD05AF6))
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
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
stopwatch::interval_type
stopwatch::get_nanoseconds() const
{
    interval_type   result;
    interval_type   count   =   get_period_count();

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    if (count < STLSOFT_GEN_SINT64_SUFFIX(0x8637BD05AF6))
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    if (count < interval_type(0x863, 0x7BD05AF6))
#endif /* !STLSOFT_CF_64BIT_INT_SUPPORT */
    {
        result = (count * interval_type(1000000000)) / frequency_();
    }
    else
    {
        result = (count / frequency_()) * interval_type(100000000);
    }

    return result;
}


inline
stopwatch::interval_type
stopwatch::stop_get_period_count_and_restart()
{
    stop();

    interval_type   interval    =   get_period_count();

    m_start = m_end;

    return interval;
}

inline
stopwatch::interval_type
stopwatch::stop_get_seconds_and_restart()
{
    stop();

    interval_type   interval    =   get_seconds();

    m_start = m_end;

    return interval;
}

inline
stopwatch::interval_type
stopwatch::stop_get_milliseconds_and_restart()
{
    stop();

    interval_type   interval    =   get_milliseconds();

    m_start = m_end;

    return interval;
}

inline
stopwatch::interval_type
stopwatch::stop_get_microseconds_and_restart()
{
    stop();

    interval_type   interval    =   get_microseconds();

    m_start = m_end;

    return interval;
}

inline
stopwatch::interval_type
stopwatch::stop_get_nanoseconds_and_restart()
{
    stop();

    interval_type   interval    =   get_nanoseconds();

    m_start = m_end;

    return interval;
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

#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

