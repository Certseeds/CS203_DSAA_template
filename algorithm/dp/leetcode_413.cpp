// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_413_test.hpp"

namespace leetcode_413 {

int32_t leetcode_413::numberOfArithmeticSlices(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums.size() <= 2) {
        return 0;
    }
    static constexpr const auto func = [](int32_t x) {
        return (x - 1) * (x - 2) / 2;
    };// 完全不必要嗯算, 有连续段落的总长度即可
    int32_t sums{0}, lastDiff{nums[1] - nums[0]}, len{1};
    for (size_t i{2}; i < nums_size; i++) {
        const int32_t nowDiff{nums[i] - nums[i - 1]};
        if (nowDiff != lastDiff) {
            sums += func(len + 1);
            len = 1;
            lastDiff = nowDiff;
        } else {
            len++;
        }
    }
    sums += func(len + 1);
    return sums;
}

}
