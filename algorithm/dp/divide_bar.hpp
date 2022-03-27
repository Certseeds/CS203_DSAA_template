// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_DIVIDE_BAR_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_DIVIDE_BAR_HPP

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace dp_divide_bar {
using std::vector;
namespace iter {
static int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length);
}
namespace rec {
static int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_DIVIDE_BAR_HPP
