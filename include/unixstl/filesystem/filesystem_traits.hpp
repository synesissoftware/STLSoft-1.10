/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/filesystem_traits.hpp
 *
 * Purpose:     Contains the filesystem_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
 * Updated:     22nd January 2024
 *
 * Thanks:      To Sergey Nikulov, for spotting a preprocessor typo that
 *              broke GCC -pedantic; to Michal Makowski and Zar Eindl for
 *              reporting GCC 4.5+ problem with use of NULL in return
 *              of invalid_file_handle_value().
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


/** \file unixstl/filesystem/filesystem_traits.hpp
 *
 * \brief [C++] Definition of the unixstl::filesystem_traits traits
 *  class
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MAJOR     4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MINOR     15
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_REVISION  5
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_EDIT      181
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

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS
# include <unixstl/filesystem/path_classify_functions.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS*/
#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS
# include <unixstl/filesystem/path_parse_functions.h>
#endif /*! UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_PARSE_FUNCTIONS */
#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <unixstl/system/system_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#ifdef _UNIXSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST
#   include <stlsoft/conversion/truncation_cast.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST */
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST
#   include <stlsoft/conversion/truncation_test.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST */
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* _UNIXSTL_FILESYSTEM_TRAITS_USE_TRUNCATION_TESTING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR
# include <stlsoft/string/c_string/strnpbrkn.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS
# include <stlsoft/util/resizeable_buffer_helpers.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_RESIZEABLE_BUFFER_HELPERS */

#ifdef _WIN32
# include <ctype.h>
#endif /* _WIN32 */
#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_FCNTL
# define STLSOFT_INCL_H_FCNTL
# include <fcntl.h>
#endif /* !STLSOFT_INCL_H_FCNTL */
#ifdef _WIN32
# include <io.h>
# if defined(STLSOFT_COMPILER_IS_INTEL) || \
     defined(STLSOFT_COMPILER_IS_MSVC)
#  include <direct.h>
# endif /* os && compiler */
#endif /* _WIN32 */
#ifndef STLSOFT_INCL_H_DLFCN
# define STLSOFT_INCL_H_DLFCN
# include <dlfcn.h>
#endif /* !STLSOFT_INCL_H_DLFCN */
#ifndef STLSOFT_INCL_H_DIRENT
# define STLSOFT_INCL_H_DIRENT
# include <dirent.h>
#endif /* !STLSOFT_INCL_H_DIRENT */
#ifndef STLSOFT_INCL_H_LIMITS
# define STLSOFT_INCL_H_LIMITS
# include <limits.h>
#endif /* !STLSOFT_INCL_H_LIMITS */
#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>
#endif /* !STLSOFT_INCL_H_STDIO */
#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>
#endif /* !STLSOFT_INCL_H_STDLIB */
#ifndef STLSOFT_INCL_H_UNISTD
# define STLSOFT_INCL_H_UNISTD
# include <unistd.h>
#endif /* !STLSOFT_INCL_H_UNISTD */
#ifndef STLSOFT_INCL_SYS_H_TYPES
# define STLSOFT_INCL_SYS_H_TYPES
# include <sys/types.h>
#endif /* !STLSOFT_INCL_SYS_H_TYPES */
#ifndef STLSOFT_INCL_SYS_H_STAT
# define STLSOFT_INCL_SYS_H_STAT
# include <sys/stat.h>
#endif /* !STLSOFT_INCL_SYS_H_STAT */

#ifdef _WIN32
# ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
#  include <winstl/api/external/ErrorHandling.h>
# endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#endif /* _WIN32 */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

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
    typedef us_size_t                                       size_type;
    /// The large size type
    typedef us_uint64_t                                     large_size_type;
    /// The difference type
    typedef us_ptrdiff_t                                    difference_type;
    /// The stat data type
    typedef struct stat                                     stat_data_type;
    /// The fstat data type
    typedef struct stat                                     fstat_data_type;
    /// The current instantion of the type
    typedef filesystem_traits<C>                            class_type;
    /// The path-classification type
    typedef path_classification_t                           path_classification_type;
    /// The path-classification results type
    typedef unixstl_C_path_classification_results_t         path_classification_results_type;
    /// The path-classification string slice type
    typedef stlsoft_C_string_slice_t                        path_classification_string_slice_type;

    /// The (signed) integer type
    typedef us_int_t                                        int_type;
    /// The Boolean type
    typedef us_bool_t                                       bool_type;
    /// The type of a system file handle
    typedef int                                             file_handle_type;
    /// The type of a handle to a dynamically loaded module
    typedef void*                                           module_type;
    /// The type of system error codes
    typedef int                                             error_type;
    /// The mode type
#ifdef _WIN32
    typedef unsigned short                                  mode_type;
#else /* ? _WIN32 */
    typedef mode_t                                          mode_type;
#endif /* _WIN32 */
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
#ifdef PATH_MAX
    enum
    {
        maxPathLength = PATH_MAX //!< The maximum length of a path for the current file system
    };
