/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/string/grab_CString_buffer.hpp (originally MFGrbStr.h: ::SynesisMfc)
 *
 * Purpose:     CString Get/ReleaseBuffer scoping class.
 *
 * Created:     12th February 1999
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1999-2019, Matthew Wilson and Synesis Software
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


/** \file mfcstl/string/grab_CString_buffer.hpp
 *
 * \brief [C++] Definition of the mfcstl::grab_CString_buffer class
 *   (\ref group__library__String "String" Library).
 */

#ifndef MFCSTL_INCL_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER
#define MFCSTL_INCL_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER_MAJOR      5
# define MFCSTL_VER_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER_MINOR      0
# define MFCSTL_VER_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER_REVISION   1
# define MFCSTL_VER_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER_EDIT       72
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */
namespace stlsoft
{
namespace mfcstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * grab_CString_buffer
 *
 * This class is used to scope the aquisition and release of a CString buffer
 * ensuring that ReleaseBuffer() is called on the given CString object.
 */

/** Scopes the aquisition and release of a CString buffer
 *
 * \ingroup group__library__String
 *
 * This class is used to scope the aquisition and release of a CString buffer
 * ensuring that ReleaseBuffer() is called on the given CString object.
 */
class grab_CString_buffer
{
private:
    typedef grab_CString_buffer   class_type;

// Construction
public:
    /// Acquires the requested length on the given managed string
    ///
    /// Calls \c GetBuffer(length) on the given string, after recording the
    /// original length. If acquisition fails then a CMemoryException is thrown.
    grab_CString_buffer(CString &str, int length) stlsoft_throw_1(CMemoryException *);
    /// Releases the managed string.
    ~grab_CString_buffer() STLSOFT_NOEXCEPT;

// Conversion operators
public:
    /// Returns a pointer to a nul-terminated string
    LPCTSTR c_str() const;

    /// Provides mutating access to the managed string's internal buffer
    operator LPTSTR();
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
    /// Provides non-mutating access to the managed string's internal buffer
    operator LPCTSTR() const;
#endif /* compiler */

// Attributes
public:
    /// Returns the length of the managed string
    int length() const;
    /// Returns the original length of the managed string
    int original_length() const;

// Members
private:
    CString         &m_str;
    const int       m_len;
    const int       m_originalLen;
    const LPTSTR    m_psz;

// Not implemented
private:
    grab_CString_buffer(class_type const& rhs);
    class_type& operator =(class_type const& rhs);
};

/* /////////////////////////////////////////////////////////////////////////
 * backwards compatibility
 */

#ifdef STLSOFT_OBSOLETE

typedef grab_CString_buffer                                 grab_cstring_buffer;
#endif /* !STLSOFT_OBSOLETE */

////////////////////////////////////////////////////////////////////////////
// Implementation

inline grab_CString_buffer::grab_CString_buffer(CString &str, int length) stlsoft_throw_1(CMemoryException *)
    : m_str(str)
    , m_len(length)
    , m_originalLen(str.GetLength())
    , m_psz(str.GetBuffer(length))
{
    // Fortunately, objects of this class contain no resources of their own, and so
    // throwing an exception from the constructor is somewhat benign.

    // Newer versions of MFC do not append a nul character to the end of the reallocated
    // area, so we do that now
    m_psz[m_len] = '\0';
}

inline grab_CString_buffer::~grab_CString_buffer() STLSOFT_NOEXCEPT
{
    // Best to check that the end character has not been overwritten
    MFCSTL_MESSAGE_ASSERT("The client code has overwritten the managed area of the grab_CString_buffer instance", '\0' == m_psz[m_len]);

    // Dtor will never be called if GetBufferSetLength throws,
    // so we can assume we have a valid reference to an open
    // string which needs to be released here.
    m_str.ReleaseBuffer();
}

inline LPCTSTR grab_CString_buffer::c_str() const
{
    return m_psz;
}

inline grab_CString_buffer::operator LPTSTR()
{
    return m_psz;
}

#if !defined(STLSOFT_COMPILER_IS_BORLAND)
inline grab_CString_buffer::operator LPCTSTR() const
{
    return m_psz;
}
#endif /* compiler */

inline int grab_CString_buffer::length() const
{
    return m_len;
}

inline int grab_CString_buffer::original_length() const
{
    return m_originalLen;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace mfcstl */
# else
} /* namespace mfcstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !MFCSTL_INCL_MFCSTL_STRING_HPP_GRAB_CSTRING_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

