/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/containers/environment_block.hpp (stlsoft_environment_block.h)
 *
 * Purpose:     Contains the basic_environment_block class.
 *
 * Created:     25th June 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/containers/environment_block.hpp
 *
 * \brief [C++] Definition of the stlsoft::basic_environment_block
 *   container class template
 *   (\ref group__library__Container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK
#define STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK_MAJOR     4
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK_MINOR     2
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK_REVISION  10
# define STLSOFT_VER_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK_EDIT      61
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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>       // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

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

/** Stores nul-terminated environment variable name-value strings
 *    continguously in a format compatible with system environment settings.
 *
 * \ingroup group__library__Container
 *
 * \param C The character type
 * \param T The traits type. Defaults to char_traits<C>. On translators that do not support default template parameters, this must be explicitly specified.
 * \param A The allocator type. Defaults to stlsoft::allocator_selector<C>::allocator_type. On translators that do not support default template parameters, this must be explicitly specified.
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = char_traits<C>
        ,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = char_traits<C> */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_environment_block
{
/// \name Types
/// @{
public:
    /// The value type
    typedef C                                               value_type;
    /// The char type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// The current specialisation of the type
    typedef basic_environment_block<C, T, A>                class_type;
    /// The mutating (non-const) pointer type
    typedef char_type*                                      pointer;
    /// The non-mutating (const) pointer type
    typedef char_type const*                                const_pointer;
    /// The size type
    typedef ss_size_t                                       size_type;
/// @}

/// \name Construction
/// @{
public:
    basic_environment_block()
        : m_chars(1)
        , m_offsets(1)
        , m_pointers(0)
    {
        m_chars[0]      =   '\0';
        m_offsets[0]    =   0;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Append a full NAME=VALUE environment pair
    void push_back(char_type const* s, ss_size_t cch)
    {
        STLSOFT_ASSERT(NULL != s);
        STLSOFT_ASSERT(cch >= 3);
        STLSOFT_ASSERT(NULL != traits_type::find(s, cch, '='));

        STLSOFT_ASSERT(m_chars.size() > 0);
        STLSOFT_ASSERT('\0' == m_chars[m_chars.size() - 1]);

        const size_type   numChars_     =   m_chars.size();
        const size_type   numOffsets_   =   m_offsets.size();
        const size_type   numPointers_  =   m_pointers.size();

        STLSOFT_SUPPRESS_UNUSED(numPointers_);

        m_chars.resize(numChars_ + cch + 1);
        // The next item
        traits_type::copy(&m_chars[numChars_ - 1], s, cch);
        m_chars[numChars_ + cch - 1] = '\0';
        // The terminating item
        m_chars[numChars_ + cch] = '\0';

        m_offsets.resize(numOffsets_ + 1);
        m_offsets[numOffsets_] = numChars_ + cch;

        m_pointers.resize(0);

        STLSOFT_ASSERT('\0' == m_chars[m_chars.size() - 1]);
    }
    template <ss_typename_param_k S>
    void push_back(S const& s)
    {
        push_back(STLSOFT_NS_QUAL(c_str_data)(s), STLSOFT_NS_QUAL(c_str_len)(s));
    }
    void push_back(char_type const* name, ss_size_t cchName, char_type const* value, ss_size_t cchValue)
    {
        STLSOFT_ASSERT(NULL != name);
        STLSOFT_ASSERT(NULL != value);
        STLSOFT_ASSERT(cchName > 0);
        STLSOFT_ASSERT(cchValue > 0);
        STLSOFT_ASSERT(NULL == traits_type::find(name, cchName, '='));

        STLSOFT_ASSERT(m_chars.size() > 0);
        STLSOFT_ASSERT('\0' == m_chars[m_chars.size() - 1]);

        const size_type   numChars_     =   m_chars.size();
        const size_type   numOffsets_       =   m_offsets.size();
        const size_type   numPointers_  =   m_pointers.size();

        STLSOFT_SUPPRESS_UNUSED(numPointers_);

        m_chars.resize(numChars_ + cchName + 1 + cchValue + 1);
        // The next item

        traits_type::copy(&m_chars[numChars_ - 1], name, cchName);
        m_chars[numChars_ - 1 + cchName] = '=';
        traits_type::copy(&m_chars[numChars_ - 1 + cchName + 1], value, cchValue);
        m_chars[numChars_ - 1 + cchName + 1 + cchValue] = '\0';
        // The terminating item
        m_chars[numChars_ + cchName + 1 + cchValue] = '\0';

        m_offsets.resize(numOffsets_ + 1);
        m_offsets[numOffsets_] = numChars_ + cchName + 1 + cchValue;

        m_pointers.resize(0);

        STLSOFT_ASSERT('\0' == m_chars[m_chars.size() - 1]);
    }
    template<   ss_typename_param_k S1
            ,   ss_typename_param_k S2
            >
    void push_back(S1 const& name, S2 const& value)
    {
        push_back(STLSOFT_NS_QUAL(c_str_data)(name), STLSOFT_NS_QUAL(c_str_len)(name), STLSOFT_NS_QUAL(c_str_data)(value), STLSOFT_NS_QUAL(c_str_len)(value));
    }

    void clear()
    {
        m_chars.resize(1);
        m_offsets.resize(1);
        m_pointers.resize(0);

        m_chars[0]      =   '\0';
        m_offsets[0]    =   0;
    }
/// @}

/// \name Accessors
/// @{
public:
    char_type const* const* base() const
    {
        if (m_pointers.size() != m_offsets.size())
        {
            set_pointers();
        }

        return m_pointers.data();
    }
    size_type size() const
    {
        STLSOFT_ASSERT(m_offsets.size() >= 1);

        return m_offsets.size() - 1;
    }
/// @}

// Implementation
private:
    void set_pointers()
    {
        if (m_pointers.resize(m_offsets.size()))
        {
            for (size_type i = 0; i < m_offsets.size(); ++i)
            {
                m_pointers[i] = &m_chars[m_offsets[i]];
            }
        }
    }

    void set_pointers() const
    {
        const_cast<class_type*>(this)->set_pointers();
    }

// Members
private:
    typedef STLSOFT_NS_QUAL(auto_buffer_old)<
        char_type
    ,   allocator_type
    ,   1024
    >                                                       char_buffer_type;

    typedef STLSOFT_NS_QUAL(auto_buffer_old)<
        size_type
#if defined(STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT)
    ,   ss_typename_type_k allocator_type::ss_template_qual_k rebind<size_type>::other
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    ,   ss_typename_type_k allocator_selector<size_type>::allocator_type
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    ,   32
    >                                                       offset_buffer_type;

    typedef STLSOFT_NS_QUAL(auto_buffer_old)<
        const_pointer
#if defined(STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT)
    ,   ss_typename_type_k allocator_type::ss_template_qual_k rebind<pointer>::other
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    ,   ss_typename_type_k allocator_selector<pointer>::allocator_type
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    ,   32
    >                                                       pointer_buffer_type;

    char_buffer_type        m_chars;
    offset_buffer_type      m_offsets;
    pointer_buffer_type     m_pointers;
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT

 /// Specialisation of the basic_path template for the ANSI character type \c char
typedef basic_environment_block<ss_char_a_t>    environment_block_a;
/** Specialisation of the basic_environment_block template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__Container
 */
typedef basic_environment_block<ss_char_w_t>    environment_block_w;

#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINERS_HPP_ENVIRONMENT_BLOCK */

/* ///////////////////////////// end of file //////////////////////////// */

