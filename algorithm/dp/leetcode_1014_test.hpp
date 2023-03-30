// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day7

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1014_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1014_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1014 {
using std::vector;

struct leetcode_1014 {
    static int32_t maxScoreSightseeingPair(const vector<int32_t> &values) noexcept;
};

TEST_CASE("3 [test_1014]", "[test_1014]") {
    const vector<int32_t> input{4, 7, 5, 8};
    static constexpr const auto result{13};
    CHECK(result == leetcode_1014::maxScoreSightseeingPair(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1014_TEST_CPP
