// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanos

*/
#include "leetcode_643_test.hpp"

namespace leetcode_643 {

double leetcode_643::findMaxAverage(const vector<int32_t> &nums, int32_t k) {
    const auto nums_size{nums.size()};
    if (nums_size <= static_cast<size_t>(k)) {
        return double(std::accumulate(nums.begin(), nums.end(), 0)) /
               static_cast<double>(nums_size);
    }
    vector<int32_t> DP(nums_size - k + 1);
    DP[0] = std::accumulate(nums.begin(), nums.begin() + k, 0);
    int willreturn = DP[0];
    for (size_t i{1}; i + k <= nums_size; i++) {
        DP[i] = DP[i - 1] - nums[i - 1] + nums[k + i - 1];
        willreturn = std::max(willreturn, DP[i]);
    }
    return willreturn / double(k);
}

}