#endif /* PATH_MAX */

    enum
    {
        pathComparisonIsCaseSensitive = true
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
    /// \note On UNIX it is '*'
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

    /// Gets the full path name into the given buffer, resizing it if
    /// required
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
    // opendir/readdir API

    /// Initiate a file-system search
    static DIR*                 open_dir(char_type const* dir);
    /// Read an entry from the file-system search
    static struct dirent const* read_dir(DIR* h);
    /// Closes the handle of the file-system search
    static void                 close_dir(DIR* h);
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
#ifndef _WIN32
    /// Returns whether the given path represents a socket
    static bool_type    is_socket(char_type const* path);
#endif /* OS */
    /// Returns whether the given path represents a link
    static bool_type    is_link(char_type const* path);

    /// Gets the information for a particular file system entry
    static bool_type    stat(char_type const* path, stat_data_type* stat_data);
    /// Gets the information for a particular file system entry
    static bool_type    lstat(char_type const* path, stat_data_type* stat_data);
    /// Gets the information for a particular open file
    static bool_type    fstat(file_handle_type h, fstat_data_type* fstat_data);

    /// Returns whether the given stat info represents a file
    static bool_type    is_file(stat_data_type const* stat_data);
    /// Returns whether the given stat info represents a directory
    static bool_type    is_directory(stat_data_type const* stat_data);
#ifndef _WIN32
    /// Returns whether the given stat info represents a socket
    static bool_type    is_socket(stat_data_type const* stat_data);
#endif /* OS */
    /// Returns whether the given stat info represents a link
    static bool_type    is_link(stat_data_type const* stat_data);

    /// Returns whether the given stat info represents a read-only entry
    static bool_type    is_readonly(stat_data_type const* stat_data);
/// @}

/// \name file-system control
/// @{
public:
    /// Creates a directory
    static bool_type    create_directory(char_type const* dir);
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
#if 0

    static bool_type    copy_file(char_type const* sourceName, char_type const* newName, bool_type bFailIfExists = false);
#endif

    /// The value returned by open_file() that indicates that the
    /// operation failed
    static file_handle_type invalid_file_handle_value();
    /// Create / open a file
    static file_handle_type open_file(char_type const* fileName, int oflag, int pmode);
    /// Closes the given operating system handle
    static bool_type        close_file(file_handle_type h);
    /// Create / open a file
    ///
    /// \deprecated Users should use open_file()
    static file_handle_type open(char_type const* fileName, int oflag, int pmode);
    /// Closes the given operating system handle
    ///
    /// \deprecated Users should use close_file()
    static bool_type        close(file_handle_type h);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    /// Gets the size of the file
    static large_size_type      get_file_size(file_handle_type h);
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
public: // types
    typedef us_size_t                                       size_type;
    typedef us_uint64_t                                     large_size_type;
    typedef us_ptrdiff_t                                    difference_type;
    typedef us_int_t                                        int_type;
    typedef us_bool_t                                       bool_type;
    typedef int                                             file_handle_type;
    typedef void*                                           module_type;
    typedef int                                             error_type;
#ifdef _WIN32
    typedef unsigned short                                  mode_type;
#else /* ? _WIN32 */
    typedef mode_t                                          mode_type;
#endif /* _WIN32 */

public: // path classification and analysis
    static size_type path_max()
    {
#if defined(PATH_MAX)

        return PATH_MAX;
#else /* ? PATH_MAX */

        return 1 + pathconf("/", _PC_PATH_MAX);
#endif /* PATH_MAX */
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<us_char_a_t>
    : public system_traits<us_char_a_t>
#if 0
    , protected filesystem_traits_util_
#endif /* 0 */
{
public: // types
    typedef us_char_a_t                                     char_type;
    typedef us_size_t                                       size_type;
    typedef us_uint64_t                                     large_size_type;
    typedef us_ptrdiff_t                                    difference_type;
    typedef struct stat                                     stat_data_type;
    typedef struct stat                                     fstat_data_type;
    typedef filesystem_traits<us_char_a_t>                  class_type;
    typedef path_classification_t                           path_classification_type;
    typedef unixstl_C_path_classification_results_m_t       path_classification_results_type;
    typedef stlsoft_C_string_slice_m_t                      path_classification_string_slice_type;
    typedef us_int_t                                        int_type;
    typedef us_bool_t                                       bool_type;
    typedef int                                             file_handle_type;
    typedef void*                                           module_type;
    typedef int                                             error_type;
#ifdef _WIN32
    typedef unsigned short                                  mode_type;
#else /* ? _WIN32 */
    typedef mode_t                                          mode_type;
#endif /* _WIN32 */
private:
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_type
    >                                                       buffer_type_;

public: // constants
#ifdef PATH_MAX
    enum
    {
        maxPathLength = PATH_MAX //!< The maximum length of a path for the current file system
    };
#endif /* PATH_MAX */

    enum
    {
#ifdef _WIN32

        pathComparisonIsCaseSensitive   =   false
#else /* ? _WIN32 */

        pathComparisonIsCaseSensitive   =   true
#endif /* _WIN32 */
    };

public: // general string handling
    static int_type str_fs_compare(char_type const* s1, char_type const* s2)
    {
#ifdef _WIN32

        return str_compare_no_case(s1, s2);
#else /* ? _WIN32 */

        return str_compare(s1, s2);
#endif /* _WIN32 */
    }

    static int_type str_fs_n_compare(char_type const* s1, char_type const* s2, size_type len)
    {
#ifdef _WIN32

        return str_n_compare_no_case(s1, s2, len);
#else /* ? _WIN32 */

        return str_n_compare(s1, s2, len);
#endif /* _WIN32 */
    }

public: // directory-end
    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    )
    {
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(0 == len || NULL != dir);
        UNIXSTL_ASSERT(0 == capacity || len < capacity);

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
        UNIXSTL_ASSERT(0 == len || NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

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
        return unixstl_C_path_classify(path, len, parseFlags, results);
    }

    static
    bool
    path_is_rooted(
        path_classification_t               pc
    )
    {
        return 0 != unixstl_C_path_is_rooted(pc);
    }

    static
    bool
    path_is_absolute(
        path_classification_t               pc
    )
    {
        return path_is_rooted(pc);
    }


    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    )
    {
        UNIXSTL_ASSERT(NULL != path);

        return unixstl_C_find_last_path_name_separator(path);
    }

    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    {
        UNIXSTL_ASSERT(0 == len || NULL != path);

        return unixstl_C_find_last_path_name_separator_len(path, len);
    }

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    )
    {
        UNIXSTL_ASSERT(NULL != path);

        return unixstl_C_find_first_path_name_separator(path);
    }

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    {
        UNIXSTL_ASSERT(0 == len || NULL != path);

        return unixstl_C_find_first_path_name_separator_len(path, len);
    }

    static bool_type is_dots(char_type const* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32

        // It might be a UNC path. This is handled by the second test below, but
        // this is a bit clearer, and since this is a debug kind of thing, we're
        // not worried about the cost
        if ('\\' == path[0] &&
            '\\' == path[1])
        {
            return true;
        }

        // If it's really on Windows, then we need to skip the drive, if present
        if (isalpha(path[0]) &&
            ':' == path[1])
        {
            path += 2;
        }

        // If it's really on Windows, then we need to account for the fact that
        // the slash might be backwards, but that's taken care of for us by
        // is_path_name_separator()
#endif /* _WIN32 */

        return is_path_name_separator(*path);
    }

    static bool_type is_path_rooted(
        char_type const*    path
    ,   size_t              len
    )
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32

        if (len >= 2)
        {
            // It might be a UNC path. This is handled by the second test below, but
            // this is a bit clearer, and since this is a debug kind of thing, we're
            // not worried about the cost
            if ('\\' == path[0] &&
                '\\' == path[1])
            {
                return true;
            }
        }

        if (len >= 2)
        {
            // If it's really on Windows, then we need to skip the drive, if present
            if (isalpha(path[0]) &&
                ':' == path[1])
            {
                path += 2;
                len -= 2;
            }
        }

        // If it's really on Windows, then we need to account for the fact that
        // the slash might be backwards, but that's taken care of for us by
        // is_path_name_separator()
#endif /* _WIN32 */

        return 0 != len && is_path_name_separator(*path);
    }

    static bool_type is_path_absolute(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32

        // If it's really on Windows, then it can only be absolute if ...
        //
        // ... it's a UNC path, or ...
        if (is_path_UNC(path))
        {
            return true;
        }
        // ... it's got drive + root slash, or
        if (isalpha(path[0]) &&
            ':' == path[1] &&
            is_path_name_separator(path[2]))
        {
            return true;
        }

        return false;
#else /* ? _WIN32 */

        return is_path_rooted(path);
#endif /* _WIN32 */
    }

    static bool_type is_path_absolute(
        char_type const*    path
    ,   size_t              len
    )
    {
        if (0 == len)
        {
            return false;
        }

#ifdef _WIN32

        // If it's really on Windows, then it can only be absolute if ...
        //
        // ... it's a UNC path, or ...
        if (is_path_UNC(path, len))
        {
            return true;
        }
        if (len >= 3)
        {
            // ... it's got drive + root slash, or
            if (isalpha(path[0]) &&
                ':' == path[1] &&
                is_path_name_separator(path[2]))
            {
                return true;
            }
        }

        return false;
#else /* ? _WIN32 */

        return is_path_rooted(path, len);
#endif /* _WIN32 */
    }

    static bool_type is_path_UNC(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32

        size_type const len = str_len(path);

        return is_path_UNC(path, len);
#else /* ? _WIN32 */

        STLSOFT_SUPPRESS_UNUSED(path);

        return false;
#endif /* _WIN32 */
    }

    static bool_type is_path_UNC(
        char_type const*    path
    ,   size_t              len
    )
    {
#ifdef _WIN32

        switch (len)
        {
            case    0:
            case    1:
                return false;
            default:
                return '\\' == path[0] && '\\' == path[1];
        }
#else /* ? _WIN32 */

        STLSOFT_SUPPRESS_UNUSED(path);
        STLSOFT_SUPPRESS_UNUSED(len);

        return false;
#endif /* _WIN32 */
    }

