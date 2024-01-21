/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/process/functions.h
 *
 * Purpose:     Process functions.
 *
 * Created:     12th March 2006
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/process/functions.h
 *
 * \brief [C, C++] Process control functions
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_PROCESS_H_FUNCTIONS
#define WINSTL_INCL_WINSTL_PROCESS_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_PROCESS_H_FUNCTIONS_MAJOR    1
# define WINSTL_VER_WINSTL_PROCESS_H_FUNCTIONS_MINOR    1
# define WINSTL_VER_WINSTL_PROCESS_H_FUNCTIONS_REVISION 6
# define WINSTL_VER_WINSTL_PROCESS_H_FUNCTIONS_EDIT     32
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

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
# include <winstl/api/external/HandleAndObject.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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
 * C functions
 */

/** Simplified interface to <code>CreateProcess()</code>
 *
 * \ingroup group__library__System
 *
 * \param cmdLine the command-line to use
 * \param processAttributes security information to apply to the process; may be NULL
 * \param threadAttributes security information to apply to the thread; may be NULL
 * \param inheritsHandles determines whether the child process inherits the process handles
 * \param creationFlags XXXX
 * \param environment pointer to an environment block; may be NULL
 * \param currentDirectory a directory to use as a current directory; may be NULL
 * \param si Pointer to an instance of <code>STARTUPINFO</code>. May be NULL, in which case defaults are used
 * \param pi Pointer to an instance of <code>PROCESS_INFORMATION</code>, which will receive the handles and identifiers of the created process and thread. May be NULL, in which case the handles are closed
 */
STLSOFT_INLINE BOOL winstl_C_CreateProcess9_a(
    ws_char_a_t const*      cmdLine
,   LPSECURITY_ATTRIBUTES   processAttributes
,   LPSECURITY_ATTRIBUTES   threadAttributes
,   BOOL                    inheritsHandles
,   DWORD                   creationFlags
,   ws_char_a_t const*      environment
,   ws_char_a_t const*      currentDirectory
,   LPSTARTUPINFO           si
,   LPPROCESS_INFORMATION   pi
)
{
    STARTUPINFO         si_;
    PROCESS_INFORMATION pi_;
    BOOL                b;

    if (NULL == si)
    {
        STLSOFT_API_INTERNAL_memfns_memset(&si_, 0, sizeof(si_));
        si = &si_;
    }
    if (NULL == pi)
    {
        pi = &pi_;
    }

    b = STLSOFT_NS_GLOBAL(CreateProcessA)(NULL, stlsoft_const_cast(ws_char_a_t*, cmdLine), processAttributes, threadAttributes, inheritsHandles, creationFlags, stlsoft_const_cast(ws_char_a_t*, environment), currentDirectory, si, pi);

    if (b)
    {
        if (pi == &pi_)
        {
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(pi->hProcess);
            WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(pi->hThread);
        }
    }

    return b;
}

/**
 *
 * \ingroup group__library__System
 */
STLSOFT_INLINE BOOL winstl_C_CreateProcessFEA_a(ws_char_a_t const* cmdLine, DWORD flags, ws_char_a_t const* envBlock)
{
    STARTUPINFO         si;
    PROCESS_INFORMATION pi;
    BOOL                b;

    STLSOFT_API_INTERNAL_memfns_memset(&si, 0, sizeof(si));

    b = STLSOFT_NS_GLOBAL(CreateProcessA)(NULL, stlsoft_const_cast(ws_char_a_t*, cmdLine), NULL, NULL, FALSE, flags, stlsoft_const_cast(ws_char_a_t*, envBlock), NULL, &si, &pi);

    if (b)
    {
        WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(pi.hProcess);
        WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(pi.hThread);
    }

    return b;
}

/**
 *
 * \ingroup group__library__System
 */
STLSOFT_INLINE BOOL winstl_C_CreateProcessEA(ws_char_a_t const* cmdLine, ws_char_a_t const* envBlock)
{
    return winstl_C_CreateProcessFEA_a(cmdLine, 0, envBlock);
}

/**
 *
 * \ingroup group__library__System
 */
