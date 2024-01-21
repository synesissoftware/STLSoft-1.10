/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/shims/access/string/VARIANT.hpp
 *
 * Purpose:     Definition of the string access shims for the VARIANT type.
 *
 * Created:     24th May 2002
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/shims/access/string/VARIANT.hpp
 *
 * \brief [C++] Definition of the string access shims for the
 *   <code>VARIANT</code> type
 *   (\ref group__concept__Shim__string_access "String Access Shims" Concept).
 */

#ifndef COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT
#define COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT_MAJOR    5
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT_MINOR    4
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT_REVISION 8
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT_EDIT     149
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS
# include <comstl/string/BSTR_functions.h>
#endif /* !COMSTL_INCL_COMSTL_STRING_H_BSTR_FUNCTIONS */
#ifndef COMSTL_INCL_COMSTL_UTIL_H_VARIANT_FUNCTIONS
# include <comstl/util/VARIANT_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_VARIANT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION
# include <stlsoft/exception/out_of_memory_exception.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_OUT_OF_MEMORY_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */

#ifdef STLSOFT_CF_THROW_BAD_ALLOC
# include <new>
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet
# include <winstl/api/external/UnicodeAndCharacterSet.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_UnicodeAndCharacterSet */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper classes & functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
struct ximpl_comstl_shims_access_string_variant_
{
public:
    static
    BSTR
    BSTR_from_SCODE(
        SCODE scode
    )
    {
        OSVERSIONINFO   osvi;

        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

#include <stlsoft/internal/warnings/push/suppress_deprecation_.h>

        if (!::GetVersionEx(&osvi) ||
            VER_PLATFORM_WIN32_NT != osvi.dwPlatformId)
#include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>
        {
            /* Not supported on Windows 9x */
            return NULL;
        }
        else
        {
            // Format: (error=%d{, <text>})

            WCHAR   code[23];
            LPWSTR  msg     =   NULL;
            DWORD   cchCode =   static_cast<DWORD>(::wsprintfW(&code[0], L"%d\00x%08x" + ((0x8000000 & scode) ? 3 : 0), scode));
            DWORD   cchMsg  =   ::FormatMessageW(   FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS
                                                ,   NULL
                                                ,   DWORD(scode)
                                                ,   MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
                                                ,   (LPWSTR)&msg
                                                ,   0
                                                ,   NULL);
            DWORD   cchAll  =   cchCode;

            if (0 == cchMsg)
            {
                DWORD const e = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

                if (ERROR_OUTOFMEMORY == e)
                {
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
                    STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_COMSTL, STLSoftLibraryIdentifier_Shims_Access_String, e));
#else /* ? STLSOFT_CF_THROW_BAD_ALLOC */
                    return NULL;
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
                }
            }
            else
            {
                for (; 0 != cchCode; --cchMsg)
                {
                    WCHAR& ch = msg[cchMsg - 1];

                    switch (ch)
                    {
                        case    L'\r':
                        case    L'\n':
                        case    L' ':
                        case    L'.':
                            ch = L'\0';;
                            break;
                    }

                    if (L'\0' != ch)
                    {
                        break;
                    }
                }

                cchAll += 2 + cchMsg;
            }

            BSTR result = ::SysAllocStringLen(NULL, cchAll);

            if (NULL == result)
            {
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
                ::LocalFree(msg);
                msg = NULL;

                STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_COMSTL, STLSoftLibraryIdentifier_Shims_Access_String, WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
            }
            else
            {
                STLSOFT_API_INTERNAL_memfns_memcpy(result + 0, code, cchCode * sizeof(WCHAR));
                if (0 != cchMsg)
                {
                    STLSOFT_API_INTERNAL_memfns_memcpy(result + cchCode, L", ", 2 * sizeof(WCHAR));
                    STLSOFT_API_INTERNAL_memfns_memcpy(result + cchCode + 2, msg, cchMsg * sizeof(WCHAR));
                }
            }

            if (NULL != msg)
            {
                ::LocalFree(msg);
            }

