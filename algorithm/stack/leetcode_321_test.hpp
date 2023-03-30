// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 单调栈
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_TEST_HPP

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_TEST_HPP
