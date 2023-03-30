// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_986_test.hpp"

namespace leetcode_986 {

vector<vector<int>> leetcode_986::intervalIntersection(const vector<vector<int>> &fst, const vector<vector<int>> &snd) {
    vector<vector<int32_t>> will_return;
    const auto fst_size{fst.size()}, snd_size{snd.size()};
    const auto judgement = [&fst, &snd](size_t pre, size_t post) -> vector<int32_t> {
        const auto &fst_element{fst[pre]}, &snd_element{snd[post]};
        return {std::max(fst_element[0], snd_element[0]),
                std::min(fst_element[1], snd_element[1])};
    };
    for (size_t x{0}, y{0}, judge{0}; x < fst_size && y < snd_size;) {
        if (fst[x][1] < snd[y][0]) {
            ++x;
        } else if (fst[x][0] > snd[y][1]) {
            ++y;
        } else {
            const vector<int32_t> temp = judgement(x, y);
            will_return.emplace_back(temp);
            judge = ((temp[1] >= fst[x][1]) == 1 ? 1 : 0);
            x += judge;
            y += (1 - judge);
        }
    }
    return will_return;
}
}
