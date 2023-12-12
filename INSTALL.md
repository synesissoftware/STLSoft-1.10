============================================================================
STLSoft - Install

; Created:  29th March 2002
; Updated:  4th January 2021

============================================================================

 STLSoft is a 100% header-only library, and so requires no building.

 It is recommended that you define an STLSOFT environment variable.

 For example, if you're using UNIX and you install
  to /usr/local/stlsoft/stlsoft-1.10.1 then you should set the environment
  variable STLSOFT to /usr/local/stlsoft/stlsoft-1.10.1 in which case the
  file stlsoft/stlsoft.h, for example, will be located in
  $STLSOFT/include/stlsoft/stlsoft.h

 Conversely, if you're using Windows and you intall
  to C:\3pty\STLSoft\stlsoft-1.10.1 then you should set the environment
  variable STLSoft to C:\3pty\STLSoft\stlsoft-1.10.1 in which case the
  file stlsoft/stlsoft.h, for example, will be located in
  C:\3pty\STLSoft\stlsoft-1.10.1\stlsoft\stlsoft.h

 The makefiles / project files of several other open-source projects expect
 this symbol, including:

  * b64             https://github.com/synesissoftware/b64
  * CLASP           https://github.com/synesissoftware/CLASP
  * ExpCxxLib       tbc
  * FastFormat      https://github.com/synesissoftware/FastFormat
  * libCLImate      https://github.com/synesissoftware/libCLImate
  * Pantheios       https://github.com/synesissoftware/Pantheios
  * recls           https://github.com/synesissoftware/recls
  * shwild          https://github.com/synesissoftware/shwild
  * VOLE            https://github.com/synesissoftware/VOLE
  * xContract       https://github.com/synesissoftware/xcontract
  * xCover          https://github.com/synesissoftware/xcover
  * xTests          https://github.com/synesissoftware/xtests

 If you're using STLSoft on UNIX, you might want to apply dos2unix over all
 the files before using it. You *must* do this if you're using the SunPro
 C compiler - this action is carried out automatically, for example, by the
 Pantheios makefile(s).

=============================== end of file ================================

