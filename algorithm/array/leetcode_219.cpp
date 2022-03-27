// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_219_test.hpp"
#include <unordered_map>

namespace leetcode_219 {
using std::unordered_map;

bool leetcode_219::containsNearbyDuplicate(const vector<int32_t> &nums, int32_t k) {
    unordered_map<size_t, int32_t> umap;
    const int32_t nums_size{static_cast<int32_t>(nums.size())};
    for (int32_t i{0}; i < nums_size; i++) {
        if (umap[nums[i]] != 0 && (i - umap[nums[i]]) < k) {
            return true;
        }
        umap[nums[i]] = i + 1;
    }
    return false;
}

}
