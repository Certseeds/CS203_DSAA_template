// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_48_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_48_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_48 {
using std::vector;

struct leetcode_48 {
    static vector<vector<int32_t>> rotate_(const vector<vector<int32_t>> &matrix) {
        vector<vector<int32_t>> mut{matrix};
        rotate(mut);
        return mut;
    }

    static void rotate(vector<vector<int32_t>> &matrix);
};

using Catch::Matchers::Equals;

TEST_CASE("basic test [test_48]", "[test_48]") {
    const vector<vector<int32_t>> input{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    const vector<vector<int32_t>> result{
            {7, 4, 1},
            {8, 5, 2},
            {9, 6, 3}
    };
    CHECK_THAT(result, Equals(leetcode_48::rotate_(input)));
}

TEST_CASE("basic test 2 [test_48]", "[test_48]") {
    const vector<vector<int32_t>> input{
            {5,  1,  9,  11},
            {2,  4,  8,  10},
            {13, 3,  6,  7},
            {15, 14, 12, 16}
    };
    const vector<vector<int32_t>> result{
            {15, 13, 2,  5},
            {14, 3,  4,  1},
            {12, 6,  8,  9},
            {16, 7,  10, 11}
    };
    CHECK_THAT(result, Equals(leetcode_48::rotate_(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_48_TEST_HPP
