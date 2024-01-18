/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/util/semaphore_api_.h
 *
 * Purpose:     Discrimination of synchronisation features.
 *
 * Created:     16th January 2024
 * Updated:     18th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2024, Matthew Wilson and Synesis Information Systems
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


/** \file unixstl/synch/util/semaphore_api_.h
 *
 * \brief [INTERNAL] Discrimination of synchronisation features
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_SEMAPHORE_API_
#define UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_SEMAPHORE_API_

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_SEMAPHORE_API__MAJOR    1
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_SEMAPHORE_API__MINOR    0
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_SEMAPHORE_API__REVISION 1
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_SEMAPHORE_API__EDIT     2
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

#if 0
#elif defined(UNIXSTL_USE_SEMAPHORE_POSIX)
# ifdef UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH
#  error Cannot define both UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH and UNIXSTL_USE_SEMAPHORE_POSIX
# endif /* UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH */
#elif defined(UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH)
# ifdef UNIXSTL_USE_SEMAPHORE_POSIX
#  error Cannot define both UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH and UNIXSTL_USE_SEMAPHORE_POSIX
# endif /* UNIXSTL_USE_SEMAPHORE_POSIX */
#else

# if 0
# elif 0 || \
       defined(UNIXSTL_OS_IS_APPLE) || \
       defined(UNIXSTL_OS_IS_MACOSX) || \
       0

#  define UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH
# else

#  define UNIXSTL_USE_SEMAPHORE_POSIX
# endif
#endif


#ifdef UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH
# ifndef STLSOFT_INCL_DISPATCH_H_DISPATCH
#  define STLSOFT_INCL_DISPATCH_H_DISPATCH
#  include <dispatch/dispatch.h>
# endif /* !STLSOFT_INCL_DISPATCH_H_DISPATCH */
# ifndef STLSOFT_INCL_H_ERRNO
#  define STLSOFT_INCL_H_ERRNO
#  include <errno.h>
# endif /* !STLSOFT_INCL_H_ERRNO */
# ifndef STLSOFT_INCL_H_STDINT
#  define STLSOFT_INCL_H_STDINT
#  include <stdint.h>
# endif /* !STLSOFT_INCL_H_STDINT */
#endif /* UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH */

#ifdef UNIXSTL_USE_SEMAPHORE_POSIX
# ifndef STLSOFT_INCL_H_SEMAPHORE
#  define STLSOFT_INCL_H_SEMAPHORE
#  include <semaphore.h>
# endif /* !STLSOFT_INCL_H_SEMAPHORE */
#endif /* UNIXSTL_USE_SEMAPHORE_POSIX */


/* /////////////////////////////////////////////////////////////////////////
 * API
 */

#ifdef UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH

/*
 * This work informed by the following:
 *
 * - Stack Overflow answer (https://stackoverflow.com/a/27847103);
 * - Apple Lists answer (https://lists.apple.com/archives/darwin-kernel/2009/Apr/msg00010.html);
 */

typedef dispatch_semaphore_t                                UNIXSTL_INTERNAL_SYNCH_POSIX_sem_t;

STLSOFT_INLINE
int
UNIXSTL_INTERNAL_SYNCH_POSIX_sem_destroy(
    UNIXSTL_INTERNAL_SYNCH_POSIX_sem_t* sem
)
{
    STLSOFT_SUPPRESS_UNUSED(sem);

    return 0;
}

STLSOFT_INLINE
int
UNIXSTL_INTERNAL_SYNCH_POSIX_sem_init(
    UNIXSTL_INTERNAL_SYNCH_POSIX_sem_t* sem
,   int                                 pshared
,   unsigned int                        value
)
{
    STLSOFT_SUPPRESS_UNUSED(pshared);

    *sem = dispatch_semaphore_create(value);

    return 0;
}


STLSOFT_INLINE
int
UNIXSTL_INTERNAL_SYNCH_POSIX_sem_post(
    UNIXSTL_INTERNAL_SYNCH_POSIX_sem_t* sem
)
{
    intptr_t const r = dispatch_semaphore_signal(*sem);

    if (0 != r)
    {
        errno = EINVAL;

        return -1;
    }

    return 0;
}

STLSOFT_INLINE
int
UNIXSTL_INTERNAL_SYNCH_POSIX_sem_trywait(
    UNIXSTL_INTERNAL_SYNCH_POSIX_sem_t* sem
)
{
    intptr_t const r = dispatch_semaphore_wait(*sem, DISPATCH_TIME_NOW);

    if (0 != r)
    {
        errno = EAGAIN;

        return -1;
    }

    return 0;
}

STLSOFT_INLINE
int
UNIXSTL_INTERNAL_SYNCH_POSIX_sem_wait(
    UNIXSTL_INTERNAL_SYNCH_POSIX_sem_t* sem
)
{
    intptr_t const r = dispatch_semaphore_wait(*sem, DISPATCH_TIME_FOREVER);

    if (0 != r)
    {
        errno = EINVAL;

        return -1;
    }

    return 0;
}
#endif /* UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH */


#ifdef UNIXSTL_USE_SEMAPHORE_POSIX

# define UNIXSTL_INTERNAL_SYNCH_POSIX_sem_t                 STLSOFT_NS_GLOBAL(sem_t)

# define UNIXSTL_INTERNAL_SYNCH_POSIX_sem_destroy           STLSOFT_NS_GLOBAL(sem_destroy)
# define UNIXSTL_INTERNAL_SYNCH_POSIX_sem_init              STLSOFT_NS_GLOBAL(sem_init)
# define UNIXSTL_INTERNAL_SYNCH_POSIX_sem_post              STLSOFT_NS_GLOBAL(sem_post)
# define UNIXSTL_INTERNAL_SYNCH_POSIX_sem_trywait           STLSOFT_NS_GLOBAL(sem_trywait)
# define UNIXSTL_INTERNAL_SYNCH_POSIX_sem_wait              STLSOFT_NS_GLOBAL(sem_wait)
#endif /* UNIXSTL_USE_SEMAPHORE_POSIX */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_SEMAPHORE_API_ */

/* ///////////////////////////// end of file //////////////////////////// */

