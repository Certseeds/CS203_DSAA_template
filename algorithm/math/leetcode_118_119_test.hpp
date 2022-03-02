// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 数学问题
//@Plan 动态规划入门 Day12
//@Plan 数据结构入门 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_118 {
using std::vector;

struct leetcode_118 {
    static vector<vector<int32_t>> generate(int32_t numRows);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_118]", "[test_118]") {
    static constexpr const auto input{5};
    const vector<vector<int32_t>> result{
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
    };
    CHECK_THAT(result, Equals(leetcode_118::generate(input)));
}


TEST_CASE("2 [test_118]", "[test_118]") {
    static constexpr const auto input{1};
    const vector<vector<int32_t>> result{
            {1},
    };
    CHECK_THAT(result, Equals(leetcode_118::generate(input)));
}
}
namespace leetcode_119 {
using std::vector;

struct leetcode_119 {
    static vector<int32_t> getRow(int32_t rowIndex);

    static vector<int32_t> getRowN(int32_t rowIndex);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_119]", "[test_119]") {
    static constexpr const auto input{3};
    const vector<int32_t> result{1, 3, 3, 1};
    CHECK_THAT(result, Equals(leetcode_119::getRow(input)));
    CHECK_THAT(result, Equals(leetcode_119::getRowN(input)));
}


TEST_CASE("2 [test_119]", "[test_119]") {
    static constexpr const auto input{1};
    const vector<int32_t> result{1, 1};
    CHECK_THAT(result, Equals(leetcode_119::getRow(input)));
    CHECK_THAT(result, Equals(leetcode_119::getRowN(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP
