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
int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length);

TEST_CASE("1 [test_divide_bar]", "[test_divide_bar]") {
    const vector<int64_t> profits{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    const vector<int64_t> results{0, 1, 5, 8, 10, 13, 17, 18, 22, 25, 30};
    const auto maxLength{results.size()};
    for (size_t i{0}; i < maxLength; ++i) {
        CHECK(results[i] == maxProfit(profits, i));
    }
}

namespace with_solution {
std::tuple<int64_t, vector<int64_t>> maxProfit(const vector<int64_t> &divide_profits, size_t length);

using Catch::Matchers::Equals;

TEST_CASE("1 [test_divide_bar::iter::with_solution]", "[test_divide_bar]") {
    const vector<int64_t> profits{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    const vector<std::tuple<int64_t, vector<int64_t>>> results{
            std::make_tuple(0, vector<int64_t>{}),
            std::make_tuple(1, vector<int64_t>{1}),
            std::make_tuple(5, vector<int64_t>{2}),
            std::make_tuple(8, vector<int64_t>{3}),
            std::make_tuple(10, vector<int64_t>{2, 2}),
            std::make_tuple(13, vector<int64_t>{2, 3}),
            std::make_tuple(17, vector<int64_t>{6}),
            std::make_tuple(18, vector<int64_t>{1, 6}),
            std::make_tuple(22, vector<int64_t>{2, 6}),
            std::make_tuple(25, vector<int64_t>{3, 6}),
            std::make_tuple(30, vector<int64_t>{10}), // instead of {2,2,6}
    };
    const auto maxLength{results.size()};
    for (size_t i{0}; i < maxLength; ++i) {
        const auto [resultProfit, resultNums] = results[i];
        const auto [outputProfit, outputNums] = maxProfit(profits, i);
        CHECK(resultProfit == outputProfit);
        CHECK_THAT(resultNums, Equals(outputNums));
    }
}
}
}

namespace rec {
int64_t maxProfit(const vector<int64_t> &divide_profits, size_t length);

}
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_DIVIDE_BAR_TEST_HPP
