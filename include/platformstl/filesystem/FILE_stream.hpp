/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/FILE_stream.hpp
 *
 * Purpose:     Facade for the standard C Streams API.
 *
 * Created:     31st May 2009
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2009-2019, Matthew Wilson and Synesis Software
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


/** \file platformstl/filesystem/FILE_stream.hpp
 *
 * \brief [C++] Definition of the platformstl::thread_shareable_FILE_stream typedef
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MAJOR       2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MINOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_REVISION    4
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_EDIT        24
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_ACCESS_EXCEPTION
#  include <winstl/exception/access_exception.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_ACCESS_EXCEPTION */
#endif
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_FILESYSTEM_EXCEPTION
# include <platformstl/exception/filesystem_exception.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_FILESYSTEM_EXCEPTION */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_FILE_NOT_FOUND_EXCEPTION
# include <platformstl/exception/file_not_found_exception.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_FILE_NOT_FOUND_EXCEPTION */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
# include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_ATOMIC_TYPES
# include <platformstl/synch/atomic_types.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_ATOMIC_TYPES */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_W2M
# include <stlsoft/conversion/w2m.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_W2M */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION
# include <stlsoft/exception/out_of_memory_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE
# include <stlsoft/filesystem/handles/FILE_stream_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR
# include <stlsoft/shims/attribute/get_FILE_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED
# include <stlsoft/synch/refcount_policies/refcount_policy_single_threaded.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>
#endif /* !STLSOFT_INCL_H_STDIO */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */

namespace stlsoft
{
namespace platformstl_project
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Handle::Ref+<b>Wrapper</b> wrapper class
 *
 */
template<
    ss_typename_param_k R
,   ss_typename_param_k I = int
>
class FILE_stream_base
{
private: // Member Types
    typedef R                                                   refcount_policy_type_;
    typedef I                                                   refcount_counter_type_;
public:
    /// This type
    typedef FILE_stream_base<R, I>                              class_type;

    typedef STLSOFT_NS_QUAL(FILE_stream_handle)<
        refcount_policy_type_
    ,   refcount_counter_type_
    >                                                           handle_adaptor_type;  // Optional type
    /// The Handle::Ref+Wrapper <strong>Handle</strong> type
    typedef ss_typename_type_k handle_adaptor_type::handle_type handle_type;          // Mandatory types for HRW
    /// The Handle::Ref+Wrapper <strong>Ref</strong> type
    typedef ss_typename_type_k handle_adaptor_type::Ref         ref_type;             // Mandatory types for HRW
    /// The Handle::Ref+Wrapper <strong>Wrapper</strong> type: this type
    typedef FILE_stream_base<R, I>                              wrapper_type;         // Mandatory types for HRW

    /// The Handle::Ref+Wrapper ref type
    typedef ref_type                                            Ref;

    /// The size type
    typedef size_t                                              size_type;

public: // Construction
    /// Creates an instance of the class opened over a file stream for the
    /// given \c path, according to the given \c mode.
    template <typename S1, typename S2>
    FILE_stream_base(S1 const& path, S2 const& mode)
        : m_ref(init_(STLSOFT_NS_QUAL(c_str_ptr)(path), STLSOFT_NS_QUAL(c_str_ptr)(mode)))
    {}
    /// Copy constructor
    FILE_stream_base(class_type const& rhs)
        : m_ref(rhs.m_ref)
    {}

    /// Returns the Handle::Ref+Wrapper <strong>ref</strong>, which
    /// encapsulates a shared file stream handle.
    Ref get() const STLSOFT_NOEXCEPT
    {
        return m_ref;
    }

public: // Operations
    /// Writes the given string and the end-of-line character
    /// <code>'\n'</code> to the underlying file stream.
    ///
    /// \note The line is combined with the end-of-line character before
    ///   passing to the underlying <code>fwrite()</code> operation. In
    ///   cases where <code>fwrite()</code> is implemented to write
    ///   atomically to the underlying file, the line and character will be
    ///   written in a single operation.
    template <typename S>
    class_type& write_line(S const& line)
    {
        return write_line_(STLSOFT_NS_QUAL(c_str_data)(line), STLSOFT_NS_QUAL(c_str_len)(line));
    }

