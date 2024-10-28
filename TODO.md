# STLSoft - TODO

**NOTE**: some of the following are very old, stretching back even into the 2000s, so this list will be updated a lot over the coming months. The most glaring of these is to ensure compatiblity with C++-14/17/20 as is necessary.

## STLSoft 1.10.x TODOs:

 * centralise `mbstowcs`/`mbstowcs_s` and `wcstombs`/`wcstombs_s` in single function
 * ~~final filesystem fixes (found during testing of [**recls**](https://github.com/synesissoftware/recls) 1.10's significantly improved functionality)~~ - ✅
 * have `basic_path_buffer` use pre and post eye-catcher (`STLSOFT_DEBUG`-only)
 * take down https://github.com/synesissoftware/STLSoft-1.10-delta
 * update the downloads on SourceForge
 * flesh out [**README.md**](./README.md)
 * sort the SourceForge site
 * ~~CMake~~ - ✅
 * VC++ common makefile(s)
 * STLSoft 1.10-related blog posts (focusing on new components)
 * ~~apply `stlsoft::unit::string_insert()` to UNIXSTL/WinSTL `basic_path<>`~~ - ✅
 * `invoke_ACE_OS_snprintf` should be implemented in terms of `stlsoft_C_snprintf()`
 * `invalid_integral_range_policy::operator ()` should be implemented in terms of `stlsoft_C_snprintf()`
 * ~~C++ 11/14/17/20 compatibility - partial~~ - ✅
 * optimise `char_traits<>` and/or `pod_fill_n()` block operations (e.g. in terms of `mem***()`)
 * standard names of integer-to-string and string-to-integer to allow for coming enhancements for multiple bases
 * `stlsoft::auto_buffer<>::copy_from()` should be template and work with other instances (with different `V_internalSize`)
 * GitHub README.md image features - version, build, etc;
 * hash specialisations for all possible key types (incl. `stlsoft::basic_simple_string<>`, etc.);
 * better documentation markup for `stlsoft::translate_thousands()`, `stlsoft::format_thousands()`, `stlsoft::integer_to_lc_string()`, `winstl::format_thousands()`, ...
 * apply `stlsoft::string_insert()` to **WinSTL** time type shims;
 * fix Doxygen build;



## STLSoft 1.11+ TODOs:

 * move include/stlsoft/util/string/*printf.h code to api/internal, and deprecate
 * same with the include/stlsoft/std/* files
 * rename all HAS files to remove the trailing _ (as that _might_ conflict with actual symbols; in any case, have the header name exact). Maybe further disambiguate with has_file/... and has_construct/...
 * DO NOT just branch over; instead, take each component at a time and consider files such as include/stlsoft/util/std/stdio_overload_detectors.hpp even still having a purpose - Maybe this is a 1.12 thing?
 * include/*stl*/error => include/*stl*/diagnostics
 * deprecate various iterator types ...
 * syslog in variadic templates, a la `winstl::output_debug_line()`
 * find all `STLSOFT_USING_SAFE_STR_FUNCTIONS` and abstract all code to worker functions
 * canonicalise all exception messages - consistency, lower-case, etc.
 * memory-mapped-file class minor issues
 * integrate **STLSoft**'s exception-hierarchies with new standard exception design
 * C++ 11/14/17/20 compatibility - partial; further coming in 1.12
 * bring in platformstl::properties_file from 1.12 project
 * further system_traits refactoring:
   - joining common code via **CRTP**
   - abstracting out string stuff (into `stlsoft::`)
   - sorting the "safe-string" stuff
 * Documentation improvements
 * Website - currenty http://stlsoft.org/ is *VERY* out of date
 * Set-up donation


## abandoned TODOs:

 * custom radix in integer_to_string - abandoned for performance reasons, and obviated by new conversion functions (oct, dec, hex) in 1.10


<!-- ########################### end of file ########################### -->

