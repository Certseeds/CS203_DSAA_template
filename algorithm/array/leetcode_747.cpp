
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_747_test.hpp"

namespace leetcode_747 {

int32_t leetcode_747::dominantIndex(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    size_t pos{0};
    int32_t lastMax{-1}, maxV{-1};
    for (size_t i{0}; i < nums_size; ++i) {
        if (maxV < nums[i]) {
            pos = i;
            maxV = nums[i];
        }
    }
    for (size_t i{0}; i < nums_size; ++i) {
        if (nums[i] != maxV && lastMax < nums[i]) {
            lastMax = nums[i];
        }
    }
    if (lastMax * 2 <= maxV) {
        return pos;
    }
    return -1;
}
}
