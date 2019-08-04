/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/external/Synchronization.h
 *
 * Purpose:     External preprocessor aliases for external Windows' Synchronization
 *              API.
 *
 * Created:     22nd October 2016
 * Updated:     11th December 2017
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2016-2017, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Synchronization
#define WINSTL_INCL_WINSTL_API_external_h_Synchronization

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

/* /////////////////////////////////////////////////////////////////////////
 * synchronization functions
 */


/* *************************************
 * Asynchronous functions
 */


/* *************************************
 * Condition Variable and SRW Lock functions
 */


#if WINSTL_WIN32_WINNT >= 0x0600

#ifndef WINSTL_API_EXTERNAL_Synchronization_AcquireSRWLockExclusive
# define WINSTL_API_EXTERNAL_Synchronization_AcquireSRWLockExclusive                                STLSOFT_NS_GLOBAL(AcquireSRWLockExclusive)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_AcquireSRWLockExclusive */

#ifndef WINSTL_API_EXTERNAL_Synchronization_AcquireSRWLockShared
# define WINSTL_API_EXTERNAL_Synchronization_AcquireSRWLockShared                                   STLSOFT_NS_GLOBAL(AcquireSRWLockShared)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_AcquireSRWLockShared */

#ifndef WINSTL_API_EXTERNAL_Synchronization_InitializeSRWLock
# define WINSTL_API_EXTERNAL_Synchronization_InitializeSRWLock                                      STLSOFT_NS_GLOBAL(InitializeSRWLock)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InitializeSRWLock */

#ifndef WINSTL_API_EXTERNAL_Synchronization_ReleaseSRWLockExclusive
# define WINSTL_API_EXTERNAL_Synchronization_ReleaseSRWLockExclusive                                STLSOFT_NS_GLOBAL(ReleaseSRWLockExclusive)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_ReleaseSRWLockExclusive */

#ifndef WINSTL_API_EXTERNAL_Synchronization_ReleaseSRWLockShared
# define WINSTL_API_EXTERNAL_Synchronization_ReleaseSRWLockShared                                   STLSOFT_NS_GLOBAL(ReleaseSRWLockShared)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_ReleaseSRWLockShared */

#ifndef WINSTL_API_EXTERNAL_Synchronization_TryAcquireSRWLockExclusive
# define WINSTL_API_EXTERNAL_Synchronization_TryAcquireSRWLockExclusive                             STLSOFT_NS_GLOBAL(TryAcquireSRWLockExclusive)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_TryAcquireSRWLockExclusive */

#ifndef WINSTL_API_EXTERNAL_Synchronization_TryAcquireSRWLockShared
# define WINSTL_API_EXTERNAL_Synchronization_TryAcquireSRWLockShared                                STLSOFT_NS_GLOBAL(TryAcquireSRWLockShared)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_TryAcquireSRWLockShared */



#ifndef WINSTL_API_EXTERNAL_Synchronization_InitializeConditionVariable
# define WINSTL_API_EXTERNAL_Synchronization_InitializeConditionVariable                            STLSOFT_NS_GLOBAL(InitializeConditionVariable)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InitializeConditionVariable */

#ifndef WINSTL_API_EXTERNAL_Synchronization_WakeConditionVariable
# define WINSTL_API_EXTERNAL_Synchronization_WakeConditionVariable                                  STLSOFT_NS_GLOBAL(WakeConditionVariable)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_WakeConditionVariable */

#ifndef WINSTL_API_EXTERNAL_Synchronization_WakeAllConditionVariable
# define WINSTL_API_EXTERNAL_Synchronization_WakeAllConditionVariable                               STLSOFT_NS_GLOBAL(WakeAllConditionVariable)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_WakeAllConditionVariable */

#ifndef WINSTL_API_EXTERNAL_Synchronization_SleepConditionVariableCS
# define WINSTL_API_EXTERNAL_Synchronization_SleepConditionVariableCS                               STLSOFT_NS_GLOBAL(SleepConditionVariableCS)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_SleepConditionVariableCS */

