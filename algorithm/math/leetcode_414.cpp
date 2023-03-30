// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_414_test.hpp"
#include <unordered_set>

namespace leetcode_414 {
using std::unordered_set;

int32_t leetcode_414::thirdMax(const vector<int32_t> &nums) {
    unordered_set<int32_t> uset;
    for (const auto i: nums) {
        uset.insert(i);
    }
    if (uset.size() < 3) {
        return *(std::max_element(uset.cbegin(), uset.cend()));
    }
    std::array<int32_t, 3> fst{std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min(),
                               std::numeric_limits<int32_t>::min()};
    for (const auto i: uset) {
        if (i > fst[2] && i != fst[1] && i != fst[0]) {
            fst[2] = i;
        }
        if (fst[2] > fst[1]) {
            std::swap(fst[1], fst[2]);
        }
        if (fst[1] > fst[0]) {
            std::swap(fst[0], fst[1]);
        }
    }
    return fst[2];
}

}
