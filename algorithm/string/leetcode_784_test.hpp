// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Description 非常简单
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_784 {
using std::string;

struct leetcode_784 {
    static vector<string> letterCasePermutation(const string &S);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_784]", "[test_784]") {
    static constexpr const char *const input{"a1b2"};
    static constexpr const std::array<const char *const, 4> arr{"a1b2", "a1B2", "A1b2", "A1B2"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, UnorderedEquals(leetcode_784::letterCasePermutation(input)));
}

TEST_CASE("2 [test_784]", "[test_784]") {
    static constexpr const char *const input{"3z4"};
    static constexpr const std::array<const char *const, 2> arr{"3z4", "3Z4"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, UnorderedEquals(leetcode_784::letterCasePermutation(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP
