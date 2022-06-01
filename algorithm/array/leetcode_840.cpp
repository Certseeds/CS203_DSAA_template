// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_840_test.hpp"

namespace leetcode_840 {

bool numMagicSquaresInside_help(const vector<vector<int>> &grid, size_t x, size_t y) {
    for (size_t i{0}; i < 3; ++i) {
        for (size_t j{0}; j < 3; ++j) {
            if (grid[x + i][y + j] > 9 || grid[x + i][y + j] < 1) {
                return false;
            }
        }
    }
    return (
            // 中间需要是五
            grid[x + 1][y + 1] == 5 &&
            grid[x][y] + grid[x + 2][y + 2] == 10 &&
            grid[x + 1][y] + grid[x + 1][y + 2] == 10 &&
            grid[x + 2][y] + grid[x][y + 2] == 10 &&
            grid[x][y] != grid[x + 2][y + 2] &&
            grid[x + 1][y] != grid[x + 1][y + 2] &&
            grid[x + 2][y] != grid[x][y + 2] &&
            grid[x][y] + grid[x][y + 1] + grid[x][y + 2] == 15 &&
            grid[x][y] + grid[x + 1][y] + grid[x + 2][y] == 15 &&
            grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] == 15
    );
}

int leetcode_840::numMagicSquaresInside(const vector<vector<int>> &grid) {
    const auto m{grid.size()};
    if (m < 3) {
        return 0;
    }
    const auto n{grid.size()};
    if (n < 3) {
        return 0;
    }
    int count = 0;
    for (size_t i{0}; i + 3 <= m; ++i) {
        for (size_t j{0}; j + 3 <= n; ++j) {
            count += numMagicSquaresInside_help(grid, i, j);
        }
    }
    return count;
}
}
