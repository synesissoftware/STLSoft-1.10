/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/diagnostics/processtimes_stopwatch.hpp (formerly unixstl::processtimes_counter, unixstl/performance/processtimes_counter.hpp)
 *
 * Purpose:     UNIXSTL process-time stopwatch class.
 *
 * Created:     9th June 2006
 * Updated:     24th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/diagnostics/processtimes_stopwatch.hpp
 *
 * \brief [C++] Definition of the
 *  \link unixstl::processtimes_stopwatch processtimes_stopwatch\endlink class
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH
#define UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_MAJOR       2
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_MINOR       0
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_REVISION    2
# define UNIXSTL_VER_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH_EDIT        24
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
#ifndef STLSOFT_INCL_SYS_H_RESOURCE
# define STLSOFT_INCL_SYS_H_RESOURCE
# include <sys/resource.h>
#endif /* !STLSOFT_INCL_SYS_H_RESOURCE */

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

// class unixstl::processtimes_stopwatch
/** A stopwatch that provides process-specific performance timings
 *
 * \ingroup group__library__Diagnostic
 *
 * This class uses the operating system's performance monitoring facilities to provide timing
 * information pertaining to the calling process only, irrespective of the activities of other
 * processes on the system. This class does not provide meaningful timing information on operating
 * systems that do not provide process-specific monitoring.
 */
class processtimes_stopwatch
{
public:
    typedef processtimes_stopwatch    class_type;
    typedef us_sint64_t             epoch_type;

public:
    /// The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef us_sint64_t             interval_type;

// Construction
public:
    processtimes_stopwatch();

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
    // Kernel

    /// The elapsed count in the measurement period for kernel mode activity
    ///
    /// This represents the extent, in machine-specific increments, of the measurement period for kernel mode activity
    interval_type   get_kernel_period_count() const;
    /// The number of whole seconds in the measurement period for kernel mode activity
    ///
    /// This represents the extent, in whole seconds, of the measurement period for kernel mode activity
    interval_type   get_kernel_seconds() const;
    /// The number of whole milliseconds in the measurement period for kernel mode activity
    ///
    /// This represents the extent, in whole milliseconds, of the measurement period for kernel mode activity
    interval_type   get_kernel_milliseconds() const;
    /// The number of whole microseconds in the measurement period for kernel mode activity
    ///
    /// This represents the extent, in whole microseconds, of the measurement period for kernel mode activity
    interval_type   get_kernel_microseconds() const;

    // User

    /// The elapsed count in the measurement period for user mode activity
    ///
    /// This represents the extent, in machine-specific increments, of the measurement period for user mode activity
    interval_type   get_user_period_count() const;
    /// The number of whole seconds in the measurement period for user mode activity
    ///
    /// This represents the extent, in whole seconds, of the measurement period for user mode activity
    interval_type   get_user_seconds() const;
    /// The number of whole milliseconds in the measurement period for user mode activity
    ///
    /// This represents the extent, in whole milliseconds, of the measurement period for user mode activity
    interval_type   get_user_milliseconds() const;
    /// The number of whole microseconds in the measurement period for user mode activity
    ///
    /// This represents the extent, in whole microseconds, of the measurement period for user mode activity
    interval_type   get_user_microseconds() const;

    // Total

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

// Members
private:
    typedef struct timeval timeval_t;

    timeval_t   m_kernelStart;
    timeval_t   m_kernelEnd;
    timeval_t   m_userStart;
    timeval_t   m_userEnd;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
processtimes_stopwatch::processtimes_stopwatch()
{
    // Note that the constructor does nothing, for performance reasons. Calling
    // any of the Attribute methods before having gone through a start()-stop()
    // cycle will yield undefined results.
}

// Operations
inline
void
processtimes_stopwatch::start()
{
    struct rusage   r_usage;

    ::getrusage(RUSAGE_SELF, &r_usage);

    m_kernelStart   =   r_usage.ru_stime;
    m_userStart     =   r_usage.ru_utime;
}

inline
void
processtimes_stopwatch::stop()
{
    struct rusage   r_usage;

    ::getrusage(RUSAGE_SELF, &r_usage);

    m_kernelEnd     =   r_usage.ru_stime;
    m_userEnd       =   r_usage.ru_utime;
}

// Kernel
inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_kernel_period_count() const
{
    return get_kernel_microseconds();
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_kernel_seconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_kernelStart.tv_sec <= m_kernelEnd.tv_sec);

    long    secs    =   m_kernelEnd.tv_sec - m_kernelStart.tv_sec;
    long    usecs   =   m_kernelEnd.tv_usec - m_kernelStart.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs + usecs / (1000 * 1000);
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_kernel_milliseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_kernelStart.tv_sec <= m_kernelEnd.tv_sec);

    long    secs    =   m_kernelEnd.tv_sec - m_kernelStart.tv_sec;
    long    usecs   =   m_kernelEnd.tv_usec - m_kernelStart.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * 1000 + usecs / 1000;
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_kernel_microseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_kernelStart.tv_sec <= m_kernelEnd.tv_sec);

    long    secs    =   m_kernelEnd.tv_sec - m_kernelStart.tv_sec;
    long    usecs   =   m_kernelEnd.tv_usec - m_kernelStart.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * (1000 * 1000) + usecs;
}

// User
inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_user_period_count() const
{
    return get_user_microseconds();
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_user_seconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_userStart.tv_sec <= m_userEnd.tv_sec);

    long    secs    =   m_userEnd.tv_sec - m_userStart.tv_sec;
    long    usecs   =   m_userEnd.tv_usec - m_userStart.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs + usecs / (1000 * 1000);
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_user_milliseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_userStart.tv_sec <= m_userEnd.tv_sec);

    long    secs    =   m_userEnd.tv_sec - m_userStart.tv_sec;
    long    usecs   =   m_userEnd.tv_usec - m_userStart.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * 1000 + usecs / 1000;
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_user_microseconds() const
{
    UNIXSTL_MESSAGE_ASSERT("end before start: stop() must be called after start()", m_userStart.tv_sec <= m_userEnd.tv_sec);

    long    secs    =   m_userEnd.tv_sec - m_userStart.tv_sec;
    long    usecs   =   m_userEnd.tv_usec - m_userStart.tv_usec;

    UNIXSTL_ASSERT(usecs >= 0 || secs > 0);

    return secs * (1000 * 1000) + usecs;
}

// Total
inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_period_count() const
{
    return get_kernel_period_count() + get_user_period_count();
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_seconds() const
{
    return get_period_count() / interval_type(10000000);
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_milliseconds() const
{
    return get_period_count() / interval_type(10000);
}

inline
processtimes_stopwatch::interval_type
processtimes_stopwatch::get_microseconds() const
{
    return get_period_count() / interval_type(10);
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

#endif /* !UNIXSTL_INCL_UNIXSTL_DIAGNOSTICS_HPP_PROCESSTIMES_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

