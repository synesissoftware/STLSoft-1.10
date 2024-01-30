/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/functions.h (originally MWBase.h, ::SynesisWin)
 *
 * Purpose:     Window functions.
 *
 * Created:     7th May 2000
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2000-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/window/functions.h
 *
 * \brief [C, C++] Miscellaneous functions
 *   (\ref group__library__Windows_Window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_MAJOR     4
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_MINOR     0
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_REVISION  16
# define WINSTL_VER_WINSTL_WINDOW_H_FUNCTIONS_EDIT      82
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

#if defined(__cplusplus)
#ifndef WINSTL_INCL_WINSTL_CONVERSION_HPP_WINDOWS_TYPE_CONVERSIONS
# include <winstl/conversion/windows_type_conversions.hpp>
#endif /* !WINSTL_INCL_WINSTL_CONVERSION_HPP_WINDOWS_TYPE_CONVERSIONS */
#endif /* __cplusplus */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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
 * C functions
 */

#ifndef NOWINOFFSETS


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_INLINE
ws_sptrint_t
winstl_C_get_window_sptrint_(
    HWND    h
,   int     index
)
{
#if defined(WINSTL_OS_IS_WIN64) || \
    defined(_Wp64)
    return STLSOFT_NS_GLOBAL(GetWindowLongPtr)(h, index);
#else /* ? width */
    return STLSOFT_NS_GLOBAL(GetWindowLong)(h, index);
#endif /* width */
}
STLSOFT_INLINE
ws_sptrint_t
winstl_C_set_window_sptrint_(
    HWND            h
,   int             index
,   ws_sptrint_t    newData
)
{
#if defined(WINSTL_OS_IS_WIN64) || \
    defined(_Wp64)
    return STLSOFT_NS_GLOBAL(SetWindowLongPtr)(h, index, newData);
#else /* ? width */
    return STLSOFT_NS_GLOBAL(SetWindowLong)(h, index, newData);
#endif /* width */
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

STLSOFT_INLINE
ws_sptrint_t
winstl_C_GetStyle(
    HWND h
)
{
    return winstl_C_get_window_sptrint_(h, GWL_STYLE);
}

/** Gets the extended style of the window
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_sptrint_t
winstl_C_GetExStyle(
    HWND h
)
{
    return winstl_C_get_window_sptrint_(h, GWL_EXSTYLE);
}

/** Sets the style of the window
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_sptrint_t
winstl_C_SetStyle(
    HWND            h
,   ws_sptrint_t    s
)
{
    return winstl_C_set_window_sptrint_(h, GWL_STYLE, s);
}

/** Sets the extended style of the window
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_sptrint_t
winstl_C_SetExStyle(
    HWND            h
,   ws_sptrint_t    x
)
{
    return winstl_C_set_window_sptrint_(h, GWL_EXSTYLE, x);
}

/** Modifies the style of the window
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_sptrint_t
winstl_C_ModifyStyle(
    HWND            h
,   ws_sptrint_t    sRem
,   ws_sptrint_t    sAdd
)
{
    return winstl_C_SetStyle(h, (winstl_C_GetStyle(h) & ~sRem) | sAdd);
}

/** Modifies the extended style of the window
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_sptrint_t
winstl_C_ModifyExStyle(
    HWND            h
,   ws_sptrint_t    sRem
,   ws_sptrint_t    sAdd
)
{
    return winstl_C_SetExStyle(h, (winstl_C_GetExStyle(h) & ~sRem) | sAdd);
}

#endif /* !NOWINOFFSETS */


/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_int_t
winstl_C_IsWindowClassA(
    HWND                hwnd
,   ws_char_a_t const*  name
)
{
    ws_char_a_t szName[256];

    WINSTL_ASSERT(NULL != hwnd);
    WINSTL_ASSERT(NULL != name);

    stlsoft_static_cast(void, STLSOFT_NS_GLOBAL(GetClassNameA)(hwnd, szName, STLSOFT_NUM_ELEMENTS(szName)));

    return 0 == STLSOFT_API_EXTERNAL_string_stricmp(szName, name);
}

/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_int_t
winstl_C_IsWindowClassW(
    HWND                hwnd
,   ws_char_w_t const*  name
)
{
    ws_char_w_t szName[256];

    WINSTL_ASSERT(NULL != hwnd);
    WINSTL_ASSERT(NULL != name);

    stlsoft_static_cast(void, STLSOFT_NS_GLOBAL(GetClassNameW)(hwnd, szName, STLSOFT_NUM_ELEMENTS(szName)));

    return 0 == STLSOFT_API_EXTERNAL_string_wcsicmp(szName, name);
}

#ifndef NOCTLMGR

/** Enables/disable a dialog item
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
void
winstl_C_EnableDlgItem(
    HWND    hwnd
,   int     id
,   BOOL    bEnable
)
{
    STLSOFT_NS_GLOBAL(EnableWindow)(STLSOFT_NS_GLOBAL(GetDlgItem)(hwnd, id), bEnable);
}

/** Elicits the enable status of a dialog item
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_int_t
winstl_C_IsDlgItemEnabled(
    HWND    hwnd
,   int     id
)
{
    return STLSOFT_NS_GLOBAL(IsWindowEnabled)(STLSOFT_NS_GLOBAL(GetDlgItem)(hwnd, id));
}

/** Gets the text length of a dialog item's window contents
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
ws_int_t
winstl_C_GetDlgItemTextLength(
    HWND    hwnd
,   int     id
)
{
    return STLSOFT_NS_GLOBAL(GetWindowTextLength)(STLSOFT_NS_GLOBAL(GetDlgItem)(hwnd, id));
}

#endif /* !NOCTLMGR */

#ifndef NOWINOFFSETS

/** Gets the HINSTANCE associated with a given window
 *
 * \ingroup group__library__Windows_Window
 */
STLSOFT_INLINE
HINSTANCE
winstl_C_GetWindowInstance(
    HWND hwnd
)
{
#if defined(WINSTL_OS_IS_WIN64) || \
    defined(_Wp64)
    const int index = GWLP_HINSTANCE;
#else /* ? width */
    const int index = GWL_HINSTANCE;
#endif /* width */

    /* When compiling for Win32 with -Wp64, the conversion that we've catered
     * for - by the use of winstl_C_get_window_sptrint_(), and by the above
     * discrimination - is mistakenly reported as a truncation, so we need to
     * suppress the warning nonetheless.
     */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    defined(_Wp64)
# pragma warning(push)
# pragma warning(disable : 4312)
#endif
    return stlsoft_reinterpret_cast(HINSTANCE, winstl_C_get_window_sptrint_(hwnd, index));
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    defined(_Wp64)
# pragma warning(pop)
#endif
}

#endif /* !NOWINOFFSETS */

/* /////////////////////////////////////////////////////////////////////////
 * obsolete symbols
 *
 * NOTE: these are only defined if:
 *
 * - we're generating documentation, or
 * - STLSOFT_OBSOLETE is specified, or
 * - it's STLSoft 1.9 (or earlier)
 */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION) || \
    defined(STLSOFT_OBSOLETE) || \
    _STLSOFT_VER < 0x010a0000

/** \def winstl__GetStyle
 *
 * \deprecated Use winstl_C_GetStyle
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_GetStyle, winstl__GetStyle)
# define winstl__GetStyle                                   winstl_C_GetStyle

/** \def winstl__GetExStyle
 *
 * \deprecated Use winstl_C_GetExStyle
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_GetExStyle, winstl__GetExStyle)
# define winstl__GetExStyle                                 winstl_C_GetExStyle

/** \def winstl__SetStyle
 *
 * \deprecated Use winstl_C_SetStyle
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_SetStyle, winstl__SetStyle)
# define winstl__SetStyle                                   winstl_C_SetStyle

/** \def winstl__SetExStyle
 *
 * \deprecated Use winstl_C_SetExStyle
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_SetExStyle, winstl__SetExStyle)
# define winstl__SetExStyle                                 winstl_C_SetExStyle

/** \def winstl__ModifyStyle
 *
 * \deprecated Use winstl_C_ModifyStyle
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_ModifyStyle, winstl__ModifyStyle)
# define winstl__ModifyStyle                                winstl_C_ModifyStyle

/** \def winstl__ModifyExStyle
 *
 * \deprecated Use winstl_C_ModifyExStyle
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_ModifyExStyle, winstl__ModifyExStyle)
# define winstl__ModifyExStyle                              winstl_C_ModifyExStyle

/** \def winstl__IsWindowClassA
 *
 * \deprecated Use winstl_C_IsWindowClassA
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_IsWindowClassA, winstl__IsWindowClassA)
# define winstl__IsWindowClassA                             winstl_C_IsWindowClassA

/** \def winstl__IsWindowClassW
 *
 * \deprecated Use winstl_C_IsWindowClassW
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_IsWindowClassW, winstl__IsWindowClassW)
# define winstl__IsWindowClassW                             winstl_C_IsWindowClassW

/** \def winstl__EnableDlgItem
 *
 * \deprecated Use winstl_C_EnableDlgItem
 */
STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_EnableDlgItem, winstl__EnableDlgItem)
# define winstl__EnableDlgItem                              winstl_C_EnableDlgItem

