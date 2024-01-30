/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/toolhelp/process_sequence.hpp
 *
 * Purpose:     TOOLHELP process sequence class.
 *
 * Created:     21st May 2005
 * Updated:     22nd January 2024
 *
 * Thanks:      To Pablo for contributing this great library.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2007, Pablo Aguilar
 * Copyright (c) 2006-2007, Matthew Wilson
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
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems,
 *   nor Pablo Aguilar,  nor the names of any contributors may be used to
 *   endorse or promote products derived from this software without
 *   specific prior written permission.
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


/** \file winstl/toolhelp/process_sequence.hpp
 *
 * \brief [C++] Definition of the
 *  \link winstl::process_sequence process_sequence\endlink class
 *   (\ref group__library__Windows_Toolhelp "Windows ToolHelp" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TOOLHELP_HPP_PROCESS_SEQUENCE
#define WINSTL_INCL_WINSTL_TOOLHELP_HPP_PROCESS_SEQUENCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_PROCESS_SEQUENCE_MAJOR      1
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_PROCESS_SEQUENCE_MINOR      1
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_PROCESS_SEQUENCE_REVISION   4
# define WINSTL_VER_WINSTL_TOOLHELP_HPP_PROCESS_SEQUENCE_EDIT       21
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

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */
#ifndef WINSTL_INCL_WINSTL_TOOLHELP_HPP_SEQUENCE_BASE
# include <winstl/toolhelp/sequence_base.hpp>
#endif /* !WINSTL_INCL_WINSTL_TOOLHELP_HPP_SEQUENCE_BASE */

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
 * classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION

class process_sequence
{
public: // types
    class                                                   const_iterator;
    typedef process_sequence                                class_type;

public: // construction
    explicit
    process_sequence(
        DWORD pid
    );

public: // iteration
    const_iterator  begin() const;
    const_iterator  end() const;
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

// th_sequence_value_traits specialization for process_sequence
////////////////////////////////////////////////////////////////////////////
# define WINSTL_TH_API_SEQUENCE_VALUE_TRAITS_VALUE          PROCESSENTRY32
# define WINSTL_TH_API_SEQUENCE_VALUE_TRAITS_FIRST          Process32First
# define WINSTL_TH_API_SEQUENCE_VALUE_TRAITS_NEXT           Process32Next
# define WINSTL_TH_API_SEQUENCE_VALUE_TRAITS_FLAG           TH32CS_SNAPPROCESS
# define WINSTL_TH_API_SEQUENCE_VALUE_TRAITS_CREATE_SNAPSHOT_FAIL_MESSAGE    ("Could not create process list snapshot")
# include <winstl/toolhelp/sequence_value_traits.hpp>

/** An STL collection for accessing process information.
 *
 * \ingroup group__library__Windows_Toolhelp
 */
typedef th_sequence_base<PROCESSENTRY32>            process_sequence;

/** Attribute shim for retrieving the process id associated with the PROCESSENTRY32 instance
 *
 * \ingroup group__library__Windows_Toolhelp
 *
 * \param pe The PROCESSENTRY32 instance
 */
inline DWORD get_pid(PROCESSENTRY32 const& pe)
{
    return pe.th32ProcessID;
}

#endif /* STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_TOOLHELP_HPP_PROCESS_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