private:
#ifdef _WIN32

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
#endif /* _WIN32 */
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
        UNIXSTL_ASSERT(NULL != path);

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
        UNIXSTL_ASSERT(0 == cchPath || NULL != path);

        if (is_root_directory_(path, cchPath))
        {
            return true;
        }

#ifdef _WIN32

        if (is_root_drive_(path, cchPath))
        {
            return true;
        }

        if (is_root_UNC_(path, cchPath))
        {
            return true;
        }
#endif

        return false;
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    static bool_type is_path_name_separator(char_type ch)
    {
#ifdef _WIN32

        if ('\\' == ch)
        {
            return true;
        }
#endif /* _WIN32 */

        return '/' == ch;
    }

    static char_type path_separator()
    {
        return ':';
    }

    static char_type path_name_separator()
    {
        return '/';
    }

    static char_type const* pattern_all()
    {
        return "*";
    }

    static size_type path_max()
    {
        return filesystem_traits_::path_max();
    }

private:
#if _STLSOFT_VER >= 0x010b0000

# error Sort get_root_len_() properly
#endif

    // TODO: promote this to public
public:
    static
    size_type
    get_root_len_(
        char_type const*    path
    ,   size_type           len
    )
    {
        if (0 == len)
        {
            return 0;
        }

#ifdef _WIN32

        // If it's really on Windows, then we need to check for drive designator
        if (iswalpha(path[0]) &&
            ':' == path[1] &&
            is_path_name_separator(path[2]))
        {
            return 3;
        }

        // If it's really on Windows, then we need to skip the drive, if present
        if ('\\' == path[0] &&
            '\\' == path[1])
        {
            char_type const* slash2 = find_next_path_name_separator(path + 2);

            if (NULL == slash2)
            {
#if 0
                WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_INVALID_ARGUMENT);
#endif /* 0 */

                return 0;
            }
            else
            {
                return 1 + (slash2 - path);
            }
        }
