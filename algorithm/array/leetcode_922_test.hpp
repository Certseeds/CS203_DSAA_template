// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_922_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_922_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_922 {
using std::vector;

struct leetcode_922 {
    static vector<int32_t> sortArrayByParityII(const vector<int32_t> &nums);
};


void judgement(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    CHECK(nums_size % 2 == 0);
    for (size_t i{0}; i < nums_size; ++i) {
        CHECK(static_cast<bool>(nums[i] % 2) == static_cast<bool>( i % 2));
    }
}

TEST_CASE("test case 1 {test_922}", "{test_922}") {
    const vector<int32_t> input{4, 2, 5, 7};
    judgement(leetcode_922::sortArrayByParityII(input));
}

TEST_CASE("test case 2 {test_922}", "{test_922}") {
    const vector<int32_t> input{1, 1, 4, 5, 4, 4};
    judgement(leetcode_922::sortArrayByParityII(input));
}

TEST_CASE("test case 3 {test_922}", "{test_922}") {
    const vector<int32_t> input{1, 9, 2, 9, 8, 1, 0, 0};
    judgement(leetcode_922::sortArrayByParityII(input));
}

TEST_CASE("test case 4 {test_922}", "{test_922}") {
    const vector<int32_t> input{8, 5, 2, 7};
    judgement(leetcode_922::sortArrayByParityII(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_922_TEST_HPP