/** \def winstl__IsDlgItemEnabled
 *
 * \deprecated Use winstl_C_IsDlgItemEnabled
 */

STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_IsDlgItemEnabled, winstl__IsDlgItemEnabled)
# define winstl__IsDlgItemEnabled                           winstl_C_IsDlgItemEnabled

/** \def winstl__GetDlgItemTextLength
 *
 * \deprecated Use winstl_C_GetDlgItemTextLength
 */

STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_GetDlgItemTextLength, winstl__GetDlgItemTextLength)
# define winstl__GetDlgItemTextLength                       winstl_C_GetDlgItemTextLength

/** \def winstl__GetWindowInstance
 *
 * \deprecated Use winstl_C_GetWindowInstance
 */

STLSOFT_DECLARE_MACRO_DEPRECATION_IN_FAVOUR_OF(winstl_C_GetWindowInstance, winstl__GetWindowInstance)
# define winstl__GetWindowInstance                          winstl_C_GetWindowInstance

#endif /* obsolete || 1.9 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

# ifndef NOWINOFFSETS

/** Gets the style of the window
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_sptrint_t
GetStyle(
    HWND h
)
{
    return winstl_C_GetStyle(h);
}

/** Gets the extended style of the window
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_sptrint_t
GetExStyle(
    HWND h
)
{
    return winstl_C_GetExStyle(h);
}

/** Sets the style of the window
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_sptrint_t
SetStyle(
    HWND            h
,   ws_sptrint_t    s
)
{
    return winstl_C_SetStyle(h, s);
}

/** Sets the extended style of the window
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_sptrint_t
SetExStyle(
    HWND            h
,   ws_sptrint_t    x
)
{
    return winstl_C_SetExStyle(h, x);
}

/** Modifies the style of the window
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_sptrint_t
ModifyStyle(
    HWND            h
,   ws_sptrint_t    sRem
,   ws_sptrint_t    sAdd
)
{
    return winstl_C_ModifyStyle(h, sRem, sAdd);
}

/** Modifies the extended style of the window
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_sptrint_t
ModifyExStyle(
    HWND            h
,   ws_sptrint_t    sRem
,   ws_sptrint_t    sAdd
)
{
    return winstl_C_ModifyExStyle(h, sRem, sAdd);
}

# endif /* !NOWINOFFSETS */

/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_bool_t
IsWindowClass(
    HWND                hwnd
,   ws_char_a_t const*  name
)
{
    return BOOL2bool(winstl_C_IsWindowClassA(hwnd, name));
}

/** Tests whether the given window has the given window class
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_bool_t
IsWindowClass(
    HWND                hwnd
,   ws_char_w_t const*  name
)
{
    return BOOL2bool(winstl_C_IsWindowClassW(hwnd, name));
}

# ifndef NOCTLMGR

/** Enables/disable a dialog item
 *
 * \ingroup group__library__Windows_Window
 */
inline
void
EnableDlgItem(
    HWND        hwnd
,   int         id
,   ws_bool_t   bEnable
)
{
    winstl_C_EnableDlgItem(hwnd, id, bEnable);
}

/** Elicits the enable status of a dialog item
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_bool_t
IsDlgItemEnabled(
    HWND    hwnd
,   int     id
)
{
    return BOOL2bool(winstl_C_IsDlgItemEnabled(hwnd, id));
}

/** Gets the text length of a dialog item's window contents
 *
 * \ingroup group__library__Windows_Window
 */
inline
ws_int_t
GetDlgItemTextLength(
    HWND    hwnd
,   int     id
)
{
    return winstl_C_GetDlgItemTextLength(hwnd, id);
}

