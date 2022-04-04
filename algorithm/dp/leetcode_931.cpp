// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_931_test.hpp"
#include <algorithm>
#include <numeric>

namespace leetcode_931 {

int32_t leetcode_931::minFallingPathSum(const vector<vector<int32_t>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return 0;
    }
    const auto row{matrix.size()}, col{matrix.front().size()};
    if (col == 1) {
        return std::accumulate(matrix.cbegin(), matrix.cend(), 0,
                               [](auto &fir, const auto &sec) { return fir + sec[0]; });
    }
    vector<int32_t> last(row, 0), now(row, 0);
    for (size_t line{0}; line < row; line++) {
        now[0] = matrix[line][0] + std::min(last[0], last[1]);
        for (size_t j{1}; j < col - 1; j++) {
            now[j] = matrix[line][j] + std::min({last[j], last[j - 1], last[j + 1]});
        }
        now[col - 1] = matrix[line][col - 1] + std::min(last[col - 2], last[col - 1]);
        std::swap(now, last);
    }
    return *std::min_element(last.cbegin(), last.cend());
}
}