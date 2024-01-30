/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/synch/util/windows_api_.h
 *
 * Purpose:     Discrimination of synchronisation features.
 *
 * Created:     3rd January 2017
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/* STLSOFT:Windows:FILE_EXCEPTED */

/** \file unixstl/synch/util/windows_api_.h
 *
 * \brief [INTERNAL] Discrimination of synchronisation features
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_WINDOWS_API_
#define UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_WINDOWS_API_

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_WINDOWS_API__MAJOR    1
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_WINDOWS_API__MINOR    2
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_WINDOWS_API__REVISION 4
# define UNIXSTL_VER_UNIXSTL_SYNCH_UTIL_H_WINDOWS_API__EDIT     11
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

#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_TYPES
# include <unixstl/synch/atomic_types.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_H_ATOMIC_TYPES */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_UTIL_H_WINDOWS_API_
# include <stlsoft/synch/util/windows_api_.h>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_UTIL_H_WINDOWS_API_ */

#ifdef __cplusplus
# include <stlsoft/conversion/sap_cast.hpp>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

#if 0
#elif defined(_WIN64)
#elif defined(_WIN32)

STLSOFT_INLINE
long volatile*
UNIXSTL_INTERNAL_SYNCH_32cast_(
    UNIXSTL_NS_QUAL(atomic_int_t) volatile* p
)
{
# ifdef __cplusplus

    return STLSOFT_NS_QUAL(sap_cast)<long volatile*>(p);
# else
    return STLSOFT_C_CAST(long volatile*, (p));
# endif
}

# if defined(_MSC_VER) && \
     _MSC_VER < 1400
STLSOFT_INLINE
long*
UNIXSTL_INTERNAL_SYNCH_32cast_v_(
    UNIXSTL_NS_QUAL(atomic_int_t) volatile* p
)
{
    return STLSOFT_CONST_CAST(long*, UNIXSTL_INTERNAL_SYNCH_32cast_(p));
}
#  define UNIXSTL_INTERNAL_SYNCH_32cast_                    UNIXSTL_INTERNAL_SYNCH_32cast_v_
# else

#  define UNIXSTL_INTERNAL_SYNCH_32cast_                    UNIXSTL_INTERNAL_SYNCH_32cast_
# endif
#else
# error Architecture not recognised
#endif

#ifndef UNIXSTL_INTERNAL_SYNCH_32cast_
# define UNIXSTL_INTERNAL_SYNCH_32cast_(p)                          (p)
#endif /* UNIXSTL_INTERNAL_SYNCH_32cast_ */

#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement64       STLSOFT_NS_GLOBAL_(InterlockedDecrement64)
#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedDecrement(p)      STLSOFT_NS_GLOBAL_(InterlockedDecrement)(UNIXSTL_INTERNAL_SYNCH_32cast_((p)))

#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchange64        STLSOFT_NS_GLOBAL_(InterlockedExchange64)
#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchange(p, n)    STLSOFT_NS_GLOBAL_(InterlockedExchange)(UNIXSTL_INTERNAL_SYNCH_32cast_((p)), (n))

#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchangeAdd64     STLSOFT_NS_GLOBAL_(InterlockedExchangeAdd64)
#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedExchangeAdd(p, n) STLSOFT_NS_GLOBAL_(InterlockedExchangeAdd)(UNIXSTL_INTERNAL_SYNCH_32cast_((p)), (n))

#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement64       STLSOFT_NS_GLOBAL_(InterlockedIncrement64)
#define UNIXSTL_INTERNAL_SYNCH_Windows_InterlockedIncrement(p)      STLSOFT_NS_GLOBAL_(InterlockedIncrement)(UNIXSTL_INTERNAL_SYNCH_32cast_((p)))

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_WINDOWS_API_ */

/* ///////////////////////////// end of file //////////////////////////// */

