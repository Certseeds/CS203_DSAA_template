// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1047_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1047_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_1047 {
using std::string;

struct leetcode_1047 {
    static string removeDuplicates(const string &s);
};

TEST_CASE("1 [test_1047]", "[test_1047]") {
    static constexpr const char *const input{"abbaca"};
    static constexpr const char *const result{"ca"};
    CHECK(result == leetcode_1047::removeDuplicates(input));
}

TEST_CASE("2 [test_1047]", "[test_1047]") {
    static constexpr const char *const input{"114514"};
    static constexpr const char *const result{"4514"};
    CHECK(result == leetcode_1047::removeDuplicates(input));
}

TEST_CASE("3 [test_1047]", "[test_1047]") {
    static constexpr const char *const input{"1919810"};
    static constexpr const char *const result{"1919810"};
    CHECK(result == leetcode_1047::removeDuplicates(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1047_TEST_HPP
