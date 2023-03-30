// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Mid
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1760_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1760_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1760 {
using std::vector;

namespace leetcode_1760 {
int32_t minimumSize(const vector<int32_t> &nums, int32_t maxOperations);
}

TEST_CASE("1 [test_1760]", "[test_1760]") {
    const vector<int32_t> nums{9};
    constexpr const auto operations{3};
    constexpr const auto minResult{3};
    CHECK(minResult == leetcode_1760::minimumSize(nums, operations));
}


TEST_CASE("2 [test_1760]", "[test_1760]") {
    const vector<int32_t> nums{2, 2, 4, 8};
    constexpr const auto operations{4};
    constexpr const auto minResult{2};
    CHECK(minResult == leetcode_1760::minimumSize(nums, operations));
}
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1760_TEST_HPP
