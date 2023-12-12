============================================================================
STLSoft - FAQ

; Created:  29th March 2002
; Updated:  4th January 2021

============================================================================



The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/STLSoft-1.10/issues)
it will be used to create one.

FAQs:
=====

Q1: "How do I build STLSoft?"

A1:
  You don't: STLSoft is 100% header-only, so all you have to do is #include
  it. We do recommend that you use an environment variable, e.g. STLSOFT, so
  that you can use new versions of the library from your projects without
  disruption.


Q2: "How do I install STLSoft?"

A2:
  There are a few simple steps, depending on how you obtain it.

  If you obtain the latest release as an archive, then:

    1. Download the latest distribution of STLSoft, e.g. from GitHub, as in
        https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta26

    2. Unzip it to a directory of your choice, e.g /3pty/STLSoft-1.10-1.10.1-beta25

    3. Define an environment variable STLSOFT, whose value is the directory
       in which you unzipped it, e.g. STLSOFT=/3pty/STLSoft-1.10-1.10.1-beta25,
       and then specify $(STLSOFT)/include or %STLSOFT%\include in your project
       files and makefiles

  If you obtain the latest beta as a Git clone from the project site on
  GitHub - https://github.com/synesissoftware/STLSoft-1.10 - then:

    1. Determine the branch in which you're interested, e.g. beta-26

    2. Clone it, as in:

        $ git clone --branch beta-25 https://github.com/synesissoftware/STLSoft-1.10/ ./STLSoft-1.10-b25

      or

        > git clone --branch beta-25 https://github.com/synesissoftware/STLSoft-1.10/ .\STLSoft-1.10-b25

    3. Define an environment variable STLSOFT, whose value is the directory
       in which you unzipped it, e.g. STLSOFT=/3pty/STLSoft-1.10-b25, and
       then specify $(STLSOFT)/include or %STLSOFT%\include in your project
       files and makefiles

Q3: "How do I use STLSoft?"

A3:
  Assuming you've installed it (as per instructions A2):

  In your IDE settings, add the include directory $(STLSOFT)/include, OR in
  your makefiles, add the include directory:
    * -I$STLSOFT/include (if you're on UNIX), OR
    * -I%STLSOFT%/include (if you're on Windows)


Q4: "Does STLSoft have unit-tests?"

A4:
  Yes, there are *MANY* such, but for various reasons they're not available
  with the STLSoft 1.10 distribution. When STLSoft 1.11 is released it will
  include unit-tests, which will likely be a mix of xTests and Catch
  unit-test libraries, both of which will be bundled with the distribution.

=============================== end of file ================================

