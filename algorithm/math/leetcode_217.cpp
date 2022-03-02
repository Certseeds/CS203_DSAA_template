// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_217_test.hpp"
#include <unordered_set>

namespace leetcode_217 {
using std::unordered_set;

bool leetcode_217::containsDuplicate(const vector<int32_t> &nums) {
    unordered_set<int32_t> judges;
    for (size_t i{0}, nums_size{nums.size()}; i < nums_size; i++) {
        if (judges.count(nums[i]) != 0) {
            return true;
        } else {
            judges.insert(nums[i]);
        }
    }
    return false;
}

}