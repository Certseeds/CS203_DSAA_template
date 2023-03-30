// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_905_test.hpp"

namespace leetcode_905 {
vector<int32_t> leetcode_905::sortArrayByParity(vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    for (size_t begin{0}, end{nums_size - 1}; begin < end; std::swap(nums[begin], nums[end])) {
        for (; ((nums[begin] & 1) == 0) && (begin < end); ++begin) {}
        for (; ((nums[end] & 1) == 1) && (begin < end); --end) {}
    }
    return nums;
}
}
