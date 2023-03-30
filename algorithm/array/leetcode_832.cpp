// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_832_test.hpp"

namespace leetcode_832 {

vector<vector<int>> leetcode_832::flipAndInvertImageConst(const vector<vector<int>> &image) {
    const auto m{image.size()};
    if (m == 0) {
        return image;
    }
    const auto n{image.front().size()};
    if (n == 0) {
        return image;
    }
    vector<vector<int32_t>> result(image);
    vector<uint8_t> traverse(n);
    for (size_t i{0}; i < m; ++i) {
        for (size_t left{0}, right{n - 1}; left < right && right < n; ++left, --right) {
            if (image[i][left] == image[i][right]) {
                result[i][left] = !image[i][left];
                result[i][right] = !image[i][right];
            }
        }
        if (n % 2 == 1) {
            result[i][n / 2] = !image[i][n / 2];
        }
    }
    return result;
}


}
