// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_69_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_69_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一

namespace leetcode_69 {
struct leetcode_69 final {
    static int32_t mySqrt(int32_t x);
};

TEST_CASE("test case 0", "[test leetcode_69]") {
    CHECK(0 == leetcode_69::mySqrt(0));
    CHECK(1 == leetcode_69::mySqrt(1));
    CHECK(1 == leetcode_69::mySqrt(1));
    CHECK(1 == leetcode_69::mySqrt(1));
}

TEST_CASE("test case 1", "[test leetcode_69]") {
    static constexpr const auto input{4}, result{2};
    CHECK(result == leetcode_69::mySqrt(input));
}

TEST_CASE("test case 2", "[test leetcode_69]") {
    static constexpr const auto input{8}, result{2};
    CHECK(result == leetcode_69::mySqrt(input));
}

TEST_CASE("test case 3", "[test leetcode_69]") {
    static constexpr const auto input{9}, result{3};
    CHECK(result == leetcode_69::mySqrt(input));
}

TEST_CASE("test case 4", "[test leetcode_69]") {
    static constexpr const auto input{6}, result{2};
    CHECK(result == leetcode_69::mySqrt(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_69_TEST_HPP

