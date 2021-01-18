/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/current_directory_scope.hpp
 *
 * Purpose:     Current working directory scoping class.
 *
 * Created:     12th November 1998
 * Updated:     15th January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/current_directory_scope.hpp
 *
 * \brief [C++] Definition of the winstl::basic_current_directory_scope
 *  class template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE_MAJOR     5
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE_MINOR     2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE_REVISION  17
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE_EDIT      143
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

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# error winstl/filesystem/current_directory_scope.hpp is not compatible with Visual C++ 5.0 or earlier
#endif /* compiler */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
#  include <winstl/exception/winstl_exception.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL
# include <stlsoft/util/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL */

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
 * basic_current_directory_scope
 *
 * This class pushes the given directory as the current directory upon
 * construction, and pops back to the original at destruction.
 */

/** Current directory scoping class
 *
 * \ingroup group__library__FileSystem
 *
 * This class scopes the process's current directory, by changing to the path
 * given in the constructor, and then, if that succeeded, changing back in the
 * destructor.
 *
 * \param C The character type (e.g. \c char, \c wchar_t)
 * \param T The file-system traits. In translators that support default template parameters that defaults to \c filesystem_traits<C>
 */

template<
    ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T = filesystem_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = filesystem_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class basic_current_directory_scope
{
public: // types
    /// The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// This type
    typedef basic_current_directory_scope<C, T>             class_type;
    /// The size type
    typedef ws_size_t                                       size_type;
private:
    typedef auto_buffer<
        char_type
    >                                                       buffer_type_;

public: // construction
    /// Constructs a scope instance and changes to the given directory
    ///
    /// \param dir The name of the directory to change the current directory to
    ss_explicit_k basic_current_directory_scope(char_type const* dir);
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT)
    /// Constructs a scope instance and changes to the given directory
    ///
    /// \param dir The name of the directory to change the current directory to
    template <ss_typename_param_k S>
    ss_explicit_k basic_current_directory_scope(S const& dir)
        : m_previous(1)
    {
        init_(STLSOFT_NS_QUAL(c_str_ptr)(dir));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    /// Returns the current directory to its original location
    ~basic_current_directory_scope() STLSOFT_NOEXCEPT;
private:
    basic_current_directory_scope();                    // default-construction proscribed
    basic_current_directory_scope(class_type const&);   // copy-construction proscribed
    class_type const& operator =(class_type const&);    // copy-assignment proscribed

public: // accessors
    /// Returns a C-string pointer to the original directory
    char_type const* get_previous() const;

    /// Returns a C-string pointer to the original directory
    operator char_type const* () const;

private:
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, operator_bool_generator_type, operator_bool_type);
public:
    /// Indicates whether the construction was successful
    ///
    /// \retval true The scope instance was successfully constructed and the current directory changed as per the constructor argument
    /// \retval false The scope instance was not successfully constructed, and the current directory was unchanged.
    operator operator_bool_type() const
    {
        return operator_bool_generator_type::translate('\0' != m_previous[0]);
    }

private: // implementation
    void init_(char_type const* dir);

private: // fields
    buffer_type_    m_previous;
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** Specialisation of the basic_current_directory_scope template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_current_directory_scope<ws_char_a_t, filesystem_traits<ws_char_a_t> >     current_directory_scope_a;
/** Specialisation of the basic_current_directory_scope template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_current_directory_scope<ws_char_w_t, filesystem_traits<ws_char_w_t> >     current_directory_scope_w;
/** Specialisation of the basic_current_directory_scope template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_current_directory_scope<TCHAR, filesystem_traits<TCHAR> >                 current_directory_scope;

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
C const*
c_str_ptr_null(
    basic_current_directory_scope<C, T> const& b
)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(b.get_previous());
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
C const*
c_str_ptr(
    basic_current_directory_scope<C, T> const& b
)
{
    return b.get_previous();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
C const*
c_str_data(
    basic_current_directory_scope<C, T> const& b
)
{
    return b.get_previous();
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
ws_size_t
c_str_len(
    basic_current_directory_scope<C, T> const& b
)
{
    return STLSOFT_NS_QUAL(c_str_len)(b.get_previous());
}

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template<
    ss_typename_param_k S
,   ss_typename_param_k C
,   ss_typename_param_k T
>
inline
S&
operator <<(
    S&                                          s
,   basic_current_directory_scope<C, T> const&  b
)
{
    s << b.get_previous();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
void
basic_current_directory_scope<C, T>::init_(
    ss_typename_type_k basic_current_directory_scope<C, T>::char_type const* dir
)
{
    if (0 == traits_type::get_current_directory(m_previous))
    {
        DWORD const le = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(winstl_exception("could not determine current directory", le));
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
        m_previous[0] = '\0';
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else if (!traits_type::set_current_directory(dir))
    {
        DWORD const le = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(winstl_exception("could not change current directory", le));
#else /* ?STLSOFT_CF_EXCEPTION_SUPPORT */
        m_previous[0] = '\0';
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
basic_current_directory_scope<C, T>::basic_current_directory_scope(
    ss_typename_type_k basic_current_directory_scope<C, T>::char_type const* dir
)
    : m_previous(1)
{
    init_(dir);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
basic_current_directory_scope<C, T>::~basic_current_directory_scope() STLSOFT_NOEXCEPT
{
    if ('\0' != m_previous[0])
    {
        traits_type::set_current_directory(&m_previous[0]);
    }
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
ss_typename_type_ret_k basic_current_directory_scope<C, T>::char_type const*
basic_current_directory_scope<C, T>::get_previous() const
{
    return STLSOFT_NS_QUAL(c_str_ptr)(m_previous);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
#if defined(STLSOFT_COMPILER_IS_GCC)
inline
basic_current_directory_scope<C, T>::operator C const* () const
#else /* ? compiler */
inline
basic_current_directory_scope<C, T>::operator ss_typename_type_k basic_current_directory_scope<C, T>::char_type const* () const
#endif /* compiler */
{
    return get_previous();
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

using ::winstl::c_str_ptr_null;

using ::winstl::c_str_ptr;

using ::winstl::c_str_data;

using ::winstl::c_str_len;

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */

