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
#include "leetcode_14_test.hpp"

namespace leetcode_14 {
string leetcode_14::longestCommonPrefix(const vector<string> &strs) {
    if (strs.empty()) {
        return "";
    }
    auto length = std::min_element(std::begin(strs), std::end(strs),
                                   [](const string &s1, const string &s2) {
                                       return s1.size() < s2.size();
                                   })->size();
    string will_return = "";
    will_return.reserve(10000);
    for (size_t i = 0; i < length; i++) {
        char judge = strs[0][i];
        for (const auto &item : strs) {
            if (item[i] != judge) {
                return will_return;
            }
        }
        will_return += judge;
    }
    return will_return;
}

}