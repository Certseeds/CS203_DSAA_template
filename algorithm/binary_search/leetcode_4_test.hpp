/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Hard
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_HPP

#include <catch_main.hpp>
#include <vector>

namespace leetcode_4 {
using std::vector;

struct leetcode_4 {
    static double findMedianSortedArraysOn(const vector<int32_t> &nums1, const vector<int32_t> &nums2);

    static double findMedianSortedArraysOlogN(const vector<int32_t> &nums1, const vector<int32_t> &nums2);

    static double findMedianSortedArraysOlogN2(const vector<int32_t> &nums1, const vector<int32_t> &nums2);
};

TEST_CASE("1 [test 4]", "[test 4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 2);
}

TEST_CASE("2 [test 4]", "[test 4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2, 4};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 2.5f);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 2.5f);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 2.5f);
}

TEST_CASE("3 [test 4]", "[test 4]") {
    const vector<int32_t> num1{0, 0};
    const vector<int32_t> num2{0, 0};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 0);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 0);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 0);
}

TEST_CASE("4 [test 4]", "[test 4]") {
    const vector<int32_t> num1{1};
    const vector<int32_t> num2{};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 1);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 1);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 1);
}

TEST_CASE("5 [test 4]", "[test 4]") {
    const vector<int32_t> num1{2};
    const vector<int32_t> num2{};
    CHECK(leetcode_4::findMedianSortedArraysOn(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 2);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 2);
}

TEST_CASE("6 [test 4]", "[test 4]") {
    const vector<int32_t> num1{2, 2, 4, 4};
    const vector<int32_t> num2{2, 2, 4, 4};
    CHECK(leetcode_4::findMedianSortedArraysOlogN(num1, num2) == 3.0f);
    CHECK(leetcode_4::findMedianSortedArraysOlogN2(num1, num2) == 3.0f);
}
}


#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_HPP
