/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path_classify_functions.h
 *
 * Purpose:     Path classification functions
 *
 * Created:     28th November 2020
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020-2024, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/filesystem/path_classify_functions.h
 *
 * \brief [C, C++] Path classification functions
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_MINOR       3
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_REVISION    3
# define WINSTL_VER_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_EDIT        11
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR
# include <stlsoft/string/c_string/strnchr.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR */
#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNPBRKN
# include <stlsoft/string/c_string/strnpbrkn.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNPBRKN */
#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNSTRN
# include <stlsoft/string/c_string/strnstrn.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNSTRN */
#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
# include <stlsoft/string/string_slice.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */

#ifndef STLSOFT_INCL_H_CTYPE
# define STLSOFT_INCL_H_CTYPE
# include <ctype.h>
#endif /* !STLSOFT_INCL_H_CTYPE */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

enum winstl_C_path_classification_t
{
        WinSTL_C_PathType_MIN_VALUE             =   -10000

    ,   WinSTL_C_PathType_InvalidSlashRuns      =   -3
    ,   WinSTL_C_PathType_InvalidChars          =   -2
    ,   WinSTL_C_PathType_Invalid               =   -1
    ,   WinSTL_C_PathType_Unknown               =   0
    ,   WinSTL_C_PathType_Empty
    ,   WinSTL_C_PathType_Relative
    ,   WinSTL_C_PathType_SlashRooted
    ,   WinSTL_C_PathType_DriveLetterRelative
    ,   WinSTL_C_PathType_DriveLetterRooted
    ,   WinSTL_C_PathType_UncIncomplete
    ,   WinSTL_C_PathType_UncRooted
    ,   WinSTL_C_PathType_HomeRooted

    /* no enumerator to be placed AFTER this one */
    ,   WinSTL_C_PathType_MAX_VALUE
};
#ifndef __cplusplus
typedef enum winstl_C_path_classification_t                 winstl_C_path_classification_t;
#endif /* !__cplusplus */

struct winstl_C_path_classification_results_m_t
{
    stlsoft_C_string_slice_m_t      input;
    stlsoft_C_string_slice_m_t      fullPath;               /*!< UNUSED. A future version will allow make-absolute and make-canonical functionality */
    stlsoft_C_string_slice_m_t      prefix;                 /*!< the prefix, if any, before the root, e.g. "\\?\", "\\?\UNC\" */
    stlsoft_C_string_slice_m_t      location;               /*!< the entire path excepting the file */
    stlsoft_C_string_slice_m_t      root;                   /*!< root of path, which may be "", or "C:", or "\\?\UNC\server-name\share-name" */
    stlsoft_C_string_slice_m_t      directory;              /*!< the entire directory, beginning with the first character after the root until the first character before the file */
    size_t                          numDirectoryParts;
    size_t                          numDotsDirectoryParts;
    stlsoft_C_string_slice_m_t      entry;
    stlsoft_C_string_slice_m_t      stem;
    stlsoft_C_string_slice_m_t      extension;
    stlsoft_C_string_slice_m_t      firstInvalid;           /*!< the first invalid character, if any */
};
#ifndef __cplusplus
typedef struct winstl_C_path_classification_results_m_t     winstl_C_path_classification_results_m_t;
#endif /* !__cplusplus */

struct winstl_C_path_classification_results_w_t
{
    stlsoft_C_string_slice_w_t      input;
    stlsoft_C_string_slice_w_t      fullPath;               /*!< UNUSED. A future version will allow make-absolute and make-canonical functionality */
    stlsoft_C_string_slice_w_t      prefix;                 /*!< the prefix, if any, before the root, e.g. "\\?\", "\\?\UNC\" */
    stlsoft_C_string_slice_w_t      location;               /*!< the entire path excepting the file */
    stlsoft_C_string_slice_w_t      root;                   /*!< root of path, which may be "", or "C:", or "\\?\UNC\server-name\share-name" */
    stlsoft_C_string_slice_w_t      directory;              /*!< the entire directory, beginning with the first character after the root until the first character before the file */
    size_t                          numDirectoryParts;
    size_t                          numDotsDirectoryParts;
    stlsoft_C_string_slice_w_t      entry;
    stlsoft_C_string_slice_w_t      stem;
    stlsoft_C_string_slice_w_t      extension;
    stlsoft_C_string_slice_w_t      firstInvalid;           /*!< the first invalid character, if any */
};
#ifndef __cplusplus
typedef struct winstl_C_path_classification_results_w_t     winstl_C_path_classification_results_w_t;
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#define WINSTL_PATH_CLASSIFY_F_NONE                         (0)

