// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Plan 数据结构入门 Day9

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_20 {
using std::string;

struct leetcode_20 {
    static bool isValid(const string &s);
};

TEST_CASE("test case 1 [test_20]", "[test_20]") {
    CHECK(leetcode_20::isValid("()"));
    CHECK(leetcode_20::isValid("()[]{}"));
    CHECK(leetcode_20::isValid("(()[]{})[()[]{}]{()[]{}}"));
    CHECK(leetcode_20::isValid("(((()[]{})[()[]{}]{()[]{}})[]{})[()[]{}]{()[]{}}"));
}

TEST_CASE("test case 0 [test_20]", "[test_20]") {
    CHECK_FALSE(leetcode_20::isValid("(]"));
    CHECK_FALSE(leetcode_20::isValid("(}"));
    CHECK_FALSE(leetcode_20::isValid("[}"));
    CHECK_FALSE(leetcode_20::isValid("[)"));
    CHECK_FALSE(leetcode_20::isValid("{)"));
    CHECK_FALSE(leetcode_20::isValid("{]"));
    CHECK_FALSE(leetcode_20::isValid("([)]"));
    CHECK_FALSE(leetcode_20::isValid("(((()[]{})[()[]{}]{()[]{}})[]{))[()[]{}]{()[]{}}"));
}

TEST_CASE("test case 2-2 [test_20]", "[test_20]") {
    CHECK_FALSE(leetcode_20::isValid("([)]"));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_TEST_HPP
