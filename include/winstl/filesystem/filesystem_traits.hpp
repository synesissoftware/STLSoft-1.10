/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/filesystem_traits.hpp
 *
 * Purpose:     Contains the filesystem_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
 * Updated:     20th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
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


/** \file winstl/filesystem/filesystem_traits.hpp
 *
 * \brief [C++] Definition of the winstl::filesystem_traits traits
 *  class
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MAJOR       4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MINOR       21
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_REVISION    8
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_EDIT        186
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

#ifdef WINSTL_OS_IS_WIN64

# define _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING
#endif /* _WIN64 || _M_??64 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS
# include <winstl/filesystem/path_classify_functions.h>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS*/
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS
# include <winstl/filesystem/path_parse_functions.h>
#endif /*! WINSTL_INCL_WINSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST
#   include <stlsoft/conversion/truncation_cast.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST */
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST
#   include <stlsoft/conversion/truncation_test.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST */
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR
# include <stlsoft/string/c_string/strnchr.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR */
#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR
# include <stlsoft/string/c_string/strnpbrkn.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS
# include <stlsoft/util/resizeable_buffer_helpers.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS */

#ifndef STLSOFT_INCL_H_CTYPE
# define STLSOFT_INCL_H_CTYPE
# include <ctype.h>
#endif /* !STLSOFT_INCL_H_CTYPE */
#ifndef STLSOFT_INCL_H_WCTYPE
# define STLSOFT_INCL_H_WCTYPE
# include <wctype.h>
#endif /* !STLSOFT_INCL_H_WCTYPE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_external_h_FileManagement
# include <winstl/api/external/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_FileManagement */
#ifndef WINSTL_INCL_WINSTL_API_internal_h_FileManagement
# include <winstl/api/internal/FileManagement.h>
#endif /* !WINSTL_INCL_WINSTL_API_internal_h_FileManagement */
#ifndef WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION_
# include <winstl/internal/windows_version_.h>
#endif /* !WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION_ */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

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

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

/** Traits class for file-system operations
 *
 * \ingroup group__library__FileSystem
 *
 * filesystem_traits is a traits class for determining the correct file-system
 * structures and functions for a given character type.
 *
 * \param C The character type (e.g. \c char, \c wchar_t)
 */
template <ss_typename_param_k C>
struct filesystem_traits
    : public system_traits<C>
{
/// \name types
/// @{
private:
    typedef system_traits<C>                                parent_class_type;
public:
    /// The character type
    typedef C                                               char_type;
    /// The size type
    typedef ws_size_t                                       size_type;
    /// The large size type
    typedef ws_uint64_t                                     large_size_type;
    /// The difference type
    typedef ws_ptrdiff_t                                    difference_type;
    /// The find data type
    typedef WIN32_FIND_DATA                                 find_data_type;     // Placeholder only
    /// The stat data type
    typedef WIN32_FIND_DATA                                 stat_data_type;
    /// The fstat data type
    typedef BY_HANDLE_FILE_INFORMATION                      fstat_data_type;
    /// The current instantion of the type
    typedef filesystem_traits<C>                            class_type;
    /// The path-classification type
    typedef path_classification_t                           path_classification_type;
    /// The path-classification results type
    typedef winstl_C_path_classification_results_t          path_classification_results_type;
    /// The path-classification string slice type
    typedef stlsoft_C_string_slice_t                        path_classification_string_slice_type;
    /// The (signed) integer type
    typedef ws_int_t                                        int_type;
    /// The Boolean type
    typedef ws_bool_t                                       bool_type;
    /// The type of a system file handle
    typedef HANDLE                                          file_handle_type;
    /// The type of a handle to a dynamically loaded module
    typedef HINSTANCE                                       module_type;
    /// The type of system error codes
    typedef DWORD                                           error_type;
    /// The type of file attributes
    typedef DWORD                                           file_attributes_type;
/// @}

/// \name concepts
/// @{
public:
    /// This type does not actually exists in the compilable code, but,
    /// rather, represents a concept used in several functions
    ///
    /// \note It is <em>ALWAYS</em> assumed that the last element in the
    ///   buffer is a <code>NUL</code>-terminator
    struct resizeable_buffer
    {
    public: // typedef
        typedef T_value                                     value_type;
        typedef std::size_t                                 size_type;

    public: // accessors

        /// Obtains a copy of the value (usually a character)
        /// at \c index
        ///
        /// \pre index < size()
        value_type& operator [](size_type index) noexcept;

        /// The number of elements currently managed
        ///
        /// \post empty() || value_type(0) == operator[](size() - 1)
        size_type size() const noexcept;

        /// Indicates whether any elements are managed
        bool_type empty() const noexcept;

    public: // operations

        void resize(size_type newSize);
    };
/// @}

/// \name constants
/// @{
public:
    enum
    {
        maxPathLength = WINSTL_CONST_MAX_PATH   //!< The maximum length of a path for the current file system
    };

    enum
    {
        pathComparisonIsCaseSensitive = false
    };
/// @}

/// \name general string handling
/// @{
public:
    /// Compares the contents of \c src and \c dest, according to the
      /// lexicographical ordering on the host operating system.
    static int_type     str_fs_compare(char_type const* s1, char_type const* s2);
    /// Compares the contents of \c src and \c dest up to \c len
    /// characters. according to the lexicographical ordering on the host
    /// operating system.
    static int_type     str_fs_n_compare(char_type const* s1, char_type const* s2, size_type len);
/// @}

/// \name directory-end
/// @{
public:
    /// Ensures that a given C-style string has a trailing path name
    /// separator by appending one where necessary
    ///
    /// \param dir A non-null pointer to a mutable C-style string
    ///
    /// \return \c dir
    ///
    /// \pre nullptr != dir
    ///
    /// \note \c dir is assumed to contain space for an additional
    ///   character (if required) and NUL-terminator
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    );

    /// Ensures that a given C-style string has a trailing path name
    /// separator by appending one where necessary
    ///
    /// \param path Pointer to characters of path to be examined
    /// \param len Number of characters in \c path to be examined
    /// \param capacity Number of available characters available
    ///   in \c path. If 0, capacity will not be checked
    /// \param pLenToIncrease An optional pointer to a variable that will
    ///   be incremented if a path name separator is appended
    ///
    /// \return \c dir
    ///
    /// \pre 0 == len || nullptr != dir
    /// \pre 0 == capacity || len < capacity
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    ,   size_type   len
    ,   size_type   capacity
    ,   size_type*  pLenToIncrease
    );

    /// Ensures that a given C-style resizeable buffer has a trailing path
    /// name separator by appending one where necessary
    ///
    /// \param rb a reference to a \c resizeable_buffer
    ///
    /// \return The length of \c rb, excluding the
    ///   <code>NUL</code>-terminator, after the operation has completed
    /// \retval 0 if the buffer cannot be resized to accommodate a new
    ///   <code>NUL</code>-terminator
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    ensure_dir_end(
        T_resizeableBuffer& rb
    );

    /// Returns \c true if \c dir has trailing path name separator
    ///
    /// \pre nullptr != dir
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static
    bool_type
    has_dir_end(
        char_type const* dir
    );

    /// Returns \c true if the string designated by \c dir and \c len has
    /// trailing path name separator
    ///
    /// \pre 0 == len || nullptr != dir
    ///
    /// \param path Pointer to characters of path to be examined
    /// \param len Number of characters in \c path to be examined
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static
    bool_type
    has_dir_end(
        char_type const*    dir
    ,   size_type           len
    );

    /// Returns \c true if \c rb has trailing path name separator
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    ///
    /// \retval true !rb.empty() && is_path_name_separator(rb[-2])
    /// \retval false rb.empty() || !is_path_name_separator(rb[-2])
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    bool_type
    has_dir_end(
        T_resizeableBuffer const& rb
    );

    /// Removes the path name separator from the end of \c dir, if present
    ///
    /// \pre nullptr != dir
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static
    char_type*
    remove_dir_end(
        char_type* dir
    );

    /// Removes the path name separator from the end of \c dir, if present
    ///
    /// \param path Pointer to characters of path to be examined
    /// \param len Number of characters in \c path to be examined
    /// \param pLenToDecrease An optional pointer to a variable that will
    ///   be decremented if a path name separator is removed
    ///
    /// \return \c dir
    ///
    /// \pre 0 == len || nullptr != dir
    /// \pre nullptr != pLenToDecrease
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static
    char_type*
    remove_dir_end(
        char_type*  dir
    ,   size_type   len
    ,   size_type*  pLenToDecrease
    );

    /// Removes the path name separator from the end of \c rb, if present
    ///
    /// \param rb a reference to a \c resizeable_buffer
    ///
    /// \return The length of \c rb after the operation has completed
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    remove_dir_end(
        T_resizeableBuffer& rb
    );
/// @}