    /// Writes an empty line to the underlying stream.
    class_type& write_line()
    {
#if 0 ||\
    defined(UNICODE) ||\
    defined(_UNICODE) ||\
    defined(FASTFORMAT_USE_WIDE_STRINGS) ||\
    defined(PANTHEIOS_USE_WIDE_STRINGS) ||\
    defined(STLSOFT_USE_WIDE_STRINGS) ||\
    0

        return write_line_(static_cast<wchar_t const*>(NULL), 0u);
#else

        return write_line_(static_cast<char const*>(NULL), 0u);
#endif
    }

    /// Writes the given string to the underlying stream.
    template <typename S>
    class_type& write(S const& text)
    {
        return write_text_(STLSOFT_NS_QUAL(c_str_data)(text), STLSOFT_NS_QUAL(c_str_len)(text));
    }

    /// Writes to the underlying file stream \c cch multibyte characters
    /// from the memory block pointed to by \c ps.
    ///
    /// \exception X Thrown in \c cch characters cannot be written to the
    ///   underlying stream
    class_type& write(char const* ps, size_type cch)
    {
        return write_text_(ps, cch);
    }

    /// Writes to the underlying file stream \c cch wide characters
    /// from the memory block pointed to by \c ps.
    ///
    /// \exception X Thrown in \c cch characters cannot be written to the
    ///   underlying stream
    class_type& write(wchar_t const* ps, size_type cch)
    {
        return write_text_(ps, cch);
    }

    /// Writes \c cb bytes from the memory block pointed to by \c pv to the
    /// underlying file stream.
    ///
    /// \exception X Thrown in \c cb bytes cannot be written to the
    ///   underlying stream
    class_type& write(void const* pv, size_type cb)
    {
        return write_bytes_(pv, cb);
    }

    /// Causes any buffered output to be emitted to the underlying file
    /// stream.
    void flush()
    {
        if (0 != ::fflush(m_ref->handle))
        {
            int const e = errno;

            report_nonnormative_("failed to flush file", e);
        }
    }

    /// Seeks the underlying file stream pointer to an absolute position.
    void seek_from_start(long offset)
    {
        seek_(offset, SEEK_SET);
    }

    /// Seeks the underlying file stream pointer relative to the current
    /// position.
    void seek_relative(long offset)
    {
        seek_(offset, SEEK_CUR);
    }

    /// Seeks the underlying file stream pointer relative to the given
    /// origin.
    void seek_from(long offset, int origin)
    {
        seek_(offset, origin);
    }

    /// Elicits the current file stream pointer position.
    long tell() const
    {
        long pos = ::ftell(m_ref->handle);

        if (-1l == pos)
        {
            int const e = errno;

            report_nonnormative_("failed to tell file position", e);
        }

        return pos;
    }

private: // Implementation
    static
    int
    validate_errno_(
        FILE*   h
    ,   int     e
    )
    {
#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
    (   (   defined(STLSOFT_COMPILER_IS_MSVC) || \
            (   defined(_WIN32) && \
                defined(STLSOFT_COMPILER_IS_INTEL))) && \
        _MSC_VER < 1310) || \
    defined(STLSOFT_COMPILER_IS_MWERKS)

        if (NULL == h &&
            0 == e)
        {
            e = EMFILE;
        }

#else /* ? compiler */

        STLSOFT_SUPPRESS_UNUSED(h);

#endif /* compiler */

        return e;
    }

