// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day21
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_377_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_377_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_377 {
using std::vector;

struct leetcode_377 final {
    static int32_t combinationSum4(const vector<int32_t> &nums, int32_t target);
};

TEST_CASE("1 [test_377]", "[test_377]") {
    const vector<int32_t> nums{1, 2, 3};
    static constexpr const auto target{4};
    static constexpr const auto result{7};
    CHECK(result == leetcode_377::combinationSum4(nums, target));
}

TEST_CASE("2 [test_377]", "[test_377]") {
    const vector<int32_t> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190,
                               200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370,
                               380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550,
                               560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730,
                               740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910,
                               920, 930, 940, 950, 960, 970, 980, 990, 111};
    static constexpr const auto target{999};//9个111
    static constexpr const auto result{1};
    CHECK(result == leetcode_377::combinationSum4(nums, target));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_377_TEST_CPP
