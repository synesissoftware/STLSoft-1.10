/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/path_functions/classify_functions_X_.h
 *
 * Purpose:     Path classification functions char-X implementation
 *
 * Created:     21st December 2020
 * Updated:     18th January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2020-2024, Matthew Wilson and Synesis Information Systems
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


/* STLSOFT:FILE_NOT_SELF_SUFFICIENT */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_H_PATH_CLASSIFY_FUNCTIONS
# error This file must be included from unixstl/filesystem/path_classify_functions.h
#endif

#ifndef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_
# error UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_
#endif

#ifndef unixstl_C_path_classification_results_X_t_
# error unixstl_C_path_classification_results_X_t_
#endif

#ifndef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_
# error UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_
#endif

#ifndef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_
# error UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_
#endif

#ifndef UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_
# error UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnstrn_X_
#endif

#ifndef UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_
# error UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_ must be defined
#endif

#ifndef unixstl_C_path_classify_alwaysInvalidChars_X_
# error unixstl_C_path_classify_alwaysInvalidChars_X_ must be defined
#endif

#ifndef unixstl_C_path_classify_root_X_
# error unixstl_C_path_classify_root_X_ must be defined
#endif

#ifndef unixstl_C_path_classify_impl_X_
# error unixstl_C_path_classify_impl_X_ must be defined
#endif

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

STLSOFT_INLINE
UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_
unixstl_C_path_classify_alwaysInvalidChars_X_()
{
    typedef UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_             char_t;

    static char_t s_invalidCards[] =
    {
        '<'
    ,   '>'
    ,   '|'
    ,   '?'
    ,   '*'
    ,   '"'
    ,   '\0'
    };

    UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_  r = { STLSOFT_NUM_ELEMENTS(s_invalidCards), s_invalidCards };

#if 0
/*
    < (less than)
    > (greater than)
    | (vertical bar or pipe)
    ? (question mark)
    * (asterisk)
    " (double quote)
    NUL

    : (colon)
    / (forward slash)
    \ (backslash)
*/
#endif

    return r;
}

STLSOFT_INLINE
unixstl_C_path_classification_t
unixstl_C_path_classify_root_X_(
    UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_ const*  s0
,   size_t                                      cch0
,   int                                         parseFlags
,   unixstl_C_path_classification_results_X_t_* results
,   UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_ const** ppS1
,   size_t*                                     pCch1
,   size_t*                                     pCchPrefix
)
{
    UNIXSTL_ASSERT(ss_nullptr_k != s0);
    UNIXSTL_ASSERT(0 != cch0);

    UNIXSTL_MESSAGE_ASSERT("unrecognised parsing flags", 0 == (~UNIXSTL_PATH_CLASSIFY_F_MASK_ & parseFlags));

    UNIXSTL_ASSERT(ss_nullptr_k != results);

    UNIXSTL_ASSERT(ss_nullptr_k != ppS1);
    UNIXSTL_ASSERT(ss_nullptr_k != pCch1);

    UNIXSTL_ASSERT(ss_nullptr_k != pCchPrefix);


    STLSOFT_SUPPRESS_UNUSED(parseFlags);
    STLSOFT_SUPPRESS_UNUSED(results);


    *ppS1           =   s0;
    *pCch1          =   cch0;

    *pCchPrefix     =   0;

    if ('/' == s0[0])
    {
        /* "/" */

        return UNIXSTL_C_PathType_SlashRooted;
    }

    if ('~' == s0[0])
    {
        if (0 != (UNIXSTL_PATH_CLASSIFY_F_RECOGNISETILDEHOME & parseFlags))
        {
            if (1 == cch0)
            {
                *ppS1       =   s0 + 1;
                *pCch1      =   cch0 - 1;

                return UNIXSTL_C_PathType_HomeRooted;
            }
            else
            switch (s0[1])
            {
            case '/':

                *ppS1       =   s0 + 1;
                *pCch1      =   cch0 - 1;

                return UNIXSTL_C_PathType_HomeRooted;
            }
        }
    }

    return UNIXSTL_C_PathType_Relative;
}


STLSOFT_INLINE
unixstl_C_path_classification_t
unixstl_C_path_classify_impl_X_(
    UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_ const* s0
,   size_t                                      cch0
,   int                                         parseFlags
,   unixstl_C_path_classification_results_X_t_* results
)
{
    typedef UNIXSTL_C_PATH_CLASSIFY_IMPL_char_t_            char_t;

    char_t const*                               s1;
    size_t                                      cch1;
    size_t                                      cchPrefix;
    char_t const*                               invalidChar;
    unixstl_C_path_classification_t             rcRoot;
#if 0
#elif defined(STLSOFT_CF_gcc_pragma_diagnostic_pop)

# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wmissing-braces"
# pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
    unixstl_C_path_classification_results_X_t_  blank = { 0 };
#if 0
#elif defined(STLSOFT_CF_gcc_pragma_diagnostic_pop)

# pragma GCC diagnostic pop
#endif

    UNIXSTL_ASSERT(0 == cch0 || ss_nullptr_k != s0);

    UNIXSTL_MESSAGE_ASSERT("unrecognised parsing flags", 0 == (~UNIXSTL_PATH_CLASSIFY_F_MASK_ & parseFlags));

    UNIXSTL_ASSERT(ss_nullptr_k != results);

    *results = blank;

    results->input.ptr  =   s0;
    results->input.len  =   cch0;

    if (0 == cch0)
    {
        return UNIXSTL_C_PathType_Empty;
    }

    rcRoot = unixstl_C_path_classify_root_X_(
        s0, cch0
    ,   parseFlags
    ,   results
    ,   &s1, &cch1
    ,   &cchPrefix
    );

    UNIXSTL_ASSERT(s0 + cch0 == s1 + cch1);

    switch (rcRoot)
    {
    case    UNIXSTL_C_PathType_Relative:
    case    UNIXSTL_C_PathType_SlashRooted:
    case    UNIXSTL_C_PathType_HomeRooted:

        break;
    default:

        return rcRoot;
    }

    if (0 == (UNIXSTL_PATH_CLASSIFY_F_IGNOREINVALIDCHARS & parseFlags))
    {
        UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_string_slice_X_t_ const alwaysInvalidChars = unixstl_C_path_classify_alwaysInvalidChars_X_();

        if (ss_nullptr_k != (invalidChar = UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnpbrkn_X_(s1, cch1, alwaysInvalidChars.ptr, alwaysInvalidChars.len)))
        {
            results->firstInvalid.len   =   1;
            results->firstInvalid.ptr   =   invalidChar;

            return UNIXSTL_C_PathType_InvalidChars;
        }

        if (ss_nullptr_k != (invalidChar = UNIXSTL_C_PATH_CLASSIFY_IMPL_stlsoft_C_strnchr_X_(s1, cch1, ':')))
        {
            results->firstInvalid.len   =   1;
            results->firstInvalid.ptr   =   invalidChar;

            return UNIXSTL_C_PathType_InvalidChars;
        }
    }

    {
        char_t const* const last    =   s1 + cch1;

        char_t const*       p0;
        size_t              i;

        char_t const*       lastBSlash  =   ss_nullptr_k;
        char_t const*       lastFSlash  =   ss_nullptr_k;
        char_t const*       lastSlash   =   ss_nullptr_k;

        char_t const*       lastDot     =   ss_nullptr_k;
        char_t const*       prev        =   ss_nullptr_k;

#if 0 || \
    defined(STLSOFT_COMPILER_IS_CLANG) || \
    defined(STLSOFT_COMPILER_IS_GCC) || \
    0

        STLSOFT_SUPPRESS_UNUSED(prev);
#endif

        int const           checkRuns   =   0 == (UNIXSTL_PATH_CLASSIFY_F_IGNORESLASHRUNS & parseFlags);
        int                 runLength   =   0;

        size_t              numParts    =   0;

        for (i = 0, p0 = s1; i != cch1; ++i, ++p0)
        {
            switch (*p0)
            {
            case '.':

                lastDot = p0;

                runLength = 0;
                break;
            case '/':
            case '\\':

                *((*p0 == '\\') ? &lastBSlash : &lastFSlash) = p0;

                lastDot = ss_nullptr_k;

                if (0 == runLength)
                {
                    ++numParts;
                }
                else
                {
                    if (checkRuns)
                    {
                        results->firstInvalid.len    =   1;
                        results->firstInvalid.ptr    =   p0;

                        return UNIXSTL_C_PathType_InvalidSlashRuns;
                    }
                }

                ++runLength;
                break;
            default:

                runLength = 0;
                break;
            }

            prev = p0;
        }

        if (ss_nullptr_k != lastBSlash)
        {
            if (ss_nullptr_k != lastFSlash)
            {
                if (lastBSlash < lastFSlash)
                {
                    lastSlash = lastFSlash;
                }
                else
                {
                    lastSlash = lastBSlash;
                }
            }
            else
            {
                lastSlash = lastBSlash;
            }
        }
        else
        {
            if (ss_nullptr_k != lastFSlash)
            {
                lastSlash = lastFSlash;
            }
            else
            {
                ; /* nothing to do */
            }
        }

        if (ss_nullptr_k != lastSlash)
        {
            if (lastSlash < s1 + (cch1 - 1))
            {
                results->entry.len  =   last - (lastSlash + 1);
                results->entry.ptr  =   lastSlash + 1;
            }
        }
        else
        {
            if (0 != cch1)
            {
                results->entry.len  =   cch1;
                results->entry.ptr  =   s1;
            }
        }

        results->stem   =   results->entry;

        if (ss_nullptr_k != lastDot)
        {
            /* Now we need to examine for special names
             *
             * - "."
             * - ".."
             *
             */

            if (1 == results->entry.len)
            {
                UNIXSTL_ASSERT(lastDot == results->entry.ptr);

                /* The current directory "." */

                ;
            }
            else
            if (2 == results->entry.len &&
                '.' == results->entry.ptr[0] &&
                '.' == results->entry.ptr[1])
            {
                /* The parent directory ".." */

                ;
            }
            else
            {
                results->extension.len  =   last - lastDot;
                results->extension.ptr  =   lastDot;

                results->stem.len       -=  results->extension.len;
            }
        }

        results->numDirectoryParts  =   numParts;
    }

    results->prefix.len =   cchPrefix;
    results->prefix.ptr =   s0;

    results->root.len   =   cch0 - cch1;
    results->root.ptr   =   s0;

    results->location   =   results->input;
    results->directory  =   results->input;

    if (0 != results->entry.len)
    {
        results->location.len   -=  results->entry.len;
        results->directory.len  -=  results->entry.len;
    }

    if (0 != results->root.len)
    {
        results->directory.len  -=  results->root.len;
        results->directory.ptr  +=  results->root.len;
    }

    return rcRoot;
}

/* ///////////////////////////// end of file //////////////////////////// */

