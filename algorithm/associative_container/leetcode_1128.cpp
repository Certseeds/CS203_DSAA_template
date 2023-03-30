// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_1128_test.hpp"
#include <array>

namespace leetcode_1128 {
using std::array;

int32_t leetcode_1128::numEquivDominoPairs(const vector<vector<int32_t>> &dominoes) {
    std::array<std::array<int32_t, 10>, 10> arr{};
    for (const auto &domino: dominoes) {
        const auto fst{domino[0]}, snd{domino[1]};
        if (fst > snd) {
            arr[fst][snd] += 1;
        } else {
            arr[snd][fst] += 1;
        }
    }
    int32_t will_return{0};
    for (size_t i{0}; i < 10; ++i) {
        for (size_t j{0}; j < i; ++j) {
            const auto num{arr[i][j]};
            will_return += (num > 1 ? (num - 1) * num / 2 : 0);
        }
    }
    return will_return;
}

}
