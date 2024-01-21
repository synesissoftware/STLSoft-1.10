/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/directory_functions.hpp (originally MLFlMan.h, ::SynesisStd)
 *
 * Purpose:     Functions for manipulating directories.
 *
 * Created:     7th February 2002
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


/** \file winstl/filesystem/directory_functions.hpp
 *
 * \brief [C++] Functions for manipulating directories
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_MAJOR     5
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_MINOR     1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_REVISION  5
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_EDIT      72
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

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifdef _ATL_MIN_CRT
# ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
#  include <stlsoft/memory/util/allocator_selector.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#else /* ? _ATL_MIN_CRT */
# ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
#  include <winstl/memory/processheap_allocator.hpp>
# endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#endif /* _ATL_MIN_CRT */

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
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_OPEN_WORKER_NS_(ximpl_winstl_directory_functions_)

template<
    ss_typename_param_k T_character
>
struct directory_recurse_traits_t
{
public: // types
    typedef T_character                                     char_type;
    typedef filesystem_traits<
        char_type
    >                                                       fs_traits_type;
#ifdef _ATL_MIN_CRT

    typedef ss_typename_type_k STLSOFT_NS_QUAL(allocator_selector)<
        char_type
    >::allocator_type                                       allocator_type;
#else /* ? _ATL_MIN_CRT */

    typedef processheap_allocator<
        char_type
    >                                                       allocator_type;
#endif /* _ATL_MIN_CRT */
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_type
    ,   1 + WINSTL_CONST_MAX_PATH
    ,   allocator_type
    >                                                       buffer_type;
};

template<
    ss_typename_param_k T_character
>
inline
ws_bool_t
create_directory_recurse_impl(
    T_character const*      dir
,   LPSECURITY_ATTRIBUTES   lpsa
)
{
    typedef directory_recurse_traits_t<T_character>         dr_traits_t;
    typedef ss_typename_type_k dr_traits_t::buffer_type     buffer_t;
    typedef ss_typename_type_k dr_traits_t::char_type       char_t;
    typedef ss_typename_type_k dr_traits_t::fs_traits_type  fs_traits_t;

    if (NULL == dir ||
        '\0' == *dir)
    {
        fs_traits_t::set_last_error(ERROR_DIRECTORY);

        return false;
    }
    else
    {
        if (fs_traits_t::file_exists(dir))
        {
            if (fs_traits_t::is_directory(dir))
            {
                fs_traits_t::set_last_error(ERROR_ALREADY_EXISTS);

                return true;
            }
            else
            {
                fs_traits_t::set_last_error(ERROR_FILE_EXISTS);

                return false;
            }
        }
        else
        {
            // May be being compiled absent exception support, so need to check the
            // file path buffers. (This _could_ be done with a compile-time #ifdef,
            // but it's best not, since some translators support exceptions but yet
            // don't throw on mem exhaustion, and in any case a user could change
            // ::new)

            ws_size_t const dirLen = fs_traits_t::str_len(dir);
            buffer_t        sz(dirLen + 1);

            if (0 == sz.size())
            {
                return false;
            }

            fs_traits_t::char_copy(&sz[0] + 0, dir, dirLen);
            sz[dirLen] = '\0';
            fs_traits_t::remove_dir_end(sz);

            if (fs_traits_t::create_directory(sz.data(), lpsa) ||
                ERROR_ALREADY_EXISTS == fs_traits_t::get_last_error())
            {
                return true;
            }
            else
            {
                // Trim previous directory

                ws_size_t const szLen = fs_traits_t::str_len(dir);
                buffer_t        szParent(szLen + 1);

                if (0 == szParent.size())
                {
                    return false;
                }

                fs_traits_t::char_copy(&szParent[0], sz.data(), szLen);
                szParent[szLen] = '\0';

                char_t const* const pszSlash = fs_traits_t::find_last_path_name_separator(szParent.data());
                if (NULL == pszSlash)
                {
                    fs_traits_t::set_last_error(ERROR_DIRECTORY);

                    return false;
                }
                else
                {
                    *const_cast<char_t*>(pszSlash) = '\0';

                    // If second character is ':', and total lengths is less than four,
                    // or the recurse create fails, then return false;
                    if ((   szParent[1] == ':' &&
                            (fs_traits_t::set_last_error(ERROR_CANNOT_MAKE), fs_traits_t::str_len(szParent.data()) < 4)) ||
                        !create_directory_recurse_impl(szParent.data(), lpsa))
                    {
                        return false;
                    }
                    else
                    {
                        return fs_traits_t::create_directory(sz.data(), lpsa) || ERROR_ALREADY_EXISTS == fs_traits_t::get_last_error();
                    }
                }
            }
        }
    }
}

// \return the Windows API's "last" error
template<
    ss_typename_param_k T_character
,   ss_typename_param_k T_finddata  // This is need because VC++6 cannot deduce filesystem_traits<T_character>::find_data_type
>
inline
ws_dword_t
remove_directory_recurse_impl(
    T_character const*  dir
,   ws_int_t          (*pfn)(void* param, T_character const* subDir, T_finddata const* st, DWORD err)
,   void*               param
)
{
    typedef directory_recurse_traits_t<T_character>         dr_traits_t;
    typedef ss_typename_type_k dr_traits_t::fs_traits_type  fs_traits_t;
    typedef ss_typename_type_k dr_traits_t::buffer_type     buffer_t;
    typedef ss_typename_type_k fs_traits_t::stat_data_type  stat_data_t;

    ws_dword_t dwRet = static_cast<ws_dword_t>(E_FAIL);

    if (NULL != pfn)
    {
        // starting: { param, dir, NULL, ~0 }
        (void)(*pfn)(param, dir, NULL, ~static_cast<ws_dword_t>(0)); // Entering
    }

    if (NULL == dir ||
        '\0' == *dir)
    {
        dwRet = ERROR_DIRECTORY;

        if (NULL != pfn)
        {
            // failed: { param, dir, NULL, error-code }
            (void)(*pfn)(param, dir, NULL, dwRet);
        }
    }
    else
    {
        if (!fs_traits_t::file_exists(dir))
        {
            // The given path does not exist, so this is treated as success, but
            // reporting ERROR_PATH_NOT_FOUND

            dwRet = ERROR_PATH_NOT_FOUND;

            if (NULL != pfn)
            {
                // failed: { param, dir, NULL, error-code }
                (void)(*pfn)(param, dir, NULL, dwRet);
            }
        }
        else
        {
            if (fs_traits_t::is_file(dir))
            {
                // The given path exists as a file. This is failure
                dwRet = ERROR_FILE_EXISTS;

                if (NULL != pfn)
                {
                    // failed: { param, dir, NULL, error-code }
                    (void)(*pfn)(param, dir, NULL, dwRet);
                }
            }
            else
            {
                // Otherwise, we attempt to remove it
                if (fs_traits_t::remove_directory(dir))
                {
                    dwRet = ERROR_SUCCESS;

                    if (NULL != pfn)
                    {
                        // succeeded: { param, dir, NULL, ERROR_SUCCESS }
                        (void)(*pfn)(param, dir, NULL, dwRet); // Deleted
                    }
                }
                else
                {
                    const DWORD removeError = fs_traits_t::get_last_error();

                    if (ERROR_DIR_NOT_EMPTY != removeError &&
                        ERROR_SHARING_VIOLATION != removeError)
                    {
                        dwRet = removeError;

                        if (NULL != pfn)
                        {
                            // failed: { param, dir, NULL, error-code }
                            (void)(*pfn)(param, dir, NULL, dwRet);
                        }
                    }
                    else
                    {
                        // It has some contents, so we need to remove them

                        bool const          hasEnd  =   fs_traits_t::has_dir_end(dir);
                        ws_size_t const     dirLen  =   fs_traits_t::str_len(dir);
                        ws_size_t const     wildLen =   fs_traits_t::str_len(fs_traits_t::pattern_all());
                        ws_size_t const     baseLen =   dirLen + (hasEnd ? 0 : 1);
                        buffer_t            sz(baseLen + wildLen + 1);

                        if (0 == sz.size())
                        {
                            return ERROR_OUTOFMEMORY;
                        }

                        fs_traits_t::char_copy(&sz[0] + 0, dir, dirLen);

                        if (!hasEnd)
                        {
                            sz[dirLen] = '\0';
                            fs_traits_t::ensure_dir_end(&sz[0] + dirLen - 1);
                        }

                        fs_traits_t::char_copy(&sz[0] + baseLen, fs_traits_t::pattern_all(), wildLen);
                        sz[baseLen + wildLen] = '\0';

                        stat_data_t st;
                        HANDLE      hSrch = fs_traits_t::find_first_file(sz.data(), &st);
                        if (INVALID_HANDLE_VALUE == hSrch)
                        {
                            dwRet = fs_traits_t::get_last_error();
                        }
                        else
                        {
                            dwRet = ERROR_SUCCESS;

                            do
                            {
                                if (!fs_traits_t::is_dots(st.cFileName))
                                {
                                    ws_size_t const filenameLen = fs_traits_t::str_len(st.cFileName);

                                    if (sz.size() < baseLen + filenameLen + 1)
                                    {
                                        if (!sz.resize(baseLen + filenameLen + 1))
                                        {
                                            return ERROR_OUTOFMEMORY;
                                        }
                                    }

                                    fs_traits_t::char_copy(&sz[0] + baseLen, st.cFileName, filenameLen);
                                    sz[baseLen + filenameLen] = '\0';

                                    if (fs_traits_t::is_file(sz.data()))
                                    {
                                        // If it's a file, the pfn must be consulted, otherwise
                                        // it's an automatic failure

                                        ws_int_t r = 0;

                                        if (NULL == pfn ||
                                            0 == (r = (*pfn)(param, dir, &st, ERROR_SUCCESS)))
                                        {
                                            dwRet = ERROR_DIR_NOT_EMPTY;

                                            if (NULL != pfn)
                                            {
                                                // failed: { param, dir, &entry, error-code }
                                                (void)(*pfn)(param, dir, &st, dwRet);
                                            }

                                            break;
                                        }
                                        else
                                        {
                                            if (r > 0)
                                            {
                                                if (!fs_traits_t::delete_file(sz.data()))
                                                {
                                                    dwRet = fs_traits_t::get_last_error();

                                                    if (NULL != pfn)
                                                    {
                                                        // failed: { param, dir, &entry, error-code }
                                                        (void)(*pfn)(param, dir, &st, dwRet);
                                                    }

                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        ws_int_t r = 1;

                                        // If it's a directory, then pfn is consulted, otherwise
                                        // it's an automatic attempt to recursively delete
                                        if (NULL != pfn &&
                                            0 == (r = (*pfn)(param, dir, &st, ERROR_SUCCESS)))
                                        {
                                            dwRet = ERROR_DIR_NOT_EMPTY;

                                            if (NULL != pfn)
                                            {
                                                // failed: { param, dir, &entry, error-code }
                                                (void)(*pfn)(param, dir, &st, dwRet);
                                            }

                                            break;
                                        }
                                        else
                                        {
                                            if (r > 0)
                                            {
                                                dwRet = remove_directory_recurse_impl(sz.data(), pfn, param);

                                                if (ERROR_SUCCESS != dwRet)
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }

                            } while (fs_traits_t::find_next_file(hSrch, &st));

                            fs_traits_t::find_file_close(hSrch);

                            if (ERROR_SUCCESS == dwRet)
                            {
                                if (fs_traits_t::remove_directory(dir))
                                {
                                    if (NULL != pfn)
                                    {
                                        // succeeded: { param, dir, NULL, ERROR_SUCCESS }
                                        (void)(*pfn)(param, dir, NULL, ERROR_SUCCESS); // Deleted
                                    }
                                }
                                else
                                {
                                    dwRet = fs_traits_t::get_last_error();
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return dwRet;
}

STLSOFT_CLOSE_WORKER_NS_(ximpl_winstl_directory_functions_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Creates the given directory, including all its parent directories, applying
 * the given mode.
 *
 * \ingroup group__library__FileSystem
 *
 * \param dir The path of the directory to create
 * \param lpsa The security attributes with which each directory is to be created
 */
inline
ws_bool_t
create_directory_recurse(
    ws_char_a_t const*      dir
,   LPSECURITY_ATTRIBUTES   lpsa = NULL
)
{
    return STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_directory_functions_, create_directory_recurse_impl)(dir, lpsa);
}

/** Creates the given directory, including all its parent directories, applying
 * the given mode.
 *
 * \ingroup group__library__FileSystem
 *
 * \param dir The path of the directory to create
 * \param lpsa The security attributes with which each directory is to be created
 */
inline
ws_bool_t
create_directory_recurse(
    ws_char_w_t const*      dir
,   LPSECURITY_ATTRIBUTES   lpsa = NULL
)
{
    return STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_directory_functions_, create_directory_recurse_impl)(dir, lpsa);
}

/** Creates the given directory, including all its parent directories, applying
 * the given mode.
 *
 * \ingroup group__library__FileSystem
 *
 * \param dir The path of the directory to create
 * \param lpsa The security attributes with which each directory is to be created
 */
template<
    ss_typename_param_k S
>
inline
ws_bool_t
create_directory_recurse(
    S const&                dir
,   LPSECURITY_ATTRIBUTES   lpsa = NULL
)
{
    return create_directory_recurse(STLSOFT_NS_QUAL(c_str_ptr)(dir), lpsa);
}

/** Removes the given directory, and all its subdirectories.
 *
 * \ingroup group__library__FileSystem
 *
 * \param dir The path of the directory to remove.
 * \param pfn Pointer to a callback function, which will receive
 *   notifications and requests for file/directory deletion. The semantics
 *   of the parameters are specified in the note below.
 * \param param Caller-supplied parameter, always passed through to the
 *   callback function \c pfn.
 *
 * \note If no callback function is specified, then the function will remove
 *   only empty subdirectories, i.e. no files will be removed. To remove
 *   files, a function must be supplied, and may take additional measures
 *   (such as changing file attributes) before the deletion is attempted by
 *   <code>remove_directory_recurse()</code>. Do not delete the file in the
 *   callback, otherwise the attempt within
 *   <code>remove_directory_recurse()</code> will fail, and the function
 *   will report overall failure of the operation.
 *
 * \note The semantics of the callback function's parameters are as follows:
 * \li If the err param is ~0 (-1 on UNIX), then the \c dir param specifies
 *   the name of the current directory being traversed. All other params are
 *   unspecified (except \c param). The return value is ignored.
 * \li If the err param is 0 and the \c st param is NULL, then \c dir
 *   specifies the name of a directory that has been successfully removed.
 *   All other params are unspecified (except \c param). The return value is
 *   ignored.
 * \li If the err param is 0 and the \c st param is not NULL, then \c dir
 *   specifies the name of the currently traversing directory, and \c st
 *   specifies the stat information for the entry to be deleted. Return true
 *   to enable removal of this entry, or false to prevent removal (and
 *   cancel the overall operation). All other params are unspecified (except
 *   \c param).
 * \li If the err param is any other value, and the \c st param is NULL,
 *   then the \c dir param specifies the name of a directory that could not
 *   be deleted and err specifies the errno value associated with the
 *   failure. All other params are unspecified (except \c param). The return
 *   value is ignored.
 * \li If the err param is any other value, and the \c st param is not NULL,
 *   then the \c dir param specifies the name of a directory within which an
 *   entry could not be deleted, \c st specifies the stat information of the
 *   entry that could not be deleted, and err specifies the errno value
 *   associated with the failure. All other params are unspecified (except
 *   \c param). The return value is ignored.
 */
inline
ws_bool_t
remove_directory_recurse(
    ws_char_a_t const*  dir
,   ws_int_t          (*pfn)(void* param, ws_char_a_t const* subDir, WIN32_FIND_DATAA const* st, DWORD err)
,   void*               param
)
{
    typedef filesystem_traits<ws_char_a_t>  traits_t;

    ws_dword_t const dwRet = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_directory_functions_, remove_directory_recurse_impl)<ws_char_a_t, WIN32_FIND_DATAA>(dir, pfn, param);

    traits_t::set_last_error(dwRet);

    return ERROR_SUCCESS == dwRet;
}

/** Removes the given directory, and all its subdirectories.
 *
 * \ingroup group__library__FileSystem
 */
inline
ws_bool_t
remove_directory_recurse(
    ws_char_a_t const* dir
)
{
    return remove_directory_recurse(dir, NULL, NULL);
}

/** Removes the given directory, and all its subdirectories.
 *
 * \ingroup group__library__FileSystem
 */
inline
ws_bool_t
remove_directory_recurse(
    ws_char_w_t const*  dir
,   ws_int_t          (*pfn)(void* param, ws_char_w_t const* subDir, WIN32_FIND_DATAW const* st, DWORD err)
,   void*               param
)
{
    typedef filesystem_traits<ws_char_w_t>  traits_t;

    ws_dword_t const dwRet = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_directory_functions_, remove_directory_recurse_impl)<ws_char_w_t, WIN32_FIND_DATAW>(dir, pfn, param);

    traits_t::set_last_error(dwRet);

    return ERROR_SUCCESS == dwRet;
}

/** Removes the given directory, and all its subdirectories.
 *
 * \ingroup group__library__FileSystem
 */
inline
ws_bool_t
remove_directory_recurse(
    ws_char_w_t const* dir
)
{
    return remove_directory_recurse(dir, NULL, NULL);
}

/** Removes the given directory, and all its subdirectories.
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k S
>
inline
ws_bool_t
remove_directory_recurse(
    S const& dir
)
{
    return remove_directory_recurse(STLSOFT_NS_QUAL(c_str_ptr)(dir), NULL, NULL);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

