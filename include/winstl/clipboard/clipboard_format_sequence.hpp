/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/clipboard/clipboard_format_sequence.hpp
 *
 * Purpose:     Enumerates clipboard formats.
 *
 * Created:     11th May 2003
 * Updated:     22nd January 2024
 *
 * Thanks:      To Martin Moene for reporting the lack of iterator traits
 *              of the const_iterator nested class; wiluite for a defect
 *              report.
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


/** \file winstl/clipboard/clipboard_format_sequence.hpp
 *
 * \brief [C++] Definition of the winstl::clipboard_format_sequence
 *  class
 *   (\ref group__library__Windows_Clipboard "Windows Clipboard" Library).
 */

#ifndef WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_FORMAT_SEQUENCE
#define WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_FORMAT_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_FORMAT_SEQUENCE_MAJOR    4
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_FORMAT_SEQUENCE_MINOR    0
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_FORMAT_SEQUENCE_REVISION 10
# define WINSTL_VER_WINSTL_CLIPBOARD_HPP_CLIPBOARD_FORMAT_SEQUENCE_EDIT     49
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
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

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

// class clipboard_format_sequence
/** This class provides an STL-like sequence for iterating the
 *   clipboard formats for the current process.
 *
 * \ingroup group__library__Windows_Clipboard
 *
 * The class enables the formats currently available on the clipboard to be
 * enumerated, as shown in the following example:
\code
  winstl::clipboard_format_sequence   fmt;

  std::copy(fmt.begin(), fmt.end()
          , stlsoft::ostream_iterator<UINT>(std::cout, "\t", "\n"));
\endcode
 *
 * On the system on which this documentation was written, this printed the
 * following:
\code
    1
    16
    7
    13
\endcode
 *
 * which are
 *  <code>CF_TEXT</code>,
 *  <code>CF_LOCALE</code>,
 *  <code>CF_OEMTEXT</code>,
 * and
 *  <code>CF_UNICODETEXT</code>.
 */
class clipboard_format_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
/// \name Member Types
/// @{
public:
    /// The type
    typedef clipboard_format_sequence       class_type;
    /// The value type
    typedef UINT                            value_type;
    /// The size type
    typedef ws_size_t                       size_type;
    /// The difference type
    typedef ws_ptrdiff_t                    difference_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs a sequence object, attempting to open the clipboard
    clipboard_format_sequence()
        : m_bOpen(::OpenClipboard(NULL) != FALSE)
    {}

    /// Release any resources acquired
    ~clipboard_format_sequence() STLSOFT_NOEXCEPT
    {
        if (m_bOpen)
        {
            ::CloseClipboard();
        }
    }
/// @}

/// \name Iteration
/// @{
public:
    /// Non-mutating iterator class
    class const_iterator
        : public STLSOFT_NS_QUAL(iterator_base)<STLSOFT_NS_QUAL_STD(input_iterator_tag)
                                            ,   value_type
                                            ,   ws_ptrdiff_t
                                            ,   void        // By-Value Temporary reference
                                            ,   value_type  // By-Value Temporary reference
                                            >
    {
        friend class clipboard_format_sequence;

    public:
        /// The type
        typedef const_iterator              class_type;
        /// The container type
        typedef clipboard_format_sequence   container_type;

    /// \name Construction
    /// @{
    private:
        /// Constructs an iterator from the given format
        const_iterator(UINT nextFmt)
            : m_nextFmt(nextFmt)
        {}
    public:
        /// Constructs an iterator
        const_iterator()
            : m_nextFmt(0)
        {}
        /// Copy constructor
        const_iterator(class_type const& rhs)
            : m_nextFmt(rhs.m_nextFmt)
        {}

        /// Copy assignment operator
        class_type& operator =(class_type const& rhs)
        {
            m_nextFmt = rhs.m_nextFmt;

            return *this;
        }

    /// @}

    public:
        /// Pre-increment operator
        class_type& operator ++()
        {
            WINSTL_MESSAGE_ASSERT("Incrementing an invalid iterator!", m_nextFmt != 0);

            m_nextFmt = ::EnumClipboardFormats(m_nextFmt);

            return *this;
        }
        /// Post-increment operator
        class_type operator ++(int)
        {
            class_type  ret(*this);

            operator ++();

            return ret;
        }

        value_type operator *() const
        {
            WINSTL_MESSAGE_ASSERT("Dereferencing an invalid iterator!", m_nextFmt != 0);

            return m_nextFmt;
        }

        /// Evaluates whether \c this and \c rhs are equivalent
        ///
        /// \param rhs The instance against which to compare
        /// \retval true If \c this and \c rhs are equivalent
        /// \retval false If \c this and \c rhs are not equivalent
        ws_bool_t operator ==(class_type const& rhs) const
        {
            return m_nextFmt == rhs.m_nextFmt;
        }

        /// Evaluates whether \c this and \c rhs are not equivalent
        ///
        /// \param rhs The instance against which to compare
        /// \retval true If \c this and \c rhs are not equivalent
        /// \retval false If \c this and \c rhs are equivalent
        ws_bool_t operator !=(class_type const& rhs) const
        {
            return !operator ==(rhs);
        }

    /// Members
    private:
        UINT    m_nextFmt;
    };

    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const
    {
        return const_iterator(::EnumClipboardFormats(0));
    }
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const
    {
        return const_iterator(0);
    }

    /// Indicates whether the search sequence is empty
    ws_bool_t empty() const
    {
        return begin() == end();
    }

    /// Returns the number of elements in the sequence
    size_type size() const
    {
        return static_cast<size_type>(::CountClipboardFormats());
    }

    /// Indicates whether the search sequence is valid
    ///
    /// \note The sequence may not be able to access the clipboard formats if another window is currently holding the clipboard via a call to <b>OpenClipboard()</b>
    ws_bool_t inaccessible() const
    {
        return !m_bOpen;
    }
/// @}

/// \name Members
/// @{
private:
    ws_bool_t   m_bOpen;
/// @}

/// \name Not to be implemented
/// @{
private:
    clipboard_format_sequence(clipboard_format_sequence const&);
    clipboard_format_sequence& operator =(clipboard_format_sequence const&);
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

#endif /* !WINSTL_INCL_WINSTL_CLIPBOARD_HPP_CLIPBOARD_FORMAT_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

