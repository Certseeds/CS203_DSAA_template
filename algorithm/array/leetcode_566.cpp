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
