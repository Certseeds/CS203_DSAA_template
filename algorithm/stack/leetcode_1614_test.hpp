// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_1614 {
using std::string;

struct leetcode_1614 {
    static int maxDepth(const string &s);
};

TEST_CASE("1 [test_1614]", "[test_1614]") {
    CHECK(1 == leetcode_1614::maxDepth("()"));
    CHECK(1 == leetcode_1614::maxDepth("(*)"));
    CHECK(2 == leetcode_1614::maxDepth("((*))"));
}

TEST_CASE("2 [test_1614]", "[test_1614]") {
    CHECK(3 == leetcode_1614::maxDepth("(1+(2*3)+((8)/4))+1"));
    CHECK(3 == leetcode_1614::maxDepth("(1)+((2))+(((3)))"));
    CHECK(1 == leetcode_1614::maxDepth("1+(2*3)/(2-1)"));
    CHECK(0 == leetcode_1614::maxDepth("1"));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_TEST_HPP