    static
    Ref
    init_(
        char const* path
    ,   char const* mode
    )
    {
#if defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
        FILE* handle;
        int   e = ::fopen_s(&handle, path, mode);

        if (0 != e)
        {
#else // }
        FILE* handle = ::fopen(path, mode);

        if (NULL == handle)
        {
            int e = errno;
#endif

            e = validate_errno_(handle, e);

            STLSOFT_MESSAGE_ASSERT("errno should not be 0 when file could not be opened. If it is, the FILE_stream component is not correctly implemented for your compiler. Please contact Synesis Software for assistance", 0 != e);

            report_nonnormative_("failed to open/create file", path, e);
        }

        try
        {
            STLSOFT_ASSERT(NULL != handle);

            return handle_adaptor_type::create(handle);
        }
        catch(...)
        {
            handle_adaptor_type::destroy(handle);

            throw;
        }
    }
#if defined(STLSOFT_COMPILER_IS_MSVC)
    static
    Ref
    init_(
        wchar_t const*  path
    ,   wchar_t const*  mode
    )
    {
# if defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) && \
     defined(STLSOFT_COMPILER_IS_MSVC)
        FILE* handle;
        int   e = ::_wfopen_s(&handle, path, mode);

        if (0 != e)
        {
# else // }
        FILE* handle = ::_wfopen(path, mode);

        if (NULL == handle)
        {
            int e = errno;
# endif

            e = validate_errno_(handle, e);

            STLSOFT_MESSAGE_ASSERT("errno should not be 0 when file could not be opened. If it is, the FILE_stream component is not correctly implemented for your compiler. Please contact Synesis Software for assistance", 0 != e);

            report_nonnormative_("failed to open/create file", path, e);
        }

        try
        {
            STLSOFT_ASSERT(NULL != handle);

            return handle_adaptor_type::create(handle);
        }
        catch(...)
        {
            handle_adaptor_type::destroy(handle);

            throw;
        }
    }
#endif /* compiler */

    class_type&
    write_line_(
        char const* s
    ,   size_type   len
    )
    {
        STLSOFT_NS_QUAL(auto_buffer)<char>  buff(2u + len);

        if (0 != len)
        {
            STLSOFT_API_INTERNAL_memfns_memcpy(&buff[0], s, sizeof(*s) * len);
        }
        buff[len + 0] = '\n';
        buff[len + 1] = '\0';

        return write_text_(buff.data(), 1u + len);
    }

    class_type&
    write_line_(
        wchar_t const*  s
    ,   size_type       len
    )
    {
        STLSOFT_NS_QUAL(auto_buffer)<wchar_t>  buff(2u + len);

        if (0 != len)
        {
            STLSOFT_API_INTERNAL_memfns_memcpy(&buff[0], s, sizeof(*s) * len);
        }
        buff[len + 0] = '\n';
        buff[len + 1] = '\0';

        return write_text_(buff.data(), 1u + len);
    }

    class_type&
    write_bytes_(
        void const* pv
    ,   size_type   cb
    )
    {
        size_type const n = ::fwrite(pv, sizeof(byte_t), cb, m_ref->handle);

        if (n < cb)
        {
            int const e = errno;

            report_nonnormative_("failed to write bytes to file", e);
        }

        return *this;
    }

    class_type&
    write_text_(
        char const*     ps
    ,   size_type       cch
    )
    {
        char        fmt_[20 + 3 + 1];
        size_t      n;
        char const* fmt =   stlsoft::integer_to_decimal_string(&fmt_[0], STLSOFT_NUM_ELEMENTS(fmt_) - 1, cch, &n);

        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - 2] = 's';
        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - 1] = '\0';

        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - (2 + n + 1)] = '.';
        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - (2 + n + 2)] = '%';

        fmt -= 2;

        int const r = ::fprintf(m_ref->handle, fmt, ps);

        if (r < 0)
        {
            int const e = errno;

            report_nonnormative_("failed to write multibyte string to file", e);
        }

