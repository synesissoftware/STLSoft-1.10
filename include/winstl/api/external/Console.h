/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/api/external/Console.h
 *
 * Purpose:     External preprocessor aliases for external Windows' Console
 *              API.
 *
 * Created:     24th August 2014
 * Updated:     15th February 2017
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014-2017, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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

#ifndef WINSTL_INCL_WINSTL_API_external_h_Console
#define WINSTL_INCL_WINSTL_API_external_h_Console

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

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


#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_AddConsoleAlias
#  define WINSTL_API_EXTERNAL_Console_AddConsoleAlias                       STLSOFT_NS_GLOBAL(AddConsoleAlias)
# endif /* !WINSTL_API_EXTERNAL_Console_AddConsoleAlias */
# ifndef WINSTL_API_EXTERNAL_Console_AddConsoleAliasA
#  define WINSTL_API_EXTERNAL_Console_AddConsoleAliasA                      STLSOFT_NS_GLOBAL(AddConsoleAliasA)
# endif /* !WINSTL_API_EXTERNAL_Console_AddConsoleAliasA */
# ifndef WINSTL_API_EXTERNAL_Console_AddConsoleAliasW
#  define WINSTL_API_EXTERNAL_Console_AddConsoleAliasW                      STLSOFT_NS_GLOBAL(AddConsoleAliasW)
# endif /* !WINSTL_API_EXTERNAL_Console_AddConsoleAliasW */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_AllocConsole
# define WINSTL_API_EXTERNAL_Console_AllocConsole                           STLSOFT_NS_GLOBAL(AllocConsole)
#endif /* !WINSTL_API_EXTERNAL_Console_AllocConsole */

#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_AttachConsole
#  define WINSTL_API_EXTERNAL_Console_AttachConsole                         STLSOFT_NS_GLOBAL(AttachConsole)
# endif /* !WINSTL_API_EXTERNAL_Console_AttachConsole */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_CreateConsoleScreenBuffer
# define WINSTL_API_EXTERNAL_Console_CreateConsoleScreenBuffer              STLSOFT_NS_GLOBAL(CreateConsoleScreenBuffer)
#endif /* !WINSTL_API_EXTERNAL_Console_CreateConsoleScreenBuffer */

#ifndef WINSTL_API_EXTERNAL_Console_FillConsoleOutputAttribute
# define WINSTL_API_EXTERNAL_Console_FillConsoleOutputAttribute             STLSOFT_NS_GLOBAL(FillConsoleOutputAttribute)
#endif /* !WINSTL_API_EXTERNAL_Console_FillConsoleOutputAttribute */

#ifndef WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacter
# define WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacter             STLSOFT_NS_GLOBAL(FillConsoleOutputCharacter)
#endif /* !WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacter */
#ifndef WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacterA
# define WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacterA            STLSOFT_NS_GLOBAL(FillConsoleOutputCharacterA)
#endif /* !WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacterA */
#ifndef WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacterW
# define WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacterW            STLSOFT_NS_GLOBAL(FillConsoleOutputCharacterW)
#endif /* !WINSTL_API_EXTERNAL_Console_FillConsoleOutputCharacterW */

#ifndef WINSTL_API_EXTERNAL_Console_FlushConsoleInputBuffer
# define WINSTL_API_EXTERNAL_Console_FlushConsoleInputBuffer                STLSOFT_NS_GLOBAL(FlushConsoleInputBuffer)
#endif /* !WINSTL_API_EXTERNAL_Console_FlushConsoleInputBuffer */

#ifndef WINSTL_API_EXTERNAL_Console_FreeConsole
# define WINSTL_API_EXTERNAL_Console_FreeConsole                            STLSOFT_NS_GLOBAL(FreeConsole)
#endif /* !WINSTL_API_EXTERNAL_Console_FreeConsole */

#ifndef WINSTL_API_EXTERNAL_Console_GenerateConsoleCtrlEvent
# define WINSTL_API_EXTERNAL_Console_GenerateConsoleCtrlEvent               STLSOFT_NS_GLOBAL(GenerateConsoleCtrlEvent)
#endif /* !WINSTL_API_EXTERNAL_Console_GenerateConsoleCtrlEvent */

#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAlias
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAlias                       STLSOFT_NS_GLOBAL(GetConsoleAlias)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAlias */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasA
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasA                      STLSOFT_NS_GLOBAL(GetConsoleAliasA)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasA */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasW
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasW                      STLSOFT_NS_GLOBAL(GetConsoleAliasW)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasW */
#endif /* !WINSTL_WIN32_WINNT */

