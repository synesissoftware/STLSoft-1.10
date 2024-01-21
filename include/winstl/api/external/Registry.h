/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/external/Registry.h
 *
 * Purpose:     External preprocessor aliases for external Windows' Registry
 *              API.
 *
 * Created:     1st April 2014
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2014-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* WARNING: this file contains undocumented internal features that are
 * subject to change at any time, so if you use them it is at your own risk.
 */

#ifndef WINSTL_INCL_WINSTL_API_external_h_Registry
#define WINSTL_INCL_WINSTL_API_external_h_Registry

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

/* /////////////////////////////////////////////////////////////////////////
 * registry functions
 */


#ifndef WINSTL_API_EXTERNAL_Registry_RegCloseKey
# define WINSTL_API_EXTERNAL_Registry_RegCloseKey           STLSOFT_NS_GLOBAL_(RegCloseKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCloseKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegConnectRegistryA
# define WINSTL_API_EXTERNAL_Registry_RegConnectRegistryA   STLSOFT_NS_GLOBAL_(RegConnectRegistryA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegConnectRegistryA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegConnectRegistryW
# define WINSTL_API_EXTERNAL_Registry_RegConnectRegistryW   STLSOFT_NS_GLOBAL_(RegConnectRegistryW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegConnectRegistryW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegConnectRegistry
# define WINSTL_API_EXTERNAL_Registry_RegConnectRegistry    STLSOFT_NS_GLOBAL_(RegConnectRegistry)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegConnectRegistry */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegCopyTreeA
#  define WINSTL_API_EXTERNAL_Registry_RegCopyTreeA         STLSOFT_NS_GLOBAL_(RegCopyTreeA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegCopyTreeA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegCopyTreeW
#  define WINSTL_API_EXTERNAL_Registry_RegCopyTreeW         STLSOFT_NS_GLOBAL_(RegCopyTreeW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegCopyTreeW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegCopyTree
#  define WINSTL_API_EXTERNAL_Registry_RegCopyTree          STLSOFT_NS_GLOBAL_(RegCopyTree)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegCopyTree */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyA
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyA         STLSOFT_NS_GLOBAL_(RegCreateKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyW
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyW         STLSOFT_NS_GLOBAL_(RegCreateKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKey
# define WINSTL_API_EXTERNAL_Registry_RegCreateKey          STLSOFT_NS_GLOBAL_(RegCreateKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyExA
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyExA       STLSOFT_NS_GLOBAL_(RegCreateKeyExA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyExA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyExW
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyExW       STLSOFT_NS_GLOBAL_(RegCreateKeyExW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyExW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyEx
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyEx        STLSOFT_NS_GLOBAL_(RegCreateKeyEx)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyEx */

#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransactedA
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransactedA       STLSOFT_NS_GLOBAL_(RegCreateKeyTransactedA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransactedA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransactedW
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransactedW       STLSOFT_NS_GLOBAL_(RegCreateKeyTransactedW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransactedW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransacted
# define WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransacted        STLSOFT_NS_GLOBAL_(RegCreateKeyTransacted)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegCreateKeyTransacted */

#ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyA
# define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyA         STLSOFT_NS_GLOBAL_(RegDeleteKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyW
# define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyW         STLSOFT_NS_GLOBAL_(RegDeleteKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKey
# define WINSTL_API_EXTERNAL_Registry_RegDeleteKey          STLSOFT_NS_GLOBAL_(RegDeleteKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKey */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyExA
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyExA      STLSOFT_NS_GLOBAL_(RegDeleteKeyExA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyExA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyExW
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyExW      STLSOFT_NS_GLOBAL_(RegDeleteKeyExW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyExW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyEx
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyEx       STLSOFT_NS_GLOBAL_(RegDeleteKeyEx)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyEx */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransactedA
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransactedA      STLSOFT_NS_GLOBAL_(RegDeleteKeyTransactedA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransactedA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransactedW
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransactedW      STLSOFT_NS_GLOBAL_(RegDeleteKeyTransactedW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransactedW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransacted
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransacted       STLSOFT_NS_GLOBAL_(RegDeleteKeyTransacted)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTransacted */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValueA
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValueA   STLSOFT_NS_GLOBAL_(RegDeleteKeyValueA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValueA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValueW
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValueW   STLSOFT_NS_GLOBAL_(RegDeleteKeyValueW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValueW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValue
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValue    STLSOFT_NS_GLOBAL_(RegDeleteKeyValue)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyValue */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTreeA
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTreeA    STLSOFT_NS_GLOBAL_(RegDeleteKeyTreeA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTreeA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTreeW
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTreeW    STLSOFT_NS_GLOBAL_(RegDeleteKeyTreeW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTreeW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTree
#  define WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTree     STLSOFT_NS_GLOBAL_(RegDeleteKeyTree)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteKeyTree */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteValueA
# define WINSTL_API_EXTERNAL_Registry_RegDeleteValueA       STLSOFT_NS_GLOBAL_(RegDeleteValueA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteValueA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteValueW
# define WINSTL_API_EXTERNAL_Registry_RegDeleteValueW       STLSOFT_NS_GLOBAL_(RegDeleteValueW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteValueW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegDeleteValue
# define WINSTL_API_EXTERNAL_Registry_RegDeleteValue        STLSOFT_NS_GLOBAL_(RegDeleteValue)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegDeleteValue */

#ifndef WINSTL_API_EXTERNAL_Registry_RegDisablePredefinedCache
# define WINSTL_API_EXTERNAL_Registry_RegDisablePredefinedCache     STLSOFT_NS_GLOBAL_(RegDisablePredefinedCache)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegDisablePredefinedCache */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegDisablePredefinedCacheEx
#  define WINSTL_API_EXTERNAL_Registry_RegDisablePredefinedCacheEx  STLSOFT_NS_GLOBAL_(RegDisablePredefinedCacheEx)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDisablePredefinedCacheEx */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegDisableReflectionKey
#  define WINSTL_API_EXTERNAL_Registry_RegDisableReflectionKey      STLSOFT_NS_GLOBAL_(RegDisableReflectionKey)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegDisableReflectionKey */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegEnableReflectionKey
#  define WINSTL_API_EXTERNAL_Registry_RegEnableReflectionKey       STLSOFT_NS_GLOBAL_(RegEnableReflectionKey)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegEnableReflectionKey */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumKeyA
# define WINSTL_API_EXTERNAL_Registry_RegEnumKeyA           STLSOFT_NS_GLOBAL_(RegEnumKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumKeyW
# define WINSTL_API_EXTERNAL_Registry_RegEnumKeyW           STLSOFT_NS_GLOBAL_(RegEnumKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumKey
# define WINSTL_API_EXTERNAL_Registry_RegEnumKey            STLSOFT_NS_GLOBAL_(RegEnumKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumKeyExA
# define WINSTL_API_EXTERNAL_Registry_RegEnumKeyExA         STLSOFT_NS_GLOBAL_(RegEnumKeyExA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumKeyExA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumKeyExW
# define WINSTL_API_EXTERNAL_Registry_RegEnumKeyExW         STLSOFT_NS_GLOBAL_(RegEnumKeyExW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumKeyExW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumKeyEx
# define WINSTL_API_EXTERNAL_Registry_RegEnumKeyEx          STLSOFT_NS_GLOBAL_(RegEnumKeyEx)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumKeyEx */

#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumValueA
# define WINSTL_API_EXTERNAL_Registry_RegEnumValueA         STLSOFT_NS_GLOBAL_(RegEnumValueA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumValueA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumValueW
# define WINSTL_API_EXTERNAL_Registry_RegEnumValueW         STLSOFT_NS_GLOBAL_(RegEnumValueW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumValueW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegEnumValue
# define WINSTL_API_EXTERNAL_Registry_RegEnumValue          STLSOFT_NS_GLOBAL_(RegEnumValue)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegEnumValue */

#ifndef WINSTL_API_EXTERNAL_Registry_RegFlushKey
# define WINSTL_API_EXTERNAL_Registry_RegFlushKey           STLSOFT_NS_GLOBAL_(RegFlushKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegFlushKey */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegGetValueA
#  define WINSTL_API_EXTERNAL_Registry_RegGetValueA         STLSOFT_NS_GLOBAL_(RegGetValueA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegGetValueA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegGetValueW
#  define WINSTL_API_EXTERNAL_Registry_RegGetValueW         STLSOFT_NS_GLOBAL_(RegGetValueW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegGetValueW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegGetValue
#  define WINSTL_API_EXTERNAL_Registry_RegGetValue          STLSOFT_NS_GLOBAL_(RegGetValue)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegGetValue */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegLoadAppKeyA
#  define WINSTL_API_EXTERNAL_Registry_RegLoadAppKeyA       STLSOFT_NS_GLOBAL_(RegLoadAppKeyA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadAppKeyA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegLoadAppKeyW
#  define WINSTL_API_EXTERNAL_Registry_RegLoadAppKeyW       STLSOFT_NS_GLOBAL_(RegLoadAppKeyW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadAppKeyW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegLoadAppKey
#  define WINSTL_API_EXTERNAL_Registry_RegLoadAppKey        STLSOFT_NS_GLOBAL_(RegLoadAppKey)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadAppKey */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegLoadKeyA
# define WINSTL_API_EXTERNAL_Registry_RegLoadKeyA           STLSOFT_NS_GLOBAL_(RegLoadKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegLoadKeyW
# define WINSTL_API_EXTERNAL_Registry_RegLoadKeyW           STLSOFT_NS_GLOBAL_(RegLoadKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegLoadKey
# define WINSTL_API_EXTERNAL_Registry_RegLoadKey            STLSOFT_NS_GLOBAL_(RegLoadKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadKey */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegLoadMUIStringA
#  define WINSTL_API_EXTERNAL_Registry_RegLoadMUIStringA    STLSOFT_NS_GLOBAL_(RegLoadMUIStringA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadMUIStringA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegLoadMUIStringW
#  define WINSTL_API_EXTERNAL_Registry_RegLoadMUIStringW    STLSOFT_NS_GLOBAL_(RegLoadMUIStringW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadMUIStringW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegLoadMUIString
#  define WINSTL_API_EXTERNAL_Registry_RegLoadMUIString     STLSOFT_NS_GLOBAL_(RegLoadMUIString)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegLoadMUIString */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegNotifyChangeKeyValue
# define WINSTL_API_EXTERNAL_Registry_RegNotifyChangeKeyValue       STLSOFT_NS_GLOBAL_(RegNotifyChangeKeyValue)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegNotifyChangeKeyValue */

#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenCurrentUser
# define WINSTL_API_EXTERNAL_Registry_RegOpenCurrentUser    STLSOFT_NS_GLOBAL_(RegOpenCurrentUser)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenCurrentUser */

#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyA
# define WINSTL_API_EXTERNAL_Registry_RegOpenKeyA           STLSOFT_NS_GLOBAL_(RegOpenKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyW
# define WINSTL_API_EXTERNAL_Registry_RegOpenKeyW           STLSOFT_NS_GLOBAL_(RegOpenKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKey
# define WINSTL_API_EXTERNAL_Registry_RegOpenKey            STLSOFT_NS_GLOBAL_(RegOpenKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyExA
# define WINSTL_API_EXTERNAL_Registry_RegOpenKeyExA         STLSOFT_NS_GLOBAL_(RegOpenKeyExA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyExA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyExW
# define WINSTL_API_EXTERNAL_Registry_RegOpenKeyExW         STLSOFT_NS_GLOBAL_(RegOpenKeyExW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyExW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyEx
# define WINSTL_API_EXTERNAL_Registry_RegOpenKeyEx          STLSOFT_NS_GLOBAL_(RegOpenKeyEx)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyEx */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransactedA
#  define WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransactedA        STLSOFT_NS_GLOBAL_(RegOpenKeyTransactedA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransactedA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransactedW
#  define WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransactedW        STLSOFT_NS_GLOBAL_(RegOpenKeyTransactedW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransactedW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransacted
#  define WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransacted STLSOFT_NS_GLOBAL_(RegOpenKeyTransacted)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenKeyTransacted */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegOpenUserClassesRoot
# define WINSTL_API_EXTERNAL_Registry_RegOpenUserClassesRoot        STLSOFT_NS_GLOBAL_(RegOpenUserClassesRoot)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOpenUserClassesRoot */

#ifndef WINSTL_API_EXTERNAL_Registry_RegOverridePredefKey
# define WINSTL_API_EXTERNAL_Registry_RegOverridePredefKey  STLSOFT_NS_GLOBAL_(RegOverridePredefKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegOverridePredefKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryInfoKeyA
# define WINSTL_API_EXTERNAL_Registry_RegQueryInfoKeyA      STLSOFT_NS_GLOBAL_(RegQueryInfoKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryInfoKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryInfoKeyW
# define WINSTL_API_EXTERNAL_Registry_RegQueryInfoKeyW      STLSOFT_NS_GLOBAL_(RegQueryInfoKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryInfoKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryInfoKey
# define WINSTL_API_EXTERNAL_Registry_RegQueryInfoKey       STLSOFT_NS_GLOBAL_(RegQueryInfoKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryInfoKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValuesA
# define WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValuesA       STLSOFT_NS_GLOBAL_(RegQueryMultipleValuesA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValuesA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValuesW
# define WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValuesW       STLSOFT_NS_GLOBAL_(RegQueryMultipleValuesW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValuesW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValues
# define WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValues        STLSOFT_NS_GLOBAL_(RegQueryMultipleValues)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryMultipleValues */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegQueryReflectionKey
#  define WINSTL_API_EXTERNAL_Registry_RegQueryReflectionKey        STLSOFT_NS_GLOBAL_(RegQueryReflectionKey)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryReflectionKey */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryValueA
# define WINSTL_API_EXTERNAL_Registry_RegQueryValueA        STLSOFT_NS_GLOBAL_(RegQueryValueA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryValueA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryValueW
# define WINSTL_API_EXTERNAL_Registry_RegQueryValueW        STLSOFT_NS_GLOBAL_(RegQueryValueW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryValueW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryValue
# define WINSTL_API_EXTERNAL_Registry_RegQueryValue         STLSOFT_NS_GLOBAL_(RegQueryValue)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryValue */

#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryValueExA
# define WINSTL_API_EXTERNAL_Registry_RegQueryValueExA      STLSOFT_NS_GLOBAL_(RegQueryValueExA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryValueExA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryValueExW
# define WINSTL_API_EXTERNAL_Registry_RegQueryValueExW      STLSOFT_NS_GLOBAL_(RegQueryValueExW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryValueExW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegQueryValueEx
# define WINSTL_API_EXTERNAL_Registry_RegQueryValueEx       STLSOFT_NS_GLOBAL_(RegQueryValueEx)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegQueryValueEx */

#ifndef WINSTL_API_EXTERNAL_Registry_RegReplaceKeyA
# define WINSTL_API_EXTERNAL_Registry_RegReplaceKeyA        STLSOFT_NS_GLOBAL_(RegReplaceKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegReplaceKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegReplaceKeyW
# define WINSTL_API_EXTERNAL_Registry_RegReplaceKeyW        STLSOFT_NS_GLOBAL_(RegReplaceKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegReplaceKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegReplaceKey
# define WINSTL_API_EXTERNAL_Registry_RegReplaceKey         STLSOFT_NS_GLOBAL_(RegReplaceKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegReplaceKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegRestoreKeyA
# define WINSTL_API_EXTERNAL_Registry_RegRestoreKeyA        STLSOFT_NS_GLOBAL_(RegRestoreKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegRestoreKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegRestoreKeyW
# define WINSTL_API_EXTERNAL_Registry_RegRestoreKeyW        STLSOFT_NS_GLOBAL_(RegRestoreKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegRestoreKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegRestoreKey
# define WINSTL_API_EXTERNAL_Registry_RegRestoreKey         STLSOFT_NS_GLOBAL_(RegRestoreKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegRestoreKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegSaveKeyA
# define WINSTL_API_EXTERNAL_Registry_RegSaveKeyA           STLSOFT_NS_GLOBAL_(RegSaveKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSaveKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSaveKeyW
# define WINSTL_API_EXTERNAL_Registry_RegSaveKeyW           STLSOFT_NS_GLOBAL_(RegSaveKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSaveKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSaveKey
# define WINSTL_API_EXTERNAL_Registry_RegSaveKey            STLSOFT_NS_GLOBAL_(RegSaveKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSaveKey */

#ifndef WINSTL_API_EXTERNAL_Registry_RegSaveKeyExA
# define WINSTL_API_EXTERNAL_Registry_RegSaveKeyExA         STLSOFT_NS_GLOBAL_(RegSaveKeyExA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSaveKeyExA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSaveKeyExW
# define WINSTL_API_EXTERNAL_Registry_RegSaveKeyExW         STLSOFT_NS_GLOBAL_(RegSaveKeyExW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSaveKeyExW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSaveKeyEx
# define WINSTL_API_EXTERNAL_Registry_RegSaveKeyEx          STLSOFT_NS_GLOBAL_(RegSaveKeyEx)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSaveKeyEx */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Registry_RegSetKeyValueA
#  define WINSTL_API_EXTERNAL_Registry_RegSetKeyValueA      STLSOFT_NS_GLOBAL_(RegSetKeyValueA)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegSetKeyValueA */
# ifndef WINSTL_API_EXTERNAL_Registry_RegSetKeyValueW
#  define WINSTL_API_EXTERNAL_Registry_RegSetKeyValueW      STLSOFT_NS_GLOBAL_(RegSetKeyValueW)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegSetKeyValueW */
# ifndef WINSTL_API_EXTERNAL_Registry_RegSetKeyValue
#  define WINSTL_API_EXTERNAL_Registry_RegSetKeyValue       STLSOFT_NS_GLOBAL_(RegSetKeyValue)
# endif /* !WINSTL_API_EXTERNAL_Registry_RegSetKeyValue */
#endif

#ifndef WINSTL_API_EXTERNAL_Registry_RegSetValueA
# define WINSTL_API_EXTERNAL_Registry_RegSetValueA          STLSOFT_NS_GLOBAL_(RegSetValueA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSetValueA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSetValueW
# define WINSTL_API_EXTERNAL_Registry_RegSetValueW          STLSOFT_NS_GLOBAL_(RegSetValueW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSetValueW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSetValue
# define WINSTL_API_EXTERNAL_Registry_RegSetValue           STLSOFT_NS_GLOBAL_(RegSetValue)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSetValue */

#ifndef WINSTL_API_EXTERNAL_Registry_RegSetValueExA
# define WINSTL_API_EXTERNAL_Registry_RegSetValueExA        STLSOFT_NS_GLOBAL_(RegSetValueExA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSetValueExA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSetValueExW
# define WINSTL_API_EXTERNAL_Registry_RegSetValueExW        STLSOFT_NS_GLOBAL_(RegSetValueExW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSetValueExW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegSetValueEx
# define WINSTL_API_EXTERNAL_Registry_RegSetValueEx         STLSOFT_NS_GLOBAL_(RegSetValueEx)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegSetValueEx */

#ifndef WINSTL_API_EXTERNAL_Registry_RegUnloadKeyA
# define WINSTL_API_EXTERNAL_Registry_RegUnloadKeyA         STLSOFT_NS_GLOBAL_(RegUnloadKeyA)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegUnloadKeyA */
#ifndef WINSTL_API_EXTERNAL_Registry_RegUnloadKeyW
# define WINSTL_API_EXTERNAL_Registry_RegUnloadKeyW         STLSOFT_NS_GLOBAL_(RegUnloadKeyW)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegUnloadKeyW */
#ifndef WINSTL_API_EXTERNAL_Registry_RegUnloadKey
# define WINSTL_API_EXTERNAL_Registry_RegUnloadKey          STLSOFT_NS_GLOBAL_(RegUnloadKey)
#endif /* !WINSTL_API_EXTERNAL_Registry_RegUnloadKey */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_API_external_h_Registry */

/* ///////////////////////////// end of file //////////////////////////// */

