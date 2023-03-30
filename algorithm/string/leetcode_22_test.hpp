// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag DP
//@Tag 回溯
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_22_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_22_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

namespace leetcode_22 {

using std::string;
using std::vector;

struct leetcode_22 {
    static vector<string> generateParenthesis(int32_t n);
};

static const vector<string> gene5{
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
};
using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_22]", "[test_22]") {
    CHECK(leetcode_22::generateParenthesis(1).size() == 1);
    CHECK(leetcode_22::generateParenthesis(2).size() == 2);
    CHECK(leetcode_22::generateParenthesis(3).size() == 5);
    CHECK(leetcode_22::generateParenthesis(4).size() == 14);
    CHECK_THAT(leetcode_22::generateParenthesis(3), UnorderedEquals(gene5));
}

TEST_CASE("2 [test_22]", "[test_22]") {
    for (int32_t i{1}; i < 5; i++) {
        CHECK_THAT(leetcode_22::generateParenthesis(i), UnorderedEquals(leetcode_22::generateParenthesis(i)));
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_22_TEST_HPP
