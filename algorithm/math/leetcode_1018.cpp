// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_1018_test.hpp"

namespace leetcode_1018 {

vector<bool> leetcode_1018::prefixesDivBy5(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    vector<bool> willreturn(nums_size);
    for (size_t i{0}, num{0}; i < nums_size; ++i) {
        num = (2 * num + nums[i]) % 5;
        willreturn[i] = (num == 0);
    }
    return willreturn;
}

}
