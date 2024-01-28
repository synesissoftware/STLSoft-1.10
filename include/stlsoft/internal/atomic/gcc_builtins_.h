/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/atomic/gcc_builtins_.h
 *
 * Purpose:     Atomic operations built around GCC's builtins
 *
 * Created:     6th January 2017
 * Updated:     22nd January 2024
 *
 * Author:      Matthew Wilson
 *
 * Home:        http://www.stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2017-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/internal/atomic/gcc_builtins_.h
 *
 * \brief [C, C++] Atomic operations built around GCC's builtins.
 */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_ATOMIC_H_GCC_BUILTINS_
#define STLSOFT_INCL_STLSOFT_INTERNAL_ATOMIC_H_GCC_BUILTINS_

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_INTERNAL_ATOMIC_H_GCC_BUILTINS__MAJOR     1
# define STLSOFT_VER_H_STLSOFT_INTERNAL_ATOMIC_H_GCC_BUILTINS__MINOR     0
# define STLSOFT_VER_H_STLSOFT_INTERNAL_ATOMIC_H_GCC_BUILTINS__REVISION  3
# define STLSOFT_VER_H_STLSOFT_INTERNAL_ATOMIC_H_GCC_BUILTINS__EDIT      8
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if !defined(STLSOFT_CF_SUPPORT_ATOMIC_GCC_BUILTINS)
# error This file cannot be used with compilers that do not support GCC atomic built-in operations
#endif

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define STLSOFT_INTERNAL_ATOMIC_GCC_memorder_ADD_           __ATOMIC_ACQ_REL
#define STLSOFT_INTERNAL_ATOMIC_GCC_memorder_INC_           __ATOMIC_ACQ_REL
#define STLSOFT_INTERNAL_ATOMIC_GCC_memorder_READ_          __ATOMIC_ACQUIRE
#define STLSOFT_INTERNAL_ATOMIC_GCC_memorder_WRITE_         __ATOMIC_RELEASE

/* exchange */

#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_exchange(pa, value)      __atomic_exchange_n((pa), (value), STLSOFT_INTERNAL_ATOMIC_GCC_memorder_READ_)

/* addition */

#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_postadd(pa, value)       __atomic_fetch_add((pa), (value), STLSOFT_INTERNAL_ATOMIC_GCC_memorder_ADD_)
#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_preadd(pa, value)        __atomic_add_fetch((pa), (value), STLSOFT_INTERNAL_ATOMIC_GCC_memorder_ADD_)

/* increment / decrement */

#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_decrement(pa)            STLSOFT_STATIC_CAST(void, __atomic_sub_fetch((pa), 1, STLSOFT_INTERNAL_ATOMIC_GCC_memorder_INC_))
#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_increment(pa)            STLSOFT_STATIC_CAST(void, __atomic_fetch_add((pa), 1, STLSOFT_INTERNAL_ATOMIC_GCC_memorder_INC_))

#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_postdecrement(pa)        __atomic_fetch_sub((pa), 1, STLSOFT_INTERNAL_ATOMIC_GCC_memorder_INC_)
#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_predecrement(pa)         __atomic_sub_fetch((pa), 1, STLSOFT_INTERNAL_ATOMIC_GCC_memorder_INC_)

#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_postincrement(pa)        __atomic_fetch_add((pa), 1, STLSOFT_INTERNAL_ATOMIC_GCC_memorder_INC_)
#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_preincrement(pa)         __atomic_add_fetch((pa), 1, STLSOFT_INTERNAL_ATOMIC_GCC_memorder_INC_)

/* read / write */

#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_read(pa)                 __atomic_load_n((pa), STLSOFT_INTERNAL_ATOMIC_GCC_memorder_READ_)

#define STLSOFT_INTERNAL_ATOMIC_GCC_atomic_write(pa, value)         __atomic_store_n((pa), (value), STLSOFT_INTERNAL_ATOMIC_GCC_memorder_WRITE_)

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_ATOMIC_H_GCC_BUILTINS_ */

/* ///////////////////////////// end of file //////////////////////////// */

