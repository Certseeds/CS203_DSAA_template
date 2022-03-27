// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_561_test.hpp"

namespace leetcode_561 {

int32_t leetcode_561::arrayPairSum(const vector<int32_t> &nums) {
    const size_t nums_size{nums.size()};
    vector<int32_t> input{nums};
    std::sort(input.begin(), input.end());
    int32_t temp{0};
    for (size_t i{0}; i < nums_size; i += 2) {
        temp += input[i];
    }
    return temp;
}

}
