// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

namespace leetcode_14 {
using std::string;
using std::vector;

struct leetcode_14 {
    static string longestCommonPrefix(const vector<string> &strs);
};

TEST_CASE("test case 1 [test_14]", "[test_14]") {
    const vector<string> strs{"flower", "flow", "flight"};
    static constexpr const char *const result{"fl"};
    CHECK(result == leetcode_14::longestCommonPrefix(strs));
}

TEST_CASE("test case 2 [test_14]", "[test_14]") {
    const vector<string> strs{"dog", "racecar", "car"};
    CHECK(leetcode_14::longestCommonPrefix(strs).empty());

}

TEST_CASE("test case 3 [test_14]", "[test_14]") {
    const vector<string> strs{};
    CHECK(leetcode_14::longestCommonPrefix(strs).empty());
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_TEST_HPP
