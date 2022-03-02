// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_763_test.hpp"
#include <array>

namespace leetcode_763 {
using std::array;

vector<int32_t> leetcode_763::partitionLabels(const string &S) {
    array<size_t, 26> vals{0};
    vector<int32_t> willreturn{};
    for (size_t i{0}; i < S.size(); i++) {
        vals[S[i] - 'a'] = i; // chara -> rightest pos
    }
    for (size_t left{0}, right{0}, i{0}; i < S.size(); i++) {
        right = std::max(right, vals[S[i] - 'a']);
        // this and the next judge means, if the left's range final in here.
        if (right == i) {
            willreturn.push_back(right - left + 1);
            left += willreturn.back();
        }
    }
    return willreturn;
}
}