
add_executable(test.unit.stlsoft.string.string_view
    entry.cpp
)

target_link_libraries(test.unit.stlsoft.string.string_view
    xTests::xTests.core
)

target_compile_options(test.unit.stlsoft.string.string_view PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-unused-function
        -Wno-unused-value

        ${GCC_WARN_NO_cxx11_long_long}
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

