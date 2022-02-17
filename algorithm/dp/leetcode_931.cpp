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
#include "leetcode_931_test.hpp"

namespace leetcode_931 {

int32_t leetcode_931::minFallingPathSum(const vector<vector<int32_t>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return 0;
    }
    const auto row{matrix.size()}, col{matrix.front().size()};
    if (col == 1) {
        return std::accumulate(matrix.cbegin(), matrix.cend(), 0,
                               [](auto &fir, const auto &sec) { return fir + sec[0]; });
    }
    vector<int32_t> last(row, 0), now(row, 0);
    for (size_t line{0}; line < row; line++) {
        now[0] = matrix[line][0] + std::min(last[0], last[1]);
        for (size_t j{1}; j < col - 1; j++) {
            now[j] = matrix[line][j] + std::min({last[j], last[j - 1], last[j + 1]});
        }
        now[col - 1] = matrix[line][col - 1] + std::min(last[col - 2], last[col - 1]);
        std::swap(now, last);
    }
    return *std::min_element(last.cbegin(), last.cend());
}
}