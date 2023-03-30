// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_1021 {
using std::string;

struct leetcode_1021 {
    static string removeOuterParentheses(const string &str);
};

TEST_CASE("1 [test_1021]", "[test_1021]") {
    static constexpr const char *const input{"(()())(())"};
    static constexpr const char *const result{"()()()"};
    CHECK(result == leetcode_1021::removeOuterParentheses(input));
}

TEST_CASE("2 [test_1021]", "[test_1021]") {
    static constexpr const char *const input{"(())(()()())((()))"};
    static constexpr const char *const result{"()()()()(())"};
    CHECK(result == leetcode_1021::removeOuterParentheses(input));
}

TEST_CASE("3 [test_1021]", "[test_1021]") {
    static constexpr const char *const input{"()()"};
    static constexpr const char *const result{""};
    CHECK(result == leetcode_1021::removeOuterParentheses(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP
