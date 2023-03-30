// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_896_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_896_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_896 {
using std::vector;

struct leetcode_896 {
    static bool isMonotonic(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 {test_896}", "{test_896}") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    CHECK_FALSE(leetcode_896::isMonotonic(input));
}

TEST_CASE("test case 2 {test_896}", "{test_896}") {
    const vector<int32_t> input{1, 9, 1, 9, 8, 1, 0};
    CHECK_FALSE(leetcode_896::isMonotonic(input));
}

TEST_CASE("test case 3 {test_896}", "{test_896}") {
    const vector<int32_t> input{1, 2, 3, 4, 5, 6};
    CHECK(leetcode_896::isMonotonic(input));
}

TEST_CASE("test case 4 {test_896}", "{test_896}") {
    const vector<int32_t> input{1, 1, 2, 3, 4, 5, 5};
    CHECK(leetcode_896::isMonotonic(input));
}

TEST_CASE("test case 5 {test_896}", "{test_896}") {
    const vector<int32_t> input{1, 3, 2};
    CHECK_FALSE(leetcode_896::isMonotonic(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_896_TEST_HPP
