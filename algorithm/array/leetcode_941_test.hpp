// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_941_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_941_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_941 {
using std::vector;

struct leetcode_941 {
    static bool validMountainArray(const vector<int32_t> &arr);
};


TEST_CASE("test case 1 {test_941}", "{test_941}") {
    const vector<int32_t> input{4, 5, 10, 7};
    CHECK(leetcode_941::validMountainArray(input));
}

TEST_CASE("test case 2 {test_941}", "{test_941}") {
    const vector<int32_t> input{0, 3, 2, 1};
    CHECK(leetcode_941::validMountainArray(input));
}

TEST_CASE("test case 3 {test_941}", "{test_941}") {
    const vector<int32_t> input{114, 514, 191};
    CHECK(leetcode_941::validMountainArray(input));
}

TEST_CASE("test case 4 {test_941}", "{test_941}") {
    const vector<int32_t> input{1, 8, 0};
    CHECK(leetcode_941::validMountainArray(input));
}

TEST_CASE("test case 5 {test_941}", "{test_941}") {
    const vector<int32_t> input{9, 1, 9};
    CHECK_FALSE(leetcode_941::validMountainArray(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_941_TEST_HPP
