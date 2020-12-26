/* /////////////////////////////////////////////////////////////////////////
 * File:        mfcstl/shims/attribute/get_FILE_ptr.hpp
 *
 * Purpose:     Contains the get_FILE_ptr attribute shim.
 *
 * Created:     22nd May 2008
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


/** \file mfcstl/shims/attribute/get_FILE_ptr.hpp
 *
 * \brief [C++] <code>FILE*</code> attribute shim for MFC types
 *   (\ref group__concept__Shim__Attribute__get_ptr "Pointer Attribute Shims").
 */

#ifndef MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR
#define MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR_MAJOR       1
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR_MINOR       0
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR_REVISION    5
# define MFCSTL_VER_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR_EDIT        12
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef MFCSTL_INCL_MFCSTL_HPP_MFCSTL
# include <mfcstl/mfcstl.hpp>
#endif /* !MFCSTL_INCL_MFCSTL_HPP_MFCSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::mfcstl */
namespace mfcstl
{
# else
/* Define stlsoft::mfcstl_project */
namespace stlsoft
{
namespace mfcstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * get_FILE_ptr
 *
 * This can be applied to an expression, and the return value is the
 * corresponding HWND.
 */

/** Access the FILE* of the given CStdioFile instance
 *
 * \ingroup group__library__Shims_Attribute_FILE
 *
 * This attribute <a href = "http://stlsoft.org/white_papers.html#shims">shim</a>
 * retrieves the <code>FILE*</code> file handle for the given instance.
 *
 * \param file A reference to the CStdioFile instance whose FILE* will be retrieved
 *
 * \return The <code>FILE*</code> corresponding to the given instance
 *
 */
inline
FILE*
get_FILE_ptr(
    CStdioFile& file
)
{
    return file.m_pStream;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef MFCSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace mfcstl */
# else
} /* namespace stlsoft::mfcstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The file ptr shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef MFCSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

    using ::mfcstl::get_FILE_ptr;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !MFCSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !MFCSTL_INCL_MFCSTL_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

