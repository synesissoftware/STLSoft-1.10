
add_executable(test.scratch.unixstl.synch.semaphore
    main.cpp
)

target_compile_options(test.scratch.unixstl.synch.semaphore PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-declarations
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

