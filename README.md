# STLSoft-1.10

Version 1.10 of STLSoft libraries

# Releases

## 1.10.1 beta-12 (Latest) - 26th December 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta12>

 * added sas_to_string() (and related) functions
 * added stlsoft::errno_exception (from 1.12 branch)
 * added stlsoft::locale_scope
 * STLSoft's struct tm String Access Shims now work for arbitrary locale
 * UNIXSTL's timeval String Access Shims now work for arbitrary locale

## 1.10.1 beta-11 - 22nd December 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta11>

 * stlsoft::ref_ptr : + borrow(); + own()
 * UNIXSTL special string instances : + added standard string access shims
 * winstl::environment_variable : + data(); + equal(); + equal_ignore_case(); + exists(); + operators ==() and !=()

## 1.10.1 beta-10 - 20th December 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta10>

 * winstl::process_mutex() now takes an optional EVENT handle which will be signalled if the mutex experiences an abandoned acquire
 * special_string_instance now provides generic (SAS) (in)equality operators automatically
 * try_parse_to_bool() semantics firmed up

## 1.10.1 beta-9 - 12th June 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta9>

 * Borland compatibility

## 1.10.1 beta-8 - 11th June 2018

<https://github.com/synesissoftware/STLSoft-1.10/releases/tag/1.10.1-beta8>

 * fixing break to UNIX-compatibility introduced in beta-6/7

