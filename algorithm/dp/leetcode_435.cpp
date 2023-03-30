// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#include "leetcode_435_test.hpp"

namespace leetcode_435 {

// 逆向思维来看, 这个问题就相当于排课问题中应该排出多少门课程的结果之反: 应该排除多少门课程
// 因此, 采用经典贪心解法,一直选取最早结束的课程,即可获取答案.
int32_t leetcode_435::eraseOverlapIntervals(const vector<vector<int32_t>> &intervals) {
    vector<vector<int32_t>> times{intervals};
    auto will_return = static_cast<int32_t>(times.size());
    std::sort(std::begin(times), std::end(times), [](const auto& p1, const auto& p2) { return p1[1] < p2[1]; });
    int32_t end{std::numeric_limits<int32_t>::min()};
    for (const auto &p: times) {
        if (p[0] >= end) {
            end = p[1];
            --will_return;
        }
    }
    return will_return;
}
}
