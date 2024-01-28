/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/environment_variable.hpp
 *
 * Purpose:     Simple class that provides access to an environment variable.
 *
 * Created:     20th December 2002
 * Updated:     20th January 2024
 *
 * Thanks to:   Pablo Aguilar for requesting size() and empty().
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


/** \file winstl/system/environment_variable.hpp
 *
 * \brief [C++] Definition of the winstl::basic_environment_variable
 *  class template
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_ENVIRONMENT_VARIABLE
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_ENVIRONMENT_VARIABLE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_ENVIRONMENT_VARIABLE_MAJOR    4
# define WINSTL_VER_WINSTL_SYSTEM_HPP_ENVIRONMENT_VARIABLE_MINOR    4
# define WINSTL_VER_WINSTL_SYSTEM_HPP_ENVIRONMENT_VARIABLE_REVISION 3
# define WINSTL_VER_WINSTL_SYSTEM_HPP_ENVIRONMENT_VARIABLE_EDIT     86
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

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>      // for get_environment_variable()
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */

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
 * basic_environment_variable
 *
 * This class converts a relative path to an absolute one, and effectively acts
 * as a C-string of its value.
 */

/** Represents an environment variable
 *
 * \ingroup group__library__System
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments, this defaults to system_traits<C>
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = system_traits<C>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = system_traits<C> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_environment_variable
{
public:
    /// The char type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The allocator type
    typedef processheap_allocator<C>                        allocator_type;
    /// The current specialisation of the type
    typedef basic_environment_variable<C, T>                class_type;
    /// The size type
    typedef ws_size_t                                       size_type;
    /// The difference type
    typedef ws_ptrdiff_t                                    difference_type;
    /// The Boolean type
    typedef ws_bool_t                                       bool_type;
private:
    typedef STLSOFT_NS_QUAL(auto_buffer_old)<
        char_type
    ,   allocator_type
    >                                                       buffer_type_;

// Construction
public:
    /// Create an instance representing the given environment variable
    ss_explicit_k basic_environment_variable(char_type const* name)
        : m_buffer(1)
        , m_exists(obtain_(STLSOFT_NS_QUAL(c_str_ptr)(name), m_buffer))
    {}
#ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT

    /// Create an instance representing the given environment variable
    template<ss_typename_param_k S>
    ss_explicit_k basic_environment_variable(S const& name)
        : m_buffer(1)
        , m_exists(obtain_(STLSOFT_NS_QUAL(c_str_ptr)(name), m_buffer))
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
private:
    basic_environment_variable(class_type const&);  // copy-construction proscribed
    class_type& operator =(class_type const&);      // copy-assignment proscribed

// Conversions
public:
    /// Implicit conversion to a non-mutable (const) pointer to the variable
    operator char_type const* () const
    {
        return m_buffer.data();
    }

public: // accessors
    /// Returns a pointer to a nul-terminated string
    char_type const* c_str() const
    {
        return m_buffer.data();
    }

    /// A non-null pointer to the stored characters
    char_type const*
    data() const
    {
        return m_buffer.data();
    }

    /// Returns the length of the variable
    size_type length() const
    {
        return size();
    }
    /// Returns the length of the variable
    size_type size() const
    {
        return m_buffer.size() - 1;
    }
    /// Indicate whether the environment variable is empty
    ///
    /// \note If the variable does not exist, this method will
    ///   true. Use exists()
    ///
    /// \see exists()
    bool_type empty() const
    {
        return 0u == size();
    }
    /// Indicates whether the environment variable exists
    bool_type exists() const
    {
        return m_exists;
    }

public: // comparison
    /// Determines whether the given string contains the same value
    template <ss_typename_param_k T_string>
    bool
    equal(
        T_string const&   s
    ) const
    {
        return equal_n_(
            this->data(), this->size()
        ,   stlsoft::c_str_data(s), stlsoft::c_str_len(s)
        );
    }

    /// Determines whether the given instance contains the same value
    bool
    equal(class_type const& rhs) const
    {
        if (rhs.size() != size())
        {
            return false;
        }

        return 0 == traits_type::str_n_compare(data(), rhs.data(), rhs.size());
    }

    /// Determines whether the given string contains the same value, ignoring case
    template <ss_typename_param_k T_string>
    bool
    equal_ignore_case(
        T_string const&   s
    ) const
    {
        return equal_n_ignore_case_(
            this->data(), this->size()
        ,   stlsoft::c_str_data(s), stlsoft::c_str_len(s)
        );
    }

private: // implementation
    bool
    equal_n_(
        char_type const*  s1
    ,   size_type         cch1
    ,   char_type const*  s2
    ,   size_type         cch2
    ) const
    {
        if (cch1 != cch2)
        {
            return false;
        }

        return 0 == traits_type::str_n_compare(s1, s2, cch2);
    }

    bool
    equal_n_ignore_case_(
        char_type const*  s1
    ,   size_type         cch1
    ,   char_type const*  s2
    ,   size_type         cch2
    ) const
    {
        if (cch1 != cch2)
        {
            return false;
        }

        return 0 == traits_type::str_n_compare_no_case(s1, s2, cch2);
    }

    static
    bool_type
    obtain_(
        char_type const*    name
    ,   buffer_type_&       buffer
    )
    {
        WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(0);

        if (0 != traits_type::get_environment_variable(name, buffer))
        {
            return true;
        }

        bool const r = 0 == WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();

        buffer.resize(1);
        buffer[0] = char_type(0);

        return r;
    }

// fields
private:
    buffer_type_    m_buffer;
    bool_type       m_exists;
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** Specialisation of the basic_environment_variable template for the ANSI character type \c char
 *
 * \ingroup group__library__System
 */
typedef basic_environment_variable<ws_char_a_t, system_traits<ws_char_a_t> >    environment_variable_a;
/** Specialisation of the basic_environment_variable template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__System
 */
typedef basic_environment_variable<ws_char_w_t, system_traits<ws_char_w_t> >    environment_variable_w;
/** Specialisation of the basic_environment_variable template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__System
 */
typedef basic_environment_variable<TCHAR, system_traits<TCHAR> >                environment_variable;

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k S
>
inline
bool
operator ==(
    basic_environment_variable<C, T> const& lhs
,   S const&                                rhs
)
{
    return lhs.equal(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k S
>
inline
bool
operator !=(
    basic_environment_variable<C, T> const& lhs
,   S const&                                rhs
)
{
    return !lhs.equal(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k S
>
inline
bool
operator ==(
    S const&                                lhs
,   basic_environment_variable<C, T> const& rhs
)
{
    return rhs.equal(lhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k S
>
inline
bool
operator !=(
    S const&                                lhs
,   basic_environment_variable<C, T> const& rhs
)
{
    return !rhs.equal(lhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
bool
operator ==(
    basic_environment_variable<C, T> const& lhs
,   basic_environment_variable<C, T> const& rhs
)
{
    return rhs.equal(lhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
>
inline
bool
operator !=(
    basic_environment_variable<C, T> const& lhs
,   basic_environment_variable<C, T> const& rhs
)
{
    return !rhs.equal(lhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1100

/** This helper function makes an environment variable without needing to
 * qualify the template parameter.
 *
 * \ingroup group__library__System
 */
template<ss_typename_param_k C>
inline
basic_environment_variable<C>
make_environment_variable(
    C const* path
)
{
    return basic_environment_variable<C>(path);
}

#endif /* compiler */

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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_ENVIRONMENT_VARIABLE */

/* ///////////////////////////// end of file //////////////////////////// */

