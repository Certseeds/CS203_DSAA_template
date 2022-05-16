// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_883_test.hpp"

namespace leetcode_883 {

int32_t leetcode_883::projectionArea(const vector<vector<int32_t>> &grid) {
    const auto m{grid.size()};
    if (m == 0) {
        return 0;
    }
    int willreturn{0};
    for (size_t i{0}; i < m; ++i) {
        int max1{0}, max2{0};
        for (size_t j{0}; j < m; ++j) {
            if (grid[i][j]) {
                willreturn++;
            }
            max1 = std::max(max1, grid[j][i]);
            max2 = std::max(max2, grid[i][j]);
        }
        willreturn += (max1 + max2);
    }
    return willreturn;
}

}