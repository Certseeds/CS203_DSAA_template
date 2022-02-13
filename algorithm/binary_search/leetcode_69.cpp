/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
#include "leetcode_69_test.hpp"
#include <algorithm>

// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一
namespace leetcode_69 {

int32_t leetcode_69::mySqrt(int32_t x) {
    if (x == 0) {
        return 0;
    } else if (x <= 3) {
        return 1;
    }
    size_t begin{1}, end{static_cast<size_t>(x - 1)}, middle{0};
    while (begin <= end) {
        middle = begin + (end - begin) / 2;
        const size_t mul{middle * middle},
                mul2{mul + (middle << 1) + 1};
        if (mul <= static_cast<size_t>(x) && static_cast<size_t>(x) < mul2) {
            return static_cast<int32_t>(middle);
        }
        if (mul > static_cast<size_t>(x)) {
            end = middle - 1;
        } else if (mul < static_cast<size_t>(x)) {
            begin = middle + 1;
        }
    }
    return -1;
}


}