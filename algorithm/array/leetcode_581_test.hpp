// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_581 {
using std::vector;

struct leetcode_581 {
    static int32_t findUnsortedSubarray(const vector<int32_t> &nums);

    static int32_t findUnsortedSubarray2(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_581]", "[test_581]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{4};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}

TEST_CASE("test case 2 [test_581]", "[test_581]") {
    const vector<int32_t> input{2, 6, 4, 8, 10, 9, 15};
    static constexpr const auto result{5};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}

TEST_CASE("test case 3 [test_581]", "[test_581]") {
    const vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto result{0};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}

TEST_CASE("test case 4 [test_581]", "[test_581]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP
