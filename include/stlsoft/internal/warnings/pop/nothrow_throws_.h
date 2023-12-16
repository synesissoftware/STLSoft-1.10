/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/warnings/pop/nothrow_throws_.h
 *
 * Purpose:     Pops warning suppression for "throwing an exception from a
 *              function marked nothrow()".
 *
 * Created:     18th November 2008
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Refer to stlsoft/stlsoft.h for license conditions
 */

/* STLSOFT:FILE_EXCEPTED */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error Requires stlsoft/stlsoft.h
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_
# undef STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_
#else /* ? STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_ */
# error stlsoft/internal/warnings/pop/nothrow_throws_.h already included without preceeding push
#endif /* STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_ */

#if 0 || \
    defined(STLSOFT_COMPILER_IS_MSVC) || \
    0
# pragma warning(pop)
#endif

/* ///////////////////////////// end of file //////////////////////////// */

