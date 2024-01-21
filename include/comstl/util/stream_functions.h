/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/stream_functions.h
 *
 * Purpose:     Stream functions.
 *
 * Created:     22nd October 2005
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file comstl/util/stream_functions.h
 *
 * \brief [C++; requires COM] COM stream functions
 *   (\ref group__library__COM_Utility "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_H_STREAM_FUNCTIONS
#define COMSTL_INCL_COMSTL_UTIL_H_STREAM_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_H_STREAM_FUNCTIONS_MAJOR    2
# define COMSTL_VER_COMSTL_UTIL_H_STREAM_FUNCTIONS_MINOR    1
# define COMSTL_VER_COMSTL_UTIL_H_STREAM_FUNCTIONS_REVISION 7
# define COMSTL_VER_COMSTL_UTIL_H_STREAM_FUNCTIONS_EDIT     28
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(COMSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** [C] Gets the size of a stream
 *
 * \ingroup group__library__COM_Utility
 *
 * \see comstl::get_stream_size
 */
STLSOFT_INLINE HRESULT comstl__get_stream_size(LPSTREAM pstm, ULARGE_INTEGER *psize)
{
    STATSTG statstg;
    HRESULT hr  =   COMSTL_ITF_CALL(pstm)->Stat(COMSTL_ITF_THIS(pstm) &statstg, STATFLAG_NONAME);

    if (SUCCEEDED(hr))
    {
        *psize = statstg.cbSize;
    }

    return hr;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace comstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus
/** Gets the size of a stream
 *
 * \ingroup group__library__COM_Utility
 */
inline HRESULT get_stream_size(LPSTREAM pstm, ULARGE_INTEGER *psize)
{
    return comstl__get_stream_size(pstm, psize);
}

/** Gets the size of a stream
 *
 * \ingroup group__library__COM_Utility
 */
inline HRESULT get_stream_size(LPSTREAM pstm, ULARGE_INTEGER &size)
{
    return comstl__get_stream_size(pstm, &size);
}

/** Gets the size of a stream
 *
 * \ingroup group__library__COM_Utility
 */
inline HRESULT get_stream_size(LPSTREAM pstm, cs_uint64_t &size)
{
    ULARGE_INTEGER  uli;
    HRESULT         hr  =   comstl__get_stream_size(pstm, &uli);

    if (SUCCEEDED(hr))
    {
        size = uli.QuadPart;
    }

    return hr;
}
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_UTIL_H_STREAM_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

