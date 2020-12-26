/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/current_directory.hpp
 *
 * Purpose:     Special-string instance that obtains the current directory.
 *
 * Created:     1st November 2003
 * Updated:     24th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file unixstl/filesystem/current_directory.hpp
 *
 * \brief [C++] Definition of the unixstl::basic_current_directory
 *  class template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_MAJOR     4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_MINOR     2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_REVISION  2
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY_EDIT      68
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE
# include <stlsoft/string/special_string_instance.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE */
#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <unixstl/filesystem/filesystem_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

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
 * classes
 */

/** \ref group__pattern__special_string_instance "Special String Instance"
 *   policy template for eliciting the <b>current</b> directory.
 *
 * \ingroup group__library__System
 */
template <ss_typename_param_k C>
struct cwd_policy
{
    typedef C                           char_type;
    typedef void                        allocator_type;
    typedef ss_size_t                   size_type;
    typedef size_type                   (*pfn_type)(char_type *, size_type);

    enum { internalBufferSize       =   128 };

    enum { allowImplicitConversion  =   1   };

    enum { caseSensitive            =   1   };

    enum { sharedState              =   0   };

    static pfn_type     get_fn()
    {
        return unixstl::filesystem_traits<char_type>::get_current_directory;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>current</b> directory; ANSI specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_0)< cwd_policy<us_char_a_t> >   current_directory_a;
/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>current</b> directory; 'Unicode' specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_0)< cwd_policy<us_char_w_t> >   current_directory_w;
/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>current</b> directory; char specialisation.
 *
 * \ingroup group__library__System
 */
typedef STLSOFT_NS_QUAL(special_string_instance_0)< cwd_policy<char> >          current_directory;

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

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_CURRENT_DIRECTORY */

/* ///////////////////////////// end of file //////////////////////////// */

