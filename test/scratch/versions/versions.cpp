
#include <stlsoft/stlsoft.h>

#include <stdio.h>


int main(int argc, char* argv[])
{
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);

    fprintf(
        stderr
    ,   "STLSoft = %d.%d.%d.%d\n"
    ,   (_STLSOFT_VER >> 24) & 0xff
    ,   (_STLSOFT_VER >> 16) & 0xff
    ,   (_STLSOFT_VER >> 8) & 0xff
    ,   (_STLSOFT_VER >> 0) & 0xff
    );
    fprintf(
        stderr
    ,   "_STLSOFT_VER = 0x%04x%04x\n"
    ,   static_cast<unsigned int>((_STLSOFT_VER >> 16) & 0xffff)
    ,   static_cast<unsigned int>((_STLSOFT_VER >> 0) & 0xffff)
    );
    fprintf(
        stderr
    ,   "STLSOFT_COMPILER_VERSION_STRING = %s\n"
    ,   STLSOFT_COMPILER_VERSION_STRING
    );

    return 0;
}

