// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_13_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_13_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_13 {

using std::string;

struct leetcode_13 {
    static int32_t romanToInt(const string &str);
};

TEST_CASE("test case 1 [test_13]", "[test_13]") {
    CHECK(leetcode_13::romanToInt("III") == 3);
}

TEST_CASE("test case 2 [test_13]", "[test_13]") {
    CHECK(leetcode_13::romanToInt("IV") == 4);
}

TEST_CASE("test case 3 [test_13]", "[test_13]") {
    CHECK(leetcode_13::romanToInt("IX") == 9);
}

TEST_CASE("test case 4 [test_13]", "[test_13]") {
    CHECK(leetcode_13::romanToInt("LVIII") == 58);
}

TEST_CASE("test case 5 [test_13]", "[test_13]") {
    CHECK(leetcode_13::romanToInt("MCMXCIV") == 1994);
}

TEST_CASE("test case 6 [test_13]", "[test_13]") {
    CHECK(leetcode_13::romanToInt(
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV") ==
          114514);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_13_TEST_HPP
