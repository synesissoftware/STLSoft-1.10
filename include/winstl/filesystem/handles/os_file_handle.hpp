/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/handles/os_file_handle.hpp
 *
 * Purpose:     Handle::Ref+Wrapper handle-adapter class template for
 *              Windows file handles.
 *
 * Created:     7th July 2010
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/filesystem/handles/os_file_handle.hpp
 *
 * \brief [C++] Definition of the winstl::os_file_handle class
 *   template (\ref group__library__FileSystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE
#define WINSTL_INCL_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_MAJOR      1
# define WINSTL_VER_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_MINOR      0
# define WINSTL_VER_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_REVISION   6
# define WINSTL_VER_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_EDIT       15
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
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR
# include <stlsoft/smartptr/ref_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef WINSTL_INCL_WINSTL_API_external_h_HandleAndObject
# include <winstl/api/external/HandleAndObject.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_HandleAndObject */

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

/** A Handle::Ref+Wrapper handle class template for Windows' (HANDLE) files.
 */
template <ss_typename_param_k R>
struct os_file_handle
{
private: // Member Types
//    typedef filesystem_traits<char>                             traits_a_type_;
public:
    /// The handle type
//    typedef ss_typename_type_k traits_a_type_::file_handle_type handle_type;
    typedef HANDLE                                              handle_type;
    /// The reference count policy type
    typedef R                                                   refcount_policy;
    /// This type
    typedef os_file_handle<R>                                   class_type;
    /// The Handle::Ref+Wrapper ref type
    typedef stlsoft::ref_ptr<class_type>                        Ref;

public: // Construction

    /// Creates an instance of the ref from the underlying
    static Ref create(handle_type h)
    {
        return Ref(new class_type(h, true), false);
    }
    /// Destroys an instance of the underlying handle type
    static void destroy(handle_type h)
    {
        WINSTL_API_EXTERNAL_HandleAndObject_CloseHandle(h);
    }

private:
    os_file_handle(handle_type h, bool isOwner)
        : handle(h)
        , refCount(1)
        , isOwner(isOwner)
    {}
private:
    class_type& operator =(class_type const &);

public: // Reference-counting Operations
    /// Adds/increment the reference
    os_file_handle* AddRef()
    {
        refcount_policy::addref(refCount);

        return this;
    }

    /// Releases/decrements the reference
    void Release()
    {
        if (0 == refcount_policy::release(refCount))
        {
            if (isOwner)
            {
                destroy(handle);
            }
            delete this;
        }
    }

public: // Member Variables
    /// The handle value
    handle_type     handle;
private:
    atomic_int_t    refCount;
    const bool      isOwner;
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** Elicits an underlying file-stream handle (<code>HANDLE</code>) from the
 * given instance.
 */
template <ss_typename_param_k R>
inline
ss_typename_type_k os_file_handle<R>::handle_type
get_os_file_handle(
    os_file_handle<R>& h
)
{
    return h.handle;
}

/** Elicits an underlying file-stream handle (<code>HANDLE</code>) from the
 * given instance.
 */
template <ss_typename_param_k R>
inline
ss_typename_type_k os_file_handle<R>::handle_type
get_os_file_handle(
    os_file_handle<R>* h
)
{
    return (NULL != h) ? h->handle : INVALID_HANDLE_VALUE;
}

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

#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE */

/* ///////////////////////////// end of file //////////////////////////// */

