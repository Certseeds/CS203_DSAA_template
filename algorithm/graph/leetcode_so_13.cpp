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
#include "leetcode_so_13_test.hpp"
#include <vector>
#include <queue>

namespace leetcode_so_13 {
using std::vector;
using std::queue;

int32_t leetcode_so_13::movingCount(int32_t m, int32_t n, int32_t k) {
    vector<vector<uint8_t>> visit(m + 2, vector<uint8_t>(n + 2, false));
    for (int32_t i{0}; i < n + 2; i++) {
        visit[0][i] = true;
        visit[m + 1][i] = true;
    }
    for (int32_t i{0}; i < m + 2; i++) {
        visit[i][0] = true;
        visit[i][n + 1] = true;
    }
    visit[1][1] = true;
    static constexpr const auto sums = [](auto num) {
        int32_t sum{0};
        for (; num != 0; num /= 10) { sum += num % 10; }
        return sum;
    };
    static constexpr const std::array<std::array<int32_t, 2>, 4> path{{{1, 0},
                                                                       {-1, 0},
                                                                       {0, 1},
                                                                       {0, -1}}};
    int32_t nums{0};
    for (queue<std::pair<int32_t, int32_t>> que{{{1, 1}}}; !que.empty(); ++nums) {
        const auto head = que.front();
        que.pop();
        for (const auto&[row, col]: path) {
            const auto x{head.first + row}, y{head.second + col};
            if (!visit[x][y] &&
                sums(x - 1) + sums(y - 1) <= k) {
                que.push({x, y});
                visit[x][y] = true;
            }
        }
    }
    return nums;
}
}