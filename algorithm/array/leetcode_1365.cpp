// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023  nanoseeds

*/
#include "leetcode_1365_test.hpp"

namespace leetcode_1365 {

vector<int32_t> leetcode_1365::smallerNumbersThanCurrent(const vector<int32_t> &nums) {
    constexpr const auto max_num{100};
    const auto nums_size{nums.size()};
    for (const auto num: nums) {
        assert(num >= 0);
        assert(num <= max_num);
    }
    assert(nums_size >= 2);
    assert(nums_size <= 500);
    std::array<int32_t, max_num + 1> arrs{0,};
    for (const auto num: nums) {
        arrs[num] += 1;
    }
    for (int32_t i{1}; i < max_num + 1; i++) {
        arrs[i] = arrs[i] + arrs[i - 1];
    }
    vector<int32_t> will_return(nums_size, 0);
    for (size_t i{0}; i < nums_size; i++) {
        if (nums[i] != 0) {
            will_return[i] = arrs[nums[i] - 1];
        }
    }
    return will_return;
}

}
