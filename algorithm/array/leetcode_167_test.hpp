// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_167 {
using std::vector;

struct leetcode_167 {
    static vector<int32_t> twoSum(const vector<int32_t> &numbers, int32_t target);

    static vector<int32_t> twoSum2(const vector<int32_t> &numbers, int32_t target);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_167]", "[test_167]") {
    const vector<int32_t> input{2, 7, 11, 15};
    static constexpr const auto target{9};
    const vector<int32_t> result{1, 2};
    CHECK_THAT(leetcode_167::twoSum(input, target), Equals(result));
    CHECK_THAT(leetcode_167::twoSum2(input, target), Equals(result));
}

TEST_CASE("test case 2 [test_167]", "[test_167]") {
    const vector<int32_t> input{2, 3, 4};
    static constexpr const auto target{6};
    const vector<int32_t> result{1, 3};
    CHECK_THAT(leetcode_167::twoSum(input, target), Equals(result));
    CHECK_THAT(leetcode_167::twoSum2(input, target), Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_TEST_HPP
