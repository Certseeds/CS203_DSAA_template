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
//@Tag 单调栈

#include "leetcode_316_test.hpp"

namespace leetcode_316 {

string leetcode_316::removeDuplicateLetters(string_view str) {
    if (str.size() <= 1) {
        return string{str};
    }
    // 这个最重要的一点在于从"找到"
    // -> 每次删除一个char,删掉哪一个可以得到阶段性最小值?
    // 删掉从左向右数,第一个大于右边char的char
    // 再基于此得到一次性单调栈模型, 最后产出多次单调栈模型
    std::array<int32_t, (1 << 8)> uset{0}, stackSize{0};
    for (const auto ch: str) {
        uset[ch]++;
    }
    stack<size_t> sta;
    for (size_t i{0}; i < str.size(); i++) {
        const auto ch = str[i];
        if (stackSize[ch] == 0) {
            while (!sta.empty() && ch < str[sta.top()]) {
                const auto topCH{str[sta.top()]};
                if (uset[topCH] > 0) {
                    stackSize[topCH] = 0;
                    sta.pop();
                } else {
                    break;
                }
            }
            stackSize[ch] = 1;
            sta.push(i);
        }
        uset[ch]--;
    }
    vector<char> will_return{};
    while (!sta.empty()) {
        will_return.push_back(str[sta.top()]);
        sta.pop();
    }
    return {will_return.crbegin(), will_return.crend()};
}

}