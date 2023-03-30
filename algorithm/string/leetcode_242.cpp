// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_242_test.hpp"
#include <array>
#include <algorithm>

namespace leetcode_242 {
using std::array;

bool leetcode_242::isAnagram(const string &s, const string &t) {
    std::array<size_t, std::numeric_limits<char>::max() + 1> arr{0};
    for (const auto ch: s) { ++arr[ch]; }
    for (const auto ch: t) { --arr[ch]; }
    return std::all_of(arr.cbegin(), arr.cend(), [](const auto ele) { return ele == 0; });
}
}
