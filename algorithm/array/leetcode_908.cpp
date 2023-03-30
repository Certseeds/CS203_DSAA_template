// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_908_test.hpp"

namespace leetcode_908 {

int32_t leetcode_908::smallestRangeI(const vector<int32_t> &nums, int32_t k) {
    int min{0x3f3f3f3f}, max{0};
    for (const auto num: nums) {
        min = std::min(min, num);
        max = std::max(max, num);
    }
    return (max - min >= 2 * k ? max - min - 2 * k : 0);
}

}
