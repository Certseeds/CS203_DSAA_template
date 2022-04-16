// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_75_test.hpp"

namespace leetcode_75 {

void leetcode_75::sortColors(vector<int32_t> &nums) {
    std::array<int32_t, 3> counts{0, 0, 0};
    for (const auto num: nums) {
        counts[num]++;
    }
    for (int32_t i{0}, count{0}; i < 3; ++i) {
        for (int32_t j{0}; j < counts[i]; ++j, ++count) {
            nums[count] = i;
        }
    }
}

}