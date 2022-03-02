// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_55_test.hpp"

namespace leetcode_55 {

bool leetcode_55::canJump(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return true;
    }
    size_t fst{0}, end = nums[0];
    while (fst < end) {
        const size_t next = end;
        for (size_t now{fst}; now <= next; now++) {
            end = std::max(now + nums[now], end);
            if (end + 1 >= nums_size) {
                return true;
            }
        }
        fst = next;
    }
    return end + 1 >= nums_size;
}

}