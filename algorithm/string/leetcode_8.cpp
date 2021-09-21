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
#include "leetcode_8_test.hpp"

namespace leetcode_8 {

int leetcode_8::myAtoi(const string &str) {
    size_t begin{0};
    int8_t sign{1};
    int64_t will_return{0};
    while (str[begin] == ' ') {
        begin++;
    }
    if (str[begin] >= 'a' && str[begin] <= 'z') {
        return 0;
    } else if (str[begin] == '+') {
        begin++;
    } else if (str[begin] == '-') {
        sign = -1;
        begin++;
    }
    while (str[begin] >= '0' && str[begin] <= '9') {
        will_return = will_return * 10 + (str[begin] - '0');
        begin++;
        if (will_return > std::numeric_limits<int32_t>::max()) {
            return sign == 1 ? std::numeric_limits<int32_t>::max() :
                   std::numeric_limits<int32_t>::min();
        }
    }
    return static_cast<int32_t>(will_return * sign);
}
}