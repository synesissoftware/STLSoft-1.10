/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/synch/singlethreaded_tss_index.hpp
 *
 * Purpose:     An interface-compatible replacement for the tss_index
 *              classes defined elsewhere in the libraries, for use in
 *              single-threaded contexts.
 *
 * Created:     3rd February 2008
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/synch/singlethreaded_tss_index.hpp
 *
 * \brief [C++] An interface-compatible replacement for the tss_index
 *   classes defined elsewhere in the libraries, for use in single-threaded
 *   contexts.
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_SINGLE_THREADED_TSS_INDEX
#define STLSOFT_INCL_STLSOFT_SYNCH_HPP_SINGLE_THREADED_TSS_INDEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SINGLE_THREADED_TSS_INDEX_MAJOR      1
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SINGLE_THREADED_TSS_INDEX_MINOR      0
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SINGLE_THREADED_TSS_INDEX_REVISION   6
# define STLSOFT_VER_STLSOFT_SYNCH_HPP_SINGLE_THREADED_TSS_INDEX_EDIT       14
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_UNIXSTL
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

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

/** Interface-compatible single-threaded replacement for
 *    unixstl::tss_index, winstl::tss_index and platformstl::tss_index.
 *
 * \ingroup group__library__Synch
 */
class singlethreaded_tss_index
{
/// \name Types
/// @{
public:
    /// This class
    typedef singlethreaded_tss_index        class_type;
    /// The type of the TSS key
    typedef void                            key_type;
    /// The type of the slot values
    typedef void*                           value_type;
/// @}

/// \name Construction
/// @{
public:
    /// Allocates a TSS key
    ss_explicit_k singlethreaded_tss_index()
        : m_value(NULL)
    {}
    /// Releases the TSS key
    ~singlethreaded_tss_index() STLSOFT_NOEXCEPT
    {}
/// @}

/// \name Operations
/// @{
public:
    /// Sets the value in the slot for the current thread
    void        set_value(value_type value)
    {
        m_value = value;
    }
    /// Gets the value in the slot for the current thread
    value_type  get_value() const
    {
        return m_value;
    }
/// @}

/// \name Members
/// @{
private:
    value_type  m_value;
/// @}

/// \name Not to be implemented
/// @{
private:
    singlethreaded_tss_index(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

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

#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_SINGLE_THREADED_TSS_INDEX */

/* ///////////////////////////// end of file //////////////////////////// */

