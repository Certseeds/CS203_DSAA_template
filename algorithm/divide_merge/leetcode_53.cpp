// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_53_test.hpp"

namespace leetcode_53 {
// [begin,end)
int32_t maxSubArray(const vector<int32_t> &nums, size_t begin, size_t end) {
    if (begin + 1 == end) {
        return nums[begin];
    }
    const auto half{begin + (end - begin) / 2};
    const auto left{maxSubArray(nums, begin, half)},
            right{maxSubArray(nums, half, end)};
    int32_t max_left{-0x3f3f3f3f}, left_sum{0}, max_right{-0x3f3f3f3f}, right_sum{0};
    for (size_t left_order{half}; left_order >= begin + 1; left_order--) {
        // 无符号数判断的时候不要-1 > 0, 而是用 > 1
        left_sum += nums[left_order - 1];
        max_left = std::max(max_left, left_sum);
    }
    for (size_t right_order{half}; right_order < end; right_order++) {
        right_sum += nums[right_order];
        max_right = std::max(max_right, right_sum);
    }
    return std::max({left, right, max_left + max_right});
}

int32_t leetcode_53::maxSubArray(const vector<int32_t> &nums) {
    return ::leetcode_53::maxSubArray(nums, 0, nums.size());
}

int32_t leetcode_53::maxSubArray2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 1) {
        return nums[0];
    }
    vector<int32_t> dp(nums_size + 1, 0);
    // dp[i] 考虑前第i个的最大值 X 带有第i个的最大值 √(不然不能直接用dp[i-1]+nums[i-1])
    // 若带前面的,则为 dp[i-1]+nums[i-1]
    // 若不带前面的,则为 nums[i-1]
    dp[0] = 0; // 选0个一定为0
    dp[1] = nums[0]; // 只选一个肯定是nums[0]
    int32_t maxV{nums[0]};
    for (size_t i{2}; i <= nums_size; i++) {
        dp[i] = std::max(nums[i - 1], dp[i - 1] + nums[i - 1]);
        maxV = std::max(maxV, dp[i]);
    }
    return maxV;
}
}