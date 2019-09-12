
#ifndef STLSOFT_INCL_stlsoft_internal_std_has_HPP_unique_ptr_
#define STLSOFT_INCL_stlsoft_internal_std_has_HPP_unique_ptr_

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error This file must not be included independently of stlsoft/stlsoft.h
#endif

#ifndef __cplusplus
# error Valid only for C++ compilation
#endif

#ifdef STLSOFT_SHIMS_ATTRIBUTE_STD_HAS_unique_ptr_
# error STLSOFT_SHIMS_ATTRIBUTE_STD_HAS_unique_ptr_ should not be defined already
#endif

#if __cplusplus >= 197711L
# define STLSOFT_SHIMS_ATTRIBUTE_STD_HAS_unique_ptr_
#endif

#endif /* !STLSOFT_INCL_stlsoft_internal_std_has_HPP_unique_ptr_ */