        return *this;
    }

    class_type&
    write_text_(
        wchar_t const*  ps
    ,   size_type       cch
    )
    {
        wchar_t         fmt_[20 + 3 + 1];
        size_t          n;
        wchar_t const*  fmt =   stlsoft::integer_to_decimal_string(&fmt_[0], STLSOFT_NUM_ELEMENTS(fmt_) - 1, cch, &n);

        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - 2] = 's';
        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - 1] = '\0';

        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - (2 + n + 1)] = '.';
        fmt_[STLSOFT_NUM_ELEMENTS(fmt_) - (2 + n + 2)] = '%';

        fmt -= 2;

        int const r = ::fwprintf(m_ref->handle, fmt, ps);

        if (r < 0)
        {
            int const e = errno;

            report_nonnormative_("failed to write wide string to file", e);
        }

        return *this;
    }

    void
    seek_(
        long    offset
    ,   int     origin
    )
    {
        if (0 != ::fseek(m_ref->handle, offset, origin))
        {
            int const e = errno;

            report_nonnormative_("failed to seek", e);
        }
    }

    static
    void
    report_nonnormative_(
        char const* message
    ,   int         e
    )
    {
        switch (e)
        {
            case    ENOMEM:
                STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_STLSoft, STLSoftLibraryIdentifier_FileSystem, e));
            case    ENOENT:
                STLSOFT_THROW_X(file_not_found_exception(message, e));
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
            case    EACCES:
                STLSOFT_THROW_X(WINSTL_NS_QUAL(access_exception)(message, e));
#endif
            default:
                STLSOFT_THROW_X(filesystem_exception(message, e));
        }
    }

    static
    void
    report_nonnormative_(
        char const* message
    ,   char const* path
    ,   int         e
    )
    {
        switch (e)
        {
            case    ENOMEM:
                STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_STLSoft, STLSoftLibraryIdentifier_FileSystem, e));
            case    ENOENT:
                STLSOFT_THROW_X(file_not_found_exception(message, e, path));
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
#elif defined(PLATFORMSTL_OS_IS_WINDOWS_)
            case    EACCES:
                STLSOFT_THROW_X(WINSTL_NS_QUAL(access_exception)(message, e, path));
#endif
            default:
                STLSOFT_THROW_X(filesystem_exception(message, e, path));
        }
    }

    static
    void
    report_nonnormative_(
        char const*     message
    ,   wchar_t const*  path
    ,   int             e
    )
    {
        if (NULL == path ||
            '\0' == path[0])
        {
            report_nonnormative_(message, e);
        }
        else if (ENOMEM == e)
        {
            report_nonnormative_(message, e);
        }
        else
        {
            report_nonnormative_(message, w2m(path), e);
        }
    }

private: // Member Variables
    Ref m_ref;
};

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** A file stream suitable for manipulating files from a single thread.
 */
typedef FILE_stream_base<
    refcount_policy_single_threaded
>                                                           FILE_stream;

/** A file stream whose underlying handle can be shared between threads.
 */
typedef FILE_stream_base<
    refcount_policy_multi_threaded
,   atomic_int_t
>                                                           thread_shareable_FILE_stream;

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** Elicits a file-stream handle (<code>FILE*</code>) from the given
 * instance.
 *
 * \ingroup group__library__Shims_Attribute_FILE
 */
template<
    ss_typename_param_k R
,   ss_typename_param_k I
>
inline
FILE*
get_FILE_ptr(
    FILE_stream_base<R, I>& file
)
{
    ss_typename_type_k FILE_stream_base<R, I>::Ref r = file.get();

    return (NULL != r.get()) ? r->handle : NULL;
}

template<
    ss_typename_param_k R
,   ss_typename_param_k I
>
inline
FILE*
get_FILE_stream_Handle(
    FILE_stream_base<R, I>& file
)
{
    return get_FILE_ptr(file);
}

template<
    ss_typename_param_k R
,   ss_typename_param_k I
>
inline
ss_typename_type_k FILE_stream_base<R, I>::Ref
get_FILE_stream_Ref(
    FILE_stream_base<R, I>& file
)
{
    return file.get();
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
#else
} /* namespace platformstl_project */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The file ptr shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef PLATFORMSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

    using ::platformstl::get_FILE_ptr;
    using ::platformstl::get_FILE_stream_Handle;
    using ::platformstl::get_FILE_stream_Ref;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !PLATFORMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM */

/* ///////////////////////////// end of file //////////////////////////// */

