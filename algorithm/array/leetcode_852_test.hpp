// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_852_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_852_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_852 {
using std::vector;

struct leetcode_852 {
    static int32_t peakIndexInMountainArray(const vector<int32_t> &A);
};

TEST_CASE("test case 1 [test_852]", "[test_852]") {
    const vector<int32_t> inputs{0, 1, 0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_852::peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 2 [test_852]", "[test_852]") {
    const vector<int32_t> inputs{0, 2, 1, 0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_852::peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 3 [test_852]", "[test_852]") {
    const vector<int32_t> inputs{0, 10, 5, 2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_852::peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 4 [test_852]", "[test_852]") {
    const vector<int32_t> inputs{3, 4, 5, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_852::peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 5 [test_852]", "[test_852]") {
    const vector<int32_t> inputs{24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    static constexpr const auto result{2};
    CHECK(result == leetcode_852::peakIndexInMountainArray(inputs));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_852_TEST_HPP
