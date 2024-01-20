/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/functionals.hpp
 *
 * Purpose:     File-system related functions and predicates.
 *
 * Created:     19th January 2002
 * Updated:     20th January 2024
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


/** \file winstl/filesystem/functionals.hpp
 *
 * \brief [C++] Definition of the winstl::path_compare,
 *  winstl::path_compare_env, winstl::path_exists, winstl::path_exists_env
 *  and winstl::directory_contains_file function classes
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FUNCTIONALS
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FUNCTIONALS_MAJOR     4
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FUNCTIONALS_MINOR     2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FUNCTIONALS_REVISION  5
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_FUNCTIONALS_EDIT      104
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
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING
# include <winstl/shims/access/string.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef _WINSTL_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _WINSTL_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _WINSTL_FUNCTIONALS_NO_STD */

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
 * utility functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_OPEN_WORKER_NS_(ximpl_winstl_filesystem_functionals_)

template<
    ss_typename_param_k T_character
>
inline
bool
path_exists_envx_(
    T_character const*  s
,   ws_bool_t           bExpandEnvironmentStrings
)
{
    typedef filesystem_traits<
        T_character
    >                                                   traits_t;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        T_character
    >                                                   buffer_t;

    buffer_t    nvx(1);
    buffer_t    full(1);

    if (bExpandEnvironmentStrings &&
        NULL == traits_t::str_chr(s, '%'))
    {
        bExpandEnvironmentStrings = false;
    }

    if (bExpandEnvironmentStrings)
    {
        if (0 == traits_t::expand_environment_strings(s, nvx))
        {
            return false;
        }
        else
        {
            s = nvx.data();
        }
    }

    if (!traits_t::get_full_path_name(s, full))
    {
        return false;
    }
    else
    {
        return traits_t::file_exists(&full[0]);
    }
}

template<
    ss_typename_param_k T_character
>
inline
bool
paths_are_equal_envx_(
    T_character const*  s1
,   T_character const*  s2
,   ws_bool_t           bExpandEnvironmentStrings
)
{
    typedef filesystem_traits<
        T_character
    >                                                   traits_t;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        T_character
    >                                                   buffer_t;

    buffer_t    full1(1);
    buffer_t    full2(1);
    buffer_t    nvx1(1);
    buffer_t    nvx2(1);

    if (bExpandEnvironmentStrings &&
        NULL == traits_t::str_chr(s1, '%') &&
        NULL == traits_t::str_chr(s2, '%'))
    {
        bExpandEnvironmentStrings = false;
    }

    if (bExpandEnvironmentStrings)
    {
        if (0 == traits_t::expand_environment_strings(s1, nvx1) ||
            0 == traits_t::expand_environment_strings(s2, nvx2))
        {
            return false;
        }
        else
        {
            s1 = nvx1.data();
            s2 = nvx2.data();
        }
    }

    if (0 == traits_t::get_full_path_name(s1, full1) ||
        0 == traits_t::get_full_path_name(s2, full2))
    {
        return false;
    }
    else
    {
        traits_t::remove_dir_end(full1);
        traits_t::remove_dir_end(full2);

        s1 = full1.data();
        s2 = full2.data();
    }

    return 0 == traits_t::str_compare_no_case(s1, s2);
}

