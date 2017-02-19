/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/warnings/push/suppress_deprecation_.h
 *
 * Purpose:     Pushes warning suppression for "".
 *
 * Created:     6th October 2016
 * Updated:     19th February 2017
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2016-2017, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Refer to stlsoft/stlsoft.h for license conditions
 */

/* STLSOFT:FILE_EXCEPTED */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error Requires stlsoft/stlsoft.h
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_SUPPRESS_DEPRECATION_
# error stlsoft/internal/warnings/push/suppress_deprecation_.h already included without matching pop
#else /* ? STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_SUPPRESS_DEPRECATION_ */
# define STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_SUPPRESS_DEPRECATION_
#endif /* STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_SUPPRESS_DEPRECATION_ */

#if 0 || \
    defined(STLSOFT_COMPILER_IS_MSVC) || \
    0
# pragma warning(push)
#endif

#if 0 || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER >= 1310) || \
    0
# pragma warning(disable: 4996)
#endif /* VC++ 8+ */

/* ///////////////////////////// end of file //////////////////////////// */

