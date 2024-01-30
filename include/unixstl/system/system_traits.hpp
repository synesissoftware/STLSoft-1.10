/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/system/system_traits.hpp
 *
 * Purpose:     Contains the system_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
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


/** \file unixstl/system/system_traits.hpp
 *
 * \brief [C++] Definition of the unixstl::system_traits traits
 *  class
 *   (\ref group__library__System "System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS
#define UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS_MAJOR     6
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS_MINOR     2
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS_REVISION  1
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS_EDIT      135
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

#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS
# include <unixstl/system/directory_functions.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_H_DIRECTORY_FUNCTIONS */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS
# include <stlsoft/string/c_string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS
# include <stlsoft/util/resizeable_buffer_helpers.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS */

#if defined(_WIN32) || \
    defined(_WIN64)
# include <ctype.h>
#endif /* Windows */
#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_FCNTL
# define STLSOFT_INCL_H_FCNTL
# include <fcntl.h>
#endif /* !STLSOFT_INCL_H_FCNTL */
#if defined(_WIN32) || \
    defined(_WIN64)
# include <io.h>
# if defined(STLSOFT_COMPILER_IS_INTEL) || \
     defined(STLSOFT_COMPILER_IS_MSVC)
#  include <direct.h>
# endif /* os && compiler */
#endif /* Windows */
#ifndef STLSOFT_INCL_H_DLFCN
# define STLSOFT_INCL_H_DLFCN
# include <dlfcn.h>
#endif /* !STLSOFT_INCL_H_DLFCN */
#ifndef STLSOFT_INCL_H_LIMITS
# define STLSOFT_INCL_H_LIMITS
# include <limits.h>
#endif /* !STLSOFT_INCL_H_LIMITS */
#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>
#endif /* !STLSOFT_INCL_H_STDIO */
#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>
#endif /* !STLSOFT_INCL_H_STDLIB */
#ifndef STLSOFT_INCL_H_UNISTD
# define STLSOFT_INCL_H_UNISTD
# include <unistd.h>
#endif /* !STLSOFT_INCL_H_UNISTD */
#ifndef STLSOFT_INCL_SYS_H_TYPES
# define STLSOFT_INCL_SYS_H_TYPES
# include <sys/types.h>
#endif /* !STLSOFT_INCL_SYS_H_TYPES */
#ifndef STLSOFT_INCL_SYS_H_STAT
# define STLSOFT_INCL_SYS_H_STAT
# include <sys/stat.h>
#endif /* !STLSOFT_INCL_SYS_H_STAT */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */
#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

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

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** Traits for accessing the correct system functions for a given
 *   character type.
 *
 * \ingroup group__library__System
 *
 * system_traits is a traits class for determining the correct system
 * structures and functions for a given character type.
 *
 * \param C The character type (e.g. \c char, \c wchar_t)
 */
template <ss_typename_param_k C>
struct system_traits
    : public stlsoft::c_string_traits<C>
{
/// \name Types
/// @{
public:
    /// The character type
    typedef C                                               char_type;
    /// The size type
    typedef us_size_t                                       size_type;
    /// The difference type
    typedef us_ptrdiff_t                                    difference_type;
    /// The current instantion of the type
    typedef system_traits<C>                                class_type;
    /// The (signed) integer type
    typedef us_int_t                                        int_type;
    /// The Boolean type
    typedef us_bool_t                                       bool_type;
    /// The type of a handle to a dynamically loaded module
    typedef void*                                           module_type;
    /// The type of a handle to a kernel object
    typedef int                                             handle_type;
    /// The type of system result codes
    typedef int                                             result_code_type;
    /// The type of system error codes
    typedef int                                             error_type;
/// @}

/// \name Path string handling
/// @{
public:
    /// Performs a semantic string comparison with specific handling for
    /// path string character rules on the ambient operating system
    ///
    /// \param ps1 C-style string pointer to the first path. May not be
    ///   \c null
    /// \param ps2 C-style string pointer to the first path. May not be
    ///   \c null
    ///
    /// \note This function does <em>not</em> perform analysis such as
    ///   canonicalisation of dots directories
    static
    int_type
    path_str_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    );

    /// Performs a semantic string comparison with specific handling for
    /// path string character rules on the ambient operating system
    ///
    /// \param ps1 C-style string pointer to the first path. May not be
    ///   \c null
    /// \param ps2 C-style string pointer to the first path. May not be
    ///   \c null
    /// \param cch Number of characters to compare
    ///
    /// \note This function does <em>not</em> perform analysis such as
    ///   canonicalisation of dots directories
    static
    int
    path_str_n_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    ,   size_type           cch
    );
/// @}

/// \name System Paths
/// @{
public:

    /// Gets the full path name of the current user's home directory
    ///
    /// \param buffer Pointer to array of size \c cchBuffer. Must not be
    ///  \c nullptr unless \c cchBuffer is 0
    /// \param cchBuffer Size of the buffer, measured in characters,
    ///  available in \c buffer. Should include space for the terminating
    ///  \c NUL character
    ///
    /// \pre 0 == cchBuffer || nullptr != buffer
    static
    size_type
    get_home_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    );

    /// Gets the full path name of the current user's home directory
    ///
    /// \param rb Reference to a resizeable buffer
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_home_directory(
        T_resizeableBuffer& rb
    );
/// @}

/// \name Dynamic Loading
/// @{
public:
    /// Loads the given executable module
    static
    module_type
    load_library(
        char_type const*    name
    );
    /// Closes the given executable module
    static
    bool_type
    free_library(
        module_type         hModule
    );
    /// Retrieves the given symbol from the library
    static
    void*
    find_symbol(
        module_type         hModule
    ,   char const*         symbolName
    );
/// @}

/// \name Kernel object control
/// @{
public:
    /// Closes the given operating system handle
    static bool_type    close_handle(handle_type h);
/// @}

/// \name Error
/// @{
public:
    /// Gives the failure code that represents success
    static error_type   get_success_code();
    /// Gives the last error
    static error_type   get_last_error();
    /// Sets the last error
    static void         set_last_error(error_type er);
/// @}

/// \name Environment
/// @{
public:
    /// Gets an environment variable into the given buffer
    ///
    /// \param name The name of the variable to find
    /// \param buffer The buffer in which to write the variable. If this is NULL, then the required length is returned
    /// \param cchBuffer The size of the buffer, in characters
    ///
    /// \pre NULL != name
    /// \pre 0 == cchBuffer || nullptr != buffer
    static
    size_type
    get_environment_variable(
        char_type const*    name
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    );

    /// Gets an environment variable into the given buffer
    ///
    /// \param name The name of the variable to find
    /// \param rb Reference to a resizeable buffer into which the
    ///   environment variable value is to be written
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_environment_variable(
        char_type const*    name
    ,   T_resizeableBuffer& rb
    );

    /// Expands environment strings in \c src into \c buffer, up to a maximum \c cchDest characters
    ///
    /// \pre NULL != src
    /// \pre 0 == cchBuffer || nullptr != buffer
    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    );

    /// Expands environment strings in \c src into the given buffer
    ///
    /// \param src The string to be expanded
    /// \param rb Reference to a resizeable buffer into which the
    ///   expansion is to be written
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   T_resizeableBuffer& rb
    );
/// @}
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct system_traits;

struct system_traits_
{
public: // types
    typedef us_size_t                                       size_type;
    typedef us_ptrdiff_t                                    difference_type;
    typedef us_int_t                                        int_type;
    typedef us_bool_t                                       bool_type;
    typedef void*                                           module_type;
    typedef int                                             handle_type;
    typedef int                                             result_code_type;
    typedef int                                             error_type;

public:
    static bool_type close_handle(handle_type h)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_INTEL))

        return 0 == ::_close(h);
#else /* ? _WIN32 */

        return 0 == ::close(h);
#endif /* _WIN32 */
    }

public:
    static bool_type free_library(module_type hModule)
    {
        return 0 == ::dlclose(hModule);
    }

    static
    void*
    find_symbol(
        module_type     hModule
    ,   char const*     symbolName
    )
    {
        UNIXSTL_ASSERT(NULL != symbolName);

        return ::dlsym(hModule, symbolName);
    }

public:
    static error_type get_success_code()
    {
        return 0;
    }

    static error_type get_last_error()
    {
        return errno;
    }

    static void set_last_error(error_type er)
    {
        errno = er;
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct system_traits<us_char_a_t>
    : public STLSOFT_NS_QUAL(c_string_traits)<us_char_a_t>
{
public:
    typedef us_char_a_t                                     char_type;
    typedef us_size_t                                       size_type;
    typedef us_ptrdiff_t                                    difference_type;
    typedef system_traits<us_char_a_t>                      class_type;
    typedef us_int_t                                        int_type;
    typedef us_bool_t                                       bool_type;
    typedef void*                                           module_type;
    typedef int                                             handle_type;
    typedef int                                             result_code_type;
    typedef int                                             error_type;

public:
    static
    int_type
    path_str_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    )
    {
        UNIXSTL_ASSERT(NULL != ps1);
        UNIXSTL_ASSERT(NULL != ps2);

        for (;; ++ps1, ++ps2)
        {
            int_type d = int_type(*ps1) - int_type(*ps2);

#ifdef _WIN32

            if (0 != d)
            {
                d = toupper(*ps1) - toupper(*ps2);
            }

            if (0 != d)
            {
                switch (*ps1)
                {
                case '/':
                case '\\':

                    switch (*ps2)
                    {
                    case '/':
                    case '\\':

                        d = 0;
                        break;
                    }
                    break;
                }
            }
#endif

            if (0 != d)
            {
                return d;
            }

            if ('\0' == *ps1)
            {
                break;
            }
        }

        return 0;
    }

    static
    int
    path_str_n_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    ,   size_type           cch
    )
    {
        UNIXSTL_ASSERT(NULL != ps1);
        UNIXSTL_ASSERT(NULL != ps2);

        for (; 0 != cch; ++ps1, ++ps2, --cch)
        {
            int_type d = int_type(*ps1) - int_type(*ps2);

#ifdef _WIN32

            if (0 != d)
            {
                d = toupper(*ps1) - toupper(*ps2);
            }

            if (0 != d)
            {
                switch (*ps1)
                {
                case '/':
                case '\\':

                    switch (*ps2)
                    {
                    case '/':
                    case '\\':

                        d = 0;
                        break;
                    }
                    break;
                }
            }
#endif

            if (0 != d)
            {
                return d;
            }
        }

        return 0;
    }

