
#include <stlsoft/stlsoft.h>

#include <iomanip>
#include <iostream>


int main(int /* argc */, char* /* argv */[])
{
    std::cout
        << "__cplusplus = "
        << __cplusplus
        << std::endl
        ;

    std::cout
        << "STLSoft = "
        << ((_STLSOFT_VER >> 24) & 0xff)
        << "."
        << ((_STLSOFT_VER >> 16) & 0xff)
        << "."
        << ((_STLSOFT_VER >> 8) & 0xff)
        << "."
        << ((_STLSOFT_VER >> 0) & 0xff)
        << std::endl
        ;
    std::cout
        << "_STLSOFT_VER = 0x"
        << std::hex << std::setfill('0') << std::setw(8) << _STLSOFT_VER
        << std::endl
        ;
    std::cout
        << "STLSOFT_COMPILER_VERSION_STRING = "
        << STLSOFT_COMPILER_VERSION_STRING
        << std::endl
        ;
    ;

    return 0;
}

