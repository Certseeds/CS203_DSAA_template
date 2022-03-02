// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_40_test.hpp"
#include <algorithm>
#include <map>

namespace leetcode_40 {
using std::map;
struct pair final {
    int32_t number;
    int32_t times;
};

void combinSumTrace(vector<vector<int32_t>> &combinations, const vector<pair> &candidates,
                    vector<int32_t> &combination, int32_t target, size_t index) {
    if (target == 0) {
        combinations.emplace_back(combination);
        return;
    }
    if (index == candidates.size() || target < candidates[index].number) {
        return;
    }
    const auto this_num{candidates[index]};
    index++;
    for (int32_t i{0}; i <= this_num.times; i++, target -= this_num.number) {
        if (target < 0) {
            continue;
        }
        for (int32_t j{0}; j < i; j++) {
            combination.push_back(this_num.number);
        }
        combinSumTrace(combinations, candidates, combination, target, index);
        for (int32_t j{0}; j < i; j++) {
            combination.pop_back();
        }
    }
}

vector<vector<int32_t>> leetcode_40::combinationSum2(const vector<int32_t> &candidates, int32_t target) {
    map<int32_t, int32_t> umap;
    for (const auto candidate: candidates) {
        umap[candidate]++;
    }
    vector<pair> pairs;
    pairs.reserve(umap.size());
    for (const auto[k, v]: umap) {
        pairs.push_back(pair{k, v});
    }
    vector<vector<int32_t>> combinations;
    vector<int32_t> combination;
    combinSumTrace(combinations, pairs, combination, target, static_cast<size_t>(0));
    return combinations;
}

}