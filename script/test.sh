#!/bin/bash
set -eoux pipefail
###
# @Github: https://github.com/Certseeds/CS203_DSAA_template
# @Organization: SUSTech
# @Author: nanoseeds
# @Date: 2020-07-27 21:48:41
 # @LastEditors: nanoseeds
 # @LastEditTime: 2021-01-04 00:32:11
###
cmake_path="cmake_build_path"
function cmake_make() {
    mkdir -p ./"${cmake_path}"
    cd ./"${cmake_path}"
    cmake ..
    make -j"$(nproc)"
    # now at ./../cmake_build_path
}
function main() {
    make test
    cd ..
    # now at ./../
}
function finish() {
    rm -rf "${scratch}"
}
# now in ./
cd ..
scratch="$(pwd)/${cmake_path}"
trap finish EXIT
cmake_make
main
