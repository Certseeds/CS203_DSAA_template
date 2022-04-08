// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_240_test.hpp"

namespace leetcode_240 {

bool leetcode_240::findNumberIn2DArray(const vector<vector<int32_t>> &matrix, int32_t target) {
    if (matrix.empty() || matrix.front().empty()) {
        return false;
    }
    const size_t n = matrix.size();
    vector<int32_t> begins(n, 0);
    vector<int32_t> ends(n, 0);
    for (size_t i{0}; i < n; ++i) {
        begins[i] = *matrix[i].begin();
        ends[i] = *(matrix[i].end() - 1);
    }
    const auto temp = std::upper_bound(begins.begin(), begins.end(), target) - begins.begin() - 1;
    const auto temp2 = std::lower_bound(ends.begin(), ends.end(), target) - ends.begin();
    for (auto i{temp2}; i <= temp; ++i) {
        if (std::binary_search(matrix[i].begin(), matrix[i].end(), target)) {
            return true;
        }
    }
    return false;
}

bool leetcode_240::findNumberIn2DArrayZ(const vector<vector<int32_t>> &matrix, int32_t target) {
    const auto m = static_cast<int32_t>(matrix.size());
    if (m == 0) {
        return false;
    }
    const auto n = static_cast<int32_t>(matrix.front().size());
    if (n == 0) {
        return false;
    }
    for (int32_t x{0}, y = n - 1; x < m && y >= 0;) {
        const auto find = matrix[x][y];
        if (find == target) {
            return true;
        } else if (find > target) {
            y--;
        } else {
            x++;
        }
    }
    return false;
}

}
