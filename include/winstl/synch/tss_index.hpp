/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/tss_index.hpp (originally in MWTlsFns.h, ::SynesisWin)
 *
 * Purpose:     Wrapper class for Win32 TSS key.
 *
 * Created:     20th January 1999
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/synch/tss_index.hpp
 *
 * \brief [C++] Definition of winstl::tss_index class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_TSS_INDEX
#define WINSTL_INCL_WINSTL_SYNCH_HPP_TSS_INDEX

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_TSS_INDEX_MAJOR    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_TSS_INDEX_MINOR    0
# define WINSTL_VER_WINSTL_SYNCH_HPP_TSS_INDEX_REVISION 14
# define WINSTL_VER_WINSTL_SYNCH_HPP_TSS_INDEX_EDIT     55
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

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON
# include <winstl/synch/common.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_COMMON */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Debugging
# include <winstl/api/external/Debugging.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Debugging */
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

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
/** Indicates that a TSS key cannot be allocated.
 *
 * \note This exception indicates an irrecoverable condition.
 *
 * \ingroup group__library__Synch
 */
class tss_exception
    : public synchronisation_exception
{
/// \name Types
/// @{
public:
    typedef synchronisation_exception                       parent_class_type;
    typedef tss_exception                                   class_type;
    typedef parent_class_type::system_status_code_type      system_status_code_type;
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    typedef system_status_code_type                         error_code_type;
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Construction
/// @{
public:
    tss_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    )
        : parent_class_type(sc, message, Synchronisation_TssIndexCreationFailed)
    {}
/// @}

/// \name Accessors
/// @{
public:
    virtual char const* what() const STLSOFT_NOEXCEPT_STDOVR
    {
        return "failed to allocate a TSS key";
    }
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type& operator =(class_type const&);
/// @}
};
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/** Wrapper for a Win32 TSS key (TLS index).
 *
 * \ingroup group__library__Synch
 */
class tss_index
{
/// \name Types
/// @{
public:
    /// This class
    typedef tss_index   class_type;
    /// The type of the TSS key
    typedef ws_dword_t  key_type;
    /// The type of the TSS key
    ///
    /// \deprecated Deprecated in favour of key_type
    typedef key_type    index_type;
    /// The type of the slot values
    typedef void*       value_type;
/// @}

/// \name Construction
/// @{
public:
    /// Allocates a TSS key
    ss_explicit_k tss_index()
        : m_index(index_create_())
    {}
    /// Releases the TSS key
    ~tss_index() STLSOFT_NOEXCEPT
    {
        index_destroy_(m_index);
    }
/// @}

/// \name Operations
/// @{
public:
    /// Sets the value in the slot for the current thread
    void        set_value(value_type value)
    {
        class_type::set_slot_value_(m_index, value);
    }
    /// Gets the value in the slot for the current thread
    value_type  get_value() const
    {
        return class_type::get_slot_value_(m_index);
    }
/// @}

/// \name Accessors
/// @{
public:
    /// Implicit conversion operator to the
    operator key_type () const
    {
        return m_index;
    }
/// @}

/// \name Implementation
/// @{
private:
    static key_type index_create_()
    {
        key_type const key = ::TlsAlloc();

        if (0xFFFFFFFF == key)
        {
            DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(tss_exception(e, "could not allocate a TSS key"));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            WINSTL_API_EXTERNAL_Debugging_OutputDebugStringA("fatal: could not allocate a TSS key!\n");
            ::RaiseException(STATUS_NO_MEMORY, EXCEPTION_NONCONTINUABLE, 0, 0);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return key;
    }

    static void index_destroy_(key_type key)
    {
        ::TlsFree(key);
    }

    static void set_slot_value_(key_type key, value_type value)
    {
        ::TlsSetValue(key, value);
    }

    static value_type get_slot_value_(key_type key)
    {
        return ::TlsGetValue(key);
    }
/// @}

/// \name Members
/// @{
private:
    key_type    m_index;
/// @}

/// \name Not to be implemented
/// @{
private:
    tss_index(class_type const&);
    class_type& operator =(class_type const&);
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_TSS_INDEX */

/* ///////////////////////////// end of file //////////////////////////// */

