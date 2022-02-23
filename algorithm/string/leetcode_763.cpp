/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#include "leetcode_763_test.hpp"
#include <array>

namespace leetcode_763 {
using std::array;

vector<int32_t> leetcode_763::partitionLabels(const string &S) {
    array<size_t, 26> vals{0};
    vector<int32_t> willreturn{};
    for (size_t i{0}; i < S.size(); i++) {
        vals[S[i] - 'a'] = i; // chara -> rightest pos
    }
    for (size_t left{0}, right{0}, i{0}; i < S.size(); i++) {
        right = std::max(right, vals[S[i] - 'a']);
        // this and the next judge means, if the left's range final in here.
        if (right == i) {
            willreturn.push_back(right - left + 1);
            left += willreturn.back();
        }
    }
    return willreturn;
}
}