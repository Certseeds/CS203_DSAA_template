/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanos
 * @Date: 2021-04-03 10:15:42
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
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
//@Tag 贪心
#include "leetcode_678_test.hpp"

namespace leetcode_678 {

bool leetcode_678::checkValidString(const string &s) {
    int32_t order{0};
    stack<int32_t> s1{}, s2{};
    for (auto &&ch: s) {
        if (ch == '(') {
            s1.push(order);
        } else if (ch == '*') {
            s2.push(order);
        } else {
            if (!s1.empty()) {
                s1.pop();
            } else if (!s2.empty()) {
                s2.pop();
            } else {
                return false;
            }
        }
        order++;
    }
    if (s1.size() > s2.size()) {
        return false;
    }
    while (!s1.empty() && !s2.empty()) {
        if (s1.top() > s2.top()) {
            return false;
        }
        s1.pop();
        s2.pop();
    }
    return true;
}

bool leetcode_678::checkValidString2(const string &s) {
    int32_t low{0}, high{0};
    for (auto &&ch: s) {
        if (ch == '(') {
            low++;
            high++;
        } else if (ch == '*') {
            low = std::max(0, low - 1); // mayBe match a )
            high++;
        } else {
            high--;
            low = std::max(0, low - 1);
            if (high < 0) {
                return false;
            }
        }
    }
    if (low == 0) {
        return true;
    }
    return false;
}
}