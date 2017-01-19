# STLSoft 1.10

**STLSoft** is a suite of libraries that provides:

 - STL extensions;
 - General-purpose utility components;
 - Facades over operating-system and technology-specific APIs.

The overarching characteristic of STLSoft is that it is *lightweight*. That
sounds great, but what does it actually mean? Specifically, the STLSoft
libraries share the following characteristics:

- "**100% header-only**" - all components within the libraries are entirely
   defined within header files, meaning that users need only \#include the
   requisite files to access the functionality.
- "**Intersecting Conformance**" -  similar, but not-identical, components
   from different projects (e.g. UNIXSTL and WinSTL) are structurally
   conformant (they share compatible syntax, and corresponding semantics,
   without being related by type) only to the degree of the intersection of
   identical functionality, rather than employing significant additional
   functionality to achieve total structural conformance. For example,
   though both the `unixstl::filesystem_traits` and
   `winstl::filesystem_traits` traits classes provide the `stat()`
   and `f!stat()` operations, `lstat()` is provided only
   by `unixstl::filesystem_traits`.
- **Maximum Cohesion with Minimal Coupling** - achieved by extensive
  use of generalising mechanisms, particularly "*shims*", e.g. types that
  manipulate character strings are able to interact with arbitrary string
  types, not just `char const*` and `std::string`.
- **Very High Efficiency** - Second only to *Robustness*, all components
  in the libraries are implemented with a view to maximum efficient. This is
  aided by the extensive use of efficient utility classes, such as
  `stlsoft::auto_buffer`
  and
  `stlsoft::scoped_handle`

It is important to note that *STLSoft is not a framework*. Each library
component is as "thin" as possible to provide its given function. The intent
is that STLSoft components are used as building blocks for writing higher
level components - applications, classes, libraries, servers. STLSoft has
been used extensively in the development of software in all these guises.

... more information TBC as we move towards a full (non-beta) release
