// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "matrix_multiply_test.hpp"


namespace dp {
namespace matrix_multiply {
namespace iter {
int64_t min_multiply(const vector<tuple<int32_t, int32_t>> &mats) {
    for (auto iter = mats.cbegin(), next = iter + 1; next != mats.cend(); ++iter, ++next) {
        CHECK(std::get<1>(*iter) == std::get<0>(*next));
    }
    const auto mats_size{mats.size()};
    vector <vector<int64_t>> times(mats_size, vector<int64_t>(mats_size, 0x3f3f3f3f));
    // i < j, times[i][j] = min of matrix multiply times between i to j
    for (auto iter{0ull}; iter < mats_size; ++iter) {
        times[iter][iter] = 0; //
    }
    const auto func = [&mats](size_t i, size_t j, size_t k) {
        const auto [fstCol, fstRow] = mats[i];
        const auto [sndCol1, sndRow1] = mats[j];
        const auto [trdCol, trdRow] = mats[k];
        return fstCol * sndRow1 * trdRow;
    };
    // k-i>j-1-i , k-i>k-j,所以可以从左上到右下, 三角形的获取
    for (size_t i{mats_size - 1}; i != 0; --i) { // 代表左上到右下一行的元素数量
        const auto step = mats_size - i; // 代表一步的步长
        for (size_t j{0}; j + step < mats_size; ++j) { // 确保最后一步不越界
            const auto x = j;
            const auto y = j + step;
            for (size_t k{x}; k < y; ++k) {// 代表中间点
                const auto sums = times[x][k] + times[k + 1][y] + func(x, k, y);
                if (sums < times[x][y]) {
                    times[x][y] = sums;
                }
            }
        }
    }
    return times[0].back();
}
}

}
}
