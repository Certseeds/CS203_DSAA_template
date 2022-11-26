// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1217_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1217_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1217 {
using std::vector;
using std::string;

namespace leetcode_1217 {
int32_t minCostToMoveChips(const vector<int32_t> &position);
}

TEST_CASE("test case 1-1 {test_1217}", "{test_1217}") {
    const vector<int32_t> input{1, 4, 5,};
    const auto output = leetcode_1217::minCostToMoveChips(input);
    constexpr const auto result{1};
    CHECK(result == output);
}

TEST_CASE("test case 1-2 {test_1217}", "{test_1217}") {
    const vector<int32_t> input{1, 2, 3,};
    const auto output = leetcode_1217::minCostToMoveChips(input);
    constexpr const auto result{1};
    CHECK(result == output);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1217_TEST_HPP
