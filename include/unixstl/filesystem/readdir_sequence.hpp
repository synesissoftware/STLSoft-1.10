/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/readdir_sequence.hpp
 *
 * Purpose:     readdir_sequence class.
 *
 * Created:     15th January 2002
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


/** \file unixstl/filesystem/readdir_sequence.hpp
 *
 * \brief [C++] Definition of the unixstl::readdir_sequence class
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_MAJOR      5
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_MINOR      1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_REVISION   2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE_EDIT       156
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
# ifndef UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTION_UNIXSTL_EXCEPTION
#  include <unixstl/exception/unixstl_exception.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_HPP_EXCEPTION_UNIXSTL_EXCEPTION */

#if defined(PATH_MAX)
# ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STATIC_STRING
#  include <stlsoft/string/static_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STATIC_STRING */
#else /* ? PATH_MAX */
# ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
#  include <stlsoft/string/simple_string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */
#endif /* !PATH_MAX */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */

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
#ifndef STLSOFT_INCL_H_DIRENT
# define STLSOFT_INCL_H_DIRENT
# include <dirent.h>
#endif /* !STLSOFT_INCL_H_DIRENT */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

/* No STLSoft namespaces means no UNIXSTL namespaces */
#ifdef STLSOFT_NO_NAMESPACES
# define UNIXSTL_NO_NAMESPACES
#endif /* STLSOFT_NO_NAMESPACES */

/* No UNIXSTL namespaces means no unixstl namespace */
#ifdef UNIXSTL_NO_NAMESPACES
# define UNIXSTL_NO_NAMESPACE
#endif /* UNIXSTL_NO_NAMESPACES */

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

/** Exception class thrown by unixstl::readdir_sequence.
 *
 * \ingroup group__library__FileSystem
 */
class readdir_sequence_exception
    : public unixstl_exception
{
/// \name Types
/// @{
public:
    typedef unixstl_exception               parent_class_type;
    typedef readdir_sequence_exception      class_type;
    typedef parent_class_type::string_type  string_type;
/// @}

/// \name Construction
/// @{
public:
    readdir_sequence_exception(us_char_a_t const* message, us_int_t erno)
        : parent_class_type(message, erno)
        , Directory()
    {}
    readdir_sequence_exception(us_char_a_t const* message, us_int_t erno, us_char_a_t const* directory)
        : parent_class_type(message, erno)
#if 0
        , Directory(directory)
#else /* ? 0 */
        , Directory(stlsoft::c_str_ptr(directory))
#endif /* 0 */
    {}
    ~readdir_sequence_exception() STLSOFT_NOEXCEPT
    {}
private:
    class_type& operator =(class_type const&);
/// @}

/// \name Fields
/// @{
public:
    /// The name of this field is subject to change in a future revision
    string_type const   Directory;
/// @}
};


/** STL-like readonly sequence based on directory contents
 *
 * \ingroup group__library__FileSystem
 *
 * This class presents and STL-like readonly sequence interface to allow the
 * iteration over the contents of a directory.
 */
class readdir_sequence
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
/// \name Member Types
/// @{
public:
    /// This class
    typedef readdir_sequence                                class_type;
private:
    // These make it easy to move to a template, if ever needed
    typedef us_char_a_t                                     char_type;
    typedef filesystem_traits<char_type>                    traits_type;
public:
    /// The size type
    typedef us_size_t                                       size_type;
    /// The non-mutating (const) iterator type
    class                                                   const_iterator;
    /// The value type
#if defined(UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE)
    typedef struct dirent const*                            value_type;
#else /* ? UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */
    typedef char_type const*                                value_type;
#endif /* UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */
    /// The flags type
    typedef us_int_t                                        flags_type;

public:
#if defined(PATH_MAX)
    typedef STLSOFT_NS_QUAL(basic_static_string)<
        char_type
    ,   PATH_MAX
    >                                                       string_type;
#else /* ? PATH_MAX */
    typedef STLSOFT_NS_QUAL(basic_simple_string)<
        char_type
    >                                                       string_type;
#endif /* !PATH_MAX */
/// @}