            return result;
        }
    }

    static
    void
    prepare_VARIANT_copy_or_throw(
        VARIANT*        dest
    ,   VARIANT const&  src
    )
    {
        COMSTL_ASSERT(NULL != dest);
        COMSTL_ASSERT(VT_EMPTY == dest->vt);

        HRESULT hr = VARIANT_change_type(dest, &src, LOCALE_USER_DEFAULT, VARIANT_ALPHABOOL, VT_BSTR);

#ifdef STLSOFT_CF_THROW_BAD_ALLOC
        if (E_OUTOFMEMORY == hr)
        {
            STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_COMSTL, STLSoftLibraryIdentifier_Shims_Access_String, hr));
        }
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */

        if (FAILED(hr))
        {
            if (VT_ERROR == src.vt)
            {
                dest->bstrVal = BSTR_from_SCODE(src.scode);
            }
            else
            {
                dest->bstrVal = NULL;
            }
        }
    }

private:
    static
    bool
    string_equal_by_VT_(
        cs_char_a_t const*  s1
    ,   cs_size_t const&    cch1
    ,   cs_char_a_t const*  s2
    ,   cs_size_t const&    cch2
    ,   VARTYPE const&      vt
    )
    {
        if (cch1 != cch2)
        {
            return false;
        }

        if (0 == cch1)
        {
            return true;
        }

        switch (vt)
        {
        default:
            return 0 == STLSOFT_NS_GLOBAL(strncmp)(s1, s2, cch1);

#ifdef STLSOFT_API_EXTERNAL_string_strnicmp

        case VT_BOOL:
            return 0 == STLSOFT_API_EXTERNAL_string_strnicmp(s1, s2, cch1);
#endif
        }
    }

    static
    bool
    string_equal_by_VT_(
        cs_char_w_t const*  s1
    ,   cs_size_t const&    cch1
    ,   cs_char_w_t const*  s2
    ,   cs_size_t const&    cch2
    ,   VARTYPE const&      vt
    )
    {
        if (cch1 != cch2)
        {
            return false;
        }

        if (0 == cch1)
        {
            return true;
        }

        switch (vt)
        {
        default:
            return 0 == STLSOFT_NS_GLOBAL(wcsncmp)(s1, s2, cch1);

#ifdef STLSOFT_API_EXTERNAL_string_wcsnicmp

        case VT_BOOL:
            return 0 == STLSOFT_API_EXTERNAL_string_wcsnicmp(s1, s2, cch1);
#endif
        }
    }

public:
    template <ss_typename_type_k C>
    static
    bool
    string_equal_by_VT(
        C const*            s1
    ,   cs_size_t const&    cch1
    ,   C const*            s2
    ,   cs_size_t const&    cch2
    ,   VARTYPE const&      vt
    )
    {
        return string_equal_by_VT_(s1, cch1, s2, cch2, vt);
    }
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_null() function, such that the text of a given variant
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_null_VARIANT_proxy_w
{
// Types
public:
    typedef c_str_null_VARIANT_proxy_w                      class_type;
    typedef cs_char_w_t                                     char_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given BSTR
    ///
    /// \param s The BSTR from which the text will be retrieved
    /// \param vt The variant type of the origin VARIANT instance
    c_str_null_VARIANT_proxy_w(
        BSTR&   s
    ,   VARTYPE vt
    )
        : m_bstr(s)
        , m_vt(vt)
    {
        s = NULL;
    }

#ifdef STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_null_VARIANT_proxy_w(class_type& rhs)
        : m_bstr(rhs.m_bstr)
        , m_vt(rhs.m_vt)
    {
        move_lhs_from_rhs(rhs).m_bstr = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_null_VARIANT_proxy_w(class_type const& rhs)
        : m_bstr(BSTR_dup(rhs.m_bstr))
        , m_vt(rhs.m_vt)
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage acquired by the proxy
    ~c_str_null_VARIANT_proxy_w() STLSOFT_NOEXCEPT
    {
        ::SysFreeString(m_bstr);
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

// Accessors
public:
    /// Returns a null-terminated string representing the VARIANT contents.
    operator LPCOLESTR () const
    {
        return (0u != ::SysStringLen(m_bstr)) ? m_bstr : NULL;
    }

// Comparison
public:
    bool
    equal(
        char_type const* rhs
    ) const STLSOFT_NOEXCEPT
    {
        cs_size_t const rhsLen = stlsoft::c_str_len(rhs);

        return ximpl_comstl_shims_access_string_variant_::string_equal_by_VT(m_bstr, ::SysStringLen(m_bstr), rhs, rhsLen, m_vt);
    }

// Fields
private:
    BSTR            m_bstr;
    VARTYPE const   m_vt;
};


/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_a() function, such that the text of a given variant
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_null_VARIANT_proxy_a
{
// Types
public:
    typedef c_str_null_VARIANT_proxy_a                      class_type;
    typedef cs_char_a_t                                     char_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given BSTR
    ///
    /// \param s The BSTR from which the text will be retrieved
    /// \param vt The variant type of the origin VARIANT instance
    c_str_null_VARIANT_proxy_a(
        BSTR&   s
    ,   VARTYPE vt
    )
        : m_bstr(s)
        , m_buffer(NULL)
        , m_vt(vt)
    {
        s = NULL;
    }

#ifdef STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_null_VARIANT_proxy_a(class_type& rhs)
        : m_bstr(rhs.m_bstr)
        , m_buffer(rhs.m_buffer)
        , m_vt(rhs.m_vt)
    {
        move_lhs_from_rhs(rhs).m_bstr = NULL;
        move_lhs_from_rhs(rhs).m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_null_VARIANT_proxy_a(class_type const& rhs)
        : m_bstr(BSTR_dup(rhs.m_bstr))
        , m_buffer(NULL)
        , m_vt(rhs.m_vt)
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage acquired by the proxy
    ~c_str_null_VARIANT_proxy_a() STLSOFT_NOEXCEPT
    {
        ::SysFreeString(m_bstr);
#ifndef STLSOFT_CF_THROW_BAD_ALLOC
        if (empty_string_() != m_buffer)
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
        {
            ::CoTaskMemFree(m_buffer);
        }
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

// Accessors
public:
    /// Returns a null-terminated string representing the VARIANT contents.
    operator char_type const* () const
    {
        if (NULL == m_buffer)
        {
            cs_size_t cch = ::SysStringLen(m_bstr);

            if (0 != cch)
            {
                LPCOLESTR   w_value =   m_bstr;
                char_type*& buffer_ =   const_cast<class_type*>(this)->m_buffer;

                buffer_ = static_cast<char_type *>(::CoTaskMemAlloc((1 + cch) * sizeof(char_type)));

                if (NULL == buffer_)
                {
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
                    STLSOFT_THROW_X(STLSOFT_NS_QUAL(out_of_memory_exception)(STLSoftProjectIdentifier_COMSTL, STLSoftLibraryIdentifier_Shims_Access_String, WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_THROW_BAD_ALLOC */
                    buffer_ = empty_string_();
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
                }
                else
                {
                    int const n = WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_WideCharToMultiByte(0, 0, w_value, -1, buffer_, static_cast<int>(cch + 1), NULL, NULL);

#ifdef WIN32
                    if (0 == n)
#else /* ? WIN32 */
# error Not currently implemented for operating systems other than Win32
#endif /* WIN32 */
                    {
                        // TODO: report failure to convert via exception
#if defined(STLSOFT_COMPILER_IS_BORLAND)
                        w_value = NULL; // Need this fatuous operation, in order to prevent Borland from optimising out the previous statement
#endif
                    }
                }
            }
        }

        return m_buffer;
    }

// Comparison
public:
    bool
    equal(
        char_type const* rhs
    ) const STLSOFT_NOEXCEPT
    {
        char_type const* const  lhs     =   *this;
        cs_size_t const         lhsLen  =   (NULL != lhs) ? ::SysStringLen(m_bstr) : 0;
        cs_size_t const         rhsLen  =   stlsoft::c_str_len(rhs);

        return ximpl_comstl_shims_access_string_variant_::string_equal_by_VT(lhs, lhsLen, rhs, rhsLen, m_vt);
    }

// Implementation
private:
#ifndef STLSOFT_CF_THROW_BAD_ALLOC
    static char_type* empty_string_()
    {
        // This character array is initialised to 0, which conveniently happens to
        // be the empty string, by the module/application load, so it is
        // guaranteed to be valid, and there are no threading/race conditions
        static char_type s_empty[1];

        COMSTL_ASSERT(s_empty[0] == '\0'); // Paranoid check

        return s_empty;
    }
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */

// Fields
private:
    BSTR            m_bstr;
    char_type*      m_buffer;
    VARTYPE const   m_vt;
};

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_w() function, such that the text of a given variant
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_VARIANT_proxy_w
{
// Types
public:
    typedef c_str_VARIANT_proxy_w                           class_type;
    typedef cs_char_w_t                                     char_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given BSTR
    ///
    /// \param s The BSTR from which the text will be retrieved
    /// \param vt The variant type of the origin VARIANT instance
    c_str_VARIANT_proxy_w(
        BSTR&   s
    ,   VARTYPE vt
    )
        : m_bstr(s)
        , m_vt(vt)
    {
        s = NULL;
    }

#ifdef STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_VARIANT_proxy_w(class_type& rhs)
        : m_bstr(rhs.m_bstr)
        , m_vt(rhs.m_vt)
    {
        move_lhs_from_rhs(rhs).m_bstr = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_VARIANT_proxy_w(class_type const& rhs)
        : m_bstr(BSTR_dup(rhs.m_bstr))
        , m_vt(rhs.m_vt)
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage acquired by the proxy
    ~c_str_VARIANT_proxy_w() STLSOFT_NOEXCEPT
    {
        ::SysFreeString(m_bstr);
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

// Accessors
public:
    /// Returns a null-terminated string representing the VARIANT contents.
    operator LPCOLESTR () const
    {
        return (m_bstr == NULL) ? L"" : m_bstr;
    }

// Comparison
public:
    /// Compares the instance with the given C-style string
    bool
    equal(
        char_type const* rhs
    ) const STLSOFT_NOEXCEPT
    {
        cs_size_t const rhsLen = stlsoft::c_str_len(rhs);

        return ximpl_comstl_shims_access_string_variant_::string_equal_by_VT(m_bstr, ::SysStringLen(m_bstr), rhs, rhsLen, m_vt);
    }

// Members
private:
    BSTR            m_bstr;
    VARTYPE const   m_vt;
};

/** This class provides an intermediary object that may be returned by the
 * c_str_ptr_a() function, such that the text of a given variant
 * may be accessed as a null-terminated string.
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
class c_str_VARIANT_proxy_a
{
// Types
public:
    typedef c_str_VARIANT_proxy_a                           class_type;
    typedef cs_char_a_t                                     char_type;

// Construction
public:
    /// Constructs an instance of the proxy from the given c_str_VARIANT_proxy_w
    ///
    /// \param s The BSTR instance from which the proxy instance will be
    ///   constructed
    /// \param vt The variant type of the origin VARIANT instance
    c_str_VARIANT_proxy_a(
        BSTR&   s
    ,   VARTYPE vt
    )
        : m_bstr(s)
        , m_buffer(NULL)
        , m_vt(vt)
    {
        s = NULL;
    }

#ifdef STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT
    /// Move constructor
    ///
    /// This <a href = "http://synesis.com.au/resources/articles/cpp/movectors.pdf">move constructor</a>
    /// is for circumstances when the compiler does not, or cannot, apply the
    /// return value optimisation. It causes the contents of \c rhs to be
    /// transferred into the constructing instance. This is completely safe
    /// because the \c rhs instance will never be accessed in its own right, so
    /// does not need to maintain ownership of its contents.
    c_str_VARIANT_proxy_a(class_type& rhs)
        : m_bstr(rhs.m_bstr)
        , m_buffer(rhs.m_buffer)
        , m_vt(rhs.m_vt)
    {
        move_lhs_from_rhs(rhs).m_bstr = NULL;
        move_lhs_from_rhs(rhs).m_buffer = NULL;
    }
#else /* ? STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */
    // Copy constructor
    c_str_VARIANT_proxy_a(class_type const& rhs)
        : m_bstr(BSTR_dup(rhs.m_bstr))
        , m_buffer(NULL)
        , m_vt(rhs.m_vt)
    {}
#endif /* STLSOFT_CF_MOVE_CONSTRUCTOR_SUPPORT */

    /// Releases any storage acquired by the proxy
    ~c_str_VARIANT_proxy_a() STLSOFT_NOEXCEPT
    {
        ::SysFreeString(m_bstr);
        if (m_buffer != empty_string_())
        {
            ::CoTaskMemFree(m_buffer);
        }
    }
private:
    void operator =(class_type const& rhs); // copy-assignment proscribed

// Accessors
public:
    /// Returns a null-terminated string representing the VARIANT contents.
    operator char_type const* () const
    {
        if (NULL == m_buffer)
        {
            LPCOLESTR   w_value =   m_bstr;
            char_type*& buffer_ =   const_cast<class_type*>(this)->m_buffer;

            if (NULL == w_value ||
                L'\0' == *w_value)
            {
                buffer_ = empty_string_();
            }
            else
            {
                cs_size_t cch = ::SysStringLen(m_bstr);

                buffer_ = static_cast<char_type*>(::CoTaskMemAlloc((1 + cch) * sizeof(char_type)));

                if (NULL == buffer_)
                {
                    buffer_ = empty_string_();
                }
                else
                {
                    int const n = WINSTL_API_EXTERNAL_UnicodeAndCharacterSet_WideCharToMultiByte(0, 0, w_value, -1, buffer_, static_cast<int>(cch + 1), NULL, NULL);

#ifdef WIN32
                    if (0 == n)
#else /* ? WIN32 */
# error Not currently implemented for operating systems other than Win32
#endif /* WIN32 */
                    {
                        // TODO: report failure to convert via exception
#if defined(STLSOFT_COMPILER_IS_BORLAND)
                        w_value = NULL; // Need this fatuous operation, in order to prevent Borland from optimising out the previous statement
#endif
                    }
                }
            }
        }

        return m_buffer;
    }

// Comparison
public:
    bool
    equal(
        char_type const* rhs
    ) const STLSOFT_NOEXCEPT
    {
        char_type const* const  lhs     =   *this;
        cs_size_t const         lhsLen  =   (NULL != lhs) ? ::SysStringLen(m_bstr) : 0;
        cs_size_t const         rhsLen  =   stlsoft::c_str_len(rhs);

        return ximpl_comstl_shims_access_string_variant_::string_equal_by_VT(lhs, lhsLen, rhs, rhsLen, m_vt);
    }

// Implementation
private:
    static char_type* empty_string_()
    {
        // This character array is initialised to 0, which conveniently happens to
        // be the empty string, by the module/application load, so it is
        // guaranteed to be valid, and there are no threading/race conditions
        static char_type s_empty[1];

        COMSTL_ASSERT(s_empty[0] == '\0'); // Paranoid check

        return s_empty;
    }

// Fields
private:
    BSTR            m_bstr;
    char_type*      m_buffer;
    VARTYPE const   m_vt;
};

/* /////////////////////////////////////////////////////////////////////////
 * equivalence testing
 */

// c_str_null_VARIANT_proxy_a
inline
cs_bool_t
operator ==(
    LPCSTR                              lhs
,   c_str_null_VARIANT_proxy_a const&   rhs
)
{
    return rhs.equal(lhs);
}

inline
cs_bool_t
operator ==(
    c_str_null_VARIANT_proxy_a const&   lhs
,   LPCSTR                              rhs
)
{
    return lhs.equal(rhs);
}

inline
cs_bool_t
operator !=(
    LPCSTR                              lhs
,   c_str_null_VARIANT_proxy_a const&   rhs
)
{
    return !rhs.equal(lhs);
}

inline
cs_bool_t
operator !=(
    c_str_null_VARIANT_proxy_a const&   lhs
,   LPCSTR                              rhs
)
{
    return !lhs.equal(rhs);
}

// c_str_null_VARIANT_proxy_w
inline
cs_bool_t
operator ==(
    LPCOLESTR                           lhs
,   c_str_null_VARIANT_proxy_w const&   rhs
)
{
    return rhs.equal(lhs);
}

inline
cs_bool_t
operator ==(
    c_str_null_VARIANT_proxy_w const&   lhs
,   LPCOLESTR                           rhs
)
{
    return lhs.equal(rhs);
}

inline
cs_bool_t
operator !=(
    LPCOLESTR                           lhs
,   c_str_null_VARIANT_proxy_w const&   rhs
)
{
    return !rhs.equal(lhs);
}

inline
cs_bool_t
operator !=(
    c_str_null_VARIANT_proxy_w const&   lhs
,   LPCOLESTR                           rhs
)
{
    return !lhs.equal(rhs);
}

// c_str_VARIANT_proxy_a
inline
cs_bool_t
operator ==(
    LPCSTR                          lhs
,   c_str_VARIANT_proxy_a const&    rhs
)
{
    return rhs.equal(lhs);
}

inline
cs_bool_t
operator ==(
    c_str_VARIANT_proxy_a const&    lhs
,   LPCSTR                          rhs
)
{
    return lhs.equal(rhs);
}

inline
cs_bool_t
operator !=(
    LPCSTR                          lhs
,   c_str_VARIANT_proxy_a const&    rhs
)
{
    return !rhs.equal(lhs);
}

inline
cs_bool_t
operator !=(
    c_str_VARIANT_proxy_a const&    lhs
,   LPCSTR                          rhs
)
{
    return !lhs.equal(rhs);
}

// c_str_VARIANT_proxy_w
inline
cs_bool_t
operator ==(
    LPCOLESTR                       lhs
,   c_str_VARIANT_proxy_w const&    rhs
)
{
    return rhs.equal(lhs);
}

inline
cs_bool_t
operator ==(
    c_str_VARIANT_proxy_w const&    lhs
,   LPCOLESTR                       rhs
)
{
    return lhs.equal(rhs);
}

inline
cs_bool_t
operator !=(
    LPCOLESTR                       lhs
,   c_str_VARIANT_proxy_w const&    rhs
)
{
    return !rhs.equal(lhs);
}

inline
cs_bool_t
operator !=(
    c_str_VARIANT_proxy_w const&    lhs
,   LPCOLESTR                       rhs
)
{
    return !lhs.equal(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * iostream compatibility
 */

template <ss_typename_param_k S>
inline
S&
operator <<(
    S&                                  s
,   c_str_null_VARIANT_proxy_w const&   shim
)
{
    s << stlsoft::c_str_ptr_w(shim);

    return s;
}

template <ss_typename_param_k S>
inline
S&
operator <<(
    S&                                  s
,   c_str_null_VARIANT_proxy_a const&   shim
)
{
    s << stlsoft::c_str_ptr_a(shim);

    return s;
}

template <ss_typename_param_k S>
inline
S&
operator <<(
    S&                                  s
,   c_str_VARIANT_proxy_w const&        shim
)
{
    s << stlsoft::c_str_ptr_w(shim);

    return s;
}

template <ss_typename_param_k S>
inline
S&
operator <<(
    S&                                  s
,   c_str_VARIANT_proxy_a const&        shim
)
{
    s << stlsoft::c_str_ptr_a(shim);

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
c_str_VARIANT_proxy_a
c_str_data_a(
    VARIANT const& v
)
{
    VARIANT vs;

    ::VariantInit(&vs);

    ximpl_comstl_shims_access_string_variant_::prepare_VARIANT_copy_or_throw(&vs, v);

    return c_str_VARIANT_proxy_a(vs.bstrVal, v.vt);
}

inline
c_str_VARIANT_proxy_w
c_str_data_w(
    VARIANT const& v
)
{
    VARIANT vs;

    ::VariantInit(&vs);

    ximpl_comstl_shims_access_string_variant_::prepare_VARIANT_copy_or_throw(&vs, v);

    return c_str_VARIANT_proxy_w(vs.bstrVal, v.vt);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Returns the corresponding possibly unterminated C-string pointer of the VARIANT \c v
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
#ifdef UNICODE
inline
c_str_VARIANT_proxy_w
c_str_data(
    VARIANT const& v
)
#else /* ? UNICODE */
inline
c_str_VARIANT_proxy_a
c_str_data(
    VARIANT const& v
)
#endif /* UNICODE */
{
#ifdef UNICODE
    return c_str_data_w(v);
#else /* ? UNICODE */
    return c_str_data_a(v);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/** Returns the length (in characters) of the VARIANT \c v, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
cs_size_t
c_str_len_a(
    VARIANT const& v
)
{
    if (v.vt == VT_NULL ||
        v.vt == VT_EMPTY)
    {
        return 0;
    }
    else
    {
        return STLSOFT_NS_QUAL(c_str_len_a)(c_str_data_a(v));
    }
}

/** Returns the length (in characters) of the VARIANT \c v, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
cs_size_t
c_str_len_w(
    VARIANT const& v
)
{
    if (v.vt == VT_BSTR)
    {
        return v.bstrVal != NULL ? ::SysStringLen(v.bstrVal) : 0;
    }
    else if (v.vt == VT_NULL ||
            v.vt == VT_EMPTY)
    {
        return 0;
    }
    else
    {
        return STLSOFT_NS_QUAL(c_str_len_w)(c_str_data_w(v));
    }
}

/** Returns the length (in characters) of the VARIANT \c v, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
inline
cs_size_t
c_str_len(
    VARIANT const& v
)
{
#ifdef UNICODE
    return c_str_len_w(v);
#else /* ? UNICODE */
    return c_str_len_a(v);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
c_str_VARIANT_proxy_a
c_str_ptr_a(
    VARIANT const& v
)
{
    return c_str_data_a(v);
}

inline
c_str_VARIANT_proxy_w
c_str_ptr_w(
    VARIANT const& v
)
{
    return c_str_data_w(v);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Returns the corresponding C-string pointer of the VARIANT \c v
 *
 * \ingroup group__concept__Shim__string_access
 *
 */
#ifdef UNICODE
inline
c_str_VARIANT_proxy_w
c_str_ptr(
    VARIANT const& v
)
#else /* ? UNICODE */
inline
c_str_VARIANT_proxy_a
c_str_ptr(
    VARIANT const& v
)
#endif /* UNICODE */
{
#ifdef UNICODE
    return c_str_ptr_w(v);
#else /* ? UNICODE */
    return c_str_ptr_a(v);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
c_str_null_VARIANT_proxy_a
c_str_ptr_null_a(
    VARIANT const& v
)
{
    VARIANT vs;

    ::VariantInit(&vs);

    ximpl_comstl_shims_access_string_variant_::prepare_VARIANT_copy_or_throw(&vs, v);

    return c_str_null_VARIANT_proxy_a(vs.bstrVal, v.vt);
}

inline
c_str_null_VARIANT_proxy_w
c_str_ptr_null_w(
    VARIANT const& v
)
{
    VARIANT vs;

    ::VariantInit(&vs);

    ximpl_comstl_shims_access_string_variant_::prepare_VARIANT_copy_or_throw(&vs, v);

    return c_str_null_VARIANT_proxy_w(vs.bstrVal, v.vt);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Returns the corresponding ANSI C-string pointer of the VARIANT \c v, or a null pointer
 *
 * \ingroup group__concept__Shim__string_access
 *
 */

#ifdef UNICODE
inline
c_str_null_VARIANT_proxy_w
c_str_ptr_null(
    VARIANT const& v
)
#else /* ? UNICODE */
inline
c_str_null_VARIANT_proxy_a
c_str_ptr_null(
    VARIANT const& v
)
#endif /* UNICODE */
{
#ifdef UNICODE
    return c_str_ptr_null_w(v);
#else /* ? UNICODE */
    return c_str_ptr_null_a(v);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace stlsoft::comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef COMSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::comstl::c_str_data_a;
using ::comstl::c_str_data_w;
using ::comstl::c_str_data;

using ::comstl::c_str_len_a;
using ::comstl::c_str_len_w;
using ::comstl::c_str_len;

using ::comstl::c_str_ptr_a;
using ::comstl::c_str_ptr_w;
using ::comstl::c_str_ptr;

using ::comstl::c_str_ptr_null_a;
using ::comstl::c_str_ptr_null_w;
using ::comstl::c_str_ptr_null;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * global namespace shims
 */

/* This defines stream inserter shim functions for the converters for use
 * with the Visual C++ <7.1 standard library.
 */

#if defined(STLSOFT_CF_STD_LIBRARY_IS_DINKUMWARE_VC) && \
    STLSOFT_CF_STD_LIBRARY_DINKUMWARE_VC_VERSION < STLSOFT_CF_DINKUMWARE_VC_VERSION_7_1

# include <iosfwd>
# include <iostream>

inline
STLSOFT_NS_QUAL_STD(basic_ostream)<char>&
operator <<(
    STLSOFT_NS_QUAL_STD(basic_ostream)<char>&       stm
,   COMSTL_NS_QUAL(c_str_VARIANT_proxy_a) const&    v
)
{
    return stm << static_cast<char const*>(v);
}

inline
STLSOFT_NS_QUAL_STD(basic_ostream)<wchar_t>&
operator <<(
    STLSOFT_NS_QUAL_STD(basic_ostream)<wchar_t>&    stm
,   COMSTL_NS_QUAL(c_str_VARIANT_proxy_w) const&    v
)
{
    return stm << static_cast<wchar_t const*>(v);
}

#endif /* library */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_VARIANT */

/* ///////////////////////////// end of file //////////////////////////// */

