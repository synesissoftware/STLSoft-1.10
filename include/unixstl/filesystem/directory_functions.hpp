/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/directory_functions.hpp
 *
 * Purpose:     Functions for manipulating directories.
 *
 * Created:     7th February 2002
 * Updated:     25th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file unixstl/filesystem/directory_functions.hpp
 *
 * \brief [C++] Functions for manipulating directories
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_MAJOR       3
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_MINOR       1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_REVISION    2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS_EDIT        62
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

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */

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
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_OPEN_WORKER_NS_(ximpl_unixstl_directory_functions_)

template<
    ss_typename_param_k T_character
>
inline
us_bool_t
create_directory_recurse_impl(
    T_character const*  dir
,   unsigned short      mode
)
{
    typedef T_character                                     char_t;
    typedef filesystem_traits<
        T_character
    >                                                       fs_traits_t;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_t
#ifdef PATH_MAX
    ,   1 + PATH_MAX
#else /* ? PATH_MAX */
    ,   1 + 512
#endif /* PATH_MAX */
    >                                                       buffer_t;

    if (NULL == dir ||
        '\0' == *dir)
    {
        fs_traits_t::set_last_error(ENOTDIR);

        return false;
    }
    else
    {
        if (fs_traits_t::file_exists(dir))
        {
            if (fs_traits_t::is_directory(dir))
            {
                fs_traits_t::set_last_error(EISDIR);

                return true;
            }
            else
            {
                fs_traits_t::set_last_error(EEXIST);

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

            us_size_t const dirLen = fs_traits_t::str_len(dir);
            buffer_t        sz(dirLen + 1);

            if (0 == sz.size())
            {
                return false;
            }

            if ((dirLen + 1) > sz.size())
            {
                fs_traits_t::set_last_error(EINVAL);

                return false;
            }

            fs_traits_t::char_copy(&sz[0] + 0, dir, dirLen);
            sz[dirLen] = '\0';
            fs_traits_t::remove_dir_end(sz);

            if (fs_traits_t::create_directory(sz.data(), mode) ||
                EEXIST == fs_traits_t::get_last_error())
            {
                return true;
            }
            else
            {
                // Trim previous directory

                us_size_t const szLen = fs_traits_t::str_len(dir);
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
                    fs_traits_t::set_last_error(ENOTDIR);

                    return false;
                }
                else
                {
                    *const_cast<char_t*>(pszSlash) = '\0';

                    // If second character is ':', and total lengths is less than four,
                    // or the recurse create fails, then return false;
                    if ((   szParent[1] == ':' &&
                            (fs_traits_t::set_last_error(EACCES), fs_traits_t::str_len(szParent.data()) < 4)) ||
                        !create_directory_recurse_impl(szParent.data(), mode))
                    {
                        return false;
                    }
                    else
                    {
                        return fs_traits_t::create_directory(sz.data(), mode) || EEXIST == fs_traits_t::get_last_error();
                    }
                }
            }
        }
    }
}

template<
    ss_typename_param_k T_character
