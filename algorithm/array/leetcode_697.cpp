// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_697_test.hpp"
#include <unordered_map>

namespace leetcode_697 {
using std::unordered_map;

int32_t leetcode_697::findShortestSubArray(const vector<int32_t> &nums) {
    if (nums.empty()) {
        return 0;
    }
    unordered_map<int, int> times, begin;
    int32_t max{0}, will_return{0};
    const auto nums_size{static_cast<int32_t>(nums.size())};
    for (int32_t i{0}; i < nums_size; i++) {
        const auto num{nums[i]};
        ++times[num];
        if (times[num] == 1) {
            begin[num] = i;
        } else {
            if (times[num] > max) {
                max = times[num];
                will_return = i - begin[num];
            } else if (times[num] == max) {
                will_return = std::min(will_return, i - begin[num]);
            }
        }
    }
    return will_return + 1;
}
}
