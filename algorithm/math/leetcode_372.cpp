// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_372_test.hpp"

namespace leetcode_372 {
static constexpr const int32_t divided{1337};

static std::array<int32_t, 10> power10(int32_t a) {
    std::array<int32_t, 10> power10{1, a % divided,};
    for (size_t i = 2; i < 10; i++) {
        power10[i] = (power10[i - 1] * power10[1]) % divided;
    }
    return power10;
}

int32_t superPower(int32_t a, const vector<int32_t> &b, size_t length, const std::array<int32_t, 10> &nums) {
    CHECK((0 < length && length <= 2000)); // TODO, catch2 why do not support && in CHECK?
    CHECK((0 <= b[length - 1] && b[length - 1] <= 9));
    int32_t will_return{nums[b[length - 1]]};
    if (length == 1) {
        return will_return;
    }
    auto next = superPower(a, b, length - 1, nums);
    const auto next2{(next * next) % divided};
    next = (next2 * next2) % divided;
    next = (next * next) % divided;
    return (will_return * ((next * next2) % divided)) % divided;
}

int32_t leetcode_372::superPow(int32_t a, const vector<int32_t> &b) {
    CHECK((1 <= a && a <= std::numeric_limits<int32_t>::max()));
    std::array<int32_t, 10> nums = power10(a);
    return superPower(a, b, b.size(), nums);
}
}
