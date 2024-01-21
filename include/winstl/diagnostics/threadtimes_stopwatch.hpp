/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/threadtimes_stopwatch.hpp (formerly winstl::threadtimes_counter, winstl/performance/threadtimes_counter.hpp)
 *
 * Purpose:     WinSTL thread-time stopwatch class.
 *
 * Created:     22nd March 2002
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


/** \file winstl/diagnostics/threadtimes_stopwatch.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::threadtimes_stopwatch threadtimes_stopwatch\endlink class
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_THREADTIMES_STOPWATCH
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_THREADTIMES_STOPWATCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_THREADTIMES_STOPWATCH_MAJOR      5
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_THREADTIMES_STOPWATCH_MINOR      0
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_THREADTIMES_STOPWATCH_REVISION   2
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_THREADTIMES_STOPWATCH_EDIT       61
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

// class winstl::threadtimes_stopwatch
/** A stopwatch that provides thread-specific performance timings
 *
 * \ingroup group__library__Diagnostic
 *
 * This class uses the operating system's performance monitoring facilities to provide timing
 * information pertaining to the calling thread only, irrespective of the activities of other
 * threads on the system. This class does not provide meaningful timing information on operating
 * systems that do not provide thread-specific monitoring.
 */
class threadtimes_stopwatch
{
public:
    /// This type
    typedef threadtimes_stopwatch   class_type;

private:
    typedef ws_sint64_t             epoch_type;
public:
    /// The interval type
    ///
    /// The type of the interval measurement, a 64-bit signed integer
    typedef ws_sint64_t             interval_type;

// Construction
public:
    /// Constructor
    ///
    /// Creates an instance of the class, and caches the thread token so that measurements will
    /// be taken with respect to the thread in which the class was created.
    threadtimes_stopwatch();

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
    /// The number of whole nanoseconds in the measurement period for kernel mode activity
    ///
    /// This represents the extent, in whole nanoseconds, of the measurement period for kernel mode activity
    interval_type   get_kernel_nanoseconds() const;

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
    /// The number of whole nanoseconds in the measurement period for user mode activity
    ///
    /// This represents the extent, in whole nanoseconds, of the measurement period for user mode activity
    interval_type   get_user_nanoseconds() const;

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
    /// The number of whole nanoseconds in the measurement period
    ///
    /// This represents the extent, in whole nanoseconds, of the measurement period
    interval_type   get_nanoseconds() const;

private: // Implementation
    static epoch_type convert_(FILETIME const& ft);

// Members
private:
    epoch_type  m_kernelStart;
    epoch_type  m_kernelEnd;
    epoch_type  m_userStart;
    epoch_type  m_userEnd;
    HANDLE      m_thread;
};

////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
/* static */
threadtimes_stopwatch::epoch_type
threadtimes_stopwatch::convert_(FILETIME const& ft)
{
    epoch_type r = ft.dwHighDateTime;

    r <<= 32;

    r += ft.dwLowDateTime;

    return r;
}

inline
threadtimes_stopwatch::threadtimes_stopwatch()
    : m_thread(::GetCurrentThread())
{
    // Note that the constructor does nothing, for performance reasons. Calling
    // any of the Attribute methods before having gone through a start()-stop()
    // cycle will yield undefined results.
}

// Operations
inline
void
threadtimes_stopwatch::start()
{
    FILETIME    creationTime;
    FILETIME    exitTime;
    FILETIME    kernelTime;
    FILETIME    userTime;

    if (!::GetThreadTimes(m_thread, &creationTime, &exitTime, &kernelTime, &userTime))
    {
        m_kernelStart   =   0;
        m_userStart     =   0;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        ; // TODO: throw
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        m_kernelStart   =   convert_(kernelTime);
        m_userStart     =   convert_(userTime);
    }
}

inline
void
threadtimes_stopwatch::stop()
{
    FILETIME    creationTime;
    FILETIME    exitTime;
    FILETIME    kernelTime;
    FILETIME    userTime;

    if (!::GetThreadTimes(m_thread, &creationTime, &exitTime, &kernelTime, &userTime))
    {
        m_kernelEnd     =   0;
        m_userEnd       =   0;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        ; // TODO: throw
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        m_kernelEnd     =   convert_(kernelTime);
        m_userEnd       =   convert_(userTime);
    }
}

// Attributes

// Kernel
inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_kernel_period_count() const
{
    return static_cast<interval_type>(m_kernelEnd - m_kernelStart);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_kernel_seconds() const
{
    return get_kernel_period_count() / interval_type(10000000);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_kernel_milliseconds() const
{
    return get_kernel_period_count() / interval_type(10000);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_kernel_microseconds() const
{
    return get_kernel_period_count() / interval_type(10);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_kernel_nanoseconds() const
{
    return get_kernel_period_count() * interval_type(100);
}

// User
inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_user_period_count() const
{
    return static_cast<interval_type>(m_userEnd - m_userStart);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_user_seconds() const
{
    return get_user_period_count() / interval_type(10000000);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_user_milliseconds() const
{
    return get_user_period_count() / interval_type(10000);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_user_microseconds() const
{
    return get_user_period_count() / interval_type(10);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_user_nanoseconds() const
{
    return get_user_period_count() * interval_type(100);
}

// Total
inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_period_count() const
{
    return get_kernel_period_count() + get_user_period_count();
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_seconds() const
{
    return get_period_count() / interval_type(10000000);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_milliseconds() const
{
    return get_period_count() / interval_type(10000);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_microseconds() const
{
    return get_period_count() / interval_type(10);
}

inline
threadtimes_stopwatch::interval_type
threadtimes_stopwatch::get_nanoseconds() const
{
    return get_period_count() * interval_type(100);
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

#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_THREADTIMES_STOPWATCH */

/* ///////////////////////////// end of file //////////////////////////// */

