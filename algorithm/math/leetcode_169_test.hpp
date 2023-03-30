// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_169_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_169_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_169 {
using std::vector;

struct leetcode_169 {
    static int32_t majorityElement(const vector<int32_t> &nums);

    static int32_t majorityElement2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_169]", "[test_169]") {
    const vector<int32_t> input{3, 4, 3};
    static constexpr const auto result{3};
    CHECK(result == leetcode_169::majorityElement(input));
    CHECK(result == leetcode_169::majorityElement2(input));
}

TEST_CASE("2 [test_169]", "[test_169]") {
    const vector<int32_t> input{1, 0, 1, 1, 0, 1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_169::majorityElement(input));
    CHECK(result == leetcode_169::majorityElement2(input));
}

TEST_CASE("3 [test_169]", "[test_169]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_169::majorityElement(input));
    CHECK(result == leetcode_169::majorityElement2(input));
}

TEST_CASE("4 [test_169]", "[test_169]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4, 1, 9, 1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_169::majorityElement(input));
    CHECK(result == leetcode_169::majorityElement2(input));
}

TEST_CASE("5 [test_169]", "[test_169]") {
    const vector<int32_t> input{2, 2, 1, 1, 1, 2, 2};
    static constexpr const auto result{2};
    CHECK(result == leetcode_169::majorityElement(input));
    CHECK(result == leetcode_169::majorityElement2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_169_TEST_HPP

