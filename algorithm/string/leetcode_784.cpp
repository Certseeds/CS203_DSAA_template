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
#include "leetcode_784_test.hpp"

namespace leetcode_784 {

static constexpr const char diff = 'A' - 'a';

char low_to_up(const char &ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - diff;
    }
    return ch;
}

char up_to_low(const char &ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch + diff;
    }
    return ch;
}

vector<string> leetcode_784::letterCasePermutation(const string &S) {
    const auto s_size{S.size()};
    vector<size_t> pos;
    pos.reserve(s_size);
    for (size_t i{0}; i < s_size; ++i) {
        if (std::isalpha(S[i])) {
            pos.push_back(i);
        }
    }
    const size_t pos_size{pos.size()}, will_return_size = 1 << pos_size;
    vector<string> will_return(will_return_size, S);
    for (size_t i{0}; i < pos_size; ++i) {
        const int divisor = (1 << (pos.size() - 1 - i));
        for (size_t j{0}; j < will_return_size; ++j) {
            will_return[j][pos[i]] = ((j / divisor) % 2 == 0) ? low_to_up(S[pos[i]]) : up_to_low(S[pos[i]]);
        }
    }
    return will_return;
}

}