#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliases
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliases                     STLSOFT_NS_GLOBAL(GetConsoleAliases)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliases */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasesA
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasesA                    STLSOFT_NS_GLOBAL(GetConsoleAliasesA)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasesA */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasesW
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasesW                    STLSOFT_NS_GLOBAL(GetConsoleAliasesW)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasesW */
#endif /* !WINSTL_WIN32_WINNT */

#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLength
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLength               STLSOFT_NS_GLOBAL(GetConsoleAliasesLength)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLength */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLengthA
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLengthA              STLSOFT_NS_GLOBAL(GetConsoleAliasesLengthA)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLengthA */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLengthW
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLengthW              STLSOFT_NS_GLOBAL(GetConsoleAliasesLengthW)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasesLengthW */
#endif /* !WINSTL_WIN32_WINNT */

#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasExes
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasExes                   STLSOFT_NS_GLOBAL(GetConsoleAliasExes)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasExes */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesA
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesA                  STLSOFT_NS_GLOBAL(GetConsoleAliasExesA)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesA */
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesW
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesW                  STLSOFT_NS_GLOBAL(GetConsoleAliasExesW)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesW */
#endif /* !WINSTL_WIN32_WINNT */

#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesLength
#  define WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesLength             STLSOFT_NS_GLOBAL(GetConsoleAliasExesLength)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleAliasExesLength */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleCP
# define WINSTL_API_EXTERNAL_Console_GetConsoleCP                           STLSOFT_NS_GLOBAL(GetConsoleCP)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleCP */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleCursorInfo
# define WINSTL_API_EXTERNAL_Console_GetConsoleCursorInfo                   STLSOFT_NS_GLOBAL(GetConsoleCursorInfo)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleCursorInfo */

#if WINSTL_WIN32_WINNT >= 0x0500
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleDisplayMode
#  define WINSTL_API_EXTERNAL_Console_GetConsoleDisplayMode                 STLSOFT_NS_GLOBAL(GetConsoleDisplayMode)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleDisplayMode */
#endif /* !WINSTL_WIN32_WINNT */

#if WINSTL_WIN32_WINNT >= 0x0500
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleFontSize
#  define WINSTL_API_EXTERNAL_Console_GetConsoleFontSize                    STLSOFT_NS_GLOBAL(GetConsoleFontSize)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleFontSize */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleHistoryInfo
# define WINSTL_API_EXTERNAL_Console_GetConsoleHistoryInfo                  STLSOFT_NS_GLOBAL(GetConsoleHistoryInfo)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleHistoryInfo */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleMode
# define WINSTL_API_EXTERNAL_Console_GetConsoleMode                         STLSOFT_NS_GLOBAL(GetConsoleMode)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleMode */

#if WINSTL_WIN32_WINNT >= 0x0600
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleOriginalTitle
#  define WINSTL_API_EXTERNAL_Console_GetConsoleOriginalTitle               STLSOFT_NS_GLOBAL(GetConsoleOriginalTitle)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleOriginalTitle */
# ifndef CONSOLE_external_GetConsoleOriginalTitleA
#  define WINSTL_API_EXTERNAL_Console_GetConsoleOriginalTitleA              STLSOFT_NS_GLOBAL(GetConsoleOriginalTitleA)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleOriginalTitleA */
# ifndef CONSOLE_external_GetConsoleOriginalTitleW
#  define WINSTL_API_EXTERNAL_Console_GetConsoleOriginalTitleW              STLSOFT_NS_GLOBAL(GetConsoleOriginalTitleW)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleOriginalTitleW */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleOutputCP
# define WINSTL_API_EXTERNAL_Console_GetConsoleOutputCP                     STLSOFT_NS_GLOBAL(GetConsoleOutputCP)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleOutputCP */

#if WINSTL_WIN32_WINNT >= 0x0501
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleProcessList
#  define WINSTL_API_EXTERNAL_Console_GetConsoleProcessList                 STLSOFT_NS_GLOBAL(GetConsoleProcessList)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleProcessList */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfo
# define WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfo             STLSOFT_NS_GLOBAL(GetConsoleScreenBufferInfo)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfo */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfoEx
# define WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfoEx           STLSOFT_NS_GLOBAL(GetConsoleScreenBufferInfoEx)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleScreenBufferInfoEx */

#if WINSTL_WIN32_WINNT >= 0x0500
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleSelectionInfo
#  define WINSTL_API_EXTERNAL_Console_GetConsoleSelectionInfo               STLSOFT_NS_GLOBAL(GetConsoleSelectionInfo)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleSelectionInfo */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleTitle
# define WINSTL_API_EXTERNAL_Console_GetConsoleTitle                        STLSOFT_NS_GLOBAL(GetConsoleTitle)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleTitle */
#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleTitleA
# define WINSTL_API_EXTERNAL_Console_GetConsoleTitleA                       STLSOFT_NS_GLOBAL(GetConsoleTitleA)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleTitleA */
#ifndef WINSTL_API_EXTERNAL_Console_GetConsoleTitleW
# define WINSTL_API_EXTERNAL_Console_GetConsoleTitleW                       STLSOFT_NS_GLOBAL(GetConsoleTitleW)
#endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleTitleW */

#if WINSTL_WIN32_WINNT >= 0x0500
# ifndef WINSTL_API_EXTERNAL_Console_GetConsoleWindow
#  define WINSTL_API_EXTERNAL_Console_GetConsoleWindow                      STLSOFT_NS_GLOBAL(GetConsoleWindow)
# endif /* !WINSTL_API_EXTERNAL_Console_GetConsoleWindow */
#endif /* !WINSTL_WIN32_WINNT */

#if WINSTL_WIN32_WINNT >= 0x0500
# ifndef WINSTL_API_EXTERNAL_Console_GetCurrentConsoleFont
#  define WINSTL_API_EXTERNAL_Console_GetCurrentConsoleFont                 STLSOFT_NS_GLOBAL(GetCurrentConsoleFont)
# endif /* !WINSTL_API_EXTERNAL_Console_GetCurrentConsoleFont */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_GetCurrentConsoleFontEx
# define WINSTL_API_EXTERNAL_Console_GetCurrentConsoleFontEx                STLSOFT_NS_GLOBAL(GetCurrentConsoleFontEx)
#endif /* !WINSTL_API_EXTERNAL_Console_GetCurrentConsoleFontEx */

#ifndef WINSTL_API_EXTERNAL_Console_GetLargestConsoleWindowSize
# define WINSTL_API_EXTERNAL_Console_GetLargestConsoleWindowSize            STLSOFT_NS_GLOBAL(GetLargestConsoleWindowSize)
#endif /* !WINSTL_API_EXTERNAL_Console_GetLargestConsoleWindowSize */

#ifndef WINSTL_API_EXTERNAL_Console_GetNumberOfConsoleInputEvents
# define WINSTL_API_EXTERNAL_Console_GetNumberOfConsoleInputEvents          STLSOFT_NS_GLOBAL(GetNumberOfConsoleInputEvents)
#endif /* !WINSTL_API_EXTERNAL_Console_GetNumberOfConsoleInputEvents */

#ifndef WINSTL_API_EXTERNAL_Console_GetNumberOfConsoleMouseButtons
# define WINSTL_API_EXTERNAL_Console_GetNumberOfConsoleMouseButtons         STLSOFT_NS_GLOBAL(GetNumberOfConsoleMouseButtons)
#endif /* !WINSTL_API_EXTERNAL_Console_GetNumberOfConsoleMouseButtons */

#ifndef WINSTL_API_EXTERNAL_Console_GetStdHandle
# define WINSTL_API_EXTERNAL_Console_GetStdHandle                           STLSOFT_NS_GLOBAL(GetStdHandle)
#endif /* !WINSTL_API_EXTERNAL_Console_GetStdHandle */

#ifndef WINSTL_API_EXTERNAL_Console_HandlerRoutine
# define WINSTL_API_EXTERNAL_Console_HandlerRoutine                         STLSOFT_NS_GLOBAL(HandlerRoutine)
#endif /* !WINSTL_API_EXTERNAL_Console_HandlerRoutine */

#ifndef WINSTL_API_EXTERNAL_Console_PeekConsoleInput
# define WINSTL_API_EXTERNAL_Console_PeekConsoleInput                       STLSOFT_NS_GLOBAL(PeekConsoleInput)
#endif /* !WINSTL_API_EXTERNAL_Console_PeekConsoleInput */

#ifndef WINSTL_API_EXTERNAL_Console_ReadConsole
# define WINSTL_API_EXTERNAL_Console_ReadConsole                            STLSOFT_NS_GLOBAL(ReadConsole)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsole */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleA
# define WINSTL_API_EXTERNAL_Console_ReadConsoleA                           STLSOFT_NS_GLOBAL(ReadConsoleA)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleA */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleW
# define WINSTL_API_EXTERNAL_Console_ReadConsoleW                           STLSOFT_NS_GLOBAL(ReadConsoleW)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleW */

#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleInput
# define WINSTL_API_EXTERNAL_Console_ReadConsoleInput                       STLSOFT_NS_GLOBAL(ReadConsoleInput)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleInput */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleInputA
# define WINSTL_API_EXTERNAL_Console_ReadConsoleInputA                      STLSOFT_NS_GLOBAL(ReadConsoleInputA)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleInputA */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleInputW
# define WINSTL_API_EXTERNAL_Console_ReadConsoleInputW                      STLSOFT_NS_GLOBAL(ReadConsoleInputW)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleInputW */

#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleOutput
# define WINSTL_API_EXTERNAL_Console_ReadConsoleOutput                      STLSOFT_NS_GLOBAL(ReadConsoleOutput)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleOutput */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleOutputA
# define WINSTL_API_EXTERNAL_Console_ReadConsoleOutputA                     STLSOFT_NS_GLOBAL(ReadConsoleOutputA)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleOutputA */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleOutputW
# define WINSTL_API_EXTERNAL_Console_ReadConsoleOutputW                     STLSOFT_NS_GLOBAL(ReadConsoleOutputW)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleOutputW */

#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleOutputAttribute
# define WINSTL_API_EXTERNAL_Console_ReadConsoleOutputAttribute             STLSOFT_NS_GLOBAL(ReadConsoleOutputAttribute)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleOutputAttribute */

#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacter
# define WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacter             STLSOFT_NS_GLOBAL(ReadConsoleOutputCharacter)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacter */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacterA
# define WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacterA            STLSOFT_NS_GLOBAL(ReadConsoleOutputCharacterA)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacterA */
#ifndef WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacterW
# define WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacterW            STLSOFT_NS_GLOBAL(ReadConsoleOutputCharacterW)
#endif /* !WINSTL_API_EXTERNAL_Console_ReadConsoleOutputCharacterW */

#ifndef WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBuffer
# define WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBuffer              STLSOFT_NS_GLOBAL(ScrollConsoleScreenBuffer)
#endif /* !WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBuffer */
#ifndef WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBufferA
# define WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBufferA             STLSOFT_NS_GLOBAL(ScrollConsoleScreenBufferA)
#endif /* !WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBufferA */
#ifndef WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBufferW
# define WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBufferW             STLSOFT_NS_GLOBAL(ScrollConsoleScreenBufferW)
#endif /* !WINSTL_API_EXTERNAL_Console_ScrollConsoleScreenBufferW */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleActiveScreenBuffer
# define WINSTL_API_EXTERNAL_Console_SetConsoleActiveScreenBuffer           STLSOFT_NS_GLOBAL(SetConsoleActiveScreenBuffer)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleActiveScreenBuffer */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleCP
# define WINSTL_API_EXTERNAL_Console_SetConsoleCP                           STLSOFT_NS_GLOBAL(SetConsoleCP)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleCP */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleCtrlHandler
# define WINSTL_API_EXTERNAL_Console_SetConsoleCtrlHandler                  STLSOFT_NS_GLOBAL(SetConsoleCtrlHandler)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleCtrlHandler */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleCursorInfo
# define WINSTL_API_EXTERNAL_Console_SetConsoleCursorInfo                   STLSOFT_NS_GLOBAL(SetConsoleCursorInfo)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleCursorInfo */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleCursorPosition
# define WINSTL_API_EXTERNAL_Console_SetConsoleCursorPosition               STLSOFT_NS_GLOBAL(SetConsoleCursorPosition)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleCursorPosition */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleDisplayMode
# define WINSTL_API_EXTERNAL_Console_SetConsoleDisplayMode                  STLSOFT_NS_GLOBAL(SetConsoleDisplayMode)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleDisplayMode */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleHistoryInfo
# define WINSTL_API_EXTERNAL_Console_SetConsoleHistoryInfo                  STLSOFT_NS_GLOBAL(SetConsoleHistoryInfo)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleHistoryInfo */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleMode
# define WINSTL_API_EXTERNAL_Console_SetConsoleMode                         STLSOFT_NS_GLOBAL(SetConsoleMode)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleMode */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleOutputCP
# define WINSTL_API_EXTERNAL_Console_SetConsoleOutputCP                     STLSOFT_NS_GLOBAL(SetConsoleOutputCP)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleOutputCP */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleScreenBufferInfoEx
# define WINSTL_API_EXTERNAL_Console_SetConsoleScreenBufferInfoEx           STLSOFT_NS_GLOBAL(SetConsoleScreenBufferInfoEx)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleScreenBufferInfoEx */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleScreenBufferSize
# define WINSTL_API_EXTERNAL_Console_SetConsoleScreenBufferSize             STLSOFT_NS_GLOBAL(SetConsoleScreenBufferSize)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleScreenBufferSize */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleTextAttribute
# define WINSTL_API_EXTERNAL_Console_SetConsoleTextAttribute                STLSOFT_NS_GLOBAL(SetConsoleTextAttribute)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleTextAttribute */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleTitle
# define WINSTL_API_EXTERNAL_Console_SetConsoleTitle                        STLSOFT_NS_GLOBAL(SetConsoleTitle)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleTitle */

#ifndef WINSTL_API_EXTERNAL_Console_SetConsoleWindowInfo
# define WINSTL_API_EXTERNAL_Console_SetConsoleWindowInfo                   STLSOFT_NS_GLOBAL(SetConsoleWindowInfo)
#endif /* !WINSTL_API_EXTERNAL_Console_SetConsoleWindowInfo */

#if WINSTL_WIN32_WINNT >= 0x0500
# ifndef WINSTL_API_EXTERNAL_Console_SetCurrentConsoleFontEx
#  define WINSTL_API_EXTERNAL_Console_SetCurrentConsoleFontEx               STLSOFT_NS_GLOBAL(SetCurrentConsoleFontEx)
# endif /* !WINSTL_API_EXTERNAL_Console_SetCurrentConsoleFontEx */
#endif /* !WINSTL_WIN32_WINNT */

#ifndef WINSTL_API_EXTERNAL_Console_SetStdHandle
# define WINSTL_API_EXTERNAL_Console_SetStdHandle                           STLSOFT_NS_GLOBAL(SetStdHandle)
#endif /* !WINSTL_API_EXTERNAL_Console_SetStdHandle */

#ifndef WINSTL_API_EXTERNAL_Console_WriteConsole
# define WINSTL_API_EXTERNAL_Console_WriteConsole                           STLSOFT_NS_GLOBAL(WriteConsole)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsole */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleA
# define WINSTL_API_EXTERNAL_Console_WriteConsoleA                          STLSOFT_NS_GLOBAL(WriteConsoleA)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleA */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleW
# define WINSTL_API_EXTERNAL_Console_WriteConsoleW                          STLSOFT_NS_GLOBAL(WriteConsoleW)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleW */

#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleInput
# define WINSTL_API_EXTERNAL_Console_WriteConsoleInput                      STLSOFT_NS_GLOBAL(WriteConsoleInput)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleInput */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleInputA
# define WINSTL_API_EXTERNAL_Console_WriteConsoleInputA                     STLSOFT_NS_GLOBAL(WriteConsoleInputA)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleInputA */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleInputW
# define WINSTL_API_EXTERNAL_Console_WriteConsoleInputW                     STLSOFT_NS_GLOBAL(WriteConsoleInputW)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleInputW */

#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleOutput
# define WINSTL_API_EXTERNAL_Console_WriteConsoleOutput                     STLSOFT_NS_GLOBAL(WriteConsoleOutput)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleOutput */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleOutputA
# define WINSTL_API_EXTERNAL_Console_WriteConsoleOutputA                    STLSOFT_NS_GLOBAL(WriteConsoleOutputA)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleOutputA */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleOutputW
# define WINSTL_API_EXTERNAL_Console_WriteConsoleOutputW                    STLSOFT_NS_GLOBAL(WriteConsoleOutputW)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleOutputW */

#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleOutputAttribute
# define WINSTL_API_EXTERNAL_Console_WriteConsoleOutputAttribute            STLSOFT_NS_GLOBAL(WriteConsoleOutputAttribute)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleOutputAttribute */

#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacter
# define WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacter            STLSOFT_NS_GLOBAL(WriteConsoleOutputCharacter)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacter  */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacterA
# define WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacterA           STLSOFT_NS_GLOBAL(WriteConsoleOutputCharacterA)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacter A */
#ifndef WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacterW
# define WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacterW           STLSOFT_NS_GLOBAL(WriteConsoleOutputCharacterW)
#endif /* !WINSTL_API_EXTERNAL_Console_WriteConsoleOutputCharacter W */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_API_external_h_Console */

/* ///////////////////////////// end of file //////////////////////////// */
