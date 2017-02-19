/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/warnings/pop/suppress_deprecation_.h
 *
 * Purpose:     Pops warning suppression for "".
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
# undef STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_SUPPRESS_DEPRECATION_
#else /* ? STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_SUPPRESS_DEPRECATION_ */
# error stlsoft/internal/warnings/pop/suppress_deprecation_.h already included without preceeding push
#endif /* STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_SUPPRESS_DEPRECATION_ */

#if 0 || \
    defined(STLSOFT_COMPILER_IS_MSVC) || \
    0
# pragma warning(pop)
#endif

/* ///////////////////////////// end of file //////////////////////////// */

