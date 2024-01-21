/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/memory_mapped_file.hpp (based on MMFile.h, ::SynesisWin)
 *
 * Purpose:     Memory mapped file class.
 *
 * Created:     15th December 1996
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1996-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/filesystem/memory_mapped_file.hpp
 *
 * \brief [C++] Definition of the unixstl::memory_mapped_file class
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_MAJOR       4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_MINOR       6
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_REVISION    2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE_EDIT        109
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

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_ACCESS_EXCEPTION
#  include <unixstl/exception/access_exception.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_FILESYSTEM_EXCEPTION */
# ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_ENTRY_NOT_FOUND_EXCEPTION
#  include <unixstl/exception/entry_not_found_exception.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_ENTRY_NOT_FOUND_EXCEPTION */
# ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_FILE_NOT_FOUND_EXCEPTION
#  include <unixstl/exception/file_not_found_exception.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_FILE_NOT_FOUND_EXCEPTION */
# ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_FILESYSTEM_EXCEPTION
#  include <unixstl/exception/filesystem_exception.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_FILESYSTEM_EXCEPTION */
# ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION
#  include <stlsoft/exception/out_of_memory_exception.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER
# include <stlsoft/exception/status_code_provider.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_STATUS_CODE_PROVIDER */
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE
# include <stlsoft/smartptr/scoped_handle.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_SCOPED_HANDLE */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

#ifndef STLSOFT_INCL_SYS_H_MMAN
# define STLSOFT_INCL_SYS_H_MMAN
# include <sys/mman.h>
#endif /* !STLSOFT_INCL_SYS_H_MMAN */
#ifndef STLSOFT_INCL_SYS_H_STAT
# define STLSOFT_INCL_SYS_H_STAT
# include <sys/stat.h>
#endif /* !STLSOFT_INCL_SYS_H_STAT */

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

/** Facade over the UNIX memory mapped file API.
 *
 * \ingroup group__library__FileSystem
 */
class memory_mapped_file
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    : public status_code_provider<int>
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
{
/// \name Member Types
/// @{
private:
    /// The character type
    typedef us_char_a_t                     char_type;
    /// The traits type
    typedef filesystem_traits<us_char_a_t>  traits_type;
public:
    /// This type
    typedef memory_mapped_file              class_type;
    /// The size type
    typedef us_size_t                       size_type;
    /// The status code type
    typedef int                             status_code_type;
    /// The error type
    ///
    /// \deprecated Instead use \c status_code_type
    typedef status_code_type                error_type;
    /// The offset type
    typedef off_t                           offset_type;
    /// The boolean type
    typedef us_bool_t                       bool_type;
/// @}

/// \name Implementation
/// @{
private:
    void open_(
        char_type const*    fileName
    ,   offset_type         offset
    ,   size_type           requestSize
    )
    {
        scoped_handle<int>  hfile(  traits_type::open(  fileName
                                                    ,   O_RDONLY
                                                    ,   PROT_READ)
                                ,   &traits_type::close
                                ,   -1);

        if (hfile.empty())
        {
            if (on_failure_("Failed to open file for mapping"))
            {
                return;
            }
        }
        else
        {
            struct stat st;

            if (0 != ::fstat(hfile.get(), &st))
            {
                if (on_failure_("Failed to determine mapped file size"))
                {
                    return;
                }
            }
            else if (0 == st.st_size)
            {
                m_memory    =   NULL;
                m_cb        =   0;
            }
            else
            {
                if (0 == requestSize)
                {
                    requestSize = static_cast<size_type>(st.st_size);
                }
                else if (requestSize + offset > static_cast<size_type>(st.st_size))
                {
                    requestSize = static_cast<size_type>(st.st_size) - offset;
                }

                void* const memory = ::mmap(NULL, static_cast<size_t>(requestSize), PROT_READ, MAP_PRIVATE, hfile.get(), offset);

                if (MAP_FAILED == memory)
                {
                    on_failure_("Failed to map view of file");
                }
                else
                {
                    m_memory    =   memory;
                    m_cb        =   requestSize;
                }
            }
        }
    }
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k
    memory_mapped_file(
        char_type const* fileName
    )
        : m_cb(0)
        , m_memory(NULL)
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        , m_lastStatusCode(0)
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        open_(fileName, 0, 0);
    }
    template <ss_typename_param_k S>
    ss_explicit_k
    memory_mapped_file(
        S const& fileName
    )
        : m_cb(0)
        , m_memory(NULL)
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        , m_lastStatusCode(0)
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        open_(STLSOFT_NS_QUAL(c_str_ptr)(fileName), 0, 0);
    }
    memory_mapped_file(
        char_type const*    fileName
    ,   offset_type         offset
    ,   size_type           requestSize
    )
        : m_cb(0)
        , m_memory(NULL)
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        , m_lastStatusCode(0)
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        open_(fileName, offset, requestSize);
    }
    template <ss_typename_param_k S>
    memory_mapped_file(
        S const&    fileName
    ,   offset_type offset
    ,   size_type   requestSize
    )
        : m_cb(0)
        , m_memory(NULL)
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        , m_lastStatusCode(0)
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        open_(STLSOFT_NS_QUAL(c_str_ptr)(fileName), offset, requestSize);
    }

    /// Closes the view on the mapped file
    ~memory_mapped_file() STLSOFT_NOEXCEPT
    {
        UNIXSTL_ASSERT(is_valid());

        if (NULL != m_memory)
        {
            ::munmap(m_memory, static_cast<us_size_t>(m_cb));
        }
    }

    /// Swaps the state of this instance with another
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        UNIXSTL_ASSERT(is_valid());

        std_swap(m_cb, rhs.m_cb);
        std_swap(m_memory, rhs.m_memory);
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        std_swap(m_lastStatusCode, rhs.m_lastStatusCode);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        UNIXSTL_ASSERT(is_valid());
    }

private:
    memory_mapped_file(class_type const&);      // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Accessors
/// @{
public:
    /// Non-mutating (const) pointer to the start of the mapped region
    void const* memory() const
    {
        return m_memory;
    }
    /// The number of bytes in the mapped region
    size_type size() const
    {
        return m_cb;
    }

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    /// [Deprecated] The status code associated with the last attempted
    /// operation
    ///
    /// \deprecated This method will be removed in a future version. Instead
    ///   use <code>status_code()</code>
    status_code_type lastError() const
    {
        return m_lastStatusCode;
    }

    /* virtual */ status_code_type
    status_code() const ss_override_k
    {
        return m_statusCode;
    }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
/// @}

/// \name Comparison
/// @{
public:
    /** Determines whether the given instance is the same size and has
     * identical contents to the calling instance.
     *
     * \param rhs The instance against whose contents will be compared those
     *   of the calling instance.
     *
     * \retval true \c rhs is the same size and has identical contents to
     *   the calling instance.
     * \retval false \c rhs is a different size and/or has different
     *   contents to the calling instance.
     */
    bool
    equal(
        class_type const& rhs
    ) const
    {
        class_type const& lhs = *this;

        if (lhs.size() != rhs.size())
        {
            return false;
        }
        if (0 != ::memcmp(lhs.memory(), rhs.memory(), lhs.size()))
        {
            return false;
        }
        return true;
    }
/// @}

/// \name Implementation
/// @{
private:
    bool_type
    on_failure_(
        char const*         message
    ,   status_code_type    scode = errno
    )
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        switch (scode)
        {
        case ENOMEM:
            STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_UNIXSTL, STLSoftLibraryIdentifier_FileSystem, scode));
        case ENOENT:
            STLSOFT_THROW_X(file_not_found_exception(message, scode));
        case EACCES:
            STLSOFT_THROW_X(access_exception(message, scode));
        default:
            STLSOFT_THROW_X(filesystem_exception(message, scode));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        STLSOFT_SUPPRESS_UNUSED(message);

        m_lastStatusCode = scode;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return true;
    }

    bool_type is_valid() const
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if ((NULL != m_memory) != (0 != m_cb))
        {
            return false;
        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        return true;
    }
/// @}

/// \name Fields
/// @{
private:
    size_type           m_cb;
    void*               m_memory;
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    status_code_type    m_lastStatusCode;
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * comparison operators
 */

inline
bool
operator ==(
    memory_mapped_file const&   lhs
,   memory_mapped_file const&   rhs
)
{
    return lhs.equal(rhs);
}

inline
bool
operator !=(
    memory_mapped_file const&   lhs
,   memory_mapped_file const&   rhs
)
{
    return !lhs.equal(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

/** Swaps the state of two \link unixstl::memory_mapped_file memory_mapped_file\endlink
 * instances.
 */
inline
void
swap(
    memory_mapped_file& lhs
,   memory_mapped_file& rhs
)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

#ifdef STLSOFT_CF_std_NAMESPACE
namespace std
{

    inline
    void
    swap(
        UNIXSTL_NS_QUAL(memory_mapped_file)& lhs
    ,   UNIXSTL_NS_QUAL(memory_mapped_file)& rhs
    )
    {
        lhs.swap(rhs);
    }

} /* namespace std */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE */

/* ///////////////////////////// end of file //////////////////////////// */

