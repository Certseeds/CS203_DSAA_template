// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_16_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_16_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_16 {
using std::vector;

struct leetcode_16 {
    static int32_t threeSumClosest(vector<int32_t> &nums, int32_t target);
};

TEST_CASE("1 [test_16]", "[test_16]") {
    vector<int32_t> nums{-1, 2, 1, -4};
    const auto output = leetcode_16::threeSumClosest(nums, 1);
    CHECK(output == 2);
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_16_TEST_HPP
