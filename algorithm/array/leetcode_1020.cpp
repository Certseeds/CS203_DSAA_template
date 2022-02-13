/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
#include "leetcode_1020_test.hpp"

namespace leetcode_1020 {
void visit(const vector<vector<int32_t>> &grid, vector<vector<uint8_t>> &visited, size_t row, size_t col) {
    const auto judge = [& grid, &visited](size_t r, size_t c) {
        return grid[r][c] == 1 && visited[r][c] == 0;
    };
    if (!judge(row, col)) {
        return;
    }
    const auto row_size{grid.size()}, col_size{grid.front().size()};
    for (std::vector<std::pair<size_t, size_t>> now{{row, col}}, next{}; !now.empty(); next.clear()) {
        for (const auto &[this_row, this_col]: now) {
            visited[this_row][this_col] = 1;
            if (this_col > 0 && judge(this_row, this_col - 1)) {
                next.emplace_back(this_row, this_col - 1);
            }
            if (this_row > 0 && judge(this_row - 1, this_col)) {
                next.emplace_back(this_row - 1, this_col);
            }
            if (this_col + 1 < col_size && judge(this_row, this_col + 1)) {
                next.emplace_back(this_row, this_col + 1);
            }
            if (this_row + 1 < row_size && judge(this_row + 1, this_col)) {
                next.emplace_back(this_row + 1, this_col);
            }
        }
        std::swap(now, next);
    }
}

int32_t leetcode_1020::numEnclaves(const vector<vector<int32_t>> &grid) {
    if (grid.empty() || grid.front().empty()) {
        return 0;
    }
    const auto row{grid.size()}, col{grid.front().size()};
    vector<vector<uint8_t>> visited(row, vector<uint8_t>(col, 0));
    int32_t ones{0};
    for (const auto &rows: grid) {
        for (const auto &num: rows) {
            ones += (num == 1);
        }
    }
    for (size_t i{0}; i < col; ++i) {
        visit(grid, visited, 0, i);
        visit(grid, visited, row - 1, i);
    }
    for (size_t i{1}; i + 1 < row; ++i) {
        visit(grid, visited, i, 0);
        visit(grid, visited, i, col - 1);
    }
    for (const auto &rows: visited) {
        for (const auto &num: rows) {
            ones -= (num == 1);
        }
    }
    return ones;
}

}
