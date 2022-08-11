// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1122_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1122_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1122 {
using std::vector;

struct leetcode_1122 {
    static vector<int32_t> relativeSortArray(const vector<int32_t> &arr1, const vector<int32_t> &arr2);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1122}", "{test_1122}") {
    const vector<int32_t> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    const vector<int32_t> arr2{2, 1, 4, 3, 9, 6};
    const vector<int32_t> result{2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19};
    CHECK_THAT(result, Equals(leetcode_1122::relativeSortArray(arr1, arr2)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1122_TEST_HPP
