// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag "双"指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1013_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1013_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1013 {
using std::vector;

struct leetcode_1013 {
    static bool canThreePartsEqualSum(const vector<int32_t> &arr);
};

TEST_CASE("test case 1 {test_1013}", "{test_1013}") {
    const vector<int32_t> input{1, -1, 1, -1};
    CHECK_FALSE(leetcode_1013::canThreePartsEqualSum(input));
}

TEST_CASE("test case 5 {test_1013}", "{test_1013}") {
    const vector<int32_t> input{0, 1, -1, 1, -1, 0};
    CHECK(leetcode_1013::canThreePartsEqualSum(input));
}

TEST_CASE("test case 2 {test_1013}", "{test_1013}") {
    const vector<int32_t> input{3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    CHECK(leetcode_1013::canThreePartsEqualSum(input));
}

TEST_CASE("test case 3 {test_1013}", "{test_1013}") {
    const vector<int32_t> input{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    CHECK(leetcode_1013::canThreePartsEqualSum(input));
}

TEST_CASE("test case 4 {test_1013}", "{test_1013}") {
    const vector<int32_t> input{0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    CHECK_FALSE(leetcode_1013::canThreePartsEqualSum(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1013_TEST_HPP
