/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/system_info.hpp
 *
 * Purpose:     Contains the basic_system_info class, which provides information
 *              regarding the host system, such as number of processors and
 *              page size.
 *
 * Created:     7th February 2002
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


/** \file winstl/system/system_info.hpp
 *
 * \brief [C++] Definition of the winstl::system_info class
 *  template
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_INFO
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_INFO

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_INFO_MAJOR     4
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_INFO_MINOR     1
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_INFO_REVISION  8
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_INFO_EDIT      74
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

/** Provides system information, which provides information regarding
 *  the host system, such as number of processors and page size
 *
 * \ingroup group__library__System
 *
 * This class wraps the GetSystemInfo() API function. Since the information that
 * this function provides is constant for any particular active system for its
 * lifetime, the function is called only once, as implemented via the
 * get_systeminfo_() method.
 */
class system_info
{
public:
    /// This type
    typedef system_info class_type;

// Construction
private:
    system_info();
    ~system_info() STLSOFT_NOEXCEPT;

// Operations
public:
    /// Value indicating the architecture of the host machine
    static ws_uint16_t processor_architecture()
    {
        return get_systeminfo_().wProcessorArchitecture;
    }

    /// Returns the number of processes on the host machine
    static ws_uint32_t number_of_processors()
    {
        return get_systeminfo_().dwNumberOfProcessors;
    }

    /// Returns the page size of the host machine
    static ws_size_t page_size()
    {
        return get_systeminfo_().dwPageSize;
    }

    /// Returns the allocation granularity of the host machine
    static ws_size_t allocation_granularity()
    {
        return get_systeminfo_().dwAllocationGranularity;
    }

    /// Provides a non-mutable (const) reference to the \c SYSTEM_INFO instance
    static SYSTEM_INFO const& get_systeminfo()
    {
        return get_systeminfo_();
    }

// Implementation
private:
    /// Unfortunately, something in this technique scares the Borland compilers (5.5
    /// and 5.51) into Internal compiler errors so the s_init variable in
    /// get_systeminfo_() is int rather than bool when compiling for borland.
    static SYSTEM_INFO const& get_systeminfo_()
    {
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
  // Safe to suppress these warnings, because race-conditions are benign here
# pragma warning(push)
# pragma warning(disable : 4640)
#endif /* compiler */

        static SYSTEM_INFO  s_systeminfo;
#ifdef STLSOFT_COMPILER_IS_BORLAND
        /* WSCB: Borland has an internal compiler error if use ws_bool_t */
        static ws_int_t     s_init = (::GetSystemInfo(&s_systeminfo), ws_true_v);
#else /* ? compiler */
        static ws_bool_t    s_init = (::GetSystemInfo(&s_systeminfo), ws_true_v);
#endif /* compiler */

        STLSOFT_SUPPRESS_UNUSED(s_init);

        return s_systeminfo;

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(pop)
#endif /* compiler */
    }
};

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_INFO */

/* ///////////////////////////// end of file //////////////////////////// */

