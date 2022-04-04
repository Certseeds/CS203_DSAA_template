// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP

#include <catch_main.hpp>
#include <catch2/catch_approx.hpp>

#include <cassert>
#include <cstdint>

namespace leetcode_50 {
struct leetcode_50 {
    static double myPow(double x, int n);
};

using Catch::Approx;
static constexpr const auto epsilon{1e-3};

TEST_CASE("1 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{-2147483648};
    static constexpr const auto result{0.0};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}

TEST_CASE("2 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{10};
    static constexpr const auto result{1024.0};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}

TEST_CASE("3 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{-2};
    static constexpr const auto result{0.25};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}

TEST_CASE("4 [test_50]", "[test_50]") {
    static constexpr const auto x{2.1};
    static constexpr const auto n{3};
    static constexpr const auto result{9.261};
    CHECK(Approx(result).epsilon(epsilon) == leetcode_50::myPow(x, n));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP
