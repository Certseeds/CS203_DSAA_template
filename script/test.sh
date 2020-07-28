#!/bin/bash
set -eoux pipefail
###
# @Github: https://github.com/Certseeds/CS203_DSAA_template
# @Organization: SUSTech
# @Author: nanoseeds
# @Date: 2020-07-27 21:48:41
 # @LastEditors: nanoseeds
 # @LastEditTime: 2020-07-28 14:23:01
###
main() {
    old_env=$(pwd)
    prefix="basic_algorithms"
    ./CS203_DSAA_template_test
    cd ./algorithm
    {
        cd ./sort
        ./${prefix}_sort
        cd ..
    }
    {
        cd ./binary_search
        ./${prefix}_binary_search
        cd ..
    }
    cd ..
    # now at ./../cmake_build_path
}
try_mkdir() {
    cd ./..
    if [ ! -d "cmake_build_path" ]; then
        mkdir ./cmake_build_path
    fi
    cd ./cmake_build_path
    cmake ..
    make
    # now at ./../cmake_build_path
}
clear(){
    cd ..
    rm -rf "cmake_build_path"
    # now at ./../
}
# now in ./
try_mkdir
main
clear