STLSOFT_INLINE BOOL winstl_C_CreateProcess0A(ws_char_a_t const* cmdLine)
{
    return winstl_C_CreateProcessEA(cmdLine, NULL);
}

/* /////////////////////////////////////////////////////////////////////////
 * obsolete functions
 */

#define winstl__CreateProcessFEA                            winstl_C_CreateProcessFEA_a
#define winstl__CreateProcessEA                             winstl_C_CreateProcessEA
#define winstl__CreateProcess0A                             winstl_C_CreateProcess0A

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** Simplified interface to <code>CreateProcess()</code>
 *
 * \ingroup group__library__System
 *
 * \param cmdLine the command-line to use
 * \param processAttributes security information to apply to the process; may be NULL
 * \param threadAttributes security information to apply to the thread; may be NULL
 * \param inheritsHandles determines whether the child process inherits the process handles
 * \param creationFlags XXXX
 * \param environment pointer to an environment block; may be NULL
 * \param currentDirectory a directory to use as a current directory; may be NULL
 * \param si Pointer to an instance of <code>STARTUPINFO</code>. May be NULL, in which case defaults are used
 * \param pi Pointer to an instance of <code>PROCESS_INFORMATION</code>, which will receive the handles and identifiers of the created process and thread. May be NULL, in which case the handles are closed
 */
inline BOOL create_process(
    ws_char_a_t const*      cmdLine
,   LPSECURITY_ATTRIBUTES   processAttributes
,   LPSECURITY_ATTRIBUTES   threadAttributes
,   BOOL                    inheritsHandles
,   DWORD                   creationFlags
,   ws_char_a_t const*      environment
,   ws_char_a_t const*      currentDirectory
,   LPSTARTUPINFO           si
,   LPPROCESS_INFORMATION   pi
)
{
    return winstl_C_CreateProcess9_a(cmdLine, processAttributes, threadAttributes, inheritsHandles, creationFlags, environment, currentDirectory, si, pi);
}

/** Creates a process, with flags and environment
 *
 * \ingroup group__library__System
 *
 * \deprecated This is deprecated in favour of winstl::create_process()
 */
inline BOOL create_process(ws_char_a_t const* cmdLine, DWORD flags, ws_char_a_t const* envBlock)
{
    return winstl_C_CreateProcessFEA_a(cmdLine, flags, envBlock);
}

/** Creates a process, with environment
 *
 * \ingroup group__library__System
 *
 * \deprecated This is deprecated in favour of winstl::create_process()
 */
inline BOOL create_process(ws_char_a_t const* cmdLine, ws_char_a_t const* envBlock)
{
    return winstl_C_CreateProcessEA(cmdLine, envBlock);
}

/** Creates a process
 *
 * \ingroup group__library__System
 *
 * \deprecated This is deprecated in favour of winstl::create_process()
 */
inline BOOL create_process(ws_char_a_t const* cmdLine)
{
    return winstl_C_CreateProcess0A(cmdLine);
}




/** [DEPRECATED] Creates a process, with flags and environment
 *
 * \ingroup group__library__System
 *
 * \deprecated This is deprecated in favour of winstl::create_process()
 */
inline BOOL CreateProcess(ws_char_a_t const* cmdLine, DWORD flags, ws_char_a_t const* envBlock)
{
    return winstl_C_CreateProcessFEA_a(cmdLine, flags, envBlock);
}

/** [DEPRECATED] Creates a process, with environment
 *
 * \ingroup group__library__System
 *
 * \deprecated This is deprecated in favour of winstl::create_process()
 */
inline BOOL CreateProcess(ws_char_a_t const* cmdLine, ws_char_a_t const* envBlock)
{
    return winstl_C_CreateProcessEA(cmdLine, envBlock);
}

/** [DEPRECATED] Creates a process
 *
 * \ingroup group__library__System
 *
 * \deprecated This is deprecated in favour of winstl::create_process()
 */
inline BOOL CreateProcess(ws_char_a_t const* cmdLine)
{
    return winstl_C_CreateProcess0A(cmdLine);
}

#endif /* __cplusplus */

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

#endif /* !WINSTL_INCL_WINSTL_PROCESS_H_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

