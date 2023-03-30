// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_268_test.hpp"
#include <numeric>

namespace leetcode_268 {

int32_t leetcode_268::missingNumber(const vector<int32_t> &nums) {
    const auto nums_size = static_cast<int32_t>(nums.size());
    return nums_size * (nums_size + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
}
}