/// \name path classification and analysis
/// @{
public:
    /// Classifies a path
    ///
    /// \param path
    /// \param len
    /// \param parseFlags
    /// \param results
    ///
    /// \pre 0 == len || nullptr != path
    static
    path_classification_t
    path_classify(
        char_type const*                    path
    ,   size_t                              len
    ,   int                                 parseFlags
    ,   path_classification_results_type*   results
    );

    static
    path_classification_t
    path_classify_root(
        char_type const*                        path
    ,   size_t                                  len
    ,   int                                     parseFlags
    ,   path_classification_string_slice_type*  root
    );

    static
    bool
    path_is_rooted(
        path_classification_t               pc
    );

    static
    bool
    path_is_absolute(
        path_classification_t               pc
    );

    /// Returns a pointer to the last path name separator
    /// in \c path, or \c nullptr if none is found
    ///
    /// \param path C-style string pointer of path to be examined
    ///
    /// \pre nullptr != path
    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    );

    /// Returns a pointer to the last path name separator
    /// in \c path, or \c nullptr if none is found
    ///
    /// \param path Pointer to characters of path to be examined
    /// \param len Number of characters in \c path to be examined
    ///
    /// \pre 0 == len || nullptr != path
    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    );

    /// Returns a pointer to the next path name separator
    /// in \c path, or \c nullptr if none is found
    ///
    /// \param path C-style string pointer of path to be examined
    ///
    /// \pre nullptr != path
    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    );

    /// Returns a pointer to the next path name separator
    /// in \c path, or \c nullptr if none is found
    ///
    /// \param path Pointer to characters of path to be examined
    /// \param len Number of characters in \c path to be examined
    ///
    /// \pre 0 == len || nullptr != path
    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    );

    /// Returns \c true if dir is \c "." or \c ".."
    static bool_type    is_dots(char_type const* dir);

    /// Returns \c true if the path begins with a dots directory
    static bool_type    starts_with_dots(char_type const* dir);

    /// Returns \c true if path is rooted
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// root character sequence(s).
    static bool_type    is_path_rooted(char_type const* path);
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    static bool_type    is_path_rooted(
        char_type const*    path
    ,   size_t              len
    );
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// Returns \c true if path is an absolute path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// absolute path character sequence(s).
    static bool_type    is_path_absolute(char_type const* path);
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    static bool_type    is_path_absolute(
        char_type const*    path
    ,   size_t              len
    );
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// Returns \c true if path is a UNC path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the UNC character sequence(s).
    static bool_type    is_path_UNC(char_type const* path);
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    static bool_type    is_path_UNC(
        char_type const*    path
    ,   size_t              len
    );
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    /// Indicates whether the given path is the root designator.
    ///
    /// The root designator is one of the following:
    ///  - the slash character <code>/</code>
    ///  - the backslash character <code>\\</code>
    ///  - a drive specification, e.g. <code>H:\\</code> or <code>H:/</code>
    ///  - a UNC host, e.g. <code>H:\\\\host</code> or <code>H:\\\\host\\</code>
    ///
    /// The function returns false if the path contains any part of a
    /// file name (or extension), directory, or share.
    static
    bool_type
    is_root_designator(
        char_type const*    path
    );
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    static
    bool_type
    is_root_designator(
        char_type const*    path
    ,   size_t              cchPath
    );
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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
    /// \note On Win32 it is '*.*'
    static char_type const* pattern_all();
    /// The maximum length of a path on the file-system
    ///
    /// \note Because not all systems support fixed maximum path lengths, the value of this function is notionally dynamic
    static size_type    path_max();
    /// Gets the full path name into the given buffer, returning a pointer to the file-part
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    ,   char_type**         ppFile
    );
    /// Gets the full path name into the given buffer
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    );

    /// Gets the full path name into the given buffer
    ///
    /// \param fileName The path to be translated
    /// \param rb Reference to a resizeable buffer into which the
    ///   full-path is to be written
    ///
    /// \return The length of \c rb after the operation has completed
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    );

    /// Gets the full path name into the given buffer
    ///
    /// \deprecated The other overload is now the preferred form
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    );

    /// Gets the short path name into the given buffer
    ///
    /// \deprecated The other overload is now the preferred form
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    );

    /// Gets the short path name into the given buffer
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    );

    /// Gets the short path name into the given buffer
    ///
    /// \param fileName The path to be translated
    /// \param rb Reference to a resizeable buffer into which the
    ///   short-path is to be written
    ///
    /// \return The length of \c rb after the operation has completed
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    );
/// @}

/// \name file-system enumeration
/// @{
public:
    // FindFirstFile/FindNextFile API

    /// Initiate a file-system search
    static HANDLE       find_first_file(char_type const* spec, find_data_type* findData);
#if _WIN32_WINNT >= 0x0400
    /// Initiate a file-system search - NT4+-only
    static HANDLE       find_first_file_ex(char_type const* spec, FINDEX_SEARCH_OPS flags, find_data_type* findData);
#endif /* _WIN32_WINNT >= 0x0400 */
    /// Advance a given file-system search
    static bool_type    find_next_file(HANDLE h, find_data_type* findData);
    /// Closes the handle of the file-system search
    static void         find_file_close(HANDLE h);

    // FindFirstVolume/FindNextVolume API

#ifndef WINSTL_FINDVOLUME_API_NOT_DECLARED

    /// Initiate a file-system volume search
    static HANDLE       find_first_volume(char_type* volume_name, size_type cch_volume_name);
    /// Advance a given file-system volume search
    static bool_type    find_next_volume(HANDLE h, char_type* volume_name, size_type cch_volume_name);
    /// Closes the handle of the file-volume search
    static void         find_volume_close(HANDLE h);
#endif // !WINSTL_FINDVOLUME_API_NOT_DECLARED
/// @}

/// \name file-system control
/// @{
public:
    /// Sets the current directory to \c dir
    static
    bool_type
    set_current_directory(
        char_type const*    dir
    );
    /// Retrieves the name of the current directory into \c buffer up to a maximum of \c cchBuffer characters
    ///
    /// \deprecated The other overload is now the preferred form
    static
    size_type
    get_current_directory(
        size_type   cchBuffer
    ,   char_type   buffer[]
    );
    /// Retrieves the name of the current directory into \c buffer up to a maximum of \c cchBuffer characters
    static
    size_type
    get_current_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    );

    /// Retrieves the name of the current directory into the given buffer
    ///
    /// \param rb Reference to a resizeable buffer into which the
    ///   current directory is to be written
    ///
    /// \return The length of \c rb after the operation has completed
    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_current_directory(
        T_resizeableBuffer& rb
    );
/// @}

/// \name file-system state
/// @{
public:
    /// Returns whether a file exists or not
    static bool_type    file_exists(char_type const* path);
    /// Returns whether the given path represents a file
    static bool_type    is_file(char_type const* path);
    /// Returns whether the given path represents a directory
    static bool_type    is_directory(char_type const* path);
    /// Gets the information for a particular file system entry
    static bool_type    stat(char_type const* path, stat_data_type* stat_data);
    /// Gets the information for a particular open file
    static bool_type    fstat(file_handle_type fd, fstat_data_type* fstat_data);
    /// Gets the file attributes for the given path
    ///
    /// \pre (NULL != path);
    /// \pre (NULL != attr);
    static bool_type    get_file_attributes(char_type const* path, file_attributes_type* attr);
    /// Sets the file attributes for the given path
    ///
    /// \pre (NULL != path);
    /// \pre (INVALID_FILE_ATTRIBUTES != attr);
    static bool_type    set_file_attributes(char_type const* path, file_attributes_type const attr);

    /// Returns whether the given stat info represents a file
    static bool_type    is_file(stat_data_type const* stat_data);
    static bool_type    is_file(fstat_data_type const* stat_data);
    /// Returns whether the given stat info represents a directory
    static bool_type    is_directory(stat_data_type const* stat_data);
    static bool_type    is_directory(fstat_data_type const* stat_data);
    /// Returns whether the given stat info represents a link
    static bool_type    is_link(stat_data_type const* stat_data);
    static bool_type    is_link(fstat_data_type const* stat_data);
    /// Returns whether the given stat info represents a read-only entry
    static bool_type    is_readonly(stat_data_type const* stat_data);
    static bool_type    is_readonly(fstat_data_type const* stat_data);

    /// Indicates whether the given drive currently exists on the system
    static bool_type    drive_exists(char_type driveLetter);
    /// Returns a status code denoting the type of the drive
    ///
    /// \return One of the return codes of the GetDriveType() API function
    static DWORD        get_drive_type(char_type driveLetter);
/// @}

/// \name file-system control
/// @{
public:
    /// Creates a directory
    static bool_type    create_directory(char_type const* dir);
    /// Creates a directory, with the given security attributes
    static bool_type    create_directory(char_type const* dir, LPSECURITY_ATTRIBUTES lpsa);
    /// Deletes a directory
    static bool_type    remove_directory(char_type const* dir);

    /// Delete a file
    static bool_type    unlink_file(char_type const* file);
    /// Delete a file
    ///
    /// \deprecated Users should use unlink_file()
    static bool_type    delete_file(char_type const* file);
    /// Rename a file
    static bool_type    rename_file(char_type const* currentName, char_type const* newName);
    /// Copy a file
    static bool_type    copy_file(char_type const* sourceName, char_type const* newName, bool_type bFailIfExists = false);

    /// The value returned by create_file() that indicates that the
    /// operation failed
    static file_handle_type invalid_file_handle_value();
    /// Create / open a file
    static file_handle_type create_file(char_type const* fileName, size_type desiredAccess, size_type shareMode, LPSECURITY_ATTRIBUTES sa, size_type creationDisposition, size_type flagAndAttributes, HANDLE hTemplateFile);
    /// Closes the given file handle
    static bool_type    close_file(file_handle_type h);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    /// Gets the size of the file
    static large_size_type  get_file_size(file_handle_type h);
    /// Gets the size of the file
    static large_size_type  get_file_size(stat_data_type const& sd);
    /// Gets the size of the file
    ///
    /// \pre (NULL != psd)
    static large_size_type  get_file_size(stat_data_type const* psd);
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
private:
    /// Not currently supported
    static void         get_file_size(stat_data_type const*);
    /// Not currently supported
    static void         get_file_size(stat_data_type const&);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
/// @}
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct filesystem_traits;

