// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_7 {

struct leetcode_7 {
    static int32_t reverse(int32_t x);

    static int32_t reverse2(int32_t x);

    static int32_t reverse3(int32_t x);
};

TEST_CASE("1 [test_7]", "[test_7]") {
    CHECK(leetcode_7::reverse(123) == 321);
    CHECK(leetcode_7::reverse2(123) == 321);
    CHECK(leetcode_7::reverse3(123) == 321);
}

TEST_CASE("2 [test_7]", "[test_7]") {
    CHECK(leetcode_7::reverse(-123) == -321);
    CHECK(leetcode_7::reverse2(-123) == -321);
    CHECK(leetcode_7::reverse3(-123) == -321);
}

TEST_CASE("3 [test_7]", "[test_7]") {
    CHECK(leetcode_7::reverse(120) == 21);
    CHECK(leetcode_7::reverse2(120) == 21);
    CHECK(leetcode_7::reverse3(120) == 21);
}

TEST_CASE("4 [test_7]", "[test_7]") {
    CHECK(leetcode_7::reverse(0) == 0);
    CHECK(leetcode_7::reverse2(0) == 0);
    CHECK(leetcode_7::reverse3(0) == 0);
}

TEST_CASE("5 [test_7]", "[test_7]") {
    CHECK(leetcode_7::reverse(-2147483648) == 0);
    CHECK(leetcode_7::reverse2(-2147483648) == 0);
    CHECK(leetcode_7::reverse3(-2147483648) == 0);
}

TEST_CASE("6 [test_7]", "[test_7]") {
    CHECK(leetcode_7::reverse(1463847412) == 2147483641);
    CHECK(leetcode_7::reverse2(1463847412) == 2147483641);
    CHECK(leetcode_7::reverse3(1463847412) == 2147483641);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_TEST_HPP
