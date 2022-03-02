// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/

#include "divide_bar.hpp"
#include "divide_bar_test.hpp"

namespace dp_divide_bar {
namespace iter {
static int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length) {
    const auto divide_profits_size{divide_profits.size()};
    const auto minIter{std::min(divide_profits_size, length)};
    vector<int64_t> profits_table(length + 1, -0x3f3f3f);
    profits_table[0] = 0;
    for (size_t i{0}; i < minIter; i++) {
        profits_table[i + 1] = divide_profits[i];
    }
    for (size_t i{2}; i <= length; i++) {
        for (size_t j{1}; j < (i / 2 + 1); j++) {
            profits_table[i] = std::max(profits_table[i], profits_table[j] + profits_table[i - j]);
        }
    }
    return profits_table.back();
}
}
namespace rec {
static int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length) {

    return 0;
}
}
}

