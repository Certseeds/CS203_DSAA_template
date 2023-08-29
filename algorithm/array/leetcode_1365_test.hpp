// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1365_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1365_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1365 {
using std::vector;

namespace leetcode_1365 {
vector<int32_t> smallerNumbersThanCurrent(const vector<int32_t> &nums);
}

using Catch::Matchers::Equals;

TEST_CASE("test case 1-1 {test_1365}", "{test_1365}") {
    const vector<int32_t> nums{8, 1, 2, 2, 3};
    const vector<int32_t> result{4, 0, 1, 1, 3};
    CHECK_THAT(result, Equals(leetcode_1365::smallerNumbersThanCurrent(nums)));
}

TEST_CASE("test case 1-2 {test_1365}", "{test_1365}") {
    const vector<int32_t> nums{6, 5, 4, 8};
    const vector<int32_t> result{2, 1, 0, 3};
    CHECK_THAT(result, Equals(leetcode_1365::smallerNumbersThanCurrent(nums)));
}

TEST_CASE("test case 1-3 {test_1365}", "{test_1365}") {
    const vector<int32_t> nums{7, 7, 7, 7};
    const vector<int32_t> result{0, 0, 0, 0};
    CHECK_THAT(result, Equals(leetcode_1365::smallerNumbersThanCurrent(nums)));
}
TEST_CASE("test case 1-4 {test_1365}", "{test_1365}") {
    const vector<int32_t> nums{0, 0, 0, 0};
    const vector<int32_t> result{0, 0, 0, 0};
    CHECK_THAT(result, Equals(leetcode_1365::smallerNumbersThanCurrent(nums)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1365_TEST_HPP
