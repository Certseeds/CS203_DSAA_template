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
#include "leetcode_709_test.hpp"
#include <array>

namespace leetcode_709 {
using std::array;

constexpr std::array<char, std::numeric_limits<char>::max() + 1> prepare() {
    std::array<char, std::numeric_limits<char>::max() + 1> bigs{0};
    for (char ch{'A'}; ch <= 'Z'; ++ch) {
        bigs[ch] = ('a' - 'A');
    }
    return bigs;
}

string leetcode_709::toLowerCase(const string &str) {
    static constexpr const std::array<char, prepare().size()> arr{prepare()};
    string will_return{str};
    for (auto &ch: will_return) {
        ch += arr[ch];
    }
    return will_return;
}
}