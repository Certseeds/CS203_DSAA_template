
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#include "leetcode_153_154_test.hpp"


namespace leetcode_154 {
int32_t leetcode_154::findMin(const vector<int32_t> &nums) {
    size_t begin{0}, middle{0};
    size_t end{nums.size() - 1};
    while (begin < end) {
        middle = (end - begin) / 2 + begin;
        if (nums[middle] > nums[end]) {
            begin = middle + 1;
        } else if (nums[middle] < nums[end]) {
            end = middle;
        } else {
            end--;
        }
    }
    return nums[begin];
}
}

namespace leetcode_153 {
using leetcode_154::leetcode_154;

int32_t leetcode_153::findMin(const vector<int32_t> &nums) {
    return leetcode_154::findMin(nums);
}
}
