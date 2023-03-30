// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Hard
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_4 {
using std::vector;

struct leetcode_4 {
    static double findMedianSortedArraysOn(const vector<int32_t> &nums1, const vector<int32_t> &nums2);

    static double findMedianSortedArraysOlogN(const vector<int32_t> &nums1, const vector<int32_t> &nums2);

    static double findMedianSortedArraysOlogN2(const vector<int32_t> &nums1, const vector<int32_t> &nums2);
};

TEST_CASE("1 [test_4]", "[test_4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 2);
}

TEST_CASE("2 [test_4]", "[test_4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2, 4};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 2.5f);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 2.5f);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 2.5f);
}

TEST_CASE("3 [test_4]", "[test_4]") {
    const vector<int32_t> num1{0, 0};
    const vector<int32_t> num2{0, 0};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 0);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 0);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 0);
}

TEST_CASE("4 [test_4]", "[test_4]") {
    const vector<int32_t> num1{1};
    const vector<int32_t> num2{};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 1);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 1);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 1);
}

TEST_CASE("5 [test_4]", "[test_4]") {
    const vector<int32_t> num1{2};
    const vector<int32_t> num2{};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 2);
}

TEST_CASE("6 [test_4]", "[test_4]") {
    const vector<int32_t> num1{2, 2, 4, 4};
    const vector<int32_t> num2{2, 2, 4, 4};
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 3.0f);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 3.0f);
}
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_TEST_HPP
