// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day3
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_740_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_740_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_740 {
using std::vector;

struct leetcode_740 final {
    static int deleteAndEarn(const vector<int> &nums);
};


TEST_CASE("1 [test_740]", "[test_740]") {
    const vector<int32_t> input{3, 4, 2};
    static constexpr const auto result{6};
    CHECK(result == leetcode_740::deleteAndEarn(input));
}

TEST_CASE("2 [test_740]", "[test_740]") {
    const vector<int32_t> input{2, 2, 3, 3, 3, 4};
    static constexpr const auto result{9};
    CHECK(result == leetcode_740::deleteAndEarn(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_740_TEST_CPP
