
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

# define STLSOFT_STANDARD_LIBRARY_HAS_auto_ptr_
#endif

#endif /* !STLSOFT_INCL_stlsoft_internal_std_has_HPP_auto_ptr_ */

