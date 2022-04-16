// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_532_test.hpp"
#include <unordered_map>
#include <numeric>

namespace leetcode_532 {
using std::unordered_map;

int32_t leetcode_532::findPairs(const vector<int32_t> &nums, int32_t k) {
    if (k < 0) {
        return 0;
    }
    unordered_map<int32_t, int32_t> umap;
    int count = 0;
    for (const auto num: nums) {
        umap[num]++;
    }
    if (k == 0) {
        return std::accumulate(umap.cbegin(), umap.cend(), 0,
                               [](const auto base, const auto value) { return base + (value.second > 1); });
    }
    for (auto i: umap) {
        count += (umap.count(i.first + k) > 0);
    }
    return count;
}

}
