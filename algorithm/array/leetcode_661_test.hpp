// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_661_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_661_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_661 {
using std::vector;

struct leetcode_661 {
    static vector<vector<int32_t>> imageSmoother(const vector<vector<int32_t>> &M);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_661]", "[test_661]") {
    const vector<vector<int32_t>> input{{1, 1, 1},
                                        {1, 0, 1},
                                        {1, 1, 1},};
    const vector<vector<int32_t>> result{{0, 0, 0},
                                         {0, 0, 0},
                                         {0, 0, 0},};
    CHECK_THAT(result, Equals(leetcode_661::imageSmoother(input)));
}

TEST_CASE("test case 2 [test_661]", "[test_661]") {
    const vector<vector<int32_t>> input{{1, 1, 1},};
    const vector<vector<int32_t>> result{{1, 1, 1},};
    CHECK_THAT(result, Equals(leetcode_661::imageSmoother(input)));
}

TEST_CASE("test case 3 [test_661]", "[test_661]") {
    const vector<vector<int32_t>> input{{1},
                                        {1},
                                        {1},};
    const vector<vector<int32_t>> result{{1},
                                         {1},
                                         {1},};
    CHECK_THAT(result, Equals(leetcode_661::imageSmoother(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_661_TEST_HPP
