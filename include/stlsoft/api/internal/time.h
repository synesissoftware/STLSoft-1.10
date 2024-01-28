/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/api/internal/time.h
 *
 * Purpose:     Internal adaptations for time.h constructs.
 *
 * Created:     11th January 2017
 * Updated:     2nd January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2017-2019, Matthew Wilson and Synesis Software
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


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_time
#define STLSOFT_INCL_STLSOFT_API_internal_h_time

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */

/* /////////////////////////////////////////////////////////////////////////
 * time functions
 */

STLSOFT_INLINE
int
STLSOFT_API_INTERNAL_Time_gmtime(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_ASSERT(NULL != tm);
    STLSOFT_ASSERT(NULL != t);

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

    STLSOFT_COVER_MARK_LINE();

    return STLSOFT_NS_GLOBAL_(gmtime_s)(tm, t);
#else

  {
    struct tm const* const ptm = STLSOFT_NS_GLOBAL_(gmtime)(t);

    STLSOFT_COVER_MARK_LINE();

    if (NULL == ptm)
    {
        STLSOFT_COVER_MARK_LINE();

        return errno;
    }
    else
    {
        STLSOFT_COVER_MARK_LINE();

        *tm = *ptm;

        return 0;
    }
  }
#endif
}

STLSOFT_INLINE
int
STLSOFT_API_INTERNAL_Time_localtime(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_ASSERT(NULL != tm);
    STLSOFT_ASSERT(NULL != t);

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

    STLSOFT_COVER_MARK_LINE();

    return STLSOFT_NS_GLOBAL_(localtime_s)(tm, t);
#else

  {
    struct tm const* const ptm = STLSOFT_NS_GLOBAL_(localtime)(t);

    STLSOFT_COVER_MARK_LINE();

    if (NULL == ptm)
    {
        STLSOFT_COVER_MARK_LINE();

        return errno;
    }
    else
    {
        STLSOFT_COVER_MARK_LINE();

        *tm = *ptm;

        return 0;
    }
  }
#endif
}

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_time */

/* ///////////////////////////// end of file //////////////////////////// */

