// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_657_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_657_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_657 {
using std::string;

struct leetcode_657 {
    static bool judgeCircle(const string &moves);
};

TEST_CASE("1 [test_657]", "[test_657]") {
    static constexpr const char *const input{"UD"};
    CHECK(leetcode_657::judgeCircle(input));
}

TEST_CASE("2 [test_657]", "[test_657]") {
    static constexpr const char *const input{"LL"};
    CHECK_FALSE(leetcode_657::judgeCircle(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_657_TEST_HPP
