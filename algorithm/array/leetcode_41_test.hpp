// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_41 {
using std::vector;

struct leetcode_41 {
    static int firstMissingPositive(vector<int32_t> &nums);

    static int firstMissingPositive2(vector<int32_t> &nums);
};

TEST_CASE("basic test [test_41]", "[test_41]") {
    const vector<int32_t> cinput{1, 2, 0};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{3};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 2 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{3, 4, -1, 1};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{2};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 3 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{7, 8, 9, 11, 12};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{1};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 4 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{1};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{2};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 6 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{0, 1, 2};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{3};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_TEST_HPP
