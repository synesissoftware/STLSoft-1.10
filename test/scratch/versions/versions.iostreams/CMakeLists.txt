
add_executable(test.scratch.versions.iostreams
    versions.cpp
)

# target_link_libraries(test.scratch.versions.iostreams
#     xTests
# )

target_compile_options(test.scratch.versions.iostreams PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wextra -pedantic>
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

