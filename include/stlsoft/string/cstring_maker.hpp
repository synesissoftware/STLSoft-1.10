/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/cstring_maker.hpp
 *
 * Purpose:     Simple utility class for creating (constant) C-strings.
 *
 * Created:     14th May 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/cstring_maker.hpp
 *
 * \brief [C++] Definition of the stlsoft::string_maker class template
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER
#define STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_CSTRING_MAKER_MAJOR    5
# define STLSOFT_VER_STLSOFT_STRING_HPP_CSTRING_MAKER_MINOR    0
# define STLSOFT_VER_STLSOFT_STRING_HPP_CSTRING_MAKER_REVISION 5
# define STLSOFT_VER_STLSOFT_STRING_HPP_CSTRING_MAKER_EDIT     65
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE
# include <stlsoft/memory/allocator_base.hpp>       // for STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_BASE */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */


#if 0 || \
    (   defined(STLSOFT_COMPILER_IS_GCC) && \
        __GNUC__ < 4) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1200) || \
    0
# ifndef STLSOFT_cstring_maker_REQUIRE_PER_COMPILER_
#  define STLSOFT_cstring_maker_REQUIRE_PER_COMPILER_
# endif /* !STLSOFT_cstring_maker_REQUIRE_PER_COMPILER_ */
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_OPEN_WORKER_NS_(ximpl_cstring_maker_)

