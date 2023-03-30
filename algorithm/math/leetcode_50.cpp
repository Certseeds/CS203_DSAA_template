// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_50_test.hpp"

namespace leetcode_50 {

double quick_pow(vector<double> &pows, double num, int32_t n) {
    CHECK((0 <= n && n < 32));
    CHECK((pows.size() == 32));

    if (pows[n] != 0) {
        return pows[n];
    }
    pows[n - 1] = quick_pow(pows, num, n - 1);
    return pows[n - 1] * pows[n - 1];
}

double leetcode_50::myPow(double x, int32_t n) {
    CHECK((-100 < x && x < 100));
    CHECK((std::numeric_limits<int32_t>::min() <= n && n <= std::numeric_limits<int32_t>::max()));
    if (0 == n) {
        return 1;
    } else if (1 == x || 0 == x) {
        return x;
    } else if (n < 0 && n != std::numeric_limits<int32_t>::min()) {
        return 1 / myPow(x, -n);
    } else if (std::numeric_limits<int32_t>::min() == n) {
        return 1 / (myPow(x, std::numeric_limits<int32_t>::max()) * x);
    }
    vector<double> pows(32, 0);
    pows[0] = x;
    pows[1] = x * x;
    vector<short> nums{};
    nums.reserve(32);
    for (short i{1}; i <= 32; i++) {
        if ((n & (1 << (i - 1))) > 0) {
            nums.push_back(i);
        }
    }
    std::sort(nums.begin(), nums.end(), std::less<>());
    for (const auto i: nums) {
        quick_pow(pows, x, i);
    }
    double will_return{1.0f};
    for (const auto i: nums) {
        will_return *= pows[i - 1];
    }
    return will_return;
}

}
