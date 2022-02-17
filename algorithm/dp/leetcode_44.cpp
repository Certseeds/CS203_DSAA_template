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
#include "leetcode_44_test.hpp"
#include <vector>

namespace leetcode_44 {
using std::vector;

bool leetcode_44::isMatch(const string &s, const string &p) {
    const auto s_size{s.size()}, p_size{p.size()};
    vector<vector<uint8_t>> DP(s_size + 1, vector<uint8_t>(p_size + 1, false));
    DP[0][0] = true;
    for (size_t i{1}; i <= p_size; i++) {
        DP[0][i] = (p[i - 1] == '*') && DP[0][i - 1];
    }
    for (size_t i{1}; i <= s_size; i++) {
        for (size_t j{1}; j <= p_size; j++) {
            switch (p[j - 1]) {
                case '?': {
                    DP[i][j] = DP[i - 1][j - 1];
                    break;
                }
                case '*': {
                    DP[i][j] = DP[i][j - 1] || DP[i - 1][j];
                    break;
                }
                default: {
                    DP[i][j] = DP[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                    break;
                }
            }
        }
    }
    return DP.back().back();
}
}