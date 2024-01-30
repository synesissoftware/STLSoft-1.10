/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/special/errno_exception.hpp
 *
 * Purpose:     Defines the errno_exception exception class.
 *
 * Created:     17th May 2014
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2014-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/exception/special/errno_exception.hpp
 *
 * \brief [C++] Defines the errno_exception exception class
 *   (\ref group__library__exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION
#define STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION_MAJOR       1
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION_MINOR       1
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION_REVISION    5
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION_EDIT        14
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_NEW
# define STLSOFT_INCL_NEW
# include <new>
#endif /* !STLSOFT_INCL_NEW */
#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>
#endif /* !STLSOFT_INCL_STDEXCEPT */

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

class errno_exception
    : public std::runtime_error
{
public: // types
    typedef std::runtime_error                              parent_class_type;
    typedef errno_exception                                 class_type;

public: // construction
    /// Constructs an instance from the given errno value
    ss_explicit_k
    errno_exception(int e)
        : parent_class_type(make_message_(e))
        , ErrnoValue(e)
    {
        free_(context_);
    }
    /// Constructs an instance from the given errno value and message
    errno_exception(
        int         e
    ,   char const* message
    )
        : parent_class_type(message)
        , ErrnoValue(e)
    {}
    /// Constructs an instance from the given errno value and message
    template <ss_typename_param_k S>
    errno_exception(
        int         e
    ,   S const&    message
    )
        : parent_class_type(c_str_ptr_a(message))
        , ErrnoValue(e)
    {}
#if 0
#elif defined(__GNUC__)
    ~errno_exception() STLSOFT_NOEXCEPT_STDOVR
    {}
#endif

private:
    void operator =(class_type const&); // copy-assignment proscribed

private: // implementation
    char const*
    make_message_(
        int e
    )
    {
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        char        buff[1001];
        int const   e2  =   ::strerror_s(buff, e);
        char* const r   =   ::_strdup((0 == e2) ? buff : "unknown failure");

        if (NULL == r)
        {
            STLSOFT_THROW_X(std::bad_alloc());
        }

        context_ = r;

        return r;
#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
        context_ = NULL;

        return ::strerror(e);
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    }

    static
    void
    free_(
        void* pv
    )
    {
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        STLSOFT_ASSERT(NULL != pv);

        ::free(pv);
#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
        STLSOFT_ASSERT(NULL == pv);

        STLSOFT_SUPPRESS_UNUSED(pv);
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    }

public: // fields
    int const   ErrnoValue;
private:
    void*       context_;
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_ERRNO_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */

