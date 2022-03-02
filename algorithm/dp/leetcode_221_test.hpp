// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day16
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_221_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_221_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_221 {
using std::vector;

struct leetcode_221 final {
    static int32_t maximalSquare(const vector<vector<char>> &matrix);

    static int32_t maximalSquare2(const vector<vector<char>> &matrix);
};

TEST_CASE("4 [test_221]", "[test_221]") {
    const vector<vector<char>> input{
            {'1', '1'},
            {'1', '1'},
    };
    static constexpr const auto result{4};
    CHECK(result == leetcode_221::maximalSquare(input));
    CHECK(result == leetcode_221::maximalSquare2(input));
}

TEST_CASE("1 [test_221]", "[test_221]") {
    const vector<vector<char>> input{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    static constexpr const auto result{4};
    CHECK(result == leetcode_221::maximalSquare(input));
    CHECK(result == leetcode_221::maximalSquare2(input));
}

TEST_CASE("2 [test_221]", "[test_221]") {
    const vector<vector<char>> input{
            {'0', '1'},
            {'1', '0'},
    };
    static constexpr const auto result{1};
    CHECK(result == leetcode_221::maximalSquare(input));
    CHECK(result == leetcode_221::maximalSquare2(input));
}

TEST_CASE("3 [test_221]", "[test_221]") {
    const vector<vector<char>> input{{'0'},};
    static constexpr const auto result{0};
    CHECK(result == leetcode_221::maximalSquare(input));
    CHECK(result == leetcode_221::maximalSquare2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_221_TEST_CPP
