
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_766_test.hpp"

namespace leetcode_766 {


bool leetcode_766::isToeplitzMatrix(const vector<vector<int32_t>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return true;
    }
    const auto m{matrix.size()}, n{matrix.front().size()};
    if (1 == m || 1 == n) {
        return true;
    }
    const auto minV{std::min(m, n)};
    for (size_t i{0}; i < m; ++i) {
        auto val{i + 1};
        const auto num{matrix[i][0]};
        for (size_t j = 1; j < std::min(m - i, n); ++j) {
            if (num != matrix[val][j]) {
                return false;
            }
            val += 1;
        }
    }
//    for (size_t i{1}; i < minV; i++) {
//        const auto num = matrix[0][0];
//        if (num != matrix[i][i]) {
//            return false;
//        }
//    }
    for (size_t i{1}; i < n; ++i) {
        const auto num = matrix[0][i];
        auto val{i + 1};
        for (size_t j{1}; j < std::min(m, n - i); ++j) {
            if (num != matrix[j][val]) {
                return false;
            }
            val += 1;
        }
    }
    return true;
}

}
