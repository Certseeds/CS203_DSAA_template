// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_914_test.hpp"
#include <array>
#include <unordered_map>
#include <unordered_set>

namespace leetcode_914 {
using std::array;
using std::unordered_map;
using std::unordered_set;

void getPrime(int32_t value, unordered_map<int32_t, size_t> &uset) {
    for (int32_t begin{2}; begin <= value; ++begin) {
        if (value % begin == 0) {
            ++uset[begin];
        }
    }
}

bool leetcode_914::hasGroupsSizeX(const vector<int32_t> &deck) {
    if (deck.size() < 2) {
        return false;
    }
    int maxv{0};
    unordered_map<int32_t, int32_t> umap;
    for (const auto i: deck) {
        umap[i]++;
        maxv = std::max(umap[i], maxv);
    }
    unordered_map<int32_t, size_t> umap2;
    for (const auto [key, value]: umap) {
        getPrime(value, umap2);
    }
    return std::any_of(umap2.cbegin(), umap2.cend(), [&umap](std::pair<int32_t, size_t> pai) {
        return pai.second == umap.size();
    });
}

}
