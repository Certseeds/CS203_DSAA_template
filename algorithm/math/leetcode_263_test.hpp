// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>

namespace leetcode_263 {

struct leetcode_263 {
    static bool isUgly(int32_t n);
};

TEST_CASE("1 [test_263]", "[test_263]") {
    static constexpr const auto input{6};
    CHECK(leetcode_263::isUgly(input));
}

TEST_CASE("2 [test_263]", "[test_263]") {
    static constexpr const auto input{8};
    CHECK(leetcode_263::isUgly(input));
}

TEST_CASE("3 [test_263]", "[test_263]") {
    static constexpr const auto input{14};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("4 [test_263]", "[test_263]") {
    static constexpr const auto input{1};
    CHECK(leetcode_263::isUgly(input));
}

TEST_CASE("5 [test_263]", "[test_263]") {
    static constexpr const auto input{-1};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("6 [test_263]", "[test_263]") {
    static constexpr const auto input{0};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("7 [test_263]", "[test_263]") {
    static constexpr const auto input{std::numeric_limits<int32_t>::min()};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("8 [test_263]", "[test_263]") {
    static constexpr const auto input{std::numeric_limits<int32_t>::max()};
    CHECK_FALSE(leetcode_263::isUgly(input));
}

TEST_CASE("9 [test_263]", "[test_263]") {
    static constexpr const auto input{233};
    CHECK_FALSE(leetcode_263::isUgly(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP

