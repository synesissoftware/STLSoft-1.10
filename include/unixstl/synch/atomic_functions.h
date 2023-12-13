/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/atomic_functions.h
 *
 * Purpose:     UNIXSTL atomic functions.
 *
 * Created:     23rd October 1997
 * Updated:     26th April 2021
 *
 * Thanks:      To Brad Cox, for helping out in testing and fixing the
 *              implementation for MAC OSX (Intel).
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1997-2019, Matthew Wilson and Synesis Software
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


/** \file unixstl/synch/atomic_functions.h
 *
 * \brief [C++] Definition of the atomic functions
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS
#define UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_MAJOR     7
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_MINOR     0
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_REVISION  4
# define UNIXSTL_VER_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS_EDIT      219
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_FEATURES
# include <unixstl/synch/util/features.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_FEATURES */
#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_TYPES
# include <unixstl/synch/atomic_types.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_TYPES */

#if defined(UNIXSTL_FORCE_ATOMIC_INTEGER_OPERATIONS)

 /* Nothing to include here; UNIXSTL_FORCED_ATOMIC_INTEGER_IMPLEMENTATIONS will be included inside unixstl namespace */
#elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_GCC_BUILTINS)

# include <stlsoft/internal/atomic/gcc_builtins_.h>
#elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_MACOSX)

# include <libkern/OSAtomic.h>
#elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED)

# include <unixstl/synch/util/windows_api_.h>
#else

# error Atomic integer operations not supported: see unixstl/synch/util/features.h for details
#endif /* ? */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#if 0
#elif defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

/** Indicates whether the atomic_exchange function is defined for
 *    the current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_exchange

/** Indicates whether the atomic_preincrement function is defined
 *    for the current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_preincrement

/** Indicates whether the atomic_predecrement function is defined
 *    for the current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_predecrement

/** Indicates whether the atomic_postincrement function is defined
 *    for the current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_postincrement

/** Indicates whether the atomic_postdecrement function is defined
 *    for the current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_postdecrement

/** Indicates whether the atomic_increment function is defined for
 *    the current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_increment

/** Indicates whether the atomic_decrement function is defined for
 *    the current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_decrement

/** Indicates whether the atomic_read function is defined for the
 *    current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_read

/** Indicates whether the atomic_write function is defined for the
 *    current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_write

/** Indicates whether the atomic_preadd function is defined for the
 *    current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_preadd

/** Indicates whether the atomic_postadd function is defined for the
 *    current compiler/operating-system/architecture
 */
# define UNIXSTL_HAS_atomic_postadd

#elif defined(UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS)

# if defined(UNIXSTL_FORCE_ATOMIC_INTEGER_OPERATIONS)


 /* ************************************
  * Forced
  */

#  ifndef UNIXSTL_FORCED_ATOMIC_INTEGER_IMPLEMENTATIONS
#   error If you are forcing atomic integer support (by defining UNIXSTL_FORCE_ATOMIC_INTEGER_OPERATIONS) you must also define UNIXSTL_FORCED_ATOMIC_INTEGER_IMPLEMENTATIONS as the header containing the atomic integer operations, which will be included
#  endif /* UNIXSTL_FORCED_ATOMIC_INTEGER_IMPLEMENTATIONS */

#  include UNIXSTL_FORCED_ATOMIC_INTEGER_IMPLEMENTATIONS

# elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_GCC_BUILTINS)


 /* ************************************
  * GCC builtins
  */

STLSOFT_INLINE
atomic_int_t
atomic_exchange(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_exchange(pv, value);
}
# define UNIXSTL_HAS_atomic_exchange
# define UNIXSTL_HAS_ATOMIC_EXCHANGE


STLSOFT_INLINE
atomic_int_t
atomic_postadd(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_postadd(pv, value);
}
# define UNIXSTL_HAS_atomic_postadd
# define UNIXSTL_HAS_ATOMIC_POSTADD

STLSOFT_INLINE
atomic_int_t
atomic_preadd(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_preadd(pv, value);
}
# define UNIXSTL_HAS_atomic_preadd
# define UNIXSTL_HAS_ATOMIC_PREADD


STLSOFT_INLINE
void
atomic_decrement(
    atomic_int_t volatile*  pv
)
{
    STLSOFT_INTERNAL_ATOMIC_GCC_atomic_decrement(pv);
}
# define UNIXSTL_HAS_atomic_decrement
# define UNIXSTL_HAS_ATOMIC_DECREMENT

