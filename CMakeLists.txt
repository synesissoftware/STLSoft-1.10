
cmake_minimum_required(VERSION 3.0)

project(stlsoft)

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif()

foreach(ITEM
        stlsoft
        platformstl
        unixstl
        )

    install(
        DIRECTORY ${CMAKE_SOURCE_DIR}/include/${ITEM}/
        DESTINATION include/${ITEM}/
        FILES_MATCHING PATTERN "*.h*"
	)
endforeach()

