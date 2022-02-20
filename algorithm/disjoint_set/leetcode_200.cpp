/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
#include "leetcode_200_test.hpp"
#include "disjoint_set.hpp"
#include <unordered_set>
#include <string>

namespace leetcode_200 {
using std::string;
using disjoint_set::disjoint_set;
using std::unordered_set;

int leetcode_200::numIslands(const vector<vector<char>> &grid) {
    if (grid.empty() || grid.back().empty()) {
        return 0;
    }
    const auto x_size{grid.size()}, y_size{grid.back().size()};
    vector<vector<char>> grids(x_size + 1, vector<char>(y_size + 1, 0));
    for (size_t i{0}; i < x_size; i++) {
        for (size_t j{0}; j < y_size; j++) {
            grids[i][j] = grid[i][j];
        }
    }
    const auto x_size2{x_size + 1}, y_size2{y_size + 1}, grid_size2{x_size2 * y_size2};
    const auto loca = [y_size2](auto x, auto y) {
        return x * y_size2 + y + 1;
    };
    disjoint_set jset(grid_size2);
    for (size_t i{0}; i < x_size; i++) {
        for (size_t j{0}; j < y_size; j++) {
            if (grids[i][j] == GRID::LAND) {
                if (grids[i + 1][j] == GRID::LAND) {
                    jset.merge(loca(i + 1, j), loca(i, j));
                }
                if (grids[i][j + 1] == GRID::LAND) {
                    jset.merge(loca(i, j + 1), loca(i, j));
                }
            }
        }
    }
    std::unordered_set<size_t> uset;
    for (size_t i{0}; i < x_size; i++) {
        for (size_t j{0}; j < y_size; j++) {
            if (grids[i][j] == GRID::LAND) {
                uset.insert(jset.find(loca(i, j)));
            }
        }
    }
    return uset.size();
}

}