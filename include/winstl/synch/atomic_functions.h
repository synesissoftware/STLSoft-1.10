/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/atomic_functions.h (originally MLAtomic.cpp, ::SynesisStd)
 *
 * Purpose:     WinSTL atomic functions.
 *
 * Created:     23rd October 1997
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


/** \file winstl/synch/atomic_functions.h
 *
 * \brief [C, C++] Definition of the atomic functions
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS_MAJOR     4
# define WINSTL_VER_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS_MINOR     8
# define WINSTL_VER_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS_REVISION  3
# define WINSTL_VER_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS_EDIT      231
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

#ifndef WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_TYPES
# include <winstl/synch/atomic_types.h>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_TYPES */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Synchronization
# include <winstl/api/external/Synchronization.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Synchronization */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if !defined(WINSTL_ARCH_IS_X86) && \
    !defined(WINSTL_ARCH_IS_IA64) && \
    !defined(WINSTL_ARCH_IS_X64)
# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */

#ifdef STLSOFT_ATOMIC_CALLCONV
# undef STLSOFT_ATOMIC_CALLCONV
#endif /* STLSOFT_ATOMIC_CALLCONV */
#ifdef WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL
# undef WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL
#endif /* WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL */
#ifdef WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL
# undef WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL
#endif /* WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL */

#ifndef STLSOFT_NO_FASTCALL
# if defined(STLSOFT_COMPILER_IS_BORLAND) || \
     defined(STLSOFT_COMPILER_IS_DMC) || \
     defined(STLSOFT_COMPILER_IS_WATCOM)
#  define STLSOFT_NO_FASTCALL
# endif /* compiler */
#endif /* STLSOFT_NO_FASTCALL */

#if defined(WINSTL_ARCH_IS_X86)

# if defined(STLSOFT_CF_FASTCALL_SUPPORTED) && \
     !defined(STLSOFT_NO_FASTCALL)
#  define WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL
#  define WINSTL_ATOMIC_FNS_CALLCONV                        __fastcall
# elif defined(STLSOFT_CF_STDCALL_SUPPORTED)
#  define WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL
#  define WINSTL_ATOMIC_FNS_CALLCONV                        __stdcall
# else
#  error Need to define calling convention
# endif /* call-conv */

#elif defined(WINSTL_ARCH_IS_IA64) || \
      defined(WINSTL_ARCH_IS_X64)

#  define WINSTL_ATOMIC_FNS_CALLCONV_IS_CDECL
#  define WINSTL_ATOMIC_FNS_CALLCONV                        __cdecl

#else /* ? arch */
# error Only defined for the Intel x86 and IA64 architectures
#endif /* arch */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if 1 &&\
     !defined(_FILETIME_) &&\
     !defined(EXCEPTION_POSSIBLE_DEADLOCK) &&\
     !defined(FLAG_FILE_FIRST_PIPE_INSTANCE) &&\
     !defined(COPY_FILE_ALLOW_DECRYPTED_DESTINATION) &&\
     1

STLSOFT_INLINE
LONG*
winstl_C_internal_synch_atomic_ptrconv32_(
    WINSTL_NS_QUAL(atomic_int32_t) volatile* pv
)
{
    STLSOFT_STATIC_ASSERT(sizeof(LONG) == sizeof(WINSTL_NS_QUAL(atomic_int32_t)));

    return STLSOFT_C_CAST(LONG*, STLSOFT_CONST_CAST(WINSTL_NS_QUAL(atomic_int32_t*), pv));
}
#  if 0
#  elif defined(WINSTL_OS_IS_WIN64)
STLSOFT_INLINE
LONGLONG*
winstl_C_internal_synch_atomic_ptrconv64_(
    WINSTL_NS_QUAL(atomic_int64_t) volatile* pv
)
{
    STLSOFT_STATIC_ASSERT(sizeof(LONGLONG) == sizeof(WINSTL_NS_QUAL(atomic_int64_t)));

    return STLSOFT_C_CAST(LONGLONG*, STLSOFT_CONST_CAST(WINSTL_NS_QUAL(atomic_int64_t*), pv));
}
#  else
#  endif
# else

