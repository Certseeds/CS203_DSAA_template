// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Plan 数据结构入门 Day5
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_36_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_36_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_36 {
using std::vector;

struct leetcode_36 {
    static bool isValidSudoku(const vector<vector<char>> &board);
};

TEST_CASE("basic test [test_36]", "[test_36]") {
    const vector<vector<char>> vec1{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    CHECK(leetcode_36::isValidSudoku(vec1));
}

TEST_CASE("test reverse [test_36]", "[test_36]") {
    const vector<vector<char>> vec1{
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    CHECK_FALSE(leetcode_36::isValidSudoku(vec1));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_36_TEST_HPP
