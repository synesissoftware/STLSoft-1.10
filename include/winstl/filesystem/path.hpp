/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path.hpp
 *
 * Purpose:     Simple class that represents a path.
 *
 * Created:     1st May 1993
 * Updated:     20th January 2024
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


/** \file winstl/filesystem/path.hpp
 *
 * \brief [C++] Definition of the winstl::basic_path class template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_MAJOR    7
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_MINOR    1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_REVISION 5
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_EDIT     319
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
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_BUFFER
# include <winstl/filesystem/path_buffer.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH_BUFFER */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
#  include <winstl/exception/winstl_exception.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES
# include <stlsoft/memory/util/allocator_features.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES */
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

#ifdef STLSOFT_DEBUG
# include <stlsoft/algorithms/pod.hpp>
#endif

#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

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
 * basic_path
 *
 * This class represents a path, and effectively acts as a C-string of its value.
 */

/** Class used for composing and decomposing file-system paths.
 *
 * \ingroup group__library__FileSystem
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments, this defaults to filesystem_traits<C>
 * \param A The allocator type. On translators that support default template arguments, this defaults to processheap_allocator<C>
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
,   ss_typename_param_k A = processheap_allocator<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = filesystem_traits<C> */
,   ss_typename_param_k A /* = processheap_allocator<C> */
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
    ///
    /// \code
    /// winstl::path  p;
    ///
    /// assert(0 == p.size());
    /// assert("" == p);
    /// \endcode
    basic_path();
    /// Constructs a path from a nul-terminated character string
    ///
    /// \code
    /// winstl::path  p("C:\\Windows");
    ///
    /// assert(10 == p.size());
    /// assert("C:\\Windows" == p);
    /// assert("C:\\WINDOWS" == p);
    /// assert("c:\\windows" == p);
    /// \endcode
    ///
    /// \pre len(path) <= size()
    ss_explicit_k
    basic_path(
        char_type const* path
    );
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
    /// Constructs a path from a string object.
    ///
    /// \remarks The string object may be any type for which the
    ///  <b>c_str_len</b> and <b>c_str_data</b>
    ///  \ref group__concept__Shim__string_access "String Access Shims" are
    ///  defined. The following example shows the use of a window handle
    ///  (HWND). Other types supported are <code>std::exception</code>,
    ///  <code>std::string</code>, <code>stlsoft::simple_string</code>,
    ///  <code>winstl::error_desc</code>, and many more
    ///
    /// \code
    /// HWND          hwndParent = . . .
    /// HWND          hwnd       = winstl::CreateEdit(hwndParent, "C:\\Windows", ES_LEFT, 0, 0, 10, 10, 1001);
    /// winstl::path  p(hwnd);
    ///
    /// assert(10 == p.size());
    /// assert("C:\\Windows" == p);
    /// assert("C:\\WINDOWS" == p);
    /// assert("c:\\windows" == p);
    /// \endcode
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
    ///
    /// \code
    /// winstl::path  p("C:\\Windows\\system32", 10);
    ///
    /// assert(10 == p.size());
    /// assert("C:\\Windows" == p);
    /// assert("C:\\WINDOWS" == p);
    /// assert("c:\\windows" == p);
    /// \endcode
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
    ///
    /// \remarks If the path currently contains path name separators, and
    ///   they are all forward slashes '/', then a forward slash will be
    ///   used; otherwise a backslash '\\' will be used.
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
    /// \htmlonly
    /// <pre>
    /// winstl::path  p("C:\\Windows\\system32\\..");
    ///
    /// assert(p != "C:\\WINDOWS\\");
    /// assert(!p.equal("C:\\WINDOWS\\"));
    /// assert(p.equivalent("C:\\WINDOWS\\"));
    /// </pre>
    /// \endhtmlonly
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
    bool_type               has_dir_end_() const STLSOFT_NOEXCEPT;

    class_type&             push_(char_type const* rhs, size_type cch, bool_type bAddPathNameSeparator);
    class_type&             push_sep_(char_type sep);
    class_type&             concat_(char_type const* rhs, size_type cch);

    char_type&              last_() STLSOFT_NOEXCEPT;
    static char_type const* last_slash_(char_type const* buffer, size_type len) STLSOFT_NOEXCEPT;
    static char_type const* next_slash_or_end_(char_type const* p) STLSOFT_NOEXCEPT;
    static char_type const* next_part_or_end_(char_type const* p) STLSOFT_NOEXCEPT;

    static char_type        path_name_separator() STLSOFT_NOEXCEPT;
    static char_type        path_name_separator_alt() STLSOFT_NOEXCEPT;

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
# ifdef WIN32
    typedef ss_typename_type_k processheap_allocator<
        part_type
    >                                                       part_ator_type_;