STLSOFT_INLINE
LONG volatile*
winstl_C_internal_synch_atomic_ptrconv32_(
    WINSTL_NS_QUAL(atomic_int32_t) volatile* pv
)
{
    return STLSOFT_C_CAST(LONG volatile*, pv);
}
#  if 0
#  elif defined(WINSTL_OS_IS_WIN64)
STLSOFT_INLINE
LONGLONG volatile*
winstl_C_internal_synch_atomic_ptrconv64_(
    WINSTL_NS_QUAL(atomic_int64_t) volatile* pv
)
{
    STLSOFT_STATIC_ASSERT(sizeof(LONGLONG) == sizeof(WINSTL_NS_QUAL(atomic_int64_t)));

    return STLSOFT_C_CAST(LONGLONG volatile*, pv);
}
#  else
#  endif
# endif
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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
 * implementation options
 *
 * Because some compilers can make the code actually faster when the naked
 * functions are not inline, we provide for that here. If you want to make
 * out-of-line the functions, then you just need to define the symbol
 * WINSTL_ATOMIC_FNS_DECLARATION_ONLY in the code that uses it, and define
 * the symbol WINSTL_ATOMIC_FNS_DEFINITION in one implementation file.
 */

#ifdef WINSTL_ATOMIC_FNS_DECL_
# undef WINSTL_ATOMIC_FNS_DECL_
#endif /* WINSTL_ATOMIC_FNS_DECL_ */

#ifdef WINSTL_ATOMIC_FNS_IMPL_
# undef WINSTL_ATOMIC_FNS_IMPL_
#endif /* WINSTL_ATOMIC_FNS_IMPL_ */


#if defined(WINSTL_ATOMIC_FNS_DECLARATION_ONLY)

/* Only the function declarations are included */
# define WINSTL_ATOMIC_FNS_DECL_(type)              type WINSTL_ATOMIC_FNS_CALLCONV
#elif defined(WINSTL_ATOMIC_FNS_DEFINITION)

/* Only the function definitions are included */
# ifdef STSLSOFT_INLINE_ASM_SUPPORTED
#  define WINSTL_ATOMIC_FNS_IMPL_(type)             __declspec(naked) type WINSTL_ATOMIC_FNS_CALLCONV
# else /* ? STSLSOFT_INLINE_ASM_SUPPORTED */
#  define WINSTL_ATOMIC_FNS_IMPL_(type)             type WINSTL_ATOMIC_FNS_CALLCONV
# endif /* STSLSOFT_INLINE_ASM_SUPPORTED */
#else /* ? declaration / definition */

# if defined(STLSOFT_COMPILER_IS_MWERKS) && \
     (__MWERKS__ & 0xFF00) < 0x3000
#  error CodeWarrior 7 and earlier does not generate correct code when inline naked functions are used
# endif /* compiler */


#if !defined(__cplusplus) && \
    defined(STSLSOFT_INLINE_ASM_SUPPORTED)
 /* Not currently supporting inline assembler for C compilation. It's perfectly possible, but need more work to sort out. */
# undef STSLSOFT_INLINE_ASM_SUPPORTED
#endif /* !__cplusplus && STSLSOFT_INLINE_ASM_SUPPORTED */

# ifdef STSLSOFT_INLINE_ASM_SUPPORTED
  /* The default is to define them inline */
#  ifdef STSLSOFT_ASM_IN_INLINE_SUPPORTED
#   define WINSTL_ATOMIC_FNS_DECL_(type)             STLSOFT_INLINE type WINSTL_ATOMIC_FNS_CALLCONV
#   define WINSTL_ATOMIC_FNS_IMPL_(type)             STLSOFT_INLINE __declspec(naked) type WINSTL_ATOMIC_FNS_CALLCONV
#  else /* ? STSLSOFT_ASM_IN_INLINE_SUPPORTED */
#   define WINSTL_ATOMIC_FNS_DECL_(type)             type WINSTL_ATOMIC_FNS_CALLCONV
#   define WINSTL_ATOMIC_FNS_IMPL_(type)             static __declspec(naked) type WINSTL_ATOMIC_FNS_CALLCONV
#  endif /* STSLSOFT_ASM_IN_INLINE_SUPPORTED */
# else /* ? STSLSOFT_INLINE_ASM_SUPPORTED */
  /* ASM not supported, so we're using the Win32 functions */
#  if defined(__cplusplus)
#   define WINSTL_ATOMIC_FNS_DECL_(type)             STLSOFT_INLINE type WINSTL_ATOMIC_FNS_CALLCONV
#   define WINSTL_ATOMIC_FNS_IMPL_(type)             STLSOFT_INLINE type WINSTL_ATOMIC_FNS_CALLCONV
#  else /* ? __cplusplus */
#   define WINSTL_ATOMIC_FNS_DECL_(type)             STLSOFT_INLINE type WINSTL_ATOMIC_FNS_CALLCONV
#   define WINSTL_ATOMIC_FNS_IMPL_(type)             STLSOFT_INLINE type WINSTL_ATOMIC_FNS_CALLCONV
#  endif /* __cplusplus */
# endif /* STSLSOFT_INLINE_ASM_SUPPORTED */
#endif /* declaration / definition */

