/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/functional/com_predicate_adaptors.hpp
 *
 * Purpose:     Contains the comstl::com_SUCCEEDED and comstl::com_S_OK.
 *
 * Created:     3rd April 2007
 * Updated:     26th December 2020
 *
 * Home:        http://comstl.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/functional/com_predicate_adaptors.hpp
 *
 * \brief [C++] Contains predicates adaptors that interpret the
 *   success of COM functions (that return HRESULT).
 *   (\ref group__library__Functional "Functional" Library).
 */

#ifndef COMSTL_INCL_COMSTL_FUNCTIONAL_HPP_COM_PREDICATE_ADAPTORS
#define COMSTL_INCL_COMSTL_FUNCTIONAL_HPP_COM_PREDICATE_ADAPTORS

#ifndef COMSTL_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_FUNCTIONAL_HPP_COM_PREDICATE_ADAPTORS_MAJOR    1
# define COMSTL_VER_COMSTL_FUNCTIONAL_HPP_COM_PREDICATE_ADAPTORS_MINOR    0
# define COMSTL_VER_COMSTL_FUNCTIONAL_HPP_COM_PREDICATE_ADAPTORS_REVISION 5
# define COMSTL_VER_COMSTL_FUNCTIONAL_HPP_COM_PREDICATE_ADAPTORS_EDIT     15
#endif /* !COMSTL_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_STLSOFT
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_FUNCTIONAL
# define STLSOFT_INCL_FUNCTIONAL
# include <functional>
#endif /* !STLSOFT_INCL_FUNCTIONAL */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** A unary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:unary-function: com_SUCCEEDED_tester_1_stdcall<T<R>, T<A>>]]
template <ss_typename_param_k A0>
struct com_SUCCEEDED_tester_1_stdcall
    : public STLSOFT_NS_QUAL_STD(unary_function)<A0, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          argument_type;
    typedef HRESULT (STLSOFT_STDCALL*   function_type)(argument_type);
public:
    ss_explicit_k com_SUCCEEDED_tester_1_stdcall(function_type func)
        : m_func(func)
    {}
    return_type operator ()(argument_type a) const
    {
        return SUCCEEDED((*m_func)(a));
    }
private:
    function_type m_func;
};

/** A binary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:binary-function: com_SUCCEEDED_tester_2_stdcall<T<R>, T<A0>, T<A1>>]]
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
struct com_SUCCEEDED_tester_2_stdcall
    : public STLSOFT_NS_QUAL_STD(binary_function)<A0, A1, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          first_argument_type;
    typedef A1                          second_argument_type;
    typedef HRESULT (STLSOFT_STDCALL*   function_type)(first_argument_type, second_argument_type);
public:
    ss_explicit_k com_SUCCEEDED_tester_2_stdcall(function_type func)
        : m_func(func)
    {}
    return_type operator ()(first_argument_type a0, second_argument_type a1) const
    {
        return SUCCEEDED((*m_func)(a0, a1));
    }

private:
    function_type m_func;
};


/** A unary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:unary-function: com_SUCCEEDED_tester_1_stdcall<T<R>, T<A>>]]
template <ss_typename_param_k A0>
struct com_S_OK_tester_1_stdcall
    : public STLSOFT_NS_QUAL_STD(unary_function)<A0, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          argument_type;
    typedef HRESULT (STLSOFT_STDCALL*   function_type)(argument_type);
public:
    ss_explicit_k com_S_OK_tester_1_stdcall(function_type func)
        : m_func(func)
    {}
    return_type operator ()(argument_type a) const
    {
        return S_OK == (*m_func)(a);
    }
private:
    function_type m_func;
};

/** A binary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:binary-function: com_S_OK_tester_2_stdcall<T<R>, T<A0>, T<A1>>]]
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
struct com_S_OK_tester_2_stdcall
    : public STLSOFT_NS_QUAL_STD(binary_function)<A0, A1, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          first_argument_type;
    typedef A1                          second_argument_type;
    typedef HRESULT (STLSOFT_STDCALL*   function_type)(first_argument_type, second_argument_type);
public:
    ss_explicit_k com_S_OK_tester_2_stdcall(function_type func)
        : m_func(func)
    {}
    return_type operator ()(first_argument_type a0, second_argument_type a1) const
    {
        return S_OK == (*m_func)(a0, a1);
    }

private:
    function_type m_func;
};

/** A unary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:unary-function: com_SUCCEEDED_tester_1_cdecl<T<R>, T<A>>]]
template <ss_typename_param_k A0>
struct com_SUCCEEDED_tester_1_cdecl
    : public STLSOFT_NS_QUAL_STD(unary_function)<A0, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          argument_type;
    typedef HRESULT (STLSOFT_CDECL*     function_type)(argument_type);
public:
    ss_explicit_k com_SUCCEEDED_tester_1_cdecl(function_type func)
        : m_func(func)
    {}
    return_type operator ()(argument_type a) const
    {
        return SUCCEEDED((*m_func)(a));
    }
private:
    function_type m_func;
};

/** A binary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:binary-function: com_SUCCEEDED_tester_2_cdecl<T<R>, T<A0>, T<A1>>]]
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
struct com_SUCCEEDED_tester_2_cdecl
    : public STLSOFT_NS_QUAL_STD(binary_function)<A0, A1, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          first_argument_type;
    typedef A1                          second_argument_type;
    typedef HRESULT (STLSOFT_CDECL*     function_type)(first_argument_type, second_argument_type);
public:
    ss_explicit_k com_SUCCEEDED_tester_2_cdecl(function_type func)
        : m_func(func)
    {}
    return_type operator ()(first_argument_type a0, second_argument_type a1) const
    {
        return SUCCEEDED((*m_func)(a0, a1));
    }

private:
    function_type m_func;
};


/** A unary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:unary-function: com_SUCCEEDED_tester_1_cdecl<T<R>, T<A>>]]
template <ss_typename_param_k A0>
struct com_S_OK_tester_1_cdecl
    : public STLSOFT_NS_QUAL_STD(unary_function)<A0, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          argument_type;
    typedef HRESULT (STLSOFT_CDECL*     function_type)(argument_type);
public:
    ss_explicit_k com_S_OK_tester_1_cdecl(function_type func)
        : m_func(func)
    {}
    return_type operator ()(argument_type a) const
    {
        return S_OK == (*m_func)(a);
    }
private:
    function_type m_func;
};

/** A binary function adaptor for pointers to COM functions, that
 *    will cause them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
// [[synesis:class:function-class:binary-function: com_S_OK_tester_2_cdecl<T<R>, T<A0>, T<A1>>]]
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
struct com_S_OK_tester_2_cdecl
    : public STLSOFT_NS_QUAL_STD(binary_function)<A0, A1, bool>
{
public:
    typedef bool                        return_type;
    typedef A0                          first_argument_type;
    typedef A1                          second_argument_type;
    typedef HRESULT (STLSOFT_CDECL*     function_type)(first_argument_type, second_argument_type);
public:
    ss_explicit_k com_S_OK_tester_2_cdecl(function_type func)
        : m_func(func)
    {}
    return_type operator ()(first_argument_type a0, second_argument_type a1) const
    {
        return S_OK == (*m_func)(a0, a1);
    }

private:
    function_type m_func;
};

/* /////////////////////////////////////////////////////////////////////////
 * creator functions
 */

/** Creator function to adapt pointers to unary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template <ss_typename_param_k A0>
inline com_SUCCEEDED_tester_1_stdcall<A0> com_SUCCEEDED(HRESULT (STLSOFT_STDCALL *pfn)(A0))
{
    return com_SUCCEEDED_tester_1_stdcall<A0>(pfn);
}

/** Creator function to adapt pointers to unary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template <ss_typename_param_k A0>
inline com_SUCCEEDED_tester_1_cdecl<A0> com_SUCCEEDED(HRESULT (STLSOFT_CDECL *pfn)(A0))
{
    return com_SUCCEEDED_tester_1_cdecl<A0>(pfn);
}

/** Creator function to adapt pointers to binary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
inline com_SUCCEEDED_tester_2_stdcall<A0, A1> com_SUCCEEDED(HRESULT (STLSOFT_STDCALL *pfn)(A0, A1))
{
    return com_SUCCEEDED_tester_2_stdcall<A0, A1>(pfn);
}

/** Creator function to adapt pointers to binary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
inline com_SUCCEEDED_tester_2_cdecl<A0, A1> com_SUCCEEDED(HRESULT (STLSOFT_CDECL *pfn)(A0, A1))
{
    return com_SUCCEEDED_tester_2_cdecl<A0, A1>(pfn);
}

/** Creator function to adapt pointers to unary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template <ss_typename_param_k A0>
inline com_S_OK_tester_1_stdcall<A0> com_S_OK(HRESULT (STLSOFT_STDCALL *pfn)(A0))
{
    return com_S_OK_tester_1_stdcall<A0>(pfn);
}

/** Creator function to adapt pointers to unary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template <ss_typename_param_k A0>
inline com_S_OK_tester_1_cdecl<A0> com_S_OK(HRESULT (STLSOFT_CDECL *pfn)(A0))
{
    return com_S_OK_tester_1_cdecl<A0>(pfn);
}

/** Creator function to adapt pointers to binary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
inline com_S_OK_tester_2_stdcall<A0, A1> com_S_OK(HRESULT (STLSOFT_STDCALL *pfn)(A0, A1))
{
    return com_S_OK_tester_2_stdcall<A0, A1>(pfn);
}

/** Creator function to adapt pointers to binary COM functions,
 *    causing them to act as predicates.
 *
 * \ingroup group__library__Functional
 *
 */
template<   ss_typename_param_k A0
        ,   ss_typename_param_k A1
        >
inline com_S_OK_tester_2_cdecl<A0, A1> com_S_OK(HRESULT (STLSOFT_CDECL *pfn)(A0, A1))
{
    return com_S_OK_tester_2_cdecl<A0, A1>(pfn);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_FUNCTIONAL_HPP_COM_PREDICATE_ADAPTORS */

/* ///////////////////////////// end of file //////////////////////////// */

