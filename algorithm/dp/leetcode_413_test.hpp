// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day10

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_413 {
using std::vector;

struct leetcode_413 final {
    static int32_t numberOfArithmeticSlices(const vector<int32_t> &nums);
};


TEST_CASE("1 [test_413]", "[test_413]") {
    const vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto output{3};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}

TEST_CASE("2 [test_413]", "[test_413]") {
    const vector<int32_t> input{1};
    static constexpr const auto output{0};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}

TEST_CASE("3 [test_413]", "[test_413]") {
    const vector<int32_t> input{1, 2, 3, 8, 9, 10};
    static constexpr const auto output{2};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}

TEST_CASE("4 [test_413]", "[test_413]") {
    const vector<int32_t> input{2, 1, 3, 4, 2, 3};
    static constexpr const auto output{0};
    CHECK(output == leetcode_413::numberOfArithmeticSlices(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP
