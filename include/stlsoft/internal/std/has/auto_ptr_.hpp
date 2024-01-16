
/* STLSOFT:FILE_NOT_SELF_SUFFICIENT */

#ifndef STLSOFT_INCL_stlsoft_internal_std_has_HPP_auto_ptr_
#define STLSOFT_INCL_stlsoft_internal_std_has_HPP_auto_ptr_

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error This file must not be included independently of stlsoft/stlsoft.h
#endif

#ifndef __cplusplus
# error Valid only for C++ compilation
#endif

#ifdef STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_
# error STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_ should not be defined already
#endif

#if 0
#elif __cplusplus < 199711L
#elif __cplusplus >= 201703L
#else

# if 0
# elif defined(__GNUC__) && \
       __GNUC__ >= 9 && \
       !defined(STLSOFT_ALLOW_auto_ptr_in_cplusplus_11_or_14) && \
       __cplusplus >= 201402L

    /* for GCC 9+ and C++11-14 or later we do not enable, so as to avoid warnings */
# elif defined(STLSOFT_COMPILER_IS_WATCOM)

    /* not supported on any known version */
# else

#  define STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_
# endif
#endif

#endif /* !STLSOFT_INCL_stlsoft_internal_std_has_HPP_auto_ptr_ */

/* ///////////////////////////// end of file //////////////////////////// */

