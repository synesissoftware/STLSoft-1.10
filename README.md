# STLSoft-1.10

Version 1.10 of STLSoft libraries

## Current Status (January 2021)

**NOTE:** **STLSoft** version **1.10** as obtained from [its Github repository](https://github.com/synesissoftware/STLSoft-1.10) is not yet released as a non-beta. Users should **not** obtain the **master** branch, but should instead use the [latest beta](https://github.com/synesissoftware/STLSoft-1.10/releases) of [STLSoft, v 1.10] branch. Each beta-branch contains a full set of all **STLSoft** library components current at the time of its release.

### Impending 1.10 release

Working now (January 2021) on the 1.10 release candidate, and expect to be done this month.


## Releases

### 1.10.1 beta-26 (Latest) - 4th January 2021

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta26>

* added (**UNIXSTL** and **WinSTL**) **Path Classification API** (from 1.12 work), which work with Windows UNC and long-path root designators and all slash conventions
* added (**UNIXSTL** and **WinSTL**) **path parsing function** - **include/???stl/filesystem/path_parse_functions.h**, presenting a consistent set of functions centralised from disparate parts of the libraries
* **BREAKING CHANGES**: (**UNIXSTL** and **WinSTL**) ``basic_path<>`` methods ``get_file()`` and ``get_ext()`` now return slices, and ``get_ext()`` changed semantics to include ``'.'``
* (**UNIXSTL** and **WinSTL**) ``basic_path<>`` added move semantics and ``get_location()`` method and made ``swap()`` method public, as well as numerous defect fixes and consistency improvements implemented in terms of new **Path Classification API**
* (**UNIXSTL** and **WinSTL**) ``filesystem_traits<>`` added path classification and path parsing methods, as well as numerous defect fixes
* updated copyright info for all files, from **Synesis Software** to **Synesis Information Systems**
* ``stlsoft::basic_path_buffer<>`` added ``resize()``, ``back()``, ``front()`` methods
* added ``stlsoft_C_(str|wcs)nicmp()``
* raw (C) string slice types moved out of ``stlsoft::`` namespace in C++
* C++14 compatibility
* a whole lot of work to reduce dependencies
* many improvements to **GCC** compatibility
* all uses of ``memcpy()`` and ``memset()`` now in terms of abstractions (in **stlsoft/api/internal/memfns.h**)
* **BREAKING CHANGES**: ~ abstracted out string-handling from ``???stl::system_traits<>`` into ``stlsoft::c_string_traits<>``, and removed several unused (and sketchy) functions

### 1.10.1 beta-25 - 14th December 2020

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta25>

* added two more files missing from beta 23 - D'oh!

### 1.10.1 beta-24 - 13th December 2020

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta24>

* added file unixstl/filesystem/path_buffer.hpp missing from beta 23

### 1.10.1 beta-23 - 13th December 2020

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta23>

* ``basic_file_path_buffer<>`` is now deprecated in all projects, and all dependent components are modified to use other facilities
* added ``platformstl::environment_variable<>`` class template
* added (in)equality operators for ``stlsoft::error_desc``
* added ``stlsoft::basic_path_buffer<>`` component, as an alternative to ``basic_file_path_buffer<>``
* ``stlsoft::auto_buffer<>`` class template ``copy_from()`` method, and ctor and ``resize()`` method that take value for initialisation of (new) elements
* added ``stlsoft::strnpbrkn()``/``wcsnpbrkn()`` (and added ``stlsoft_C_``(``str``|``wcs``)``npbrkn()``)
* added move constructor to ``unixstl::module`` and ``winstl::module``
* large number of new methods and defect fixes in (``platformstl``|``unixstl``|``winstl``)``::filesystem_traits``
* large number of new methods and defect fixes in (``platformstl``|``unixstl``|``winstl``)``::system_traits``


### 1.10.1 beta-22 - 29th November 2020

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta22>

* added ``stlsoft::string_to_integer_range()``
* added ``stlsoft::strnchr()``, ``stlsoft::strnistrn()``, ``stlsoft::strnstrn()`` C-style string search functions
* added move constructor to ``stlsoft::auto_buffer<>``
* added move constructor for ``stlsoft::scoped_handle<>``
* added move constructor for ``stlsoft::(basic_)simple_string<>``
* ``winstl::output_debug_line()`` overloads expanded to 16-parameters, and changed to use variadic templates where supported
* ``stlsoft::split()`` functions enhanced to: return vector of arbitrary length; allow heterogeneous types for the split elements
* ``stlsoft::string_switch()`` split into two overloads to handle property and unambiguously flag enums, regular enums, and enum classes
* significant, BREAKING changes to ``stlsoft::try_parse_to()`` overloads to avoid ambiguity
* changed significantly the way in which ``stlsoft::cstring_maker`` works, and adjusted all dependent code
* various additions for compatibility with ``std::string_view`` (which is very similar to ``stlsoft::string_view``)
* fixed case of a bunch of headers


### 1.10.1 beta-21 - 27th July 2020

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta21>

* VC++ 15/16 compatibility
* fixed ``unixstl::readdir_sequence::empty()``

### 1.10.1 beta-20 - 4th July 2020

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta20>

* fixed detecton of ``std::shared_ptr`` and ``std::unique_ptr``

### 1.10.1 beta-19 - 4th July 2020

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

