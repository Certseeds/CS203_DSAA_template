// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 哈希表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_448_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_448_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_448 {
using std::vector;

struct leetcode_448 {
    static vector<int32_t> findDisappearedNumbers(const vector<int32_t> &nums);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_448]", "[test_448]") {
    const vector<int32_t> input{4, 3, 2, 7, 8, 2, 3, 1};
    const vector<int32_t> result{5, 6};
    CHECK_THAT(result, UnorderedEquals(leetcode_448::findDisappearedNumbers(input)));
}

TEST_CASE("test case 2 [test_448]", "[test_448]") {
    const vector<int32_t> input{1, 1};
    const vector<int32_t> result{2};
    CHECK_THAT(result, UnorderedEquals(leetcode_448::findDisappearedNumbers(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_448_TEST_HPP
