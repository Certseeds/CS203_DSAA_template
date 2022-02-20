/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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

}
