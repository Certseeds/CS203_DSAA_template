// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_867 {
using std::vector;

struct leetcode_867 {
    static vector<vector<int32_t>> transpose(const vector<vector<int32_t>> &A);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_867}", "{test_867}") {
    const vector<vector<int32_t>> inputs{{{1, 2, 3},
                                          {4, 5, 6},
                                          {7, 8, 9}}};
    const vector<vector<int32_t>> result{{{1, 4, 7},
                                          {2, 5, 8},
                                          {3, 6, 9}}};
    CHECK_THAT(result, Equals(leetcode_867::transpose(inputs)));
}

TEST_CASE("test case 2 {test_867}", "{test_867}") {
    const vector<vector<int32_t>> inputs{{1, 2, 3},
                                         {4, 5, 6}};
    const vector<vector<int32_t>> result{{1, 4},
                                         {2, 5},
                                         {3, 6}};
    CHECK_THAT(result, Equals(leetcode_867::transpose(inputs)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
