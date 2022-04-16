// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_136_test.hpp"

namespace leetcode_136 {

int leetcode_136::singleNumber(const vector<int32_t> &nums) {
    int will_return{0};
    for (const auto num: nums) {
        will_return ^= num;
    }
    return will_return;
}

}