struct filesystem_traits_
    : public system_traits_
{
public:
    typedef ws_size_t                                       size_type;
    typedef ws_uint64_t                                     large_size_type;
    typedef ws_ptrdiff_t                                    difference_type;
    typedef filesystem_traits_                              class_type;
    typedef BY_HANDLE_FILE_INFORMATION                      fstat_data_type;
    typedef ws_int_t                                        int_type;
    typedef ws_bool_t                                       bool_type;
    typedef HANDLE                                          file_handle_type;
    typedef HINSTANCE                                       module_type;
    typedef DWORD                                           error_type;
    typedef DWORD                                           file_attributes_type;

    enum
    {
        maxPathLength = WINSTL_CONST_MAX_PATH   //!< The maximum length of a path for the current file system
    };

    enum
    {
        pathComparisonIsCaseSensitive = false
    };

public:
    static bool_type fstat(file_handle_type fd, fstat_data_type* fstat_data)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_GetFileInformationByHandle(fd, fstat_data);
    }

    static bool_type is_file(fstat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_directory(fstat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_link(fstat_data_type const*  /* stat_data */)
    {
        return false;
    }
    static bool_type is_readonly(fstat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static large_size_type get_file_size(file_handle_type h)
    {
        DWORD   dwHigh;
        DWORD   dwLow = WINSTL_API_EXTERNAL_FileManagement_GetFileSize(h, &dwHigh);

        if (0xFFFFFFFF == dwLow &&
            ERROR_SUCCESS != WINSTL_API_EXTERNAL_ErrorHandling_GetLastError())
        {
            dwHigh = 0xFFFFFFFF;
        }

        return (static_cast<ws_uint64_t>(dwHigh) << 32) | dwLow;
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<ws_char_a_t>
    : public system_traits<ws_char_a_t>
{
public: // types
    typedef ws_char_a_t                                     char_type;
    typedef ws_size_t                                       size_type;
    typedef ws_uint64_t                                     large_size_type;
    typedef ws_ptrdiff_t                                    difference_type;
    typedef WIN32_FIND_DATAA                                find_data_type;
    typedef WIN32_FIND_DATAA                                stat_data_type;
    typedef BY_HANDLE_FILE_INFORMATION                      fstat_data_type;
    typedef filesystem_traits<char_type>                    class_type;
    typedef path_classification_t                           path_classification_type;
    typedef winstl_C_path_classification_results_m_t        path_classification_results_type;
    typedef stlsoft_C_string_slice_m_t                      path_classification_string_slice_type;
    typedef ws_int_t                                        int_type;
    typedef ws_bool_t                                       bool_type;
    typedef HANDLE                                          file_handle_type;
    typedef HINSTANCE                                       module_type;
    typedef DWORD                                           error_type;
    typedef DWORD                                           file_attributes_type;
private:
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1200
    typedef STLSOFT_NS_QUAL(auto_buffer)<char_type>         buffer_type_;
#endif /* compiler */

public: // constants
    enum
    {
        maxPathLength = WINSTL_CONST_MAX_PATH   //!< The maximum length of a path for the current file system
    };

    enum
    {
        pathComparisonIsCaseSensitive = false
    };

public: // general string handling
    static int_type str_fs_compare(char_type const* s1, char_type const* s2)
    {
        return str_compare_no_case(s1, s2);
    }

    static int_type str_fs_n_compare(char_type const* s1, char_type const* s2, size_type len)
    {
        return str_n_compare_no_case(s1, s2, len);
    }

public: // directory-end
    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type const len = str_len(dir);

        return ensure_dir_end(dir, len, 0, NULL);
    }

    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    ,   size_type   len
    ,   size_type   capacity
    ,   size_type*  pLenToIncrease
    )
    {
        WINSTL_ASSERT(0 == len || NULL != dir);
        WINSTL_ASSERT(0 == capacity || len < capacity);

        size_type dummy;

        if (NULL == pLenToIncrease)
        {
            pLenToIncrease = &dummy;
        }

        if (0 != len)
        {
            char_type last = dir[len - 1];

            if (!is_path_name_separator(last))
            {
                if (0 == capacity)
                {
                    dir[len + 0]    =   path_name_separator();
                    dir[len + 1]    =   char_type(0);

                    ++*pLenToIncrease;
                }
                else
                {
                    if (len + 0 < capacity)
                    {
                        dir[len + 0]    =   path_name_separator();

                        ++*pLenToIncrease;
                    }
                    if (len + 1 < capacity)
                    {
                        dir[len + 1]    =   char_type(0);
                    }
                }
            }
        }

        return dir;
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    ensure_dir_end(
        T_resizeableBuffer& rb
    )
    {
        if (!has_dir_end(rb))
        {
            size_type const n = rb.size();

            if (0 != n)
            {
                if (!resizeable_buffer_resize(rb, n + 1))
                {
                    return 0;
                }

                rb[n - 1]   =   path_name_separator();
                rb[n - 0]   =   char_type(0);
            }
        }

        return rb.empty() ? 0 : rb.size() - 1;
    }

    static
    bool_type
    has_dir_end(
        char_type const*    dir
    ,   size_type           len
    )
    {
        WINSTL_ASSERT(0 == len || NULL != dir);

        switch (len)
        {
        case 0:

            return false;
        case 1:

            return is_path_name_separator(dir[0]);
        default:

            if (char_type(0) == dir[len - 1])
            {
                return is_path_name_separator(dir[len - 2]);
            }
            else
            {
                return is_path_name_separator(dir[len - 1]);
            }
        }
    }

    static
    bool_type
    has_dir_end(
        char_type const*    dir
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type const len = str_len(dir);

        return has_dir_end(dir, len);
    }

    // required to disambiguate from resizeable-buffer overload
    static
    bool_type
    has_dir_end(
        char_type* dir
    )
    {
        return has_dir_end(const_cast<char_type const*>(dir));
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    bool_type
    has_dir_end(
        T_resizeableBuffer const& rb
    )
    {
        if (rb.size() < 2)
        {
            return false;
        }

        return is_path_name_separator(rb[rb.size() - 2]);
    }

    static
    char_type*
    remove_dir_end(
        char_type*  dir
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type const len = str_len(dir);

        return remove_dir_end(dir, len, NULL);
    }

    static
    char_type*
    remove_dir_end(
        char_type*  dir
    ,   size_type   len
    ,   size_type*  pLenToDecrease
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type dummy;

        if (NULL == pLenToDecrease)
        {
            pLenToDecrease = &dummy;
        }

        if (0 != len)
        {
            char_type& last = dir[len - 1];

            if (is_path_name_separator(last))
            {
                last = char_type(0);

                --*pLenToDecrease;
            }
        }

        return dir;
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    remove_dir_end(
        T_resizeableBuffer& rb
    )
    {
        if (has_dir_end(rb))
        {
            size_type const n = rb.size();

            if (!resizeable_buffer_resize(rb, n - 1))
            {
                return 0;
            }

            rb[n - 2] = char_type(0);
        }

        return rb.empty() ? 0 : rb.size() - 1;
    }

public: // path classification and analysis
    static
    path_classification_t
    path_classify(
        char_type const*                    path
    ,   size_t                              len
    ,   int                                 parseFlags
    ,   path_classification_results_type*   results
    )
    {
        return winstl_C_path_classify(path, len, parseFlags, results);
    }

    static
    path_classification_t
    path_classify_root(
        char_type const*                        path
    ,   size_t                                  len
    ,   int                                     parseFlags
    ,   path_classification_string_slice_type*  root
    )
    {
        return winstl_C_path_classify_root(path, len, parseFlags, root);
    }

    static
    bool
    path_is_rooted(
        path_classification_t               pc
    )
    {
        return 0 != winstl_C_path_is_rooted(pc);
    }

    static
    bool
    path_is_absolute(
        path_classification_t               pc
    )
    {
        return 0 != winstl_C_path_is_absolute(pc);
    }

    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    )
    {
        WINSTL_ASSERT(NULL != path);

        return winstl_C_find_last_path_name_separator(path);
    }

    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    {
        WINSTL_ASSERT(0 == len || NULL != path);

        return winstl_C_find_last_path_name_separator_len(path, len);
    }

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    )
    {
        WINSTL_ASSERT(NULL != path);

        return winstl_C_find_first_path_name_separator(path);
    }

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    {
        WINSTL_ASSERT(0 == len || NULL != path);

        return winstl_C_find_first_path_name_separator_len(path, len);
    }

    static bool_type is_dots(char_type const* dir)
    {
        WINSTL_ASSERT(NULL != dir);

        if ('.' == dir[0])
        {
            if ('\0' == dir[1])
            {
                // found "."
                return true;
            }

            if ('.' == dir[1])
            {
                if ('\0' == dir[2])
                {
                    // found ".."
                    return true;
                }
            }
        }

        return false;
    }

    static bool_type starts_with_dots(char_type const* dir)
    {
        WINSTL_ASSERT(NULL != dir);

        if ('.' == dir[0])
        {
            if ('\0' == dir[1])
            {
                return true;
            }

            if (is_path_name_separator(dir[1]))
            {
                return true;
            }

            if ('.' == dir[1])
            {
                if ('\0' == dir[2])
                {
                    return true;
                }

                if (is_path_name_separator(dir[2]))
                {
                    return true;
                }
            }
        }

        return false;
    }

    static bool_type is_path_rooted(char_type const* path)
    {
        WINSTL_ASSERT(NULL != path);

        return is_path_name_separator(*path) || is_path_absolute(path);
    }

    static bool_type is_path_rooted(
        char_type const*    path
    ,   size_t              len
    )
    {
        return (0 != len && is_path_name_separator(*path)) || is_path_absolute(path, len);
    }

    static bool_type is_path_absolute(char_type const* path)
    {
        WINSTL_ASSERT(NULL != path);

        return is_path_absolute(path, str_len(path));
    }

    static bool_type is_path_absolute(
        char_type const*    path
    ,   size_t              len
    )
    {
        if (is_path_UNC(path, len))
        {
            return true;
        }

        if (len >= 3)
        {
            if (isalpha(path[0]) &&
                ':' == path[1] &&
                is_path_name_separator(path[2]))
            {
                return true;
            }
        }

        return false;
    }

    static bool_type is_path_UNC(char_type const* path)
    {
        WINSTL_ASSERT(NULL != path);

        return ('\\' == path[0] && '\\' == path[1]);
    }

    static bool_type is_path_UNC(
        char_type const*    path
    ,   size_t              len
    )
    {
        switch (len)
        {
            case    0:
            case    1:
                return false;
            default:
                return '\\' == path[0] && '\\' == path[1];
        }
    }

private:
    // Determines whether the given path is a properly-formed drive:
    //
    //  "X:\"
    //
    static
    bool_type
    is_root_drive_(
        char_type const*    path
    ,   size_type           len
    )
    {
        if (3 == len)
        {
            if (isalpha(path[0]) &&
                ':' == path[1] &&
                is_path_name_separator(path[2]))
            {
                return true;
            }
        }

        return false;
    }
    // Determines whether the given path is a UNC root:
    //
    //  "\\"
    //
    static
    bool_type
    is_root_UNC_(
        char_type const*    path
    ,   size_type           len
    )
    {
        if (len < 2)
        {
            return false;
        }
        else if (L'\\' != path[0])
        {
            return false;
        }
        else if (L'\\' != path[1])
        {
            return false;
        }
        else if (2 == len)
        {
            // "\\"

            return true;
        }
        else if (len < 4)
        {
            return false;
        }
        else
        {
            char_type const*    svr =   path + 2;
            size_type           rem =   len - 2;

            if (ss_nullptr_k != stlsoft::c_string::strnchr(svr, rem, '?'))
            {
                return false;
            }

            // now only have to be concerned with
            //
            // - "\\svr\share\";


            // we've skipped past either "\\", so search for
            // next '\'

            char_type const* shr = stlsoft::c_string::strnchr(svr, rem, '\\');

            if (ss_nullptr_k != shr)
            {
                if (ss_nullptr_k != shr)
                {
                    ++shr;
                    rem -=  size_type(shr - svr);

                    char_type const* sl = stlsoft::c_string::strnpbrkn(shr, rem, "\\/", 2);

                    if (ss_nullptr_k != sl)
                    {
                        size_type const n3 = size_type(sl - shr);

                        rem -= n3;

                        if (1 == rem)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
    // Determines whether the given path is a directory root:
    //
    //  "\"
    //
    // or:
    //
    //  "/"
    //
    static
    bool_type
    is_root_directory_(
        char_type const*    path
    ,   size_type           len
    )
    {
        if (1 == len)
        {
            if (is_path_name_separator(path[0]))
            {
                return true;
            }
        }

        return false;
    }
public:
    static
    bool_type
    is_root_designator(
        char_type const*    path
    )
    {
        WINSTL_ASSERT(NULL != path);

        size_type const len = str_len(path);

        return is_root_designator(path, len);
    }
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    static
    bool_type
    is_root_designator(
        char_type const*    path
    ,   size_t              cchPath
    )
    {
        WINSTL_ASSERT(0 == cchPath || NULL != path);

        if (is_root_directory_(path, cchPath))
        {
            return true;
        }

        if (is_root_drive_(path, cchPath))
        {
            return true;
        }

        if (is_root_UNC_(path, cchPath))
        {
            return true;
        }

        return false;
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    static bool_type is_path_name_separator(char_type ch)
    {
        return '\\' == ch || '/' == ch;
    }

    static char_type path_separator()
    {
        return ';';
    }

    static char_type path_name_separator()
    {
        return '\\';
    }

    static char_type const* pattern_all()
    {
        return "*.*";
    }

    static size_type path_max()
    {
        return WINSTL_CONST_MAX_PATH;
    }

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    ,   char_type**         ppFile
    )
    {
        WINSTL_MESSAGE_ASSERT("GetFullPathNameW() will crash when the file-name and buffer parameters are the same, so it's not a good idea to do this for ANSI compilation", fileName != buffer);

        if ('"' == *fileName)
        {
            // This can only work if ...
            size_type const         len     =   class_type::str_len(fileName);
            char_type const* const  closing =   class_type::str_chr(fileName + 1, '"');

            // ... 1. the only other double quote is at the end of the string, and ...
            if (NULL != closing &&
                closing - fileName == static_cast<ws_ptrdiff_t>(len - 1))
            {
                size_type res = class_type::get_full_path_name(fileName + 1, cchBuffer, buffer, ppFile);

                // ... 2. the front-quote skipped string can be converted, and ...
                if (0 != res &&
                    res < cchBuffer)
                {
                    WINSTL_ASSERT('\0' == buffer[res]);

                    char_type* const closing2 = class_type::str_chr(buffer, '"');

                    // ... 3. the front-quote skipped converted string contains a single trailing quote
                    if (NULL != closing2 &&
                        closing2 - buffer == static_cast<ws_ptrdiff_t>(res - 1))
                    {
                        buffer[res-- - 1] = '\0';

                        return res;
                    }
                }
            }
        }

        return WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameA(fileName, cchBuffer, buffer, ppFile);
    }
#else /* ? compiler */
private:
    static
    size_type
    get_full_path_name_impl2(
        char_type const*    fileName
    ,   size_type           len
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    ,   char_type**         ppFile
    )
    {
        size_type r = class_type::GetFullPathNameA(fileName, cchBuffer, buffer, ppFile);

        if (0 != r &&
            NULL != buffer &&
            r > cchBuffer)
        {
            buffer_type_    buffer_(1 + r);

            if (0 == buffer_.size())
            {
                *ppFile = NULL;

                return 0;
            }
            else
            {
                char_type*  pFile2;
                size_type   r2 = get_full_path_name_impl2(fileName, len, &buffer_[0], buffer_.size(), &pFile2);

                if (0 == r2)
                {
                    return 0;
                }
                else
                {
                    if (r2 > cchBuffer)
                    {
                        r2 = cchBuffer;
                    }

                    STLSOFT_API_INTERNAL_memfns_memcpy(&buffer[0], &buffer_[0], sizeof(char_type) * r2);
                    if (NULL != pFile2 &&
                        r2 == (r - 1) &&
                        static_cast<size_type>(pFile2 - &buffer_[0]) < r2)
                    {
                        *ppFile = &buffer[0] + (pFile2 - &buffer_[0]);
                    }
                    else
                    {
                        *ppFile = NULL;
                    }

                    return r2;
                }
            }
        }
        else
        {
#if 0
            DWORD dw = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

            if (0 == r &&
                0 == dw &&
                str_len(fileName) > WINSTL_CONST_MAX_PATH)
            {
                WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_FILENAME_EXCED_RANGE);
            }
#endif /* 0 */

            return r;
        }
    }

    static
    size_type
    get_full_path_name_impl(
        char_type const*    fileName
    ,   size_type           len
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    ,   char_type**         ppFile
    )
    {
        WINSTL_ASSERT(len > 0);

        if ('\0' != fileName[len])
        {
            buffer_type_    fileName_(1 + (len - 1));

            // May be being compiled absent exception support, so need to check the
            // file path buffers. (This _could_ be done with a compile-time #ifdef,
            // but it's best not, since some translators support exceptions but yet
            // don't throw on mem exhaustion, and in any case a user could change
            // ::new)
            if (0 == fileName_.size())
            {
                set_last_error(ERROR_OUTOFMEMORY);

                return 0;
            }
            else
            {
                fileName_[len] = '\0';

                return get_full_path_name_impl(
                    static_cast<char_type*>(STLSOFT_API_INTERNAL_memfns_memcpy(&fileName_[0], fileName, sizeof(char_type) * len))
                ,   len
                ,   buffer
                ,   cchBuffer
                ,   ppFile
                );
            }
        }
        else
        {
            return get_full_path_name_impl2(fileName, len, buffer, cchBuffer, ppFile);
        }
    }

public:
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    ,   char_type**         ppFile
    )
    {
        WINSTL_MESSAGE_ASSERT("GetFullPathNameW() will crash when the file-name and buffer parameters are the same, so it's not a good idea to do this for ANSI compilation", fileName != buffer);

        size_type       n   =   0;
        size_type const len =   class_type::str_len(fileName);

        if (NULL != class_type::str_pbrk(fileName, "<>|*?"))
        {
            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INVALID_NAME);

            return 0;
        }

        if ('"' == *fileName)
        {
            // This can only work if:
            //
            // - the only other double-quote is at the end of the string
            // - the unquoted form successfully converts
            char_type const* const closing = class_type::str_chr(fileName + 1, '"');

            if (NULL == closing ||
                static_cast<size_type>(closing - fileName) != len - 1)
            {
                set_last_error(ERROR_INVALID_DATA);
            }
            else
            {
                size_type   r;

                if (NULL == buffer)
                {
                    r = get_full_path_name_impl(fileName, len, NULL, 0, ppFile);

                    if (0 != r)
                    {
                        n = 2 + r;
                    }
                }
                else if (cchBuffer == 0)
                {
                    n = 0;
                    *ppFile = NULL;
                }
                else if (cchBuffer == 1)
                {
                    // Have to check it's valid
                    r = get_full_path_name_impl(fileName, len, NULL, 0, ppFile);

                    if (0 != r)
                    {
                        buffer[0] = '"';
                        n = 1;
                        *ppFile = NULL;
                    }
                }
                else
                {
                    r = get_full_path_name_impl(fileName + 1, len - 2, buffer + 1, cchBuffer - 1, ppFile);

                    if (0 != r)
                    {
                        // Write the first quote character into the buffer
                        buffer[0] = '"';

                        if (r + 1 < cchBuffer)
                        {
                            // There's enough space for the result and the closing quote
                            buffer[r + 1] = '"';

                            if (r + 2 < cchBuffer)
                            {
                                // There's enough space for the result and the closing quote and the nul-terminator
                                buffer[r + 2] = '\0';

                                n = r + 2;
                            }
                            else
                            {
                                n = r + 2;
                            }
                        }
                        else
                        {
                            n = r + 1;
                        }
                    }
                }
            }
        }
        else
        {
            n = get_full_path_name_impl(fileName, len, buffer, cchBuffer, ppFile);
        }

        // Paths that exceed _MAX_PATH (aka WINSTL_CONST_MAX_PATH) cause GetFullPathNameA() to fail, but it
        // does not (appear to) call SetLastError()
        if (0 == n &&
            0 == WINSTL_API_EXTERNAL_ErrorHandling_GetLastError() &&
            str_len(fileName) > WINSTL_CONST_MAX_PATH)
        {
            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_FILENAME_EXCED_RANGE);
        }

        return n;
    }
#endif /* compiler */

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        WINSTL_ASSERT(NULL != fileName);

        char_type* pFile;

        if ('\0' == *fileName)
        {
            static const char   s_dot[2] = { '.', '\0' };

            fileName = s_dot;
        }

        return get_full_path_name(fileName, cchBuffer, buffer, &pFile);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_full_path_name(fileName, static_cast<char_type*>(NULL), 0);

        if (!resizeable_buffer_resize(rb, cchRequired))
        {
            return 0;
        }

        return get_full_path_name(fileName, &rb[0], rb.size());
    }

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    )
    {
        return get_full_path_name(fileName, buffer, cchBuffer);
    }

    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    )
    {
        return class_type::GetShortPathNameA(fileName, buffer, cchBuffer);
    }
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        return class_type::GetShortPathNameA(fileName, buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_short_path_name(fileName, static_cast<char_type*>(NULL), 0);

        if (!resizeable_buffer_resize(rb, cchRequired))
        {
            return 0;
        }

        return get_short_path_name(fileName, &rb[0], rb.size());
    }

public: // file-system enumeration
    static HANDLE find_first_file(char_type const* spec, find_data_type* findData)
    {
        return WINSTL_API_EXTERNAL_FileManagement_FindFirstFileA(spec, findData);
    }

#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0400
    static HANDLE find_first_file_ex(char_type const* spec, FINDEX_SEARCH_OPS flags, find_data_type* findData)
    {
        return WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExA(spec, FindExInfoStandard, findData, flags, NULL, 0);
    }
#endif /* _WIN32_WINNT >= 0x0400 */

    static bool_type find_next_file(HANDLE h, find_data_type* findData)
    {
        return WINSTL_API_EXTERNAL_FileManagement_FindNextFileA(h, findData) != FALSE;
    }

    static void find_file_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        WINSTL_API_EXTERNAL_FileManagement_FindClose(h);
    }

#ifndef WINSTL_FINDVOLUME_API_NOT_DECLARED

    static HANDLE find_first_volume(char_type* volume_name, size_type cch_volume_name)
    {
        return class_type::FindFirstVolumeA(volume_name, cch_volume_name);
    }

    static bool_type find_next_volume(HANDLE h, char_type* volume_name, size_type cch_volume_name)
    {
        return class_type::FindNextVolumeA(h, volume_name, cch_volume_name) != FALSE;
    }

    static void find_volume_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        WINSTL_API_EXTERNAL_FileManagement_FindVolumeClose(h);
    }
