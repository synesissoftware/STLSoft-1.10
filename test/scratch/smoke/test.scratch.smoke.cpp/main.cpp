/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/smoke/test.scratch.smoke.cpp/main.cpp
 *
 * Purpose: Compile/link smoke for C++ headers, MSVC recognition, and
 *          standard-library discrimination (incl. modern MSVC STL).
 *
 * Created: 15th October 2026
 * Updated: 15th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */

#include <stlsoft/stlsoft.h>

#include <stlsoft/util/std/library_discriminator.hpp>

#if defined(_WIN32) || \
    defined(WIN32)
# include <winstl/winstl.h>
#elif defined(unix) || \
      defined(UNIX) || \
      defined(__unix__) || \
      defined(__unix) || \
      defined(__APPLE__) || \
      defined(__MACH__)
# include <unixstl/unixstl.h>
#else
# include <platformstl/platformstl.h>
#endif

#include <iostream>


int main(int argc, char* argv[])
{
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);

    std::cout
        << "test.scratch.smoke.cpp: "
        << STLSOFT_COMPILER_LABEL_STRING
        << " / "
        << STLSOFT_COMPILER_VERSION_STRING
#ifdef STLSOFT_CF_STD_LIBRARY_NAME_STRING
        << " ; stdlib="
        << STLSOFT_CF_STD_LIBRARY_NAME_STRING
#endif
        << std::endl;

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */
