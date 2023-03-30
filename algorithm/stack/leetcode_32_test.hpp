// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 动态规划
//@Tag DP
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_32 {
using std::string;

struct leetcode_32 {
    static int32_t longestValidParentheses(const string &s);
};

TEST_CASE("test case 1 [test_32]", "[test_32]") {
    CHECK(0 == leetcode_32::longestValidParentheses(""));
    CHECK(2 == leetcode_32::longestValidParentheses("(()"));
    CHECK(2 == leetcode_32::longestValidParentheses("())"));
    CHECK(4 == leetcode_32::longestValidParentheses(")()())"));
    CHECK(6 == leetcode_32::longestValidParentheses("()(())"));
    CHECK(2 == leetcode_32::longestValidParentheses("()(()"));
    CHECK(6 == leetcode_32::longestValidParentheses("(()())"));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_TEST_HPP