#ifndef WINSTL_API_EXTERNAL_Synchronization_SleepConditionVariableSRW
# define WINSTL_API_EXTERNAL_Synchronization_SleepConditionVariableSRW                              STLSOFT_NS_GLOBAL(SleepConditionVariableSRW)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_SleepConditionVariableSRW */

#endif

/* *************************************
 * Critical Section functions
 */

#ifndef WINSTL_API_EXTERNAL_Synchronization_DeleteCriticalSection
# define WINSTL_API_EXTERNAL_Synchronization_DeleteCriticalSection                                  STLSOFT_NS_GLOBAL(DeleteCriticalSection)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_DeleteCriticalSection */

#ifndef WINSTL_API_EXTERNAL_Synchronization_EnterCriticalSection
# define WINSTL_API_EXTERNAL_Synchronization_EnterCriticalSection                                   STLSOFT_NS_GLOBAL(EnterCriticalSection)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_EnterCriticalSection */

#ifndef WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSection
# define WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSection                              STLSOFT_NS_GLOBAL(InitializeCriticalSection)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSection */

#if WINSTL_WIN32_WINNT >= 0x0403
# ifndef WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSectionAndSpinCount
#  define WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSectionAndSpinCount                 STLSOFT_NS_GLOBAL(InitializeCriticalSectionAndSpinCount)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSectionAndSpinCount */
#endif

#if WINSTL_WIN32_WINNT >= 0x0403
# ifndef WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSectionEx
#  define WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSectionEx                           STLSOFT_NS_GLOBAL(InitializeCriticalSectionEx)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InitializeCriticalSectionEx */
#endif

#ifndef WINSTL_API_EXTERNAL_Synchronization_LeaveCriticalSection
# define WINSTL_API_EXTERNAL_Synchronization_LeaveCriticalSection                                   STLSOFT_NS_GLOBAL(LeaveCriticalSection)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_LeaveCriticalSection */

#if WINSTL_WIN32_WINNT >= 0x0403
# ifndef WINSTL_API_EXTERNAL_Synchronization_SetCriticalSectionSpinCount
#  define WINSTL_API_EXTERNAL_Synchronization_SetCriticalSectionSpinCount                           STLSOFT_NS_GLOBAL(SetCriticalSectionSpinCount)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_SetCriticalSectionSpinCount */
#endif

#if WINSTL_WIN32_WINNT >= 0x0400
# ifndef WINSTL_API_EXTERNAL_Synchronization_TryEnterCriticalSection
#  define WINSTL_API_EXTERNAL_Synchronization_TryEnterCriticalSection                               STLSOFT_NS_GLOBAL(TryEnterCriticalSection)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_TryEnterCriticalSection */
#endif


/* *************************************
 * Event functions
 */

#ifndef WINSTL_API_EXTERNAL_Synchronisation_CreateEventA
# define WINSTL_API_EXTERNAL_Synchronisation_CreateEventA                                           STLSOFT_NS_GLOBAL(CreateEventA)
#endif /* !WINSTL_API_EXTERNAL_Synchronisation_CreateEventA */
#ifndef WINSTL_API_EXTERNAL_Synchronisation_CreateEventW
# define WINSTL_API_EXTERNAL_Synchronisation_CreateEventW                                           STLSOFT_NS_GLOBAL(CreateEventW)
#endif /* !WINSTL_API_EXTERNAL_Synchronisation_CreateEventW */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Synchronisation_CreateEventExA
#  define WINSTL_API_EXTERNAL_Synchronisation_CreateEventExA                                        STLSOFT_NS_GLOBAL(CreateEventExA)
# endif /* !WINSTL_API_EXTERNAL_Synchronisation_CreateEventExA */
# ifndef WINSTL_API_EXTERNAL_Synchronisation_CreateEventExW
#  define WINSTL_API_EXTERNAL_Synchronisation_CreateEventExW                                        STLSOFT_NS_GLOBAL(CreateEventExW)
# endif /* !WINSTL_API_EXTERNAL_Synchronisation_CreateEventExW */
#endif

