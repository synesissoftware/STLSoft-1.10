/* /////////////////////////////////////////////////////////////////////////
 * File:        inetstl/filesystem/filesystem_traits.hpp (originally MInetEnm.h)
 *
 * Purpose:     Contains the filesystem_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     30th April 1999
 * Updated:     29th January 2024
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


/** \file inetstl/filesystem/filesystem_traits.hpp
 *
 * \brief [C++] Definition of the inetstl::filesystem_traits
 *   traits class template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
#define INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MAJOR    5
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MINOR    0
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_REVISION 2
# define INETSTL_VER_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_EDIT     95
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef INETSTL_INCL_INETSTL_H_INETSTL
# include <inetstl/inetstl.h>
#endif /* !INETSTL_INCL_INETSTL_H_INETSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS
# include <stlsoft/string/c_string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_C_STRING_TRAITS */

#ifndef INETSTL_OS_IS_WINDOWS
# error This file is currently compatible only with the Win32/Win64 API
#endif /* !INETSTL_OS_IS_WINDOWS */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_ANY_CAST
# include <stlsoft/conversion/any_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_ANY_CAST */
#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::inetstl */
namespace inetstl
{
# else
/* Define stlsoft::inetstl_project */
namespace stlsoft
{
namespace inetstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** Traits for accessing the correct file-system functions for a given character type
 *
 * \ingroup group__library__FileSystem
 *
 * filesystem_traits is a traits class for determining the correct file-system
 * structures and functions for a given character type.
 *
 * \param C The character type
 */
template <ss_typename_param_k C>
struct filesystem_traits
{
/// \name Member Types
/// @{
public:
    /// The character type
    typedef C                       char_type;
    /// The size type
    typedef is_size_t               size_type;
    /// The difference type
    typedef is_ptrdiff_t            difference_type;
    /// The find data type
    typedef WIN32_FIND_DATA         find_data_type;
    /// The stat data type
    typedef WIN32_FIND_DATA         stat_data_type;
    /// The current instantion of the type
    typedef filesystem_traits<C>    class_type;
    /// The (signed) integer type
    typedef is_int_t                int_type;
    /// The Boolean type
    typedef is_bool_t               bool_type;
    /// The type of system error codes
    typedef DWORD                   error_type;
/// @}

/// \name File-system entry names
/// @{
public:
    /// Appends a path name separator to \c dir if one does not exist
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type*   ensure_dir_end(char_type* dir);
    /// Removes the path name separator from the end of \c dir, if it has it
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type*   remove_dir_end(char_type* dir);
    /// Returns \c true if \c dir has trailing path name separator
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static bool_type    has_dir_end(char_type const* dir);

    /// Returns \c true if dir is \c "." or \c ".."
    static bool_type    is_dots(char_type const* dir);
    /// Returns \c true if path is rooted
    static bool_type    is_path_rooted(char_type const* path);
    /// Returns \c true if path is an absolute path
    static bool_type    is_path_absolute(char_type const* path);

    /// Returns \c true if the character is a path-name separator
    ///
    /// \note Both \c / and \c \\ are interpreted as a path name separator
    static bool_type    is_path_name_separator(char_type ch);

