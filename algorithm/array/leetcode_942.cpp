// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_942_test.hpp"

namespace leetcode_942 {

vector<int32_t> leetcode_942::diStringMatch(const string &str) {
    const auto str_size{str.size()};
    int32_t min{0}, max{static_cast<int32_t>(str_size)};
    vector<int32_t> willreturn(max + 1);
    for (size_t i{0}; i < str_size; i++) {
        if (str[i] == 'I') {
            willreturn[i] = min;
            min++;
        } else {
            willreturn[i] = max;
            max--;
        }
    }
    willreturn.back() = min;
    return willreturn;
}

}
