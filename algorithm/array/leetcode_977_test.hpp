// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_977_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_977_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_977 {
using std::vector;

struct leetcode_977 {
    static vector<int32_t> sortedSquares(const vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_977}", "{test_977}") {
    const vector<int32_t> input{-4, -1, 0, 3, 10};
    const vector<int32_t> result{0, 1, 9, 16, 100};
    CHECK_THAT(result, Equals(leetcode_977::sortedSquares(input)));
}

TEST_CASE("test case 2 {test_977}", "{test_977}") {
    const vector<int32_t> input{-7, -3, 2, 3, 11};
    const vector<int32_t> result{4, 9,9, 49, 121};
    CHECK_THAT(result, Equals(leetcode_977::sortedSquares(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_977_TEST_HPP