/// \name Member Constants
/// @{
public:
    enum
    {
            includeDots     =   0x0008  /*!< Requests that dots directories be included in the returned sequence */
        ,   directories     =   0x0010  /*!< Causes the search to include directories */
        ,   files           =   0x0020  /*!< Causes the search to include files */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
        ,   sockets         =   0x0000  /*!< CURRENTLY UNSUPPORTED : DO NOT USE! This exists for forward compatibility with STLSoft 1.10 test programs, and is subject to change in the future. A future version will support sockets, but it may not use this enumerator name. */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
        ,   typeMask        =   0x0070
        ,   fullPath        =   0x0100  /*!< Each file entry is presented as a full path relative to the search directory. */
        ,   absolutePath    =   0x0200  /*!< The search directory is converted to an absolute path. */
    };
/// @}

/// \name Construction
/// @{
public:
    /// Constructs a sequence according to the given criteria
    ///
    /// The constructor initialises a readdir_sequence instance on the given
    /// directory with the given flags.
    ///
    /// \param directory The directory whose contents are to be searched
    /// \param flags Flags to alter the behaviour of the search. By default
    ///   the \c directories and \c files flags are passed. If none of the
    ///   entry type flags (\c directories, \c files, \c sockets) are
    ///   specified, then all types are included in the search.
    ///
    /// \note The \c flags parameter defaults to <code>directories | files</code> because
    /// this reflects the default behaviour of \c readdir(), and also because it is the
    /// most efficient.
    template <ss_typename_param_k S>
    readdir_sequence(S const& directory, flags_type flags = directories | files)
        : m_flags(validate_flags_(flags))
        , m_directory(prepare_directory_(STLSOFT_NS_QUAL(c_str_ptr)(directory), flags))
    {}
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;
/// @}

/// \name Attributes
/// @{
public:
    /// Indicates whether the search sequence is empty
    us_bool_t empty() const;

    /// The search directory
    ///
    /// \note The value returned by this method always has a trailing path
    /// name separator, so you can safely concatenate this with the value
    /// returned by the iterator's <code>operator *()</code> with minimal
    /// fuss, though you should do this only if you have not specified
    /// \c fullPath nor \c absolutePath.
    string_type const&  get_directory() const;

    /// The flags used by the sequence
    ///
    /// \note This value is the value used by the sequence, which may, as a
    /// result of the determination of defaults, be different from those
    /// specified in its constructor. For example, if
    /// <code>includeDots</code> was specified, this function will instead
    /// return <code>includeDots | directories | files</code>.
    flags_type          get_flags() const;
/// @}

/// \name Implementation
/// @{
private:
    /// Ensures that the flags are correct
    static flags_type   validate_flags_(flags_type flags);

    /// Prepares the directory, according to the given flags
    static string_type  prepare_directory_(char_type const* directory, flags_type flags);
/// @}

/// \name Members
/// @{
private:
    const flags_type    m_flags;
    const string_type   m_directory;
/// @}

