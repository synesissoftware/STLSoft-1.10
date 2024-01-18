
add_executable(test.unit.stlsoft.containers.pod_vector
    entry.cpp
)

target_link_libraries(test.unit.stlsoft.containers.pod_vector
    xTests::xTests.core
)

target_compile_options(test.unit.stlsoft.containers.pod_vector PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #



