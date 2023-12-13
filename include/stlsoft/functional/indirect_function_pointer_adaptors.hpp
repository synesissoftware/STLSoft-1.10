/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/functional/indirect_function_pointer_adaptors.hpp
 *
 * Purpose:     Contains the stlsoft::ptr_ifun calling convention-aware function adaptors.
 *
 * Created:     13th June 1999
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1999-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/functional/indirect_function_pointer_adaptors.hpp
 *
 * \brief [C++] Function classes that adapt indirect non-member
 *   functions (and handle different calling conventions)
 *   (\ref group__library__Functional "Functional" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_INDIRECT_FUNCTION_POINTER_ADAPTORS
#define STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_INDIRECT_FUNCTION_POINTER_ADAPTORS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_INDIRECT_FUNCTION_POINTER_ADAPTORS_MAJOR    2
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_INDIRECT_FUNCTION_POINTER_ADAPTORS_MINOR    1
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_INDIRECT_FUNCTION_POINTER_ADAPTORS_REVISION 5
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_INDIRECT_FUNCTION_POINTER_ADAPTORS_EDIT     20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
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

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("Refactor the names of the function class templates"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */


#ifndef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID

# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T>
struct ref2ptr_1_CDECL_void_t
    : STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
{
public:
    ref2ptr_1_CDECL_void_t(void (STLSOFT_CDECL *p)(T*))
        : m_p(p)
    {}

public:
    void operator ()(T &t) const
    {
        (*m_p)(&t);
    }

private:
    void (STLSOFT_CDECL *m_p)(T*);
};
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T>
struct ref2ptr_1_FASTCALL_void_t
    : STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
{
public:
    ref2ptr_1_FASTCALL_void_t(void (STLSOFT_FASTCALL *p)(T*))
        : m_p(p)
    {}

public:
    void operator ()(T &t) const
    {
        (*m_p)(&t);
    }

private:
    void (STLSOFT_FASTCALL *m_p)(T*);
};
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T>
struct ref2ptr_1_STDCALL_void_t
    : STLSOFT_NS_QUAL_STD(unary_function)<T*, void>
{
public:
    ref2ptr_1_STDCALL_void_t(void (STLSOFT_STDCALL *p)(T*))
        : m_p(p)
    {}

public:
    void operator ()(T &t) const
    {
        (*m_p)(&t);
    }

private:
    void (STLSOFT_STDCALL *m_p)(T*);
};
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */


# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T, typename R>
struct ref2ptr_1_CDECL_t
    : STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
{
public:
    ref2ptr_1_CDECL_t(R (STLSOFT_CDECL *p)(T*))
        : m_p(p)
    {}

public:
    R operator ()(T &t) const
    {
        return (*m_p)(&t);
    }

private:
    R (STLSOFT_CDECL *m_p)(T*);
};
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T, typename R>
struct ref2ptr_1_FASTCALL_t
    : STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
{
public:
    ref2ptr_1_FASTCALL_t(R (STLSOFT_FASTCALL *p)(T*))
        : m_p(p)
    {}

public:
    R operator ()(T &t) const
    {
        return (*m_p)(&t);
    }

private:
    R (STLSOFT_FASTCALL *m_p)(T*);
};
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T, typename R>
struct ref2ptr_1_STDCALL_t
    : STLSOFT_NS_QUAL_STD(unary_function)<T*, R>
{
public:
    ref2ptr_1_STDCALL_t(R (STLSOFT_STDCALL *p)(T*))
        : m_p(p)
    {}

public:
    R operator ()(T &t) const
    {
        return (*m_p)(&t);
    }

private:
    R (STLSOFT_STDCALL *m_p)(T*);
};
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

/* /////////////////////////////////////////////////////////////////////////
 * creator functions
 */

# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T, typename R>
inline ref2ptr_1_CDECL_t<T, R> ptr_ifun(R (STLSOFT_CDECL *p)(T*))
{
    return ref2ptr_1_CDECL_t<T, R>(p);
}
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T, typename R>
inline ref2ptr_1_FASTCALL_t<T, R> ptr_ifun(R (STLSOFT_FASTCALL *p)(T*))
{
    return ref2ptr_1_FASTCALL_t<T, R>(p);
}
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T, typename R>
inline ref2ptr_1_STDCALL_t<T, R> ptr_ifun(R (STLSOFT_STDCALL *p)(T*))
{
    return ref2ptr_1_STDCALL_t<T, R>(p);
}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#ifdef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID
# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T>
inline ref2ptr_1_CDECL_t<T, void> ptr_ifun_void(void (STLSOFT_CDECL *p)(T*))
{
    return ref2ptr_1_CDECL_t<T, void>(p);
}
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_FASTCALL_t<T, void> ptr_ifun_void(void (STLSOFT_FASTCALL *p)(T*))
{
    return ref2ptr_1_FASTCALL_t<T, void>(p);
}
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_STDCALL_t<T, void> ptr_ifun_void(void (STLSOFT_STDCALL *p)(T*))
{
    return ref2ptr_1_STDCALL_t<T, void>(p);
}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T>
inline ref2ptr_1_CDECL_void_t<T> ptr_ifun_void(void (STLSOFT_CDECL *p)(T*))
{
    return ref2ptr_1_CDECL_void_t<T>(p);
}
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_FASTCALL_void_t<T> ptr_ifun_void(void (STLSOFT_FASTCALL *p)(T*))
{
    return ref2ptr_1_FASTCALL_void_t<T>(p);
}
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_STDCALL_void_t<T> ptr_ifun_void(void (STLSOFT_STDCALL *p)(T*))
{
    return ref2ptr_1_STDCALL_void_t<T>(p);
}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T, typename R>
inline ref2ptr_1_CDECL_t<T, R> ref2ptr(R (STLSOFT_CDECL *p)(T*))
{
    return ref2ptr_1_CDECL_t<T, R>(p);
}
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T, typename R>
inline ref2ptr_1_FASTCALL_t<T, R> ref2ptr(R (STLSOFT_FASTCALL *p)(T*))
{
    return ref2ptr_1_FASTCALL_t<T, R>(p);
}
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T, typename R>
inline ref2ptr_1_STDCALL_t<T, R> ref2ptr(R (STLSOFT_STDCALL *p)(T*))
{
    return ref2ptr_1_STDCALL_t<T, R>(p);
}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */

#ifdef STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID
# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T>
inline ref2ptr_1_CDECL_t<T, void> ref2ptr_void(void (STLSOFT_CDECL *p)(T*))
{
    return ref2ptr_1_CDECL_t<T, void>(p);
}
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_FASTCALL_t<T, void> ref2ptr_void(void (STLSOFT_FASTCALL *p)(T*))
{
    return ref2ptr_1_FASTCALL_t<T, void>(p);
}
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_STDCALL_t<T, void> ref2ptr_void(void (STLSOFT_STDCALL *p)(T*))
{
    return ref2ptr_1_STDCALL_t<T, void>(p);
}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#else /* ? STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */
# ifdef STLSOFT_CF_CDECL_SUPPORTED
template <typename T>
inline ref2ptr_1_CDECL_void_t<T> ref2ptr_void(void (STLSOFT_CDECL *p)(T*))
{
    return ref2ptr_1_CDECL_void_t<T>(p);
}
# endif /* STLSOFT_CF_CDECL_SUPPORTED */
# ifdef STLSOFT_CF_FASTCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_FASTCALL_void_t<T> ref2ptr_void(void (STLSOFT_FASTCALL *p)(T*))
{
    return ref2ptr_1_FASTCALL_void_t<T>(p);
}
# endif /* STLSOFT_CF_FASTCALL_SUPPORTED */
# ifdef STLSOFT_CF_STDCALL_SUPPORTED
template <typename T>
inline ref2ptr_1_STDCALL_void_t<T> ref2ptr_void(void (STLSOFT_STDCALL *p)(T*))
{
    return ref2ptr_1_STDCALL_void_t<T>(p);
}
# endif /* STLSOFT_CF_STDCALL_SUPPORTED */
#endif /* !STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID */

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

#endif /* !STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_INDIRECT_FUNCTION_POINTER_ADAPTORS */

/* ///////////////////////////// end of file //////////////////////////// */

