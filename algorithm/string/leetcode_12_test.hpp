// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_TEST_HPP

#include <catch_main.hpp>
#include <array>
#include <string>
#include <vector>

namespace leetcode_12 {

using std::array;
using std::string;
using std::vector;

struct leetcode_12 {
    static string intToRoman(int num);

    static string intToRoman_2(int num);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_12]", "[test_12]") {
    static constexpr const auto input{3};
    static constexpr const char *const result{"III"};
    CHECK_THAT(result, Equals(leetcode_12::intToRoman(input)));
    CHECK_THAT(result, Equals(leetcode_12::intToRoman_2(input)));
}

TEST_CASE("test case 2 [test_12]", "[test_12]") {
    static constexpr const auto input{4};
    static constexpr const char *const result{"IV"};
    CHECK_THAT(result, Equals(leetcode_12::intToRoman(input)));
    CHECK_THAT(result, Equals(leetcode_12::intToRoman_2(input)));
}

TEST_CASE("test case 3 [test_12]", "[test_12]") {
    static constexpr const auto input{9};
    static constexpr const char *const result{"IX"};
    CHECK_THAT(result, Equals(leetcode_12::intToRoman(input)));
    CHECK_THAT(result, Equals(leetcode_12::intToRoman_2(input)));
}

TEST_CASE("test case 4 [test_12]", "[test_12]") {
    static constexpr const auto input{58};
    static constexpr const char *const result{"LVIII"};
    CHECK_THAT(result, Equals(leetcode_12::intToRoman(input)));
    CHECK_THAT(result, Equals(leetcode_12::intToRoman_2(input)));
}

TEST_CASE("test case 5 [test_12]", "[test_12]") {
    static constexpr const auto input{1994};
    static constexpr const char *const result{"MCMXCIV"};
    CHECK_THAT(result, Equals(leetcode_12::intToRoman(input)));
    CHECK_THAT(result, Equals(leetcode_12::intToRoman_2(input)));
}

TEST_CASE("test case 6 [test_12]", "[test_12]") {
    static constexpr const auto input{114514};
    static constexpr const char *const result{
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV"};
    CHECK_THAT(result, Equals(leetcode_12::intToRoman(input)));
    CHECK_THAT(result, Equals(leetcode_12::intToRoman_2(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_TEST_HPP
