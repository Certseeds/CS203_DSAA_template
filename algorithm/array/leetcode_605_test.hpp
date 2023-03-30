// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_605_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_605_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_605 {
using std::vector;

struct leetcode_605 {
    static bool canPlaceFlowers(const vector<int32_t> &urinal, int32_t n);
};

TEST_CASE("test case 1 [test_605]", "[test_605]") {
    const vector<int32_t> input{1, 0, 0, 0, 1};
    static constexpr const auto n{1};
    CHECK(leetcode_605::canPlaceFlowers(input, n));
}

TEST_CASE("test case 2 [test_605]", "[test_605]") {
    const vector<int32_t> input{1, 0, 0, 0, 1};
    static constexpr const auto n{2};
    CHECK_FALSE(leetcode_605::canPlaceFlowers(input, n));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_605_TEST_HPP
