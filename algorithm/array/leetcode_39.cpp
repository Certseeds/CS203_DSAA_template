// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_39_test.hpp"
#include <algorithm>

namespace leetcode_39 {

void
combinSumTrace(vector<vector<int32_t>> &combinations, const vector<int32_t> &candidates, vector<int32_t> &combination,
               int32_t target, size_t index) {
    if (target == 0) {
        combinations.emplace_back(combination);
        return;
    }
    if (index == candidates.size()) {
        return;
    }
    const auto this_num{candidates[index]};
    if (this_num <= target) {
        combination.emplace_back(this_num);
        combinSumTrace(combinations, candidates, combination, target - this_num, index);
        combination.pop_back();
    } else {
        return;
    }
    combinSumTrace(combinations, candidates, combination, target, index + 1);
}

vector<vector<int32_t>> leetcode_39::combinationSum(const vector<int32_t> &candidates, int32_t target) {
    vector<int32_t> candidates_back{candidates};
    std::sort(candidates_back.begin(), candidates_back.end());
    vector<vector<int32_t>> combinations;
    vector<int32_t> combination;
    combinSumTrace(combinations, candidates_back, combination, target, static_cast<size_t>(0));
    return combinations;
}
}
