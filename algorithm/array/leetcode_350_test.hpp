// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 哈希表
//@Plan 数据结构入门 Day3
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_350 {
using std::vector;

struct leetcode_350 {
    static vector<int32_t> intersect(const vector<int32_t> &nums1, const vector<int32_t> &nums2);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_350]", "[test_350]") {
    const vector<int32_t> input1{1, 2, 2, 1}, input2{2, 2};
    const vector<int32_t> result{2, 2};
    CHECK_THAT(result, UnorderedEquals(leetcode_350::intersect(input1, input2)));
}

TEST_CASE("test case 2 [test_350]", "[test_350]") {
    const vector<int32_t> input1{4, 9, 5}, input2{9, 4, 9, 8, 4};
    const vector<int32_t> result{4, 9};
    CHECK_THAT(result, UnorderedEquals(leetcode_350::intersect(input1, input2)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_TEST_HPP
