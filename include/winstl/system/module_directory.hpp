/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/module_directory.hpp
 *
 * Purpose:     Simple class that gets, and makes accessible, the module's
 *              directory.
 *
 * Created:     5th June 2003
 * Updated:     29th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/system/module_directory.hpp
 *
 * \brief [C++] Definition of the winstl::basic_module_directory class
 *  template
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY_MAJOR    4
# define WINSTL_VER_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY_MINOR    3
# define WINSTL_VER_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY_REVISION 1
# define WINSTL_VER_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY_EDIT     73
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE
# include <stlsoft/string/special_string_instance.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
  // Borland is a bit of a thicky, and requires a (valid) spin_mutex_type
# include <winstl/synch/spin_mutex.hpp>
#endif /* compiler */

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
 * basic_module_directory
 *
 * This class determines the directory of a module, and effectively acts as a
 * C-string of its value.
 */

/** Represents the directory of a module
 *
 * \ingroup group__library__System
 *
 * <h2>How</h2>
 *
 * An instance of basic_module_directory encapsulates the directory of a given module. You instantiate it
 * from a given module handle, as follows:
 *
 * [STLSOFT-DOC:VERBATIM:start;comment:/// ;]
 * HINSTANCE                           hinst = . . .;
 * basic_module_directory<char>(hinst) mdir(hinst);
 * puts(mdir);
 * [STLSOFT-DOC:VERBATIM:end]
 *
 * You can also use one of the three given typedefs:
 * \c module_directory (specialised on TCHAR),
 * \c module_directory_a (specialised on CHAR),
 * \c module_directory_w (specialised on WCHAR).
 *
 * <h2>Why</h2>
 *
 * 1. It affords a simpler syntax. You can use temporary instances of the class, and use the <code>char_type const*</code>
 * implicit conversion, or the \c c_str() method inline
 *
 * [STLSOFT-DOC:VERBATIM:start;comment:/// ;]
 * puts(module_directory_a(hinst));
 * [STLSOFT-DOC:VERBATIM:end]
 *
 * You can also use it with the IOStreams:
 *
 * [STLSOFT-DOC:VERBATIM:start;comment:/// ;]
 * cout << L"The module was loaded from the " << module_directory_w(hinst) << L" directory" << endl;
 * [STLSOFT-DOC:VERBATIM:end]
 *
 * 2. It relieves you from the boilerplate coding of calling \c GetModuleFileName() and then parsing the
 * returned path to trim off the directory. All that is handled in the class.
 *
 *
 * \param C The character type
 * \param T The traits type. On translators that support default template arguments, this defaults to filesystem_traits<C>
 */

template <ss_typename_param_k C>
struct moddir_policy
{
/// \name Member Types
/// @{
public:
    typedef C                           char_type;
    typedef HINSTANCE                   argument_0_type;
    typedef processheap_allocator<C>    allocator_type;
    typedef ws_size_t                   size_type;
    typedef size_type                   (*pfn_type)(argument_0_type, char_type *, size_type);
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    // Borland is a bit of a thicky, and requires a (valid) spin_mutex_type
    typedef winstl::spin_mutex          spin_mutex_type;
    typedef winstl::atomic_int_t        atomic_int_type;
#endif /* compiler */
/// @}

/// \name Member Constants
/// @{
public:
    enum { internalBufferSize       =   128  };

    enum { allowImplicitConversion  =   1   };

    enum { caseSensitive            =   0   };

    enum { sharedState              =   0   };
/// @}

/// \name Operations
/// @{
public:
    static pfn_type     get_fn()
    {
        return winstl::system_traits<char_type>::get_module_directory;
    }
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>module</b> directory; ANSI specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_1)<moddir_policy<ws_char_a_t> >    module_directory_a;
/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>module</b> directory; 'Unicode' specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_1)<moddir_policy<ws_char_w_t> >    module_directory_w;
/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>module</b> directory; TCHAR specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_1)<moddir_policy<TCHAR> >          module_directory;

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

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_MODULE_DIRECTORY */

/* ///////////////////////////// end of file //////////////////////////// */

