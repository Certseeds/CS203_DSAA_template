// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_16_test.hpp"
#include <algorithm>

namespace leetcode_16 {

int leetcode_16::threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int32_t mindiff{std::numeric_limits<int32_t>::max()}, will_return{0};
    const auto nums_size = nums.size();
    for (size_t i{0}; i < nums_size; i++) {
        const auto target_diff = target - nums[i];
        size_t left{i + 1}, right{nums_size - 1};
        while (left < right) {
            const auto sum = nums[left] + nums[right];
            const auto diff = target_diff - sum;
            if (diff < 0) {
                right--;
            } else {
                left++;
            }
            if (mindiff > std::abs(diff)) {
                mindiff = std::abs(diff);
                will_return = sum + nums[i];
            }
        }
    }
    return will_return;
}
}
