/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/tokeniser_functions.hpp
 *
 * Purpose:     Restartable tokenising functions.
 *
 * Created:     6th January 2001
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2001-2019, Matthew Wilson and Synesis Software
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

/** \file stlsoft/string/tokeniser_functions.hpp
 *
 * \brief [C++] Definition of the stlsoft::find_next_token suite of
 *  restartable tokenising functions
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS_MAJOR      2
# define STLSOFT_VER_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS_MINOR      0
# define STLSOFT_VER_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS_REVISION   6
# define STLSOFT_VER_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS_EDIT       34
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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Adjusts the delimiters into a token string to find the next
 *    token, according to the given delimiter. Processing stops when \c p1
 *    is equal to \c end
 *
 * \ingroup group__library__String
 *
 * \param p0 Pointer to the current token in the string. Will be set to the
 *   next when the function returns
 * \param p1 Pointer to the current token in the string. Will be set to the
 *   end of the token when the function returns
 * \param end The end of the string
 * \param delim The delimiter
 *
 * \return p0
 *
 * \pre NULL != p0
 * \pre NULL != p1
 * \pre NULL != end
 * \pre p0 <= p1
 * \pre p1 <= end
 */
template <ss_typename_param_k C>
inline C const*
find_next_token(
    C const*&       p0
,   C const*&       p1
#if defined(STLSOFT_COMPILER_IS_DMC)
,   C const*        end
#else /* ? compiler */
,   C const* const  end
#endif /* compiler */
,   C               delim
)
{
    STLSOFT_ASSERT(NULL != p0);
    STLSOFT_ASSERT(NULL != p1);
    STLSOFT_ASSERT(NULL != end);
    STLSOFT_ASSERT(p0 <= p1);
    STLSOFT_ASSERT(p1 <= end);

    if (p1 != end)
    {
        if (p0 != p1)
        {
            p0 = ++p1;
        }
        else
        {
            p0 = p1;
        }

        if (delim == *p1)
        {
            ++p0;
            ++p1;
        }
        else for (; p1 != end; ++p1)
        {
            if (delim == *p1)
            {
                break;
            }
        }
    }
    else
    {
        p0 = end;
    }

    return p0;
}

/** Adjusts the delimiters into a token string to find the next
 *    token, according to the given delimiter. Processing stops when \c p1
 *    points to the nul-terminating character
 *
 * \ingroup group__library__String
 *
 * \param p0 Pointer to the current token in the string. Will be set to the
 *   next when the function returns
 * \param p1 Pointer to the current token in the string. Will be set to the
 *   end of the token when the function returns
 * \param delim The delimiter
 *
 * \return p0
 *
 * \pre NULL != p0
 * \pre NULL != p1
 * \pre p0 <= p1
 */
template <ss_typename_param_k C>
inline bool
find_next_token(
    C const*&   p0
,   C const*&   p1
,   C           delim
)
{
    STLSOFT_ASSERT(NULL != p0);
    STLSOFT_ASSERT(NULL != p1);
    STLSOFT_ASSERT(p0 <= p1);

    if ('\0' == *p1)
    {
        p0 = p1;

        return false;
    }

    if (p0 != p1)
    {
        p0 = ++p1;
    }
    else
    {
        p0 = p1;
    }

    if (delim == *p1)
    {
        ++p0;
        ++p1;
    }
    else for (;; ++p1)
    {
        if ('\0' == *p1)
        {
            return p0 != p1;
        }
        else if (delim == *p1)
        {
            break;
        }
    }

    return true;
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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_TOKENISER_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

