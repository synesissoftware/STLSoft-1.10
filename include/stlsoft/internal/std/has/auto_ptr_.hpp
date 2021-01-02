
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
       __cplusplus >= 201402L

   /* for GCC 9+ and C++14 or later we do not enable, so as to avoid warnings */

# else

#  define STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_
# endif
#endif

#endif /* !STLSOFT_INCL_stlsoft_internal_std_has_HPP_auto_ptr_ */