STLSOFT_INLINE
void
atomic_increment(
    atomic_int_t volatile*  pv
)
{
    STLSOFT_INTERNAL_ATOMIC_GCC_atomic_increment(pv);
}
# define UNIXSTL_HAS_atomic_increment
# define UNIXSTL_HAS_ATOMIC_INCREMENT


STLSOFT_INLINE
atomic_int_t
atomic_postdecrement(
    atomic_int_t volatile*  pv
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_postdecrement(pv);
}
# define UNIXSTL_HAS_atomic_postdecrement
# define UNIXSTL_HAS_ATOMIC_POSTDECREMENT

STLSOFT_INLINE
atomic_int_t
atomic_predecrement(
    atomic_int_t volatile*  pv
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_predecrement(pv);
}
# define UNIXSTL_HAS_atomic_predecrement
# define UNIXSTL_HAS_ATOMIC_PREDECREMENT


STLSOFT_INLINE
atomic_int_t
atomic_postincrement(
    atomic_int_t volatile*  pv
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_postincrement(pv);
}
# define UNIXSTL_HAS_atomic_postincrement
# define UNIXSTL_HAS_ATOMIC_POSTINCREMENT

STLSOFT_INLINE
atomic_int_t
atomic_preincrement(
    atomic_int_t volatile*  pv
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_preincrement(pv);
}
# define UNIXSTL_HAS_atomic_preincrement
# define UNIXSTL_HAS_ATOMIC_PREINCREMENT


STLSOFT_INLINE
atomic_int_t
atomic_read(
    atomic_int_t volatile*  pv
)
{
    return STLSOFT_INTERNAL_ATOMIC_GCC_atomic_read(pv);
}
# define UNIXSTL_HAS_atomic_read
# define UNIXSTL_HAS_ATOMIC_READ


STLSOFT_INLINE
void
atomic_write(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
    STLSOFT_INTERNAL_ATOMIC_GCC_atomic_write(pv, value);
}
# define UNIXSTL_HAS_atomic_write
# define UNIXSTL_HAS_ATOMIC_WRITE



# elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_MACOSX)


 /* ************************************
  * Mac OS-X
  */

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
atomic_int_t
atomic_postadd(
    atomic_int_t volatile*  pv
,   atomic_int_t            n
)
{
    return STLSOFT_NS_GLOBAL(OSAtomicAdd32Barrier)(n, stlsoft_const_cast(atomic_int_t*, pv)) - n;
}
#  define UNIXSTL_HAS_atomic_postadd
#  define UNIXSTL_HAS_ATOMIC_POSTADD

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
atomic_int_t
atomic_preadd(
    atomic_int_t volatile*  pv
,   atomic_int_t            n
)
{
    return STLSOFT_NS_GLOBAL(OSAtomicAdd32Barrier)(n, stlsoft_const_cast(atomic_int_t*, pv));
}
#  define UNIXSTL_HAS_atomic_preadd
#  define UNIXSTL_HAS_ATOMIC_PREADD

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
void
atomic_decrement(
    atomic_int_t volatile* pv
)
{
    STLSOFT_NS_GLOBAL(OSAtomicDecrement32Barrier)(stlsoft_const_cast(atomic_int_t*, pv));
}
#  define UNIXSTL_HAS_atomic_decrement
#  define UNIXSTL_HAS_ATOMIC_DECREMENT

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
void
atomic_increment(
    atomic_int_t volatile* pv
)
{
    STLSOFT_NS_GLOBAL(OSAtomicIncrement32Barrier)(stlsoft_const_cast(atomic_int_t*, pv));
}
#  define UNIXSTL_HAS_atomic_increment
#  define UNIXSTL_HAS_ATOMIC_INCREMENT

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
atomic_int_t
atomic_postdecrement(
    atomic_int_t volatile* pv
)
{
    return STLSOFT_NS_GLOBAL(OSAtomicDecrement32Barrier)(stlsoft_const_cast(atomic_int_t*, pv)) + 1;
}
#  define UNIXSTL_HAS_atomic_postdecrement
#  define UNIXSTL_HAS_ATOMIC_POSTDECREMENT

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
atomic_int_t
atomic_predecrement(
    atomic_int_t volatile* pv
)
{
    return STLSOFT_NS_GLOBAL(OSAtomicDecrement32Barrier)(stlsoft_const_cast(atomic_int_t*, pv));
}
#  define UNIXSTL_HAS_atomic_predecrement
#  define UNIXSTL_HAS_ATOMIC_PREDECREMENT

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
atomic_int_t
atomic_postincrement(
    atomic_int_t volatile* pv
)
{
    return STLSOFT_NS_GLOBAL(OSAtomicIncrement32Barrier)(stlsoft_const_cast(atomic_int_t*, pv)) - 1;
}
#  define UNIXSTL_HAS_atomic_postincrement
#  define UNIXSTL_HAS_ATOMIC_POSTINCREMENT

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
atomic_int_t
atomic_preincrement(
    atomic_int_t volatile* pv
)
{
    return STLSOFT_NS_GLOBAL(OSAtomicIncrement32Barrier)(stlsoft_const_cast(atomic_int_t*, pv));
}
#  define UNIXSTL_HAS_atomic_preincrement
#  define UNIXSTL_HAS_ATOMIC_PREINCREMENT

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE
atomic_int_t
atomic_read(
    atomic_int_t volatile* pv
)
{
    STLSOFT_NS_GLOBAL(OSMemoryBarrier)();

    return *pv;
}
#  define UNIXSTL_HAS_atomic_read
#  define UNIXSTL_HAS_ATOMIC_READ

