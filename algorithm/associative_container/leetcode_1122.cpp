
// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1122_test.hpp"

namespace leetcode_1122 {

vector<int32_t> leetcode_1122::relativeSortArray(const vector<int32_t> &arr1, const vector<int32_t> &arr2) {
    std::array<int32_t, 1001> umap{0};
    const auto arr2_size = static_cast<int32_t>(arr2.size());
    for (int32_t i{0}; i < arr2_size; ++i) {
        umap[arr2[i]] = i + 1;
    }
    vector<int32_t> arr{arr1};
    std::sort(arr.begin(), arr.end(), [&umap](const auto x, const auto y) -> bool {
        const auto num_x = (umap[x] == 0) ? x + 2000 : umap[x];
        const auto num_y = (umap[y] == 0) ? y + 2000 : umap[y];
        return num_x < num_y;
    });
    return arr;
}

}