#define WINSTL_PATH_CLASSIFY_F_IGNORESLASHRUNS              (0x00000001)
#define WINSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARS           (0x00000002)
#define WINSTL_PATH_CLASSIFY_F_RECOGNISETILDEHOME           (0x00000004)
#define WINSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARSINLONGPATH (0x00000008)

#define WINSTL_PATH_CLASSIFY_F_MASK_                        (0x0000000f)

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define WINSTL_C_PATH_CLASSIFY_IMPL_char_t_                char
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_ \
                                                            stlsoft_C_string_slice_m_t
# define winstl_C_path_classification_results_X_t_          winstl_C_path_classification_results_m_t
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_isalpha_X_   STLSOFT_NS_GLOBAL(isalpha)
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_   stlsoft_C_strnchr
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_ stlsoft_C_strnpbrkn
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_  stlsoft_C_strnstrn
# define winstl_C_path_classify_alwaysInvalidChars_X_       winstl_C_path_classify_alwaysInvalidChars_m_
# define winstl_C_path_classify_find_UNC_server_and_share_X_ \
                                                            winstl_C_path_classify_find_UNC_server_and_share_m_
# define winstl_C_path_classify_root_X_                     winstl_C_path_classify_root_m_
# define winstl_C_path_classify_impl_X_                     winstl_C_path_classify_impl_m_
# define winstl_C_path_classify_root_impl_X_                winstl_C_path_classify_root_impl_m_
# include <winstl/filesystem/path_functions/classify_functions_X_.h>
# undef WINSTL_C_PATH_CLASSIFY_IMPL_char_t_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_
# undef winstl_C_path_classification_results_X_t_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_isalpha_X_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_
# undef winstl_C_path_classify_alwaysInvalidChars_X_
# undef winstl_C_path_classify_find_UNC_server_and_share_X_
# undef winstl_C_path_classify_root_X_
# undef winstl_C_path_classify_impl_X_
# undef winstl_C_path_classify_root_impl_X_

# define WINSTL_C_PATH_CLASSIFY_IMPL_char_t_                wchar_t
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_ \
                                                            stlsoft_C_string_slice_w_t
# define winstl_C_path_classification_results_X_t_          winstl_C_path_classification_results_w_t
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_isalpha_X_   STLSOFT_NS_GLOBAL(iswalpha)
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_   stlsoft_C_wcsnchr
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_ stlsoft_C_wcsnpbrkn
# define WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_  stlsoft_C_wcsnstrn
# define winstl_C_path_classify_alwaysInvalidChars_X_       winstl_C_path_classify_alwaysInvalidChars_w_
# define winstl_C_path_classify_find_UNC_server_and_share_X_ \
                                                            winstl_C_path_classify_find_UNC_server_and_share_w_
# define winstl_C_path_classify_root_X_                     winstl_C_path_classify_root_w_
# define winstl_C_path_classify_impl_X_                     winstl_C_path_classify_impl_w_
# define winstl_C_path_classify_root_impl_X_                winstl_C_path_classify_root_impl_w_
# include <winstl/filesystem/path_functions/classify_functions_X_.h>
# undef WINSTL_C_PATH_CLASSIFY_IMPL_char_t_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_
# undef winstl_C_path_classification_results_X_t_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_isalpha_X_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_
# undef WINSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_
# undef winstl_C_path_classify_alwaysInvalidChars_X_
# undef winstl_C_path_classify_find_UNC_server_and_share_X_
# undef winstl_C_path_classify_root_X_
# undef winstl_C_path_classify_impl_X_
# undef winstl_C_path_classify_root_impl_X_

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

STLSOFT_INLINE
winstl_C_path_classification_t
winstl_C_path_classify_m(
    char const*                                 s
,   size_t                                      cch
,   int                                         parseFlags
,   winstl_C_path_classification_results_m_t*   results
)
{
    winstl_C_path_classification_results_m_t dummy;

    if (ss_nullptr_k == results)
    {
        results = &dummy;
    }

    return winstl_C_path_classify_impl_m_(
        s, cch
    ,   parseFlags
    ,   results
    );
}

STLSOFT_INLINE
winstl_C_path_classification_t
winstl_C_path_classify_w(
    wchar_t const*                              s
,   size_t                                      cch
,   int                                         parseFlags
,   winstl_C_path_classification_results_w_t*   results
)
{
    winstl_C_path_classification_results_w_t dummy;

    if (ss_nullptr_k == results)
    {
        results = &dummy;
    }

    return winstl_C_path_classify_impl_w_(
        s, cch
    ,   parseFlags
    ,   results
    );
}

