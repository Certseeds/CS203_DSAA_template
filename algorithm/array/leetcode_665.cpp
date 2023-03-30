// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_665_test.hpp"

namespace leetcode_665 {

bool leetcode_665::checkPossibility(const vector<int32_t> &nums) {
    int count{0};
    size_t position{0};
    for (size_t i{0}; i < nums.size() - 1; i++) {
        if (nums[i] - nums[i + 1] > 0) {
            count++;
            position = i;
        }
    }
    if (count > 1) {
        return false;
    }
    if (position == 0 || position == nums.size() - 1) {
        return true;
    }
    bool first{true}, second{true};
    if (nums[position - 1] > nums[position + 1]) {
        first = false;
    }
    for (size_t i = position + 1; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            first = false;
        }
    }
    if (position < nums.size() - 2) {
        if (nums[position] > nums[position + 2]) {
            return first;
        }
        for (size_t i = position + 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return first;
            }
        }
    }
    return first || second;
}
}
