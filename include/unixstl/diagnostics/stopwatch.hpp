/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/diagnostics/stopwatch.hpp (formerly unixstl::performance_counter, unixstl/performance/performance_counter.hpp)
 *
 * Purpose:     stopwatch class.
 *
 * Created:     16th January 2002
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


/** \file unixstl/diagnostics/stopwatch.hpp
 *
 * \brief [C++] Definition of the
 *  \link unixstl::stopwatch stopwatch\endlink class
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_STOPWATCH
#define UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_STOPWATCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_STOPWATCH_MAJOR    5
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_STOPWATCH_MINOR    1
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_STOPWATCH_REVISION 1
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_STOPWATCH_EDIT     77
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_SYS_H_TIME
# define STLSOFT_INCL_SYS_H_TIME
# include <sys/time.h>
#endif /* !STLSOFT_INCL_SYS_H_TIME */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** A stopwatch using \c gettimeofday()
 *
 * \ingroup group__library__Diagnostic
 *
 * This class provides performance monitoring functionality based around the
 * UNIX \c gettimeofday() API.
 */
class stopwatch
{
public: // Types
    /// The epoch type
    ///
    /// The type of the epoch measurement, a 64-bit signed integer.
    typedef struct timeval                                  epoch_type;
    /// The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef us_sint64_t                                     interval_type;
    /// The class type
    typedef stopwatch                                       class_type;

public: // Construction
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    stopwatch() // This is needed only to suppress compiler warnings about unused variables
    {}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

public: // Operations
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

public: // Attributes
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
    /// This represents the extent, in arbitrary units, of the measurement period
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

private: // Implementation
    static void measure_(epoch_type &epoch);

private: // Fields
    epoch_type  m_start;
    epoch_type  m_end;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
/* static */
void
stopwatch::measure_(
    stopwatch::epoch_type&  epoch
)
{
    ::gettimeofday(&epoch, NULL);
}

inline
void
stopwatch::start()
{
    measure_(m_start);

    m_end = m_start;
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

inline
/* static */
stopwatch::epoch_type
stopwatch::get_epoch()
{
    epoch_type epoch;

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
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", start.tv_sec <= end.tv_sec);

    long    secs    =   end.tv_sec - start.tv_sec;
    long    usecs   =   end.tv_usec - start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs + usecs / (1000 * 1000);
}

inline
/* static */
stopwatch::interval_type
stopwatch::get_milliseconds(
    stopwatch::epoch_type   start
,   stopwatch::epoch_type   end
)
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", start.tv_sec <= end.tv_sec);

    long    secs    =   end.tv_sec - start.tv_sec;
    long    usecs   =   end.tv_usec - start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * 1000 + usecs / 1000;
}

inline
/* static */
stopwatch::interval_type
stopwatch::get_microseconds(
    stopwatch::epoch_type   start
,   stopwatch::epoch_type   end
)
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", start.tv_sec <= end.tv_sec);

    long    secs    =   end.tv_sec - start.tv_sec;
    long    usecs   =   end.tv_usec - start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * (1000 * 1000) + usecs;
}

inline
stopwatch::interval_type
stopwatch::get_period_count() const
{
    return get_microseconds();
}

inline
stopwatch::interval_type
stopwatch::get_seconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_start.tv_sec <= m_end.tv_sec);

    long    secs    =   m_end.tv_sec - m_start.tv_sec;
    long    usecs   =   m_end.tv_usec - m_start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs + usecs / (1000 * 1000);
}

inline
stopwatch::interval_type
stopwatch::get_milliseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_start.tv_sec <= m_end.tv_sec);

    long    secs    =   m_end.tv_sec - m_start.tv_sec;
    long    usecs   =   m_end.tv_usec - m_start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * 1000 + usecs / 1000;
}

inline
stopwatch::interval_type
stopwatch::get_microseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_start.tv_sec <= m_end.tv_sec);

    long    secs    =   m_end.tv_sec - m_start.tv_sec;
    long    usecs   =   m_end.tv_usec - m_start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * (1000 * 1000) + usecs;
}

inline
stopwatch::interval_type
stopwatch::get_nanoseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_start.tv_sec <= m_end.tv_sec);

    long    secs    =   m_end.tv_sec - m_start.tv_sec;
    long    usecs   =   m_end.tv_usec - m_start.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * (1000 * 1000 * 1000) + usecs * 1000;
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

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

