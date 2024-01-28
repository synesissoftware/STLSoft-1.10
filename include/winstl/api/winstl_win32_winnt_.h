
/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */


#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
#define WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_

/* /////////////////////////////////////////////////////////////////////////
 * Windows version compatibility check(s)
 */

#ifdef WINSTL_WIN32_WINNT
# undef WINSTL_WIN32_WINNT
#endif /* WINSTL_WIN32_WINNT */

#if !defined(_WIN32_WINNT)
# define WINSTL_WIN32_WINNT                                 (0)
#else
# define WINSTL_WIN32_WINNT                                 (_WIN32_WINNT)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

/* ///////////////////////////// end of file //////////////////////////// */

