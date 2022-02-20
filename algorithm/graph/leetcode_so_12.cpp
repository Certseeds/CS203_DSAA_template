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
#include "leetcode_so_12_test.hpp"

namespace leetcode_so_12 {
bool dfs(vector<vector<char>> &board, const string &word, const string &wor, const std::pair<size_t, size_t> loca) {
    if (word == wor) {
        return true;
    }
    const auto&[row, line] = loca;
    const auto ch = board[row][line];
    const auto this_ch = word[wor.size()];
    board[row][line] = ' ';
    bool temp{false};
    temp = temp || (row > 0 && this_ch == board[row - 1][line] &&
                    dfs(board, word, wor + board[row - 1][line], {row - 1, line}))
           || (row + 1 < board.size() && this_ch == board[row + 1][line] &&
               dfs(board, word, wor + board[row + 1][line], {row + 1, line}))
           || (line > 0 && this_ch == board[row][line - 1] &&
               dfs(board, word, wor + board[row][line - 1], {row, line - 1}))
           || (line + 1 < board.front().size() && this_ch == board[row][line + 1] &&
               dfs(board, word, wor + board[row][line + 1], {row, line + 1}));
    board[row][line] = ch;
    return temp;
}

bool leetcode_so_12::exist(const vector<vector<char>> &board, const string &word) {
    if (board.empty() || board.front().empty()) {
        return word.empty();
    } else if (word.empty()) {
        return true;
    }
    vector<vector<char>> boardMutable{board};
    const auto row{board.size()}, col{board.front().size()};
    for (size_t i{0}; i < row; ++i) {
        for (size_t j{0}; j < col; ++j) {
            if (board[i][j] == word.front() && dfs(boardMutable, word, string(1, board[i][j]), {i, j})) {
                return true;
            }
        }
    }
    return false;
}

}