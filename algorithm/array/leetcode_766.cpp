
/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
#include "leetcode_766_test.hpp"

namespace leetcode_766 {


bool leetcode_766::isToeplitzMatrix(const vector<vector<int32_t>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return true;
    }
    const auto m{matrix.size()}, n{matrix.front().size()};
    if (1 == m || 1 == n) {
        return true;
    }
    const auto minV{std::min(m, n)};
    for (size_t i{0}; i < m; ++i) {
        auto val{i + 1};
        const auto num{matrix[i][0]};
        for (size_t j = 1; j < std::min(m - i, n); ++j) {
            if (num != matrix[val][j]) {
                return false;
            }
            val += 1;
        }
    }
//    for (size_t i{1}; i < minV; i++) {
//        const auto num = matrix[0][0];
//        if (num != matrix[i][i]) {
//            return false;
//        }
//    }
    for (size_t i{1}; i < n; ++i) {
        const auto num = matrix[0][i];
        auto val{i + 1};
        for (size_t j{1}; j < std::min(m, n - i); ++j) {
            if (num != matrix[j][val]) {
                return false;
            }
            val += 1;
        }
    }
    return true;
}

}
