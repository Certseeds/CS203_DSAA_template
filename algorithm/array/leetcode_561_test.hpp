// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_561_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_561_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_561 {
using std::vector;

struct leetcode_561 {
    static int32_t arrayPairSum(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_561]", "[test_561]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{6};
    CHECK(result == leetcode_561::arrayPairSum(input));
}

TEST_CASE("test case 2 [test_561]", "[test_561]") {
    const vector<int32_t> input{1, 4, 3, 2};
    static constexpr const auto result{4};
    CHECK(result == leetcode_561::arrayPairSum(input));
}

TEST_CASE("test case 3 [test_561]", "[test_561]") {
    const vector<int32_t> input{6, 2, 6, 5, 1, 2};
    static constexpr const auto result{9};
    CHECK(result == leetcode_561::arrayPairSum(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_561_TEST_HPP
