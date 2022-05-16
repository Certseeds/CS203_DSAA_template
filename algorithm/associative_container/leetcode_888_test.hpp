// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_888_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_888_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_888 {
using std::vector;

struct leetcode_888 {
    static vector<int32_t> fairCandySwap(const vector<int32_t> &aliceSizes, const vector<int32_t> &bobSizes);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_888}", "{test_888}") {
    const vector<int32_t> alice{1, 1};
    const vector<int32_t> tifa{2, 2};
    const vector<int32_t> cloud{1, 2};
    CHECK_THAT(cloud, Equals(leetcode_888::fairCandySwap(alice, tifa)));
}

TEST_CASE("test case 2 {test_888}", "{test_888}") {
    const vector<int32_t> alice{1, 1};
    const vector<int32_t> tifa{2, 3};
    const vector<int32_t> cloud{1, 2};
    CHECK_THAT(cloud, Equals(leetcode_888::fairCandySwap(alice, tifa)));
}

TEST_CASE("test case 3 {test_888}", "{test_888}") {
    const vector<int32_t> alice{2};
    const vector<int32_t> tifa{1, 3};
    const vector<int32_t> cloud{2, 3};
    CHECK_THAT(cloud, Equals(leetcode_888::fairCandySwap(alice, tifa)));
}

TEST_CASE("test case 4 {test_888}", "{test_888}") {
    const vector<int32_t> alice{1, 2, 5};
    const vector<int32_t> tifa{2, 4};
    const vector<int32_t> cloud{5, 4};
    CHECK_THAT(cloud, Equals(leetcode_888::fairCandySwap(alice, tifa)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_888_TEST_HPP
