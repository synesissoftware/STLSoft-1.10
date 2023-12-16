/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/diagnostics/LibraryIdentifier.h
 *
 * Purpose:     Definition of the LibraryIdentifier enumeration.
 *
 * Created:     12th May 2012
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2012-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/diagnostics/LibraryIdentifier.h
 *
 * \brief [C, C++] Definition of the LibraryIdentifier enumeration
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_DIAGNOSTICS_H_LIBRARYIDENTIFIER
#define STLSOFT_INCL_STLSOFT_DIAGNOSTICS_H_LIBRARYIDENTIFIER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_H_LIBRARYIDENTIFIER_MAJOR      1
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_H_LIBRARYIDENTIFIER_MINOR      0
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_H_LIBRARYIDENTIFIER_REVISION   2
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_H_LIBRARYIDENTIFIER_EDIT       6
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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Enumeration defining STLSoft libraries
 *
 * \ingroup group__library__Diagnostic
 */
enum STLSoftLibraryIdentifier_t
{
        STLSoftLibraryIdentifier_Invalid        =   -1
    ,   STLSoftLibraryIdentifier_Unspecified    =   0

    ,   STLSoftLibraryIdentifier_FileSystem
    ,   STLSoftLibraryIdentifier_String
    ,   STLSoftLibraryIdentifier_Utility
    ,   STLSoftLibraryIdentifier_Synch
    ,   STLSoftLibraryIdentifier_Conversion
    ,   STLSoftLibraryIdentifier_Metaprogramming
    ,   STLSoftLibraryIdentifier_Functional
    ,   STLSoftLibraryIdentifier_System
    ,   STLSoftLibraryIdentifier_DL
    ,   STLSoftLibraryIdentifier_Collection
    ,   STLSoftLibraryIdentifier_Memory
    ,   STLSoftLibraryIdentifier_Exception
    ,   STLSoftLibraryIdentifier_Algorithm
    ,   STLSoftLibraryIdentifier_Iterator
    ,   STLSoftLibraryIdentifier_Range
    ,   STLSoftLibraryIdentifier_Time
    ,   STLSoftLibraryIdentifier_Diagnostic
    ,   STLSoftLibraryIdentifier_SmartPointer
    ,   STLSoftLibraryIdentifier_Properties
    ,   STLSoftLibraryIdentifier_Container
    ,   STLSoftLibraryIdentifier_ContractEnforcement
    ,   STLSoftLibraryIdentifier_Network
    ,   STLSoftLibraryIdentifier_Security
    ,   STLSoftLibraryIdentifier_View
    ,   STLSoftLibraryIdentifier_Shims_Access_String
    ,   STLSoftLibraryIdentifier_Shims_Attribute_SynchHandle
    ,   STLSoftLibraryIdentifier_Shims_Attribute_FILE
    ,   STLSoftLibraryIdentifier_Shims_Attribute_IsEmpty
    ,   STLSoftLibraryIdentifier_Shims_Attribute_IsNull
    ,   STLSoftLibraryIdentifier_Metaprogramming_Ntypes
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
                ,   STLSoftLibraryIdentifier_error
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
    ,   STLSoftLibraryIdentifier_ACE_Reactor
    ,   STLSoftLibraryIdentifier_COM_Utility
    ,   STLSoftLibraryIdentifier_COM_Automation
    ,   STLSoftLibraryIdentifier_Windows_Window
    ,   STLSoftLibraryIdentifier_Windows_Shell
    ,   STLSoftLibraryIdentifier_Windows_Registry
    ,   STLSoftLibraryIdentifier_Windows_ControlPanel
    ,   STLSoftLibraryIdentifier_Windows_ToolHelp
    ,   STLSoftLibraryIdentifier_Windows_Control
    ,   STLSoftLibraryIdentifier_Windows_Clipboard
    ,   STLSoftLibraryIdentifier_Windows_Resource
    ,   STLSoftLibraryIdentifier_Shims_Attribute_Windows_Window
    ,   STLSoftLibraryIdentifier_Shims_Attribute_Windows_KernelHandle
    ,   STLSoftLibraryIdentifier_Shims_Attribute_Windows_HKEY

/* New values must be inserted AFTER this point */

#if 0
    ,   STLSoftLibraryIdentifier_
    ,   STLSoftLibraryIdentifier_
    ,   STLSoftLibraryIdentifier_
#endif /* 0 */

/* New values must be inserted BEFORE this point */

    ,   STLSoftLibraryIdentifier_COUNT
    ,   STLSoftLibraryIdentifier_MAXIMUM        =   STLSoftLibraryIdentifier_COUNT - 1
};

#if 0
#elif !defined(STLSOFT_NO_NAMESPACE)
typedef STLSoftLibraryIdentifier_t                          LibraryIdentifier_t;
#elif !defined(__cplusplus)
typedef enum STLSoftLibraryIdentifier_t                     STLSoftLibraryIdentifier_t;
#endif

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_DIAGNOSTICS_H_LIBRARYIDENTIFIER */

/* ///////////////////////////// end of file //////////////////////////// */

