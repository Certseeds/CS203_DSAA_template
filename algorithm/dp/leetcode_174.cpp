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
#include "leetcode_174_test.hpp"

namespace leetcode_174 {

int32_t leetcode_174::calculateMinimumHP(const vector<vector<int32_t>> &dungeon) {
    if (dungeon.empty() || dungeon.front().empty()) {
        return 0;
    }
    const auto m{dungeon.size()}, n{dungeon.front().size()};
    vector<vector<int32_t>> dp(m + 1, vector<int32_t>(n + 1, 0));
    for (size_t i{m}; i > 0; i--) {
        for (size_t j{n}; j > 0; j--) {
            dp[i][j] = dungeon[i - 1][j - 1];
        }
    }
    // i,j -> 到i,j点时,可以到达终点的最低血量.
    dp[m][n] = std::max(1 - dp[m][n], 1);
    for (size_t i{m - 1}; i > 0; i--) {
        dp[i].back() = std::max(dp[i + 1].back() - dp[i].back(), 1);
    }
    for (size_t i{n - 1}; i > 0; i--) {
        dp.back()[i] = std::max(dp.back()[i + 1] - dp.back()[i], 1);
    }
    for (size_t i{m - 1}; i > 0; i--) {
        for (size_t j{n - 1}; j > 0; j--) {
            dp[i][j] = std::max(std::min(dp[i + 1][j], dp[i][j + 1]) - dp[i][j], 1);
        }
    }
    return dp[1][1];
}
}
