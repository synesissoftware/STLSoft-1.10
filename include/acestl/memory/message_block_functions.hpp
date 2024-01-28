/* /////////////////////////////////////////////////////////////////////////
 * File:        acestl/memory/message_block_functions.hpp
 *
 * Purpose:     Helper functions for ACE_Message_Block (and ACE_Data_Block) classes.
 *
 * Created:     23rd September 2004
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


/** \file acestl/memory/message_block_functions.hpp
 *
 * \brief [C++] Helper functions for use with the ACE_Message_Block
 *   and ACE_Data_Block classes
 *   (\ref group__library__Memory "Memory" Library).
 */

#ifndef ACESTL_INCL_ACESTL_MEMORY_HPP_MESSAGE_BLOCK_FUNCTIONS
#define ACESTL_INCL_ACESTL_MEMORY_HPP_MESSAGE_BLOCK_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_MEMORY_HPP_MESSAGE_BLOCK_FUNCTIONS_MAJOR      2
# define ACESTL_VER_ACESTL_MEMORY_HPP_MESSAGE_BLOCK_FUNCTIONS_MINOR      0
# define ACESTL_VER_ACESTL_MEMORY_HPP_MESSAGE_BLOCK_FUNCTIONS_REVISION   8
# define ACESTL_VER_ACESTL_MEMORY_HPP_MESSAGE_BLOCK_FUNCTIONS_EDIT       43
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_ACE_H_MESSAGE_BLOCK
# define STLSOFT_INCL_ACE_H_MESSAGE_BLOCK
# include <ace/Message_Block.h>     // for ACE_Message_Block
#endif /* !STLSOFT_INCL_ACE_H_MESSAGE_BLOCK */
#ifndef STLSOFT_INCL_ACE_H_OS_MEMORY
# define STLSOFT_INCL_ACE_H_OS_MEMORY
# include <ace/OS_Memory.h>         // for ACE_bad_alloc, ACE_NEW_THROWS_EXCEPTIONS
#endif /* !STLSOFT_INCL_ACE_H_OS_MEMORY */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::acestl */
namespace acestl
{
# else
/* Define stlsoft::acestl_project */
namespace stlsoft
{
namespace acestl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Creates a new ACE_Message_Block instance whose contents are
 *    copied from the given memory.
 *
 * \ingroup group__library__Memory
 *
 * \param p Pointer to the memory to copy into the new message block. May be
 *   NULL, in which case the contents are not explicitly initialised.
 * \param n Number of bytes to copy into the new message block. If
 *   <code>NULL == p</code>, this is the size of the initialised block.
 *
 * Usage is simple: just specify the source (pointer and length), and test
 * for NULL (allocation failure):
 *
\code
ACE_Message_Block *newBlock = acestl::make_copied_Message_Block("Contents", 7);

if (NULL == newBlock)
{
  std::cerr <<  "Allocation failed!\n";
}
\endcode
 *
 *
 * \exception - In accordance with the non-throwing nature of
 *   ACE, memory allocation failure is reflected by returning NULL.
 */
inline ACE_Message_Block *make_copied_Message_Block(char const* p, as_size_t n)
{
#if defined(ACE_NEW_THROWS_EXCEPTIONS)
    try
    {
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
        ACE_Message_Block *pmb = new ACE_Message_Block(n);

        if (NULL == pmb)
        {
            errno = ENOMEM;
        }
        else
        {
            pmb->wr_ptr(n);

            if (NULL != p)
            {
                STLSOFT_API_INTERNAL_memfns_memcpy(pmb->base(), p, n);
            }
        }

        return pmb;
#if defined(ACE_NEW_THROWS_EXCEPTIONS)
    }
    catch(ACE_bad_alloc) // TODO: This should be a reference, surely??
    {
        return NULL;
    }
#endif /* ACE_NEW_THROWS_EXCEPTIONS */
}

#if defined(STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT)

template <ss_size_t N>
inline ACE_Message_Block *make_copied_Message_Block(const char (&ar)[N])
{
    return make_copied_Message_Block(&ar[0], N);
}

#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef ACESTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace acestl */
# else
} /* namespace acestl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !ACESTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !ACESTL_INCL_ACESTL_MEMORY_HPP_MESSAGE_BLOCK_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

