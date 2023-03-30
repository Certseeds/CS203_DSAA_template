// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_56_test.hpp"

namespace leetcode_56 {

vector<vector<int32_t>> leetcode_56::merge(const vector<vector<int32_t>> &intervals) {
    vector<vector<int32_t>> nums{intervals};
    const size_t nums_size{nums.size()};
    if (nums_size <= 1) {
        return nums;
    }
    std::sort(std::begin(nums), std::end(nums), [](const auto &v1, const auto &v2) {
        return v1[0] < v2[0];
    });
    vector<vector<int32_t>> will_return;
    int32_t begin{nums[0][0]}, end{nums[0][1]};
    for (size_t order{1}; order < nums_size; order++) {
        if (end >= nums[order][0]) {
            end = std::max(end, nums[order][1]);
        } else {
            will_return.push_back({begin, end});
            begin = nums[order][0];
            end = nums[order][1];
        }
    }
    will_return.push_back({begin, end});
    return will_return;
}
}
