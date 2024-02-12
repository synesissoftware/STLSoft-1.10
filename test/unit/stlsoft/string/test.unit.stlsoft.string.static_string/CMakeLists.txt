
add_executable(test.unit.stlsoft.string.static_string
    entry.cpp
)

target_link_libraries(test.unit.stlsoft.string.static_string
    xTests::xTests.core
)

target_compile_options(test.unit.stlsoft.string.static_string PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        ${GCC_WARN_NO_cxx11_long_long}
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #


