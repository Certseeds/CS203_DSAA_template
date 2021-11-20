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
//@Tag stack
//@Tag 栈
//@Tag 输入保证合法
#include "leetcode_1614_test.hpp"

namespace leetcode_1614 {

int leetcode_1614::maxDepth(const string &s) {
    static const auto arr = [] {
        static auto arr = std::array<uint8_t, std::numeric_limits<uint8_t>::max() + 1>{0};
        arr['('] = '(';
        arr[')'] = '(';
        return arr;
    }();
    stack<uint8_t> sta{};
    int32_t will_return{0}, temp{0};
    for (auto &&ch: s) {
        if (arr[ch] == ch) {
            sta.push(ch);
        } else if (!sta.empty() && arr[ch] == sta.top()) {
            will_return = std::max(will_return, static_cast<int32_t>(sta.size()));
            sta.pop();
        } else {
            will_return = std::max(will_return, static_cast<int32_t>(sta.size()));
        }
        temp++;
    }
    return will_return;
}
}