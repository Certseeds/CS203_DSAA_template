// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
//@Plan 剑指OfferII-I Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_21_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_21_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_so_21 {
using std::vector;

struct leetcode_so_21 {
    static vector<int32_t> exchange(const vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_so_21]", "[test_so_21]") {
    const vector<int32_t> input{1, 2, 3, 4};
    const vector<int32_t> output{1, 3, 2, 4};
    CHECK_THAT(output, Equals(leetcode_so_21::exchange(input)));
}

TEST_CASE("test case 2 [test_so_21]", "[test_so_21]") {
    const vector<int32_t> input{1, 3, 5};
    const vector<int32_t> output{1, 3, 5};
    CHECK_THAT(output, Equals(leetcode_so_21::exchange(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_21_TEST_HPP
