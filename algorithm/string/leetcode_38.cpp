// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_38_test.hpp"

namespace leetcode_38 {
string leetcode_38::countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    string str1{countAndSay(n - 1)};
    string will_return{};
    const auto str1_size{str1.size()};
    for (size_t i{0}; i < str1_size;) {
        int32_t length{0};
        while (str1[i + length] == str1[i]) {
            length++;
        }
        will_return.append(1, length + '0');
        will_return.append(1, str1[i]);
        i += length;
    }
    return will_return;
}
}