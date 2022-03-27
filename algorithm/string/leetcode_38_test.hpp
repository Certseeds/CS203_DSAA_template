// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_38 {

using std::string;

struct leetcode_38 {
    static string countAndSay(int32_t n);
};

TEST_CASE("1 [test_38]", "[test_38]") {
    CHECK(leetcode_38::countAndSay(1) == "1");
    CHECK(leetcode_38::countAndSay(2) == "11");
    CHECK(leetcode_38::countAndSay(3) == "21");
    CHECK(leetcode_38::countAndSay(4) == "1211");
    CHECK(leetcode_38::countAndSay(5) == "111221");
    CHECK(leetcode_38::countAndSay(6) == "312211");
    CHECK(leetcode_38::countAndSay(7) == "13112221");
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_TEST_HPP
