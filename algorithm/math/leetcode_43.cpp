// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_43_test.hpp"
#include <algorithm>

namespace leetcode_43 {


string leetcode_43::multiply(const string &num1, const string &num2) {
    static constexpr const char zeroC{'0'};
    static constexpr const char *const zero{"0"};
    if (num1 == zero || num2 == zero) {
        return zero;
    }
    const auto num1_size{num1.size()}, num2_size{num2.size()}, sum_size{num1_size + num2_size};
    vector<int32_t> sum(sum_size, 0);
    for (size_t i{num2_size}; i > 0; i--) {
        for (size_t j{num1_size}; j > 0; j--) {
            const auto plus{i + j - 1};
            const int32_t mul = static_cast<int32_t>(num2[i - 1] - zeroC) * static_cast<int32_t>(num1[j - 1] - zeroC);
            //cout << i << " " << j << " " << mul << endl;
            sum[plus - 1] += (mul + sum[plus]) / 10;
            sum[plus] = (mul + sum[plus]) % 10;
        }
    }
    string will_return;
    will_return.reserve(sum.size());
    for (size_t i = std::find_if(sum.begin(), sum.end(), [](int x) { return x != 0; }) - sum.begin();
         i < sum_size; i++) {
        will_return += static_cast<char>(sum[i] + static_cast<int>(zeroC));
    }
    return will_return;
}


}