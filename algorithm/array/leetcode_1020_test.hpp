// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1020 {
using std::vector;

struct leetcode_1020 {
    static int32_t numEnclaves(const vector<vector<int32_t>> &grid);
};

TEST_CASE("test case 4 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0},
            {1},
            {1},
            {0},
            {0}
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 6 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{{0, 1, 1, 0, 0}};
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 3 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0},
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 2 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 1, 1, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 1 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
    };
    static constexpr const auto result{3};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 5 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{{0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                                        {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0},
                                        {0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0},
                                        {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                                        {0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0},
                                        {1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1},
                                        {0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                                        {0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0},
                                        {1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                                        {1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1}};
    static constexpr const auto result{7};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_TEST_HPP