    /// Returns the path separator
    ///
    /// This is the separator that is used to separate multiple paths on the operating system. On UNIX it is ':'
    static char_type    path_separator();
    /// Returns the path name separator
    ///
    /// This is the separator that is used to separate parts of a path on the operating system. On UNIX it is '/'
    static char_type    path_name_separator();
    /// Returns the wildcard pattern that represents all possible matches
    ///
    /// \note It is '*'
    static char_type const* pattern_all();
    /// Gets the full path name into the given buffer, returning a pointer to the file-part
    static size_type    get_full_path_name(HINTERNET hconn, char_type const* fileName, size_type cchBuffer, char_type* buffer, char_type** ppFile);
    /// Gets the full path name into the given buffer
    static size_type    get_full_path_name(HINTERNET hconn, char_type const* fileName, size_type cchBuffer, char_type* buffer);
/// @}

/// \name Internet connectivity
/// @{
public:
    /// Opens a WinInet session
    static HINTERNET    internet_open(char_type const* agent, is_dword_t accessType, char_type const* proxy, char_type const* proxyBypass, is_dword_t flags);
    /// Makes a connection to a FTP or HTTP site
    static HINTERNET    internet_connect(HINTERNET hsess, char_type const* server, INTERNET_PORT port, char_type const* userName, char_type const* password, is_dword_t service, is_dword_t flags, is_dword_t context);
    /// Closes the connection to the FTP or HTTP site
    static void         close_connection(HINTERNET hconn);
/// @}

/// \name File-system enumeration
/// @{
public:
    /// Initiate a file-system search
    static HINTERNET    find_first_file(HINTERNET hconn, char_type const* spec, find_data_type *findData, is_dword_t flags = 0, is_dword_t context = 0);
    /// Advance a given file-system search
    static bool_type    find_next_file(HANDLE h, find_data_type *findData);
    /// Closes the file-search
    static void         find_close(HINTERNET hfind);
/// @}

/// \name File-system state
/// @{
public:
    /// Sets the current directory to \c dir
    static bool_type    set_current_directory(HINTERNET hconn, char_type const* dir);
    /// Retrieves the name of the current directory into \c buffer up to a maximum of \c cchBuffer characters
    static bool_type    get_current_directory(HINTERNET hconn, is_size_t &cchBuffer, char_type* buffer);

    /// Returns whether a file exists or not
    static bool_type    file_exists(HINTERNET hconn, char_type const* fileName);
    /// Returns whether the given path represents a file
    static bool_type    is_file(HINTERNET hconn, char_type const* path);
    /// Returns whether the given path represents a directory
    static bool_type    is_directory(HINTERNET hconn, char_type const* path);
    /// Gets the information for a particular file system entry
    static bool_type    stat(HINTERNET hconn, char_type const* path, stat_data_type *stat_data);

    /// Returns whether the given stat info represents a file
    static bool_type    is_file(stat_data_type const* stat_data);
    /// Returns whether the given stat info represents a directory
    static bool_type    is_directory(stat_data_type const* stat_data);
    /// Returns whether the given stat info represents a link
    static bool_type    is_link(stat_data_type const* stat_data);
    /// Returns whether the given stat info represents a read-only entry
    static bool_type    is_readonly(stat_data_type const* stat_data);
/// @}

/// \name File-system control
/// @{
public:
    /// Creates a directory
    static bool_type    create_directory(HINTERNET hconn, char_type const* dir);
    /// Deletes a directory
    static bool_type    remove_directory(HINTERNET hconn, char_type const* dir);