STLSOFT_CLOSE_WORKER_NS_(ximpl_winstl_filesystem_functionals_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Binary predicate that compares two file-system paths.
 *
 * \ingroup group__library__FileSystem
 *
 * \note Does not expand environment variables in the argument passed to
 * the function call operator
 *
 * \param T_character The character type
 * \param A1 The left-hand argument type; defaults to T_character const*
 * \param A2 The right-hand argument type; defaults to T_character const*
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k A1 = T_character const*
,   ss_typename_param_k A2 = T_character const*
>
// [[synesis:class:function-class:binary-predicate: path_compare<T<T_character>, T<A1>, T<A2>>]]
struct path_compare
    : public STLSOFT_NS_QUAL_STD(binary_function)<A1, A2, ws_bool_t>
{
private: // types
    typedef STLSOFT_NS_QUAL_STD(binary_function)<A1, A2, ws_bool_t>     parent_class_type;
public:
    /// The character type
    typedef T_character                                                 char_type;
    /// The first argument type
    typedef ss_typename_type_k parent_class_type::first_argument_type   first_argument_type;
    /// The second argument type
    typedef ss_typename_type_k parent_class_type::second_argument_type  second_argument_type;
    /// The result type
    typedef ss_typename_type_k parent_class_type::result_type           result_type;
    /// The current specialisation of the type
    typedef path_compare<T_character, A1, A2>                           class_type;

public: // operations
    /// Function call, compares \c s1 with \c s2
    ///
    /// \note The comparison is determined by evaluation the full-paths of both \c s1 and \c s2
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template<ss_typename_param_k T1, ss_typename_param_k T2>
    result_type operator ()(T1 const& s1, T2 const& s2) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    result_type operator ()(first_argument_type s1, second_argument_type s2) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_filesystem_functionals_, paths_are_equal_envx_)(STLSOFT_NS_QUAL(c_str_ptr)(s1), STLSOFT_NS_QUAL(c_str_ptr)(s2), false);
    }
};

/** Binary predicate object that compares two file-system paths,
 * after expanding environment variables in the compared path strings.
 *
 * \ingroup group__library__FileSystem
 *
 * \note Does not expand environment variables in the argument passed to
 * the function call operator
 *
 * \param T_character The character type
 * \param A1 The left-hand argument type; defaults to T_character const*
 * \param A2 The right-hand argument type; defaults to T_character const*
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k A1 = T_character const*
,   ss_typename_param_k A2 = T_character const*
>
// [[synesis:class:function-class:binary-predicate: path_compare_env<T<T_character>, T<A1>, T<A2>>]]
struct path_compare_env
    : public STLSOFT_NS_QUAL_STD(binary_function)<A1, A2, ws_bool_t>
{
private: // types
    typedef STLSOFT_NS_QUAL_STD(binary_function)<A1, A2, ws_bool_t>     parent_class_type;
public:
    /// The character type
    typedef T_character                                                 char_type;
    /// The first argument type
    typedef ss_typename_type_k parent_class_type::first_argument_type   first_argument_type;
    /// The second argument type
    typedef ss_typename_type_k parent_class_type::second_argument_type  second_argument_type;
    /// The result type
    typedef ss_typename_type_k parent_class_type::result_type           result_type;
    /// The current specialisation of the type
    typedef path_compare_env<T_character, A1, A2>                       class_type;

public: // operations
    /// Function call, compares \c s1 with \c s2
    ///
    /// \note The comparison is determined by evaluation the full-paths of both \c s1 and \c s2
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template<ss_typename_param_k T1, ss_typename_param_k T2>
    result_type operator ()(T1 const& s1, T2 const& s2) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    result_type operator ()(first_argument_type s1, second_argument_type s2) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_filesystem_functionals_, paths_are_equal_envx_)(STLSOFT_NS_QUAL(c_str_ptr)(s1), STLSOFT_NS_QUAL(c_str_ptr)(s2), true);
    }
};

/** Unary predicate that indicates whether a given path exists.
 *
 * \ingroup group__library__FileSystem
 *
 * \note Does not expand environment variables in the argument passed to
 * the function call operator
 *
 * \param T_character The character type
 * \param A The argument type; defaults to T_character const*
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k A = T_character const*
>
// [[synesis:class:function-class:unary-predicate: path_exists<T<T_character>, T<A>>]]
struct path_exists
    : public STLSOFT_NS_QUAL_STD(unary_function)<A, ws_bool_t>
{
private: // types
    typedef STLSOFT_NS_QUAL_STD(unary_function)<
        A
    ,   ws_bool_t
    >                                                       parent_class_type;
public:
    /// The character type
    typedef T_character                                     char_type;
    /// The argument type
    typedef A                                               argument_type;
    /// The current specialisation of the type
    typedef path_exists<T_character, A>                     class_type;

public: // operations
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    ws_bool_t operator ()(S const& s) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    ws_bool_t operator ()(argument_type s) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_filesystem_functionals_, path_exists_envx_)(STLSOFT_NS_QUAL(c_str_ptr)(s), false);
    }
};

/** Unary predicate that indicates whether a given path exists, after
 * expanding environment variables in the path string.
 *
 * \ingroup group__library__FileSystem
 *
 * \note Expands environment variables in the argument passed to
 * the function call operator
 *
 * \param T_character The character type
 * \param A The argument type; defaults to T_character const*
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k A = T_character const*
>
// [[synesis:class:function-class:unary-predicate: path_exists_env<T<T_character>, T<A>>]]
struct path_exists_env
    : public STLSOFT_NS_QUAL_STD(unary_function)<A, ws_bool_t>
{
private: // types
    typedef STLSOFT_NS_QUAL_STD(unary_function)<
        A
    ,   ws_bool_t
    >                                                       parent_class_type;
public:
    /// The character type
    typedef T_character                                     char_type;
    /// The argument type
    typedef A                                               argument_type;
    /// The current specialisation of the type
    typedef path_exists_env<T_character, A>                 class_type;

public: // operations
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    ws_bool_t operator ()(S const& s) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    ws_bool_t operator ()(argument_type s) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_filesystem_functionals_, path_exists_envx_)(STLSOFT_NS_QUAL(c_str_ptr)(s), true);
    }
};


/** Unary predicate that searches for the existance of a given file
 *  in the directory presented in its function call argument.
 *
 * \ingroup group__library__FileSystem
 *
 * \param T_character The character type
 * \param A The argument type; defaults to T_character const*
 */

