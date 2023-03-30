// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_709_test.hpp"
#include <array>

namespace leetcode_709 {
using std::array;

constexpr std::array<char, std::numeric_limits<char>::max() + 1> prepare() {
    std::array<char, std::numeric_limits<char>::max() + 1> bigs{0};
    for (char ch{'A'}; ch <= 'Z'; ++ch) {
        bigs[ch] = ('a' - 'A');
    }
    return bigs;
}

string leetcode_709::toLowerCase(const string &str) {
    static constexpr const std::array<char, prepare().size()> arr{prepare()};
    string will_return{str};
    for (auto &ch: will_return) {
        ch += arr[ch];
    }
    return will_return;
}
}
