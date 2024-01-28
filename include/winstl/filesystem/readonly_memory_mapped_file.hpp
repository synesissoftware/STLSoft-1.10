/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/readonly_memory_mapped_file.hpp
 *
 * Purpose:     Windows readonly (shareable) memory mapped file.
 *
 * Created:     30th August 2010
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/readonly_memory_mapped_file.hpp
 *
 * \brief [C++] Definition of the winstl::readonly_memory_mapped_file class
 *   template (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE_MAJOR     2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE_MINOR     0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE_REVISION  2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE_EDIT      17
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

#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_W2A
# include <winstl/conversion/w2a.hpp>
#endif /* !WINSTL_INCL_WINSTL_CONVERSION_HPP_W2A */
#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_ACCESS_EXCEPTION
# include <winstl/exception/access_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_ACCESS_EXCEPTION */
#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_FILESYSTEM_EXCEPTION
# include <winstl/exception/filesystem_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_FILESYSTEM_EXCEPTION */
#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_FILE_NOT_FOUND_EXCEPTION
# include <winstl/exception/file_not_found_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_FILE_NOT_FOUND_EXCEPTION */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS
# include <winstl/filesystem/memory_map_functions.h>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HANDLES_HPP_MEMORY_MAPPED_FILE_VIEW_HANDLE
# include <winstl/filesystem/handles/memory_mapped_file_view_handle.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HANDLES_HPP_MEMORY_MAPPED_FILE_VIEW_HANDLE */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
# include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION
# include <stlsoft/exception/out_of_memory_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR
# include <stlsoft/util/exception_string_creator.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING_CREATOR */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

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
 * classes
 */

/** Facade over the Win32 memory mapped file API.
 *
 * \ingroup group__library__FileSystem
 */
template <ss_typename_param_k R>
class readonly_memory_mapped_file_base
{
private: // Member Types
    typedef R                                                           refcount_policy_type_;
public:
    /// This type
    typedef readonly_memory_mapped_file_base<R>                         class_type;
    /// The size type
    ///
    /// This is an unsigned type that is capable of representing any
    /// address on the operating system. On 64-bit systems, it will
    /// be <code>uint64_t</code>; on 32-bit operating systems it will
    /// be <code>uint32_t</code>.
    typedef ws_uintptr_t                                                size_type;
    /// The error type
    typedef ws_dword_t                                                  status_code_type;
    /// The offset type
    typedef ws_uint64_t                                                 offset_type;
    /// The boolean type
    typedef ws_bool_t                                                   bool_type;

    /// The Handle::Ref+Wrapper <strong>HandleAdaptor</strong> type.
    ///
    /// \note This type is optional to the pattern.
    typedef memory_mapped_file_view_handle<
        refcount_policy_type_
    >                                                                   HRW_HandleAdaptor_type;
    /// The Handle::Ref+Wrapper <strong>Handle</strong> type.
    ///
    /// \note This type is mandatory to the pattern.
    typedef ss_typename_type_k HRW_HandleAdaptor_type::HRW_Handle_type  HRW_Handle_type;
    /// The Handle::Ref+Wrapper <strong>Ref</strong> type.
    ///
    /// \note This type is mandatory to the pattern.
    typedef ss_typename_type_k HRW_HandleAdaptor_type::HRW_Ref_type     HRW_Ref_type;
    /// The Handle::Ref+Wrapper <strong>Wrapper</strong> type.
    ///
    /// \note This type is mandatory to the pattern.
    typedef class_type                                                  HRW_Wrapper_type;

    typedef HRW_Handle_type                                             Handle;
    typedef HRW_Ref_type                                                Ref;
    typedef HRW_Wrapper_type                                            Wrapper;

public: // Construction
    /// Maps an entire file into memory
    ///
    /// \param fileName The name of the file to map into memory
    ///
    /// \exception winstl::winstl_exception Thrown if the map cannot be
    ///   created. May be any value returned by the Windows API; known
    ///   values include ERROR_NOT_ENOUGH_MEMORY (when the map size is
    ///   too large to fit into memory) and ERROR_INVALID_PARAMETER (when
    ///   the allocated size is too large to be valid
    ss_explicit_k
    readonly_memory_mapped_file_base(
        ws_char_a_t const* fileName
    )
        : m_ref(create_(fileName, 0, 0))
    {}
    /// Maps an entire file into memory
    ss_explicit_k
    readonly_memory_mapped_file_base(
        ws_char_w_t const* fileName
    )
        : m_ref(create_(fileName, 0, 0))
    {}
    /// Maps an entire file into memory
    template <ss_typename_param_k S>
    ss_explicit_k
    readonly_memory_mapped_file_base(
        S const& fileName
    )
        : m_ref(create_(STLSOFT_NS_QUAL(c_str_ptr)(fileName), 0, 0))
    {}
    /// Maps a portion of a file into memory
    ///
    /// \param fileName The name of the file to map into memory
    /// \param offset The offset into the file where the mapping
    ///   begins. Must be a multiple of the system allocation
    ///   granularity
    /// \param requestSize The size of the portion of the file
    ///   to map into memory. If 0, all (of the remaining portion)
    ///   of the file is loaded
    readonly_memory_mapped_file_base(
        ws_char_a_t const*  fileName
    ,   offset_type         offset
    ,   size_type           requestSize
    )
        : m_ref(create_(fileName, offset, requestSize))
    {}
    /// Maps a portion of a file into memory
    ///
    /// \param fileName The name of the file to map into memory
    /// \param offset The offset into the file where the mapping
    ///   begins. Must be a multiple of the system allocation
    ///   granularity
    /// \param requestSize The size of the portion of the file
    ///   to map into memory. If 0, all (of the remaining portion)
    ///   of the file is loaded
    readonly_memory_mapped_file_base(
        ws_char_w_t const*  fileName
    ,   offset_type         offset
    ,   size_type           requestSize
    )
        : m_ref(create_(fileName, offset, requestSize))
    {}
    /// Maps a portion of a file into memory
    ///
    /// \param fileName The name of the file to map into memory
    /// \param offset The offset into the file where the mapping
    ///   begins. Must be a multiple of the system allocation
    ///   granularity
    /// \param requestSize The size of the portion of the file
    ///   to map into memory. If 0, all (of the remaining portion)
    ///   of the file is loaded
    template <ss_typename_param_k S>
    readonly_memory_mapped_file_base(
        S const&    fileName
    ,   offset_type offset
    ,   size_type   requestSize
    )
        : m_ref(create_(STLSOFT_NS_QUAL(c_str_ptr)(fileName), offset, requestSize))
    {}

    /// Closes the view on the mapped file
    ~readonly_memory_mapped_file_base() STLSOFT_NOEXCEPT
    {}

    readonly_memory_mapped_file_base(class_type const& rhs)
        : m_ref(rhs.m_ref)
    {}
private:
    class_type& operator =(class_type const&);
public:

    /// Returns the Handle::Ref+Wrapper <strong>Ref</strong>, which
    /// encapsulates a shared memory mapped file view handle.
    Ref get() const STLSOFT_NOEXCEPT
    {
        return m_ref;
    }

    /// Swaps the state of this instance with another
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        m_ref.swap(rhs.m_ref);
    }

public: // Accessors
    /// Non-mutating (const) pointer to the start of the mapped region
    void const* memory() const STLSOFT_NOEXCEPT
    {
        return m_ref->handle.memory;
    }

    /// The number of bytes in the mapped region
    size_type size() const STLSOFT_NOEXCEPT
    {
        return m_ref->handle.size;
    }

private: // Implementation
    static
    void
    throw_(
        ws_char_a_t const*  fileName
    ,   status_code_type    e
    )
    {
        if (winstl_C_is_memory_status_code(e))
        {
            STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_WinSTL, STLSoftLibraryIdentifier_FileSystem, e));
        }

        size_type const fnl = stlsoft::c_str_len(fileName);

        stlsoft::exception_string_creator xsc(50 + fnl);

        if (0 == fnl)
        {
            xsc.append("could not map file");
        }
        else
        {
            xsc.append("could not map file '");
            xsc.append(fileName, fnl);
            xsc.append('\'');
        }

        do_throw_(xsc.c_str(), e);
    }
    static
    void
    do_throw_(
        ws_char_a_t const*  message
    ,   status_code_type    e
    )
    {
        switch (e)
        {
        case    ERROR_FILE_NOT_FOUND:
            STLSOFT_THROW_X(file_not_found_exception(message, e));
        case    ERROR_ACCESS_DENIED:
            STLSOFT_THROW_X(access_exception(message, e));
        default:
            STLSOFT_THROW_X(filesystem_exception(message, e));
        }
    }
    static
    void
    throw_(
        ws_char_w_t const*  fileName
    ,   status_code_type    e
    )
    {
        if (NULL == fileName ||
            '\0' == fileName[0])
        {
            throw_(static_cast<ws_char_a_t const*>(NULL), e);
        }

        throw_(w2a(fileName), e);
    }

    static
    Ref
    create_(
        ws_char_a_t const*  fileName
    ,   offset_type         offset
    ,   size_type           requestSize
    )
    {
        ws_uintptr_t    viewSize;
        void* const     memory = map_readonly_view_of_file_by_name(
                                    fileName
                                ,   GENERIC_READ
                                ,   FILE_SHARE_READ
                                ,   offset
                                ,   requestSize
                                ,   &viewSize
                                );

        if (NULL == memory)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

            if (0 != viewSize ||
                ERROR_SUCCESS != e)
            {
                throw_(fileName, e);
            }
        }

        try
        {
            return HRW_HandleAdaptor_type::create(memory, viewSize);
        }
        catch(...)
        {
            unmap_view_of_file(memory, viewSize);

            throw;
        }
    }
    static
    Ref
    create_(
        ws_char_w_t const*  fileName
    ,   offset_type         offset
    ,   size_type           requestSize
    )
    {
        ws_uintptr_t    viewSize;
        void* const     memory = map_readonly_view_of_file_by_name(
                                    fileName
                                ,   GENERIC_READ
                                ,   FILE_SHARE_READ
                                ,   offset
                                ,   requestSize
                                ,   &viewSize
                                );

        if (NULL == memory)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

            if (0 != viewSize ||
                ERROR_SUCCESS != e)
            {
                throw_(fileName, e);
            }
        }

        try
        {
            return HRW_HandleAdaptor_type::create(memory, viewSize);
        }
        catch(...)
        {
            unmap_view_of_file(memory, viewSize);

            throw;
        }
    }

private: // Members
    HRW_Ref_type    m_ref;
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** Elicits a file-stream handle (<code>FILE*</code>) from the given
 * instance.
 */
template <ss_typename_param_k R>
inline
memory_mapped_file_view_state_t const
get_memory_mapped_file_view_handle(
    readonly_memory_mapped_file_base<R>& h
)
{
    return h.handle;
}

/** Elicits a file-stream handle (<code>FILE*</code>) from the given
 * instance.
 */
template <ss_typename_param_k R>
inline
memory_mapped_file_view_state_t const
get_memory_mapped_file_view_handle(
    readonly_memory_mapped_file_base<R>* h
)
{
    return (NULL != h) ? h->handle : memory_mapped_file_view_state_t(NULL, 0u);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE */

/* ///////////////////////////// end of file //////////////////////////// */