#endif // !WINSTL_FINDVOLUME_API_NOT_DECLARED

public: // file-system control
    static
    bool_type
    set_current_directory(
        char_type const*    dir
    )
    {
        return WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryA(dir) != FALSE;
    }

    static
    size_type
    get_current_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        return class_type::GetCurrentDirectoryA(cchBuffer, buffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_current_directory(
        T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_current_directory(static_cast<char_type*>(NULL), 0);

        if (!resizeable_buffer_resize(rb, cchRequired))
        {
            return 0;
        }

        return get_current_directory(&rb[0], rb.size());
    }

    static
    size_type
    get_current_directory(
        size_type   cchBuffer
    ,   char_type   buffer[]
    )
    {
        return class_type::get_current_directory(buffer, cchBuffer);
    }

public: // file-system state
    static bool_type file_exists(char_type const* fileName)
    {
        return INVALID_FILE_ATTRIBUTES != WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA(fileName);
    }

    static bool_type is_file(char_type const* path)
    {
        DWORD   attr = WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA(path);

        return INVALID_FILE_ATTRIBUTES != attr && 0 == (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

    static bool_type is_directory(char_type const* path)
    {
        DWORD   attr = WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA(path);

        return INVALID_FILE_ATTRIBUTES != attr && 0 != (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

private:
    static bool_type stat_direct_(char_type const* path, stat_data_type* stat_data)
    {
        WINSTL_ASSERT(NULL != stat_data);

        size_type const len = (NULL == path) ? 0u : str_len(path);

        if (0 == len)
        {
            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INVALID_NAME);

            return false;
        }

        if (is_root_drive_(path, len))
        {
            stat_data->dwFileAttributes                 =   WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA(path);
            stat_data->ftCreationTime.dwLowDateTime     =   0;
            stat_data->ftCreationTime.dwHighDateTime    =   0;
            stat_data->ftLastAccessTime.dwLowDateTime   =   0;
            stat_data->ftLastAccessTime.dwHighDateTime  =   0;
            stat_data->ftLastWriteTime.dwLowDateTime    =   0;
            stat_data->ftLastWriteTime.dwHighDateTime   =   0;
            stat_data->nFileSizeHigh                    =   0;
            stat_data->nFileSizeLow                     =   0;
            { for (size_type i = 0; i < 4; ++i)
            {
                stat_data->cFileName[i]             =   path[i];
                stat_data->cAlternateFileName[i]    =   path[i];
            }}

            return INVALID_FILE_ATTRIBUTES != stat_data->dwFileAttributes;
        }

        WINSTL_ASSERT(NULL != path);

        HANDLE h = find_first_file(path, stat_data);

        return (INVALID_HANDLE_VALUE == h) ? false : (find_file_close(h), true);
    }
public:
    static bool_type stat(char_type const* path, stat_data_type* stat_data)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(NULL != stat_data);

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1200

        size_type const len         =   class_type::str_len(path);
        bool_type       bTryEndTest =   false;

        if (is_path_absolute(path))
        {
            if (len > 4)
            {
                bTryEndTest = true;
            }
        }
        else if (is_path_rooted(path))
        {
            if (len > 3)
            {
                bTryEndTest = true;
            }
        }
        else if (len > 2)
        {
            bTryEndTest = true;
        }

        if (bTryEndTest &&
            class_type::has_dir_end(path + len - 2))
        {
            typedef STLSOFT_NS_QUAL(auto_buffer)<char_type> buffer_t;

            WINSTL_ASSERT(len > 2);

            buffer_t    buffer(1 + len);

            if (0 == buffer.size())
            {
                return false;
            }
            else
            {
                WINSTL_ASSERT(len > 0);

                STLSOFT_API_INTERNAL_memfns_memcpy(&buffer[0], path, sizeof(char_type) * (len - 1));

                buffer[len - 1] = '\0';

                return class_type::stat_direct_(buffer.data(), stat_data);
            }
        }
        else
#endif /* compiler */
        {
            return stat_direct_(path, stat_data);
        }
    }

    static bool_type fstat(file_handle_type fd, fstat_data_type* fstat_data)
    {
        return filesystem_traits_::fstat(fd, fstat_data);
    }

    static bool_type get_file_attributes(char_type const* path, file_attributes_type* attr)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(NULL != attr);

        *attr = WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesA(path);

        return INVALID_FILE_ATTRIBUTES != *attr;
    }
    static bool_type set_file_attributes(char_type const* path, file_attributes_type const attr)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(INVALID_FILE_ATTRIBUTES != attr);

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesA(path, attr);
    }

#if 0
    /// \pre (NULL != path);
    /// \pre (INVALID_FILE_ATTRIBUTES != attr);
#endif

    static bool_type is_file(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_directory(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_link(stat_data_type const*  /* stat_data */)
    {
        return false;
    }
    static bool_type is_readonly(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

    static bool_type is_file(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_file(stat_data);
    }
    static bool_type is_directory(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_directory(stat_data);
    }
    static bool_type is_link(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_link(stat_data);
    }
    static bool_type is_readonly(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_readonly(stat_data);
    }

    static bool_type drive_exists(char_type driveLetter)
    {
        WINSTL_ASSERT(STLSOFT_NS_GLOBAL(IsCharAlphaA)(driveLetter));

        const DWORD drivesBitmap    =   WINSTL_API_EXTERNAL_FileManagement_GetLogicalDrives();
        const int   driveOrdinal    =   (driveLetter - (STLSOFT_NS_GLOBAL(IsCharUpperA)(driveLetter) ? 'A' : 'a'));

        return 0 != ((0x01 << driveOrdinal) & drivesBitmap);
    }

    static DWORD get_drive_type(char_type driveLetter)
    {
        WINSTL_ASSERT(STLSOFT_NS_GLOBAL(IsCharAlphaA)(driveLetter));

        char_type   drive[] = { '?', ':', '\\', '\0' };

        return (drive[0] = driveLetter, WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeA(drive));
    }

public: // file-system control
    static bool_type    create_directory(char_type const* dir)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryA(dir, NULL);
    }

    static bool_type    create_directory(char_type const* dir, LPSECURITY_ATTRIBUTES lpsa)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryA(dir, lpsa);
    }

    static bool_type    remove_directory(char_type const* dir)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryA(dir);
    }

    static bool_type    unlink_file(char_type const* file)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_DeleteFileA(file);
    }

    static bool_type    delete_file(char_type const* file)
    {
        return unlink_file(file);
    }

    static bool_type    rename_file(char_type const* currentName, char_type const* newName)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_MoveFileA(currentName, newName);
    }

    static bool_type    copy_file(char_type const* sourceName, char_type const* newName, bool_type bFailIfExists = false)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_CopyFileA(sourceName, newName, bFailIfExists);
    }

    static file_handle_type invalid_file_handle_value()
    {
        return INVALID_HANDLE_VALUE;
    }

    static file_handle_type create_file(char_type const* fileName, ws_uint32_t desiredAccess, ws_uint32_t shareMode, LPSECURITY_ATTRIBUTES sa, ws_uint32_t creationDisposition, ws_uint32_t flagAndAttributes, file_handle_type hTemplateFile)
    {
        return WINSTL_API_EXTERNAL_FileManagement_CreateFileA(fileName, desiredAccess, shareMode, sa, creationDisposition, flagAndAttributes, hTemplateFile);
    }

    static bool_type close_file(file_handle_type h)
    {
        return filesystem_traits_::close_handle(h);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static large_size_type get_file_size(file_handle_type h)
    {
        return filesystem_traits_::get_file_size(h);
    }
    static large_size_type get_file_size(stat_data_type const& sd)
    {
        ws_uint64_t size;

        size    =   sd.nFileSizeHigh;
        size    <<= 32;
        size    +=  sd.nFileSizeLow;

        return size;
    }
    static large_size_type get_file_size(stat_data_type const* psd)
    {
        WINSTL_ASSERT(NULL != psd);

        return get_file_size(*psd);
    }
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
private:
    static void         get_file_size(stat_data_type const*);
    static void         get_file_size(stat_data_type const&);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

private:
    static size_type GetFullPathNameA(char_type const* fileName, size_type cchBuffer, char_type buffer[], char_type** ppFile)
    {
        WINSTL_ASSERT(NULL != fileName);

        size_type result;

#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        result = WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameA(fileName, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer), buffer, ppFile);
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        result = WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameA(fileName, static_cast<DWORD>(cchBuffer), buffer, ppFile);
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        result = WINSTL_API_EXTERNAL_FileManagement_GetFullPathNameA(fileName, cchBuffer, buffer, ppFile);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        if (0 == result)
        {
            size_type requiredLen = 0;

            requiredLen += str_len(fileName);

            if (!is_path_rooted(fileName))
            {
                size_type cwdLen = WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA(0, NULL);

                requiredLen += cwdLen;
            }

            if (requiredLen >= maxPathLength)
            {
                WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_FILENAME_EXCED_RANGE);
            }
        }

        return result;
    }

    static size_type GetShortPathNameA(char_type const* fileName, char_type buffer[], size_type cchBuffer)
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameA(fileName, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameA(fileName, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameA(fileName, buffer, cchBuffer);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static HANDLE FindFirstVolumeA(char_type* volume_name, size_type cch_volume_name)
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeA(volume_name, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cch_volume_name));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cch_volume_name));

        return WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeA(volume_name, static_cast<DWORD>(cch_volume_name));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeA(volume_name, cch_volume_name);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }
    static bool_type FindNextVolumeA(HANDLE h, char_type* volume_name, size_type cch_volume_name)
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeA(h, volume_name, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cch_volume_name));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cch_volume_name));

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeA(h, volume_name, static_cast<DWORD>(cch_volume_name));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeA(h, volume_name, cch_volume_name);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetCurrentDirectoryA(size_type cchBuffer, char_type buffer[])
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA(STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer), buffer);
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA(static_cast<DWORD>(cchBuffer), buffer);
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA(cchBuffer, buffer);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<ws_char_w_t>
    : public system_traits<ws_char_w_t>
{
public: // types
    typedef ws_char_w_t                                     char_type;
    typedef ws_size_t                                       size_type;
    typedef ws_uint64_t                                     large_size_type;
    typedef ws_ptrdiff_t                                    difference_type;
    typedef WIN32_FIND_DATAW                                find_data_type;
    typedef WIN32_FIND_DATAW                                stat_data_type;
    typedef BY_HANDLE_FILE_INFORMATION                      fstat_data_type;
    typedef filesystem_traits<char_type>                    class_type;
    typedef path_classification_t                           path_classification_type;
    typedef winstl_C_path_classification_results_w_t        path_classification_results_type;
    typedef stlsoft_C_string_slice_w_t                      path_classification_string_slice_type;
    typedef ws_int_t                                        int_type;
    typedef ws_bool_t                                       bool_type;
    typedef HANDLE                                          file_handle_type;
    typedef HINSTANCE                                       module_type;
    typedef DWORD                                           error_type;
    typedef DWORD                                           file_attributes_type;
private:
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1200
    typedef STLSOFT_NS_QUAL(auto_buffer)<char_type>         buffer_type_;
#endif /* compiler */

public: // constants
    enum
    {
        maxPathLength = CONST_NT_MAX_PATH   //!< The maximum length of a path for the current file system
    };

public: // general string handling
    static int_type str_fs_compare(char_type const* s1, char_type const* s2)
    {
        return str_compare_no_case(s1, s2);
    }

    static int_type str_fs_n_compare(char_type const* s1, char_type const* s2, size_type len)
    {
        return str_n_compare_no_case(s1, s2, len);
    }

public: // directory-end
    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type const len = str_len(dir);

        return ensure_dir_end(dir, len, 0, NULL);
    }

    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    ,   size_type   len
    ,   size_type   capacity
    ,   size_type*  pLenToIncrease
    )
    {
        WINSTL_ASSERT(0 == len || NULL != dir);
        WINSTL_ASSERT(0 == capacity || len < capacity);

        size_type dummy;

        if (NULL == pLenToIncrease)
        {
            pLenToIncrease = &dummy;
        }

        if (0 != len)
        {
            char_type last = dir[len - 1];

            if (!is_path_name_separator(last))
            {
                if (0 == capacity)
                {
                    dir[len + 0]    =   path_name_separator();
                    dir[len + 1]    =   char_type(0);

                    ++*pLenToIncrease;
                }
                else
                {
                    if (len + 0 < capacity)
                    {
                        dir[len + 0]    =   path_name_separator();

                        ++*pLenToIncrease;
                    }
                    if (len + 1 < capacity)
                    {
                        dir[len + 1]    =   char_type(0);
                    }
                }
            }
        }

        return dir;
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    ensure_dir_end(
        T_resizeableBuffer& rb
    )
    {
        if (!has_dir_end(rb))
        {
            size_type const n = rb.size();

            if (0 != n)
            {
                if (!resizeable_buffer_resize(rb, n + 1))
                {
                    return 0;
                }

                rb[n - 1]   =   path_name_separator();
                rb[n - 0]   =   char_type(0);
            }
        }

        return rb.empty() ? 0 : rb.size() - 1;
    }

    static
    bool_type
    has_dir_end(
        char_type const*    dir
    ,   size_type           len
    )
    {
        WINSTL_ASSERT(0 == len || NULL != dir);

        switch (len)
        {
        case 0:

            return false;
        case 1:

            return is_path_name_separator(dir[0]);
        default:

            if (char_type(0) == dir[len - 1])
            {
                return is_path_name_separator(dir[len - 2]);
            }
            else
            {
                return is_path_name_separator(dir[len - 1]);
            }
        }
    }

    static
    bool_type
    has_dir_end(
        char_type const*    dir
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type const len = str_len(dir);

        return has_dir_end(dir, len);
    }

    // required to disambiguate from resizeable-buffer overload
    static
    bool_type
    has_dir_end(
        char_type*  dir
    )
    {
        return has_dir_end(const_cast<char_type const*>(dir));
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    bool_type
    has_dir_end(
        T_resizeableBuffer const& rb
    )
    {
        if (rb.size() < 2)
        {
            return false;
        }

        return is_path_name_separator(rb[rb.size() - 2]);
    }

    static
    char_type*
    remove_dir_end(
        char_type*  dir
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type const len = str_len(dir);

        return remove_dir_end(dir, len, NULL);
    }

    static
    char_type*
    remove_dir_end(
        char_type*  dir
    ,   size_type   len
    ,   size_type*  pLenToDecrease
    )
    {
        WINSTL_ASSERT(NULL != dir);

        size_type dummy;

        if (NULL == pLenToDecrease)
        {
            pLenToDecrease = &dummy;
        }

        if (0 != len)
        {
            char_type& last = dir[len - 1];

            if (is_path_name_separator(last))
            {
                last = char_type(0);

                --*pLenToDecrease;
            }
        }

        return dir;
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    remove_dir_end(
        T_resizeableBuffer& rb
    )
    {
        if (has_dir_end(rb))
        {
            size_type const n = rb.size();

            if (!resizeable_buffer_resize(rb, n - 1))
            {
                return 0;
            }

            rb[n - 2] = char_type(0);
        }

        return rb.empty() ? 0 : rb.size() - 1;
    }

public: // path classification and analysis
    static
    path_classification_t
    path_classify(
        char_type const*                    path
    ,   size_t                              len
    ,   int                                 parseFlags
    ,   path_classification_results_type*   results
    )
    {
        return winstl_C_path_classify(path, len, parseFlags, results);
    }

    static
    path_classification_t
    path_classify_root(
        char_type const*                        path
    ,   size_t                                  len
    ,   int                                     parseFlags
    ,   path_classification_string_slice_type*  root
    )
    {
        return winstl_C_path_classify_root(path, len, parseFlags, root);
    }

    static
    bool
    path_is_rooted(
        path_classification_t               pc
    )
    {
        return 0 != winstl_C_path_is_rooted(pc);
    }

    static
    bool
    path_is_absolute(
        path_classification_t               pc
    )
    {
        return 0 != winstl_C_path_is_absolute(pc);
    }

    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    )
    {
        WINSTL_ASSERT(NULL != path);

        return winstl_C_find_last_path_name_separator(path);
    }

    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    {
        WINSTL_ASSERT(0 == len || NULL != path);

        return winstl_C_find_last_path_name_separator_len(path, len);
    }

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    )
    {
        WINSTL_ASSERT(NULL != path);

        return winstl_C_find_first_path_name_separator(path);
    }

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    {
        WINSTL_ASSERT(0 == len || NULL != path);

        return winstl_C_find_first_path_name_separator_len(path, len);
    }

    static bool_type is_dots(char_type const* dir)
    {
        WINSTL_ASSERT(NULL != dir);

        if (L'.' == dir[0])
        {
            if (L'\0' == dir[1])
            {
                // found L"."
                return true;
            }

            if (L'.' == dir[1])
            {
                if (L'\0' == dir[2])
                {
                    // found L".."
                    return true;
                }
            }
        }

        return false;
    }

    static bool_type starts_with_dots(char_type const* dir)
    {
        WINSTL_ASSERT(NULL != dir);

        if (L'.' == dir[0])
        {
            if (L'\0' == dir[1])
            {
                return true;
            }

            if (is_path_name_separator(dir[1]))
            {
                return true;
            }

            if (L'.' == dir[1])
            {
                if (L'\0' == dir[2])
                {
                    return true;
                }

                if (is_path_name_separator(dir[2]))
                {
                    return true;
                }
            }
        }

        return false;
    }

    static bool_type is_path_rooted(char_type const* path)
    {
        WINSTL_ASSERT(NULL != path);

        return is_path_name_separator(*path) || is_path_absolute(path);
    }

    static bool_type is_path_rooted(
        char_type const*    path
    ,   size_t              len
    )
    {
        return (0 != len && is_path_name_separator(*path)) || is_path_absolute(path, len);
    }

    static bool_type is_path_absolute(char_type const* path)
    {
        WINSTL_ASSERT(NULL != path);

        return is_path_absolute(path, str_len(path));
    }

    static bool_type is_path_absolute(
        char_type const*    path
    ,   size_t              len
    )
    {
        if (is_path_UNC(path, len))
        {
            return true;
        }

        if (len >= 3)
        {
            if (iswalpha(path[0]) &&
                L':' == path[1] &&
                is_path_name_separator(path[2]))
            {
                return true;
            }
        }

        return false;
    }

    static bool_type is_path_UNC(char_type const* path)
    {
        WINSTL_ASSERT(NULL != path);

        return (L'\\' == path[0] && L'\\' == path[1]);
    }

    static bool_type is_path_UNC(
        char_type const*    path
    ,   size_t              len
    )
    {
        switch (len)
        {
            case    0:
            case    1:
                return false;
            case    2:
            default:
                return '\\' == path[0] && '\\' == path[1];
        }
    }

private:
    // Determines whether the given path is a properly-formed drive:
    //
    //  "X:\"
    //
    static
    bool_type
    is_root_drive_(
        char_type const*    path
    ,   size_type           len
    )
    {
        if (3 == len)
        {
            if (iswalpha(path[0]) &&
                L':' == path[1] &&
                is_path_name_separator(path[2]))
            {
                return true;
            }
        }

        return false;
    }
    // Determines whether the given path is a UNC root:
    //
    //  "\\"
    //
    static
    bool_type
    is_root_UNC_(
        char_type const*    path
    ,   size_type           len
    )
    {
        if (len < 2)
        {
            return false;
        }
        else if (L'\\' != path[0])
        {
            return false;
        }
        else if (L'\\' != path[1])
        {
            return false;
        }
        else if (2 == len)
        {
            // "\\"

            return true;
        }
        else if (len < 4)
        {
            return false;
        }
        else
        {
            char_type const*    svr;
            size_type           rem;

            if (L'?' == path[2] &&
                L'\\' == path[3])
            {
                if (7 == len)
                {
                    if (iswalpha(path[4]) &&
                        L':' == path[5] &&
                        is_path_name_separator(path[6]))
                    {
                        // "\\?\X:\" ?

                        return true;
                    }
                }

                svr =   path + 4;
                rem =   len - 4;

                if (ss_nullptr_k != stlsoft::c_string::strnchr(svr, rem, L'/'))
                {
                    return false;
                }
            }
            else
            {
                svr =   path + 2;
                rem =   len - 2;
            }

            // now only have to be concerned with
            //
            // - "\\svr\share\";
            // - "\\?\svr\share\"; and
            // - "\\?\UNC\svr\share\"


            // we've skipped past either "\\" or "\\?\", so search for
            // next '\'

            char_type const* shr = stlsoft::c_string::strnchr(svr, rem, L'\\');

            if (ss_nullptr_k != shr)
            {
                if (3 == shr - svr &&
                    0 == ::wcsncmp(L"UNC", svr, 3))
                {
                    svr +=  3;
                    rem -=  3;

                    shr = stlsoft::c_string::strnchr(svr + 1, rem - 1, L'\\');
                }

                if (ss_nullptr_k != shr)
                {
                    ++shr;
                    rem -=  size_type(shr - svr);

                    char_type const* sl = stlsoft::c_string::strnpbrkn(shr, rem, L"\\/", 2);

                    if (ss_nullptr_k != sl)
                    {
                        size_type const n3 = size_type(sl - shr);

                        rem -= n3;

                        if (1 == rem)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
    // Determines whether the given path is a directory root:
    //
    //  "\"
    //
    // or:
    //
    //  "/"
    //
    static
    bool_type
    is_root_directory_(
        char_type const*    path
    ,   size_type           len
    )
    {
        if (1 == len)
        {
            if (is_path_name_separator(path[0]))
            {
                return true;
            }
        }

        return false;
    }
public:
    static
    bool_type
    is_root_designator(
        char_type const*    path
    )
    {
        WINSTL_ASSERT(NULL != path);

        size_type const len = str_len(path);

        return is_root_designator(path, len);
    }
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    static
    bool_type
    is_root_designator(
        char_type const*    path
    ,   size_t              cchPath
    )
    {
        WINSTL_ASSERT(0 == cchPath || NULL != path);

        if (is_root_directory_(path, cchPath))
        {
            return true;
        }

        if (is_root_drive_(path, cchPath))
        {
            return true;
        }

        if (is_root_UNC_(path, cchPath))
        {
            return true;
        }

        return false;
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    static bool_type is_path_name_separator(char_type ch)
    {
        return L'\\' == ch || L'/' == ch;
    }

    static char_type path_separator()
    {
        return L';';
    }

    static char_type path_name_separator()
    {
        return L'\\';
    }

    static char_type const* pattern_all()
    {
        return L"*.*";
    }

    static size_type path_max()
    {
        return winstl_C_internal_IsWindows9x(NULL, NULL, NULL) ? WINSTL_CONST_MAX_PATH : CONST_NT_MAX_PATH;
    }

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    ,   char_type**         ppFile
    )
    {
        WINSTL_MESSAGE_ASSERT("GetFullPathNameW() will crash when the file-name and buffer parameters are the same", fileName != buffer);

        return class_type::GetFullPathNameW(fileName, cchBuffer, buffer, ppFile);
    }

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        char_type* pFile;

        return get_full_path_name(fileName, cchBuffer, buffer, &pFile);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_full_path_name(fileName, static_cast<char_type*>(NULL), 0);

        if (!resizeable_buffer_resize(rb, cchRequired))
        {
            return 0;
        }

        return get_full_path_name(fileName, &rb[0], rb.size());
    }

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    )
    {
        return get_full_path_name(fileName, buffer, cchBuffer);
    }

    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    )
    {
        return class_type::GetShortPathNameW(fileName, buffer, cchBuffer);
    }
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        return class_type::GetShortPathNameW(fileName, buffer, cchBuffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_short_path_name(fileName, static_cast<char_type*>(NULL), 0);

        if (!resizeable_buffer_resize(rb, cchRequired))
        {
            return 0;
        }

        return get_short_path_name(fileName, &rb[0], rb.size());
    }

public: // file-system enumeration
    static HANDLE find_first_file(char_type const* spec, find_data_type* findData)
    {
        return WINSTL_API_EXTERNAL_FileManagement_FindFirstFileW(spec, findData);
    }

#if defined(_WIN32_WINNT) && \
    _WIN32_WINNT >= 0x0400
    static HANDLE find_first_file_ex(char_type const* spec, FINDEX_SEARCH_OPS flags, find_data_type* findData)
    {
        return WINSTL_API_EXTERNAL_FileManagement_FindFirstFileExW(spec, FindExInfoStandard, findData, flags, NULL, 0);
    }
#endif /* _WIN32_WINNT >= 0x0400 */

    static bool_type find_next_file(HANDLE h, find_data_type* findData)
    {
        return WINSTL_API_EXTERNAL_FileManagement_FindNextFileW(h, findData) != FALSE;
    }

    static void find_file_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        WINSTL_API_EXTERNAL_FileManagement_FindClose(h);
    }

    // FindVolume() API
#ifndef WINSTL_FINDVOLUME_API_NOT_DECLARED

    static HANDLE find_first_volume(char_type* volume_name, size_type cch_volume_name)
    {
        return class_type::FindFirstVolumeW(volume_name, cch_volume_name);
    }

    static bool_type find_next_volume(HANDLE h, char_type* volume_name, size_type cch_volume_name)
    {
        return class_type::FindNextVolumeW(h, volume_name, cch_volume_name) != FALSE;
    }

    static void find_volume_close(HANDLE h)
    {
        WINSTL_ASSERT(INVALID_HANDLE_VALUE != h);

        WINSTL_API_EXTERNAL_FileManagement_FindVolumeClose(h);
    }
#endif // !WINSTL_FINDVOLUME_API_NOT_DECLARED

public: // file-system control
    static
    bool_type
    set_current_directory(
        char_type const*    dir
    )
    {
        return WINSTL_API_EXTERNAL_FileManagement_SetCurrentDirectoryW(dir) != FALSE;
    }

    static
    size_type
    get_current_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
        return class_type::GetCurrentDirectoryW(cchBuffer, buffer);
    }

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_current_directory(
        T_resizeableBuffer& rb
    )
    {
        size_type const cchRequired = get_current_directory(static_cast<char_type*>(NULL), 0);

        if (!resizeable_buffer_resize(rb, cchRequired))
        {
            return 0;
        }

        return get_current_directory(&rb[0], rb.size());
    }

    static
    size_type
    get_current_directory(
        size_type   cchBuffer
    ,   char_type   buffer[]
    )
    {
        return class_type::get_current_directory(buffer, cchBuffer);
    }

public: // file-system state
    static bool_type file_exists(char_type const* fileName)
    {
        return INVALID_FILE_ATTRIBUTES != WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW(fileName);
    }

    static bool_type is_file(char_type const* path)
    {
        DWORD   attr = WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW(path);

        return INVALID_FILE_ATTRIBUTES != attr && 0 == (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

    static bool_type is_directory(char_type const* path)
    {
        DWORD   attr = WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW(path);

        return INVALID_FILE_ATTRIBUTES != attr && 0 != (attr & FILE_ATTRIBUTE_DIRECTORY);
    }

private:
    static bool_type stat_direct_(char_type const* path, stat_data_type* stat_data)
    {
        WINSTL_ASSERT(NULL != stat_data);

        size_type const len = (NULL == path) ? 0u : str_len(path);

        if (0 == len)
        {
            WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INVALID_NAME);

            return false;
        }

        if (is_root_drive_(path, len))
        {
            stat_data->dwFileAttributes                 =   WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW(path);
            stat_data->ftCreationTime.dwLowDateTime     =   0;
            stat_data->ftCreationTime.dwHighDateTime    =   0;
            stat_data->ftLastAccessTime.dwLowDateTime   =   0;
            stat_data->ftLastAccessTime.dwHighDateTime  =   0;
            stat_data->ftLastWriteTime.dwLowDateTime    =   0;
            stat_data->ftLastWriteTime.dwHighDateTime   =   0;
            stat_data->nFileSizeHigh                    =   0;
            stat_data->nFileSizeLow                     =   0;
            { for (size_type i = 0; i < 4; ++i)
            {
                stat_data->cFileName[i]             =   path[i];
                stat_data->cAlternateFileName[i]    =   path[i];
            }}

            return INVALID_FILE_ATTRIBUTES != stat_data->dwFileAttributes;
        }

        WINSTL_ASSERT(NULL != path);

        HANDLE h = find_first_file(path, stat_data);

        return (INVALID_HANDLE_VALUE == h) ? false : (find_file_close(h), true);
    }
public:
    static bool_type stat(char_type const* path, stat_data_type* stat_data)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(NULL != stat_data);

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1200

        size_type const len         =   class_type::str_len(path);
        bool_type       bTryEndTest =   false;

        if (is_path_absolute(path))
        {
            if (len > 4)
            {
                bTryEndTest = true;
            }
        }
        else if (is_path_rooted(path))
        {
            if (len > 3)
            {
                bTryEndTest = true;
            }
        }
        else if (len > 2)
        {
            bTryEndTest = true;
        }

        if (bTryEndTest &&
            class_type::has_dir_end(path + len - 2))
        {
            typedef STLSOFT_NS_QUAL(auto_buffer)<char_type> buffer_t;

            WINSTL_ASSERT(len > 2);

            buffer_t    buffer(1 + len);

            if (0 == buffer.size())
            {
                return false;
            }
            else
            {
                WINSTL_ASSERT(len > 0);

                STLSOFT_API_INTERNAL_memfns_memcpy(&buffer[0], path, sizeof(char_type) * (len - 1));

                buffer[len - 1] = L'\0';

                return class_type::stat_direct_(buffer.data(), stat_data);
            }
        }
        else
#endif /* compiler */
        {
            return stat_direct_(path, stat_data);
        }
    }

    static bool_type fstat(file_handle_type fd, fstat_data_type* fstat_data)
    {
        return filesystem_traits_::fstat(fd, fstat_data);
    }

    static bool_type get_file_attributes(char_type const* path, file_attributes_type* attr)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(NULL != attr);

        *attr = WINSTL_API_EXTERNAL_FileManagement_GetFileAttributesW(path);

        return INVALID_FILE_ATTRIBUTES != *attr;
    }
    static bool_type set_file_attributes(char_type const* path, file_attributes_type const attr)
    {
        WINSTL_ASSERT(NULL != path);
        WINSTL_ASSERT(INVALID_FILE_ATTRIBUTES != attr);

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_SetFileAttributesW(path, attr);
    }

    static bool_type is_file(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY != (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_directory(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_DIRECTORY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    static bool_type is_link(stat_data_type const*  /* stat_data */)
    {
        return false;
    }
    static bool_type is_readonly(stat_data_type const* stat_data)
    {
        return FILE_ATTRIBUTE_READONLY == (stat_data->dwFileAttributes & FILE_ATTRIBUTE_READONLY);
    }

    static bool_type is_file(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_file(stat_data);
    }
    static bool_type is_directory(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_directory(stat_data);
    }
    static bool_type is_link(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_link(stat_data);
    }
    static bool_type is_readonly(fstat_data_type const* stat_data)
    {
        return filesystem_traits_::is_readonly(stat_data);
    }

    static bool_type drive_exists(char_type driveLetter)
    {
        WINSTL_ASSERT(IsCharAlphaW(driveLetter));

        const DWORD drivesBitmap    =   WINSTL_API_EXTERNAL_FileManagement_GetLogicalDrives();
        const int   driveOrdinal    =   (driveLetter - (IsCharUpperW(driveLetter) ? L'A' : L'a'));

        return 0 != ((0x01 << driveOrdinal) & drivesBitmap);
    }

    static DWORD get_drive_type(char_type driveLetter)
    {
        WINSTL_ASSERT(IsCharAlphaW(driveLetter));

        char_type   drive[] = { L'?', L':', L'\\', L'\0' };

        return (drive[0] = driveLetter, WINSTL_API_EXTERNAL_FileManagement_GetDriveTypeW(drive));
    }

public: // file-system control
    static bool_type    create_directory(char_type const* dir)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryW(dir, NULL);
    }

    static bool_type    create_directory(char_type const* dir, LPSECURITY_ATTRIBUTES lpsa)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_CreateDirectoryW(dir, lpsa);
    }

    static bool_type    remove_directory(char_type const* dir)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_RemoveDirectoryW(dir);
    }

    static bool_type    unlink_file(char_type const* file)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_DeleteFileW(file);
    }

    static bool_type    delete_file(char_type const* file)
    {
        return unlink_file(file);
    }

    static bool_type    rename_file(char_type const* currentName, char_type const* newName)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_MoveFileW(currentName, newName);
    }

    static bool_type    copy_file(char_type const* sourceName, char_type const* newName, bool_type bFailIfExists = false)
    {
        return FALSE != WINSTL_API_EXTERNAL_FileManagement_CopyFileW(sourceName, newName, bFailIfExists);
    }

    static file_handle_type invalid_file_handle_value()
    {
        return INVALID_HANDLE_VALUE;
    }

    static file_handle_type create_file(char_type const* fileName, ws_uint32_t desiredAccess, ws_uint32_t shareMode, LPSECURITY_ATTRIBUTES sa, ws_uint32_t creationDisposition, ws_uint32_t flagAndAttributes, file_handle_type hTemplateFile)
    {
        return WINSTL_API_EXTERNAL_FileManagement_CreateFileW(fileName, desiredAccess, shareMode, sa, creationDisposition, flagAndAttributes, hTemplateFile);
    }

    static bool_type close_file(file_handle_type h)
    {
        return filesystem_traits_::close_handle(h);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static large_size_type get_file_size(file_handle_type h)
    {
        return filesystem_traits_::get_file_size(h);
    }
    static large_size_type get_file_size(stat_data_type const& sd)
    {
        ws_uint64_t size = 0;

        size    =   sd.nFileSizeHigh;
        size    <<= 32;
        size    +=  sd.nFileSizeLow;

        return size;
    }
    static large_size_type get_file_size(stat_data_type const* psd)
    {
        WINSTL_ASSERT(NULL != psd);

        return get_file_size(*psd);
    }
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
private:
    static void         get_file_size(stat_data_type const*);
    static void         get_file_size(stat_data_type const&);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

private:
    static size_type GetFullPathNameW(char_type const* fileName, size_type cchBuffer, char_type buffer[], char_type** ppFile)
    {
        WINSTL_ASSERT(NULL != fileName);

        size_type result;

#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        result = WINSTL_API_INTERNAL_FileManagement_GetFullPathNameW(fileName, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer), buffer, ppFile);
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        result = WINSTL_API_INTERNAL_FileManagement_GetFullPathNameW(fileName, static_cast<DWORD>(cchBuffer), buffer, ppFile);
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        result = WINSTL_API_INTERNAL_FileManagement_GetFullPathNameW(fileName, cchBuffer, buffer, ppFile);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        if (0 == result)
        {
            size_type requiredLen = 0;

            requiredLen += str_len(fileName);

            if (!is_path_rooted(fileName))
            {
                size_type cwdLen = WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryA(0, NULL);

                requiredLen += cwdLen;
            }

            if (requiredLen >= maxPathLength)
            {
                WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_FILENAME_EXCED_RANGE);
            }
        }

        return result;
    }

    static size_type GetShortPathNameW(char_type const* fileName, char_type buffer[], size_type cchBuffer)
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameW(fileName, buffer, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameW(fileName, buffer, static_cast<DWORD>(cchBuffer));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_FileManagement_GetShortPathNameW(fileName, buffer, cchBuffer);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static HANDLE FindFirstVolumeW(char_type* volume_name, size_type cch_volume_name)
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeW(volume_name, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cch_volume_name));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cch_volume_name));

        return WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeW(volume_name, static_cast<DWORD>(cch_volume_name));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_FileManagement_FindFirstVolumeW(volume_name, cch_volume_name);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }
    static bool_type FindNextVolumeW(HANDLE h, char_type* volume_name, size_type cch_volume_name)
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeW(h, volume_name, STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cch_volume_name));
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cch_volume_name));

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeW(h, volume_name, static_cast<DWORD>(cch_volume_name));
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return FALSE != WINSTL_API_EXTERNAL_FileManagement_FindNextVolumeW(h, volume_name, cch_volume_name);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }

    static size_type GetCurrentDirectoryW(size_type cchBuffer, char_type buffer[])
    {
#ifdef _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryW(STLSOFT_NS_QUAL(truncation_cast)<DWORD>(cchBuffer), buffer);
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        WINSTL_MESSAGE_ASSERT("buffer size out of range", STLSOFT_NS_QUAL(truncation_test)<DWORD>(cchBuffer));

        return WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryW(static_cast<DWORD>(cchBuffer), buffer);
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */

        return WINSTL_API_EXTERNAL_FileManagement_GetCurrentDirectoryW(cchBuffer, buffer);
#endif /* _WINSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
    }
};

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