STLSOFT_INLINE
winstl_C_path_classification_t
winstl_C_path_classify_root_m(
    char const*                                 s
,   size_t                                      cch
,   int                                         parseFlags
,   stlsoft_C_string_slice_m_t*                 root
)
{
    stlsoft_C_string_slice_m_t  dummy;

    if (ss_nullptr_k == root)
    {
        root = &dummy;
    }

    return winstl_C_path_classify_root_impl_m_(
        s, cch
    ,   parseFlags
    ,   root
    );
}

STLSOFT_INLINE
winstl_C_path_classification_t
winstl_C_path_classify_root_w(
    wchar_t const*                              s
,   size_t                                      cch
,   int                                         parseFlags
,   stlsoft_C_string_slice_w_t*                 root
)
{
    stlsoft_C_string_slice_w_t  dummy;

    if (ss_nullptr_k == root)
    {
        root = &dummy;
    }

    return winstl_C_path_classify_root_impl_w_(
        s, cch
    ,   parseFlags
    ,   root
    );
}

STLSOFT_INLINE
STLSOFT_NS_QUAL(ss_truthy_t)
winstl_C_path_is_rooted(
    winstl_C_path_classification_t  pc
)
{
    switch (pc)
    {
    case WinSTL_C_PathType_SlashRooted:
    case WinSTL_C_PathType_DriveLetterRooted:
    case WinSTL_C_PathType_UncRooted:
    case WinSTL_C_PathType_HomeRooted:

        return true;
    default:

        return false;
    }
}

STLSOFT_INLINE
STLSOFT_NS_QUAL(ss_truthy_t)
winstl_C_path_is_absolute(
    winstl_C_path_classification_t  pc
)
{
    switch (pc)
    {
    case WinSTL_C_PathType_DriveLetterRooted:
    case WinSTL_C_PathType_UncRooted:
    case WinSTL_C_PathType_HomeRooted:

        return true;
    default:

        return false;
    }
}

#ifdef __cplusplus

inline
winstl_C_path_classification_t
winstl_C_path_classify(
    char const*                                 s
,   size_t                                      cch
,   int                                         parseFlags
,   winstl_C_path_classification_results_m_t*   results
)
{
    return winstl_C_path_classify_m(s, cch, parseFlags, results);
}

inline
winstl_C_path_classification_t
winstl_C_path_classify(
    wchar_t const*                              s
,   size_t                                      cch
,   int                                         parseFlags
,   winstl_C_path_classification_results_w_t*   results
)
{
    return winstl_C_path_classify_w(s, cch, parseFlags, results);
}

inline
winstl_C_path_classification_t
winstl_C_path_classify_root(
    char const*                                 s
,   size_t                                      cch
,   int                                         parseFlags
,   stlsoft_C_string_slice_m_t*                 root
)
{
    return winstl_C_path_classify_root_m(s, cch, parseFlags, root);
}

inline
winstl_C_path_classification_t
winstl_C_path_classify_root(
    wchar_t const*                              s
,   size_t                                      cch
,   int                                         parseFlags
,   stlsoft_C_string_slice_w_t*                 root
)
{
    return winstl_C_path_classify_root_w(s, cch, parseFlags, root);
}
#endif /* __cplusplus */

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

#ifndef __cplusplus
# error
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * C++ types
 */

typedef winstl_C_path_classification_t                      path_classification_t;
typedef winstl_C_path_classification_results_m_t            path_classification_results_m_t;
typedef winstl_C_path_classification_results_w_t            path_classification_results_w_t;

/* /////////////////////////////////////////////////////////////////////////
 * C++ API functions
 */

/**
 *
 * \param path
 *
 * \note The function does NOT use string-access shims to elicit
 *   from \c path the C-style string pointer and length, because the API
 *   returns results in slices, whose contents could be invalidated. Instead
 *   the function assumes that \c path is of a notional type that provides
 *   the methods <code>data()</code> and <code>size()</code>
 */
template<
    ss_typename_param_k T_string
,   ss_typename_param_k T_results
>
path_classification_t
path_classify(
    T_string const&         path
,   int                     parseFlags
,   T_results*              results
)
{
    WINSTL_ASSERT(0 != path.size() || ss_nullptr_k != path.data());

    return winstl_C_path_classify(path.data(), path.size(), parseFlags, results);
}

template<
    ss_typename_param_k T_string
,   ss_typename_param_k T_results
>
path_classification_t
path_classify_root(
    T_string const&         path
,   int                     parseFlags
,   T_results*              results
)
{
    WINSTL_ASSERT(0 != path.size() || ss_nullptr_k != path.data());

    return winstl_C_path_classify_root(path.data(), path.size(), parseFlags, results);
}

inline
bool
path_is_rooted(
    path_classification_t   pc
)
{
    return 0 != winstl_C_path_is_rooted(pc);
}

inline
bool
path_is_absolute(
    path_classification_t   pc
)
{
    return 0 != winstl_C_path_is_absolute(pc);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

