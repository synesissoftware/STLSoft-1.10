#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build

Directories=(CMakeFiles examples projects test)
Files=(CMakeCache.txt Makefile cmake_install.cmake)


if [ -d $CMakePath ]; then

    cd $CMakePath || exit 0

    echo "Removing all cmake artefacts"

    for d in ${Directories[@]} ; do rm -dfr "$d" ; done

    for f in ${Files[@]} ; do rm -f "$f" ; done
fi

