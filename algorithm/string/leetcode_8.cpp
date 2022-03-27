// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

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