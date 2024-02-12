
add_executable(test.unit.stlsoft.memory.auto_buffer
    entry.cpp
)

target_link_libraries(test.unit.stlsoft.memory.auto_buffer
    xTests::xTests.core
)

target_compile_options(test.unit.stlsoft.memory.auto_buffer PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        ${GCC_WARN_NO_cxx11_long_long}
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #



