// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
//@Plan 数据结构入门 Day2
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_88_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_88_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_88 {
using std::vector;

struct leetcode_88 {
    static void merge(vector<int32_t> &nums1, int32_t m, const vector<int32_t> &nums2, int32_t n);
};

using Catch::Matchers::Equals;

TEST_CASE("cases [test_88]", "[test_88]") {
    vector<int32_t> vec1{};
    vector<int32_t> vec2{};
    vector<int32_t> result{};
    GIVEN("given [test_88]") {
        THEN("test_case 1 [test_88]") {
            vec1 = {4, 5, 6, 0, 0, 0};
            vec2 = {1, 2, 3};
            result = {1, 2, 3, 4, 5, 6};
        }THEN("test_case 2 [test_88]") {
            vec1 = {1, 2, 3, 0, 0, 0};
            vec2 = {2, 5, 6};
            result = {1, 2, 2, 3, 5, 6};
        }THEN("test_case 3 [test_88]") {
            vec1 = {2, 0};
            vec2 = {1};
            result = {1, 2};
        }THEN("test_case 4 [test_88]") {
            vec1 = {0};
            vec2 = {1};
            result = {1};
        }THEN("test_case 5 [test_88]") {
            vec1 = {1};
            result = {1};
        }
        leetcode_88::merge(vec1, vec1.size() - vec2.size(), vec2, vec2.size());
        CHECK_THAT(vec1, Equals(result));
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_88_TEST_HPP
