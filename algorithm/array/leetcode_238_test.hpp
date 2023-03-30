// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 二分搜索
//@Plan 数据结构基础 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_238_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_238_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_238 {
using std::vector;

struct leetcode_238 {
    static vector<int32_t> productExceptSelf(const vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_238}", "{test_238}") {
    const vector<int32_t> input{1, 4, 7, 11, 15};
    const vector<int32_t> result{4620, 1155, 660, 420, 308};
    CHECK_THAT(result, Equals(leetcode_238::productExceptSelf(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_238_TEST_HPP
