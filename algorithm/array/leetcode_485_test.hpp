// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_485_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_485_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_485 {
using std::vector;

struct leetcode_485 {
    static int32_t findMaxConsecutiveOnes(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_485]", "[test_485]") {
    const vector<int32_t> input{1, 0, 1, 1, 0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_485::findMaxConsecutiveOnes(input));
}

TEST_CASE("test case 2 [test_485]", "[test_485]") {
    const vector<int32_t> input{1, 1, 0, 1, 1, 1};
    static constexpr const auto result{3};
    CHECK(result == leetcode_485::findMaxConsecutiveOnes(input));
}

TEST_CASE("test case 3 [test_485]", "[test_485]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_485::findMaxConsecutiveOnes(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_485_TEST_HPP
