// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_724_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_724_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_724 {
using std::vector;

struct leetcode_724 {
    static int32_t pivotIndex(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_724]", "[test_724]") {
    const vector<int32_t> input{1, 7, 3, 6, 5, 6};
    static constexpr const auto result{3};
    CHECK(result == leetcode_724::pivotIndex(input));
}

TEST_CASE("test case 2 [test_724]", "[test_724]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{-1};
    CHECK(result == leetcode_724::pivotIndex(input));
}

TEST_CASE("test case 3 [test_724]", "[test_724]") {
    const vector<int32_t> input{2, 1, -1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_724::pivotIndex(input));
}

TEST_CASE("test case 4 [test_724]", "[test_724]") {
    const vector<int32_t> input{2, 3, -1, 8, 4};
    static constexpr const auto result{3};
    CHECK(result == leetcode_724::pivotIndex(input));
}

TEST_CASE("test case 5 [test_724]", "[test_724]") {
    const vector<int32_t> input{1, -1, 4};
    static constexpr const auto result{2};
    CHECK(result == leetcode_724::pivotIndex(input));
}

TEST_CASE("test case 6 [test_724]", "[test_724]") {
    const vector<int32_t> input{2, 5, 0};
    static constexpr const auto result{-1};
    CHECK(result == leetcode_724::pivotIndex(input));
}

TEST_CASE("test case 7 [test_724]", "[test_724]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_724::pivotIndex(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_724_TEST_HPP
