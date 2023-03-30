// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_35_test.hpp"
#include <algorithm>

// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一
namespace binary_search::leetcode_35 {

int32_t leetcode_35::searchInsert(const vector<int> &nums, int32_t target) {
    const auto n_size = static_cast<int32_t>(nums.size());
    if (nums.empty() || target < nums.front()) {
        return 0; // 放到第一个
    } else if (nums.back() < target) {
        return n_size; // 放到最后一个
    }
    int32_t left{0}, right{n_size - 1}, middle{0};
    while (left < right) {
        if (middle = (right - left) / 2 + left; nums[middle] > target) {// 避免溢出
            right = middle;
        } else if (nums[middle] < target) {
            left = middle + 1;// 只有一处+1
        } else {
            return middle;
        }
    }
    return left;
}

int32_t leetcode_35::searchInsert2(const vector<int32_t> &nums, int32_t target) {
    const auto diff = std::lower_bound(nums.begin(), nums.end(), target);
    return static_cast<int32_t>(distance(nums.begin(), diff));
}

}
