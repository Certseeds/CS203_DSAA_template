// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_999_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_999_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_999 {
using std::vector;

struct leetcode_999 {
    static int32_t numRookCaptures(const vector<vector<uint8_t>> &board);
};


TEST_CASE("test case 1 {test_999}", "{test_999}") {
    const vector<vector<uint8_t>> board{{'.', '.', '.', '.', '.', '.', '.', '.'},
                                        {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                        {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                                        {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                                        {'.', '.', '.', '.', '.', '.', '.', '.'}};
    static constexpr const auto result{3};
    CHECK(result == leetcode_999::numRookCaptures(board));
}

TEST_CASE("test case 2 {test_999}", "{test_999}") {
    const vector<vector<uint8_t>> board{{'.', '.', '.', '.', '.', '.', '.', '.'},
                                        {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
                                        {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
                                        {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
                                        {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
                                        {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
                                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                                        {'.', '.', '.', '.', '.', '.', '.', '.'}};
    static constexpr const auto result{0};
    CHECK(result == leetcode_999::numRookCaptures(board));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_999_TEST_HPP
