// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_80 {
using std::vector;

struct leetcode_80 {
    static int32_t removeDuplicates(vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_80]", "[test_80]") {
    vector<int32_t> input{0, 0, 1, 1, 1, 1, 2, 3, 3};
    const vector<int32_t> result{0, 0, 1, 1, 2, 3, 3};
    const auto size = leetcode_80::removeDuplicates(input);
    input.resize(size);
    CHECK_THAT(input, Equals(result));
}

TEST_CASE("2 [test_80]", "[test_80]") {
    vector<int32_t> input{1, 1, 1, 2, 2, 3};
    const vector<int32_t> result{1, 1, 2, 2, 3};
    const auto size = leetcode_80::removeDuplicates(input);
    input.resize(size);
    CHECK_THAT(input, Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_TEST_HPP
