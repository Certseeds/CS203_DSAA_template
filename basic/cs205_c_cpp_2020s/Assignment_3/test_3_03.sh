#!/bin/bash
set -eoux pipefail
###
 # @Github: https://github.com/Certseeds
 # @Organization: SUSTech
 # @Author: nanoseeds
 # @Date: 2020-04-11 23:29:35
 # @LastEditors: nanoseeds
 # @LastEditTime: 2020-04-11 23:29:45
 ###
language=("Armenian" "Georgian" "Lao" "Malayalam" "Devanagari" "Georgian")
if [[ -f ass3_03.out ]]; then
    rm ass3_03.out
fi
mkdir -p "cmake_build_path"
cd cmake_build_path
cmake ..
make -j"$(nproc)"
cp ./src/Assignment_3_03 ./../ass3_03.out
cd ..
for (( i = 1,j=0; i < 7; i++,j++ )); do
    output=$(./ass3_03.out < "./test/sample${i}.txt")
    if [[ ${output} != ${language[${j}]} ]]; then
        echo "${i} error";
        exit 1;
    fi
done
echo "no error"