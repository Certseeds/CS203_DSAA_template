// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力枚举
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_532 {
using std::vector;

struct leetcode_532 {
    static int32_t findPairs(const vector<int32_t> &nums, int32_t k);
};

TEST_CASE("test case 1 [test_532]", "[test_532]") {
    const vector<int32_t> input{3, 1, 4, 1, 5};
    static constexpr const auto k{2}, result{2};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 2 [test_532]", "[test_532]") {
    const vector<int32_t> input{3, 1, 4, 2, 5};
    static constexpr const auto k{1}, result{4};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 3 [test_532]", "[test_532]") {
    const vector<int32_t> input{1, 3, 1, 5, 4};
    static constexpr const auto k{0}, result{1};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 4 [test_532]", "[test_532]") {
    const vector<int32_t> input{1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    static constexpr const auto k{3}, result{2};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 5 [test_532]", "[test_532]") {
    const vector<int32_t> input{-1, -2, -3};
    static constexpr const auto k{1}, result{2};
    CHECK(result == leetcode_532::findPairs(input, k));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_TEST_HPP
