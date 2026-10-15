/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/smoke/test.scratch.smoke.c/main.c
 *
 * Purpose: Compile/link smoke for C headers and compiler recognition.
 *
 * Created: 15th October 2026
 * Updated: 15th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */

#include <stlsoft/stlsoft.h>

#include <stdio.h>


int main(int argc, char* argv[])
{
    ((void)argc);
    ((void)argv);

    printf(
        "test.scratch.smoke.c: %s / %s\n"
    ,   STLSOFT_COMPILER_LABEL_STRING
    ,   STLSOFT_COMPILER_VERSION_STRING
    );

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */
