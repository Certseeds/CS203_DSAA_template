// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_334_test.hpp"

namespace leetcode_334 {

bool leetcode_334::increasingTriplet(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size < 3) {
        return false;
    }
    vector<int32_t> dp(nums_size, 0);
    // dp[i]代表 第i个元素之前的最小元素
    // 此处可以发现其实只用到了dp[i],dp[i-1],可以做空间压缩
    dp[0] = std::numeric_limits<int32_t>::max(); // 第0个前面没有元素,所以置为int32_t的最大值
    int32_t maxMin{std::numeric_limits<int32_t>::max()};
    for (size_t i{1}; i + 1 < nums_size; ++i) {
        dp[i] = std::min(dp[i - 1], nums[i - 1]);
        if (nums[i] > dp[i]) {
            maxMin = std::min(maxMin, nums[i]);
        }
        if (nums[i + 1] > maxMin) {
            return true;
        }
    }
    return false;
}
}
