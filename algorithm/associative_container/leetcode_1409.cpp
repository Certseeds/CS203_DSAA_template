// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1409_test.hpp"
#include <unordered_map>

namespace leetcode_1409 {
using std::unordered_map;

vector<int32_t> leetcode_1409::processQueries(const vector<int32_t> &queries, int32_t m) {
    vector<int32_t> will_return;
    if (queries.empty()) {
        return will_return;
    }
    unordered_map<int32_t, int32_t> num_pos;
    for (int32_t i{0}; i < m; ++i) {
        num_pos[i + 1] = i;
    }
    for (const auto &i:queries) {
        int32_t pos = num_pos[i];
        will_return.push_back(pos);
        for (auto &j:num_pos) {
            if (j.second < pos) {
                j.second++;
            }
        }
        num_pos[i] = 0;
    }
    return will_return;
}
}
