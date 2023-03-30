// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_674 {
using std::vector;

struct leetcode_674 {
    static int findLengthOfLCIS(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_674]", "[test_674]") {
    const vector<int32_t> input{4, 2, 3};
    static constexpr const auto result{2};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 2 [test_674]", "[test_674]") {
    const vector<int32_t> input{1, 3, 5, 4, 7};
    static constexpr const auto result{3};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 3 [test_674]", "[test_674]") {
    const vector<int32_t> input{2, 2, 2, 2, 2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 4 [test_674]", "[test_674]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 5 [test_674]", "[test_674]") {
    const vector<int32_t> input{};
    static constexpr const auto result{0};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_TEST_HPP
