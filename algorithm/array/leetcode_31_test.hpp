// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_31_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_31_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_31 {
using std::vector;

struct leetcode_31 {
    static void nextPermutation(vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("basic test [test_31]", "[test_31]") {
    vector<int32_t> vec1{1, 2, 3};
    const vector<int32_t> _vec1{1, 3, 2};
    leetcode_31::nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("test reverse [test_31]", "[test_31]") {
    vector<int32_t> vec1{3, 2, 1};
    const vector<int32_t> _vec1{1, 2, 3};
    leetcode_31::nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("basic test 2 [test_31]", "[test_31]") {
    vector<int32_t> vec1{1, 1, 5};
    const vector<int32_t> _vec1{1, 5, 1};
    leetcode_31::nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("complex test 1 [test_31]", "[test_31]") {
    vector<int32_t> vec1{1, 2, 1, 5, 4, 3, 3, 2, 1};
    const vector<int32_t> _vec1{1, 2, 2, 1, 1, 3, 3, 4, 5};
    leetcode_31::nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("test same elements [test_31]", "[test_31]") {
    vector<int32_t> vec1{1, 1};
    const vector<int32_t> _vec1{1, 1};
    leetcode_31::nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("test just one element [test_31]", "[test_31]") {
    vector<int32_t> vec1 = {1};
    const vector<int32_t> _vec1 = {1};
    leetcode_31::nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_31_TEST_HPP
