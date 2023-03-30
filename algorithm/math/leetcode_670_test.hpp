// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_670_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_670_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_670 {

namespace leetcode_670 {
int32_t maximumSwap(int32_t num);
int32_t maximumSwap2(int32_t num);
}

TEST_CASE("1 [test_670]", "[test_670]") {
    static constexpr const auto input{2763};
    static constexpr const auto result{7263};
    CHECK(result == leetcode_670::maximumSwap(input));
    CHECK(result == leetcode_670::maximumSwap2(input));
}

TEST_CASE("2 [test_670]", "[test_670]") {
    static constexpr const auto input{9973};
    static constexpr const auto result{9973};
    CHECK(result == leetcode_670::maximumSwap(input));
    CHECK(result == leetcode_670::maximumSwap2(input));
}

TEST_CASE("3 [test_670]", "[test_670]") {
    static constexpr const auto input{114514};
    static constexpr const auto result{514114};
    CHECK(result == leetcode_670::maximumSwap(input));
    CHECK(result == leetcode_670::maximumSwap2(input));
}

TEST_CASE("4 [test_670]", "[test_670]") {
    static constexpr const auto input{1919810};
    static constexpr const auto result{9911810};
    CHECK(result == leetcode_670::maximumSwap(input));
    CHECK(result == leetcode_670::maximumSwap2(input));
}

TEST_CASE("5 [test_670]", "[test_670]") {
    static constexpr const auto input{99901};
    static constexpr const auto result{99910};
    CHECK(result == leetcode_670::maximumSwap(input));
    CHECK(result == leetcode_670::maximumSwap2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_670_TEST_HPP