# else /* ? OS */
    typedef ss_typename_type_k allocator_selector<
        part_type
    >::allocator_type                                       part_ator_type_;
# endif /* OS */
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

    typedef STLSOFT_NS_QUAL(auto_buffer_old)<
        part_type
    ,   part_ator_type_
# ifdef WIN32
    ,   WINSTL_CONST_MAX_PATH / 2
# endif /* OS */
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
typedef basic_path<ws_char_a_t, filesystem_traits<ws_char_a_t> >       path_a;
/** Specialisation of the basic_path template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_path<ws_char_w_t, filesystem_traits<ws_char_w_t> >       path_w;
/** Specialisation of the basic_path template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_path<TCHAR, filesystem_traits<TCHAR> >                   path;

/* /////////////////////////////////////////////////////////////////////////
 * Support for PlatformSTL redefinition by inheritance+namespace, for confused
 * compilers (e.g. VC++ 6)
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template<
        ss_typename_param_k C
# ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
    ,   ss_typename_param_k T = filesystem_traits<C>
    ,   ss_typename_param_k A = processheap_allocator<C>
# else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
    ,   ss_typename_param_k T /* = filesystem_traits<C> */
    ,   ss_typename_param_k A /* = processheap_allocator<C> */
# endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
    >
    class basic_path__
        : public WINSTL_NS_QUAL(basic_path)<C, T, A>
    {
    private:
        typedef WINSTL_NS_QUAL(basic_path)<C, T, A>                     parent_class_type;
        typedef WINSTL_NS_QUAL(basic_path__)<C, T, A>                   class_type;
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
ws_bool_t
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
ws_bool_t
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
ws_bool_t
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
ws_bool_t
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
ws_bool_t
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
ws_bool_t
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

/** \ref group__concept__Shim__string_access__c_str_data for winstl::basic_path
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
    WINSTL_NS_QUAL(basic_path)<C, T, A> const& b
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
ws_char_a_t const*
c_str_data_a(
    WINSTL_NS_QUAL(basic_path)<ws_char_a_t, T, A> const& b
)
{
    return b.data();
}

template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ws_char_w_t const*
c_str_data_w(
    WINSTL_NS_QUAL(basic_path)<ws_char_w_t, T, A> const& b
)
{
    return b.data();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for winstl::basic_path
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ws_size_t
c_str_len(
    WINSTL_NS_QUAL(basic_path)<C, T, A> const& b
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
ws_size_t
c_str_len_a(
    WINSTL_NS_QUAL(basic_path)<ws_char_a_t, T, A> const& b
)
{
    return b.size();
}

template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ws_size_t
c_str_len_w(
    WINSTL_NS_QUAL(basic_path)<ws_char_w_t, T, A> const& b
)
{
    return b.size();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \ref group__concept__Shim__string_access__c_str_ptr for winstl::basic_path
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
    WINSTL_NS_QUAL(basic_path)<C, T, A> const& b
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
ws_char_a_t const*
c_str_ptr_a(
    WINSTL_NS_QUAL(basic_path)<ws_char_a_t, T, A> const& b
)
{
    return b.c_str();
}

template<
    ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ws_char_w_t const*
c_str_ptr_w(
    WINSTL_NS_QUAL(basic_path)<ws_char_w_t, T, A> const& b
)
{
    return b.c_str();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \ref group__concept__Shim__string_access__c_str_ptr_null for winstl::basic_path
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
    WINSTL_NS_QUAL(basic_path)<C, T, A> const& b
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
ws_char_a_t const*
c_str_ptr_null_a(
    WINSTL_NS_QUAL(basic_path)<ws_char_a_t, T, A> const& b
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
ws_char_w_t const*
c_str_ptr_null_w(
    WINSTL_NS_QUAL(basic_path)<ws_char_w_t, T, A> const& b
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

/** \ref group__concept__Shim__stream_insertion "stream insertion shim" for winstl::basic_path
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
,   WINSTL_NS_QUAL(basic_path)<C, T, A> const&  b
)
{
    s.write(b.data(), b.size());

    return s;
}

////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::bool_type
basic_path<C, T, A>::has_dir_end_() const STLSOFT_NOEXCEPT
{
    if (empty())
    {
        return false;
    }

    return traits_type::has_dir_end(data_() + (size_() - 1));
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
ss_typename_param_k basic_path<C, T, A>::char_type&
basic_path<C, T, A>::last_() STLSOFT_NOEXCEPT
{
    WINSTL_ASSERT(!empty());

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
    for (;;)
    {
        switch (*p)
        {
            case    '/':
            case    '\\':
            case    '\0':

                return p;
            default:

                ++p;
                break;
        }
    }
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::char_type const*
basic_path<C, T, A>::next_part_or_end_(
    ss_typename_param_k basic_path<C, T, A>::char_type const* p
) STLSOFT_NOEXCEPT
{
    for (;;)
    {
        switch (*p)
        {
            case    '/':
            case    '\\':

                ++p;

                // fall through
            case    '\0':

                return p;
            default:

                ++p;
                break;
        }
    }
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::char_type
basic_path<C, T, A>::path_name_separator_alt() STLSOFT_NOEXCEPT
{
    return '/';
}

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline /* static */
ss_typename_param_k basic_path<C, T, A>::char_type
basic_path<C, T, A>::path_name_separator() STLSOFT_NOEXCEPT
{
    WINSTL_ASSERT('\\' == traits_type::path_name_separator());

    return '\\';
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
    WINSTL_ASSERT(NULL != rhs);

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
    typedef ss_typename_param_k traits_type::path_classification_results_type       results_t_;
    typedef ss_typename_param_k traits_type::path_classification_string_slice_type  slice_t_;

    // Algorithm:
    //
    // 1. if rhs empty, do nothing
    // 2. if rhs absolute, then take rhs
    // 3. if rhs is slash-rooted and this is slash-rooted or relative, then take rhs
    // 4. if rhs is drive-letter-relative, then take rhs
    // 5. if rhs is relative and this is drive-letter-relative, then paste rhs directly

    // - otherwise, add

    // - if invalid, throw an exception (but this will happen with take rhs)


    if (0 == cch)
    {
        // 1. if rhs empty, do nothing

        return *this;
    }
    else
    {
        int const               parseFlags2  =   0
                                            ;
        slice_t_                root2;
        path_classification_t   pcls2       =   traits_type::path_classify_root(rhs, cch, parseFlags2, &root2);
        bool const              is_abs2     =   traits_type::path_is_absolute(pcls2);
        bool const              is_rooted2  =   traits_type::path_is_rooted(pcls2);

        if (is_abs2)
        {
            // 2. if rhs absolute, then take rhs

take_rhs:
            class_type newPath(rhs, cch);

            if (bAddPathNameSeparator &&
                !newPath.has_dir_end_())
            {
                newPath.push_sep();
            }

            swap(newPath);

            return *this;
        }
        else
        {
            results_t_              results1;
            int const               parseFlags1  =   0
                                                ;
            path_classification_t   pcls1       =   traits_type::path_classify(data_(), size_(), parseFlags1, &results1);
            bool const              is_abs1     =   traits_type::path_is_absolute(pcls1);

            if (is_rooted2 &&
                !is_abs1)
            {
                // 3. if rhs is slash-rooted and this is slash-rooted or relative, then take rhs

                goto take_rhs;
            }
            else
            if (WinSTL_C_PathType_DriveLetterRelative == pcls2)
            {
                // 4. if rhs is drive-letter-relative, then take rhs

                goto take_rhs;
            }
            else
            {
                if (WinSTL_C_PathType_DriveLetterRelative == pcls1 &&
                    0 == results1.directory.len &&
                    0 == results1.entry.len)
                {
                    // 5. if rhs is relative and this is drive-letter-relative, then paste rhs directly

                    WINSTL_ASSERT(!is_abs2 && !is_rooted2);

                    m_buffer.reserve(m_buffer.size() + 1 + cch + 1);

                    m_buffer.append(rhs, cch);

                    if (bAddPathNameSeparator)
                    {
                        push_sep();
                    }

                    return *this;
                }
            }

            // In an attempt to maintain slash/backslash consistency, we
            // locate the next slash to help guide the push_sep_() method.

            class_type          newPath(*this);
            char_type const*    psep    =   next_slash_or_end_(c_str());
            char_type           sep     =   ('\0' == *psep) ? char_type(0) : psep[0];

            newPath.push_sep_(sep);
            newPath.concat_(rhs, cch);
            if (bAddPathNameSeparator)
            {
                newPath.push_sep();
            }

            swap(newPath);
        }

        return *this;
    }
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
    WINSTL_ASSERT(NULL != rhs);

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
    char_type               sep     =   path_name_separator();

    char_type const* const  slash   =   stlsoft::c_string::strnchr(data_(), size_(), path_name_separator());
    char_type const* const  slash_a =   stlsoft::c_string::strnchr(data_(), size_(), path_name_separator_alt());

    if (NULL == slash &&
        NULL != slash_a)
    {
        sep = path_name_separator_alt();
    }

    return push_sep_(sep);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline
basic_path<C, T, A>&
basic_path<C, T, A>::push_sep_(
    ss_typename_type_k basic_path<C, T, A>::char_type sep
)
{
    if (0 == sep)
    {
        sep = path_name_separator();
    }

    WINSTL_MESSAGE_ASSERT("You can only push a path name separator character recognised by your operating system!", traits_type::is_path_name_separator(sep));

    if (!empty())
    {
        char_type& last = last_();

        if (traits_type::is_path_name_separator(last))
        {
            if (last != sep)
            {
                last = sep;
            }
        }
        else
        {
            m_buffer.append(sep);
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
    typedef ss_typename_param_k traits_type::path_classification_type               classification_t_;
    typedef ss_typename_param_k traits_type::path_classification_results_type       results_t_;

    results_t_              results;
    int const               parseFlags  =   0
                                        |   WINSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARSINLONGPATH
                                        ;
    classification_t_ const pcls        =   traits_type::path_classify(data_(), size_(), parseFlags, &results);
    bool const              is_rooted   =   traits_type::path_is_rooted(pcls);

    if (0 != results.entry.len)
    {
        if (0 != results.entry.len)
        {
            m_buffer.resize(m_buffer.size() - results.entry.len);

            if (bRemoveTrailingPathNameSeparator)
            {
                if (results.numDirectoryParts > (is_rooted ? 1u : 0u))
                {
                    WINSTL_MESSAGE_ASSERT("must have directory", 0 != results.directory.len);
                    WINSTL_MESSAGE_ASSERT("directory must end with slash", traits_type::is_path_name_separator(results.directory.ptr[results.directory.len - 1]));
                    WINSTL_MESSAGE_ASSERT("directory must end with slash", traits_type::is_path_name_separator(m_buffer.data()[m_buffer.size() - 1]));

                    m_buffer.pop_last();
                }
            }
        }
    }
    else
    {
        if (is_rooted)
        {
            WINSTL_ASSERT(0 != results.numDirectoryParts);

            if (1 == results.numDirectoryParts)
            {
                return *this;
            }
        }
        else
        {
            if (0 == results.numDirectoryParts)
            {
                return *this;
            }
        }

        WINSTL_MESSAGE_ASSERT("must have directory", 0 != results.directory.len);
        WINSTL_MESSAGE_ASSERT("directory must end with slash", traits_type::is_path_name_separator(results.directory.ptr[results.directory.len - 1]));

        --results.directory.len;

        char_type* const    slash   =   const_cast<char_type*>(last_slash_(results.directory.ptr, results.directory.len));
        size_t const        cchLess =    slash - results.directory.ptr;

        class_type newPath(results.location.ptr, results.location.len - cchLess);

        if (bRemoveTrailingPathNameSeparator)
        {
            newPath.pop_sep();
        }

        swap(newPath);
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
    // requirements to drop the separator:
    //
    // - does not have an entry, AND
    //   - if rooted, has 2+ directories, OR
    //   - if !rooted, has 1+ directories

    typedef ss_typename_param_k traits_type::path_classification_type               classification_t_;
    typedef ss_typename_param_k traits_type::path_classification_results_type       results_t_;

    results_t_              results;
    int const               parseFlags  =   0
                                        |   WINSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARSINLONGPATH
                                        ;
    classification_t_ const pcls        =   traits_type::path_classify(data_(), size_(), parseFlags, &results);

    if (0 == results.entry.len)
    {
        bool const is_rooted = traits_type::path_is_rooted(pcls);

        if (results.numDirectoryParts > (is_rooted ? 1u : 0u))
        {
            WINSTL_MESSAGE_ASSERT("must have directory", 0 != results.directory.len);
            WINSTL_MESSAGE_ASSERT("directory must end with slash", traits_type::is_path_name_separator(results.directory.ptr[results.directory.len - 1]));
            WINSTL_MESSAGE_ASSERT("directory must end with slash", traits_type::is_path_name_separator(results.input.ptr[results.input.len - 1]));
            WINSTL_MESSAGE_ASSERT("directory must end with slash", traits_type::is_path_name_separator(m_buffer.data()[m_buffer.size() - 1]));

            m_buffer.pop_last();
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
                                        |   WINSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARSINLONGPATH
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
    typedef ss_typename_param_k traits_type::path_classification_string_slice_type  slice_t_;

    int const               parseFlags  =   0
                                        |   WINSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARSINLONGPATH
                                        ;
    slice_t_                root;
    path_classification_t   pcls        =   traits_type::path_classify_root(data_(), size_(), parseFlags, &root);

    switch (pcls)
    {
    case    WinSTL_C_PathType_Empty:
    case    WinSTL_C_PathType_DriveLetterRooted:
    case    WinSTL_C_PathType_UncRooted:
    case    WinSTL_C_PathType_HomeRooted:

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return *this;
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */

        return true;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    default:

        break;
    }

    WINSTL_ASSERT(0 != size_());

    buffer_type_    buffer(1);
    size_type const cch = traits_type::get_full_path_name(c_str(), buffer);

    if (0 == cch)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        DWORD const le = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        STLSOFT_THROW_X(winstl_exception("could not determine the absolute path", le));
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */

        return false;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    class_type      newPath(std::move(buffer), cch);
#else /* ? STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

    class_type      newPath(buffer.data(), cch);
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */

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
                                        |   WINSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARSINLONGPATH
                                        ;
    classification_t_ const pcls        =   traits_type::path_classify(data_(), size_(), parseFlags, &results);

    switch (pcls)
    {
    case    WinSTL_C_PathType_InvalidSlashRuns:
    case    WinSTL_C_PathType_InvalidChars:
    case    WinSTL_C_PathType_Invalid:
    case    WinSTL_C_PathType_Unknown:
    case    WinSTL_C_PathType_Empty:

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        return *this;
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */

        return true;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    case    WinSTL_C_PathType_Relative:
    case    WinSTL_C_PathType_SlashRooted:
    case    WinSTL_C_PathType_DriveLetterRelative:
    case    WinSTL_C_PathType_DriveLetterRooted:
    case    WinSTL_C_PathType_UncIncomplete:
    case    WinSTL_C_PathType_UncRooted:
    case    WinSTL_C_PathType_HomeRooted:
    default:

        break;
    }

    class_type      newPath(*this);
    bool const      is_rooted   =   traits_type::path_is_rooted(pcls);

#ifdef STLSOFT_DEBUG

    STLSOFT_NS_QUAL(pod_fill_n)(&newPath.m_buffer[0] + results.root.len, newPath.m_buffer.size() - results.root.len, static_cast<char_type>('~'));
#endif /* STLSOFT_DEBUG */

    // Basically we scan through the path looking for ./ .\ ..\ and ../

    // 0. Handle special path prefixes

    part_buffer_type_   parts(this->length() / 2);  // Uncanonicalised directory parts
    char_type*          dest    =   &newPath.m_buffer[0] + results.root.len;
    char_type const*    p1      =   data_() + results.root.len;
    char_type const*    p2;
    size_type           num_d   =   0;
    size_type           num_dd  =   0;

    if (is_rooted)
    {
        *dest++ = *p1++;

        if (path_name_separator_alt() == dest[-1])
        {
            dest[-1] = path_name_separator();
        }
    }

    // 1. Parse the path into an uncanonicalised sequence of directory parts
    {
        size_type   i   =   0;

        for (; '\0' != *p1; ++i)
        {
            p2 = next_part_or_end_(p1);

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
                        else if (path_name_separator_alt() == p1[1])
                        {
                            parts[i].type   =   part_type::dot;

                            ++num_d;
                        }
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
                        else if (path_name_separator_alt() == p1[2])
                        {
                            parts[i].type   =   part_type::dotdot;

                            ++num_dd;
                        }
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
        WINSTL_ASSERT(0 != parts[i].len);

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
        WINSTL_ASSERT(0 != parts[i].len);

        part_type&  part = parts[i];

        if (part_type::dotdot == part.type)
        {
            // Now, regardless of where we're at, we look backwards
            // for the latest available non-empty normal part

            size_type prior = parts.size();

            for (size_t j = 0; j != i; ++j)
            {
                size_type index = i - (j + 1);

                WINSTL_ASSERT(index < prior);

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

            if (0 != parts[i].len)
            {
                if (path_name_separator_alt() == dest[-1])
                {
                    dest[-1] = path_name_separator();
                }
            }
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
    WINSTL_ASSERT(char_type(0) == m_buffer[size_()]);

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
    WINSTL_MESSAGE_ASSERT("Index out of range", !(size_() < index));

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

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

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
        WINSTL_NS_QUAL(basic_path)<C, T, A>&    lhs
    ,   WINSTL_NS_QUAL(basic_path)<C, T, A>&    rhs
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

#ifndef WINSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::winstl::c_str_data;
using ::winstl::c_str_data_a;
using ::winstl::c_str_data_w;

using ::winstl::c_str_len;
using ::winstl::c_str_len_a;
using ::winstl::c_str_len_w;

using ::winstl::c_str_ptr;
using ::winstl::c_str_ptr_a;
using ::winstl::c_str_ptr_w;

using ::winstl::c_str_ptr_null;
using ::winstl::c_str_ptr_null_a;
using ::winstl::c_str_ptr_null_w;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH */

/* ///////////////////////////// end of file //////////////////////////// */

