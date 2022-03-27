// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_so_61_test.hpp"
#include <array>

namespace leetcode_so_61 {
using std::array;

bool leetcode_so_61::isStraight(const vector<int32_t> &nums) {
    if (nums.size() != 5) {
        return false;
    }
    std::array<uint8_t, 14> umap{0};// 0 to 13
    int32_t maxV{-1}, minV{114514}, zeros{0};
    for (const auto num: nums) {
        if (num == 0) {
            ++zeros;
        } else {
            if (umap[num] == 0) {
                umap[num] = 1;
            } else {
                return false;
            }
            maxV = std::max(maxV, num);
            minV = std::min(minV, num);
        }
    }
    const auto maxDiff{maxV - minV};
    if (maxDiff > 4 || maxDiff + zeros < 4) {
        return false;
    }
    return true;
}

}
