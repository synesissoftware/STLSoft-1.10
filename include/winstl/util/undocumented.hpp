/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/util/undocumented.hpp (originally MCPriv.h, ::SynesisDev)
 *
 * Purpose:     Miscellaneous undocumented features.
 *
 * Created:     20th October 1994
 * Updated:     29th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1994-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/util/undocumented.hpp
 *
 * \brief [C++] Miscellaneous undocumented features
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef WINSTL_INCL_WINSTL_UTIL_HPP_UNDOCUMENTED
#define WINSTL_INCL_WINSTL_UTIL_HPP_UNDOCUMENTED

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#define WINSTL_VER_WINSTL_UTIL_HPP_UNDOCUMENTED_MAJOR       4
#define WINSTL_VER_WINSTL_UTIL_HPP_UNDOCUMENTED_MINOR       0
#define WINSTL_VER_WINSTL_UTIL_HPP_UNDOCUMENTED_REVISION    5
#define WINSTL_VER_WINSTL_UTIL_HPP_UNDOCUMENTED_EDIT        50
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
 * functions
 */

/** get_undoc_clipboard_fmt__
 *
 * \ingroup group__library__Utility
 *
 * \note This has to be implemented as a class, because the function version
 * does not correctly work in respect of the static. Specifically, it does not
 * distinguish between different values of the specialising constant, so that,
 * say, get_undoc_clipboard_fmt__<1>(. . .) will cause fmt to be correctly
 * initialised, but get_undoc_clipboard_fmt__<2>(. . .) will use the same value.
 * This behaviour is demonstrated on VC5 & VC6, but works fine with Intel C++
 * 6 and 7, and VC7.
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
    (   defined(STLSOFT_COMPILER_IS_DMC) && \
        __DMC__ >= 0x829) || \
    defined(STLSOFT_COMPILER_IS_GCC) || \
    defined(STLSOFT_COMPILER_IS_INTEL) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER >= 1300)

template <int N>
inline UINT get_undoc_clipboard_fmt__(LPCTSTR lpszFormat)
{
    static UINT fmt = ::RegisterClipboardFormat(lpszFormat);

    return fmt;
}

#else /* ? compiler */

template <int N>
struct get_undoc_clipboard_fmt__
{
public:
    ss_explicit_k get_undoc_clipboard_fmt__(LPCTSTR lpszFormat)
#ifdef STLSOFT_COMPILER_IS_DMC /* DMC++ pre 8.29 cannot work with the static get_() method */
        : m_fmt(register_(lpszFormat))
#else /* ? compiler */
        : m_fmt(get_(lpszFormat))
#endif /* compiler */
    {}

    operator UINT () const
    {
        return m_fmt;
    }

private:
    static UINT register_(LPCTSTR lpszFormat)
    {
        return ::RegisterClipboardFormat(lpszFormat);
    }

    static UINT get_(LPCTSTR lpszFormat)
    {
        static UINT fmt = register_(lpszFormat);

        return fmt;
    }

private:
    const UINT  m_fmt;
};

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

/* Messages */

#ifndef WM_CONTEXTMENU
# define WM_CONTEXTMENU                                     (0x007B)
#endif /* !WM_CONTEXTMENU */

/* Clipboard formats */

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("These should go into winstl_shell(_functions).h or something"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

#ifndef CF_FILENAMEA
# define CF_FILENAMEA                                       WINSTL_NS_QUAL(get_undoc_clipboard_fmt__)<1>(TEXT("FileName"))
#endif /* !CF_FILENAMEA */

#ifndef CF_FILENAMEW
# define CF_FILENAMEW                                       WINSTL_NS_QUAL(get_undoc_clipboard_fmt__)<2>(TEXT("FileNameW"))
#endif /* !CF_FILENAMEW */

#ifndef CF_FILENAME
# ifdef UNICODE
#  define CF_FILENAME                                       CF_FILENAMEW
# else /* ? UNICODE */
#  define CF_FILENAME                                       CF_FILENAMEA
# endif /* UNICODE */
#endif /* !CF_FILENAME */

#ifndef CF_IDLIST
# define CF_IDLIST                                          WINSTL_NS_QUAL(get_undoc_clipboard_fmt__)<3>(TEXT("Shell IDList Array"))
#endif /* !CF_IDLIST */

#ifndef CF_NETRESOURCE
# define CF_NETRESOURCE                                     WINSTL_NS_QUAL(get_undoc_clipboard_fmt__)<4>(TEXT("Net Resource"))
#endif /* !CF_NETRESOURCE */

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

#endif /* !WINSTL_INCL_WINSTL_UTIL_HPP_UNDOCUMENTED */

/* ///////////////////////////// end of file //////////////////////////// */

