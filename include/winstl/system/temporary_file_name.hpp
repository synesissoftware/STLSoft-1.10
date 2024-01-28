/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/temporary_file_name.hpp
 *
 * Purpose:     Simple class that gets, and makes accessible, a temporary
 *              file name.
 *
 * Created:     5th June 2011
 * Updated:     22nd January 2024
 *
 * Thanks to:   Pablo Aguilar for requesting this component.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/system/temporary_file_name.hpp
 *
 * \brief [C++] Definition of the winstl::basic_temporary_file_name class
 *  template
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_TEMPORARY_FILE_NAME
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_TEMPORARY_FILE_NAME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_TEMPORARY_FILE_NAME_MAJOR     1
# define WINSTL_VER_WINSTL_SYSTEM_HPP_TEMPORARY_FILE_NAME_MINOR     2
# define WINSTL_VER_WINSTL_SYSTEM_HPP_TEMPORARY_FILE_NAME_REVISION  2
# define WINSTL_VER_WINSTL_SYSTEM_HPP_TEMPORARY_FILE_NAME_EDIT      22
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE
# include <stlsoft/string/special_string_instance.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_ERROR_HPP_WINDOWS_EXCEPTIONS
#  include <winstl/error/exceptions.hpp>
# endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_WINDOWS_EXCEPTIONS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX
# include <winstl/synch/spin_mutex.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_SPIN_MUTEX */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

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
 * Sub-project namespace
 */

STLSOFT_OPEN_WORKER_NS_(system_policies)

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** \ref group__pattern__special_string_instance "Special String Instance"
 *   policy template for eliciting the <b>Windows</b> directory.
 *
 * \ingroup group__library__System
 */
template <ss_typename_param_k C>
struct tempname_policy
{
/// \name Member Types
/// @{
public:
    typedef C                           char_type;
    typedef processheap_allocator<C>    allocator_type;
    typedef ws_size_t                   size_type;
    typedef size_type                   (*pfn_type)(char_type *, size_type);
    typedef winstl::spin_mutex          spin_mutex_type;
    typedef winstl::atomic_int_t        atomic_int_type;
private:
    typedef system_traits<char_type>    traits_type_;
/// @}

/// \name Member Constants
/// @{
public:
    enum { internalBufferSize       =   128 };

    enum { allowImplicitConversion  =   1   };

    enum { caseSensitive            =   0   };

    enum { sharedState              =   0   };
/// @}

/// \name Operations
/// @{
public:
    static pfn_type get_fn()
    {
        return /* winstl::system_traits<char_type>:: */get_temporary_file_name;
    }

    static
    size_type
    initial_size()
    {
        return 1 + WINSTL_CONST_MAX_PATH;
    }
/// @}

/// \name Implementation
private:
    // TODO: move these into system_traits<>

    static size_type get_temporary_file_name(ws_char_a_t* buff, size_type cchBuff)
    {
        WINSTL_ASSERT(0 == cchBuff || NULL != buff);

        // No need for truncation test/cast here.
        ws_char_a_t dirPath_[1 + MAX_PATH] = { 0 } ;
        ws_char_a_t filePath_[1 + MAX_PATH] = { 0 } ;

        DWORD const dw = ::GetTempPathA(STLSOFT_NUM_ELEMENTS(dirPath_), &dirPath_[0]);

        if (0 == dw)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(windows_exception("could not elicit temporary directory", e));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            if (0 != cchBuff)
            {
                buff[0] = '\0';
            }

            return 0;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        UINT const  r   =   ::GetTempFileNameA(&dirPath_[0], "wst", 0, &filePath_[0]);

        if (0 == r)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(windows_exception("could not elicit temporary file name", e));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            if (0 != cchBuff)
            {
                buff[0] = '\0';
            }

            return 0;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        size_t      cch =   traits_type_::str_len(filePath_);

        if (0 != cchBuff)
        {
            if (cch > cchBuff)
            {
                cch = cchBuff;
            }

            traits_type_::char_copy(buff, filePath_, cch);

            if (cch < cchBuff)
            {
                buff[cch] = '\0';
            }
        }

        return cch;
    }
    static size_type get_temporary_file_name(ws_char_w_t* buff, size_type cchBuff)
    {
        WINSTL_ASSERT(0 == cchBuff || NULL != buff);

        // No need for truncation test/cast here.
        ws_char_w_t dirPath_[1 + MAX_PATH] = { 0 } ;
        ws_char_w_t filePath_[1 + MAX_PATH] = { 0 } ;

        DWORD const dw  =   ::GetTempPathW(STLSOFT_NUM_ELEMENTS(dirPath_), &dirPath_[0]);

        if (0 == dw)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(windows_exception("could not elicit temporary directory", e));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            if (0 != cchBuff)
            {
                buff[0] = '\0';
            }

            return 0;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        UINT const  r   =   ::GetTempFileNameW(&dirPath_[0], L"wst", 0, &filePath_[0]);

        if (0 == r)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(windows_exception("could not elicit temporary file name", e));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            if (0 != cchBuff)
            {
                buff[0] = '\0';
            }

            return 0;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        size_t      cch =   traits_type_::str_len(filePath_);

        if (0 != cchBuff)
        {
            if (cch > cchBuff)
            {
                cch = cchBuff;
            }

            traits_type_::char_copy(buff, filePath_, cch);

            if (cch < cchBuff)
            {
                buff[cch] = '\0';
            }
        }

        return cch;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Sub-project namespace
 */

STLSOFT_CLOSE_WORKER_NS_(system_policies)

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>Windows</b> directory; ANSI specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_0)<
    STLSOFT_WORKER_NS_QUAL_(system_policies, tempname_policy)<
        ws_char_a_t
    >
,   int
>                                                               temporary_file_name_a;

/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>Windows</b> directory; 'Unicode' specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_0)<
    STLSOFT_WORKER_NS_QUAL_(system_policies, tempname_policy)<
        ws_char_w_t
    >
,   int
>                                                               temporary_file_name_w;

/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>Windows</b> directory; TCHAR specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_0)<
    STLSOFT_WORKER_NS_QUAL_(system_policies, tempname_policy)<
        TCHAR
    >
,   int
>                                                               temporary_file_name;

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_TEMPORARY_FILE_NAME */

/* ///////////////////////////// end of file //////////////////////////// */

