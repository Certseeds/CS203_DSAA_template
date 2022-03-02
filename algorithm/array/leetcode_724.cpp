
// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_724_test.hpp"

namespace leetcode_724 {
int32_t leetcode_724::pivotIndex(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    vector<int32_t> accu(nums_size + 2, 0);
    for (size_t i{1}; i <= nums_size; ++i) {
        accu[i] = nums[i - 1];
        accu[i] += accu[i - 1];
    }
    accu[nums_size + 1] = accu[nums_size];
    for (size_t i{1}; i <= nums_size; ++i) {
        if (accu[i - 1] + accu[i] == accu.back()) { // 可见此处可优化
            return static_cast<int32_t>(i) - 1;
        }
    }
    return -1;
}

}
