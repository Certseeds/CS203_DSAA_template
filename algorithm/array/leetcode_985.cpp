// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_985_test.hpp"

namespace leetcode_985 {

vector<int32_t> leetcode_985::sumEvenAfterQueries(const vector<int32_t> &nums, const vector<vector<int32_t>> &queries) {
    vector<int32_t> willreturn;
    vector<int32_t> mut_nums{nums};
    willreturn.reserve(queries.size());
    int32_t sums{0};
    for (const auto num: mut_nums) {
        sums += ((num % 2 == 0) ? num : 0);
    }
    for (const auto &query: queries) {
        //for (int32_t i{0}; i < queries.size(); i++) {
        const auto val{query[0]};
        const auto index{query[1]};
        const auto lastIdx{mut_nums[index]};
        if (lastIdx % 2 == 0) {
            if (val % 2 == 0) {
                sums += val;
            } else {
                sums -= lastIdx;
            }
        } else if (val % 2 != 0) {
            sums += (lastIdx + val);
        }
        mut_nums[index] += val;
        willreturn.push_back(sums);
    }
    return willreturn;
}

}
