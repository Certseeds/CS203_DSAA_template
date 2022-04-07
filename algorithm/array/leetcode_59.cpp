// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_59_test.hpp"

namespace leetcode_59 {

vector<vector<int32_t>> leetcode_59::generateMatrix(int32_t n) {
    vector<vector<int32_t>> will_return(n, vector<int32_t>(n, 0));
    int32_t counter{1};
    const auto rightDown = [&will_return, &counter](size_t x, size_t y, int32_t steps) -> std::pair<int32_t, int32_t> {
        for (int32_t step{0}; step < steps + 1; ++counter, ++y, ++step) {
            will_return[x][y] = counter;
        }
        y -= 1, x += 1;
        for (int32_t step{0}; step < steps; ++counter, ++x, ++step) {
            will_return[x][y] = counter;
        }
        return {x - 1, y - 1}; // 向左上角
    };
    const auto leftup = [&will_return, &counter](size_t x, size_t y, int32_t steps) -> std::pair<int32_t, int32_t> {
        for (int32_t step{0}; step < steps + 1; ++counter, --y, ++step) {
            will_return[x][y] = counter;
        }
        y += 1, x -= 1;
        for (int32_t step{0}; step < steps; ++counter, --x, ++step) {
            will_return[x][y] = counter;
        }
        return {x + 1, y + 1};// 向右下角
    };
    for (int32_t i{0}, x{0}, y{0}; i < n; ++i) {
        if (i % 2 == 0) {
            const auto next = rightDown(x, y, n - i - 1);
            x = next.first, y = next.second;
        } else {
            const auto next = leftup(x, y, n - i - 1);
            x = next.first, y = next.second;
        }
    }
    return will_return;
}

}
