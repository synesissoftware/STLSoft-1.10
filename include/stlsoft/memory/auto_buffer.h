/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/memory/auto_buffer.h
 *
 * Purpose:     auto_buffer functionality for C.
 *
 * Created:     5th August 2011
 * Updated:     29th March 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/memory/auto_buffer.h
 *
 * \brief [C] auto_buffer functionality for C
 *   (\ref group__library__Memory "Memory" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_H_AUTO_BUFFER
#define STLSOFT_INCL_STLSOFT_MEMORY_H_AUTO_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_MEMORY_H_AUTO_BUFFER_MAJOR     2
# define STLSOFT_VER_STLSOFT_MEMORY_H_AUTO_BUFFER_MINOR     0
# define STLSOFT_VER_STLSOFT_MEMORY_H_AUTO_BUFFER_REVISION  3
# define STLSOFT_VER_STLSOFT_MEMORY_H_AUTO_BUFFER_EDIT      19
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

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>                     /* for malloc(), free() */
#endif /* !STLSOFT_INCL_H_STDLIB */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define STLSOFT_C_AUTO_BUFFER_DERIVE_NAME_(name)               \
                                                                \
    name ## _stlsoft_C_auto_buffer_structure_

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \def STLSOFT_C_AUTO_BUFFER_DECLARE(type, internalSize, name)
 *
 * Declares a mixed stack/heap storage arena, with a given element \c type,
 * \c internalSize, and \c name.
 *
 * \param type The type of the arena element, e.g. \c char
 * \param internalSize The number of elements in the internal (stack)
 *   storage
 * \param name The name of the arena. Must be a valid C identifier name
 *
 *
\htmlonly
<pre>
  void some_func(wchar_t const* s)
  {
    STLSOFT_C_AUTO_BUFFER_DECLARE(char, 100, buff);

    assert(NULL == buff.ptr);
  }
</pre>
\endhtmlonly
 *
 * \pre (0 < internalSize)
 *
 * \see STLSOFT_C_AUTO_BUFFER_INITIALISE, STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_RESIZE, STLSOFT_C_AUTO_BUFFER_RESIZE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_FREE
 */

#define STLSOFT_C_AUTO_BUFFER_DECLARE(type, internalSize, name) \
                                                                \
    struct STLSOFT_C_AUTO_BUFFER_DERIVE_NAME_(name)             \
    {                                                           \
        size_t  size;                                           \
        type*   ptr;                                            \
        size_t  elementSize;                                    \
        type    internal_[internalSize];                        \
    }   name = { 0, NULL, sizeof(type), { 0 } }


/** \def STLSOFT_C_AUTO_BUFFER_INITIALISE(name, requiredSize)
 *
 * Initialises the runtime allocation of a mixed stack/heap storage arena.
 *
 * \param name The name of the arena
 * \param requiredSize The required runtime size of the arena, in number of
 *   elements (not bytes)
 *
 * \return an \c int value indicating success
 * \retval 0 success
 * \retval !0 a standard (errno) failure code
 *
 * \see STLSOFT_C_AUTO_BUFFER_DECLARE, STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_RESIZE, STLSOFT_C_AUTO_BUFFER_RESIZE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_FREE
 */

#define STLSOFT_C_AUTO_BUFFER_INITIALISE(name, requiredSize)    \
                                                                \
    STLSOFT_NS_QUAL(stlsoft_C_auto_buffer_initialise)(          \
        sizeof(name.internal_[0])                               \
    ,   &name.internal_[0]                                      \
    ,   sizeof(name.internal_) / sizeof(name.internal_[0])      \
    ,   (requiredSize)                                          \
    ,   &name.size                                              \
    ,   STLSOFT_REINTERPRET_CAST(void**, &name.ptr)             \
    )

/** \def STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL(name)
 *
 * Sets the runtime allocation of a mixed stack/heap storage arena from
 * the internal (stack) area.
 *
 * \param name The name of the arena
 *
 * \return The macro cannot fail, and has a type of \c void
 *
 * \see STLSOFT_C_AUTO_BUFFER_DECLARE, STLSOFT_C_AUTO_BUFFER_INITIALISE, STLSOFT_C_AUTO_BUFFER_RESIZE, STLSOFT_C_AUTO_BUFFER_RESIZE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_FREE
 */

#define STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL(name)    \
                                                                \
    ((name.size = sizeof(name.internal_) / sizeof(name.internal_[0])), (name.ptr = &name.internal_[0]))

/** \def STLSOFT_C_AUTO_BUFFER_RESIZE(name, requiredSize)
 *
 * Resizes the runtime allocation of a mixed stack/heap storage arena.
 *
 * \param name The name of the arena
 * \param requiredSize The required runtime size of the arena
 *
 * \return an \c int value indicating success
 * \retval 0 success
 * \retval !0 a standard (errno) failure code
 *
 * \see STLSOFT_C_AUTO_BUFFER_DECLARE, STLSOFT_C_AUTO_BUFFER_INITIALISE, STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_RESIZE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_FREE
 */

#define STLSOFT_C_AUTO_BUFFER_RESIZE(name, requiredSize)        \
                                                                \
    STLSOFT_NS_QUAL(stlsoft_C_auto_buffer_resize)(              \
        sizeof(name.internal_[0])                               \
    ,   &name.internal_[0]                                      \
    ,   sizeof(name.internal_) / sizeof(name.internal_[0])      \
    ,   (requiredSize)                                          \
    ,   &name.size                                              \
    ,   STLSOFT_REINTERPRET_CAST(void**, &name.ptr)             \
    )

/** \def STLSOFT_C_AUTO_BUFFER_RESIZE_FROM_INTERNAL(name)
 *
 * Sets the runtime allocation of a mixed stack/heap storage arena from
 * the internal (stack) area.
 *
 * \param name The name of the arena
 *
 * \return The macro cannot fail, and has a type of \c void
 *
 * \see STLSOFT_C_AUTO_BUFFER_DECLARE, STLSOFT_C_AUTO_BUFFER_INITIALISE, STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_RESIZE, STLSOFT_C_AUTO_BUFFER_FREE
 */

#define STLSOFT_C_AUTO_BUFFER_RESIZE_FROM_INTERNAL(name)        \
                                                                \
    ((void)STLSOFT_NS_QUAL(stlsoft_C_auto_buffer_resize)(       \
        sizeof(name.internal_[0])                               \
    ,   &name.internal_[0]                                      \
    ,   sizeof(name.internal_) / sizeof(name.internal_[0])      \
    ,   sizeof(name.internal_) / sizeof(name.internal_[0])      \
    ,   &name.size                                              \
    ,   STLSOFT_REINTERPRET_CAST(void**, &name.ptr)             \
    ))

/** \def STLSOFT_C_AUTO_BUFFER_FREE(name)
 *
 * Releases any allocation associated with a mixed stack/heap storage arena.
 *
 * \param name The name of the arena
 *
 * \return The macro cannot fail, and has a type of \c void
 *
 * \see STLSOFT_C_AUTO_BUFFER_DECLARE, STLSOFT_C_AUTO_BUFFER_INITIALISE, STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL, STLSOFT_C_AUTO_BUFFER_RESIZE, STLSOFT_C_AUTO_BUFFER_RESIZE_FROM_INTERNAL
 */

#define STLSOFT_C_AUTO_BUFFER_FREE(name)                        \
                                                                \
    STLSOFT_NS_QUAL(stlsoft_C_auto_buffer_free)(                \
        sizeof(name.internal_[0])                               \
    ,   &name.internal_[0]                                      \
    ,   sizeof(name.internal_) / sizeof(name.internal_[0])      \
    ,   name.size                                               \
    ,   name.ptr                                                \
    )


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# ifdef __cplusplus
namespace ximpl_stlsoft_C_AUTO_BUFFER
{
# endif /* __cplusplus */

STLSOFT_INLINE
void*
stlsoft_C_auto_buffer_std_malloc_(
    void*   param
,   size_t  cb
)
{
    STLSOFT_SUPPRESS_UNUSED(param);

    return STLSOFT_NS_GLOBAL(malloc)(cb);
}

STLSOFT_INLINE
void*
stlsoft_C_auto_buffer_std_realloc_(
    void*   param
,   void*   pv
,   size_t  cb
)
{
    STLSOFT_SUPPRESS_UNUSED(param);

    return STLSOFT_NS_GLOBAL(realloc)(pv, cb);
}

STLSOFT_INLINE
void
stlsoft_C_auto_buffer_std_free_(
    void*   param
,   void*   pv
)
{
    STLSOFT_SUPPRESS_UNUSED(param);

    STLSOFT_NS_GLOBAL(free)(pv);
}

# ifdef __cplusplus
} /* namespace ximpl_stlsoft_C_AUTO_BUFFER */
# endif /* __cplusplus */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/*
 *
 * \retval 0 the allocation is successful
 * \retval !0 the allocation failed
 */
STLSOFT_INLINE
int
stlsoft_C_auto_buffer_resize_ex(
    size_t      cbElement
,   void*       internal
,   size_t      cInternal
,   size_t      cRequired
,   size_t*     psize
,   void**      pptr
,   void*       param
,   void*     (*pfnRealloc)(void* param, void* pv, size_t cb)
,   void      (*pfnFree)(void* param, void* pv)
)
{
    STLSOFT_MESSAGE_ASSERT("element size may not be zero", 0 != cbElement);
    STLSOFT_MESSAGE_ASSERT("size out-parameter must not be null", NULL != psize);
    STLSOFT_MESSAGE_ASSERT("pointer out-parameter must not be null", NULL != pptr);
    STLSOFT_MESSAGE_ASSERT("reallocation function must not be null", NULL != pfnRealloc);

    if (cRequired <= cInternal)
    {
        if (*pptr != internal)
        {
            (*pfnFree)(param, *pptr);
        }

        *pptr   =   internal;
        *psize  =   cRequired;

        return 0;
    }
    else
    {
        void* const pvOld = (*psize <= cInternal) ? NULL : *pptr;
        void* const pvNew = (*pfnRealloc)(param, pvOld, cRequired * cbElement);

        if (NULL == pvNew)
        {
            *psize = 0;

            return -1;
        }
        else
        {
            *pptr   =   pvNew;
            *psize  =   cRequired;

            return 0;
        }
    }
}

/*
 *
 * \retval 0 the allocation is successful
 * \retval !0 the allocation failed
 */
STLSOFT_INLINE
int
stlsoft_C_auto_buffer_initialise_ex(
    size_t      cbElement
,   void*       internal
,   size_t      cInternal
,   size_t      cRequired
,   size_t*     psize
,   void**      pptr
,   void*       param
,   void*     (*pfnAlloc)(void* param, size_t cb)
)
{
    STLSOFT_MESSAGE_ASSERT("element size may not be zero", 0 != cbElement);
    STLSOFT_MESSAGE_ASSERT("size out-parameter must not be null", NULL != psize);
    STLSOFT_MESSAGE_ASSERT("pointer out-parameter must not be null", NULL != pptr);
    STLSOFT_MESSAGE_ASSERT("allocation function must not be null", NULL != pfnAlloc);

    if (cRequired <= cInternal)
    {
        *pptr   =   internal;
        *psize  =   cRequired;

        return 0;
    }
    else
    {
        *pptr = (*pfnAlloc)(param, cRequired * cbElement);

        if (NULL == *pptr)
        {
            *psize = 0;

            return -1;
        }
        else
        {
            *psize = cRequired;

            return 0;
        }
    }
}

STLSOFT_INLINE
void
stlsoft_C_auto_buffer_free_ex(
    size_t      cbElement
,   void*       internal
,   size_t      cInternal
,   size_t      cAllocated
,   void*       ptr
,   void*       param
,   void      (*pfnFree)(void* param, void* pv)
)
{
    STLSOFT_MESSAGE_ASSERT("deallocation function must not be null", NULL != pfnFree);

    STLSOFT_SUPPRESS_UNUSED(cbElement);
    STLSOFT_SUPPRESS_UNUSED(cInternal);
    STLSOFT_SUPPRESS_UNUSED(cAllocated);

    if (ptr != internal)
    {
        (*pfnFree)(param, ptr);
    }
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Initialises the runtime allocation of a mixed stack/heap storage arena.
 *
 * \param cbElement The size of each element
 * \param internal Pointer to the arena internal memory buffer
 * \param cInternal Number of elements in the arena internal memory buffer
 * \param cRequired Number of elements required at runtime
 * \param psize Pointer to a variable to receive the new size (in number of
 *   elements, not bytes)
 * \param pptr Pointer to the pointer to receive a pointer to the new
 *   (reallocated) usable memory
 *
 * \retval 0 the allocation is successful
 * \retval !0 the allocation failed
 *
 * \pre NULL != psize
 * \pre NULL != pptr
 * \pre NULL != pfnAlloc
 *
 * \see STLSOFT_C_AUTO_BUFFER_INITIALISE, stlsoft_C_auto_buffer_initialise_ex
 */
STLSOFT_INLINE
int
stlsoft_C_auto_buffer_initialise(
    size_t  cbElement
,   void*   internal
,   size_t  cInternal
,   size_t  cRequired
,   size_t* psize
,   void**  pptr
)
{
# ifdef __cplusplus
    using ximpl_stlsoft_C_AUTO_BUFFER::stlsoft_C_auto_buffer_std_malloc_;
# endif /* __cplusplus */

    return stlsoft_C_auto_buffer_initialise_ex(
        cbElement
    ,   internal
    ,   cInternal
    ,   cRequired
    ,   psize
    ,   pptr
    ,   NULL
    ,   stlsoft_C_auto_buffer_std_malloc_
    );
}

/** Adjusts the runtime allocation of a mixed stack/heap storage arena.
 *
 * \param cbElement The size of each element
 * \param internal Pointer to the arena internal memory buffer
 * \param cInternal Number of elements in the arena internal memory buffer
 * \param cRequired Number of elements required at runtime
 * \param psize Pointer to a variable specifying the current size and to
 *   receive the new size (in number of elements, not bytes)
 * \param pptr Pointer to the pointer to the current usable memory and to
 *   receive a pointer to the new (reallocated) usable memory
 *
 * \retval 0 the allocation is successful
 * \retval !0 the allocation failed
 *
 * \pre NULL != psize
 * \pre NULL != pptr
 * \pre NULL != pfnAlloc
 * \pre *psize is a valid value, arising from a prior initialisation/allocation
 * \pre *pptr is a valid value, arising from a prior initialisation/allocation
 *
 * \see STLSOFT_C_AUTO_BUFFER_INITIALISE, stlsoft_C_auto_buffer_initialise_ex
 */
STLSOFT_INLINE
int
stlsoft_C_auto_buffer_resize(
    size_t  cbElement
,   void*   internal
,   size_t  cInternal
,   size_t  cRequired
,   size_t* psize
,   void**  pptr
)
{
# ifdef __cplusplus
    using ximpl_stlsoft_C_AUTO_BUFFER::stlsoft_C_auto_buffer_std_free_;
    using ximpl_stlsoft_C_AUTO_BUFFER::stlsoft_C_auto_buffer_std_realloc_;
# endif /* __cplusplus */

    return stlsoft_C_auto_buffer_resize_ex(
        cbElement
    ,   internal
    ,   cInternal
    ,   cRequired
    ,   psize
    ,   pptr
    ,   NULL
    ,   stlsoft_C_auto_buffer_std_realloc_
    ,   stlsoft_C_auto_buffer_std_free_
    );
}

/** Releases any allocation associated with a mixed stack/heap storage
 * arena.
 *
 * \param cbElement The size of each element
 * \param internal Pointer to the arena internal memory buffer
 * \param cInternal Number of elements in the arena internal memory buffer
 * \param cAllocated Number of elements allocated in the usable memory
 * \param ptr Pointer to the usable memory
 *
 * \pre NULL != ptr
 *
 * \see STLSOFT_C_AUTO_BUFFER_FREE, stlsoft_C_auto_buffer_free_ex
 */
STLSOFT_INLINE
void
stlsoft_C_auto_buffer_free(
    size_t  cbElement
,   void*   internal
,   size_t  cInternal
,   size_t  cAllocated
,   void*   ptr
)
{
# ifdef __cplusplus
    using ximpl_stlsoft_C_AUTO_BUFFER::stlsoft_C_auto_buffer_std_free_;
# endif /* __cplusplus */

    stlsoft_C_auto_buffer_free_ex(
        cbElement
    ,   internal
    ,   cInternal
    ,   cAllocated
    ,   ptr
    ,   NULL
    ,   stlsoft_C_auto_buffer_std_free_
    );
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_H_AUTO_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

