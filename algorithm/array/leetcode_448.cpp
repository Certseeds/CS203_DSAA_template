// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_448_test.hpp"

namespace leetcode_448 {

vector<int32_t> leetcode_448::findDisappearedNumbers(const vector<int32_t> &nums) {
    vector<int32_t> res, num{nums};
    const auto nums_size{nums.size()};
    for (size_t i{0}; i < nums_size; i++) {
        const int32_t m = abs(num[i]) - 1; // index start from 0
        num[m] = num[m] > 0 ? -num[m] : num[m];
    }
    for (size_t i{0}; i < nums_size; i++) {
        if (num[i] > 0) {
            res.push_back(static_cast<int32_t>(i + 1));
        }
    }
    return res;
}

}
