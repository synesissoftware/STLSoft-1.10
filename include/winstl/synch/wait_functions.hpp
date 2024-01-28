/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/wait_functions.hpp
 *
 * Purpose:     Definition of the winstl::wait_for_multiple_objects()
 *              function template suite
 *
 * Created:     30th May 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/wait_functions.hpp
 *
 * \brief [C++] Definition of the winstl::wait_for_multiple_objects()
 *  function template suite
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_MAJOR       2
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_REVISION    10
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_EDIT        27
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

#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_SYNCH_HANDLE
# include <winstl/shims/attribute/get_synch_handle.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_SYNCH_HANDLE */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Synchronization
# include <winstl/api/external/Synchronization.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Synchronization */

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
 * functions
 */

#ifndef WINSTL_WAIT_FUNCTIONS_NO_USE_SHIM_VERIFIER

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k H>
inline
HANDLE
w4mo_verify_and_get_discriminator(
    H&  h
,   H const*
)
{
    // If the compiler balks here with a message complaining about being
    //
    //     "unable to convert to HANDLE (*)(H &)",
    //
    // then it means that you're trying to pass an argument to
    // wait_for_multiple_object() for which an overload of the
    // winstl::get_synch_handle() attribute shim is not defined.
    //
    // This may confuse you if your type may be implicitly convertible to
    // HANDLE, but use of such types without shims is dangerous, and is
    // therefore disallowed.

    HANDLE (*pfn)(H &)      =   &WINSTL_NS_QUAL(get_synch_handle);

    return (*pfn)(h);
}

inline
HANDLE
w4mo_verify_and_get_discriminator(
    HANDLE  h
,   HANDLE const*
)
{
    return h;
}

template <ss_typename_param_k H>
inline
HANDLE
w4mo_verify_and_get(H &h)
{
    return w4mo_verify_and_get_discriminator(h, &h);
}

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#else /* ? WINSTL_WAIT_FUNCTIONS_NO_USE_SHIM_VERIFIER */

template <ss_typename_param_k H>
inline
HANDLE
w4mo_verify_and_get(H &h)
{
    return WINSTL_NS_QUAL(get_synch_handle)(h);
}

#endif /* !WINSTL_WAIT_FUNCTIONS_NO_USE_SHIM_VERIFIER */



/** [IMPLEMENTATION]
 *
 * \ingroup group__library__Synch
 */
inline
DWORD
w4mo_helper_8(
    HANDLE      h0
,   HANDLE      h1
,   HANDLE      h2
,   HANDLE      h3
,   HANDLE      h4
,   HANDLE      h5
,   HANDLE      h6
,   HANDLE      h7
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    HANDLE  handles[8];
    DWORD   numHandles  =   2;

    WINSTL_ASSERT(NULL != h0);
    WINSTL_ASSERT(NULL != h1);

    handles[0]   =   h0;
    handles[1]   =   h1;
    handles[2]   =   h2;
    handles[3]   =   h3;
    handles[4]   =   h4;
    handles[5]   =   h5;
    handles[6]   =   h6;
    handles[7]   =   h7;

    for (ws_size_t i = numHandles; i < STLSOFT_NUM_ELEMENTS(handles); ++i, ++numHandles)
    {
        if (NULL == handles[i])
        {
            break;
        }
    }

    return WINSTL_API_EXTERNAL_Synchronization_WaitForMultipleObjects(numHandles, &handles[0], bWaitAll, timeout);
}


/** Execute wait for 8 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__Synch
 */
template<
    ss_typename_param_k L0
,   ss_typename_param_k L1
,   ss_typename_param_k L2
,   ss_typename_param_k L3
,   ss_typename_param_k L4
,   ss_typename_param_k L5
,   ss_typename_param_k L6
,   ss_typename_param_k L7
>
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   L6&         l6
,   L7&         l7
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l6));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l7));

    return w4mo_helper_8(
            WINSTL_NS_QUAL(w4mo_verify_and_get)(l0)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l1)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l2)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l3)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l4)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l5)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l6)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l7)
        ,   bWaitAll
        ,   timeout);
}

/** Execute wait for 7 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__Synch
 */
template<
    ss_typename_param_k L0
,   ss_typename_param_k L1
,   ss_typename_param_k L2
,   ss_typename_param_k L3
,   ss_typename_param_k L4
,   ss_typename_param_k L5
,   ss_typename_param_k L6
>
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   L6&         l6
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l6));

    return w4mo_helper_8(
            WINSTL_NS_QUAL(w4mo_verify_and_get)(l0)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l1)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l2)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l3)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l4)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l5)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l6)
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** Execute wait for 6 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__Synch
 */
template<
    ss_typename_param_k L0
,   ss_typename_param_k L1
,   ss_typename_param_k L2
,   ss_typename_param_k L3
,   ss_typename_param_k L4
,   ss_typename_param_k L5
>
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l5));

    return w4mo_helper_8(
            WINSTL_NS_QUAL(w4mo_verify_and_get)(l0)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l1)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l2)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l3)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l4)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l5)
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** Execute wait for 5 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__Synch
 */
template<
    ss_typename_param_k L0
,   ss_typename_param_k L1
,   ss_typename_param_k L2
,   ss_typename_param_k L3
,   ss_typename_param_k L4
>
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l4));

    return w4mo_helper_8(
            WINSTL_NS_QUAL(w4mo_verify_and_get)(l0)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l1)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l2)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l3)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l4)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** Execute wait for 4 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__Synch
 */
template<
    ss_typename_param_k L0
,   ss_typename_param_k L1
,   ss_typename_param_k L2
,   ss_typename_param_k L3
>
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l3));

    return w4mo_helper_8(
            WINSTL_NS_QUAL(w4mo_verify_and_get)(l0)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l1)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l2)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l3)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** Execute wait for 3 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__Synch
 */
template<
    ss_typename_param_k L0
,   ss_typename_param_k L1
,   ss_typename_param_k L2
>
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l2));

    return w4mo_helper_8(
            WINSTL_NS_QUAL(w4mo_verify_and_get)(l0)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l1)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l2)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

/** Execute wait for 2 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__Synch
 */
template<
    ss_typename_param_k L0
,   ss_typename_param_k L1
>
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   ws_bool_t   bWaitAll
,   ws_dword_t  timeout
)
{
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != WINSTL_NS_QUAL(get_synch_handle)(l1));

    return w4mo_helper_8(
            WINSTL_NS_QUAL(w4mo_verify_and_get)(l0)
        ,   WINSTL_NS_QUAL(w4mo_verify_and_get)(l1)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   bWaitAll
        ,   timeout);
}

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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

