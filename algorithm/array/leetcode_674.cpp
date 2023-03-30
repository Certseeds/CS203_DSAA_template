// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_674_test.hpp"

namespace leetcode_674 {

int leetcode_674::findLengthOfLCIS(const vector<int32_t> &nums) {
    int32_t will_Return{!nums.empty()}, maxv{1};
    for (size_t i{1}, size{nums.size()}; i < size; ++i) {
        maxv = (nums[i] > nums[i - 1]) ? (maxv + 1) : 1;
        will_Return = std::max(will_Return, maxv);
    }
    return will_Return;
}

}