template <ss_typename_param_k C>
struct char_to_byte__traits_
{
    static ss_size_t byte_size_(ss_size_t cch)
    {
        return cch * sizeof(C);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct char_to_byte__traits_<ss_char_a_t>
{
    static ss_size_t byte_size_(ss_size_t cch)
    {
        return cch;
    }
};

STLSOFT_CLOSE_WORKER_NS_(ximpl_cstring_maker_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Utility class that creates/destroys fixed-size C-strings for
 *   other classes.
 *
 * \ingroup group__library__String
 */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION) || \
    !defined(STLSOFT_cstring_maker_REQUIRE_PER_COMPILER_)

template<
    ss_typename_param_k C
,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
,   ss_typename_param_k T = stlsoft_char_traits<C>
>
struct cstring_maker
{
public: // types
    /// The character type
    typedef C                                               char_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// The traits type
    typedef T                                               traits_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// This type
    typedef cstring_maker<C, A, T>                          class_type;
private:
    typedef long                                            count_type;

public:
    /// Shared block type
    struct block
    {
        size_type   n;
        count_type  rc;
        char_type   data[1];
    };

private: // constants
    enum
    {
        // Must be power of 2
        AllocationGranularity = 32
    };

public:
    /// Allocates storage for writing into a string, optionally initialising
    ///
    /// \note Includes space for a nul-terminator character
    ///
    /// \param s The optional string to be copied into the block. May be
    ///   \c null; if not, must be of at least \c cch characters long
    /// \param cch The number of characters to allocate
    ///
    /// \return the allocated block
    /// \retval nullptr Only if space cannot be allocated AND the current
    ///   compilation mode does not support exceptions
    static
    block*
    alloc(
        char_type const*    s
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
#if defined(WIN32) || \
    defined(_WIN32)

        cch = STLSOFT_WORKER_NS_QUAL_(ximpl_cstring_maker_, char_to_byte__traits_)<char_type>::byte_size_(cch);
#endif /* WIN32 || _WIN32 */

        size_type       cb      =   offsetof(block, data) + sizeof(char_type) * (1 + cch);

#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
        ss_typename_type_k allocator_type::ss_template_qual_k rebind<ss_byte_t>::other  byte_ator;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
        allocator_selector<ss_byte_t>::allocator_type                                   byte_ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

        cb = (cb + (AllocationGranularity - 1)) & ~(AllocationGranularity - 1);

#ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
        block* const    pblock  =   static_cast<block*>(static_cast<void*>(byte_ator.allocate(cb, NULL)));
#else /* ? STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
        block* const    pblock  =   static_cast<block*>(static_cast<void*>(byte_ator.allocate(cb)));
#endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */

        if (NULL == pblock)
        {
            return NULL;
        }
        else
        {
            pblock->n = cch;
            pblock->rc = 1;
            pblock->data[cch] = '\0';

            if (NULL != s)
            {
                traits_type::copy(&pblock->data[0], s, cch);
            }

            return pblock;
        }
    }

    /// Allocates storage for writing into a string, optionally
    /// initialising, or returns \c nullptr if \c cch is 0
    ///
    /// \note Includes space for a nul-terminator character
    ///
    /// \param s The optional string to be copied into the block. May be
    ///   \c null; if not, must be of at least \c cch characters long
    /// \param cch The number of characters to allocate
    static
    block*
    alloc_null(
        char_type const*    s
    ,   size_type           cch
    ) STLSOFT_NOEXCEPT
    {
        return (0 == cch) ? NULL : alloc(s, cch);
    }

    /// Shares the (reference to the) block
    static
    block*
    share(
        block* pblock
    ) STLSOFT_NOEXCEPT
    {
        if (NULL != pblock)
        {
            ++pblock->rc;
        }

        return pblock;
    }

    /// Releases the storage associated with the string
    ///
    /// \param s The string to free
    static
    void
    free(
        block* pblock
    ) STLSOFT_NOEXCEPT
    {
#ifdef STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT
        ss_typename_type_k allocator_type::ss_template_qual_k rebind<ss_byte_t>::other  byte_ator;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
        allocator_selector<ss_byte_t>::allocator_type                                   byte_ator;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */

        if (NULL != pblock)
        {
            if (0 == --pblock->rc)
            {
                STLSOFT_MESSAGE_ASSERT("block is overwritten!", pblock->data[pblock->n] == '\0');

                byte_ator.deallocate(static_cast<ss_byte_t*>(static_cast<void*>(pblock)), 0);
            }
        }
    }
};
#else /* ? per-compiler */

template<
    ss_typename_param_k C
>
struct cstring_maker
{
public:
    typedef C                                               char_type;
    typedef ss_size_t                                       size_type;
    typedef cstring_maker<char_type>                        class_type;
private:
    typedef long                                            count_type;

public:
    /// Shared block type
    struct block
    {
        size_type   n;
        count_type  rc;
        char_type   data[1];
    };

private: // constants
    enum
    {
        // Must be power of 2
        AllocationGranularity = 32
    };

public:
    static
    block*
    alloc(
        char_type const*    s
    ,   size_type           cch
    )
    {
        size_type       cb      =   offsetof(block, data) + sizeof(char_type) * (1 + cch);

        cb = (cb + (AllocationGranularity - 1)) & ~(AllocationGranularity - 1);

        block* const    pblock  =   static_cast<block*>(malloc(cb));

        if (NULL == pblock)
        {
            return NULL;
        }
        else
        {
            pblock->n = cch;
            pblock->rc = 1;
            pblock->data[cch] = '\0';

            if (NULL != s)
            {
                STLSOFT_API_INTERNAL_memfns_memcpy(&pblock->data[0], s, cch * sizeof(char_type));
            }

            return pblock;
        }
    }

    static
    block*
    alloc_null(
        char_type const*    s
    ,   size_type           cch
    )
    {
        return (0 == cch) ? NULL : alloc(s, cch);
    }

    static
    block*
    share(
        block* pblock
    )
    {
        if (NULL == pblock)
        {
            ++pblock->rc;
        }

        return pblock;
    }

    static
    void
    free(
        block* pblock
    )
    {
        if (NULL != pblock)
        {
            if (0 == --pblock->rc)
            {
                ::free(pblock);
            }
        }
    }
};
#endif /* compiler */

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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CSTRING_MAKER */

/* ///////////////////////////// end of file //////////////////////////// */

