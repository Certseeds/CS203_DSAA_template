// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_34_test.hpp"

namespace leetcode_34 {
using binary_search::binary_search_pos;

vector<int32_t> leetcode_34::searchRange(const vector<int32_t> &nums, int32_t target) {
    if (nums.empty()) {
        return vector<int32_t>{-1, -1};
    }
    if (binary_search_pos(nums, target, 0, static_cast<int32_t>(nums.size())) == -1) {
        return vector<int32_t>{-1, -1};
    }
    const auto minv{static_cast<int32_t>(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin())},
            maxv{static_cast<int32_t>(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin())};
    return vector<int32_t>{minv, maxv - 1};
}

}
