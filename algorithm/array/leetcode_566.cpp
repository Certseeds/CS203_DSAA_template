// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_566_test.hpp"

namespace leetcode_566 {

vector<vector<int32_t>> leetcode_566::matrixReshape(const vector<vector<int32_t>> &mat, int32_t r, int32_t c) {
    const auto lev1{mat.size()}, lev2{mat.front().size()};
    if (r * c - lev1 * lev2 != 0) {
        return vector<vector<int32_t>>{mat};
    }
    vector<vector<int32_t>> willreturn(r, vector<int32_t>(c));
    for (int32_t i{0}, sum{0}; i < r; i++) {
        for (int32_t j{0}; j < c; j++, sum++) {
            willreturn[i][j] = mat[sum / lev2][sum % lev2];
        }
    }
    return willreturn;
}


}