,   ss_typename_param_k T_finddata  // This is need because VC++6 cannot deduce filesystem_traits<T_character>::find_data_type
>
inline
us_int_t
remove_directory_recurse_impl(
    T_character const*  dir
,   us_int_t          (*pfn)(void* param, T_character const* subDir, T_finddata const* st, struct dirent const* de, int err)
,   void*               param
)
{
    typedef T_character                                     char_t;
    typedef filesystem_traits<T_character>                  fs_traits_t;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_t
#ifdef PATH_MAX
    ,   1 + PATH_MAX
#else /* ? PATH_MAX */
    ,   1 + 512
#endif /* PATH_MAX */
    >                                                       buffer_t;
    typedef ss_typename_type_k fs_traits_t::stat_data_type  stat_data_t;

    us_int_t dwRet;

    if (NULL != pfn)
    {
        (void)(*pfn)(param, dir, NULL, NULL, ~0);   // Entering
    }

    if (NULL == dir ||
        '\0' == *dir)
    {
        dwRet = ENOTDIR;

        if (NULL != pfn)
        {
            (void)(*pfn)(param, dir, NULL, NULL, dwRet);
        }
    }
    else
    {
        if (!fs_traits_t::file_exists(dir))
        {
            // The given path does not exist, so this is treated as success, but
            // reporting ENOENT

            dwRet = ENOENT;

            if (NULL != pfn)
            {
                (void)(*pfn)(param, dir, NULL, NULL, dwRet);
            }
        }
        else
        {
            if (fs_traits_t::is_file(dir))
            {
                // The given path exists as a file. This is failure
                dwRet = EEXIST;

                if (NULL != pfn)
                {
                    (void)(*pfn)(param, dir, NULL, NULL, dwRet);
                }
            }
            else
            {
                // Otherwise, we attempt to remove it
                if (fs_traits_t::remove_directory(dir))
                {
                    dwRet = 0;

                    if (NULL != pfn)
                    {
                        (void)(*pfn)(param, dir, NULL, NULL, dwRet); // Deleted
                    }
                }
                else
                {
                    const int removeError = fs_traits_t::get_last_error();

                    if (ENOTEMPTY != removeError &&
                        EACCES != removeError)
                    {
                        dwRet = removeError;

                        if (NULL != pfn)
                        {
                            (void)(*pfn)(param, dir, NULL, NULL, dwRet);
                        }
                    }
                    else
                    {
                        // It has some contents, so we need to remove them

                        bool const          hasEnd  =   fs_traits_t::has_dir_end(dir);
                        us_size_t const     dirLen  =   fs_traits_t::str_len(dir);
                        us_size_t const     baseLen =   dirLen + (hasEnd ? 0 : 1);
                        buffer_t            sz(baseLen + 1);

                        if (0 == sz.size())
                        {
                            return ENOMEM;
                        }

                        fs_traits_t::char_copy(&sz[0] + 0, dir, dirLen);

                        if (!hasEnd)
                        {
                            sz[dirLen] = '\0';
                            fs_traits_t::ensure_dir_end(&sz[0] + dirLen - 1);
                        }

                        sz[baseLen] = '\0';

                        DIR* hSrch = fs_traits_t::open_dir(sz.data());
                        if (NULL == hSrch)
                        {
                            dwRet = fs_traits_t::get_last_error();
                        }
                        else
                        {
                            dwRet = 0;

                            for (struct dirent const* de; 0 == dwRet && NULL != (de = fs_traits_t::read_dir(hSrch)); )
                            {
                                if (!fs_traits_t::is_dots(de->d_name))
                                {
                                    stat_data_t     st;
                                    us_size_t const denameLen = fs_traits_t::str_len(de->d_name);

                                    if (sz.size() < baseLen + denameLen + 1)
                                    {
                                        if (!sz.resize(baseLen + denameLen + 1))
                                        {
                                            return ENOMEM;
                                        }
                                    }

                                    fs_traits_t::char_copy(&sz[0] + baseLen, de->d_name, denameLen + 1);
                                    if (!fs_traits_t::stat(sz.data(), &st))
                                    {
                                        dwRet = fs_traits_t::get_last_error();

                                        if (NULL != pfn)
                                        {
                                            (void)(*pfn)(param, dir, NULL, de, dwRet);
                                        }
                                    }
                                    else
                                    {
                                        if (fs_traits_t::is_file(&st))
                                        {
                                            // If it's a file, the pfn must be consulted, otherwise
                                            // it's an automatic failure

                                            if (NULL == pfn ||
                                                !(*pfn)(param, dir, &st, de, 0))
                                            {
                                                dwRet = ENOTEMPTY;

                                                if (NULL != pfn)
                                                {
                                                    (void)(*pfn)(param, dir, &st, de, dwRet);
                                                }

                                                break;
                                            }
                                            else
                                            {
                                                if (!fs_traits_t::delete_file(sz.data()))
                                                {
                                                    dwRet = fs_traits_t::get_last_error();

                                                    if (NULL != pfn)
                                                    {
                                                        (void)(*pfn)(param, dir, &st, de, dwRet);
                                                    }

                                                    break;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            // If it's a directory, then pfn is consulted, otherwise
                                            // it's an automatic attempt to recursively delete
                                            if (NULL != pfn &&
                                                !(*pfn)(param, dir, &st, de, 0))
                                            {
                                                dwRet = ENOTEMPTY;

                                                if (NULL != pfn)
                                                {
                                                    (void)(*pfn)(param, dir, &st, de, dwRet);
                                                }

                                                break;
                                            }
                                            else
                                            {
                                                dwRet = remove_directory_recurse_impl(sz.data(), pfn, param);
                                            }
                                        }
                                    }
                                }
                            }

                            fs_traits_t::close_dir(hSrch);

                            if (0 == dwRet)
                            {
                                if (fs_traits_t::remove_directory(dir))
                                {
                                    if (NULL != pfn)
                                    {
                                        (void)(*pfn)(param, dir, NULL, NULL, 0); // Deleted
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

STLSOFT_CLOSE_WORKER_NS_(ximpl_unixstl_directory_functions_)
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
 * \param mode The permissions with which each directory is to be created
 */
inline
us_bool_t
create_directory_recurse(
    us_char_a_t const*  dir
,   unsigned short      mode = 0755
)
{
    return STLSOFT_WORKER_NS_QUAL_(ximpl_unixstl_directory_functions_, create_directory_recurse_impl)(dir, mode);
}

#if 0
/** Creates the given directory, including all its parent directories, applying
 * the given mode.
 *
 * \ingroup group__library__FileSystem
 *
 * \param dir The path of the directory to create
 * \param mode The permissions with which each directory is to be created
 */
inline
us_bool_t
create_directory_recurse(
    us_char_w_t const*  dir
,   unsigned short      mode = 0755
)
{
    return STLSOFT_WORKER_NS_QUAL_(ximpl_unixstl_directory_functions_, create_directory_recurse_impl)(dir, mode);
}
#endif /* 0 */

/** Creates the given directory, including all its parent directories, applying
 * the given mode.
 *
 * \ingroup group__library__FileSystem
 *
 * \param dir The path of the directory to create
 * \param mode The permissions with which each directory is to be created
 */
template<
    ss_typename_param_k S
>
inline
us_bool_t
create_directory_recurse(
    S const&        dir
,   unsigned short  mode = 0755
)
{
    return create_directory_recurse(STLSOFT_NS_QUAL(c_str_ptr)(dir), mode);
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
 *   specifies the name of the currently traversing directory, \c st
 *   specifies the stat information for the entry to be deleted, and \c de
 *   specifies the name of the entry within directory \c dir that is a
 *   candidate for removal. Return true to enable removal of this entry, or
 *   false to prevent removal (and cancel the overall operation). All other
 *   params are unspecified (except \c param). The return value is ignored.
 * \li If the err param is any other value, and the \c st param is NULL,
 *   then the \c dir param specifies the name of a directory that could not
 *   be deleted and err specifies the errno value associated with the
 *   failure. All other params are unspecified (except \c param). The return
 *   value is ignored.
 * \li If the err param is any other value, and the \c st param is not NULL,
 *   then the \c dir param specifies the name of a directory within which an
 *   entry could not be deleted, \c st specifies the stat information of the
 *   entry that could not be deleted, \c de specifies the name of the entry
 *   that could not be deleted, and err specifies the errno value associated
 *   with the failure. All other params are unspecified (except \c param).
 *   The return value is ignored.
 */
inline
us_bool_t
remove_directory_recurse(
    us_char_a_t const*  dir
,   us_int_t          (*pfn)(void* param, us_char_a_t const* subDir, struct stat const* st, struct dirent const* de, int err)
,   void*               param
)
{
    typedef filesystem_traits<us_char_a_t> fs_traits_t;

    us_int_t const dwRet = STLSOFT_WORKER_NS_QUAL_(ximpl_unixstl_directory_functions_, remove_directory_recurse_impl)<us_char_a_t, struct stat>(dir, pfn, param);

    fs_traits_t::set_last_error(dwRet);

    return 0 == dwRet;
}

/** Removes the given directory, and all its subdirectories.
 *
 * \ingroup group__library__FileSystem
 */
inline
us_bool_t
remove_directory_recurse(
    us_char_a_t const* dir
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
us_bool_t
remove_directory_recurse(
    S const& dir
)
{
    return remove_directory_recurse(STLSOFT_NS_QUAL(c_str_ptr)(dir), NULL, NULL);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
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

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_DIRECTORY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