/* /////////////////////////////////////////////////////////////////////////
 * atomic function declarations
 */

#if !defined(WINSTL_ATOMIC_FNS_DEFINITION) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/* Uni-processor variants */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_preincrement_up(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_predecrement_up(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postincrement_up(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postdecrement_up(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(void) atomic_increment_up(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(void) atomic_decrement_up(atomic_int_t volatile* pl);

WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_exchange_up(atomic_int_t volatile* pl, atomic_int_t n);

WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_write_up(atomic_int_t volatile* pl, atomic_int_t n);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_read_up(atomic_int_t volatile const* pl);

WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postadd_up(atomic_int_t volatile* pl, atomic_int_t n);
atomic_int_t atomic_preadd_up(atomic_int_t volatile* pl, atomic_int_t n);



/* SMP variants */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_preincrement_smp(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_predecrement_smp(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postincrement_smp(atomic_int_t volatile* pl);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postdecrement_smp(atomic_int_t volatile* pl);
void atomic_increment_smp(atomic_int_t volatile* pl);
void atomic_decrement_smp(atomic_int_t volatile* pl);

WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_exchange_smp(atomic_int_t volatile* pl, atomic_int_t n);

WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_write_smp(atomic_int_t volatile* pl, atomic_int_t n);
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_read_smp(atomic_int_t volatile const* pl);

WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postadd_smp(atomic_int_t volatile* pl, atomic_int_t n);
atomic_int_t atomic_preadd_smp(atomic_int_t volatile* pl, atomic_int_t n);


# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* Multi-processor detection variants */

/** Increments the variable atomically, and returns the result of the
 * operation
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_preincrement(atomic_int_t volatile* pl);
/** Increments the (32-bit) variable atomically, and returns the result of
 * the operation
 *
 * \ingroup group__library__Synch
 */
atomic_int32_t atomic_preincrement32(atomic_int32_t volatile* pv);

/** Decrements the variable atomically, and returns the result of the
 * operation
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_predecrement(atomic_int_t volatile* pl);
/** Decrements the (32-bit) variable atomically, and returns the result of
 * the operation
 *
 * \ingroup group__library__Synch
 */
atomic_int32_t atomic_predecrement32(atomic_int32_t volatile* pv);

/** Increments the variable atomically, and returns the value prior to the
 * operation
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postincrement(atomic_int_t volatile* pl);
/** Increments the (32-bit) variable atomically, and returns the value prior
 * to the operation
 *
 * \ingroup group__library__Synch
 */
atomic_int32_t atomic_postincrement32(atomic_int32_t volatile* pl);

/** Decrements the variable atomically, and returns the value prior to the
 * operation
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postdecrement(atomic_int_t volatile* pl);
/** Decrements the (32-bit) variable atomically, and returns the value prior
 * to the operation
 *
 * \ingroup group__library__Synch
 */
atomic_int32_t atomic_postdecrement32(atomic_int32_t volatile* pl);

/** Increments the variable atomically
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(void) atomic_increment(atomic_int_t volatile* pl);
/** Increments the (32-bit) variable atomically
 *
 * \ingroup group__library__Synch
 */
void atomic_increment32(atomic_int32_t volatile* pl);

/** Decrements the variable atomically
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(void) atomic_decrement(atomic_int_t volatile* pl);
/** Decrements the (32-bit) variable atomically
 *
 * \ingroup group__library__Synch
 */
void atomic_decrement32(atomic_int32_t volatile* pl);

/** Exchanges atomically a value with the variable
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_exchange(atomic_int_t volatile* pl, atomic_int_t n);

/** Writes to the variable atomically
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_write(atomic_int_t volatile* pl, atomic_int_t n);

/** Reads from the variable atomically
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_read(atomic_int_t volatile const* pl);

/** Add to the variable atomically, and returns the value prior to the
 * operation
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_DECL_(atomic_int_t) atomic_postadd(atomic_int_t volatile* pl, atomic_int_t n);

/** Add to the variable atomically, and returns the result of the operation
 *
 * \ingroup group__library__Synch
 */
atomic_int_t atomic_preadd(atomic_int_t volatile* pl, atomic_int_t n);


#endif /* !WINSTL_ATOMIC_FNS_DEFINITION */

/* /////////////////////////////////////////////////////////////////////////
 * atomic function definitions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# if !defined(WINSTL_ATOMIC_FNS_DECLARATION_ONLY)

#  ifdef STSLSOFT_INLINE_ASM_SUPPORTED
/* Inline assembler versions */

#ifdef STLSOFT_COMPILER_IS_BORLAND
# pragma warn -8002     /* Suppresses: "Restarting compile using assembly" */
# pragma warn -8070     /* Suppresses: "Function should return a value" */
#endif /* compiler */

/* Uni-processor */

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_preincrement_up(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        xadd dword ptr [ecx], eax

        /* Since this is pre-increment, we need to inc eax to catch up with the
         * real value
         */
        inc eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_predecrement_up(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        xadd dword ptr [ecx], eax

        /* Since this is pre-decrement, we need to inc eax to catch up with the
         * real value
         */
        dec eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postincrement_up(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        xadd dword ptr [ecx], eax

        /* Since this is post-increment, we need do nothing, since the previous
         * value is in eax
         */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postdecrement_up(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        xadd dword ptr [ecx], eax

        /* Since this is post-decrement, we need do nothing, since the previous
         * value is in eax
         */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(void) atomic_increment_up(atomic_int_t volatile* /* pl */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        add dword ptr [ecx], 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(void) atomic_decrement_up(atomic_int_t volatile* /* pl */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        sub dword ptr [ecx], 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_exchange_up(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Just exchange *pl and n */
        xchg dword ptr [ecx], edx

        /* The previous value goes into edx, so me move it into eax for return */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        xchg dword ptr [ecx], eax

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}


/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_read_up(atomic_int_t volatile const* /* pl */)
{
    _asm
    {
        mov eax, 0
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */

#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */
        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        /* pop 0 into eax, which can then be atomically added into *pl (held
         * in ecx), leaving the value unchanged.
         */
        xadd dword ptr [ecx], eax

        /* Since it's an xadd it exchanges the previous value into eax, which
         * is exactly what's required
         */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_write_up(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Just exchange *pl and n */
        xchg dword ptr [ecx], edx

        /* The previous value goes into edx, so me move it into eax for return */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        xchg dword ptr [ecx], eax

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}


/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postadd_up(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    /* Thanks to Eugene Gershnik for the fast-call implementation */
    __asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Simply atomically add them, which will leave the previous value
         * in edx
         */
        xadd dword ptr [ecx], edx

        /* Just need to move adx into eax to return it */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */

        /* Simply atomically add them, which will leave the previous value
         * in edx
         */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        xadd dword ptr [ecx], eax

        /* Just need to move adx into eax to return it */

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}

/* Symmetric multi-processor */

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_preincrement_smp(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        lock xadd dword ptr [ecx], eax

        /* Since this is pre-increment, we need to inc eax to catch up with the
         * real value
         */
        inc eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_predecrement_smp(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        lock xadd dword ptr [ecx], eax

        /* Since this is pre-decrement, we need to inc eax to catch up with the
         * real value
         */
        dec eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postincrement_smp(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        lock xadd dword ptr [ecx], eax

        /* Since this is post-increment, we need do nothing, since the previous
         * value is in eax
         */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postdecrement_smp(atomic_int_t volatile* /* pl */)
{
    _asm
    {
        /* pop 1 into eax, which can then be atomically added into *pl (held
         * in ecx). Since it's an xadd it exchanges the previous value into eax
         */
        mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */

        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        lock xadd dword ptr [ecx], eax

        /* Since this is post-decrement, we need do nothing, since the previous
         * value is in eax
         */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_exchange_smp(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Just exchange *pl and n */
        /* lock */ xchg dword ptr [ecx], edx

        /* The previous value goes into edx, so me move it into eax for return */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        /* lock */ xchg dword ptr [ecx], eax

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_read_smp(atomic_int_t volatile const* /* pl */)
{
    _asm
    {
        mov eax, 0
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl */

#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack */
        mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

        /* pop 0 into eax, which can then be atomically added into *pl (held
         * in ecx), leaving the value unchanged.
         */
        lock xadd dword ptr [ecx], eax

        /* Since it's an xadd it exchanges the previous value into eax, which
         * is exactly what's required
         */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        ret 4
#endif /* call-conv */
    }
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_write_smp(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Just exchange *pl and n */
        /* lock */ xchg dword ptr [ecx], edx

        /* The previous value goes into edx, so me move it into eax for return */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        /* lock */ xchg dword ptr [ecx], eax

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}


/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postadd_smp(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    /* Thanks to Eugene Gershnik for the fast-call implementation */
    __asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Simply atomically add them, which will leave the previous value
         * in edx
         */
        lock xadd dword ptr [ecx], edx

        /* Just need to move adx into eax to return it */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */

        /* Simply atomically add them, which will leave the previous value
         * in edx
         */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        lock xadd dword ptr [ecx], eax

        /* Just need to move adx into eax to return it */

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}

/* Processor detection */

namespace ximpl
{
    inline ws_bool_t is_host_up()
    {
        /* All these statics are guaranteed to be zero by static initialisation */
        static atomic_int_t s_spin; /* The spin variable */
        static ws_bool_t    s_init; /* This is guaranteed to be zero */
        static ws_bool_t    s_up;   /* This is the flag variable, also guaranteed to be zero */

        /* Simple spin lock */
        if (!s_init) /* Low cost pre-test. In the unlikely event that another thread does come in and */
        {           /* also sees this as false, the dual initialisation of all three statics is benign */

            for (; 0 != atomic_exchange_smp(&s_spin, 1); )
            {}

            if (!s_init)
            {
                SYSTEM_INFO sys_info;

                ::GetSystemInfo(&sys_info);

                s_init = true;

                s_up = 1 == sys_info.dwNumberOfProcessors;
            }
            atomic_write_smp(&s_spin, 0);
        }

        return s_up;
    }

    /* s_up is guaranteed to be zero at load time.
     *
     * There is a race condition with all static variables, since multiple threads
     * can come in and one can have set the hidden flag variable without first
     * setting the static variable itself, just at the time that an arbitrary number
     * of other threads pick up the pre-initialised value.
     *
     * However, because the test here is whether to skip the lock, the pathological
     * case is benign. The only cost in the very rare case where it happens is that
     * the thread(s) will use bus locking until such time as the static is fully
     * initialised.
     */
    static ws_bool_t    s_up = is_host_up();
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_preincrement(atomic_int_t volatile* /* pl */)
{
    using namespace ximpl;

    if (s_up)
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            xadd dword ptr [ecx], eax

            /* Since this is pre-increment, we need to inc eax to catch up with the
             * real value
             */
            inc eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
    else
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            lock xadd dword ptr [ecx], eax

            /* Since this is pre-increment, we need to inc eax to catch up with the
             * real value
             */
            inc eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE atomic_int32_t atomic_preincrement32(atomic_int32_t volatile* pv)
{
    return atomic_preincrement(pv);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_predecrement(atomic_int_t volatile* /* pl */)
{
    using namespace ximpl;

    if (s_up)
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            xadd dword ptr [ecx], eax

            /* Since this is pre-decrement, we need to inc eax to catch up with the
             * real value
             */
            dec eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
    else
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            lock xadd dword ptr [ecx], eax

            /* Since this is pre-decrement, we need to inc eax to catch up with the
             * real value
             */
            dec eax

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE atomic_int32_t atomic_predecrement32(atomic_int32_t volatile* pv)
{
    return atomic_predecrement(pv);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postincrement(atomic_int_t volatile* /* pl */)
{
    using namespace ximpl;

    if (s_up)
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            xadd dword ptr [ecx], eax

            /* Since this is post-increment, we need do nothing, since the previous
             * value is in eax
             */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
    else
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            lock xadd dword ptr [ecx], eax

            /* Since this is post-increment, we need do nothing, since the previous
             * value is in eax
             */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE atomic_int32_t atomic_postincrement32(atomic_int32_t volatile* pv)
{
    return atomic_postincrement(pv);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postdecrement(atomic_int_t volatile* /* pl */)
{
    using namespace ximpl;

    if (s_up)
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            xadd dword ptr [ecx], eax

            /* Since this is post-decrement, we need do nothing, since the previous
             * value is in eax
             */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
    else
    {
        _asm
        {
            /* pop 1 into eax, which can then be atomically added into *pl (held
             * in ecx). Since it's an xadd it exchanges the previous value into eax
             */
            mov eax, -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            lock xadd dword ptr [ecx], eax

            /* Since this is post-decrement, we need do nothing, since the previous
             * value is in eax
             */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE atomic_int32_t atomic_postdecrement32(atomic_int32_t volatile* pv)
{
    return atomic_postdecrement(pv);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(void) atomic_increment(atomic_int_t volatile* /* pl */)
{
    using namespace ximpl;

    if (s_up)
    {
        _asm
        {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            add dword ptr [ecx], 1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
    else
    {
        _asm
        {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            /* The IA-32 Intel Architecture Software Developer's Manual, volume 2
             * states that a LOCK can be prefixed to ADD, but CodePlay VectorC
             * has a problem with it.
             */
#if defined(STLSOFT_COMPILER_IS_VECTORC)
            mov eax, 1
            lock xadd dword ptr [ecx], eax
#else /* ? compiler */
            lock add dword ptr [ecx], 1
#endif /* compiler */


#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE void atomic_increment32(atomic_int32_t volatile* pv)
{
    atomic_increment(pv);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(void) atomic_decrement(atomic_int_t volatile* /* pl */)
{
    using namespace ximpl;

    if (s_up)
    {
        _asm
        {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            add dword ptr [ecx], -1

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
    else
    {
        _asm
        {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */

            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

#if defined(STLSOFT_COMPILER_IS_VECTORC)
            mov eax, -1
            lock xadd dword ptr [ecx], eax
#else /* ? compiler */
            /* This might be wrong */
            lock sub dword ptr [ecx], 1
#endif /* compiler */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE void atomic_decrement32(atomic_int32_t volatile* pv)
{
    atomic_decrement(pv);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_exchange(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Just exchange *pl and n */
        lock xchg dword ptr [ecx], edx

        /* The previous value goes into edx, so me move it into eax for return */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        xchg dword ptr [ecx], eax

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}
STLSOFT_INLINE atomic_int32_t atomic_exchange32(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return atomic_exchange(pv, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_read(atomic_int_t volatile const* /* pl */)
{
    using namespace ximpl;

    if (s_up)
    {
        _asm
        {
            mov eax, 0
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */

#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */
            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            /* pop 0 into eax, which can then be atomically added into *pl (held
             * in ecx), leaving the value unchanged.
             */
            xadd dword ptr [ecx], eax

            /* Since it's an xadd it exchanges the previous value into eax, which
             * is exactly what's required
             */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
    else
    {
        _asm
        {
            mov eax, 0
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl */

#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack */
            mov ecx, dword ptr [esp + 4]
#else
# error Need to define calling convention
#endif /* call-conv */

            /* pop 0 into eax, which can then be atomically added into *pl (held
             * in ecx), leaving the value unchanged.
             */
            lock xadd dword ptr [ecx], eax

            /* Since it's an xadd it exchanges the previous value into eax, which
             * is exactly what's required
             */

#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            ret 4
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE atomic_int32_t atomic_read32(atomic_int32_t volatile* pv)
{
    return atomic_read(pv);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_write(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    _asm
    {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
        /* __fastcall: ecx is pl, edx is n */

        /* Just exchange *pl and n */
        lock xchg dword ptr [ecx], edx

        /* The previous value goes into edx, so me move it into eax for return */
        mov eax, edx

        ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
        /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */
        mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
        mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

        xchg dword ptr [ecx], eax

        ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
    }
}
STLSOFT_INLINE atomic_int32_t atomic_write32(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return atomic_write(pv, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postadd(atomic_int_t volatile* /* pl */, atomic_int_t /* n */)
{
    using namespace ximpl;

    /* Thanks to Eugene Gershnik for the fast-call implementation */
    if (s_up)
    {
        __asm
        {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl, edx is n */

            /* Simply atomically add them, which will leave the previous value
             * in edx
             */
            xadd dword ptr [ecx], edx

            /* Just need to move adx into eax to return it */
            mov eax, edx

            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */

            /* Simply atomically add them, which will leave the previous value
             * in edx
             */
            mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
            mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

            xadd dword ptr [ecx], eax

            /* Just need to move adx into eax to return it */

            ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
        }
    }
    else
    {
        __asm
        {
#if defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_FASTCALL)
            /* __fastcall: ecx is pl, edx is n */

            /* Simply atomically add them, which will leave the previous value
             * in edx
             */
            lock xadd dword ptr [ecx], edx

            /* Just need to move adx into eax to return it */
            mov eax, edx

            ret
#elif defined(WINSTL_ATOMIC_FNS_CALLCONV_IS_STDCALL)
            /* __stdcall: arguments are on the stack: pl in esp+4, pl in esp+8 */

            /* Simply atomically add them, which will leave the previous value
             * in edx
             */
            mov ecx, dword ptr [esp + 4]    /* Load the address of pl into ecx */
            mov eax, dword ptr [esp + 8]    /* Load the value into eax, so the return value will be there waiting */

            lock xadd dword ptr [ecx], eax

            /* Just need to move adx into eax to return it */

            ret 8
#else
# error Need to define calling convention
#endif /* call-conv */
        }
    }
}
STLSOFT_INLINE atomic_int32_t atomic_postadd32(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return atomic_postadd(pv, n);
}

#ifdef STLSOFT_COMPILER_IS_BORLAND
# pragma warn .8070     /* Suppresses: "Function should return a value" */
# pragma warn .8002     /* Suppresses: "Restarting compile using assembly" */
#endif /* compiler */

#  else /* STSLSOFT_INLINE_ASM_SUPPORTED */

/* Non-assembler versions
 *
 * These use the Win32 Interlocked functions. These are not guaranteed to give
 * precise answers on Windows 95.
 */


/* Multi-processor detection variants */
/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int32_t atomic_preincrement32(atomic_int32_t volatile* pv)
{
    return WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrement(winstl_C_internal_synch_atomic_ptrconv32_(pv));
}

WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_preincrement(atomic_int_t volatile* pl)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return atomic_preincrement32(pl);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedIncrement64)(winstl_C_internal_synch_atomic_ptrconv64_(pl));
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int32_t atomic_predecrement32(atomic_int32_t volatile* pv)
{
    return WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrement(winstl_C_internal_synch_atomic_ptrconv32_(pv));
}

WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_predecrement(atomic_int_t volatile* pl)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return atomic_predecrement32(pl);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedDecrement64)(winstl_C_internal_synch_atomic_ptrconv64_(pl));
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int32_t atomic_postincrement32(atomic_int32_t volatile* pv)
{
    return WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrement(winstl_C_internal_synch_atomic_ptrconv32_(pv)) - 1;
}

WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postincrement(atomic_int_t volatile* pl)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return atomic_postincrement32(pl);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedIncrement64)(winstl_C_internal_synch_atomic_ptrconv64_(pl)) - 1;
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int32_t atomic_postdecrement32(atomic_int32_t volatile* pv)
{
    return WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrement(winstl_C_internal_synch_atomic_ptrconv32_(pv)) + 1;
}

WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postdecrement(atomic_int_t volatile* pl)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return atomic_postdecrement32(pl);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedDecrement64)(winstl_C_internal_synch_atomic_ptrconv64_(pl)) + 1;
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE void atomic_increment32(atomic_int32_t volatile* pv)
{
    WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrement(winstl_C_internal_synch_atomic_ptrconv32_(pv));
}

WINSTL_ATOMIC_FNS_IMPL_(void) atomic_increment(atomic_int_t volatile* pl)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    atomic_increment32(pl);
#elif defined(WINSTL_OS_IS_WIN64)

    STLSOFT_NS_GLOBAL(InterlockedIncrement64)(winstl_C_internal_synch_atomic_ptrconv64_(pl));
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE void atomic_decrement32(atomic_int32_t volatile* pv)
{
    WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrement(winstl_C_internal_synch_atomic_ptrconv32_(pv));
}

WINSTL_ATOMIC_FNS_IMPL_(void) atomic_decrement(atomic_int_t volatile* pl)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    atomic_decrement32(pl);
#elif defined(WINSTL_OS_IS_WIN64)

    STLSOFT_NS_GLOBAL(InterlockedDecrement64)(winstl_C_internal_synch_atomic_ptrconv64_(pl));
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int32_t atomic_exchange32(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return WINSTL_API_EXTERNAL_Synchronization_InterlockedExchange(winstl_C_internal_synch_atomic_ptrconv32_(pv), n);
}

WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_exchange(atomic_int_t volatile* pl, atomic_int_t n)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return atomic_exchange32(pl, n);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedExchange64)(winstl_C_internal_synch_atomic_ptrconv64_(pl), n);
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int32_t atomic_write32(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return WINSTL_API_EXTERNAL_Synchronization_InterlockedExchange(winstl_C_internal_synch_atomic_ptrconv32_(pv), n);
}

WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_write(atomic_int_t volatile* pl, atomic_int_t n)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return atomic_write32(pl, n);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedExchange64)(winstl_C_internal_synch_atomic_ptrconv64_(pl), n);
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_read(atomic_int_t volatile const* pl)
{
    return *pl;
}

WINSTL_ATOMIC_FNS_IMPL_(atomic_int32_t) atomic_read32(atomic_int32_t volatile const* pl)
{
    return *pl;
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int32_t atomic_postadd32(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangeAdd(winstl_C_internal_synch_atomic_ptrconv32_(pv), n);
}
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postadd(atomic_int_t volatile* pl, atomic_int_t n)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return atomic_postadd32(pl, n);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedExchangeAdd64)(winstl_C_internal_synch_atomic_ptrconv64_(pl), n);
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}


/* Uni-processor variants */

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_preincrement_up(atomic_int_t volatile* pl)
{
    return atomic_preincrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_predecrement_up(atomic_int_t volatile* pl)
{
    return atomic_predecrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postincrement_up(atomic_int_t volatile* pl)
{
    return atomic_postincrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postdecrement_up(atomic_int_t volatile* pl)
{
    return atomic_postdecrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(void) atomic_increment_up(atomic_int_t volatile* pl)
{
    atomic_increment(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(void) atomic_decrement_up(atomic_int_t volatile* pl)
{
    atomic_decrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_exchange_up(atomic_int_t volatile* pl, atomic_int_t n)
{
    return atomic_exchange(pl, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_write_up(atomic_int_t volatile* pl, atomic_int_t n)
{
    return atomic_write(pl, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_read_up(atomic_int_t volatile const* pl)
{
    return *pl;
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postadd_up(atomic_int_t volatile* pl, atomic_int_t n)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangeAdd(winstl_C_internal_synch_atomic_ptrconv32_(pl), n);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedExchangeAdd64)(winstl_C_internal_synch_atomic_ptrconv64_(pl), n);
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

/* SMP variants */

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_preincrement_smp(atomic_int_t volatile* pl)
{
    return atomic_preincrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_predecrement_smp(atomic_int_t volatile* pl)
{
    return atomic_predecrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postincrement_smp(atomic_int_t volatile* pl)
{
    return atomic_postincrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postdecrement_smp(atomic_int_t volatile* pl)
{
    return atomic_postdecrement(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_exchange_smp(atomic_int_t volatile* pl, atomic_int_t n)
{
    return atomic_exchange(pl, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_write_smp(atomic_int_t volatile* pl, atomic_int_t n)
{
    return atomic_write(pl, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_read_smp(atomic_int_t volatile const* pl)
{
    return *pl;
}

/**
 *
 * \ingroup group__library__Synch
 */
WINSTL_ATOMIC_FNS_IMPL_(atomic_int_t) atomic_postadd_smp(atomic_int_t volatile* pl, atomic_int_t n)
{
#if 0
#elif defined(WINSTL_OS_IS_WIN32)

    return WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangeAdd(winstl_C_internal_synch_atomic_ptrconv32_(pl), n);
#elif defined(WINSTL_OS_IS_WIN64)

    return STLSOFT_NS_GLOBAL(InterlockedExchangeAdd64)(winstl_C_internal_synch_atomic_ptrconv64_(pl), n);
#else /* ? arch */

# error Not valid for processors other than Intel
#endif /* Win32 || Win64 */
}

#  endif /* STSLSOFT_INLINE_ASM_SUPPORTED */

# endif /* !WINSTL_ATOMIC_FNS_DECLARATION_ONLY */

/* /////////////////////////////////////////////////////////////////////////
 * other inline atomic function
 */

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int_t atomic_preadd_up(atomic_int_t volatile* pl, atomic_int_t n)
{
    return n + atomic_postadd_up(pl, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE void atomic_increment_smp(atomic_int_t volatile* pl)
{
    atomic_postincrement_smp(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE void atomic_decrement_smp(atomic_int_t volatile* pl)
{
    atomic_postdecrement_smp(pl);
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int_t atomic_preadd_smp(atomic_int_t volatile* pl, atomic_int_t n)
{
    return n + atomic_postadd_smp(pl, n);
}

/**
 *
 * \ingroup group__library__Synch
 */
STLSOFT_INLINE atomic_int_t atomic_preadd(atomic_int_t volatile* pl, atomic_int_t n)
{
    return n + atomic_postadd(pl, n);
}

STLSOFT_INLINE atomic_int32_t atomic_preadd32(atomic_int32_t volatile* pl, atomic_int32_t n)
{
    return n + atomic_postadd32(pl, n);
}

# ifdef __cplusplus
#  if 0
#  elif defined(WINSTL_OS_IS_WIN64)

inline atomic_int_t atomic_postdecrement(atomic_int32_t volatile* pv)
{
    return atomic_postdecrement32(pv);
}

inline atomic_int32_t atomic_postincrement(atomic_int32_t volatile* pv)
{
    return atomic_postincrement32(pv);
}

inline atomic_int32_t atomic_predecrement(atomic_int32_t volatile* pv)
{
    return atomic_predecrement32(pv);
}

inline atomic_int32_t atomic_preincrement(atomic_int32_t volatile* pv)
{
    return atomic_preincrement32(pv);
}

inline void atomic_increment(atomic_int32_t volatile* pv)
{
    atomic_increment32(pv);
}
inline void atomic_decrement(atomic_int32_t volatile* pv)
{
    atomic_decrement32(pv);
}

inline atomic_int32_t atomic_exchange(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return atomic_exchange32(pv, n);
}

inline atomic_int32_t atomic_read(atomic_int32_t volatile* pv)
{
    return atomic_read32(pv);
}

inline atomic_int32_t atomic_write(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return atomic_write32(pv, n);
}

inline atomic_int32_t atomic_postadd(atomic_int32_t volatile* pv, atomic_int32_t n)
{
    return atomic_postadd32(pv, n);
}

#  endif
# endif /* __cplusplus */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_ATOMIC_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

