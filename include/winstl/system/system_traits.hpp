/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/system_traits.hpp
 *
 * Purpose:     Contains the system_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
 * Updated:     1st January 2021
 *
 * Thanks to:   Austin Ziegler for spotting the defective pre-condition
 *              enforcement of expand_environment_strings().
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/system/system_traits.hpp
 *
 * \brief [C++] Definition of the winstl::system_traits traits
 *  class
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_MAJOR       6
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_MINOR       0
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_REVISION    4
# define WINSTL_VER_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS_EDIT        165
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS
# include <stlsoft/string/c_string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#if defined(WINSTL_OS_IS_WIN64) || \
    defined(_Wp64)

# define _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING
#endif /* _WIN64 || _M_IA64 */

#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST
#   include <stlsoft/conversion/truncation_cast.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST */
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST
#   include <stlsoft/conversion/truncation_test.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST */
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

#if STLSOFT_LEAD_VER >= 0x010a0000
# ifndef WINSTL_INCL_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS
#  include <winstl/system/directory_functions.h>
# endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_DIRECTORY_FUNCTIONS */
#endif /* STLSoft 1.10+ */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS
# include <winstl/system/system_information_functions.h>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_SYSTEM_INFORMATION_FUNCTIONS */

#ifndef STLSOFT_INCL_H_CTYPE
# define STLSOFT_INCL_H_CTYPE
# include <ctype.h>
#endif /* !STLSOFT_INCL_H_CTYPE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary
# include <winstl/api/external/DynamicLinkLibrary.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary */
#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
# include <winstl/api/external/HandleAndObject.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */
#ifndef WINSTL_INCL_WINSTL_API_external_h_MemoryManagement
# include <winstl/api/external/MemoryManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_MemoryManagement */
#ifndef WINSTL_INCL_WINSTL_API_external_h_SystemInformation
# include <winstl/api/external/SystemInformation.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_SystemInformation */

#ifndef WINSTL_INCL_WINSTL_API_internal_h_DynamicLinkLibrary
# include <winstl/api/internal/DynamicLinkLibrary.h>
#endif /* !WINSTL_INCL_WINSTL_API_internal_h_DynamicLinkLibrary */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

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
    typedef ws_size_t                                       size_type;
    /// The difference type
    typedef ws_ptrdiff_t                                    difference_type;
    /// The current instantion of the type
    typedef system_traits<C>                                class_type;
    /// The (signed) integer type
    typedef ws_int_t                                        int_type;
    /// The Boolean type
    typedef ws_bool_t                                       bool_type;
    /// The type of a handle to a dynamically loaded module
    typedef HMODULE                                         module_type;
    /// The type of a handle to a kernel object
    typedef HANDLE                                          handle_type;
    /// The type of system result codes
    typedef DWORD                                           result_code_type;
    /// The type of system error codes
    typedef DWORD                                           error_type;
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

/// \name Locale management
/// @{
public:
    /// Returns the locale information
#ifndef NONLS
    static
    int_type
    get_locale_info(
        LCID        locale
    ,   LCTYPE      type
    ,   char_type*  data
    ,   int_type    cchData
    );
#endif /* !NONLS */
/// @}

/// \name System Paths
/// @{
public:
    /// Gets the full path name of the given module
    ///
    /// \param hModule The module handle. If \c nullptr then obtains the
    ///  full path of the executing module
    /// \param buffer Pointer to array of size \c cchBuffer. Must not be
    ///  \c nullptr unless \c cchBuffer is 0
    /// \param cchBuffer Size of the buffer, measured in characters,
    ///  available in \c buffer. Should include space for the terminating
    ///  \c NUL character
    ///
    /// \pre 0 == cchBuffer || nullptr != buffer
    static
    size_type
    get_module_filename(
        HMODULE     hModule
    ,   char_type   buffer[]
    ,   size_type   cchBuffer
    );

    /// Gets the full path name of the given module
    ///
    /// \param hModule The module handle. If \c nullptr then obtains the
    ///  full path of the executing module
    /// \param rb Reference to a resizeable buffer
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_module_filename(
        HMODULE             hModule
    ,   T_resizeableBuffer& rb
    );

    /// Gets the full path name of the directory of the given module
    ///
    /// \param hModule The module handle. If \c nullptr then obtains the
    ///  directory path of the executing module
    /// \param buffer Pointer to array of size \c cchBuffer. Must not be
    ///  \c nullptr unless \c cchBuffer is 0
    /// \param cchBuffer Size of the buffer, measured in characters,
    ///  available in \c buffer. Should include space for the terminating
    ///  \c NUL character
    ///
    /// \pre 0 == cchBuffer || nullptr != buffer
    static
    size_type
    get_module_directory(
        HMODULE     hModule
    ,   char_type   buffer[]
    ,   size_type   cchBuffer
    );

    /// Gets the full path name of the system directory
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
    get_system_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    );

    /// Gets the full path name of the system directory
    ///
    /// \param rb Reference to a resizeable buffer
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_system_directory(
        T_resizeableBuffer& rb
    );

    /// Gets the full path name of the Windows directory
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
    get_windows_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    );

    /// Gets the full path name of the Windows directory
    ///
    /// \param rb Reference to a resizeable buffer
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_windows_directory(
        T_resizeableBuffer& rb
    );

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

