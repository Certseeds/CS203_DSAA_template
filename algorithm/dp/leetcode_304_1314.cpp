/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanos
 * @Date: 2021-04-03 10:15:42
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "leetcode_304_1314_test.hpp"

namespace leetcode_304 {
vector<vector<int32_t>> init(const vector<vector<int32_t>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return {};
    }
    const auto row{matrix.size()}, col{matrix.front().size()};
    vector<vector<int32_t>> range(row + 1, vector<int32_t>(col + 1));
    for (size_t i{0}; i < row; i++) {
        for (size_t j{0}; j < col; j++) {
            range[i + 1][j + 1] = range[i][j + 1] + range[i + 1][j] - range[i][j] + matrix[i][j];
        }
    }
    return range;
}

NumMatrix::NumMatrix(const vector<vector<int32_t>> &matrix) : sumRange(init(matrix)) {
}

int NumMatrix::sumRegion(int32_t row1, int32_t col1, int32_t row2, int32_t col2) const {
    return this->sumRange[row2 + 1][col2 + 1] - this->sumRange[row1][col2 + 1] -
           this->sumRange[row2 + 1][col1] + this->sumRange[row1][col1];
}
}

namespace leetcode_1314 {

vector<vector<int32_t>> leetcode_1314::matrixBlockSum(const vector<vector<int32_t>> &mat, int32_t K) {
    if (mat.empty() || mat.front().empty()) {
        return {};
    }
    const auto k = static_cast<size_t>(K);
    const auto row{mat.size()}, col{mat.front().size()};
    const vector<vector<int32_t>> dp{leetcode_304::init(mat)};
    vector<vector<int32_t>> will_return(row, vector<int32_t>(col));
    for (size_t i{0}; i < row; ++i) {
        const size_t left{i > k ? i - k : 0};
        const size_t right{std::min(i + k, row - 1)};
        for (size_t j{0}; j < col; ++j) {
            const size_t head{j > k ? j - k : 0};
            const size_t loot{std::min(j + k, col - 1)};
            will_return[i][j] = dp[right + 1][loot + 1] - dp[left][loot + 1] - dp[right + 1][head] +
                                dp[left][head];
        }
    }
    return will_return;
}
}

