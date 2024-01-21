/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/path_classify_functions.h
 *
 * Purpose:     Path classification functions
 *
 * Created:     21st December 2020
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


/** \file unixstl/filesystem/path_classify_functions.h
 *
 * \brief [C, C++] Path classification functions
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_MAJOR     1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_MINOR     0
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_REVISION  6
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS_EDIT      7
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
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

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

enum unixstl_C_path_classification_t
{
        UNIXSTL_C_PathType_MIN_VALUE            =   -10000

    ,   UNIXSTL_C_PathType_InvalidSlashRuns     =   -3
    ,   UNIXSTL_C_PathType_InvalidChars         =   -2
    ,   UNIXSTL_C_PathType_Invalid              =   -1
    ,   UNIXSTL_C_PathType_Unknown              =   0
    ,   UNIXSTL_C_PathType_Empty
    ,   UNIXSTL_C_PathType_Relative
    ,   UNIXSTL_C_PathType_SlashRooted
    ,   UNIXSTL_C_PathType_reserved_1
    ,   UNIXSTL_C_PathType_reserved_2
    ,   UNIXSTL_C_PathType_reserved_3
    ,   UNIXSTL_C_PathType_reserved_4
    ,   UNIXSTL_C_PathType_HomeRooted

    /* no enumerator to be placed AFTER this one */
    ,   UNIXSTL_C_PathType_MAX_VALUE
};
#ifndef __cplusplus
typedef enum unixstl_C_path_classification_t                unixstl_C_path_classification_t;
#endif /* !__cplusplus */

struct unixstl_C_path_classification_results_m_t
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
typedef struct unixstl_C_path_classification_results_m_t    unixstl_C_path_classification_results_m_t;
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#define UNIXSTL_PATH_CLASSIFY_F_NONE                        (0)

#define UNIXSTL_PATH_CLASSIFY_F_IGNORESLASHRUNS             (0x00000001)
#define UNIXSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARS          (0x00000002)
#define UNIXSTL_PATH_CLASSIFY_F_RECOGNISETILDEHOME          (0x00000004)

#define UNIXSTL_PATH_CLASSIFY_F_MASK_                       (0x00000007)

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_               char
# define UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_ \
                                                            stlsoft_C_string_slice_m_t
# define unixstl_C_path_classification_results_X_t_         unixstl_C_path_classification_results_m_t
# define UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_  stlsoft_C_strnchr
# define UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_ \
                                                            stlsoft_C_strnpbrkn
# define UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_ stlsoft_C_strnstrn
# define unixstl_C_path_classify_alwaysInvalidChars_X_      unixstl_C_path_classify_alwaysInvalidChars_m_
# define unixstl_C_path_classify_root_X_                    unixstl_C_path_classify_root_m_
# define unixstl_C_path_classify_impl_X_                    unixstl_C_path_classify_impl_m_
# include <unixstl/filesystem/path_functions/classify_functions_X_.h>
# undef UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_
# undef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_
# undef unixstl_C_path_classification_results_X_t_
# undef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_
# undef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_
# undef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_
# undef unixstl_C_path_classify_alwaysInvalidChars_X_
# undef unixstl_C_path_classify_root_X_
# undef unixstl_C_path_classify_impl_X_

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

STLSOFT_INLINE
unixstl_C_path_classification_t
unixstl_C_path_classify_m(
    char const*                                 s
,   size_t                                      cch
,   int                                         parseFlags
,   unixstl_C_path_classification_results_m_t*   results
)
{
    unixstl_C_path_classification_results_m_t dummy;

    if (ss_nullptr_k == results)
    {
        results = &dummy;
    }

    return unixstl_C_path_classify_impl_m_(
        s, cch
    ,   parseFlags
    ,   results
    );
}

STLSOFT_INLINE
STLSOFT_NS_QUAL(ss_truthy_t)
unixstl_C_path_is_rooted(
    unixstl_C_path_classification_t pc
)
{
    switch (pc)
    {
    case UNIXSTL_C_PathType_SlashRooted:
    case UNIXSTL_C_PathType_HomeRooted:

        return 1;
    default:

        return 0;
    }
}

#ifdef __cplusplus

inline
unixstl_C_path_classification_t
unixstl_C_path_classify(
    char const*                                 s
,   size_t                                      cch
,   int                                         parseFlags
,   unixstl_C_path_classification_results_m_t*   results
)
{
    return unixstl_C_path_classify_m(s, cch, parseFlags, results);
}
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */

#ifndef __cplusplus
# error
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * C++ types
 */

typedef unixstl_C_path_classification_t                     path_classification_t;
typedef unixstl_C_path_classification_results_m_t           path_classification_results_m_t;

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
    UNIXSTL_ASSERT(0 != path.size() || ss_nullptr_k != path.data());

    return unixstl_C_path_classify(path.data(), path.size(), parseFlags, results);
}

inline
bool
path_is_rooted(
    path_classification_t   pc
)
{
    return 0 != unixstl_C_path_is_rooted(pc);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

