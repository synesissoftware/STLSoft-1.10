/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/functionals.hpp
 *
 * Purpose:     String function classes
 *
 * Created:     22nd April 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/functionals.hpp
 *
 * \brief [C++] Definition of the stlsoft::quoter and
 *  stlsoft::string_begins_with_function function class templates
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_FUNCTIONALS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_FUNCTIONALS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_FUNCTIONALS_MAJOR       2
# define STLSOFT_VER_STLSOFT_STRING_HPP_FUNCTIONALS_MINOR       2
# define STLSOFT_VER_STLSOFT_STRING_HPP_FUNCTIONALS_REVISION    10
# define STLSOFT_VER_STLSOFT_STRING_HPP_FUNCTIONALS_EDIT        48
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef _STLSOFT_STRING_FUNCTIONALS_NO_STD
# include <functional>
#else /* ? _STLSOFT_STRING_FUNCTIONALS_NO_STD */
# error Now need to write that std_binary_function stuff!!
#endif /* _STLSOFT_STRING_FUNCTIONALS_NO_STD */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("TODO: Need a function that can do quoting (or anything else)"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

/* /////////////////////////////////////////////////////////////////////////
 * function classes
 */

/** Unary function class that returns a quoted form of its argument, if
 * the argument contains spaces
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k S>
struct quoter
    : public STLSOFT_NS_QUAL_STD(unary_function)<char const*, void>
{
public:
    S operator()(S const& s) const
    {
        if (NULL != ::strpbrk(c_str_ptr(s), " \t\""))
        {
            // Check whether it has quotes. If it does, we'll just assume it's ok
            if (NULL != ::strchr(c_str_ptr(s), '"'))
            {
                return s;
            }
            else
            {
                return '"' + s + '"';
            }
        }
        else
        {
            return s;
        }
    }
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/**
 *
 * \note This is a work-in-progress, and is subject to change in a later release
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k C>
struct string_begins_with_function
    : public STLSOFT_NS_QUAL_STD(unary_function)<C const*, ss_bool_t>
{
public:

public:
    string_begins_with_function(C const* prefix)
        : m_prefix(prefix)
        , m_prefixLen(stlsoft::c_str_len(m_prefix))
    {}

public:
    ss_bool_t operator ()(C const* line) const
    {
        return 0 == ::strncmp(line, m_prefix, m_prefixLen);
    }
    template <ss_typename_param_k S>
    ss_bool_t operator ()(S const& line) const
    {
        return operator ()(c_str_ptr(line));
    }

private:
    C const* const  m_prefix;
    const ss_size_t m_prefixLen;
};

/** \note This is a work-in-progress, and is subject to change in a later release
 *
 * \ingroup group__library__String
 */
template <ss_typename_param_k C>
inline string_begins_with_function<C> string_begins_with(C const* prefix)
{
    return string_begins_with_function<C>(prefix);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * predicate classes
 */

#if 0
/** Predicate used to test the equivalence of strings (of
 *    heterogeneous types).
 *
 * \ingroup group__library__String
 *
 */
template<   ss_typename_param_k C
        >
// [[synesis:class:function-class:binary-predicate: string_equal]]
struct string_equal
    : public STLSOFT_NS_QUAL_STD(binary_function)<C const*, C const*, ss_bool_t>
{
public:
    template<   ss_typename_param_k S0
            ,   ss_typename_param_k S1
            >
    ss_bool_t operator ()(S0 const& s0, S1 const& s1) const
    {
        return compare_(STLSOFT_NS_QUAL(c_str_data)(s0)
                    ,   STLSOFT_NS_QUAL(c_str_len)(s0)
                    ,   STLSOFT_NS_QUAL(c_str_data)(s1)
                    ,   STLSOFT_NS_QUAL(c_str_len)(s1));
    }

private:
    static ss_bool_t compare_(ss_char_a_t const* p0, ss_size_t l0, ss_char_a_t const* p1, ss_size_t l1)
    {
        return (l0 != l1) ? false : 0 == ::strncmp(p0, p1, l0);
    }
    static ss_bool_t compare_(ss_char_w_t const* p0, ss_size_t l0, ss_char_w_t const* p1, ss_size_t l1)
    {
        return (l0 != l1) ? false : 0 == ::wcsncmp(p0, p1, l0);
    }
};
#endif /* 0 */

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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_FUNCTIONALS */

/* ///////////////////////////// end of file //////////////////////////// */