#ifndef WINSTL_API_EXTERNAL_Synchronisation_OpenEventA
# define WINSTL_API_EXTERNAL_Synchronisation_OpenEventA                                             STLSOFT_NS_GLOBAL(OpenEventA)
#endif /* !WINSTL_API_EXTERNAL_Synchronisation_OpenEventA */
#ifndef WINSTL_API_EXTERNAL_Synchronisation_OpenEventW
# define WINSTL_API_EXTERNAL_Synchronisation_OpenEventW                                             STLSOFT_NS_GLOBAL(OpenEventW)
#endif /* !WINSTL_API_EXTERNAL_Synchronisation_OpenEventW */

#ifndef WINSTL_API_EXTERNAL_Synchronisation_PulseEvent
# define WINSTL_API_EXTERNAL_Synchronisation_PulseEvent                                             STLSOFT_NS_GLOBAL(PulseEvent)
#endif /* !WINSTL_API_EXTERNAL_Synchronisation_PulseEvent */

#ifndef WINSTL_API_EXTERNAL_Synchronisation_ResetEvent
# define WINSTL_API_EXTERNAL_Synchronisation_ResetEvent                                             STLSOFT_NS_GLOBAL(ResetEvent)
#endif /* !WINSTL_API_EXTERNAL_Synchronisation_ResetEvent */

#ifndef WINSTL_API_EXTERNAL_Synchronisation_SetEvent
# define WINSTL_API_EXTERNAL_Synchronisation_SetEvent                                               STLSOFT_NS_GLOBAL(SetEvent)
#endif /* !WINSTL_API_EXTERNAL_Synchronisation_SetEvent */


/* *************************************
 * One-time Initialization functions
 */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Synchronisation_InitOnceInitialize
#  define WINSTL_API_EXTERNAL_Synchronisation_InitOnceInitialize                                    STLSOFT_NS_GLOBAL(InitOnceInitialize)
# endif /* !WINSTL_API_EXTERNAL_Synchronisation_InitOnceInitialize */

# ifndef WINSTL_API_EXTERNAL_Synchronisation_InitOnceExecuteOnce
#  define WINSTL_API_EXTERNAL_Synchronisation_InitOnceExecuteOnce                                   STLSOFT_NS_GLOBAL(InitOnceExecuteOnce)
# endif /* !WINSTL_API_EXTERNAL_Synchronisation_InitOnceExecuteOnce */

# ifndef WINSTL_API_EXTERNAL_Synchronisation_InitOnceBeginInitialize
#  define WINSTL_API_EXTERNAL_Synchronisation_InitOnceBeginInitialize                               STLSOFT_NS_GLOBAL(InitOnceBeginInitialize)
# endif /* !WINSTL_API_EXTERNAL_Synchronisation_InitOnceBeginInitialize */

# ifndef WINSTL_API_EXTERNAL_Synchronisation_InitOnceComplete
#  define WINSTL_API_EXTERNAL_Synchronisation_InitOnceComplete                                      STLSOFT_NS_GLOBAL(InitOnceComplete)
# endif /* !WINSTL_API_EXTERNAL_Synchronisation_InitOnceComplete */
#endif


/* *************************************
 * Interlocked functions
 */

#ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchange
# define WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchange                             STLSOFT_NS_GLOBAL(InterlockedCompareExchange)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchange */

#if 0
# ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangeAcquire
#  define WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangeAcquire                     STLSOFT_NS_GLOBAL(InterlockedCompareExchangeAcquire)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangeAcquire */
#endif

#if 0
# ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangePointer
#  define WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangePointer                     STLSOFT_NS_GLOBAL(InterlockedCompareExchangePointer)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangePointer */
#endif

#ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangeRelease
# define WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangeRelease                      STLSOFT_NS_GLOBAL(InterlockedCompareExchangeRelease)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedCompareExchangeRelease */

#ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrement
# define WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrement                                   STLSOFT_NS_GLOBAL(InterlockedDecrement)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrement */

#if 0
# ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrementAcquire
#  define WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrementAcquire                           STLSOFT_NS_GLOBAL(InterlockedDecrementAcquire)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrementAcquire */
#endif

#if 0
# ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrementRelease
#  define WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrementRelease                           STLSOFT_NS_GLOBAL(InterlockedDecrementRelease)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedDecrementRelease */
#endif

#ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedExchange
# define WINSTL_API_EXTERNAL_Synchronization_InterlockedExchange                                    STLSOFT_NS_GLOBAL(InterlockedExchange)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedExchange */

#ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangeAdd
# define WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangeAdd                                 STLSOFT_NS_GLOBAL(InterlockedExchangeAdd)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangeAdd */

#if 0
# ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangePointer
#  define WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangePointer                            STLSOFT_NS_GLOBAL(InterlockedExchangePointer)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedExchangePointer */
#endif

#ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrement
# define WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrement                                   STLSOFT_NS_GLOBAL(InterlockedIncrement)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrement */

#if 0
# ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrementAcquire
#  define WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrementAcquire                           STLSOFT_NS_GLOBAL(InterlockedIncrementAcquire)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrementAcquire */
#endif

#if 0
# ifndef WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrementRelease
#  define WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrementRelease                           STLSOFT_NS_GLOBAL(InterlockedIncrementRelease)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_InterlockedIncrementRelease */
#endif


/* *************************************
 * Mutex functions
 */

#ifndef WINSTL_API_EXTERNAL_Synchronization_CreateMutexA
# define WINSTL_API_EXTERNAL_Synchronization_CreateMutexA                                           STLSOFT_NS_GLOBAL(CreateMutexA)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_CreateMutexA */
#ifndef WINSTL_API_EXTERNAL_Synchronization_CreateMutexW
# define WINSTL_API_EXTERNAL_Synchronization_CreateMutexW                                           STLSOFT_NS_GLOBAL(CreateMutexW)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_CreateMutexW */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Synchronization_CreateMutexExA
#  define WINSTL_API_EXTERNAL_Synchronization_CreateMutexExA                                        STLSOFT_NS_GLOBAL(CreateMutexExA)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_CreateMutexExA */
# ifndef WINSTL_API_EXTERNAL_Synchronization_CreateMutexExW
#  define WINSTL_API_EXTERNAL_Synchronization_CreateMutexExW                                        STLSOFT_NS_GLOBAL(CreateMutexExW)
# endif /* !WINSTL_API_EXTERNAL_Synchronization_CreateMutexExW */
#endif

#ifndef WINSTL_API_EXTERNAL_Synchronization_OpenMutexA
# define WINSTL_API_EXTERNAL_Synchronization_OpenMutexA                                             STLSOFT_NS_GLOBAL(OpenMutexA)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_OpenMutexA */
#ifndef WINSTL_API_EXTERNAL_Synchronization_OpenMutexW
# define WINSTL_API_EXTERNAL_Synchronization_OpenMutexW                                             STLSOFT_NS_GLOBAL(OpenMutexW)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_OpenMutexW */

#ifndef WINSTL_API_EXTERNAL_Synchronization_ReleaseMutex
# define WINSTL_API_EXTERNAL_Synchronization_ReleaseMutex                                           STLSOFT_NS_GLOBAL(ReleaseMutex)
#endif /* !WINSTL_API_EXTERNAL_Synchronization_ReleaseMutex */


/* *************************************
 * Private Namespace functions
 */


/* *************************************
 * Semaphore functions
 */


/* *************************************
 * Singly-linked List functions
 */


/* *************************************
 * Synchronization Barrier functions
 */


/* *************************************
 * Timer-queue Timer functions
 */


/* *************************************
 * Wait functions
 */


/* *************************************
 * Waitable Timer functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_external_h_Synchronization */

/* ///////////////////////////// end of file //////////////////////////// */
