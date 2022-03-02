// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day3
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_213_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_213_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_198 {
using std::vector;

struct leetcode_198 final {
    static int64_t rob(const vector<int32_t> &nums);

    static int64_t rob2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_198]", "[test_198]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(4)};
    CHECK(output == leetcode_198::rob(input));
    CHECK(output == leetcode_198::rob2(input));
}

TEST_CASE("2 [test_198]", "[test_198]") {
    const vector<int32_t> input{2, 7, 9, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(12)};
    CHECK(output == leetcode_198::rob(input));
    CHECK(output == leetcode_198::rob2(input));
}

TEST_CASE("3 [test_198]", "[test_198]") {
    const vector<int32_t> input{1, 1};
    static constexpr const auto output{static_cast<int64_t>(1)};
    CHECK(output == leetcode_198::rob(input));
    CHECK(output == leetcode_198::rob2(input));
}
}
namespace leetcode_213 {
using std::vector;

struct leetcode_213 final {
    static int64_t rob(const vector<int32_t> &nums);

    static int64_t rob2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_213]", "[test_213]") {
    const vector<int32_t> input{2, 3, 2};
    static constexpr const auto output{static_cast<int64_t>(3)};
    CHECK(output == leetcode_213::rob(input));
    CHECK(output == leetcode_213::rob2(input));
}

TEST_CASE("2 [test_213]", "[test_213]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(4)};
    CHECK(output == leetcode_213::rob(input));
    CHECK(output == leetcode_213::rob2(input));
}

TEST_CASE("3 [test_213]", "[test_213]") {
    const vector<int32_t> input{1, 1};
    static constexpr const auto output{static_cast<int64_t>(1)};
    CHECK(output == leetcode_213::rob(input));
    CHECK(output == leetcode_213::rob2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_213_TEST_CPP
