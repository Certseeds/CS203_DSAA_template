// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_1200_test.hpp"

namespace leetcode_1200 {

vector<vector<int32_t>> leetcode_1200::minimumAbsDifference(const vector<int32_t> &arr_) {
    vector<int32_t> arr{arr_};
    std::sort(arr.begin(), arr.end());
    int32_t minDiff = std::numeric_limits<int32_t>::max() - 1;
    vector<vector<int32_t>> will_return{};
    for (auto fst = arr.cbegin(), snd = fst + 1; snd != arr.cend(); ++fst, ++snd) {
        const auto diff = (*snd - *fst);
        if (minDiff > diff) {
            minDiff = diff;
            will_return.clear();
            will_return.push_back({*fst, *snd});
        } else if (minDiff == diff) {
            will_return.push_back({*fst, *snd});
        }
    }
    return will_return;
}

}
