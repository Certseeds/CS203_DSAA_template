/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "leetcode_39_test.hpp"

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