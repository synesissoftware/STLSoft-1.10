#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


mkdir -p $CMakePath || exit 1

cd $CMakePath





echo "Executing make (clean)"

make clean

cd ->/dev/null

ls -al $CMakePath

