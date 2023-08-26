// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023 nanos

*/
//@Tag disjoint_set
//@Tag 并查集
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1361_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1361_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1361 {
using std::vector;

namespace leetcode_1361 {
bool validateBinaryTreeNodes(int32_t n, const vector<int32_t> &leftChild, const vector<int32_t> &rightChild);

}

TEST_CASE("1 [test_1361]", "[test_1361]") {
    constexpr const auto n{4};
    const vector<int32_t> left{1, -1, 3, -1}, right{2, -1, -1, -1};
    CHECK(leetcode_1361::validateBinaryTreeNodes(n, left, right));
}

TEST_CASE("2 [test_1361]", "[test_1361]") {
    constexpr const auto n{4};
    const vector<int32_t> left{1, -1, 3, -1}, right{2, 3, -1, -1};
    CHECK_FALSE(leetcode_1361::validateBinaryTreeNodes(n, left, right));
}

TEST_CASE("3 [test_1361]", "[test_1361]") {
    constexpr const auto n{2};
    const vector<int32_t> left{1, 0}, right{-1, -1};
    CHECK_FALSE(leetcode_1361::validateBinaryTreeNodes(n, left, right));
}

TEST_CASE("4 [test_1361]", "[test_1361]") {
    constexpr const auto n{6};
    const vector<int32_t> left{1, -1, -1, 4, -1, -1}, right{2, -1, -1, 5, -1, -1};
    CHECK_FALSE(leetcode_1361::validateBinaryTreeNodes(n, left, right));
}

TEST_CASE("5 [test_1361]", "[test_1361]") {
    constexpr const auto n{3};
    const vector<int32_t> left{1, -1, -1}, right{-1, -1, 1};
    CHECK_FALSE(leetcode_1361::validateBinaryTreeNodes(n, left, right));
}

TEST_CASE("6 [test_1361]", "[test_1361]") {
    constexpr const auto n{4};
    const vector<int32_t> left{3, -1, 1, -1}, right{-1, -1, 0, -1};
    CHECK(leetcode_1361::validateBinaryTreeNodes(n, left, right));
}

TEST_CASE("7 [test_1361]", "[test_1361]") {
    constexpr const auto n{4};
    const vector<int32_t> left{1, 0, 3, -1}, right{-1, -1, -1, -1};
    CHECK_FALSE(leetcode_1361::validateBinaryTreeNodes(n, left, right));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1361_TEST_CPP