public:
    static
    size_type
    get_home_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        UNIXSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return unixstl_C_get_home_directory_a(buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_home_directory(
        T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_home_directory(static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return get_home_directory(&rb[0], rb.size());
    }

public:
    static module_type load_library(char_type const* name)
    {
        return ::dlopen(name, RTLD_NOW);
    }

    static bool_type free_library(module_type hModule)
    {
        return system_traits_::free_library(hModule);
    }

    static
    void*
    find_symbol(
        module_type     hModule
    ,   char const*     symbolName
    )
    {
        UNIXSTL_ASSERT(NULL != symbolName);

        return system_traits_::find_symbol(hModule, symbolName);
    }

public:
    static bool_type close_handle(handle_type h)
    {
        return system_traits_::close_handle(h);
    }

public:
    static error_type get_success_code()
    {
        return system_traits_::get_success_code();
    }

    static error_type get_last_error()
    {
        return system_traits_::get_last_error();
    }

    static void set_last_error(error_type er)
    {
        system_traits_::set_last_error(er);
    }

public:
# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>

    static
    size_type
    get_environment_variable(
        char_type const*    name
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        char const* var = ::getenv(name);

        if (NULL == var)
        {
            return 0;
        }
        else
        {
            us_size_t var_len = str_len(var);

            if (NULL == buffer)
            {
                return var_len;
            }
            else
            {
                size_type writtenLen = (var_len < cchBuffer) ? var_len : cchBuffer;

                char_copy(buffer, var, writtenLen);
                if (writtenLen < cchBuffer)
                {
                    buffer[writtenLen] = '\0';
                }

                return (var_len < cchBuffer) ? var_len : cchBuffer;
            }
        }
    }
# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_environment_variable(
        char_type const*    name
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_environment_variable(name, static_cast<char_type*>(NULL), 0);

        if (0 == cchRequired)
        {
            return 0;
        }

        rb.resize(cchRequired);

        return get_environment_variable(name, &rb[0], rb.size());
    }

    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    ;

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   T_resizeableBuffer& rb
    )
    ;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct system_traits<us_char_w_t>
    : public STLSOFT_NS_QUAL(c_string_traits)<us_char_w_t>
{
public:
    typedef us_char_w_t                                     char_type;
    typedef us_size_t                                       size_type;
    typedef us_ptrdiff_t                                    difference_type;
    typedef system_traits<us_char_a_t>                      class_type;
    typedef us_int_t                                        int_type;
    typedef us_bool_t                                       bool_type;
    typedef void*                                           module_type;
    typedef int                                             handle_type;
    typedef int                                             result_code_type;
    typedef int                                             error_type;

public:
    static
    int_type
    path_str_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    );

    static
    int
    path_str_n_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    ,   size_type           cch
    );

public:
    static
    size_type
    get_home_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        UNIXSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return unixstl_C_get_home_directory_w(buffer, cchBuffer);
    }

public:
    static module_type load_library(char_type const* name);

    static bool_type free_library(module_type hModule)
    {
        return 0 == ::dlclose(hModule);
    }

    static
    void*
    find_symbol(
        module_type     hModule
    ,   char const*     symbolName
    )
    {
        UNIXSTL_ASSERT(NULL != symbolName);

        return system_traits_::find_symbol(hModule, symbolName);
    }

public:
    static bool_type close_handle(handle_type h)
    {
        return system_traits_::close_handle(h);
    }

public:
    static error_type get_success_code()
    {
        return system_traits_::get_success_code();
    }

    static error_type get_last_error()
    {
        return system_traits_::get_last_error();
    }

    static void set_last_error(error_type er)
    {
        system_traits_::set_last_error(er);
    }

public:
    static
    size_type
    get_environment_variable(
        char_type const*    name
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    ;

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_environment_variable(
        char_type const*    name
    ,   T_resizeableBuffer& rb
    )
    ;

    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    ;

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   T_resizeableBuffer& rb
    )
    ;
};

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

#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

