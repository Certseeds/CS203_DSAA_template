// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_169_test.hpp"
#include <unordered_map>

namespace leetcode_169 {
using std::unordered_map;

int32_t leetcode_169::majorityElement(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 1) {
        return nums[0];
    }
    unordered_map<int32_t, int32_t> umaps{};
    int32_t val{std::numeric_limits<int32_t>::min()}, count{0};
    for (const auto i: nums) {
        umaps[i]++;
        if (umaps[i] > count) {
            count = umaps[i];
            val = i;
        }
    }
    return val;
}

int32_t leetcode_169::majorityElement2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 0) {
        return -1;
    } else if (nums_size == 1) {
        return nums.front();
    }
    int32_t val{std::numeric_limits<int32_t>::min()}, count{0};
    for (const auto i: nums) {
        if (count > 0) {
            if (val == i) {
                count++;
            } else {
                count--;
            }
        } else {
            count = 1;
            val = i;
        }
    }
    return val;
}
}