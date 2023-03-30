// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day6
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_152_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_152_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_152 {
using std::vector;

struct leetcode_152 final {
    static int32_t maxProduct(const vector<int32_t> &nums);

    static int32_t maxProduct2(const vector<int32_t> &nums);
};


TEST_CASE("1 [test_152]", "[test_152]") {
    const vector<int32_t> input{1, 5, 11, 5};
    static constexpr const auto result{275};
    CHECK(result == leetcode_152::maxProduct(input));
    CHECK(result == leetcode_152::maxProduct2(input));
}

TEST_CASE("2 [test_152]", "[test_152]") {
    const vector<int32_t> input{-2, 0, -1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_152::maxProduct(input));
    CHECK(result == leetcode_152::maxProduct2(input));
}

TEST_CASE("3 [test_152]", "[test_152]") {
    const vector<int32_t> input{2, 3, -2, 4};
    static constexpr const auto result{6};
    CHECK(result == leetcode_152::maxProduct(input));
    CHECK(result == leetcode_152::maxProduct2(input));
}

TEST_CASE("4 [test_152]", "[test_152]") {
    const vector<int32_t> input{-2, 4, -3};
    static constexpr const auto result{24};
    CHECK(result == leetcode_152::maxProduct(input));
    CHECK(result == leetcode_152::maxProduct2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_152_TEST_CPP
