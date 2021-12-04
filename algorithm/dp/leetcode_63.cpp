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
#include "leetcode_63_test.hpp"

namespace leetcode_63 {

int32_t leetcode_63::uniquePathsWithObstacles(const vector<vector<int>> &obs) {
    const size_t m{obs.size()};
    if (m == 0) {
        return 0;
    }
    const size_t n{obs[0].size()};
    vector<vector<int32_t>> DP(m, vector<int32_t>(n, 0));
    DP[0][0] = (obs[0][0] == 0);
    for (size_t i{1}; i < m; i++) {
        DP[i][0] = (DP[i - 1][0] != 0) && (obs[i][0] == 0);
    }
    for (size_t i{1}; i < n; i++) {
        DP[0][i] = (DP[0][i - 1] != 0) && (obs[0][i] == 0);
    }
    for (size_t i{1}; i < m; i++) {
        for (size_t j{1}; j < n; j++) {
            if (obs[i][j] == 0) {
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }
    }
    return DP.back().back();
}

}