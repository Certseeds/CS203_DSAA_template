// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_961_test.hpp"
#include <unordered_set>

namespace leetcode_961 {
using std::unordered_set;

int32_t leetcode_961::repeatedNTimes(const vector<int32_t> &nums) {
    unordered_set<int32_t> uset{};
    for (const auto num: nums) {
        if (uset.count(num) != 0) {
            return num;
        } else {
            uset.insert(num);
        }
    }
    return -1;
}

}