/// \name System Information
/// @{
public:
    /// Gets the host name
    ///
    /// \pre 0 == cchBuffer || nullptr != buffer
    static
    size_type
    get_host_name(
        char_type   buffer[]
    ,   size_type   cchBuffer
    );
    /// Gets the user name
    ///
    /// \pre 0 == cchBuffer || nullptr != buffer
    static
    size_type
    get_user_name(
        char_type   buffer[]
    ,   size_type   cchBuffer
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
    FARPROC
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
    typedef ws_size_t                                       size_type;
    typedef ws_ptrdiff_t                                    difference_type;
    typedef system_traits_                                  class_type;
    typedef ws_int_t                                        int_type;
    typedef ws_bool_t                                       bool_type;
    typedef HMODULE                                         module_type;
    typedef HANDLE                                          handle_type;
    typedef DWORD                                           result_code_type;
    typedef DWORD                                           error_type;

public:
    static bool_type close_handle(handle_type h)
    {
        return FALSE != WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(h);
    }

public:
    static bool_type free_library(module_type hModule)
    {
        return FALSE != WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(hModule);
    }

    static
    FARPROC
    find_symbol(
        module_type hModule
    ,   char const* symbolName
    )
    {
        WINSTL_ASSERT(NULL != symbolName);

        return WINSTL_API_EXTERNAL_DynamicLinkLibrary_GetProcAddress(hModule, symbolName);
    }

public:
    static error_type get_success_code()
    {
        return ERROR_SUCCESS;
    }

    static error_type get_last_error()
    {
        return WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();
    }

    static void set_last_error(error_type er)
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(er);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct system_traits<ws_char_a_t>
    : public STLSOFT_NS_QUAL(c_string_traits)<ws_char_a_t>
{
public:
    typedef ws_char_a_t                                     char_type;
    typedef ws_size_t                                       size_type;
    typedef ws_ptrdiff_t                                    difference_type;
    typedef system_traits<char_type>                        class_type;
    typedef ws_int_t                                        int_type;
    typedef ws_bool_t                                       bool_type;
    typedef HMODULE                                         module_type;
    typedef HANDLE                                          handle_type;
    typedef DWORD                                           result_code_type;
    typedef DWORD                                           error_type;

public:
    static
    int_type
    path_str_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    )
    {
        WINSTL_ASSERT(NULL != ps1);
        WINSTL_ASSERT(NULL != ps2);

        for (;; ++ps1, ++ps2)
        {
            int_type d = int_type(*ps1) - int_type(*ps2);

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
        WINSTL_ASSERT(NULL != ps1);
        WINSTL_ASSERT(NULL != ps2);

        for (; 0 != cch; ++ps1, ++ps2, --cch)
        {
            int_type d = int_type(*ps1) - int_type(*ps2);

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

            if (0 != d)
            {
                return d;
            }
        }

        return 0;
    }

public:
#ifndef NONLS
    static
    int_type
    get_locale_info(
        LCID        locale
    ,   LCTYPE      type
    ,   char_type*  data
    ,   int_type    cchData
    )
    {
        return ::GetLocaleInfoA(locale, type, data, cchData);
    }
#endif /* !NONLS */

public:
    static
    size_type
    get_module_filename(
        HMODULE     hModule
    ,   char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetModuleFileNameA(hModule, buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_module_filename(
        HMODULE             hModule
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_module_filename(hModule, static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return get_module_filename(hModule, &rb[0], rb.size());
    }

    static
    size_type
    get_module_directory(
        HMODULE     hModule
    ,   char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        size_type cch = get_module_filename(hModule, buffer, cchBuffer);

        if (0 != cch &&
            cch < cchBuffer)
        {
            buffer[cch] = '\0';

            char_type *s = str_rchr(buffer, '\\');

            if (NULL != s)
            {
                *s = '\0';

                cch = static_cast<size_type>(s - buffer);
            }
        }

        return cch;
    }

    static
    size_type
    get_system_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetSystemDirectoryA(buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_system_directory(
        T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_system_directory(static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return get_system_directory(&rb[0], rb.size());
    }

    static size_type get_windows_directory(char_type* buffer, size_type cchBuffer)
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetWindowsDirectoryA(buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_windows_directory(
        T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_windows_directory(static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return get_windows_directory(&rb[0], rb.size());
    }

    static
    size_type
    get_home_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return winstl_C_get_home_directory_a(buffer, cchBuffer);
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
    static size_type get_host_name(char_type* buffer, size_type cchBuffer)
    {
        return winstl_C_get_computer_name_a(buffer, cchBuffer);
    }
    static size_type get_user_name(char_type* buffer, size_type cchBuffer)
    {
        return winstl_C_get_user_name_a(buffer, cchBuffer);
    }

public:
    static module_type load_library(char_type const* name)
    {
        WINSTL_ASSERT(NULL != name);

        return WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryA(name);
    }

    static bool_type free_library(module_type hModule)
    {
        return system_traits_::free_library(hModule);
    }

    static
    FARPROC
    find_symbol(
        module_type hModule
    ,   char const* symbolName
    )
    {
        WINSTL_ASSERT(NULL != symbolName);

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
    {
        WINSTL_ASSERT(NULL != name);
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetEnvironmentVariableA(name, buffer, cchBuffer);
    }

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
    {
        WINSTL_ASSERT(NULL != src);
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::ExpandEnvironmentStringsA(src, buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = expand_environment_strings(src, static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return expand_environment_strings(src, &rb[0], rb.size());
    }

private:
    static size_type GetModuleFileNameA(HMODULE hModule, char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_INTERNAL_DynamicLinkLibrary_GetModuleFileNameA(hModule, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_INTERNAL_DynamicLinkLibrary_GetModuleFileNameA(hModule, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_INTERNAL_DynamicLinkLibrary_GetModuleFileNameA(hModule, buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetSystemDirectoryA(char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_GetSystemDirectoryA(buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_GetSystemDirectoryA(buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_GetSystemDirectoryA(buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetWindowsDirectoryA(char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryA(buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryA(buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryA(buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetEnvironmentVariableA(char_type const* name, char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_GetEnvironmentVariableA(name, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_GetEnvironmentVariableA(name, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_GetEnvironmentVariableA(name, buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type ExpandEnvironmentStringsA(char_type const* src, char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_ExpandEnvironmentStringsA(src, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_ExpandEnvironmentStringsA(src, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_ExpandEnvironmentStringsA(src, buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct system_traits<ws_char_w_t>
    : public STLSOFT_NS_QUAL(c_string_traits)<ws_char_w_t>
{
public:
    typedef ws_char_w_t                                     char_type;
    typedef ws_size_t                                       size_type;
    typedef ws_ptrdiff_t                                    difference_type;
    typedef system_traits<char_type>                        class_type;
    typedef ws_int_t                                        int_type;
    typedef ws_bool_t                                       bool_type;
    typedef HMODULE                                         module_type;
    typedef HANDLE                                          handle_type;
    typedef DWORD                                           result_code_type;
    typedef DWORD                                           error_type;

public:
    static
    int_type
    path_str_compare(
        char_type const*    ps1
    ,   char_type const*    ps2
    )
    {
        WINSTL_ASSERT(NULL != ps1);
        WINSTL_ASSERT(NULL != ps2);

        for (;; ++ps1, ++ps2)
        {
            int_type d = int_type(*ps1) - int_type(*ps2);

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
        WINSTL_ASSERT(NULL != ps1);
        WINSTL_ASSERT(NULL != ps2);

        for (; 0 != cch; ++ps1, ++ps2, --cch)
        {
            int_type d = int_type(*ps1) - int_type(*ps2);

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

            if (0 != d)
            {
                return d;
            }
        }

        return 0;
    }

public:
#ifndef NONLS
    static
    int_type
    get_locale_info(
        LCID        locale
    ,   LCTYPE      type
    ,   char_type*  data
    ,   int_type    cchData
    )
    {
        return ::GetLocaleInfoW(locale, type, data, cchData);
    }
#endif /* !NONLS */

public:
    static
    size_type
    get_module_filename(
        HMODULE     hModule
    ,   char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetModuleFileNameW(hModule, buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_module_filename(
        HMODULE             hModule
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_module_filename(hModule, static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return get_module_filename(hModule, &rb[0], rb.size());
    }

    static
    size_type
    get_module_directory(
        HMODULE     hModule
    ,   char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        size_type cch = get_module_filename(hModule, buffer, cchBuffer);

        if (0 != cch &&
            cch < cchBuffer)
        {
            buffer[cch] = '\0';

            char_type *s = str_rchr(buffer, '\\');

            if (NULL != s)
            {
                *s = '\0';

                cch = static_cast<size_type>(s - buffer);
            }
        }

        return cch;
    }

    static
    size_type
    get_system_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetSystemDirectoryW(buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_system_directory(
        T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_system_directory(static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return get_system_directory(&rb[0], rb.size());
    }

    static size_type get_windows_directory(char_type* buffer, size_type cchBuffer)
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetWindowsDirectoryW(buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_windows_directory(
        T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_windows_directory(static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return get_windows_directory(&rb[0], rb.size());
    }

    static
    size_type
    get_home_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return winstl_C_get_home_directory_w(buffer, cchBuffer);
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
    static size_type get_host_name(char_type* buffer, size_type cchBuffer)
    {
        return winstl_C_get_computer_name_w(buffer, cchBuffer);
    }
    static size_type get_user_name(char_type* buffer, size_type cchBuffer)
    {
        return winstl_C_get_user_name_w(buffer, cchBuffer);
    }

public:
    static module_type load_library(char_type const* name)
    {
        WINSTL_ASSERT(NULL != name);

        return WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryW(name);
    }

    static bool_type free_library(module_type hModule)
    {
        return system_traits_::free_library(hModule);
    }

    static
    FARPROC
    find_symbol(
        module_type hModule
    ,   char const* symbolName
    )
    {
        WINSTL_ASSERT(NULL != symbolName);

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
    {
        WINSTL_ASSERT(NULL != name);
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::GetEnvironmentVariableW(name, buffer, cchBuffer);
    }

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
    {
        WINSTL_ASSERT(NULL != src);
        WINSTL_ASSERT(NULL != buffer || 0 == cchBuffer);

        return class_type::ExpandEnvironmentStringsW(src, buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    expand_environment_strings(
        char_type const*    src
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = expand_environment_strings(src, static_cast<char_type*>(NULL), 0);

        rb.resize(cchRequired);

        return expand_environment_strings(src, &rb[0], rb.size());
    }

private:
    static size_type GetModuleFileNameW(HMODULE hModule, char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_INTERNAL_DynamicLinkLibrary_GetModuleFileNameW(hModule, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_INTERNAL_DynamicLinkLibrary_GetModuleFileNameW(hModule, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_INTERNAL_DynamicLinkLibrary_GetModuleFileNameW(hModule, buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetSystemDirectoryW(char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_GetSystemDirectoryW(buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_GetSystemDirectoryW(buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_GetSystemDirectoryW(buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetWindowsDirectoryW(char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryW(buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryW(buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_GetWindowsDirectoryW(buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetEnvironmentVariableW(char_type const* name, char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_GetEnvironmentVariableW(name, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_GetEnvironmentVariableW(name, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_GetEnvironmentVariableW(name, buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type ExpandEnvironmentStringsW(char_type const* src, char_type* buffer, size_type cchBuffer)
    {
#ifdef _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_SystemInformation_ExpandEnvironmentStringsW(src, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_SystemInformation_ExpandEnvironmentStringsW(src, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_SystemInformation_ExpandEnvironmentStringsW(src, buffer, cchBuffer);
#endif /* _WINSTL_SYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }
};

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

