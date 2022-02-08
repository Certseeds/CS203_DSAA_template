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
#include "leetcode_387_test.hpp"

namespace leetcode_387 {
int leetcode_387::firstUniqChar(const string &s) {
    std::array<int32_t, 128> chars{0};
    for (const auto ch: s) {
        chars[ch]++;
    }
    for (size_t i{0}, size{s.size()}; i < size; ++i) {
        if (chars[s[i]] == 1) {
            return static_cast<int32_t>(i);
        }
    }
    return -1;
}

int leetcode_387::firstUniqChar2(const string &s) {
    std::array<std::pair<int32_t, size_t>, 128> chars{};
    for (auto iter = s.crbegin(); iter != s.crend(); ++iter) {
        const auto ch = *iter;
        ++chars[ch].first;
        chars[ch].second = s.crend() - iter;
    }
    int32_t will_return{0x3f3f3f3f};
    for (const auto&[k, v]: chars) {
        if (k == 1) {
            will_return = std::min(will_return, static_cast<int32_t>(v - 1));
        }
    }
    return will_return == 0x3f3f3f3f ? -1 : will_return;
}
}