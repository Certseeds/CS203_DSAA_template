// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_DIVIDE_BAR_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_DIVIDE_BAR_TEST_HPP

#include "package.hpp"
#include <catch_main.hpp>

namespace dp_divide_bar {
namespace iter {

TEST_CASE("1 [test_divide_bar]", "[test_divide_bar]") {
    static const vector<int64_t> profits{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    static const vector<int64_t> results{0, 1, 5, 8, 10, 13, 17, 18, 22, 25, 30};
    static constexpr const auto maxLength{10};
    for (size_t i{0}; i < maxLength; ++i) {
        CHECK(results[i] == maxProfit(profits, i));
    }
}

}


}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_DIVIDE_BAR_TEST_HPP