/**
 *
 * \ingroup group__library__Synch
 */
/** Note: atomic_write() for PowerPC is not yet defined. If you wish to suggest an
 * implementation, it will be most welcome.
 *
 * \ingroup group__library__Synch
 */
/* STLSOFT_INLINE */
atomic_int_t
atomic_write(
    atomic_int_t volatile*  pv
,   atomic_int_t            n
);


# elif defined(UNIXSTL_ATOMIC_INTEGER_OPERATIONS_VIA_WINDOWS_INTERLOCKED)


 /* ************************************
  * Windows Interlocked
  */


STLSOFT_INLINE
atomic_int_t
atomic_exchange(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchange64(pv, value);
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchange(pv, value);
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_exchange
# define UNIXSTL_HAS_ATOMIC_EXCHANGE


STLSOFT_INLINE
atomic_int_t
atomic_postadd(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchangeAdd64(pv, value);
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchangeAdd(pv, value);
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_postadd
# define UNIXSTL_HAS_ATOMIC_POSTADD

STLSOFT_INLINE
atomic_int_t
atomic_preadd(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchangeAdd64(pv, value) + value;
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchangeAdd(pv, value) + value;
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_preadd
# define UNIXSTL_HAS_ATOMIC_PREADD


STLSOFT_INLINE
void
atomic_decrement(
    atomic_int_t volatile*  pv
)
{
#if 0
#elif defined(_WIN64)
    UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement64(pv);
#elif defined(_WIN32)
    UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement(pv);
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_decrement
# define UNIXSTL_HAS_ATOMIC_DECREMENT

STLSOFT_INLINE
void
atomic_increment(
    atomic_int_t volatile*  pv
)
{
#if 0
#elif defined(_WIN64)
    UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement64(pv);
#elif defined(_WIN32)
    UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement(pv);
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_increment
# define UNIXSTL_HAS_ATOMIC_INCREMENT


STLSOFT_INLINE
atomic_int_t
atomic_postdecrement(
    atomic_int_t volatile*  pv
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement64(pv) + 1;
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement(pv) + 1;
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_postdecrement
# define UNIXSTL_HAS_ATOMIC_POSTDECREMENT

STLSOFT_INLINE
atomic_int_t
atomic_predecrement(
    atomic_int_t volatile*  pv
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement64(pv);
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement(pv);
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_predecrement
# define UNIXSTL_HAS_ATOMIC_PREDECREMENT


STLSOFT_INLINE
atomic_int_t
atomic_postincrement(
    atomic_int_t volatile*  pv
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement64(pv) - 1;
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement(pv) - 1;
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_postincrement
# define UNIXSTL_HAS_ATOMIC_POSTINCREMENT

STLSOFT_INLINE
atomic_int_t
atomic_preincrement(
    atomic_int_t volatile*  pv
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement64(pv);
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement(pv);
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_preincrement
# define UNIXSTL_HAS_ATOMIC_PREINCREMENT


STLSOFT_INLINE
atomic_int_t
atomic_read(
    atomic_int_t volatile*  pv
)
{
    return *pv;
}
# define UNIXSTL_HAS_atomic_read
# define UNIXSTL_HAS_ATOMIC_READ


STLSOFT_INLINE
atomic_int_t
atomic_write(
    atomic_int_t volatile*  pv
,   atomic_int_t            value
)
{
#if 0
#elif defined(_WIN64)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchange64(pv, value);
#elif defined(_WIN32)
    return UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchange(pv, value);
#else
# error Architecture not recognised
#endif
}
# define UNIXSTL_HAS_atomic_write
# define UNIXSTL_HAS_ATOMIC_WRITE





# else

#  error Atomic integer operations not supported: see unixstl/synch/util/features.h for details
# endif /* ? */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

