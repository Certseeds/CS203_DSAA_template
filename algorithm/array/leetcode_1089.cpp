// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1089_test.hpp"
#include <algorithm>

namespace leetcode_1089 {

void leetcode_1089::duplicateZeros(vector<int> &arr) {
    const auto arr_size{arr.size()};
    size_t left_pointer{0}, right_pointer{0};
    for (; left_pointer < arr_size && right_pointer < arr_size; left_pointer += 1, right_pointer += 1) {
        if (arr[left_pointer] == 0) {
            right_pointer += 1;
        }
    }// 先进行一次模拟step by step,之后反演
    // 不能只从左向右扫描0的个数,可能前面的会把后面的给"顶"出去
    for (; left_pointer > 0 && right_pointer > 0; left_pointer -= 1, right_pointer -= 1) {
        const auto left_number{arr[left_pointer - 1]};
        if (left_number != 0) {
            arr[right_pointer - 1] = arr[left_pointer - 1];
        } else {
            right_pointer -= 1;
            if (right_pointer < arr_size) [[unlikely]] { // max once
                arr[right_pointer] = 0;
            }
            arr[right_pointer - 1] = 0;
        }
    }
}

}
