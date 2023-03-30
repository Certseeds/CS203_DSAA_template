// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_45_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_45_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_45 {
using std::vector;

struct leetcode_45 {
    static int32_t jump(const vector<int32_t> &nums);

    static int32_t jump2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{2, 3, 1, 1, 4};
    static constexpr const auto result{2};
    CHECK(result == leetcode_45::jump(inputs));
    CHECK(result == leetcode_45::jump2(inputs));
}

TEST_CASE("2 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{2, 3, 0, 1, 4};
    static constexpr const auto result{2};
    CHECK(result == leetcode_45::jump(inputs));
    CHECK(result == leetcode_45::jump2(inputs));
}

TEST_CASE("4 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{3, 2, 1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_45::jump(inputs));
    CHECK(result == leetcode_45::jump2(inputs));
}

TEST_CASE("3 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{1, 2, 3};
    static constexpr const auto result{2};
    CHECK(result == leetcode_45::jump(inputs));
    CHECK(result == leetcode_45::jump2(inputs));
}

TEST_CASE("5 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{2, 1, 1, 1, 1};
    static constexpr const auto result{3};
    CHECK(result == leetcode_45::jump(inputs));
    CHECK(result == leetcode_45::jump2(inputs));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_45_TEST_CPP
