// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#include "leetcode_69_test.hpp"
#include <algorithm>
#include <vector>
// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一
namespace leetcode_69 {
using std::vector;

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