#endif /* _WIN32 */

        return is_path_name_separator(path[0]) ? 1 : 0;
    }

    static
    size_type
    get_root_len_(
        char_type const*    path
    )
    {
        UNIXSTL_ASSERT(NULL != path);

        size_type const len = str_len(path);

        return get_root_len_(path, len);
    }
private:

    static
    size_type
    get_full_path_name_impl2(
        char_type const*    fileName
    ,   size_type const     len
    ,   char_type*          buffer
    ,   size_type           cchBuffer
    )
    {
        if (NULL != buffer &&
            0 == cchBuffer)
        {
            return 0;
        }

#ifdef _WIN32

        if (!is_path_absolute(fileName) &&
            is_path_rooted(fileName))
        {
            buffer_type_    cwd(1);
            size_type const n1  =   get_current_directory(cwd);
            char const*     sep =   stlsoft_C_strnpbrkn(cwd.data(), n1, "\\/", 2);
            size_t const    n2  =   sep - cwd.data();

            if (!resizeable_buffer_resize(cwd, n2 + len + 1))
            {
                return 0;
            }

            STLSOFT_API_INTERNAL_memfns_memcpy(&cwd[0] + n2, fileName, sizeof(char_type) * len);
            cwd[n2 + len] = '\0';

            return get_full_path_name_impl2(cwd.data(), n2 + len, buffer, cchBuffer);
        }
#endif

        // The next thing to so is determine whether the path is absolute, in
        // which case we'll just copy it into the buffer

#ifdef _WIN32

        if (is_path_absolute(fileName))
#else

        if (is_path_rooted(fileName))
#endif
        {
            // Given path is absolute, so simply copy into buffer
            if (NULL == buffer)
            {
                return len + 1;
            }
            else if (cchBuffer < len + 1)
            {
                char_copy(&buffer[0], fileName, cchBuffer);

                return cchBuffer;
            }
            else
            {
                // Given buffer is large enough, so copy
                char_copy(&buffer[0], fileName, len);
                buffer[len] = '\0';

                return len;
            }
        }
        else
        {
            // Given path is relative, so get the current directory, and then concatenate
            buffer_type_ directory(1 + path_max());

            if (0 == directory.size())
            {
                set_last_error(ENOMEM);

                return 0;
            }
            else
            {
                size_type lenDir = get_current_directory(&directory[0], directory.size());

                if (0 == lenDir)
                {
                    // The call failed, so indicate that to caller
                    return 0;
                }
                else
                {
                    if ('.' == fileName[0] &&
                        (   1 == len ||
                            (   2 == len &&
                                '.' == fileName[1])))
                    {
                        if (1 == len)
                        {
                            // '.'

                            if (NULL == buffer)
                            {
                                return lenDir + 1;
                            }
                        }
                        else
                        if (2 == len)
                        {
                            // '..'

                            size_t const rootLen = get_root_len_(directory.data(), lenDir);

                            // Remove trailing slash, if any
                            if (lenDir > rootLen &&
                                has_dir_end(directory.data() + (lenDir - 1)))
                            {
                                remove_dir_end(directory.data() + (lenDir - 1));
                                --lenDir;
                            }

                            if (lenDir > rootLen)
                            {
                                char_type* const lastSlash = const_cast<char_type*>(find_last_path_name_separator(directory.data() + rootLen));

                                if (NULL != lastSlash)
                                {
                                    size_t const newLen = lastSlash - directory.data();

                                    directory[newLen] = '\0';
                                    lenDir = newLen;
                                }
                                else
                                {
                                    directory[rootLen] = '\0';
                                    lenDir = rootLen;
                                }
                            }

                            if (NULL == buffer)
                            {
                                return lenDir + 1;
                            }
                        }

                        if (cchBuffer < lenDir + 1)
                        {
                            char_copy(&buffer[0], directory.data(), cchBuffer);

                            return cchBuffer;
                        }
                        else
                        {
                            // Given buffer is large enough, so copy
                            char_copy(buffer, directory.data(), lenDir);
                            buffer[lenDir] = '\0';

                            return lenDir;
                        }

// For some reason OS-X's GCC needs this : it's confused.
#if defined(STLSOFT_COMPILER_IS_GCC) && \
    STLSOFT_GCC_VER >= 40200 && \
    STLSOFT_GCC_VER <  40300
UNIXSTL_ASSERT(0); // should never get here
return 0;
#endif
                    }
                    else
                    {
                        lenDir += str_len(ensure_dir_end(&directory[0] + (lenDir - 1))) - 1;

                        size_type const required = len + lenDir;

                        if (NULL == buffer)
                        {
                            return required + 1;
                        }
                        else
                        {
                            if (cchBuffer < lenDir + 1)
                            {
                                char_copy(&buffer[0], directory.data(), cchBuffer);

                                return cchBuffer;
                            }
                            else
                            {
                                char_copy(&buffer[0], directory.data(), lenDir);

                                if (cchBuffer < required + 1)
                                {
                                    char_copy(&buffer[0] + lenDir, fileName, cchBuffer - lenDir);

                                    return cchBuffer;
                                }
                                else
                                {
                                    char_copy(&buffer[0] + lenDir, fileName, len);
                                    buffer[lenDir + len] = '\0';

                                    return required;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    static
    size_type
    get_full_path_name_impl(
        char_type const*    fileName
    ,   size_type           len
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        UNIXSTL_ASSERT(len > 0);

        if (NULL != class_type::str_pbrk(fileName, "<>|*?"))
        {
            errno = ENOENT;

            return 0;
        }

        if ('\0' != fileName[len])
        {
            buffer_type_ fileName_(1 + (len - 1));

            // May be being compiled absent exception support, so need to check the
            // file path buffers. (This _could_ be done with a compile-time #ifdef,
            // but it's best not, since some translators support exceptions but yet
            // don't throw on mem exhaustion, and in any case a user could change
            // ::new)
            if (0 == fileName_.size())
            {
                set_last_error(ENOMEM);

                return 0;
            }
            else
            {
                fileName_[len] = '\0';

                return get_full_path_name_impl2(char_copy(&fileName_[0], fileName, len)
                                            ,   len
                                            ,   buffer
                                            ,   cchBuffer);
            }
        }
        else
        {
            return get_full_path_name_impl2(fileName, len, buffer, cchBuffer);
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
        UNIXSTL_ASSERT(NULL != ppFile);

        size_type r = get_full_path_name(fileName, buffer, cchBuffer);

        *ppFile = NULL;

        if (NULL != buffer &&
            0 != r &&
            r <= cchBuffer)
        {
            size_type cchRequired = get_full_path_name(fileName, static_cast<char_type*>(NULL), 0);

            if (r == cchRequired)
            {
                // Now search for the file separator
                char_type* pFile = const_cast<char_type*>(find_last_path_name_separator(buffer));

                if (NULL != (*ppFile = pFile))
                {
                    (*ppFile)++;
                }
            }
        }

        return r;
    }

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        UNIXSTL_ASSERT(NULL != fileName);
        UNIXSTL_ASSERT(0 == cchBuffer || NULL != buffer);

        if ('\0' == *fileName)
        {
            static const char s_dot[2] = { '.', '\0' };

            fileName = s_dot;
        }

        // Can't call realpath(), since that requires that the file exists
        return get_full_path_name_impl(fileName, str_len(fileName), buffer, cchBuffer);
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
        return get_full_path_name(fileName, cchBuffer, buffer);
    }

    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    {
        return get_full_path_name(fileName, buffer, cchBuffer);
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
        return get_full_path_name(fileName, rb);
    }

public: // file-system enumeration
    static DIR* open_dir(char_type const* dir)
    {
        return ::opendir(dir);
    }
    static struct dirent const* read_dir(DIR* h)
    {
        return ::readdir(h);
    }
    static void close_dir(DIR* h)
    {
        ::closedir(h);
    }

public: // file-system control
    static
    bool_type
    set_current_directory(
        char_type const*    dir
    )
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_INTEL))

        return 0 == ::_chdir(dir);
#else /* ? _WIN32 */

        return 0 == ::chdir(dir);
#endif /* _WIN32 */
    }

    static
    size_type
    get_current_directory(
        size_type   cchBuffer
    ,   char_type   buffer[]
    )
    {
        return get_current_directory(buffer, cchBuffer);
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

private:
    static char_type const* call_getcwd_(char_type buffer[], size_type cchBuffer)
    {
#if defined(STLSOFT_COMPILER_IS_INTEL) || \
    defined(STLSOFT_COMPILER_IS_MSVC)
        return ::_getcwd(buffer, int(cchBuffer));
#else /* ? compiler */
        return ::getcwd(buffer, int(cchBuffer));
#endif /* compiler */
    }
public:

    static
    size_type
    get_current_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    {
#if defined(_WIN32)

        char_type               local[1 + _MAX_PATH];
        size_type const         cchLocal = STLSOFT_NUM_ELEMENTS(local);
#elif defined(PATH_MAX)

        char_type               local[1 + PATH_MAX];
        size_type const         cchLocal = STLSOFT_NUM_ELEMENTS(local);
#else

        struct path_max_buffer
        {
        public:
            typedef class_type  traits_type_;

        public:
            path_max_buffer()
                : n(traits_type_::path_max())
                , p(new traits_type_::char_type[n + 1])
            {
                // check, for non-throwing new
                if (NULL == p)
                {
                    n = 0;
                }
            }
            ~path_max_buffer() STLSOFT_NOEXCEPT
            {
                delete [] p;
            }
        private:
            path_max_buffer(path_max_buffer const&) {}
            path_max_buffer& operator =(path_max_buffer const&) { return *this; }

        public:
            size_type size() const
            {
                return n;
            }
            operator char_type* ()
            {
                return p;
            }

        private:
            size_type   n;
            char_type*  p;
        };
        path_max_buffer         local;
        size_type const         cchLocal = local.size();
#endif /* _WIN32 */

        char_type const* const  dir = call_getcwd_(local, cchLocal);

        if (NULL == dir)
        {
            return 0;
        }
        else
        {
            size_type const len = str_len(dir);

            if (0 == cchBuffer)
            {
                return 1 + len;
            }
            else
            {
                size_type const n = (len < cchBuffer) ? len : cchBuffer;

                char_copy(buffer, dir, n);

                if (n < cchBuffer)
                {
                    buffer[n] = '\0';
                }

                return n;
            }
        }
    }

public: // file-system state
    static bool_type file_exists(char_type const* fileName)
    {
        stat_data_type sd;

        return class_type::stat(fileName, &sd) /* || errno != ENOENT */;
    }
    static bool_type is_file(char_type const* path)
    {
        stat_data_type sd;

        return class_type::stat(path, &sd) && S_IFREG == (sd.st_mode & S_IFMT);
    }
    static bool_type is_directory(char_type const* path)
    {
        stat_data_type sd;

        return class_type::stat(path, &sd) && S_IFDIR == (sd.st_mode & S_IFMT);
    }
#ifndef _WIN32

    static bool_type is_socket(char_type const* path)
    {
        stat_data_type sd;

        return class_type::stat(path, &sd) && S_IFSOCK == (sd.st_mode & S_IFMT);
    }
#endif /* OS */
    static bool_type is_link(char_type const* path)
    {
#ifdef _WIN32

        STLSOFT_SUPPRESS_UNUSED(path);

        return false;
#else /* ? _WIN32 */

        stat_data_type sd;

        return class_type::lstat(path, &sd) && S_IFLNK == (sd.st_mode & S_IFMT);
#endif /* _WIN32 */
    }

    static bool_type stat(char_type const* path, stat_data_type* stat_data)
    {
        UNIXSTL_ASSERT(NULL != path);
        UNIXSTL_ASSERT(NULL != stat_data);

#ifdef _WIN32

        if (NULL != class_type::str_pbrk(path, "*?"))
        {
            // Sometimes the VC6 CRT libs crash with a wildcard stat
            set_last_error(EBADF);

            return false;
        }

        if (has_dir_end(path))
        {
            // Win32 impl does not like a trailing slash
            size_type const len = str_len(path);

            if (len > 3 ||
                (   is_path_name_separator(*path) &&
                    len > 2))
            {
                buffer_type_ directory(1 + len);

                if (0 == directory.size())
                {
                    set_last_error(ENOMEM);

                    return false;
                }
                else
                {
                    char_copy(&directory[0], path, len);
                    directory[len] = '\0';

                    class_type::remove_dir_end(directory);

                    return class_type::stat(directory.data(), stat_data);
                }
            }
        }
#endif /* _WIN32 */

        return 0 == ::stat(path, stat_data);
    }
    static bool_type lstat(char_type const* path, stat_data_type* stat_data)
    {
        UNIXSTL_ASSERT(NULL != path);
        UNIXSTL_ASSERT(NULL != stat_data);

#ifdef _WIN32

        return 0 == class_type::stat(path, stat_data);
#else /* ? _WIN32 */

        return 0 == ::lstat(path, stat_data);
#endif /* _WIN32 */
    }
    static bool_type fstat(file_handle_type h, fstat_data_type* fstat_data)
    {
        UNIXSTL_ASSERT(-1 != h);
        UNIXSTL_ASSERT(NULL != fstat_data);

        return 0 == ::fstat(h, fstat_data);
    }

    static bool_type is_file(stat_data_type const* stat_data)
    {
#if 1
        return S_IFREG == (stat_data->st_mode & S_IFMT);
#else
        return filesystem_traits_util_::is_file_type_(stat_data, S_IFREG);
#endif
    }
    static bool_type is_directory(stat_data_type const* stat_data)
    {
#if 1
        return S_IFDIR == (stat_data->st_mode & S_IFMT);
#else /* ? 0 */
        return filesystem_traits_util_::is_file_type_(stat_data, S_IFDIR);
#endif /* 0 */
    }
#ifndef _WIN32

    static bool_type is_socket(stat_data_type const* stat_data)
    {
#if 1
        return S_IFSOCK == (stat_data->st_mode & S_IFMT);
#else /* ? 0 */
        return filesystem_traits_util_::is_file_type_(stat_data, S_IFSOCK);
#endif /* 0 */
    }
#endif /* OS */
    static bool_type is_link(stat_data_type const* stat_data)
    {
#ifdef _WIN32

        STLSOFT_SUPPRESS_UNUSED(stat_data);

        return false;
#else /* ? _WIN32 */

# if 1
        return S_IFLNK == (stat_data->st_mode & S_IFMT);
# else /* ? 0 */
        return filesystem_traits_util_::is_file_type_(stat_data, S_IFLNK);
# endif /* 0 */
#endif /* _WIN32 */
    }

    static bool_type is_readonly(stat_data_type const* stat_data)
    {
#ifdef _WIN32

        return S_IREAD == (stat_data->st_mode & (S_IREAD | S_IWRITE));
#else /* ? _WIN32 */

        return S_IRUSR == (stat_data->st_mode & (S_IRUSR | S_IWUSR));
#endif /* _WIN32 */
    }

    static bool_type create_directory(char_type const* dir)
    {
        mode_type mode = 0;

#ifdef _WIN32

        mode    =   S_IREAD | S_IWRITE | S_IEXEC;
#else /* ? _WIN32 */

        mode    =   S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
#endif /* _WIN32 */

        return create_directory(dir, mode);
    }

    static bool_type create_directory(char_type const* dir, mode_type permissions)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_GCC) || \
        defined(STLSOFT_COMPILER_IS_MSVC))

        STLSOFT_SUPPRESS_UNUSED(permissions);

        return 0 == ::_mkdir(dir);
#else /* ? _WIN32 */

        return 0 == ::mkdir(dir, permissions);
#endif /* _WIN32 */
    }

    static bool_type remove_directory(char_type const* dir)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))

        return 0 == ::_rmdir(dir);
#else /* ? _WIN32 */

        return 0 == ::rmdir(dir);
#endif /* _WIN32 */
    }

    static bool_type unlink_file(char_type const* file)
    {
        return 0 == ::remove(file);
    }

    static bool_type delete_file(char_type const* file)
    {
        return unlink_file(file);
    }

    static bool_type rename_file(char_type const* currentName, char_type const* newName)
    {
        return 0 == ::rename(currentName, newName);
    }

    static file_handle_type invalid_file_handle_value()
    {
        return -1;
    }

