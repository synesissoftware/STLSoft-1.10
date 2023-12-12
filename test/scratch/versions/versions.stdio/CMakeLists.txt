
add_executable(test.scratch.versions.stdio
versions.c
)

# target_link_libraries(test.scratch.versions.stdio
#     xTests
# )

target_compile_options(test.scratch.versions.stdio PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wextra -pedantic>
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

