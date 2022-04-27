
// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_830_test.hpp"

namespace leetcode_830 {

vector<vector<int32_t>> leetcode_830::largeGroupPositions(const string &S) {
    int end{1}, length{1};
    vector<vector<int32_t>> willreturn{};
    const auto s_size{static_cast<int32_t>(S.size())};
    for (int32_t i{1}; i < s_size; ++i) {
        end = i;
        if (S[i] == S[i - 1]) {
            length++;
        } else {
            if (length >= 3) {
                willreturn.push_back({end - length, end - 1});
            }
            length = 1;
        }
    }
    if (length >= 3) {
        willreturn.push_back({end - length + 1, end});
    }
    return willreturn;
}

}
