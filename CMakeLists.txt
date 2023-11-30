
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

project(stlsoft)


include_directories(include)

if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
endif()

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif()


add_subdirectory(test)



foreach(ITEM
    stlsoft
    platformstl
    unixstl
)

    install(
        DIRECTORY ${CMAKE_SOURCE_DIR}/include/${ITEM}/
        DESTINATION include/${ITEM}/
        FILES_MATCHING
        PATTERN "*.h*"
    )
endforeach()

