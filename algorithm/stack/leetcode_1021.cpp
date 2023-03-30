// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 输入保证合法
#include "leetcode_1021_test.hpp"

namespace leetcode_1021 {

string leetcode_1021::removeOuterParentheses(const string &str) {
    std::string will_return{};
    const auto str_size{str.size()};
    for (size_t i{0}; i < str_size; ++i) {
        for (size_t depth{1}; depth != 0;) {
            ++i;
            if (str[i] == '(') {
                ++depth;
            } else {
                --depth;
            }
            if (depth != 0) [[likely]] {
                will_return += str[i];
            }
        }
    }
    return will_return;
}

}
