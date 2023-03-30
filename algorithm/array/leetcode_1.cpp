// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_1_test.hpp"
#include <unordered_map>

namespace leetcode_1 {
using std::unordered_map;

vector<int32_t> leetcode_1::twoSum(const vector<int32_t> &nums, int32_t target) {
    const auto nums_size{nums.size()};
    unordered_map<int32_t, int32_t> umaps;
    for (size_t i{0}; i < nums_size; i++) {
        if (umaps.find(target - nums[i]) != std::end(umaps)) {
            return {static_cast<int32_t>(i), umaps[target - nums[i]] - 1};
        }
        umaps[nums[i]] = static_cast<int32_t>(i) + 1;
    }
    return {};
}
/*
if the number is not so big, it's better to use brute force,
if number > 50,choose hashmap.
 */
}
