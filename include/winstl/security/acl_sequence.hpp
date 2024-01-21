/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/security/acl_sequence.hpp
 *
 * Purpose:     Helper for accessing token information.
 *
 * Created:     26th June 2003
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/security/acl_sequence.hpp
 *
 * \brief [C++] Definition of the winstl::acl_sequence class
 *   (\ref group__library__Security "Security" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SECURITY_HPP_ACL_SEQUENCE
#define WINSTL_INCL_WINSTL_SECURITY_HPP_ACL_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SECURITY_HPP_ACL_SEQUENCE_MAJOR      4
# define WINSTL_VER_WINSTL_SECURITY_HPP_ACL_SEQUENCE_MINOR      0
# define WINSTL_VER_WINSTL_SECURITY_HPP_ACL_SEQUENCE_REVISION   6
# define WINSTL_VER_WINSTL_SECURITY_HPP_ACL_SEQUENCE_EDIT       46
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

#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */

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

/** Provides an iterable sequence of ACEs in an ACL
 *
 * \ingroup group__library__Security
 *
 * This class provides an iterable sequence of Access Control Entries (ACEs)
 * in an Access Control List (ACL).
 */
class acl_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
/// \name Member Types
/// @{
public:
    typedef acl_sequence    class_type;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k acl_sequence(PACL pacl)
        : m_pacl(pacl)
    {}
private:
    acl_sequence(class_type const&);            // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Iteration
/// @{
public:
    /// The const_iterator for the acl_sequence class
    class const_iterator
    {
    protected:
        friend class acl_sequence;

        const_iterator(ws_uint32_t count, ACE_HEADER *header)
            : m_index(0)
            , m_count(count)
            , m_header(header)
        {}
    public:
        const_iterator()
            : m_index(0)
            , m_count(0)
            , m_header(0)
        {}

        const_iterator(const_iterator const& rhs)
            : m_index(rhs.m_index)
            , m_count(rhs.m_count)
            , m_header(rhs.m_header)
        {}

        const_iterator& operator =(const_iterator const& rhs)
        {
            m_index     =   rhs.m_index;
            m_count     =   rhs.m_count;
            m_header    =   rhs.m_header;

            return *this;
        }

        const_iterator& operator ++()
        {
            WINSTL_MESSAGE_ASSERT("Incrementing an invalid iterator", (m_header != 0 && m_index < m_count));

            if (++m_index == m_count)
            {
                m_header = 0;
            }
            else
            {
                m_header = (ACE_HEADER*)ptr_byte_offset(m_header, m_header->AceSize);
            }

            return *this;
        }
        const_iterator operator ++(int)
        {
            const_iterator  ret(*this);

            operator ++();

            return ret;
        }

        ACE_HEADER *operator *() const
        {
            WINSTL_MESSAGE_ASSERT("Dereferencing an invalid iterator", m_header != 0);

            return m_header;
        }

        ws_bool_t operator ==(const_iterator const& rhs)
        {
            return m_header == rhs.m_header;
        }
        ws_bool_t operator !=(const_iterator const& rhs)
        {
            return !operator ==(rhs);
        }

    // Members
    private:
        ws_uint32_t m_index;
        ws_uint32_t m_count;
        ACE_HEADER* m_header;
    };

    const_iterator begin() const
    {
        return const_iterator(m_pacl->AceCount, (ACE_HEADER*)(m_pacl + 1));
    }
    const_iterator end() const
    {
        return const_iterator();
    }
/// @}

/// \name Attributes
/// @{
public:
    ws_size_t   size() const
    {
        return m_pacl->AceCount;
    }
    ws_bool_t   empty() const
    {
        return 0 == size();
    }
/// @}

/// \name Members
/// @{
private:
    PACL    m_pacl;
/// @}
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SECURITY_HPP_ACL_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