/** \note The file-name passed to the constructor is retained as a
 *    pointer, rather than an instance of a string class. Consequently, the
 *    behaviour is undefined if the memory pointed to by the constructor
 *    argument does not persist for the lifetime of the function object.
 *
 * \ingroup group__library__FileSystem
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k A = T_character const*
>
// [[synesis:class:function-class:unary-predicate: directory_contains_file<T<T_character>, T<A>>]]
struct directory_contains_file
    : public STLSOFT_NS_QUAL_STD(unary_function)<A, ws_bool_t>
{
private: // types
    typedef STLSOFT_NS_QUAL_STD(unary_function)<
        A
    ,   ws_bool_t
    >                                                       parent_class_type;
public:
    /// The character type
    typedef T_character                                     char_type;
    /// The argument type
    typedef A                                               argument_type;
    /// The current specialisation of the type
    typedef directory_contains_file<T_character, A>         class_type;

public: // construction
    ss_explicit_k
    directory_contains_file(char_type const* file)
        : m_file(file)
    {}

public: // operations
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
    template <ss_typename_param_k S>
    ws_bool_t operator ()(S const& s) const
#else /* ? STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    ws_bool_t operator ()(argument_type s) const
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    {
        return directory_contains_file_(STLSOFT_NS_QUAL(c_str_ptr)(s), m_file);
    }

private: // implementation
    static
    ws_bool_t
    directory_contains_file_(
        char_type const*    directory
    ,   char_type const*    file
    )
    {
        typedef filesystem_traits<
            char_type
        >                                                   traits_t;
        typedef STLSOFT_NS_QUAL(auto_buffer)<
            char_type
        >                                                   buffer_t;

        ws_size_t const cchDirectory    =   traits_t::str_len(directory);
        ws_bool_t const hasEnd          =   traits_t::has_dir_end(directory);
        ws_size_t const cchBase         =   cchDirectory + (hasEnd ? 0 : 1);
        ws_size_t const cchFile         =   traits_t::str_len(file);
        ws_size_t const cchPath         =   cchBase + cchFile;

        buffer_t        path(cchPath + 1);

        traits_t::char_copy(&path[0], directory, cchDirectory);
        path[cchDirectory] = '\0';
        if (!hasEnd)
        {
            traits_t::ensure_dir_end(&path[0]);
        }
        traits_t::char_copy(&path[0] + cchBase, file, cchFile);
        path[cchPath] = '\0';

        return traits_t::file_exists(path.data());
    }

private: // fields
    char_type const* m_file;
};

#ifdef STLSOFT_OBSOLETE
typedef directory_contains_file                             path_contains_file;
#endif // STLSOFT_OBSOLETE

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FUNCTIONALS */

/* ///////////////////////////// end of file //////////////////////////// */

