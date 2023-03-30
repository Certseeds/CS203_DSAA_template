// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_581_test.hpp"
#include <algorithm>

namespace leetcode_581 {

int32_t leetcode_581::findUnsortedSubarray(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    vector<int32_t> nums2{nums};
    std::sort(nums2.begin(), nums2.end());
    size_t left{0}, right{nums.size()};
    for (size_t i{0}; i < nums_size && nums2[i] == nums[i]; i++, left++) {}
    for (size_t i{nums_size}; i > 0 && nums2[i - 1] == nums[i - 1]; i--, right--) {}
    return std::max(0, static_cast<int32_t>(right - left));
}

int32_t leetcode_581::findUnsortedSubarray2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    size_t left{nums.size() - 1}, right{0};
    int32_t maxV{std::numeric_limits<int32_t>::min()}, minV{std::numeric_limits<int32_t>::max()};
    for (size_t i{0}; i < nums_size; i++) {
        if (nums[i] >= maxV) {
            maxV = nums[i];
        } else {
            right = i;
        }
    }
    for (size_t i{nums_size}; i > 0; i--) {
        if (nums[i - 1] <= minV) {
            minV = nums[i - 1];
        } else {
            left = i - 1;
        }
    }
    return right == 0 ? 0 : right - left + 1;
}
}
