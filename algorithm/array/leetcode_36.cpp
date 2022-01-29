/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "leetcode_36_test.hpp"

namespace leetcode_36 {
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
    unordered_set<int32_t> uset1,uset2;
    for (int32_t i{0}; i < sizes_36; i++) {
        if (uset1.count(board[number][i]) == 1 ||(uset2.count(board[i][number]) == 1)) {
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