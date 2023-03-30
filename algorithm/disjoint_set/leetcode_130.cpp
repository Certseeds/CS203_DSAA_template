// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_130_test.hpp"
#include "disjoint_set.hpp"
#include <unordered_set>
#include <stack>
#include <string>

namespace leetcode_130 {
using std::string;
using disjoint_set::disjoint_set;
using std::unordered_set, std::stack;

void leetcode_130::solve(vector<vector<char>> &board) {
    if (board.empty() || board.front().empty()) {
        return;
    }
    const auto x_size{board.size()},
            y_size{board.front().size()};
    vector<vector<char>> results{board};
    const auto visit = [&results, x_size, y_size](auto x, auto y) {
        if (results[x][y] != GRID::LAND) {
            return;
        }
        results[x][y] = GRID::KEEP_LAND;
        stack<std::pair<size_t, size_t>> points{{{x, y}}};
        while (!points.empty()) {
            const auto head = points.top();
            points.pop();
            vector<std::pair<size_t, size_t>> will_visit{};
            if (head.first > 0) {
                will_visit.emplace_back(head.first - 1, head.second);
            }
            if (head.first < x_size - 1) {
                will_visit.emplace_back(head.first + 1, head.second);
            }
            if (head.second > 0) {
                will_visit.emplace_back(head.first, head.second - 1);
            }
            if (head.second < y_size - 1) {
                will_visit.emplace_back(head.first, head.second + 1);
            }
            for (const auto &point: will_visit) {
                const auto[x1, y1] = point;
                if (results[x1][y1] == GRID::LAND) {
                    results[x1][y1] = GRID::KEEP_LAND;
                    points.emplace(x1, y1);
                }
            }
        }
    };
    for (size_t i{0}; i < y_size; i++) {
        visit(0, i);
        visit(x_size - 1, i);
    }
    for (size_t i{1}; i < x_size - 1; i++) { //  // [0,0] => [0,y_size-1]
        visit(i, 0);
        visit(i, y_size - 1);
    }
    for (size_t i{0}; i < x_size; i++) {
        for (size_t j{0}; j < y_size; j++) {
            if (results[i][j] == GRID::LAND) {
                board[i][j] = GRID::WATER;
            }
        }
    }
}

}
