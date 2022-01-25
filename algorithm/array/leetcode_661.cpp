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
#include "leetcode_661_test.hpp"

namespace leetcode_661 {

vector<vector<int32_t>> leetcode_661::imageSmoother(const vector<vector<int32_t>> &M) {
    const auto sizes{M.size()}, sizes_in{M[0].size()};
    vector<vector<int32_t>> willreturn(sizes, vector<int32_t>(sizes_in, 0));
    if (sizes == 1) {
        if (sizes_in == 1) {
            return M;
        } else if (sizes_in == 2) {
            return {{(M[0][0] + M[0][1]) / 2, (M[0][0] + M[0][1]) / 2}};
        } else {
            willreturn[0][0] = (M[0][0] + M[0][1]) / 2;
            willreturn[0][sizes_in - 1] = (M[0][sizes_in - 2] + M[0][sizes_in - 1]) / 2;
            for (size_t i{1}; i < sizes_in - 1; i++) {
                willreturn[0][i] = (
                                           M[0][i - 1] + M[0][i] + M[0][i + 1]) / 3;
            }
            return willreturn;
        }
    } else if (sizes_in == 1) {
        if (sizes == 2) {
            return {{(M[0][0] + M[1][0]) / 2}, {(M[0][0] + M[1][0]) / 2}};
        } else {
            willreturn[0][0] = (M[0][0] + M[1][0]) / 2;
            willreturn[sizes - 1][0] = (M[sizes - 1][0]
                                        + M[sizes - 2][0]) / 2;
            for (size_t i{1}; i < sizes - 1; i++) {
                willreturn[i][0] = (
                                           M[i - 1][0] + M[i][0] + M[i + 1][0]) / 3;
            }
            return willreturn;
        }
    }
    willreturn[0][0] =
            (M[0][0] + M[0][1] +
             M[1][0] + M[1][1]) / 4;
    willreturn[sizes - 1][0] =
            (M[sizes - 1][0] + M[sizes - 2][0] +
             M[sizes - 2][1] + M[sizes - 1][1]) / 4;
    willreturn[0][sizes_in - 1] = (
                                          M[0][sizes_in - 1] + M[1][sizes_in - 1] +
                                          M[1][sizes_in - 2] + M[0][sizes_in - 2]
                                  ) / 4;
    willreturn[sizes - 1][sizes_in - 1] = (
                                                  M[sizes - 1][sizes_in - 1] + M[sizes - 1][sizes_in - 2] +
                                                  M[sizes - 2][sizes_in - 1] + M[sizes - 2][sizes_in - 2]
                                          ) / 4;
    for (size_t i{1}; i < sizes_in - 1; i++) {
        willreturn[0][i] = (
                                   M[0][i - 1] + M[0][i] + M[0][i + 1] +
                                   M[1][i - 1] + M[1][i] + M[1][i + 1]) / 6;
        willreturn[sizes - 1][i] = (
                                           M[sizes - 2][i - 1] + M[sizes - 2][i] + M[sizes - 2][i + 1] +
                                           M[sizes - 1][i - 1] + M[sizes - 1][i] + M[sizes - 1][i + 1]) / 6;
    }
    for (size_t i{1}; i < sizes - 1; i++) {
        willreturn[i][0] = (
                                   M[i - 1][0] + M[i][0] + M[i + 1][0] +
                                   M[i - 1][1] + M[i][1] + M[i + 1][1]
                           ) / 6;
        willreturn[i][sizes_in - 1] = (
                                              M[i - 1][sizes_in - 1] + M[i][sizes_in - 1] + M[i + 1][sizes_in - 1] +
                                              M[i - 1][sizes_in - 2] + M[i][sizes_in - 2] + M[i + 1][sizes_in - 2]
                                      ) / 6;
        for (size_t j{1}; j < sizes_in - 1; j++) {
            willreturn[i][j] = (
                                       M[i - 1][j - 1] + M[i][j - 1] + M[i + 1][j - 1] +
                                       M[i - 1][j] + M[i][j] + M[i + 1][j] +
                                       M[i - 1][j + 1] + M[i][j + 1] + M[i + 1][j + 1]
                               ) / 9;
        }
    }
    return willreturn;
}
}