# include <stlsoft/internal/warnings/push/suppress_deprecation_.h>

    static file_handle_type open_file(char_type const* fileName, int oflag, int pmode)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))

        return ::_open(fileName, oflag, pmode);
#else /* ? _WIN32 */

        return ::open(fileName, oflag, pmode);
#endif /* _WIN32 */
    }

# include <stlsoft/internal/warnings/pop/suppress_deprecation_.h>

    static bool_type close_file(file_handle_type h)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))

        return 0 == ::_close(h);
#else /* ? _WIN32 */

        return 0 == ::close(h);
#endif /* _WIN32 */
    }

    static file_handle_type open(char_type const* fileName, int oflag, int pmode)
    {
        return class_type::open_file(fileName, oflag, pmode);
    }

    static bool_type close(file_handle_type h)
    {
        return class_type::close_file(h);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static large_size_type get_file_size(file_handle_type h)
    {
        struct stat st;

        return class_type::fstat(h, &st) ? st.st_size : 0;
    }
    static large_size_type get_file_size(stat_data_type const& sd)
    {
        return sd.st_size;
    }
    static large_size_type get_file_size(stat_data_type const* psd)
    {
        UNIXSTL_ASSERT(NULL != psd);

        return get_file_size(*psd);
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<us_char_w_t>
    : public system_traits<us_char_w_t>
#if 0
    , protected filesystem_traits_util_
#endif /* 0 */
{
public: // types
    typedef us_char_w_t                                     char_type;
    typedef us_size_t                                       size_type;
    typedef us_uint64_t                                     large_size_type;
    typedef us_ptrdiff_t                                    difference_type;
    typedef struct stat                                     stat_data_type;
    typedef struct stat                                     fstat_data_type;
    typedef filesystem_traits<us_char_a_t>                  class_type;
    typedef us_int_t                                        int_type;
    typedef us_bool_t                                       bool_type;
    typedef int                                             file_handle_type;
    typedef void*                                           module_type;
    typedef int                                             error_type;
#ifdef _WIN32
    typedef unsigned short                                  mode_type;
#else /* ? _WIN32 */
    typedef mode_t                                          mode_type;
#endif /* _WIN32 */
private:
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        char_type
    >                                                       buffer_type_;

public: // constants
#ifdef PATH_MAX
    enum
    {
        maxPathLength = PATH_MAX //!< The maximum length of a path for the current file system
    };
#endif /* PATH_MAX */

    enum
    {
#ifdef _WIN32

        pathComparisonIsCaseSensitive   =   false
#else /* ? _WIN32 */

        pathComparisonIsCaseSensitive   =   true
#endif /* _WIN32 */
    };

public: // general string handling
    static int_type str_fs_compare(char_type const* s1, char_type const* s2)
    {
#ifdef _WIN32

        return str_compare_no_case(s1, s2);
#else /* ? _WIN32 */

        return str_compare(s1, s2);
#endif /* _WIN32 */
    }

    static int_type str_fs_n_compare(char_type const* s1, char_type const* s2, size_type len)
    {
#ifdef _WIN32

        return str_n_compare_no_case(s1, s2, len);
#else /* ? _WIN32 */

        return str_n_compare(s1, s2, len);
#endif /* _WIN32 */
    }

public: // directory-end
    static
    char_type*
    ensure_dir_end(
        char_type*  dir
    )
    {
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(0 == len || NULL != dir);
        UNIXSTL_ASSERT(0 == capacity || len < capacity);

        size_type dummy;

        if (NULL == pLenToIncrease)
        {
            pLenToIncrease = &dummy;
        }

        if (0 != len)
        {
            char_type& last = dir[len - 1];

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
        UNIXSTL_ASSERT(0 == len || NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

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
        UNIXSTL_ASSERT(NULL != dir);

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
    char_type const*
    find_last_path_name_separator(
        char_type const* path
    )
    ;

    static
    char_type const*
    find_last_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    ;

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    )
    ;

    static
    char_type const*
    find_next_path_name_separator(
        char_type const*                    path
    ,   size_t                              len
    )
    ;

    static bool_type is_dots(char_type const* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

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

    static bool_type is_path_rooted(char_type const* path)
    ;

    static bool_type is_path_rooted(
        char_type const*    path
    ,   size_t              len
    )
    ;

    static bool_type is_path_absolute(char_type const* path)
    ;

    static bool_type is_path_absolute(
        char_type const*    path
    ,   size_t              len
    )
    ;

    static bool_type is_path_UNC(char_type const* path)
    ;

    static bool_type is_path_UNC(
        char_type const*    path
    ,   size_t              len
    )
    ;

    static bool_type is_path_name_separator(char_type ch)
    {
#ifdef _WIN32

        if (L'\\' == ch)
        {
            return true;
        }
#endif /* _WIN32 */

        return L'/' == ch;
    }

    static char_type path_separator()
    {
        return L':';
    }

    static char_type path_name_separator()
    {
        return L'/';
    }

    static char_type const* pattern_all()
    {
        return L"*";
    }

    static size_type path_max()
    {
        return filesystem_traits_::path_max();
    }

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    ,   char_type**         ppFile
    )
    ;

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    ;

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    )
    ;

    static
    size_type
    get_full_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    )
    ;

    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   size_type           cchBuffer
    ,   char_type           buffer[]
    )
    ;

    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   char_type           buffer[]
    ,   size_type           cchBuffer
    )
    ;

    template<
        ss_typename_param_k T_resizeableBuffer
    >
    static
    size_type
    get_short_path_name(
        char_type const*    fileName
    ,   T_resizeableBuffer& rb
    )
    ;

public: // file-system enumeration
    static DIR* open_dir(char_type const* dir)
    ;
    static struct dirent const* read_dir(DIR* h)
    ;
    static void close_dir(DIR* h)
    ;

public: // file-system control
    static
    bool_type
    set_current_directory(
        char_type const*    dir
    )
    ;

    static
    size_type
    get_current_directory(
        size_type   cchBuffer
    ,   char_type   buffer[]
    )
    ;

    static
    size_type
    get_current_directory(
        char_type   buffer[]
    ,   size_type   cchBuffer
    )
    ;
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

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

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

