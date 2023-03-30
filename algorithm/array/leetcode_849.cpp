// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_849_test.hpp"

namespace leetcode_849 {

int32_t leetcode_849::numMagicSquaresInside(const vector<int32_t> &seats) {
    vector<int> left(seats), right(seats);
    const auto size{seats.size()};
    left[0] = (seats[0] == 1) ? 0 : std::numeric_limits<int32_t>::max();
    right[size - 1] = (seats[size - 1] == 1) ? 0 : std::numeric_limits<int32_t>::max();
    for (size_t i{1}; i < size; ++i) {
        left[i] = (seats[i] == 1) ? 0 : left[i - 1] + 1;
    }
    for (size_t i = size; i >= 2; --i) {
        right[i - 2] = (seats[i - 2] == 1) ? 0 : right[i - 1] + 1;
    }
    int will_return{std::numeric_limits<int32_t>::min()};
    for (size_t i{0}; i < size; ++i) {
        will_return = std::max(will_return, std::min(left[i], right[i]));
    }
    return will_return;
}
}
