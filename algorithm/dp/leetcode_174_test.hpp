// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_174_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_174_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_174 {
using std::vector;

struct leetcode_174 final {
    static int32_t calculateMinimumHP(const vector<vector<int32_t>> &dungeon);
};

TEST_CASE("1 [test_174]", "[test_174]") {
    const vector<vector<int32_t>> inputs{{-2, -3,  3},
                                         {-5, -10, 1},
                                         {10, 30,  -5}};
    static constexpr const auto result{7};
    CHECK(result == leetcode_174::calculateMinimumHP(inputs));
}

TEST_CASE("2 [test_174]", "[test_174]") {
    const vector<vector<int32_t>> inputs{{0, -3}};
    static constexpr const auto result{4};
    CHECK(result == leetcode_174::calculateMinimumHP(inputs));
}

TEST_CASE("3 [test_174]", "[test_174]") {
    const vector<vector<int32_t>> inputs{{0}};
    static constexpr const auto result{1};
    CHECK(result == leetcode_174::calculateMinimumHP(inputs));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_174_TEST_CPP
