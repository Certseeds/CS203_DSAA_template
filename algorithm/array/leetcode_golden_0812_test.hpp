// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_golden_0812_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_golden_0812_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_golden_0812 {
using std::vector;
using std::array;

namespace leetcode_golden_0812 {
vector<vector<string>> solveNQueen(int32_t n);
}

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_golden_0812]", "[test_golden_0812]") {
    constexpr const int32_t input{1};
    const vector<vector<string>> result{{"Q"}};
    CHECK_THAT(result,
               UnorderedEquals(leetcode_golden_0812::solveNQueen(input)));
}

TEST_CASE("test case 2 3 [test_golden_0812]", "[test_golden_0812]") {
    CHECK_THAT(vector<vector<string>>{},
               UnorderedEquals(leetcode_golden_0812::solveNQueen(2)));

    CHECK_THAT(vector<vector<string>>{},
               UnorderedEquals(leetcode_golden_0812::solveNQueen(3)));
}

TEST_CASE("test case 5 [test_golden_0812]", "[test_golden_0812]") {
    CHECK_THAT((vector<vector<string>>{{
                                               ".Q..",
                                               "...Q",
                                               "Q...",
                                               "..Q.",

                                       },
                                       {
                                               "..Q.",
                                               "Q...",
                                               "...Q",
                                               ".Q..",

                                       }}),
               UnorderedEquals(leetcode_golden_0812::solveNQueen(4)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_golden_0812_TEST_HPP
