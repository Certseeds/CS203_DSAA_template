// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_9_test.hpp"

namespace leetcode_9 {

bool leetcode_9::isPalindrome(int32_t x) {
    vector<int32_t> nums;
    if (x < 0) {
        return false;
    }
    while (x > 0) {
        nums.push_back(x % 10);
        x /= 10;
    }
    const auto nums_size{nums.size()};
    const auto half_size{static_cast<int32_t>(nums_size / 2)};
    for (int32_t i{0}; i < half_size; i++) {
        if (nums[i] != nums[nums_size - 1 - i]) {
            return false;
        }
    }
    return true;
}
}