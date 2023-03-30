// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 模仿
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_6 {
using std::string;

struct leetcode_6 {
    static string convert(const string &s, int32_t numRows);
};


TEST_CASE("test basic [test_6]", "[test_6]") {
    CHECK(leetcode_6::convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CHECK(leetcode_6::convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CHECK(leetcode_6::convert("A", 1) == "A");
    CHECK(leetcode_6::convert("AB", 2) == "AB");
    CHECK(leetcode_6::convert("ABC", 3) == "ABC");
    CHECK(leetcode_6::convert("ABCD", 4) == "ABCD");
    CHECK(leetcode_6::convert("ABCDE", 4) == "ABCED");
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_TEST_HPP
