// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_198_213_test.hpp"

namespace leetcode_198 {

int64_t leetcode_198::rob(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return nums[0];
    }
    vector<int64_t> dp(nums_size + 1, 0); // 取得0个 只能得0
    dp[1] = nums[0];// then nums_size >= 2
    for (size_t i{2}; i <= nums_size; i++) {
        dp[i] = std::max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp.back();
}

int64_t leetcode_198::rob2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return nums[0];
    }
    std::array<int64_t, 3> dp{0, nums[0], 0};
    // 滚 动 数 组
    for (size_t i{2}; i <= nums_size; i++, dp[1] = dp[2]) {
        dp[2] = std::max(dp[0] + nums[i - 1], dp[1]);
        dp[0] = dp[1]; // 不确保执行顺序,所以不能都放过去
    }
    return dp[2];
}
}
namespace leetcode_213 {

int64_t leetcode_213::rob(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    vector<int32_t> values(nums);
    if (nums_size <= 1) {
        return values[0];
    }
    vector<int64_t> dp(nums_size + 1, 0); // 取得0个 只能得0
    dp[1] = 0;// then nums_size >= 2
    values[0] = 0;
    for (size_t i{2}; i <= nums_size; i++) {
        dp[i] = std::max(dp[i - 2] + values[i - 1], dp[i - 1]);
    }
    const auto nums1{dp.back()}; // 置首个为0, 弃用的结果
    values[0] = nums[0];
    std::fill(std::begin(dp), std::end(dp), 0);
    dp[1] = values[0];
    values[nums_size - 1] = 0;
    for (size_t i{2}; i <= nums_size; i++) {
        dp[i] = std::max(dp[i - 2] + values[i - 1], dp[i - 1]);
    }
    const auto nums2{dp.back()};// 置末尾为0, 弃用的结果
    return std::max(nums1, nums2);
}

int64_t leetcode_213::rob2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return nums[0];
    }
    const vector<int32_t> vec1{nums.cbegin(), nums.cend() - 1};
    const vector<int32_t> vec2{nums.cbegin() + 1, nums.cend()};
    return std::max(leetcode_198::leetcode_198::rob2(vec1), leetcode_198::leetcode_198::rob2(vec2));
}
}