#!/bin/bash
set -eoux pipefail
###
# @Github: https://github.com/Certseeds/CS203_DSAA_template
# @Organization: SUSTech
# @Author: nanoseeds
# @Date: 2020-07-27 21:48:41
 # @LastEditors: nanoseeds
 # @LastEditTime: 2020-07-27 22:33:04
###
main() {
    old_env=$(pwd)
    echo "${old_env}"
    cd ./../cmake_build_path
    prefix="basic_algorithms"
    ./CS203_DSAA_template_test
    cd ./algorithm
    {
        cd ./sort
        ./${prefix}_sort
        cd ..
    }
    {
        cd ./binary_searchs
        ./${prefix}_binary_search
        cd ..
    }
    cd "${old_env}"
}

main