# endif /* !NOCTLMGR */

# ifndef NOWINOFFSETS

/** Gets the HINSTANCE associated with a given window
 *
 * \ingroup group__library__Windows_Window
 */
#ifdef GetWindowInstance
# undef GetWindowInstance
#endif /* GetWindowInstance */
inline
HINSTANCE
GetWindowInstance(
    HWND hwnd
)
{
    return winstl_C_GetWindowInstance(hwnd);
}

# endif /* !NOWINOFFSETS */

# ifndef NOWINMESSAGES

inline
HICON
set_window_icon(
    HWND    hwnd
,   int     iconType
,   HICON   hicon
)
{
    WINSTL_ASSERT(ICON_BIG == iconType || ICON_SMALL == iconType);

# if defined(STLSOFT_COMPILER_IS_BORLAND) && \
     __BORLANDC__ < 0x0564
    /* This is needed here to prevent the Borland compiler from confusing it with the winstl one! */
    using ::SendMessage;
# endif /* compiler */

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     defined(_Wp64) && \
     !defined(_WIN64)
#  pragma warning(push)
#  pragma warning(disable : 4244)
# endif /* VC++ + Win32 + _Wp32 */

    return LRESULT2HICON(::SendMessage(hwnd, WM_SETICON, static_cast<WPARAM>(iconType), HICON2LPARAM(hicon)));

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     defined(_Wp64) && \
     !defined(_WIN64)
#  pragma warning(pop)
# endif /* VC++ + Win32 + _Wp32 */
}

inline
HICON
set_window_icon(
    HWND        hwnd
,   int         iconType
,   HINSTANCE   hinst
,   LPCTSTR     iconName
)
{
    return set_window_icon(hwnd, iconType, ::LoadIcon(hinst, iconName));
}

inline
HICON
set_window_icon(
    HWND        hwnd
,   int         iconType
,   HINSTANCE   hinst
,   int         iconId
)
{
    return set_window_icon(hwnd, iconType, ::LoadIcon(hinst, MAKEINTRESOURCE(iconId)));
}

# endif /* !NOWINMESSAGES */

/* ////////////////////////////////////////////////////////////////////// */

# ifndef NOCTLMGR

#  if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
#   define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1
#  elif defined(STLSOFT_COMPILER_IS_BORLAND) /* && \
        __BORLANDC__ < 0x0582 */
#   define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3
#  elif defined(STLSOFT_COMPILER_IS_MSVC)
#   if _MSC_VER > 1200
#    define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3
#   else /* ? compiler */
#    define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2
#   endif /* compiler */
#  else /* ? compiler */
#   define WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1
#  endif /* compiler */

/** Finds the first descendant window with the given id
 *
 * \ingroup group__library__Windows_Window
 *
 * \param hwndParent The window whose children will be searched
 * \param id The dialog id to search for
 *
 * \return Either the window handle of the first child window (or
 * the parent itself) that matches the id, or NULL if no windows
 * match
 *
 * \note Because several levels of windows may be searched, it's
 * possible for more than one child window to have the given id.
 * This function will return only the first one found. Which one
 * is determined by the internals of the EnumChildWindows() API
 * function.
 *
 * \note \c hwndParent is included in the search, so if it has the
 * given id, it will be returned
 */
