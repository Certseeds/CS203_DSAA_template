// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 烤馍片
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_28 {
using std::string;

struct leetcode_28 {
    static int32_t strStr(const string &haystack, const string &needle);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_28]", "[test_28]") {
    CHECK(leetcode_28::strStr("hello", "ll") == 2);
    CHECK(leetcode_28::strStr("aaaaa", "bba") == -1);
    CHECK(leetcode_28::strStr("aaaaa", "") == 0);
    CHECK(leetcode_28::strStr("a", "a") == 0);
    CHECK(leetcode_28::strStr("mississippi", "issi") == 1);
    CHECK(leetcode_28::strStr("mississippi", "issip") == 4);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP
