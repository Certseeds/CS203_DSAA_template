/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

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
//@Tag stack
//@Tag 栈
//@Tag 单调栈
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_321 {
using std::vector;

struct leetcode_321 {
    static vector<int32_t> maxNumber(const vector<int32_t> &nums1, const vector<int32_t> &nums2, size_t k);
};

using Catch::Matchers::Equals;

TEST_CASE("2 [test_321]", "[test_321]") {
    const vector<int32_t> nums1{6, 7};
    const vector<int32_t> nums2{6, 0, 7};
    static constexpr const auto k{5};
    const vector<int32_t> number{6, 7, 6, 0, 7};
    CHECK_THAT(number, Equals(leetcode_321::maxNumber(nums1, nums2, k)));
}

TEST_CASE("3 [test_321]", "[test_321]") {
    const vector<int32_t> nums1{3, 9};
    const vector<int32_t> nums2{8, 9};
    static constexpr const auto k{3};
    const vector<int32_t> number{9, 8, 9};
    CHECK_THAT(number, Equals(leetcode_321::maxNumber(nums1, nums2, k)));
}

TEST_CASE("1 [test_321]", "[test_321]") {
    const vector<int32_t> nums1{3, 4, 6, 5};
    const vector<int32_t> nums2{9, 1, 2, 5, 8, 3};
    static constexpr const auto k{5};
    const vector<int32_t> number{9, 8, 6, 5, 3};
    CHECK_THAT(number, Equals(leetcode_321::maxNumber(nums1, nums2, k)));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_HPP
