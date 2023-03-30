// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Plan 数据结构入门 Day2
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1 {
using std::vector;

struct leetcode_1 {
    static vector<int32_t> twoSum(const vector<int32_t> &nums, int32_t target);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic tests [test_1]", "[test_1]") {
    const vector<int32_t> vec{2, 7, 11, 15};
    const auto result = leetcode_1::twoSum(vec, 9);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int32_t>({0, 1}));
    }
}

TEST_CASE("basic tests 2 [test_1]", "[test_1]") {
    const vector<int32_t> vec{3, 2, 4};
    const auto result = leetcode_1::twoSum(vec, 6);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int32_t>({1, 2}));
    }
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_TEST_HPP
