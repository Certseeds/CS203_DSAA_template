// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 哈希表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_219 {
using std::vector;

struct leetcode_219 {
    static bool containsNearbyDuplicate(const vector<int32_t> &nums, int32_t k);
};

TEST_CASE("test case 1 [test_219]", "[test_219]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto k{3};
    CHECK(leetcode_219::containsNearbyDuplicate(input, k));
}

TEST_CASE("test case 2 [test_219]", "[test_219]") {
    const vector<int32_t> input{1, 0, 1, 1};
    static constexpr const auto k{1};
    CHECK(leetcode_219::containsNearbyDuplicate(input, k));
}

TEST_CASE("test case 3 [test_219]", "[test_219]") {
    const vector<int32_t> input{1, 2, 3, 1, 2, 3};
    static constexpr const auto k{2};
    CHECK_FALSE(leetcode_219::containsNearbyDuplicate(input, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_TEST_HPP
