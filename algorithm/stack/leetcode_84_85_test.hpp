// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 单调栈
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_84_85_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_84_85_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <limits>
#include <vector>

namespace leetcode_84 {
using std::vector;

struct leetcode_84 {
    static int32_t largestRectangleArea(const vector<int32_t> &heights);
};

TEST_CASE("test case 1 [test_84]", "[test_84]") {
    const vector<int32_t> input{2, 1, 5, 6, 2, 3};
    static constexpr const auto result{10};
    CHECK(result == leetcode_84::largestRectangleArea(input));
}

TEST_CASE("test case 2 [test_84]", "[test_84]") {
    const vector<int32_t> input{4, 2, 0, 3, 2, 5};
    static constexpr const auto result{6};
    CHECK(result == leetcode_84::largestRectangleArea(input));
}

TEST_CASE("test case 3 [test_84]", "[test_84]") {
    const vector<int32_t> input{0, 1, 0, 3, 1, 0, 1, 3, 2, 1, 2, 1};
    static constexpr const auto result{6};
    CHECK(result == leetcode_84::largestRectangleArea(input));
}
}
namespace leetcode_85 {

struct leetcode_85 {
    static int32_t maximalRectangle(const vector<vector<char>> &matrix);
};

TEST_CASE("test case 1 [test_85]", "[test_85]") {
    const vector<vector<char>> input{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '1'},
    };
    static constexpr const auto result{6};
    CHECK(result == leetcode_85::maximalRectangle(input));
}

TEST_CASE("test case 2 [test_85]", "[test_85]") {
    const vector<vector<char>> input{};
    static constexpr const auto result{0};
    CHECK(result == leetcode_85::maximalRectangle(input));
}

TEST_CASE("test case 3 [test_85]", "[test_85]") {
    const vector<vector<char>> input{
            {'1'}
    };
    static constexpr const auto result{1};
    CHECK(result == leetcode_85::maximalRectangle(input));
}

TEST_CASE("test case 4 [test_85]", "[test_85]") {
    const vector<vector<char>> input{
            {'0', '0'}
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_85::maximalRectangle(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_84_85_TEST_HPP
