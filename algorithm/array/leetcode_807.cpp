
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_807_test.hpp"

namespace leetcode_807 {
int leetcode_807::maxIncreaseKeepingSkyline(const vector<vector<int32_t>> &grid) {
    const auto m = grid.size();
    if (m == 0) {
        return 0;
    }
    vector<int32_t> row{}, line{};
    row.reserve(m);
    line.reserve(m);
    // ps, in this matrix, .size() == .front().size()
    for (size_t i{0}; i < m; ++i) {
        int32_t maxrow{-1}, maxline{-1};
        for (size_t j{0}; j < m; ++j) {
            maxrow = std::max(maxrow, grid[i][j]);
            maxline = std::max(maxline, grid[j][i]);
        }
        row.push_back(maxrow);
        line.push_back(maxline);
    }
    int willreturn{0};
    for (size_t i{0}; i < m; ++i) {
        for (size_t j{0}; j < m; ++j) {
            willreturn += std::min(row[i], line[j]) - grid[i][j];
        }
    }
    return willreturn;
}

}
