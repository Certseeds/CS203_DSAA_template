// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day11
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_264 {
using std::vector;

struct leetcode_264 final {
    static int32_t nthUglyNumber(int32_t n);
};


TEST_CASE("1 [test_264]", "[test_264]") {
    static constexpr const auto input{10};
    static constexpr const auto result{12};
    CHECK(result == leetcode_264::nthUglyNumber(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP
