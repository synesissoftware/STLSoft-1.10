/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/output_debug_line.h
 *
 * Purpose:     Functions to write lines to the Windows debugger.
 *
 * Created:     5th January 2011
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/diagnostics/output_debug_line.h
 *
 * \brief [C++] Functions to write lines to the Windows debugger.
 *   (\ref group__library__Diagnostic "Diagnostic" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_MAJOR    2
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_MINOR    0
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_REVISION 2
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_EDIT     22
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifndef STLSOFT_INCL_H_STDARG
# define STLSOFT_INCL_H_STDARG
# include <stdarg.h>
#endif /* !STLSOFT_INCL_H_STDARG */
#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Debugging
# include <winstl/api/external/Debugging.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_Debugging */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/* TODO: move to separate file */
STLSOFT_INLINE
STLSOFT_NS_QUAL(ss_size_t)
stlsoft_C_concatenate_N_m(
    STLSOFT_NS_QUAL(ss_char_a_t)*           buff
,   STLSOFT_NS_QUAL(ss_size_t)              cchBuff
,   STLSOFT_NS_QUAL(ss_char_a_t) const**    psz
,   STLSOFT_NS_QUAL(ss_size_t)              n
,   ...
)
{
    STLSOFT_NS_USING(ss_char_a_t);
    STLSOFT_NS_USING(ss_size_t);

    {
        ss_size_t total = 0;

        {
            va_list     args;
            ss_size_t   i;

            va_start(args, n);

            for (i = 0; i != n; ++i)
            {
                ss_char_a_t const*  s   =   va_arg(args, ss_char_a_t const*);
                ss_size_t           len =   STLSOFT_NS_QUAL(c_str_len_a)(s);

                total += len;
            }

            va_end(args);
        }

        {
            va_list         args;
            ss_size_t       i;
            ss_char_a_t*    dest;

            if (total + 1 > cchBuff)
            {
                dest = STLSOFT_STATIC_CAST(STLSOFT_NS_QUAL(ss_char_a_t)*, STLSOFT_NS_GLOBAL(malloc)(sizeof(ss_char_a_t) * (1 + total)));

                if (NULL == dest)
                {
                    *psz = NULL;

                    return 0;
                }
            }
            else
            {
                dest = buff;
            }

            *psz = dest;

            va_start(args, n);

            for (i = 0; i != n; ++i)
            {
                ss_char_a_t const*  s   =   va_arg(args, ss_char_a_t const*);
                ss_size_t           len =   STLSOFT_NS_QUAL(c_str_len_a)(s);

                STLSOFT_API_INTERNAL_memfns_memcpy(dest, s, sizeof(ss_char_a_t) * len);
                dest += len;
            }
            *dest = '\0';

            va_end(args);

            return total;
        }
    }
}

STLSOFT_INLINE
void
stlsoft_C_concatenate_free_m(
    STLSOFT_NS_QUAL(ss_char_a_t)*       buff
,   STLSOFT_NS_QUAL(ss_char_a_t) const* psz
)
{
    STLSOFT_COVER_MARK_LINE();

    if (buff != psz)
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_NS_GLOBAL(free)(STLSOFT_CONST_CAST(STLSOFT_NS_QUAL(ss_char_a_t)*, psz));
    }
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/* This is provided to facilitate unit-testing */
#ifndef WINSTL_DIAGNOSTICS_OUTPUT_DEBUG_LINE_SUPPRESS_ODS_

STLSOFT_INLINE
void
winstl_C_call_OutputDebugStringA_(
    WINSTL_NS_QUAL(ws_char_a_t) const* s
)
{
    STLSOFT_COVER_MARK_LINE();

    if (NULL != s)
    {
        STLSOFT_COVER_MARK_LINE();

        WINSTL_API_EXTERNAL_Debugging_OutputDebugStringA(s);
    }
}

#endif /* WINSTL_DIAGNOSTICS_OUTPUT_DEBUG_LINE_SUPPRESS_ODS_ */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Emits the given multibyte string fragment and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_1_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 2u, s0, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_2_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 3u, s0, s1, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_3_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 4u, s0, s1, s2, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_4_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 5u, s0, s1, s2, s3, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_5_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 6u, s0, s1, s2, s3, s4, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_6_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 7u, s0, s1, s2, s3, s4, s5, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_7_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 8u, s0, s1, s2, s3, s4, s5, s6, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_8_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 9u, s0, s1, s2, s3, s4, s5, s6, s7, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_9_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 10u, s0, s1, s2, s3, s4, s5, s6, s7, s8, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 * \param s9 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_10_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
,   WINSTL_NS_QUAL(ws_char_a_t) const* s9
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 11u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 * \param s9 String fragment to combine and emit
 * \param s10 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_11_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
,   WINSTL_NS_QUAL(ws_char_a_t) const* s9
,   WINSTL_NS_QUAL(ws_char_a_t) const* s10
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 12u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 * \param s9 String fragment to combine and emit
 * \param s10 String fragment to combine and emit
 * \param s11 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_12_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
,   WINSTL_NS_QUAL(ws_char_a_t) const* s9
,   WINSTL_NS_QUAL(ws_char_a_t) const* s10
,   WINSTL_NS_QUAL(ws_char_a_t) const* s11
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 13u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_(s11);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 * \param s9 String fragment to combine and emit
 * \param s10 String fragment to combine and emit
 * \param s11 String fragment to combine and emit
 * \param s12 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_13_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
,   WINSTL_NS_QUAL(ws_char_a_t) const* s9
,   WINSTL_NS_QUAL(ws_char_a_t) const* s10
,   WINSTL_NS_QUAL(ws_char_a_t) const* s11
,   winstl_ns_qual(ws_char_a_t) const* s12
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 14u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_(s11);
            winstl_C_call_OutputDebugStringA_(s12);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 * \param s9 String fragment to combine and emit
 * \param s10 String fragment to combine and emit
 * \param s11 String fragment to combine and emit
 * \param s12 String fragment to combine and emit
 * \param s13 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_14_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
,   WINSTL_NS_QUAL(ws_char_a_t) const* s9
,   WINSTL_NS_QUAL(ws_char_a_t) const* s10
,   WINSTL_NS_QUAL(ws_char_a_t) const* s11
,   winstl_ns_qual(ws_char_a_t) const* s12
,   winstl_ns_qual(ws_char_a_t) const* s13
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 15u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_(s11);
            winstl_C_call_OutputDebugStringA_(s12);
            winstl_C_call_OutputDebugStringA_(s13);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 * \param s9 String fragment to combine and emit
 * \param s10 String fragment to combine and emit
 * \param s11 String fragment to combine and emit
 * \param s12 String fragment to combine and emit
 * \param s13 String fragment to combine and emit
 * \param s14 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_15_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
,   WINSTL_NS_QUAL(ws_char_a_t) const* s9
,   WINSTL_NS_QUAL(ws_char_a_t) const* s10
,   WINSTL_NS_QUAL(ws_char_a_t) const* s11
,   winstl_ns_qual(ws_char_a_t) const* s12
,   winstl_ns_qual(ws_char_a_t) const* s13
,   winstl_ns_qual(ws_char_a_t) const* s14
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 16u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_(s11);
            winstl_C_call_OutputDebugStringA_(s12);
            winstl_C_call_OutputDebugStringA_(s13);
            winstl_C_call_OutputDebugStringA_(s14);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/** Emits the given multibyte string fragments and a terminating line-feed
 * as a single string to the Windows' Debugging API function
 * <code>OutputDebugStringA()</code>
 *
 * \ingroup group__library__Diagnostic
 *
 * \note The function attempts to emit the combined string atomically,
 *   defaulting to emitting the fragments separately if that cannot be
 *   achieved
 *
 * \param s0 String fragment to combine and emit
 * \param s1 String fragment to combine and emit
 * \param s2 String fragment to combine and emit
 * \param s3 String fragment to combine and emit
 * \param s4 String fragment to combine and emit
 * \param s5 String fragment to combine and emit
 * \param s6 String fragment to combine and emit
 * \param s7 String fragment to combine and emit
 * \param s8 String fragment to combine and emit
 * \param s9 String fragment to combine and emit
 * \param s10 String fragment to combine and emit
 * \param s11 String fragment to combine and emit
 * \param s12 String fragment to combine and emit
 * \param s13 String fragment to combine and emit
 * \param s14 String fragment to combine and emit
 * \param s15 String fragment to combine and emit
 */
STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_16_m(
    WINSTL_NS_QUAL(ws_char_a_t) const* s0
,   WINSTL_NS_QUAL(ws_char_a_t) const* s1
,   WINSTL_NS_QUAL(ws_char_a_t) const* s2
,   WINSTL_NS_QUAL(ws_char_a_t) const* s3
,   WINSTL_NS_QUAL(ws_char_a_t) const* s4
,   WINSTL_NS_QUAL(ws_char_a_t) const* s5
,   WINSTL_NS_QUAL(ws_char_a_t) const* s6
,   WINSTL_NS_QUAL(ws_char_a_t) const* s7
,   WINSTL_NS_QUAL(ws_char_a_t) const* s8
,   WINSTL_NS_QUAL(ws_char_a_t) const* s9
,   WINSTL_NS_QUAL(ws_char_a_t) const* s10
,   WINSTL_NS_QUAL(ws_char_a_t) const* s11
,   winstl_ns_qual(ws_char_a_t) const* s12
,   winstl_ns_qual(ws_char_a_t) const* s13
,   winstl_ns_qual(ws_char_a_t) const* s14
,   winstl_ns_qual(ws_char_a_t) const* s15
)
{
    WINSTL_NS_USING(ws_char_a_t);

    STLSOFT_COVER_MARK_LINE();

    {
#ifdef STLSOFT_DEBUG
        ws_char_a_t         buff[10];
#else /* ? STLSOFT_DEBUG */
        ws_char_a_t         buff[1000];
#endif /* STLSOFT_DEBUG */
        ws_char_a_t const*  psz;

        if (0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 17u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, "\n"))
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_(s11);
            winstl_C_call_OutputDebugStringA_(s12);
            winstl_C_call_OutputDebugStringA_(s13);
            winstl_C_call_OutputDebugStringA_(s14);
            winstl_C_call_OutputDebugStringA_(s15);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE */

/* ///////////////////////////// end of file //////////////////////////// */

