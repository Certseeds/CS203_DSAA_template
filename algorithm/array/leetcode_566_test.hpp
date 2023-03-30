// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Plan 数据结构入门 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_566_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_566_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_566 {
using std::vector;

struct leetcode_566 {
    static vector<vector<int32_t>> matrixReshape(const vector<vector<int32_t>> &mat, int32_t r, int32_t c);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_566]", "[test_566]") {
    const vector<vector<int32_t>> input{{1, 2},
                                        {3, 4}};
    static constexpr const auto r{1}, c{4};
    const vector<vector<int32_t>> result{{1, 2, 3, 4}};
    CHECK_THAT(result, Equals(leetcode_566::matrixReshape(input, r, c)));
}

TEST_CASE("test case 2 [test_566]", "[test_566]") {
    const vector<vector<int32_t>> input{{1, 2},
                                        {3, 4}};
    static constexpr const auto r{2}, c{4};
    const vector<vector<int32_t>> result{input};
    CHECK_THAT(result, Equals(leetcode_566::matrixReshape(input, r, c)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_566_TEST_HPP
