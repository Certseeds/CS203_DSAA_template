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
#include "leetcode_13_test.hpp"

namespace leetcode_13 {
int32_t  leetcode_13::romanToInt(const string &s) {
    constexpr const static array<array<const char* const, 9>,3> vas {{
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
    }};
    int32_t will_return{0};
    size_t begin{0};
    int32_t added{1000};
    while (s[begin] == 'M') {
        will_return += added;
        begin++;
    }
    for (const auto &i  :vas) {
        added /= 10;
        for (auto j{i.crbegin()}; j != i.crend(); j++) {
            const auto jsize{strlen(*j)};
            if (!s.compare(begin, jsize, *j, 0, jsize)) {
                will_return += std::distance(j, i.crend() - 1 + 1) * added;
                begin += jsize;
                break;
            }
        }
    }
    return will_return;
}
}