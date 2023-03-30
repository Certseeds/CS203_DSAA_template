// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_908_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_908_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_908 {
using std::vector;

struct leetcode_908 {
    static int32_t smallestRangeI(const vector<int32_t> &nums, int32_t k);
};

TEST_CASE("test case 1 {test_908}", "{test_908}") {
    const vector<int32_t> input{1};
    static constexpr const auto k{0};
    static constexpr const auto result{0};
    CHECK(result == leetcode_908::smallestRangeI(input, k));
}

TEST_CASE("test case 2 {test_908}", "{test_908}") {
    const vector<int32_t> input{0, 10};
    static constexpr const auto k{2};
    static constexpr const auto result{6};
    CHECK(result == leetcode_908::smallestRangeI(input, k));
}

TEST_CASE("test case 3 {test_908}", "{test_908}") {
    const vector<int32_t> input{1, 3, 6};
    static constexpr const auto k{3};
    static constexpr const auto result{0};
    CHECK(result == leetcode_908::smallestRangeI(input, k));
}

TEST_CASE("test case 4 {test_908}", "{test_908}") {
    const vector<int32_t> input{2, 7, 2};
    static constexpr const auto k{1};
    static constexpr const auto result{3};
    CHECK(result == leetcode_908::smallestRangeI(input, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_908_TEST_HPP
