// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_75_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_75_TEST_HPP

#include <catch_main.hpp>
#include <catch2/catch_approx.hpp>

#include <cassert>
#include <cstdint>

namespace leetcode_75 {
struct leetcode_75 {
    static void sortColors(vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_75]", "[test_75]") {
    const vector<int32_t> input{2, 0, 1, 2, 2, 2, 0, 0, 0, 0, 1, 1};
    const vector<int32_t> result{0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2};
    vector<int32_t> input_v{input};
    leetcode_75::sortColors(input_v);
    CHECK_THAT(result, Equals(input_v));
}

TEST_CASE("2 [test_75]", "[test_75]") {
    const vector<int32_t> input{2, 0, 1};
    const vector<int32_t> result{0, 1, 2};
    vector<int32_t> input_v{input};
    leetcode_75::sortColors(input_v);
    CHECK_THAT(result, Equals(input_v));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_75_TEST_HPP
