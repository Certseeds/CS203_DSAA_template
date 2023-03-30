// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_416 {
using std::vector;

struct leetcode_416 final {
    static bool canPartition(const vector<int32_t> &nums);

    static bool canPartition2(const vector<int32_t> &nums);
};


TEST_CASE("1 [test_416]", "[test_416]") {
    const vector<int32_t> input{1, 5, 11, 5};
    CHECK(leetcode_416::canPartition(input));
    CHECK(leetcode_416::canPartition2(input));
}

TEST_CASE("2 [test_416]", "[test_416]") {
    const vector<int32_t> input{1, 2, 3, 5};
    CHECK_FALSE(leetcode_416::canPartition(input));
    CHECK_FALSE(leetcode_416::canPartition2(input));
}

TEST_CASE("3 [test_416]", "[test_416]") {
    const vector<int32_t> input{114514};
    CHECK_FALSE(leetcode_416::canPartition(input));
    CHECK_FALSE(leetcode_416::canPartition2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP
