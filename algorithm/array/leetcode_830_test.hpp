// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_830_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_830_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_830 {
using std::vector;
using std::string;

struct leetcode_830 {
    static vector<vector<int32_t>> largeGroupPositions(const string &s);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_830]", "[test_830]") {
    static constexpr const char *const input{"abbxxxxzzy"};
    const vector<vector<int32_t>> output{{3, 6}};
    CHECK_THAT(output, Equals(leetcode_830::largeGroupPositions(input)));
}

TEST_CASE("test case 2 [test_830]", "[test_830]") {
    static constexpr const char *const input{"abc"};
    const vector<vector<int32_t>> output{};
    CHECK_THAT(output, Equals(leetcode_830::largeGroupPositions(input)));
}

TEST_CASE("test case 3 [test_830]", "[test_830]") {
    static constexpr const char *const input{"abcdddeeeeaabbbcd"};
    const vector<vector<int32_t>> output{{3, 5}, {6, 9}, {12, 14}};
    CHECK_THAT(output, Equals(leetcode_830::largeGroupPositions(input)));
}
TEST_CASE("test case 4 [test_830]", "[test_830]") {
    static constexpr const char *const input{"abz"};
    const vector<vector<int32_t>> output{};
    CHECK_THAT(output, Equals(leetcode_830::largeGroupPositions(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_830_TEST_HPP
