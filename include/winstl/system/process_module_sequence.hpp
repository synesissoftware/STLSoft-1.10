/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/process_module_sequence.hpp
 *
 * Purpose:     Process Id sequence class.
 *
 * Created:     24th June 2005
 * Updated:     22nd January 2024
 *
 * Thanks to:   Adi Shavit for spotting a small inefficiency in the
 *              resize()-ing, during the review of Extended STL volume 1
 *              (see http://extendedstl.com/).
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/system/process_module_sequence.hpp
 *
 * \brief [C++] Definition of the winstl::process_module_sequence
 *  class
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_PROCESS_MODULE_SEQUENCE
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_PROCESS_MODULE_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_PROCESS_MODULE_SEQUENCE_MAJOR     2
# define WINSTL_VER_WINSTL_SYSTEM_HPP_PROCESS_MODULE_SEQUENCE_MINOR     2
# define WINSTL_VER_WINSTL_SYSTEM_HPP_PROCESS_MODULE_SEQUENCE_REVISION  10
# define WINSTL_VER_WINSTL_SYSTEM_HPP_PROCESS_MODULE_SEQUENCE_EDIT      65
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

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
#  include <winstl/exception/winstl_exception.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#if !defined(_PSAPI_H_) && \
    !defined(_PSAPI_H)
# ifndef WINSTL_INCL_WINSTL_DL_HPP_DL_CALL
#  include <winstl/dl/dl_call.hpp>
# endif /* !WINSTL_INCL_WINSTL_DL_HPP_DL_CALL */
#endif /* psapi */

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

/** Process module (constituent DLLs) sequence
 *
 * \ingroup group__library__System
 */
class process_module_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
/// \name Member Types
/// @{
public:
    /// The value type
    typedef HMODULE                                                         value_type;
    /// The allocator type
    typedef processheap_allocator<value_type>                               allocator_type;
    /// The class type
    typedef process_module_sequence                                         class_type;
    /// The non-mutating (const) pointer type
    typedef value_type const*                                               const_pointer;
    /// The non-mutating (const) reference type
    typedef value_type const&                                               const_reference;
    /// The non-mutating (const) iterator type
    typedef STLSOFT_NS_QUAL(pointer_iterator)<  value_type
                                            ,   const_pointer
                                            ,   const_reference
                                            >::type                         const_iterator;
    /// The size type
    typedef ws_size_t                                                       size_type;
    /// The difference type
    typedef ws_ptrdiff_t                                                    difference_type;
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// The non-mutating (const) reverse iterator type
    typedef STLSOFT_NS_QUAL(const_reverse_bidirectional_iterator_base)< const_iterator
                                                                    ,   value_type
                                                                    ,   const_reference
                                                                    ,   const_pointer
                                                                    ,   difference_type
                                                                    >       const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Construction
/// @{
public:
    /// Constructs a sequence from the current modules in the given process
    ss_explicit_k process_module_sequence(HANDLE hProcess);
    /// Copies the contents of the sequence
    process_module_sequence(class_type const& rhs);
    /// Releases the storage associated with the process id list
    ~process_module_sequence() STLSOFT_NOEXCEPT;
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;

#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    /// Begins the reverse iteration
    ///
    /// \return An iterator representing the start of the reverse sequence
    const_reverse_iterator  rbegin() const;
    /// Ends the reverse iteration
    ///
    /// \return An iterator representing the end of the reverse sequence
    const_reverse_iterator  rend() const;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
/// @}

/// \name Element Access
/// @{
public:
    /// Returns a reference to the element at the given index
    ///
    /// \param index The required index. Behaviour is undefined, if not within the range [0, size())
    const_reference operator [](size_type index) const;
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the sequence is empty
    ws_bool_t   empty() const;
    /// Returns the number of identifiers in the sequence
    size_type   size() const;
/// @}

/// \name Members
/// @{
private:
    typedef STLSOFT_NS_QUAL(auto_buffer_old)<   value_type
                                            ,   allocator_type
                                            ,   64
                                            >       buffer_type_;

    buffer_type_    m_modules;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type& operator =(class_type const&);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline process_module_sequence::process_module_sequence(HANDLE hProcess)
    : m_modules(buffer_type_::internal_size())
{
    DWORD   cbReturned;

    for (;;)
    {
#if defined(_PSAPI_H_) || \
    defined(_PSAPI_H)
        if (!::EnumProcessModules(hProcess, &m_modules[0], sizeof(value_type) * m_modules.size(), &cbReturned))
#else /* ? psapi */
        if (!dl_call<BOOL>(  "PSAPI.DLL"
                        ,   WINSTL_DL_CALL_WINx_STDCALL_LITERAL("EnumProcessModules")
                        ,   hProcess
                        ,   &m_modules[0]
                        ,   sizeof(value_type) * m_modules.size()
                        ,   &cbReturned))
#endif /* psapi */
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(winstl_exception("Failed to enumerate processes", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            m_modules.resize(0);

            break;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            const ws_size_t n   =   cbReturned / sizeof(value_type);

            if (n < m_modules.size())
            {
                m_modules.resize(n);

                break;
            }
            else
            {
                const size_type size = m_modules.size();

                m_modules.resize(1); // Read "Extended STL, volume 1" to find out what this is for

                if (!m_modules.resize(2 * size))
                {
                    // This will only ever be executed when compiled in the
                    // absence of throwing bad_alloc on memory exhaustion
                    m_modules.resize(0);

                    break;
                }
            }
        }
    }
}

inline process_module_sequence::process_module_sequence(process_module_sequence const& rhs)
    : m_modules(rhs.m_modules.size())
{
    STLSOFT_NS_QUAL_STD(copy)(rhs.m_modules.begin(), rhs.m_modules.end(), m_modules.begin());
}

inline process_module_sequence::~process_module_sequence() STLSOFT_NOEXCEPT
{}

inline process_module_sequence::const_iterator process_module_sequence::begin() const
{
    return &*m_modules.begin();
}

inline process_module_sequence::const_iterator process_module_sequence::end() const
{
    return &*m_modules.end();
}

#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
inline process_module_sequence::const_reverse_iterator process_module_sequence::rbegin() const
{
    return const_reverse_iterator(end());
}

inline process_module_sequence::const_reverse_iterator process_module_sequence::rend() const
{
    return const_reverse_iterator(begin());
}
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */

inline process_module_sequence::const_reference process_module_sequence::operator [](process_module_sequence::size_type index) const
{
    WINSTL_MESSAGE_ASSERT("Index out of range", index < size());

    return m_modules[index];
}

inline ws_bool_t process_module_sequence::empty() const
{
    return m_modules.empty();
}

inline process_module_sequence::size_type process_module_sequence::size() const
{
    return m_modules.size();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_PROCESS_MODULE_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

