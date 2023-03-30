// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_771_test.hpp"
#include <array>

namespace leetcode_771 {
using std::array;

int leetcode_771::numJewelsInStones(const string &jewels, const string &stones) {
    std::array<uint8_t, 256> umap{false};
    int count = 0;
    for (const auto jewel: jewels) {
        umap[jewel] = true;
    }
    for (const auto stone: stones) {
        count += (umap[stone]);
    }
    return count;
}
}