/// \name Not to be implemented
/// @{
private:
    readdir_sequence(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

/** Iterator for the \link unixstl::readdir_sequence readdir_sequence\endlink class.
 *
 * \ingroup group__library__FileSystem
 *
 * This class performs as a non-mutating iterator (aka const iterator) for the
 * readdir_sequence class.
 */
class readdir_sequence::const_iterator
    : public STLSOFT_NS_QUAL(iterator_base)<STLSOFT_NS_QUAL_STD(input_iterator_tag)
                                        ,   readdir_sequence::value_type
                                        ,   us_ptrdiff_t
                                        ,   void                            // By-Value Temporary reference
                                        ,   readdir_sequence::value_type    // By-Value Temporary reference
                                        >
{
/// \name Members
/// @{
private:
    typedef readdir_sequence::string_type                   string_type;
public:
    /// The class type
    typedef const_iterator                                  class_type;
    /// The value type
    typedef readdir_sequence::value_type                    value_type;
    /// The flags type
    typedef readdir_sequence::flags_type                    flags_type;
//    typedef value_type*                                     pointer;
//    typedef value_type&                                     reference;
/// @}

/// \name Construction
/// @{
private:
    friend class readdir_sequence;

    /// Construct an instance and begin a sequence iteration on the given dir.
    const_iterator(DIR* dir, string_type const& directory, flags_type flags);
public:
    /// Default constructor
    const_iterator();
    /// Copy constructor
    const_iterator(class_type const& rhs);
    /// Release the search handle
    ~const_iterator() STLSOFT_NOEXCEPT;

    /// Copy assignment operator
    class_type const& operator =(class_type const& rhs);
/// @}

/// \name Input Iterator Methods
/// @{
public:
    /// Returns the value representative
    value_type operator *() const;

    /// Moves the iteration on to the next point in the sequence, or end() if
    /// the sequence is exhausted
    class_type& operator ++();

    /// Post-increment form of operator ++().
    ///
    /// \note Because this version uses a temporary on which to call the
    /// pre-increment form it is thereby less efficient, and should not be used
    /// except where post-increment semantics are required.
    class_type operator ++(int);

    /// Compares \c this for equality with \c rhs
    ///
    /// \param rhs The instance against which to test
    /// \retval true if the iterators are equivalent
    /// \retval false if the iterators are not equivalent
    bool equal(class_type const& rhs) const;
/// @}

/// \name Members
/// @{
private:
    struct shared_handle;

    shared_handle*  m_handle;   // The DIR handle, shared with other iterator instances
    struct dirent*  m_entry;    // The current entry
    flags_type      m_flags;    // flags. (Only non-const, to allow copy assignment)
    string_type     m_scratch;  // Holds the directory, and is a scratch area
    size_type       m_dirLen;   // The length of the directory (in `m_scratch`)
/// @}
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
struct readdir_sequence::const_iterator::shared_handle
{
/// \name Member Types
/// @{
public:
    typedef shared_handle   class_type;
    typedef DIR*            handle_type;
/// @}

/// \name Members
/// @{
public:
    handle_type m_dir;
private:
    ss_sint32_t m_refCount;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k shared_handle(handle_type h)
        : m_dir(h)
        , m_refCount(1)
    {}
    ss_sint32_t AddRef()
    {
        return ++m_refCount;
    }
    ss_sint32_t Release()
    {
        ss_sint32_t rc = --m_refCount;

        if (0 == rc)
        {
            delete this;
        }

        return rc;
    }
#if defined(STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR)
protected:
#else /* ? STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
private:
#endif /* STLSOFT_CF_COMPILER_WARNS_NO_PUBLIC_DTOR */
    ~shared_handle() STLSOFT_NOEXCEPT
    {
        UNIXSTL_MESSAGE_ASSERT("Shared search handle being destroyed with outstanding references!", 0 == m_refCount);

        if (NULL != m_dir)
        {
            ::closedir(m_dir);
        }
    }
/// @}

/// \name Not to be implemented
/// @{
private:
    shared_handle(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

////////////////////////////////////////////////////////////////////////////
// Operators

inline
us_bool_t
operator ==(
    readdir_sequence::const_iterator const& lhs
,   readdir_sequence::const_iterator const& rhs
)
{
    return lhs.equal(rhs);
}

inline
us_bool_t
operator !=(
    readdir_sequence::const_iterator const& lhs
,   readdir_sequence::const_iterator const& rhs
)
{
    return !lhs.equal(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// readdir_sequence

inline
/* static */
readdir_sequence::flags_type
readdir_sequence::validate_flags_(
        readdir_sequence::flags_type flags
)
{
    const flags_type    validFlags  =   0
                                    |   includeDots
                                    |   0
                                    |   directories
                                    |   files
                                    |   0
                                    |   fullPath
                                    |   absolutePath
                                    |   0;

    UNIXSTL_MESSAGE_ASSERT("Specification of unrecognised/unsupported flags", flags == (flags & validFlags));
    STLSOFT_SUPPRESS_UNUSED(validFlags);

    if (0 == (flags & (directories | files)))
    {
        flags |= (directories | files);
    }

    return flags;
}

inline
/* static */
readdir_sequence::string_type
readdir_sequence::prepare_directory_(
    char_type const*                directory
,   readdir_sequence::flags_type    flags
)
{
    if (NULL == directory ||
        '\0' == *directory)
    {
        static const char_type s_thisDir[] = { '.', '\0' };

        directory = s_thisDir;
    }

    // NOTE: because this is an auto_buffer, which understands nothing about
    // a nul-terminating character, the following code must account
    // explicitly for it, marked "+nul"
    STLSOFT_NS_QUAL(auto_buffer)<char_type> path(1);
    size_type                               n;

    if (0 == path.size())
    {
        // rather weak response to allocation failure, although this
        // happens only when STLSOFT_CF_EXCEPTION_SUPPORT not defined

        return string_type();
    }

    if (absolutePath & flags)
    {
        // NOTE: upon success, path will have been expanded to (at least)
        // `n` elements
        n = traits_type::get_full_path_name(directory, path);

        if (0 == n)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            int e = (0 != errno) ? errno : ENOMEM;

            STLSOFT_THROW_X(readdir_sequence_exception("failed to obtain full path of search directory", e, directory));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            // "+nul"
            if (!path.resize(1 + n))
            {
                return string_type();
            }

            traits_type::char_copy(&path[0], directory, n);
            path[n] = \'0';
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
    else
    {
        n = traits_type::str_len(directory);

        // "+nul"
        //
        // NOTE: we ask for 2, not 1, so that the path-name-separator
        // extension in the final step below will, if required, be
        // cheap
        if (!path.resize(2 + n))
        {
            return string_type();
        }

        traits_type::char_copy(&path[0], directory, n);
        path[n] = '\0';
    }

    // TODO: change this to `&path[n - 1]` when `ensure_dir_end()` can handle that
    // "+nul"
    if (!traits_type::has_dir_end(&path[0]))
    {
        // at this point, `path` will be exactly `n` elements in length

        // "+nul"
        path.resize(2 + n);

        // "+nul"
        traits_type::ensure_dir_end(&path[0]);

        // "+nul"
        n++;
    }


    // "+nul"
    return string_type(path.data(), n);
}

inline
readdir_sequence::const_iterator
readdir_sequence::begin() const
{
    DIR* dir = ::opendir(m_directory.c_str());

    if (NULL == dir)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(readdir_sequence_exception("failed to enumerate directory", errno, m_directory.c_str()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        return const_iterator();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        return const_iterator(dir, m_directory, m_flags);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(...)
    {
        ::closedir(dir);

        throw;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline
readdir_sequence::const_iterator
readdir_sequence::end() const
{
    return const_iterator();
}

inline
us_bool_t
readdir_sequence::empty() const
{
    return end() == begin();
}

inline
readdir_sequence::string_type const&
readdir_sequence::get_directory() const
{
    return m_directory;
}

inline
readdir_sequence::flags_type
readdir_sequence::get_flags() const
{
    return m_flags;
}


// readdir_sequence::const_iterator;

inline
readdir_sequence::const_iterator::const_iterator(
    DIR*                                    dir
,   readdir_sequence::string_type const&    directory
,   readdir_sequence::flags_type            flags
)
    : m_handle(new shared_handle(dir))
    , m_entry(NULL)
    , m_flags(flags)
    , m_scratch(directory)
    , m_dirLen(directory.length())
{
    UNIXSTL_ASSERT(traits_type::has_dir_end(m_scratch.c_str()));

    if (NULL == m_handle)
    {
        ::closedir(dir);
    }
    else
    {
        operator ++();
    }
}

inline
readdir_sequence::const_iterator::const_iterator()
    : m_handle(NULL)
    , m_entry(NULL)
    , m_flags(0)
    , m_scratch()
    , m_dirLen(0)
{}

inline
readdir_sequence::const_iterator::const_iterator(
    class_type const& rhs
)
    : m_handle(rhs.m_handle)
    , m_entry(rhs.m_entry)
    , m_flags(rhs.m_flags)
    , m_scratch(rhs.m_scratch)
    , m_dirLen(rhs.m_dirLen)
{
    if (NULL != m_handle)
    {
        m_handle->AddRef();
    }
}

inline
readdir_sequence::const_iterator::~const_iterator() STLSOFT_NOEXCEPT
{
    if (NULL != m_handle)
    {
        m_handle->Release();
    }
}

inline
readdir_sequence::const_iterator::class_type const&
readdir_sequence::const_iterator::operator =(
    readdir_sequence::const_iterator::class_type const& rhs
)
{
    shared_handle* this_handle = m_handle;

    m_handle  =   rhs.m_handle;
    m_entry   =   rhs.m_entry;
    m_flags   =   rhs.m_flags;
    m_scratch =   rhs.m_scratch;
    m_dirLen  =   rhs.m_dirLen;

    if (NULL != m_handle)
    {
        m_handle->AddRef();
    }

    if (NULL != this_handle)
    {
        this_handle->Release();
    }

    return *this;
}

inline
readdir_sequence::const_iterator::value_type
readdir_sequence::const_iterator::operator *() const
{
    UNIXSTL_MESSAGE_ASSERT( "Dereferencing invalid iterator", NULL != m_entry);

#if defined(UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE)
    return m_entry;
#else /* ? UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */
    return (readdir_sequence::fullPath & m_flags) ? m_scratch.c_str() : m_entry->d_name;
#endif /* UNIXSTL_READDIR_SEQUENCE_OLD_VALUE_TYPE */
}

inline
readdir_sequence::const_iterator::class_type&
readdir_sequence::const_iterator::operator ++()
{
    UNIXSTL_MESSAGE_ASSERT( "Incrementing invalid iterator", NULL != m_handle);

    for (;;)
    {
        errno = 0;

        m_entry = ::readdir(m_handle->m_dir);

        if (NULL == m_entry)
        {
            if (0 != errno)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                m_scratch.resize(m_dirLen);

                STLSOFT_THROW_X(readdir_sequence_exception("failed to complete directory enumeration", errno, m_scratch.c_str()));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }
        }
        else
        {
            UNIXSTL_ASSERT(NULL != m_entry->d_name);

            // Check for dots

            if (0 == (m_flags & includeDots))
            {
                if (traits_type::is_dots(m_entry->d_name))
                {
                    continue; // Don't want dots; skip it
                }
            }

            // If either
            //
            // - eliding files or directories, or
            // - requiring absolute path
            //
            // then need to construct it.
#ifdef _WIN32
            if ((m_flags & (fullPath | directories | files)) != (directories | files))
#endif /* _WIN32 */
            {
                // Truncate the scratch to the directory path, ...
                m_scratch.resize(m_dirLen);
                // ... and add the file
                m_scratch += m_entry->d_name;
            }

#ifdef _WIN32
            if ((m_flags & (directories | files)) != (directories | files))
#endif /* _WIN32 */
            {
                // Now need to process the file, by using stat
                traits_type::stat_data_type st;

                if (!traits_type::stat(m_scratch.c_str(), &st))
                {
                    // Failed to get info from entry. Must assume it is
                    // dead, so skip it
                    continue;
                }
                else
                {
#ifndef _WIN32
                    // Test for sockets : this version does not support sockets,
                    // but does elide them from the search results.
                    if (traits_type::is_socket(&st))
                    {
                        continue;
                    }
#endif /* !_WIN32 */

                    if (m_flags & directories) // Want directories
                    {
                        if (traits_type::is_directory(&st))
                        {
                            // It is a directory, so accept it
                            break;
                        }
                    }
                    if (m_flags & files) // Want files
                    {
                        if (traits_type::is_file(&st))
                        {
                            // It is a file, so accept it
                            break;
                        }
                    }

                    continue; // Not a match, so skip this entry
                }
            }
        }

        break;
    }

    if (NULL == m_entry)
    {
        UNIXSTL_ASSERT(NULL != m_handle);

        m_handle->Release();

        m_handle = NULL;
    }

    return *this;
}

inline
readdir_sequence::const_iterator::class_type
readdir_sequence::const_iterator::operator ++(int)
{
    class_type ret(*this);

    operator ++();

    return ret;
}

inline
bool
readdir_sequence::const_iterator::equal(
    readdir_sequence::const_iterator::class_type const& rhs
) const
{
    UNIXSTL_ASSERT(NULL == m_handle || NULL == rhs.m_handle || m_handle->m_dir == rhs.m_handle->m_dir);

    return m_entry == rhs.m_entry;
}

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

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_READDIR_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

