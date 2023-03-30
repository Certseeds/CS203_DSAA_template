// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include <numeric>
#include "leetcode_999_test.hpp"

namespace leetcode_999 {
static constexpr const size_t board_size{8};

int32_t leetcode_999::numRookCaptures(const vector<vector<uint8_t>> &board) {
    size_t x{0}, y{0};
    for (size_t i{0}; i < board_size; ++i) {
        for (size_t j{0}; j < board_size; ++j) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
            }
        }
    }
    std::array<bool, 4> judge{false, false, false, false};
    for (size_t i{x + 1}; i < board_size; ++i) {
        //cout << board[i][y] << endl;
        switch (board[i][y]) {
            case 'B': {
                i = board_size;
                break;
            }
            case '.': {
                break;
            }
            case 'p': {
                i = board_size;
                judge[0] = true;
                break;
            }

        }
    }
    for (size_t i{x}; i >= 1; --i) {
        //cout << board[i][y] << endl;
        switch (board[i - 1][y]) {
            case 'B': {
                i = 1;
                break;
            }

            case '.': {
                break;
            }

            case 'p': {
                judge[1] = true;
                i = 1;
                break;
            }
        }
    }

    for (size_t i{y}; i >= 1; --i) {
        switch (board[x][i - 1]) {
            case 'B': {
                i = 1;
                break;
            }
            case '.': {
                break;
            }
            case 'p': {
                judge[2] = true;
                i = 1;
                break;
            }
        }
    }
    for (size_t i{y + 1}; i < board_size; i++) {
        switch (board[x][i]) {
            case 'B': {
                i = board_size;
                break;
            }
            case '.': {
                break;
            }
            case 'p': {
                judge[3] = true;
                i = board_size;
                break;
            }

        }
    }
    return std::accumulate(judge.cbegin(), judge.cend(), 0);
}

}
