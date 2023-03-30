// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_36_test.hpp"
#include <unordered_set>

namespace leetcode_36 {
using std::unordered_set;
static constexpr const int32_t sizes_36{9}, block_36{3};

bool isValidSudoku_block(const vector<vector<char>> &board,
                         const int left, const int up) {
    unordered_set<int> uset;
    for (int32_t i{0}; i < sizes_36; i++) {
        if (uset.count(board[left + i / block_36][up + i % block_36]) == 1) {
            return false;
        }
        if (board[left + i / block_36][up + i % block_36] != '.') {
            uset.insert(board[left + i / block_36][up + i % block_36]);
        }
    }
    return true;
}

bool isValidSudoku_corss_line(const vector<vector<char>> &board, const int32_t number) {
    unordered_set<int32_t> uset1, uset2;
    for (int32_t i{0}; i < sizes_36; i++) {
        if (uset1.count(board[number][i]) == 1 || (uset2.count(board[i][number]) == 1)) {
            return false;
        }
        if (board[number][i] != '.') {
            uset1.insert(board[number][i]);
        }
        if (board[i][number] != '.') {
            uset2.insert(board[i][number]);
        }
    }
    return true;
}

bool leetcode_36::isValidSudoku(const vector<vector<char>> &board) {
    for (int32_t i{0}; i < sizes_36; i++) {
        if (!isValidSudoku_corss_line(board, i) ||
            !isValidSudoku_block(board, (i / block_36) * block_36, (i % block_36) * block_36)) {
            return false;
        }
    }
    return true;
}


}
