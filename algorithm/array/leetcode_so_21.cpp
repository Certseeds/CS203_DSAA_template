// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_so_21_test.hpp"

namespace leetcode_so_21 {

vector<int32_t> leetcode_so_21::exchange(const vector<int32_t> &nums_const) {
    if (nums_const.empty()) {
        return {};
    }
    vector<int32_t> nums{nums_const};
    static constexpr const auto judge = [](const auto num) -> bool { return num % 2 == 0; };
    // 实际上完全可以是左边模三余1,右边余0,2
    const auto nums_size{nums.size()};
    for (size_t left{0}, right{nums_size - 1}; left < right;) {
        for (; left < right && !judge(nums[left]); ++left) {}
        for (; left < right && judge(nums[right]); --right) {}
        if (left >= right) { return nums; }
        std::swap(nums[left], nums[right]);
    }
    return nums;
}
}
