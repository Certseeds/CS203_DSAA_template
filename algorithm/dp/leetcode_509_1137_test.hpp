// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day1
//@Plan 剑指OfferII-I Day08
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_509_1137_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_509_1137_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_509 {

struct leetcode_509 final {
    static int32_t fib(int32_t n);
};


TEST_CASE("1 [test_509]", "[test_509]") {
    static constexpr const auto input{2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_509::fib(input));
}

TEST_CASE("2 [test_509]", "[test_509]") {
    static constexpr const auto input{3};
    static constexpr const auto result{2};
    CHECK(result == leetcode_509::fib(input));
}

TEST_CASE("3 [test_509]", "[test_509]") {
    static constexpr const auto input{4};
    static constexpr const auto result{3};

    CHECK(result == leetcode_509::fib(input));
}

}

namespace leetcode_1137 {
using std::array;

struct leetcode_1137 final {
    static int32_t tribonacci(int32_t n);
};

TEST_CASE("1 [test_1137]", "[test_1137]") {
    static constexpr const auto input{4};
    static constexpr const auto result{4};
    CHECK(result == leetcode_1137::tribonacci(input));
}

TEST_CASE("2 [test_1137]", "[test_1137]") {
    static constexpr const auto input{0};
    static constexpr const auto result{0};
    CHECK(result == leetcode_1137::tribonacci(input));
}

TEST_CASE("3 [test_1137]", "[test_1137]") {
    static constexpr const auto input{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_1137::tribonacci(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_509_1137_TEST_CPP
