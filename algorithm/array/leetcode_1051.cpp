// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1051_test.hpp"
#include <algorithm>

namespace leetcode_1051 {

int32_t leetcode_1051::heightChecker(const vector<int32_t> &heights) {
    vector<int32_t> sorted{heights};
    std::sort(sorted.begin(), sorted.end());
    int32_t count{0};
    for (size_t i{0}; i < heights.size(); ++i) {
        if (sorted[i] != heights[i]) {
            count++;
        }
    }
    return count; // because the size smaller than 100
}

int leetcode_1051::heightCheckerSmall(const vector<int> &heights) {
    const auto h_size{128};
    vector<int32_t> sizes(128, 0);
    for (const auto height: heights) {
        sizes[height] += 1;
    }
    int32_t will_return{0};
    for (int32_t j{0}, loca{0}; j < h_size; ++j) {
        for (int32_t i{0}; i < sizes[j]; ++i) {
            if (j != heights[loca]) {
                will_return += 1;
            }
            loca += 1;
        }
    }
    return will_return;
}

}
