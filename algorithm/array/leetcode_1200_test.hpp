// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1200_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1200_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1200 {
using std::vector;
using std::string;

namespace leetcode_1200 {
vector<vector<int32_t>> minimumAbsDifference(const vector<int32_t> &arr_);
}

using Catch::Matchers::Equals;

TEST_CASE("test case 1-1 {test_1200}", "{test_1200}") {
    const vector<int32_t> distance{1, 4, 5,};
    const vector<vector<int32_t>> output{{4, 5}};
    CHECK_THAT(output, Equals(leetcode_1200::minimumAbsDifference(distance)));
}

TEST_CASE("test case 1-2 {test_1200}", "{test_1200}") {
    const vector<int32_t> distance{1, 9, 8, 0};
    const vector<vector<int32_t>> output{{0, 1}, {8, 9}};
    CHECK_THAT(output, Equals(leetcode_1200::minimumAbsDifference(distance)));
}

TEST_CASE("test case 1-3 {test_1200}", "{test_1200}") {
    const vector<int32_t> distance{11, 45, 14, 191, 98, 10};
    const vector<vector<int32_t>> output{{10, 11}};
    CHECK_THAT(output, Equals(leetcode_1200::minimumAbsDifference(distance)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1200_TEST_HPP
