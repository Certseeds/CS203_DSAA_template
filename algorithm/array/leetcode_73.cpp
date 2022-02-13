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
#include "leetcode_73_test.hpp"
#include <unordered_set>

namespace leetcode_73 {
using std::unordered_set;

void leetcode_73::setZeroes(vector<vector<int32_t>> &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return;
    }
    const auto row_size{matrix.size()}, col_size{matrix.front().size()};
    const auto row = [&matrix] {
        return std::find(matrix[0].cbegin(), matrix[0].cend(), 0) != matrix[0].cend();
    }(), col = [&matrix, row_size] {
        for (size_t i{0}; i < row_size; ++i) {
            if (matrix[i][0] == 0) {
                return true;
            }
        }
        return false;
    }();
    for (size_t i{1}; i < row_size; ++i) {
        for (size_t j{1}; j < col_size; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (size_t i{1}; i < row_size; ++i) {
        if (matrix[i][0] == 0) {
            std::fill(matrix[i].begin() + 1, matrix[i].end(), 0);
        }
    }
    for (size_t j{1}; j < col_size; ++j) {
        if (matrix[0][j] == 0) {
            for (size_t i{1}; i < row_size; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
    if (row) {
        std::fill(matrix[0].begin(), matrix[0].end(), 0);
    }
    if (col) {
        for (size_t i{0}; i < row_size; ++i) {
            matrix[i][0] = 0;
        }
    }
}

}