#  if defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1) || \
      defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2)

#  if defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2)
/* declare the template function */
template <int N>
inline
HWND
FindFirstChildById_N(
    HWND    hwndParent
,   int     id
);
#   endif /* WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2 */

inline
HWND
FindFirstChildById(
    HWND    hwndParent
,   int     id
)
#  if defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2)
{
    return FindFirstChildById_N<1>(hwndParent, id);
}

template <int N>
inline
HWND
FindFirstChildById_N(
    HWND    hwndParent
,   int     id
)
#   endif /* WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2 */
{
    if (::GetDlgCtrlID(hwndParent) == id)
    {
        return hwndParent;
    }
    else
    {
        class ChildFind
        {
        public:
            ss_explicit_k ChildFind(HWND hwndParent, int id)
                : m_hwndChild(NULL)
                , m_id(id)
            {
#ifdef STRICT
                ::EnumChildWindows(hwndParent, EnumProc, reinterpret_cast<LPARAM>(this));
#else
                ::EnumChildWindows(hwndParent, reinterpret_cast<WNDENUMPROC>(EnumProc), reinterpret_cast<LPARAM>(this));
#endif
            }

        public:
            operator HWND() const
            {
                return m_hwndChild;
            }

        private:
            static BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam)
            {
                ChildFind &find = *reinterpret_cast<ChildFind*>(lParam);

                return (::GetDlgCtrlID(hwnd) == find.m_id)
                                    ? (find.m_hwndChild = hwnd, false)
                                    : true;
            }

        private:
            HWND        m_hwndChild;
            int const   m_id;

        } find(hwndParent, id);

        return find;
    }
}

#elif defined(WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3)

struct FindFirstChildById_class
{
    class ChildFind
    {
    public:
        ss_explicit_k ChildFind(HWND hwndParent, int id)
            : m_hwndChild(NULL)
            , m_id(id)
        {
#ifdef STRICT
            ::EnumChildWindows(hwndParent, EnumProc, reinterpret_cast<LPARAM>(this));
#else
            ::EnumChildWindows(hwndParent, reinterpret_cast<WNDENUMPROC>(EnumProc), reinterpret_cast<LPARAM>(this));
#endif
        }

    public:
        operator HWND() const
        {
            return m_hwndChild;
        }

    private:
        static BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam)
        {
            ChildFind &find = *reinterpret_cast<ChildFind*>(lParam);

            return (::GetDlgCtrlID(hwnd) == find.m_id)
                                ? (find.m_hwndChild = hwnd, false)
                                : true;
        }

    private:
        HWND        m_hwndChild;
        int const   m_id;

    private:
        ChildFind& operator =(ChildFind const&);
    };

    static HWND FindFirstChildById_N(HWND hwndParent, int id)
    {
        if (::GetDlgCtrlID(hwndParent) == id)
        {
            return hwndParent;
        }
        else
        {
            ChildFind find(hwndParent, id);

            return find;
        }
    }
};

inline
HWND
FindFirstChildById(
    HWND    hwndParent
,   int     id
)
{
    return FindFirstChildById_class/* <int> */::FindFirstChildById_N(hwndParent, id);
}

#  else /* ? WINSTL_FINDFIRSTCHILDBYID_SLF_FORM?? */
#   error None of WINSTL_FINDFIRSTCHILDBYID_SLF_FORM1, WINSTL_FINDFIRSTCHILDBYID_SLF_FORM2 or WINSTL_FINDFIRSTCHILDBYID_SLF_FORM3 defined
#  endif /* WINSTL_FINDFIRSTCHILDBYID_SLF_FORM?? */

# endif /* !NOCTLMGR */

#endif /* __cplusplus */

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

#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

