/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/path.hpp
 *
 * Purpose:     Simple class that represents a path.
 *
 * Created:     1st May 1993
 * Updated:     22nd January 2024
 *
 * Thanks to:   Pablo Aguilar for reporting defect in push_ext() (which
 *              doesn't work for wide-string builds).
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1993-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/filesystem/path.hpp
 *
 * \brief [C++] Definition of the unixstl::basic_path class template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_MAJOR      7
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_MINOR      1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_REVISION   3
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_EDIT       273
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
#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH_BUFFER
# include <unixstl/filesystem/path_buffer.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH_BUFFER */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_UNIXSTL_EXCEPTION
#  include <unixstl/exception/unixstl_exception.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_EXCEPTION_HPP_UNIXSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_HPP_STRING
# include <unixstl/shims/access/string.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>       // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR
# include <stlsoft/string/c_string/strnchr.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_C_STRING_H_STRNCHR */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS
# include <stlsoft/string/copy_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE
# include <stlsoft/string/string_slice.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>                            // for std::logic_error
#endif /* !STLSOFT_INCL_STDEXCEPT */
#ifdef _WIN32
# include <ctype.h>
#endif /* _WIN32 */

#ifdef STLSOFT_DEBUG
# include <stlsoft/algorithms/pod.hpp>
#endif

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
 * basic_path
 *
 * This class represents a path, and effectively acts as a C-string of its value.
 */

/** Class used for composing and decomposing file-system paths.
 *
 * \ingroup group__library__FileSystem
 *
 * \param C The character type
 * \param T The traits type. Defaults to filesystem_traits<C>. On translators that do not support default template arguments, it must be explicitly stipulated
 * \param A The allocator class. Defaults to stlsoft::allocator_selector<C>::allocator_type. On translators that do not support default template arguments, it must be explicitly stipulated
 *
 * \note This class derives from the Synesis Software class Path, but has been influenced
 * by other, later, ideas. The idea of using the / operator for path concatenation was
 * sparked by the Boost implementation (although the details were not investigated prior
 * to this implementation, so the two may have significant semantic differences). This
 * has been added without requiring any major fundamental changes to the original
 * <code>push/pop</code>-based interface
 */
template<
    ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T = filesystem_traits<C>
,   ss_typename_param_k A = ss_typename_type_def_k STLSOFT_NS_QUAL(allocator_selector)<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = filesystem_traits<C> */
,   ss_typename_param_k A /* = ss_typename_type_def_k STLSOFT_NS_QUAL(allocator_selector)<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class basic_path
{
/// \name Types
/// @{
public:
    /// The char type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// The current specialisation of the type
    typedef basic_path<C, T, A>                             class_type;
    /// The size type
    typedef ss_typename_type_k traits_type::size_type       size_type;
    /// The Boolean type
    typedef ss_typename_type_k traits_type::bool_type       bool_type;
private:
    typedef ss_typename_type_k path_buffer_generator<
        char_type
    ,   allocator_type
    >::type                                                 path_buffer_type_;

    typedef ss_typename_param_k path_buffer_type_::buffer_type
                                                            buffer_type_;
public:
    typedef STLSOFT_NS_QUAL(string_slice)<
        char_type
    >                                                       string_slice_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an empty path
    basic_path();
    /// Constructs a path from \c path
    ss_explicit_k
    basic_path(
        char_type const* path
    );
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Constructs a path from \c path
    template<
        ss_typename_param_k S
    >
    ss_explicit_k
    basic_path(
        S const& s
    )
        : m_buffer(STLSOFT_NS_QUAL(c_str_data)(s), STLSOFT_NS_QUAL(c_str_len)(s))
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    /// Constructs a path from \c cch characters in \c path
    basic_path(
        char_type const*    path
    ,   size_type           cch
    );
#ifdef STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR

    /// Copies the contents of \c rhs
    basic_path(class_type const& rhs);
#endif /* STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR */
#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    /// Constructs an auto_buffer instance by taking over the state of the
    /// instance \c rhs
    ///
    /// \param rhs The instance whose state will be taken over. Upon return
    ///   \c rhs will be <code>empty()</code>
    ///
    /// \note When \c rhs is using external memory, this is a (fast)
    ///   constant-time operation; when using internal memory, a memory copy
    ///   operation is required
    basic_path(class_type&& rhs) STLSOFT_NOEXCEPT
        : m_buffer(std::move(rhs.m_buffer))
    {}
protected:
    basic_path(path_buffer_type_&& rhs) STLSOFT_NOEXCEPT
        : m_buffer(std::move(rhs))
    {}
    basic_path(buffer_type_&& rhs, size_type cch) STLSOFT_NOEXCEPT
        : m_buffer(std::move(rhs), cch)
    {}
public:
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */
#ifdef STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR

    /// Copies the contents of \c rhs
    class_type& operator =(class_type const& rhs);
#endif /* STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR */
    /// Copies the contents of \c rhs
    class_type& operator =(char_type const* rhs);
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    /// Copies the contents of \c s
    template<
        ss_typename_param_k S
    >
    class_type& operator =(S const& s)
    {
        return operator_equal_(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

    /// Swaps the state of the instance with \c rhs
    void swap(class_type& rhs) STLSOFT_NOEXCEPT;

    // Creates a root path
    static
    class_type
    root(
        char_type const* s
    );
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT

    // Creates a root path
    template<
        ss_typename_param_k S
    >
    static
    class_type
    root(
        S const& s
    )
    {
        return root(STLSOFT_NS_QUAL(c_str_ptr)(s));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
/// @}

/// \name Operations
/// @{
public:
    /// Appends the contents of \c rhs to the path
    class_type& push(class_type const& rhs, bool_type bAddPathNameSeparator = false);
    /// Appends the contents of \c rhs to the path
    class_type& push(char_type const* rhs, bool_type bAddPathNameSeparator = false);
    /// Appends the contents of \c rhs to the path as an extension
    class_type& push_ext(char_type const* rhs, bool_type bAddPathNameSeparator = false);
    /// Ensures that the path has a trailing path name separator
    class_type& push_sep();
    /// Pops the last path element from the path
    ///
    /// \note This operation does not remove the root.
    class_type&
    pop(
        bool_type bRemoveTrailingPathNameSeparator = true
    ) STLSOFT_NOEXCEPT;
    /// Ensures that the path does not have a trailing path name separator
    ///
    /// \note Does not trim the separator character from the root designator
    ///
    /// \note This method is idempotent.
    class_type& pop_sep() STLSOFT_NOEXCEPT;
    /// Removes the extension, if any, from the file component of the path
    ///
    /// \note This method is idempotent.
    class_type& pop_ext() STLSOFT_NOEXCEPT;

    /// Equivalent to push()
    class_type& operator /=(char_type const* rhs);

#if !defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED)
    /// Equivalent to push()
    class_type& operator /=(class_type const& rhs);
#endif /* !STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED */

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT)
    /// Equivalent to push()
    template<
        ss_typename_param_k S
    >
    class_type& operator /=(S const& rhs)
    {
        return push(STLSOFT_NS_QUAL(c_str_ptr)(rhs));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */

    /// Removes all content
    void        clear() STLSOFT_NOEXCEPT;

    /// Converts the path to absolute form
    ///
    /// \note Any iterators, pointers, or references to the instance are
    ///   invalidated by the call to this operation
    ///
    /// \note In the case where compilation does not support exceptions, the
    /// return type is Boolean and indicates whether the method failed to
    /// make absolute (rather than indicating whether a conversion was
    /// necessary)
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    class_type&
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
    bool
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    make_absolute(
        bool_type bRemoveTrailingPathNameSeparator = true
    );

    /// Canonicalises the path, removing all "./" parts and evaluating all
    /// "../" parts. Any path with only one part will not be canonicalised.
    /// A leading '.' will be preserved if no other '..' or "normal" parts
    /// are contained.
    ///
    /// \param bRemoveTrailingPathNameSeparator Removes any trailing
    ///   separator, even if no other changes have been made.
    ///
    /// \note Any iterators, pointers, or references to the instance are
    ///   invalidated by the call to this operation
    ///
    /// \note In the case where compilation does not support exceptions, the
    /// return type is Boolean and indicates whether the method failed to
    /// make canonical (rather than indicating whether a conversion was
    /// necessary)
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    class_type&
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
    bool
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    canonicalise(
        bool_type bRemoveTrailingPathNameSeparator = true
    );
/// @}

/// \name Attributes
/// @{
public:
    /// Obtains the location, if present
    string_slice_type   get_location() const STLSOFT_NOEXCEPT;
    /// Obtains the file, if present
    string_slice_type   get_file() const STLSOFT_NOEXCEPT;
    /// Obtains the extension, if present, of the file, if present
    string_slice_type   get_ext() const STLSOFT_NOEXCEPT;

    /// Returns the length of the converted path
    size_type           length() const STLSOFT_NOEXCEPT;
    /// Returns the length of the converted path
    ///
    /// \remarks Equivalent to length()
    size_type           size() const STLSOFT_NOEXCEPT;
    /// The maximum possible length of a path
    static size_type    max_size() STLSOFT_NOEXCEPT;
    /// Determines whether the path is empty
    bool_type           empty() const STLSOFT_NOEXCEPT;
    /// Returns null-terminated non-mutable (const) pointer to string data
    char_type const*    data() const STLSOFT_NOEXCEPT;
    /// Conversion to a non-mutable (const) pointer to the path
    char_type const*    c_str() const STLSOFT_NOEXCEPT;
    /// Returns a non-mutable (const) reference to the character at
    ///  the given index
    ///
    /// \note The behaviour is undefined if <code>index >= size()</code>.
    char_type const&    operator [](size_type index) const STLSOFT_NOEXCEPT;

    /// Indicates whether the path represents an existing file system entry
    bool_type           exists() const STLSOFT_NOEXCEPT;
    /// Indicates whether the path is rooted
    bool_type           is_rooted() const STLSOFT_NOEXCEPT;
    /// Indicates whether the path is absolute
    bool_type           is_absolute() const STLSOFT_NOEXCEPT;
    /// Indicates whether the path has a trailing separator
    bool_type           has_sep() const STLSOFT_NOEXCEPT;

    /// Copies the contents into a caller supplied buffer
    ///
    /// \param buffer Pointer to character buffer to receive the contents.
    ///  May be NULL, in which case the method returns size().
    /// \param cchBuffer Number of characters of available space in \c buffer.
    size_type
    copy(
        char_type   buffer[]
    ,   size_type   cchBuffer
    ) const STLSOFT_NOEXCEPT;
/// @}

/// \name Comparison
/// @{
public:
    /// Determines whether the instance holds a string that refers to
    ///  the same file-system entity as the given string.
    ///
    bool_type equivalent(char_type const* rhs) const STLSOFT_NOEXCEPT;

    /// Evaluates whether the two instances hold strings that refer
    ///  to the same file-system entity.
    ///
    /// \remarks See \link winstl::basic_path::equivalent(C const* ) equivalent()\endlink for an example.
    ///
    /// \note The string comparison is case-insensitive.
    bool_type equivalent(class_type const& rhs) const STLSOFT_NOEXCEPT;

    /// Evaluates whether the instance holds an identical string.
    ///
    /// \note The string comparison is case-insensitive.
    bool_type equal(char_type const* rhs) const STLSOFT_NOEXCEPT;

    /// Evaluates whether the two instances hold identical strings.
    ///
    /// \note The string comparison is case-insensitive.
    bool_type equal(class_type const& rhs) const STLSOFT_NOEXCEPT;
/// @}

/// \name Iteration
/// @{
public:
#if 0
    directory_iterator  dir_begin() const STLSOFT_NOEXCEPT;
    directory_iterator  dir_end() const STLSOFT_NOEXCEPT;
#endif /* 0 */
/// @}

// Implementation
private:
    char_type*              data_() STLSOFT_NOEXCEPT;
    char_type const*        data_() const STLSOFT_NOEXCEPT;
    size_type               size_() const STLSOFT_NOEXCEPT;

    class_type&             operator_equal_(char_type const* path);
    bool_type               equivalent_(char_type const* rhs, size_type cch) const STLSOFT_NOEXCEPT;

    class_type&             push_(char_type const* rhs, size_type cch, bool_type bAddPathNameSeparator);
    class_type&             concat_(char_type const* rhs, size_type cch);

    char_type&              last_() STLSOFT_NOEXCEPT;
    static char_type const* last_slash_(char_type const* buffer, size_type len) STLSOFT_NOEXCEPT;
    static char_type const* next_slash_or_end_(char_type const* p) STLSOFT_NOEXCEPT;

    static char_type        path_name_separator() STLSOFT_NOEXCEPT;
#ifdef _WIN32
    static char_type        path_name_separator_alt() STLSOFT_NOEXCEPT;
#endif /* _WIN32 */

// Members
private:
    struct part_type
    {
        enum Type
        {
                normal
            ,   dot
            ,   dotdot
        };

        size_type           len;
        char_type const*    p;
        Type                type;
    };

#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
    typedef ss_typename_type_k A::ss_template_qual_k rebind<
        part_type
    >::other                                                part_ator_type_;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    typedef ss_typename_type_k allocator_selector<
        part_type
    >::allocator_type                                       part_ator_type_;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

    typedef STLSOFT_NS_QUAL(auto_buffer_old)<
        part_type
    ,   part_ator_type_
    >                                                       part_buffer_type_;


    static
    size_type
    coalesce_parts_(
        part_buffer_type_& parts
    );

private: // fields
    path_buffer_type_   m_buffer;
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** Specialisation of the basic_path template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_path<us_char_a_t, filesystem_traits<us_char_a_t> >       path_a;
/** Specialisation of the basic_path template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_path<us_char_w_t, filesystem_traits<us_char_w_t> >       path_w;
/** Specialisation of the basic_path template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_path<us_char_a_t, filesystem_traits<us_char_a_t> >       path;

/* /////////////////////////////////////////////////////////////////////////
 * Support for PlatformSTL redefinition by inheritance+namespace, for confused
 * compilers (e.g. VC++ 6)
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template<
        ss_typename_param_k C
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
    ,   ss_typename_param_k T = filesystem_traits<C>
    ,   ss_typename_param_k A = ss_typename_type_def_k STLSOFT_NS_QUAL(allocator_selector)<C>::allocator_type
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
    ,   ss_typename_param_k T /* = filesystem_traits<C> */
    ,   ss_typename_param_k A /* = ss_typename_type_def_k STLSOFT_NS_QUAL(allocator_selector)<C>::allocator_type */
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
    >
    class basic_path__
        : public UNIXSTL_NS_QUAL(basic_path)<C, T, A>
    {
    private:
        typedef UNIXSTL_NS_QUAL(basic_path)<C, T, A>                    parent_class_type;
        typedef UNIXSTL_NS_QUAL(basic_path__)<C, T, A>                  class_type;
    public:
        typedef ss_typename_type_k parent_class_type::char_type         char_type;
        typedef ss_typename_type_k parent_class_type::traits_type       traits_type;
        typedef ss_typename_type_k parent_class_type::allocator_type    allocator_type;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;

    public:
        basic_path__()
            : parent_class_type()
        {}
        ss_explicit_k
        basic_path__(
            char_type const* path
        )
            : parent_class_type(path)
        {}
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        /// Constructs a path from \c path
        template<
            ss_typename_param_k S
        >
        ss_explicit_k
        basic_path__(
            S const& s
        )
            : parent_class_type(s)
        {}
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
        basic_path__(
            char_type const*    path
        ,   size_type           cch
        )
            : parent_class_type(path, cch)
        {}
        basic_path__(class_type const& rhs)
            : parent_class_type(rhs)
        {}

        class_type& operator =(class_type const& rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
        class_type& operator =(char_type const* rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
# ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        template<
            ss_typename_param_k S
        >
        class_type& operator =(S const& s)
        {
            parent_class_type::operator =(s);

            return *this;
        }
# endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    };

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_bool_t
operator ==(
    basic_path<C, T, A> const&                                  lhs
,   ss_typename_type_k basic_path<C, T, A>::char_type const*    rhs
)
{
    return lhs.equal(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_bool_t
operator !=(
    basic_path<C, T, A> const&                                  lhs
,   ss_typename_type_k basic_path<C, T, A>::char_type const*    rhs
)
{
    return !lhs.equal(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_bool_t
operator ==(
    ss_typename_type_k basic_path<C, T, A>::char_type const*    lhs
,   basic_path<C, T, A> const&                                  rhs
)
{
    return rhs.equal(lhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_bool_t
operator !=(
    ss_typename_type_k basic_path<C, T, A>::char_type const*    lhs
,   basic_path<C, T, A> const&                                  rhs
)
{
    return !rhs.equal(lhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_bool_t
operator ==(
    basic_path<C, T, A> const&  lhs
,   basic_path<C, T, A> const&  rhs
)
{
    return lhs.equal(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_bool_t
operator !=(
    basic_path<C, T, A> const&  lhs
,   basic_path<C, T, A> const&  rhs
)
{
    return !lhs.equal(rhs);
}

// operator /

/** Concatenates \c rhs to the path \c lhs
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>
operator /(
    basic_path<C, T, A> const&                                  lhs
,   ss_typename_type_k basic_path<C, T, A>::char_type const*    rhs
)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/** Concatenates \c rhs to the path \c lhs
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>
operator /(
    ss_typename_type_k basic_path<C, T, A>::char_type const*    lhs
,   basic_path<C, T, A> const&                                  rhs
)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/** Concatenates \c rhs to the path \c lhs
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>
operator /(
    basic_path<C, T, A> const&  lhs
,   basic_path<C, T, A> const&  rhs
)
{
    return basic_path<C, T, A>(lhs) /= rhs;
}

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#if !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
     _MSC_VER >= 1100

/** This helper function makes a path variable without needing to
 * qualify the template parameter.
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k C
>
inline
basic_path<C>
make_path(
    C const* path
)
{
    return basic_path<C>(path);
}

# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
swap(
    basic_path<C, T, A>&    lhs
,   basic_path<C, T, A>&    rhs
) STLSOFT_NOEXCEPT
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** \ref group__concept__Shim__string_access__c_str_data for unixstl::basic_path
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
C const*
c_str_data(
    UNIXSTL_NS_QUAL(basic_path)<C, T, A> const& b
)
{
    return b.data();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_char_a_t const*
c_str_data_a(
    UNIXSTL_NS_QUAL(basic_path)<us_char_a_t, T, A> const& b
)
{
    return b.data();
}
template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_char_w_t const*
c_str_data_w(
    UNIXSTL_NS_QUAL(basic_path)<us_char_w_t, T, A> const& b
)
{
    return b.data();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for unixstl::basic_path
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_size_t
c_str_len(
    UNIXSTL_NS_QUAL(basic_path)<C, T, A> const& b
)
{
    return b.size();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_size_t
c_str_len_a(
    UNIXSTL_NS_QUAL(basic_path)<us_char_a_t, T, A> const& b
)
{
    return b.size();
}
template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_size_t
c_str_len_w(
    UNIXSTL_NS_QUAL(basic_path)<us_char_w_t, T, A> const& b
)
{
    return b.size();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/** \ref group__concept__Shim__string_access__c_str_ptr for unixstl::basic_path
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
C const*
c_str_ptr(
    UNIXSTL_NS_QUAL(basic_path)<C, T, A> const& b
)
{
    return b.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_char_a_t const*
c_str_ptr_a(
    UNIXSTL_NS_QUAL(basic_path)<us_char_a_t, T, A> const& b
)
{
    return b.c_str();
}
template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_char_w_t const*
c_str_ptr_w(
    UNIXSTL_NS_QUAL(basic_path)<us_char_w_t, T, A> const& b
)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */



/** \ref group__concept__Shim__string_access__c_str_ptr_null for unixstl::basic_path
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
C const*
c_str_ptr_null(
    UNIXSTL_NS_QUAL(basic_path)<C, T, A> const& b
)
{
    if (b.empty())
    {
        return NULL;
    }

    return b.c_str();
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_char_a_t const*
c_str_ptr_null_a(
    UNIXSTL_NS_QUAL(basic_path)<us_char_a_t, T, A> const& b
)
{
    if (b.empty())
    {
        return NULL;
    }

    return b.c_str();
}
template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
us_char_w_t const*
c_str_ptr_null_w(
    UNIXSTL_NS_QUAL(basic_path)<us_char_w_t, T, A> const& b
)
{
    if (b.empty())
    {
        return NULL;
    }

    return b.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

/** \ref group__concept__Shim__stream_insertion "stream insertion shim" for unixstl::basic_path
 *
 * \ingroup group__concept__Shim__stream_insertion
 */
template<
    ss_typename_param_k S
,   ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
S&
operator <<(
    S&                                          s
,   UNIXSTL_NS_QUAL(basic_path)<C, T, A> const& b
)
{
    s.write(b.data(), b.size());

    return s;
}

////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1300
#  pragma warning(push)
#  pragma warning(disable : 4702)
# endif /* compiler*/

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_param_k basic_path<C, T, A>::char_type&
basic_path<C, T, A>::last_() STLSOFT_NOEXCEPT
{
    UNIXSTL_ASSERT(!empty());

    return m_buffer[size_() - 1];
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::char_type const*
basic_path<C, T, A>::last_slash_(
    ss_typename_param_k basic_path<C, T, A>::char_type const*   buffer
,   ss_typename_param_k basic_path<C, T, A>::size_type          len
) STLSOFT_NOEXCEPT
{
    return traits_type::find_last_path_name_separator(buffer, len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::char_type const*
basic_path<C, T, A>::next_slash_or_end_(
    ss_typename_param_k basic_path<C, T, A>::char_type const* p
) STLSOFT_NOEXCEPT
{
    for (; ; ++p)
    {
        switch (*p)
        {
            case    '/':
#ifdef _WIN32
            case    '\\':
#endif /* _WIN32 */
                ++p;
            case    '\0':

                return p;
            default:

                break;
        }
    }

    return NULL;
}

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1300
#  pragma warning(pop)
# endif /* compiler*/


#ifdef _WIN32

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::char_type
basic_path<C, T, A>::path_name_separator_alt() STLSOFT_NOEXCEPT
{
    return '\\';
}
#endif /* _WIN32 */

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::char_type
basic_path<C, T, A>::path_name_separator() STLSOFT_NOEXCEPT
{
    UNIXSTL_ASSERT('/' == traits_type::path_name_separator());

    return '/';
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_path<C, T, A>::swap(
    basic_path<C, T, A>& rhs
) STLSOFT_NOEXCEPT
{
    m_buffer.swap(rhs.m_buffer);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_param_k basic_path<C, T, A>::class_type&
basic_path<C, T, A>::concat_(
    ss_typename_param_k basic_path<C, T, A>::char_type const*   rhs
,   ss_typename_param_k basic_path<C, T, A>::size_type          cch
)
{
    m_buffer.append(rhs, cch);

    return *this;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::size_type
basic_path<C, T, A>::coalesce_parts_(
    ss_typename_param_k basic_path<C, T, A>::part_buffer_type_& parts
)
{
    ss_typename_param_k part_buffer_type_::iterator src     =   parts.begin();
    ss_typename_param_k part_buffer_type_::iterator dest    =   parts.begin();

    { for (size_type i = 0; i < parts.size(); ++i, ++src)
    {
        if (0 == parts[i].len)
        {
            ; // Skip/overwrite this element
        }
        else
        {
            if (dest != src)
            {
                *dest = *src;
            }

            ++dest;
        }
    }}

    size_type   n = static_cast<size_type>(dest - parts.begin());

    parts.resize(n);

    return n;
}


template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>::basic_path()
    : m_buffer()
{}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* ss_explicit_k */
basic_path<C, T, A>::basic_path(
    ss_typename_type_k basic_path<C, T, A>::char_type const* path
)
    : m_buffer(path)
{}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>::basic_path(
    ss_typename_type_k basic_path<C, T, A>::char_type const*    path
,   ss_typename_type_k basic_path<C, T, A>::size_type           cch
)
    : m_buffer(path, cch)
{}

#ifdef STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>::basic_path(
    basic_path<C, T, A> const& rhs
)
    : m_buffer(rhs.m_buffer)
{}
#endif /* STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR */

#ifdef STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::operator =(
    basic_path<C, T, A> const& path
)
{
    class_type  newPath(path);

    swap(newPath);

    return *this;
}
#endif /* STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::operator =(
    ss_typename_type_k basic_path<C, T, A>::char_type const* path
)
{
    return operator_equal_(path);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::operator_equal_(
    ss_typename_type_k basic_path<C, T, A>::char_type const* path
)
{
    class_type  newPath(path);

    swap(newPath);

    return *this;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_type_ret_k basic_path<C, T, A>::class_type
basic_path<C, T, A>::root(
    ss_typename_type_k basic_path<C, T, A>::char_type const* s
)
{
    return class_type(s);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::push(
    class_type const&   rhs
,   bool_type           bAddPathNameSeparator /* = false */
)
{
    return push_(rhs.data(), rhs.size(), bAddPathNameSeparator);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::push(
    char_type const*    rhs
,   bool_type           bAddPathNameSeparator /* = false */
)
{
    UNIXSTL_ASSERT(NULL != rhs);

    return push_(rhs, traits_type::str_len(rhs), bAddPathNameSeparator);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::push_(
    char_type const*    rhs
,   size_type           cch
,   bool_type           bAddPathNameSeparator
)
{
    UNIXSTL_ASSERT(0 == cch || NULL != rhs);

    if (0 != cch)
    {
        if (traits_type::is_path_rooted(rhs))
        {
            class_type  newPath(rhs);

            swap(newPath);
        }
        else
        {
            class_type  newPath(*this);

            newPath.push_sep();
            newPath.concat_(rhs, traits_type::str_len(rhs));
            if (bAddPathNameSeparator)
            {
                newPath.push_sep();
            }

            swap(newPath);
        }
    }

    return *this;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::push_ext(
    char_type const*    rhs
,   bool_type           bAddPathNameSeparator /* = false */
)
{
    UNIXSTL_ASSERT(NULL != rhs);

    class_type  newPath(*this);

    newPath.pop_sep();
    if ('.' != *rhs)
    {
        static char_type const s_dot[] = { '.', '\0' };

        newPath.concat_(s_dot, 1u);
    }
    newPath.concat_(rhs, traits_type::str_len(rhs));
    if (bAddPathNameSeparator)
    {
        newPath.push_sep();
    }

    swap(newPath);

    return *this;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::push_sep()
{
    if (!empty())
    {
        char_type& last = last_();

        if (path_name_separator() != last)
        {
#ifdef _WIN32
            if (path_name_separator_alt() != last)
#endif /* _WIN32 */
            {
                m_buffer.append(path_name_separator());
            }
        }
    }

    return *this;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::pop(
    bool_type bRemoveTrailingPathNameSeparator /* = true */
) STLSOFT_NOEXCEPT
{
    size_type const rootLen = traits_type::get_root_len_(data_(), size_());

    if (rootLen < size_())
    {
        // we have some non-root content to remove - check if a trailing slash and remove it

        char_type const* lslash = traits_type::find_last_path_name_separator(data_(), size_());

        if (&last_() == lslash)
        {
            m_buffer.pop_last();

            lslash = traits_type::find_last_path_name_separator(data_(), size_());
        }
    }

    if (rootLen < size_())
    {
        // we have some non-root content to remove

        char_type const* lslash = traits_type::find_last_path_name_separator(data_() + rootLen, size_() - rootLen);

        if (NULL == lslash)
        {
            m_buffer.resize(rootLen);
        }
        else
        {
            if (!bRemoveTrailingPathNameSeparator)
            {
                ++lslash;
            }

            m_buffer.resize(size_type(lslash - data_()));
        }
    }

    return *this;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::pop_sep() STLSOFT_NOEXCEPT
{
    if (!empty())
    {
        size_type const len = size();

        if (1 == len &&
            traits_type::is_path_name_separator(m_buffer[0]))
        {
            // It's / or \ - ignore
        }
#ifdef _WIN32
        else if (3 == len &&
                ':' == m_buffer[1] &&
                traits_type::is_path_name_separator(m_buffer[2]))
        {
            // It's drive rooted - ignore
        }
#endif /* _WIN32 */
        else
        {
            char_type* last = &last_();

            if (*last == path_name_separator())
            {
                m_buffer.pop_last();
            }
#ifdef _WIN32
            else if (*last == path_name_separator_alt())
            {
                m_buffer.pop_last();
            }
#endif /* _WIN32 */
        }
    }

    return *this;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::pop_ext() STLSOFT_NOEXCEPT
{
    typedef ss_typename_param_k traits_type::path_classification_type               classification_t_;
    typedef ss_typename_param_k traits_type::path_classification_results_type       results_t_;

    results_t_              results;
    int const               parseFlags  =   0
                                        ;
    classification_t_ const pcls        =   traits_type::path_classify(data_(), size_(), parseFlags, &results);

    STLSOFT_SUPPRESS_UNUSED(pcls);

    if (0 != results.extension.len)
    {
        m_buffer.resize(m_buffer.size() - results.extension.len);
    }

    return *this;
}

#if !defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) || \
    defined(STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED)

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::operator /=(
    basic_path<C, T, A> const& path
)
{
    return push(path);
}

#endif /* !STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT || STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::operator /=(
    ss_typename_type_k basic_path<C, T, A>::char_type const* path
)
{
    return push(path);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
void
basic_path<C, T, A>::clear() STLSOFT_NOEXCEPT
{
    m_buffer.truncate(0);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
basic_path<C, T, A>&
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
bool
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
basic_path<C, T, A>::make_absolute(
    bool_type bRemoveTrailingPathNameSeparator /* = true */
)
{
    if (!empty())
    {
        UNIXSTL_ASSERT(0 != size_());

        buffer_type_    buffer(1);
        size_type const cch = traits_type::get_full_path_name(c_str(), buffer);

        if (0 == cch)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(unixstl_exception("could not determine the absolute path", errno));
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
            return false;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

        class_type      newPath(std::move(buffer), cch);
#else /* ? STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

        class_type      newPath(buffer.data(), cch);
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

        UNIXSTL_ASSERT(newPath.size() == cch);

        if (bRemoveTrailingPathNameSeparator)
        {
            newPath.pop_sep();
        }

        swap(newPath);
    }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    return *this;
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */

    return true;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
basic_path<C, T, A>&
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
bool
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
basic_path<C, T, A>::canonicalise(
    bool_type bRemoveTrailingPathNameSeparator /* = true */
)
{
    if (empty())
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return *this;
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */

        return true;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    typedef ss_typename_param_k traits_type::path_classification_type               classification_t_;
    typedef ss_typename_param_k traits_type::path_classification_results_type       results_t_;

    results_t_              results;
    int const               parseFlags  =   0
                                        ;
    classification_t_ const pcls        =   traits_type::path_classify(data_(), size_(), parseFlags, &results);

    class_type              newPath(*this);
    bool const              is_rooted   =   traits_type::path_is_rooted(pcls);

#ifdef STLSOFT_DEBUG

    STLSOFT_NS_QUAL(pod_fill_n)(&newPath.m_buffer[0] + results.root.len, newPath.m_buffer.size() - results.root.len, static_cast<char_type>('~'));
#endif /* STLSOFT_DEBUG */

    // Basically we scan through the path looking for ./ .\ ..\ and ../

    part_buffer_type_   parts(this->length() / 2);  // Uncanonicalised directory parts
    char_type*          dest    =   &newPath.m_buffer[0] + results.root.len;
    char_type const*    p1      =   data_() + results.root.len;
    char_type const*    p2;
    size_type           num_d   =   0;
    size_type           num_dd  =   0;

    if (this->is_absolute())
    {
#ifdef _WIN32

        if (traits_type::is_path_UNC(this->c_str()))
        {
            UNIXSTL_ASSERT('\\' == m_buffer[0]);
            UNIXSTL_ASSERT('\\' == m_buffer[1]);
            UNIXSTL_ASSERT('\\' != m_buffer[2]);

            char_type const* slash0 = next_slash_or_end_(&m_buffer[3]);
            char_type const* slash1 = next_slash_or_end_(slash0);

            for (us_size_t i = 0, n = slash1 - &m_buffer[0]; i < n; ++i)
            {
                *dest++ = *p1++;
            }
        }
        else if (isalpha(m_buffer[0]) &&
                ':' == m_buffer[1])
        {
            // Copy over the drive letter, colon and slash
            *dest++ = *p1++;
            *dest++ = *p1++;
            *dest++ = *p1++;

            if (path_name_separator_alt() == dest[-1])
            {
                dest[-1] = path_name_separator();
            }
        }
        else
#endif /* _WIN32 */
        {
            *dest++ = path_name_separator();
            ++p1;

#ifdef _WIN32

            if (path_name_separator_alt() == dest[-1])
            {
                dest[-1] = path_name_separator();
            }
#endif /* _WIN32 */
        }
    }

    // 1. Parse the path into an uncanonicalised sequence of directory parts
    {
        size_type   i   =   0;

        for (; '\0' != *p1; ++i)
        {
            p2 = next_slash_or_end_(p1);

            parts[i].len    =   static_cast<size_type>(p2 - p1);
            parts[i].p      =   p1;
            parts[i].type   =   part_type::normal;
            switch (parts[i].len)
            {
                case    1:

                    if ('.' == p1[0])
                    {
                        parts[i].type   =   part_type::dot;

                        ++num_d;
                    }
                    break;
                case    2:

                    if ('.' == p1[0])
                    {
                        if ('.' == p1[1])
                        {
                            parts[i].type   =   part_type::dotdot;

                            ++num_dd;
                        }
                        else if (path_name_separator() == p1[1])
                        {
                            parts[i].type   =   part_type::dot;

                            ++num_d;
                        }
#ifdef _WIN32
                        else if (path_name_separator_alt() == p1[1])
                        {
                            parts[i].type   =   part_type::dot;

                            ++num_d;
                        }
#endif /* _WIN32 */
                    }
                    break;
                case    3:

                    if ('.' == p1[0] &&
                        '.' == p1[1])
                    {
                        if (path_name_separator() == p1[2])
                        {
                            parts[i].type   =   part_type::dotdot;

                            ++num_dd;
                        }
#ifdef _WIN32
                        else if (path_name_separator_alt() == p1[2])
                        {
                            parts[i].type   =   part_type::dotdot;

                            ++num_dd;
                        }
#endif /* _WIN32 */
                    }
                    break;
                default:

                    break;
            }

            p1 = p2;
        }

        parts.resize(i);
    }

    // 2.a Remove all '.' parts
    { for (size_type i = 0; 0 != num_d && i < parts.size(); ++i)
    {
        UNIXSTL_ASSERT(0 != parts[i].len);

        part_type&  part = parts[i];

        if (part_type::dot == part.type)
        {
            part.len = 0;

            --num_d;
        }
    }}

    coalesce_parts_(parts);

    // 2.b Process the '..' parts

    { for (size_type i = 0; 0 != num_dd && i < parts.size(); ++i)
    {
        UNIXSTL_ASSERT(0 != parts[i].len);

        part_type&  part = parts[i];

        if (part_type::dotdot == part.type)
        {
            // Now, regardless of where we're at, we look backwards
            // for the latest available non-empty normal part

            size_type prior = parts.size();

            for (size_t j = 0; j != i; ++j)
            {
                size_type index = i - (j + 1);

                UNIXSTL_ASSERT(index < prior);

                part_type const& index_part = parts[index];

                if (0 != index_part.len &&
                    part_type::normal == index_part.type)
                {
                    prior = index;

                    break;
                }
            }

            if (parts.size() == prior)
            {
                // (still) at start, or having worked back to it

                if (!is_rooted)
                {
                    // permit leading ".."
                }
                else
                {
                    // ignore leading ".."

                    part.len = 0;
                }
            }
            else
            {
                part_type& prior_part = parts[prior];

                part.len        =   0;
                prior_part.len  =   0;
            }

            --num_dd;
        }
    }}

    coalesce_parts_(parts);

    // 2.c "insert" a '.' if we've removed everything.
    if (!is_rooted &&
        parts.empty())
    {
        static const char_type  s_dot[] = { '.', '/' };

        parts.resize(1);
        parts[0].type   =   part_type::dot;
        parts[0].len    =   1;
        parts[0].p      =   s_dot;
    }

    // 3. Write out all the parts back into the new path instance
    {
#ifdef STLSOFT_DEBUG
        STLSOFT_NS_QUAL(pod_fill_n)(dest, newPath.m_buffer.size() - (dest - &newPath.m_buffer[0]), static_cast<char_type>('~'));
#endif /* STLSOFT_DEBUG */

        for (size_type i = 0; i < parts.size(); ++i)
        {
            traits_type::char_copy(dest, parts[i].p, parts[i].len);

            dest += parts[i].len;

#ifdef _WIN32

            if (0 != parts[i].len)
            {
                if (path_name_separator_alt() == dest[-1])
                {
                    dest[-1] = path_name_separator();
                }
            }
#endif
        }

        *dest = '\0';

        newPath.m_buffer.resize(dest - newPath.data());
    }

    if (bRemoveTrailingPathNameSeparator)
    {
        newPath.pop_sep();
    }

    swap(newPath);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    return *this;
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */

    return true;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::string_slice_type
basic_path<C, T, A>::get_location() const STLSOFT_NOEXCEPT
{
    char_type const* const  slash   =   last_slash_(data_(), size_());
    size_type const         len     =   (NULL == slash) ? 0 : (static_cast<size_type>(slash - data_()) + 1);

    return string_slice_type(data_(), len);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::string_slice_type
basic_path<C, T, A>::get_file() const STLSOFT_NOEXCEPT
{
    char_type const* const slash = last_slash_(data_(), size_());

    if (NULL == slash)
    {
        return string_slice_type(data_(), size_());
    }
    else
    {
        size_type const slash_offset = static_cast<size_type>(slash - data_());

        return string_slice_type(slash + 1, size_() - (1 + slash_offset));
    }
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::string_slice_type
basic_path<C, T, A>::get_ext() const STLSOFT_NOEXCEPT
{
    string_slice_type const file    =   get_file();
    char_type const* const  dot     =   stlsoft::c_string::strnchr(file.ptr, file.len, '.');

    if (NULL == dot)
    {
        return string_slice_type();
    }
    else
    {
        return string_slice_type(dot, file.len - static_cast<size_type>(dot - file.ptr));
    }
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::char_type*
basic_path<C, T, A>::data_() STLSOFT_NOEXCEPT
{
    return m_buffer.data();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::char_type const*
basic_path<C, T, A>::data_() const STLSOFT_NOEXCEPT
{
    return m_buffer.data();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::size_type
basic_path<C, T, A>::size_() const STLSOFT_NOEXCEPT
{
    return m_buffer.size();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::size_type
basic_path<C, T, A>::length() const STLSOFT_NOEXCEPT
{
    return size_();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::size_type
basic_path<C, T, A>::size() const STLSOFT_NOEXCEPT
{
    return size_();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::size_type
/* static */ basic_path<C, T, A>::max_size() STLSOFT_NOEXCEPT
{
    return path_buffer_type_::max_size() - 1u;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::empty() const STLSOFT_NOEXCEPT
{
    return 0 == size();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::char_type const*
basic_path<C, T, A>::data() const STLSOFT_NOEXCEPT
{
    return data_();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::char_type const*
basic_path<C, T, A>::c_str() const STLSOFT_NOEXCEPT
{
    UNIXSTL_ASSERT(char_type(0) == m_buffer[size_()]);

    return data_();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::char_type const&
basic_path<C, T, A>::operator [](
    ss_typename_type_k basic_path<C, T, A>::size_type index
) const STLSOFT_NOEXCEPT
{
    UNIXSTL_MESSAGE_ASSERT("Index out of range", !(size_() < index));

    return data()[index];
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::exists() const STLSOFT_NOEXCEPT
{
    return traits_type::file_exists(this->c_str());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::is_rooted() const STLSOFT_NOEXCEPT
{
    return traits_type::is_path_rooted(this->c_str());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::is_absolute() const STLSOFT_NOEXCEPT
{
    return traits_type::is_path_absolute(this->c_str());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::has_sep() const STLSOFT_NOEXCEPT
{
    if (empty())
    {
        return false;
    }

    return traits_type::has_dir_end(this->c_str() + (this->size() - 1));
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_ret_k basic_path<C, T, A>::size_type
basic_path<C, T, A>::copy(
    ss_typename_type_k basic_path<C, T, A>::char_type*  buffer
,   ss_typename_type_k basic_path<C, T, A>::size_type   cchBuffer
) const STLSOFT_NOEXCEPT
{
    return m_buffer.copy(buffer, cchBuffer);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::equivalent(
    basic_path<C, T, A> const& rhs
) const STLSOFT_NOEXCEPT
{
    return equivalent_(rhs.data(), rhs.size());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::equivalent(
    ss_typename_type_k basic_path<C, T, A>::char_type const* rhs
) const STLSOFT_NOEXCEPT
{
    return equivalent_(rhs, STLSOFT_NS_QUAL(c_str_len)(rhs));
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::equivalent_(
    char_type const*    rhs
,   size_type           cch
) const STLSOFT_NOEXCEPT
{
    class_type  lhs_(*this);
    class_type  rhs_(rhs, cch);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    return lhs_.make_absolute(false).canonicalise(true) == rhs_.make_absolute(false).canonicalise(true);
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */

    if (!lhs_.make_absolute(false))
    {
        return false;
    }
    if (!lhs_.canonicalise(false))
    {
        return false;
    }

    if (!rhs_.make_absolute(false))
    {
        return false;
    }
    if (!rhs_.canonicalise(false))
    {
        return false;
    }

    return lhs_.equal(rhs_);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::equal(
    basic_path<C, T, A> const& rhs
) const STLSOFT_NOEXCEPT
{
    if (size() != rhs.size())
    {
        return false;
    }

    return 0 == traits_type::path_str_n_compare(data_(), rhs.data(), size());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_type_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::equal(
    ss_typename_type_k basic_path<C, T, A>::char_type const* rhs
) const STLSOFT_NOEXCEPT
{
    return 0 == traits_type::path_str_compare(data_(), STLSOFT_NS_QUAL(c_str_ptr)(rhs));
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

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<
        ss_typename_param_k C
    ,   ss_typename_param_k T
    ,   ss_typename_param_k A
    >
    inline
    void
    swap(
        UNIXSTL_NS_QUAL(basic_path)<C, T, A>&   lhs
    ,   UNIXSTL_NS_QUAL(basic_path)<C, T, A>&   rhs
    ) STLSOFT_NOEXCEPT
    {
        lhs.swap(rhs);
    }
} /* namespace std */
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::unixstl::c_str_data;
using ::unixstl::c_str_data_a;
using ::unixstl::c_str_data_w;

using ::unixstl::c_str_len;
using ::unixstl::c_str_len_a;
using ::unixstl::c_str_len_w;

using ::unixstl::c_str_ptr;
using ::unixstl::c_str_ptr_a;
using ::unixstl::c_str_ptr_w;

using ::unixstl::c_str_ptr_null;
using ::unixstl::c_str_ptr_null_a;
using ::unixstl::c_str_ptr_null_w;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH */

/* ///////////////////////////// end of file //////////////////////////// */

