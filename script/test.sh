#!/bin/bash
set -eoux pipefail
###
# @Github: https://github.com/Certseeds/CS203_DSAA_template
# @Organization: SUSTech
# @Author: nanoseeds
# @Date: 2020-07-27 21:48:41
 # @LastEditors: nanoseeds
 # @LastEditTime: 2020-08-06 23:50:29
###
function cmake_make() {
  mkdir ./cmake_build_path
  cd ./cmake_build_path
  cmake ..
  make
  # now at ./../cmake_build_path
}
function main() {
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
  {
    cd ./tree
    ./${prefix}_tree
    {
      cd ./RBTree
      ./${prefix}_tree_RBTree
      cd ..
    }
    cd ..
  }
  cd ..
  # now at ./../cmake_build_path
}
function finish() {
  rm -rf "$scratch"
}
# now in ./
cd ..
scratch="$(pwd)"/cmake_build_path
trap finish EXIT
cmake_make
main
