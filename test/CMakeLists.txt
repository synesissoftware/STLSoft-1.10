
include_directories(${CMAKE_SOURCE_DIR}/include)

if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
endif()

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif()

add_subdirectory(scratch)


# ############################## end of file ############################# #