    /// Delete a file
    static bool_type    delete_file(HINTERNET hconn, char_type const* file);
    /// Rename a file
    static bool_type    rename_file(HINTERNET hconn, char_type const* currentName, char_type const* newName);
/// @}
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct filesystem_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<is_char_a_t>
    : public STLSOFT_NS_QUAL(c_string_traits)<is_char_a_t>
{
public:
    typedef is_char_a_t                     char_type;
    typedef is_size_t                       size_type;
    typedef is_ptrdiff_t                    difference_type;
    typedef WIN32_FIND_DATAA                find_data_type;
    typedef WIN32_FIND_DATAA                stat_data_type;
    typedef filesystem_traits<is_char_a_t>  class_type;
    typedef is_int_t                        int_type;
    typedef is_bool_t                       bool_type;
    typedef DWORD                           error_type;

public:
    // File-system entry names
    static char_type* ensure_dir_end(char_type* dir)
    {
        char_type       *end;
        char_type const separator = (NULL == str_chr(dir, '/') && NULL != str_chr(dir, '\\')) ? '\\' : '/';

        for (end = dir; *end != '\0'; ++end)
        {}

        if (dir < end &&
            *(end - 1) != separator)
        {
            *end        =   separator;
            *(end + 1)  =   '\0';
        }

        return dir;
    }

    static char_type* remove_dir_end(char_type* dir)
    {
        char_type   *end;

        for (end = dir; *end != '\0'; ++end)
        {}

        if (dir < end &&
            *(end - 1) == path_name_separator())
        {
            *(end - 1)  =   '\0';
        }

        return dir;
    }

    static bool_type has_dir_end(char_type const* dir)
    {
        is_size_t len = str_len(dir);

        return (0 < len) && path_name_separator() == dir[len - 1];
    }

    static bool_type is_dots(char_type const* dir)
    {
        return  dir != 0 &&
                dir[0] == '.' &&
                (   dir[1] == '\0' ||
                    (    dir[1] == '.' &&
                        dir[2] == '\0'));
    }

    static bool_type is_path_rooted(char_type const* path)
    {
        INETSTL_ASSERT(NULL != path);

        return '/' == *path;
    }

    static bool_type is_path_absolute(char_type const* path)
    {
        return is_path_rooted(path);
    }

    static bool_type is_path_name_separator(char_type ch)
    {
        return '/' == ch;
    }

    static char_type path_separator()
    {
        return ';';
    }

    static char_type path_name_separator()
    {
        return '/';
    }

    static char_type const* pattern_all()
    {
        return "*";
    }

    static size_type get_full_path_name(HINTERNET hconn, char_type const* fileName, size_type cchBuffer, char_type* buffer, char_type** ppFile)
    {
        INETSTL_ASSERT(0 == cchBuffer || NULL != buffer);
        INETSTL_ASSERT(NULL == buffer || 0 != cchBuffer);
        INETSTL_ASSERT(NULL != fileName);

        // Deduce the separator
        char_type const separator   =   (NULL == str_chr(fileName, '/') && NULL != str_chr(fileName, '\\')) ? '\\' : '/';
        char_type       fullPath[1 + INETSTL_CONST_MAX_PATH];
        size_type       len         =   str_len(fileName);

        // If we're not rooted, then get the current directory and concatenate
        if (separator != *fileName)
        {
            is_size_t   cchBuffer2  =   STLSOFT_NUM_ELEMENTS(fullPath);
            const int   isDot       =   '.' == 0[fileName] && '\0' == 0[fileName];

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This looks a bit dodgy. Better to use an auto_buffer, and cycle the size, testing the return value from get_current_directory"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

            if (!get_current_directory(hconn, cchBuffer2, fullPath))
            {
                fullPath[0] = '\0';
            }
            size_type   cchFullPath = str_len(fullPath);

            if (!isDot)
            {
                if (!has_dir_end(fullPath))
                {
                    ensure_dir_end(fullPath);
                    ++cchFullPath;
                }
                char_copy(&fullPath[0] + cchFullPath, fileName, 1 + len);
            }

            fileName    =   fullPath;
            len         +=  cchFullPath;
        }

        if (NULL != buffer)
        {
            if (cchBuffer < len)
            {
                len = cchBuffer;
            }

            char_copy(buffer, fileName, cchBuffer);

            if (NULL != ppFile)
            {
                char_type const* pRSlash        =   str_rchr(buffer, '/');
                char_type const* pRBackSlash    =   str_rchr(buffer, '\\');

                if (pRSlash < pRBackSlash)
                {
                    pRSlash = pRBackSlash;
                }

                if (NULL == pRSlash)
                {
                    *ppFile = NULL;
                }
                else
                {
                    *ppFile = const_cast<char_type*>(pRSlash) + 1;
                }
            }
        }

        return len;
    }

    static size_type get_full_path_name(HINTERNET hconn, char_type const* fileName, size_type cchBuffer, char_type* buffer)
    {
        char_type* pFile;

        return get_full_path_name(hconn, fileName, cchBuffer, buffer, &pFile);
    }

    // Internet connectivity
    static HINTERNET internet_open(char_type const* agent, is_dword_t accessType, char_type const* proxy, char_type const* proxyBypass, is_dword_t flags)
    {
        return ::InternetOpenA(agent, accessType, proxy, proxyBypass, flags);
    }

    static HINTERNET internet_connect(HINTERNET hsess, char_type const* server, INTERNET_PORT port, char_type const* userName, char_type const* password, is_dword_t service, is_dword_t flags, is_dword_t context)
    {
        return ::InternetConnectA(hsess, server, port, userName, password, service, flags, context);
    }

    static void close_connection(HINTERNET hconn)
    {
        INETSTL_ASSERT(NULL != hconn);

        ::InternetCloseHandle(hconn);
    }

    // FindFile() API
    static HINTERNET find_first_file(HINTERNET hconn, char_type const* spec, find_data_type *findData, is_dword_t flags = 0, is_dword_t context = 0)
    {
        HINTERNET hfind = ::FtpFindFirstFileA(hconn, spec, STLSOFT_NS_QUAL(any_caster)<find_data_type*, LPWIN32_FIND_DATAA, LPWIN32_FIND_DATAW>(findData), flags, context);

        return hfind;
    }

    static bool_type find_next_file(HANDLE h, find_data_type *findData)
    {
        return FALSE != ::InternetFindNextFileA(h, findData);
    }

    static void find_close(HINTERNET hfind)
    {
        INETSTL_ASSERT(NULL != hfind);

        ::InternetCloseHandle(hfind);
    }

    // File system state
    static bool_type set_current_directory(HINTERNET hconn, char_type const* dir)
    {
        return ::FtpSetCurrentDirectoryA(hconn, dir) != FALSE;
    }

    static bool_type get_current_directory(HINTERNET hconn, is_size_t &cchBuffer, char_type* buffer)
    {
        return FALSE != ::FtpGetCurrentDirectoryA(hconn, buffer, sap_cast<unsigned long*>(&cchBuffer));
    }

    static bool_type file_exists(HINTERNET hconn, char_type const* fileName)
    {
        find_data_type  data;
        HINTERNET       hfind = find_first_file(hconn, fileName, &data);

        return (NULL == hfind) ? false : (find_close(hfind), true);
    }

#if 0
    static bool_type    is_file(HINTERNET hconn, char_type const* path);
    static bool_type    is_directory(HINTERNET hconn, char_type const* path);
    static bool_type    stat(HINTERNET hconn, char_type const* path, stat_data_type *stat_data);
#endif /* 0 */

    static bool_type    is_file(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type    is_directory(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type    is_link(stat_data_type const* stat_data);
    static bool_type    is_readonly(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

    // File system control
    static bool_type create_directory(HINTERNET hconn, char_type const* dir)
    {
        return FALSE != ::FtpCreateDirectoryA(hconn, dir);
    }

    static bool_type remove_directory(HINTERNET hconn, char_type const* dir)
    {
        return FALSE != ::FtpRemoveDirectoryA(hconn, dir);
    }

    static bool_type delete_file(HINTERNET hconn, char_type const* file)
    {
        return FALSE != ::FtpDeleteFileA(hconn, file);
    }

    static bool_type rename_file(HINTERNET hconn, char_type const* currentName, char_type const* newName)
    {
        return FALSE != ::FtpRenameFileA(hconn, currentName, newName);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<is_char_w_t>
    : public STLSOFT_NS_QUAL(c_string_traits)<is_char_w_t>
{
public:
    typedef is_char_w_t                     char_type;
    typedef is_size_t                       size_type;
    typedef is_ptrdiff_t                    difference_type;
    typedef WIN32_FIND_DATAW                find_data_type;
    typedef WIN32_FIND_DATAW                stat_data_type;
    typedef filesystem_traits<is_char_w_t>  class_type;
    typedef is_int_t                        int_type;
    typedef is_bool_t                       bool_type;
    typedef DWORD                           error_type;

public:

    // File-system entry names
    static char_type* ensure_dir_end(char_type* dir)
    {
        char_type       *end;
        char_type const separator = (NULL == str_chr(dir, L'/') && NULL != str_chr(dir, L'\\')) ? L'\\' : L'/';

        for (end = dir; *end != L'\0'; ++end)
        {}

        if (dir < end &&
            *(end - 1) != separator)
        {
            *end        =   separator;
            *(end + 1)  =   L'\0';
        }

        return dir;
    }

    static char_type* remove_dir_end(char_type* dir)
    {
        char_type   *end;

        for (end = dir; *end != '\0'; ++end)
        {}

        if (dir < end &&
            *(end - 1) == path_name_separator())
        {
            *(end - 1)  =   '\0';
        }

        return dir;
    }

    static bool_type has_dir_end(char_type const* dir)
    {
        is_size_t len = str_len(dir);

        return (0 < len) && path_name_separator() == dir[len - 1];
    }

    static bool_type is_dots(char_type const* dir)
    {
        return  dir != 0 &&
                dir[0] == '.' &&
                (   dir[1] == L'\0' ||
                    (    dir[1] == L'.' &&
                        dir[2] == L'\0'));
    }

    static bool_type is_path_rooted(char_type const* path)
    {
        INETSTL_ASSERT(NULL != path);

        return L'/' == *path;
    }

    static bool_type is_path_absolute(char_type const* path)
    {
        return is_path_rooted(path);
    }

    static bool_type is_path_name_separator(char_type ch)
    {
        return L'/' == ch;
    }

    static char_type path_separator()
    {
        return L';';
    }

    static char_type path_name_separator()
    {
        return L'/';
    }

    static char_type const* pattern_all()
    {
        return L"*";
    }

    static size_type get_full_path_name(HINTERNET hconn, char_type const* fileName, size_type cchBuffer, char_type* buffer, char_type** ppFile)
    {
        INETSTL_ASSERT(0 == cchBuffer || NULL != buffer);
        INETSTL_ASSERT(NULL == buffer || 0 != cchBuffer);
        INETSTL_ASSERT(NULL != fileName);

        // Deduce the separator
        char_type const separator   =   (NULL == str_chr(fileName, L'/') && NULL != str_chr(fileName, L'\\')) ? L'\\' : L'/';
        char_type       fullPath[1 + INETSTL_CONST_MAX_PATH];
        size_type       len         =   str_len(fileName);

        // If we're not rooted, then get the current directory and concatenate
        if (separator != *fileName)
        {
            is_size_t   cchBuffer2  =   STLSOFT_NUM_ELEMENTS(fullPath);
            const int   isDot       =   L'.' == 0[fileName] && L'\0' == 0[fileName];

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("This looks a bit dodgy. Better to use an auto_buffer, and cycle the size, testing the return value from get_current_directory"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

            if (!get_current_directory(hconn, cchBuffer2, fullPath))
            {
                fullPath[0] = L'\0';
            }
            size_type   cchFullPath = str_len(fullPath);

            if (!isDot)
            {
                if (!has_dir_end(fullPath))
                {
                    ensure_dir_end(fullPath);
                    ++cchFullPath;
                }
                char_copy(&fullPath[0] + cchFullPath, fileName, 1 + len);
            }

            fileName    =   fullPath;
            len         +=  cchFullPath;
        }

        if (NULL != buffer)
        {
            if (cchBuffer < len)
            {
                len = cchBuffer;
            }

            char_copy(buffer, fileName, cchBuffer);

            if (NULL != ppFile)
            {
                char_type const* pRSlash        =   str_rchr(buffer, L'/');
                char_type const* pRBackSlash    =   str_rchr(buffer, L'\\');

                if (pRSlash < pRBackSlash)
                {
                    pRSlash = pRBackSlash;
                }

                if (NULL == pRSlash)
                {
                    *ppFile = NULL;
                }
                else
                {
                    *ppFile = const_cast<char_type*>(pRSlash) + 1;
                }
            }
        }

        return len;
    }

    static size_type get_full_path_name(HINTERNET hconn, char_type const* fileName, size_type cchBuffer, char_type* buffer)
    {
        char_type* pFile;

        return get_full_path_name(hconn, fileName, cchBuffer, buffer, &pFile);
    }

    // Internet connectivity
    static HINTERNET internet_open(char_type const* agent, is_dword_t accessType, char_type const* proxy, char_type const* proxyBypass, is_dword_t flags)
    {
        return ::InternetOpenW(agent, accessType, proxy, proxyBypass, flags);
    }

    static HINTERNET internet_connect(HINTERNET hsess, char_type const* server, INTERNET_PORT port, char_type const* userName, char_type const* password, is_dword_t service, is_dword_t flags, is_dword_t context)
    {
        return ::InternetConnectW(hsess, server, port, userName, password, service, flags, context);
    }

    static void close_connection(HINTERNET hconn)
    {
        INETSTL_ASSERT(NULL != hconn);

        ::InternetCloseHandle(hconn);
    }

    // FindFile() API
    static HINTERNET find_first_file(HINTERNET hconn, char_type const* spec, find_data_type *findData, is_dword_t flags = 0, is_dword_t context = 0)
    {
        return ::FtpFindFirstFileW(hconn, spec, STLSOFT_NS_QUAL(any_caster)<find_data_type*, LPWIN32_FIND_DATAA, LPWIN32_FIND_DATAW>(findData), flags, context);
    }

    static bool_type find_next_file(HANDLE h, find_data_type *findData)
    {
        return FALSE != ::InternetFindNextFileW(h, findData);
    }

    static void find_close(HINTERNET hfind)
    {
        INETSTL_ASSERT(NULL != hfind);

        ::InternetCloseHandle(hfind);
    }

    // File system state
    static bool_type set_current_directory(HINTERNET hconn, char_type const* dir)
    {
        return ::FtpSetCurrentDirectoryW(hconn, dir) != FALSE;
    }

    static bool_type get_current_directory(HINTERNET hconn, is_size_t &cchBuffer, char_type* buffer)
    {
        return FALSE != ::FtpGetCurrentDirectoryW(hconn, buffer, sap_cast<unsigned long*>(&cchBuffer));
    }

    /// Returns whether a file exists or not
    static bool_type file_exists(HINTERNET hconn, char_type const* fileName)
    {
        find_data_type  data;
        HINTERNET       hfind = find_first_file(hconn, fileName, &data);

        return (NULL == hfind) ? false : (find_close(hfind), true);
    }

#if 0
    static bool_type    is_file(HINTERNET hconn, char_type const* path);
    static bool_type    is_directory(HINTERNET hconn, char_type const* path);
    static bool_type    stat(HINTERNET hconn, char_type const* path, stat_data_type *stat_data);
#endif /* 0 */

    static bool_type    is_file(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type    is_directory(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type    is_link(stat_data_type const* stat_data);
    static bool_type    is_readonly(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

    // File system control
    static bool_type create_directory(HINTERNET hconn, char_type const* dir)
    {
        return FALSE != ::FtpCreateDirectoryW(hconn, dir);
    }

    static bool_type remove_directory(HINTERNET hconn, char_type const* dir)
    {
        return FALSE != ::FtpRemoveDirectoryW(hconn, dir);
    }

    static bool_type delete_file(HINTERNET hconn, char_type const* file)
    {
        return FALSE != ::FtpDeleteFileW(hconn, file);
    }

    static bool_type rename_file(HINTERNET hconn, char_type const* currentName, char_type const* newName)
    {
        return FALSE != ::FtpRenameFileW(hconn, currentName, newName);
    }
};

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef INETSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace inetstl */
# else
} /* namespace inetstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !INETSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !INETSTL_INCL_INETSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

