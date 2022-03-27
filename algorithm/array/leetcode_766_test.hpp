// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_766_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_766_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_766 {
using std::vector;

struct leetcode_766 {
    static bool isToeplitzMatrix(const vector<vector<int32_t>> &matrix);
};

TEST_CASE("test case 2 [test_766]", "[test_766]") {
    const vector<vector<int32_t>> input{
            {1, 2, 3, 4},
            {5, 1, 2, 3},
            {9, 5, 1, 2},
    };
    CHECK(leetcode_766::isToeplitzMatrix(input));
}

TEST_CASE("test case 1 [test_766]", "[test_766]") {
    const vector<vector<int32_t>> input{
            {1, 2},
            {2, 2},
    };
    CHECK_FALSE(leetcode_766::isToeplitzMatrix(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_766_TEST_HPP
