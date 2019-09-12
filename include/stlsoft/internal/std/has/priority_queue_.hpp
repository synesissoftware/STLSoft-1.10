
#ifndef STLSOFT_INCL_stlsoft_internal_std_has_HPP_priority_queue_
#define STLSOFT_INCL_stlsoft_internal_std_has_HPP_priority_queue_

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error This file must not be included independently of stlsoft/stlsoft.h
#endif

#ifndef __cplusplus
# error Valid only for C++ compilation
#endif

#ifdef STLSOFT_SHIMS_ATTRIBUTE_STD_HAS_priority_queue_
# error STLSOFT_SHIMS_ATTRIBUTE_STD_HAS_priority_queue_ should not be defined already
#endif

#if 0
#elif __cplusplus >= 201103L

# define STLSOFT_SHIMS_ATTRIBUTE_STD_HAS_priority_queue_
#elif 0 || \
      (   defined(STLSOFT_COMPILER_IS_MSVC) && \
            _MSC_VER >= 1500) || \
      0

# define STLSOFT_SHIMS_ATTRIBUTE_STD_HAS_priority_queue_
#endif

#endif /* !STLSOFT_INCL_stlsoft_internal_std_has_HPP_priority_queue_ */

