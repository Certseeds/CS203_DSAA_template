

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1402_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1402_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1402 {

namespace leetcode_1402 {
int32_t maxSatisfaction(const vector<int32_t> &satisfaction);
}

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    constexpr const auto result{72};
    CHECK(result == leetcode_1402::maxSatisfaction(input));
}

TEST_CASE("1-2 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{21, 4, 7};
    constexpr const auto result{81};
    CHECK(result == leetcode_1402::maxSatisfaction(input));
}

TEST_CASE("1-3 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{-1, 0, 5, -8, -9};
    constexpr const auto result{14};
    CHECK(result == leetcode_1402::maxSatisfaction(input));
}

TEST_CASE("1-4 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{2, 4, 3};
    constexpr const auto result{20};
    CHECK(result == leetcode_1402::maxSatisfaction(input));
}

TEST_CASE("1-5 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{-1, -4, -5};
    constexpr const auto result{0};
    CHECK(result == leetcode_1402::maxSatisfaction(input));
}

TEST_CASE("1-6 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{2, -2, -3, 1};
    constexpr const auto result{6};
    CHECK(result == leetcode_1402::maxSatisfaction(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1402_TEST_HPP

