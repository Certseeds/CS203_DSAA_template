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
#include "leetcode_120_test.hpp"

namespace leetcode_120 {

int32_t leetcode_120::minimumTotal(const vector<vector<int32_t>> &triangle) {
    const size_t tri_height{triangle.size()};
    if (tri_height == 0) {
        return 0;
    } else if (tri_height == 1) {
        return triangle[0][0];
    }
    vector<int32_t> dps(tri_height, 0);
    dps[0] = triangle.front().front();
    for (size_t i{1}; i < tri_height; i++) {
        dps[i] = dps[i - 1] + triangle[i][i];
        for (size_t r{i - 1}; r > 0; r--) {
            dps[r] = std::min(dps[r - 1], dps[r]) + triangle[i][r];
        }
        dps[0] = dps[0] + triangle[i][0];
    }
    return *std::min_element(dps.cbegin(), dps.cend());
}
}