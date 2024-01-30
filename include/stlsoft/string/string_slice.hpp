/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/string_slice.hpp
 *
 * Purpose:     Defines the string_slice class template.
 *
 * Created:     22nd February 2010
 * Updated:     30th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/string_slice.hpp
 *
 * \brief [C++] Definition of the stlsoft::string_slice class template
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE
#define STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_SLICE_MAJOR      1
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_SLICE_MINOR      6
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_SLICE_REVISION   1
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_SLICE_EDIT       32
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
# include <stlsoft/string/string_slice.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/// A type for describing string slices
template<
    ss_typename_param_k C
,   ss_typename_param_k T = stlsoft_char_traits<C>
,   ss_typename_param_k P = ss_typename_type_def_k string_slice_selection_traits_t<C>::slice_type
>
struct string_slice
    : public P
{
public: // Member Types
    /// The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
private:
    typedef P                                               parent_class_type;
public:
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The class type
    typedef string_slice<char_type, traits_type, P>         class_type;
    /// The boolean type
    typedef ss_bool_t                                       bool_type;
    /// The comparison type
    typedef int                                             int_type;
    /// The value type
    typedef C                                               value_type;
    /// The non-mutating (const) iterator type
    typedef C const*                                        const_iterator;

public: // Construction
    /// Default constructor
    string_slice()
        : parent_class_type()
    {}
    /// Constructs instance from string pointer and length
    string_slice(char_type const* s, size_type n)
        : parent_class_type(parent_class_type::create(s, n))
    {
        STLSOFT_ASSERT(0u == n || NULL != s);
    }
    /// Constructs instance from string pointer and length
    ss_explicit_k string_slice(char_type const* s)
        : parent_class_type(parent_class_type::create( STLSOFT_NS_QUAL(c_str_data)(s), STLSOFT_NS_QUAL(c_str_len)(s)))
    {}
    /// Copy constructor
    string_slice(string_slice const& rhs)
        : parent_class_type(parent_class_type::create(rhs.ptr, rhs.len))
    {}

    /// Copy assignment operator
    string_slice& operator =(string_slice const& rhs)
    {
        this->len = rhs.len;
        this->ptr = rhs.ptr;

        return *this;
    }

    /// Swaps the contents of this slice with \c rhs
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        std_swap(this->len, rhs.len);
        std_swap(this->ptr, rhs.ptr);
    }


public: // Attributes
    size_type size() const STLSOFT_NOEXCEPT
    {
        return this->len;
    }
    size_type length() const STLSOFT_NOEXCEPT
    {
        return size();
    }
    ss_bool_t empty() const STLSOFT_NOEXCEPT
    {
        return 0 == this->len;
    }

public: // Accessors
    value_type const* data() const STLSOFT_NOEXCEPT
    {
        return this->ptr;
    }

public: // Comparison
    /// Determines whether the current instance is equal to the given
    /// instance
    bool_type equals(class_type const& rhs) const STLSOFT_NOEXCEPT
    {
        return this->len == rhs.len && (this->ptr == rhs.ptr || 0 == traits_type::compare(this->ptr, rhs.ptr, this->len));
    }

    /// Determines whether the current instance is equal to the given
    /// string
    bool_type equals(char_type const* s) const STLSOFT_NOEXCEPT
    {
        return equals(class_type(s));
    }

    /// Compares the current instance with the given instance
    int_type compare(class_type const& rhs) const STLSOFT_NOEXCEPT
    {
        size_type   n   =   (this->len < rhs.len) ? this->len : rhs.len;
        int_type    r   =   traits_type::compare(this->ptr, rhs.ptr, n);

        if (0 == r &&
            (this->len != rhs.len))
        {
            return (this->len < rhs.len) ? -1 : +1;
        }

        return r;
    }

    /// Compares the current instance with the given string
    int_type compare(char_type const* s) const STLSOFT_NOEXCEPT
    {
        return compare(class_type(s));
    }


public: // Iteration
    /// Begins the iteration
    ///
    /// \return A non-mutable (const) iterator representing the start of the sequence
    const_iterator          begin() const STLSOFT_NOEXCEPT
    {
        return this->ptr;
    }
    /// Ends the iteration
    ///
    /// \return A non-mutable (const) iterator representing the end of the sequence
    const_iterator          end() const STLSOFT_NOEXCEPT
    {
        return this->ptr + this->len;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * comparison operators
 */

/* slice, slice */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator ==(
    string_slice<C, T, P> const& lhs
,   string_slice<C, T, P> const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.equals(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator !=(
    string_slice<C, T, P> const& lhs
,   string_slice<C, T, P> const& rhs
) STLSOFT_NOEXCEPT
{
    return !lhs.equals(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator <(
    string_slice<C, T, P> const& lhs
,   string_slice<C, T, P> const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) < 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator >(
    string_slice<C, T, P> const& lhs
,   string_slice<C, T, P> const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) > 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator <=(
    string_slice<C, T, P> const& lhs
,   string_slice<C, T, P> const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) <= 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator >=(
    string_slice<C, T, P> const& lhs
,   string_slice<C, T, P> const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) >= 0;
}

/* slice, char_type const* */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator ==(
    string_slice<C, T, P> const&                               lhs
,   ss_typename_type_k string_slice<C, T, P>::char_type const* rhs
) STLSOFT_NOEXCEPT
{
    return lhs.equals(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator !=(
    string_slice<C, T, P> const&                               lhs
,   ss_typename_type_k string_slice<C, T, P>::char_type const* rhs
) STLSOFT_NOEXCEPT
{
    return !lhs.equals(rhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator <(
    string_slice<C, T, P> const&                               lhs
,   ss_typename_type_k string_slice<C, T, P>::char_type const* rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) < 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator >(
    string_slice<C, T, P> const&                               lhs
,   ss_typename_type_k string_slice<C, T, P>::char_type const* rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) > 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator <=(
    string_slice<C, T, P> const&                               lhs
,   ss_typename_type_k string_slice<C, T, P>::char_type const* rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) <= 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator >=(
    string_slice<C, T, P> const&                               lhs
,   ss_typename_type_k string_slice<C, T, P>::char_type const* rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) >= 0;
}

/* char_type const*, slice */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator ==(
    ss_typename_type_k string_slice<C, T, P>::char_type const* lhs
,   string_slice<C, T, P> const&                               rhs
) STLSOFT_NOEXCEPT
{
    return rhs.equals(lhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator !=(
    ss_typename_type_k string_slice<C, T, P>::char_type const* lhs
,   string_slice<C, T, P> const&                               rhs
) STLSOFT_NOEXCEPT
{
    return !rhs.equals(lhs);
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator <(
    ss_typename_type_k string_slice<C, T, P>::char_type const* lhs
,   string_slice<C, T, P> const&                               rhs
) STLSOFT_NOEXCEPT
{
    return rhs.compare(lhs) > 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator >(
    ss_typename_type_k string_slice<C, T, P>::char_type const* lhs
,   string_slice<C, T, P> const&                               rhs
) STLSOFT_NOEXCEPT
{
    return rhs.compare(lhs) < 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator <=(
    ss_typename_type_k string_slice<C, T, P>::char_type const* lhs
,   string_slice<C, T, P> const&                               rhs
) STLSOFT_NOEXCEPT
{
    return rhs.compare(lhs) > 0;
}

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
ss_typename_type_k string_slice<C, T, P>::bool_type
operator >=(
    ss_typename_type_k string_slice<C, T, P>::char_type const* lhs
,   string_slice<C, T, P> const&                               rhs
) STLSOFT_NOEXCEPT
{
    return rhs.compare(lhs) < 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k P
>
inline
void
swap(
    string_slice<C, T, P>& lhs
,   string_slice<C, T, P>& rhs
) STLSOFT_NOEXCEPT
{
    lhs.swap(rhs);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE */

/* ///////////////////////////// end of file //////////////////////////// */

