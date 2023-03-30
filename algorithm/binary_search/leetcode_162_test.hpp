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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_162_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_162_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_162 {
using std::vector;

struct leetcode_162 {
    static int32_t findPeakElement(const vector<int32_t> &nums);

    static int32_t findPeakElement2(const vector<int32_t> &nums);
};

using Catch::Matchers::Contains;

TEST_CASE("1 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 3, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_162::findPeakElement2(nums));
    CHECK(result == leetcode_162::findPeakElement(nums));
}

TEST_CASE("2 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 1, 3, 5, 6, 4};
    const vector<int32_t> resultList{1, 5};
    const auto v = leetcode_162::findPeakElement(nums);
    const auto v2 = leetcode_162::findPeakElement2(nums);
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v}));
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v2}));
}

TEST_CASE("3 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 3, 4, 3};
    static constexpr const auto result{3};
    CHECK(result == leetcode_162::findPeakElement(nums));
    CHECK(result == leetcode_162::findPeakElement2(nums));
}

TEST_CASE("4 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 1, 3, 5, 6, 4};
    const vector<int32_t> resultList{1, 5};
    const auto v = leetcode_162::findPeakElement(nums);
    const auto v2 = leetcode_162::findPeakElement2(nums);
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v}));
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v2}));
}
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_162_TEST_HPP
