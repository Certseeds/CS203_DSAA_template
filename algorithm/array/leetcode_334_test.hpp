// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag DP
//@Plan 数据结构基础 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_334_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_334_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_334 {
using std::vector;

struct leetcode_334 {
    static bool increasingTriplet(const vector<int32_t> &nums);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_334]", "[test_334]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    CHECK(leetcode_334::increasingTriplet(input));
}

TEST_CASE("test case 2 [test_334]", "[test_334]") {
    const vector<int32_t> input{5, 4, 3, 2, 1};
    CHECK_FALSE(leetcode_334::increasingTriplet(input));
}

TEST_CASE("test case 3 [test_334]", "[test_334]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    CHECK(leetcode_334::increasingTriplet(input));
}

TEST_CASE("test case 4 [test_334]", "[test_334]") {
    const vector<int32_t> input{5, 1, 6};
    CHECK_FALSE(leetcode_334::increasingTriplet(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_334_TEST_HPP
