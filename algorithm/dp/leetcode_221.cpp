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
#include "leetcode_221_test.hpp"

namespace leetcode_221 {
static constexpr const auto base{'0'};

int32_t leetcode_221::maximalSquare(const vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return {};
    }
    const auto row{matrix.size()}, col{matrix.front().size()};
    vector<vector<int32_t>> range(row + 1, vector<int32_t>(col + 1));
    for (size_t i{0}; i < row; i++) {
        for (size_t j{0}; j < col; j++) {
            range[i + 1][j + 1] = range[i][j + 1] + range[i + 1][j] - range[i][j] + (matrix[i][j] - base);
        }
    }
    size_t maxV{0}; // O(mn*min(m,n))
    for (size_t i{1}; i <= row; i++) {
        for (size_t j{1}; j <= col; j++) {
            const auto leftUp{range[i - 1][j - 1]};
            size_t x{i + 1}, y{j + 1};
            if (matrix[i - 1][j - 1] != base) {
                maxV = std::max(maxV, static_cast<size_t>(1));
                while (x <= row && y <= col) {
                    const size_t diff = range[x][y] - range[i - 1][y] - range[x][j - 1] + leftUp;
                    if (diff != (x - i + 1) * (x - i + 1)) {
                        break;
                    } else {
                        maxV = std::max(maxV, diff);
                        x++, y++;
                    }
                }
            }
        }
    }
    return static_cast<size_t>(maxV);
}

int32_t leetcode_221::maximalSquare2(const vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return {};
    }
    const auto row{matrix.size()}, col{matrix.front().size()};
    vector<vector<int32_t>> dp(row + 1, vector<int32_t>(col + 1));
    int32_t maxV{0};
    for (size_t i{0}; i < row; i++) {
        for (size_t j{0}; j < col; j++) {
            dp[i + 1][j + 1] = (
                    matrix[i][j] == base ?
                    0
                                         :
                    std::min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1
            );
            maxV = std::max(maxV, dp[i + 1][j + 1]);
        }
    }
    return maxV * maxV;
}
}