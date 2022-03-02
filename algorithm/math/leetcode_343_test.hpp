// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag Math
//@Tag 数学
//@Plan 动态规划入门 Day21
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>

namespace leetcode_343 {

struct leetcode_343 {
    template<typename T>
    static T integerBreak(T n);
};

TEST_CASE("1 [test_343]", "[test_343]") {
    static constexpr const auto input{2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_343::integerBreak(input));
}

TEST_CASE("2 [test_343]", "[test_343]") {
    static constexpr const auto input{10};
    static constexpr const auto result{36};
    CHECK(result == leetcode_343::integerBreak(input));
}

TEST_CASE("3 [test_343]", "[test_343]") {
    static constexpr const auto input{45};
    static constexpr const auto result{14348907};
    CHECK(result == leetcode_343::integerBreak(input));
}

TEST_CASE("4 [test_343]", "[test_343]") {
    static constexpr const int64_t input{114};
    static constexpr const int64_t result{1350851717672992089};
    CHECK(result == leetcode_343::integerBreak(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP

