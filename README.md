# STLSoft-1.10

Version 1.10 of STLSoft libraries

## Current Status (July 2020)

**NOTE:** **STLSoft** version **1.10** as obtained from [its Github repository](https://github.com/synesissoftware/STLSoft-1.10) is not yet released as a non-beta. Users should **not** obtain the **master** branch, but should instead use the [latest beta](https://github.com/synesissoftware/STLSoft-1.10/releases) of [STLSoft, v 1.10] branch. Each beta-branch contains a full set of all **STLSoft** library components current at the time of its released.

### Impending 1.10 release

Working now (October 2019) on getting documentation updated and existing
automated tests included into the GitHub-released project, and then
we'll be at it.


## Releases

### 1.10.1 beta-19 (Latest) - 4th July 2020

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta19>

* added ``stlsoft::t2w``, ``stlsoft::w2t``, ``stlsoft::t2a``, ``stlsoft::a2t`` for upcoming Pantheios release
* added stream insertion operator (generic) for string slice types
* added compatibility with Visual C++ 15.x and 16.x
* added support for the ARM architecture (christopherplawrence)

### 1.10.1 beta-18 - 31st October 2019

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta18>

* added stlsoft/system/environment/functions.hpp to enhance ``stlsoft::environment_variable_exists()`` with string access shims to support arbitrary string type
* remove vestigial (and erroneous) winstl/string/spin_policies.hpp
* various documentation fixes

### 1.10.1 beta-17 - 24th October 2019

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta17>

* GCC 8 compatibility
* GCC 9 compatibility
* implemented ``WinSTL_C_FileInformation_get_SECURITY_DESCRIPTOR_w()``
* improved documentation

### 1.10.1 beta-16 - 13th October 2019

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta16>

* added ``stlsoft_C_environment_variable_exists_a()`` / ``environment_variable_exists()`` (from STLSoft 1.10-alpha)
* added ``stlsoft::count_bits(int)`` overload
* added ``cbegin()``, ``cend()``, ``crbegin()``, ``crend()`` to ``platformstl::environment_map``
* significant additions and removals of WinSTL file creation functions
* added WinSTL security functions (from STLSoft 1.10-alpha)
* automatic recognising Mac OSX architecture as UNIX
* canonicalising '\file' description sections
* suppresses deprecation warning from reporting use of deprecated functions inside other deprecated functions

### 1.10.1 beta-15 - 13th September 2019

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta15>

 * added ``stlsoft::fast_strftime()`` and ``stlsoft::fast_wcsftime()`` as (partial) drop-in replacements for ``std::strftime()`` and ``std::wcsftime()``
 * added ``stlsoft::get_ptr()`` attribute shim overloads for ``std::shared_ptr`` and ``std::unique_ptr``
 * added ``stlsoft::get_top()`` attribute shim
 * added ``stlsoft::basic_string_view<>::substr()``
 * added ``winstl_C_format_message_strerror_w()``
 * removed ``stlsoft::literal_cast<>``
 * various portability improvements to newer compilers

### 1.10.1 beta-14 - 4th August 2019

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta14>

 * added ``SECURITY_DESCRIPTOR`` helpers()
 * ``stlsoft::w2m`` and ``stlsoft::m2w`` now more general

### 1.10.1 beta-13 - 16th April 2019

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta13>

 * fixed ``STLSOFT_ALWAYS_FALSE()`` / ``STLSOFT_ALWAYS_TRUE()``
 * ``platformstl::FILE_stream`` : ~ fixing character-encoding function selection defect
 * canonicalising source file structure

### 1.10.1 beta-12 - 26th December 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta12>

 * added ``sas_to_string()`` (and related) functions
 * added ``stlsoft::errno_exception`` (from 1.12 branch)
 * added ``stlsoft::locale_scope``
 * STLSoft's ``struct tm`` String Access Shims now work for arbitrary locale
 * UNIXSTL's ``timeval`` String Access Shims now work for arbitrary locale

### 1.10.1 beta-11 - 22nd December 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta11>

 * ``stlsoft::ref_ptr`` : + ``borrow()``; + ``own()``
 * UNIXSTL special string instances : + added standard string access shims
 * ``winstl::environment_variable`` : + ``data()``; + ``equal()``; + ``equal_ignore_case()``; + ``exists()``; + ``operator`` ``==()`` and ``!=()``

### 1.10.1 beta-10 - 20th December 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta10>

 * ``winstl::process_mutex()`` now takes an optional EVENT handle which will be signalled if the mutex experiences an abandoned acquire
 * ``special_string_instance`` now provides generic (SAS) (in)equality operators automatically
 * ``try_parse_to_bool()`` semantics firmed up

### 1.10.1 beta-9 - 12th June 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta9>

 * Borland compatibility

### 1.10.1 beta-8 - 11th June 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta8>

 * fixing break to UNIX-compatibility introduced in beta-6/7

### 1.10.1 beta-7 - 9th June 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta7>

 * ``auto_buffer<>`` now supports limited form of pointer arithmethic via ``operator -()``
 * added subscript operator for ``auto_array_destructor<>``
 * VC++ 14.1x compatibility
 * refactoring of copy-proscriptions

### 1.10.1 beta-6 - 9th June 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta6>

 * refactored in terms of external API
 * removed empty/meaningless "compatibility" sections
 * canonicalising proscribed construction methods
 * simplifying, and prospective changes (for getting to 1.12)

