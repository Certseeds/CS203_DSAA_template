// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day21
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_279_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_279_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_279 {
using std::vector;

struct leetcode_279 final {
    static int32_t numSquares(int32_t n);
};


TEST_CASE("1 [test_279]", "[test_279]") {
    static constexpr const auto input{12};
    static constexpr const auto result{3};
    CHECK(result == leetcode_279::numSquares(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_279_TEST_CPP
