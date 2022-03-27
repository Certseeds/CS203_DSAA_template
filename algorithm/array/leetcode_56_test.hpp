// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_56 {
using std::vector;

struct leetcode_56 {
    static vector<vector<int32_t>> merge(const vector<vector<int32_t>> &intervals);
};

using Catch::Matchers::Equals;

TEST_CASE("1 {test_56}", "{test_56}") {
    const vector<vector<int32_t>> inputs{{1,  3},
                                         {2,  6},
                                         {8,  10},
                                         {15, 18}};
    const vector<vector<int32_t>> result{{{1, 6}, {8, 10}, {15, 18}}};
    CHECK_THAT(leetcode_56::merge(inputs), Equals(result));
}

TEST_CASE("2 {test_56}", "{test_56}") {
    const vector<vector<int32_t>> inputs{{1, 4},
                                         {4, 5}};
    const vector<vector<int32_t>> result{{{1, 5}}};
    CHECK_THAT(leetcode_56::merge(inputs), Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_TEST_HPP
