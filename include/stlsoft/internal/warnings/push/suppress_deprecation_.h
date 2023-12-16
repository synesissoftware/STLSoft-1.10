/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/warnings/push/suppress_deprecation_.h
 *
 * Purpose:     Pushes warning suppression for "".
 *
 * Created:     6th October 2016
 * Updated:     23rd January 2021
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2016-2019, Matthew Wilson and Synesis Software
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

#if 0
#elif defined(STLSOFT_CF_gcc_pragma_diagnostic_pop)

# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wdeprecated"
#elif defined(STLSOFT_CF_msvc_pragma_warning_pop)

# pragma warning(push)

# if 0 || \
     (   defined(STLSOFT_COMPILER_IS_MSVC) && \
         _MSC_VER >= 1310) || \
     0
#  pragma warning(disable: 4996)
# endif /* VC++ 8+ */
#endif

/* ///////////////////////////// end of file //////////////////////////// */

