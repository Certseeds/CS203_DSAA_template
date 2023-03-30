// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day20

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_518_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_518_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_518 {
using std::vector;

struct leetcode_518 final {
    static int32_t change(int32_t amount, const vector<int32_t> &coins);

    static int32_t change2(int32_t amount, const vector<int32_t> &coins);
};

TEST_CASE("1 [test_518]", "[test_518]") {
    static constexpr const auto amount{std::array<int32_t, 6>{1, 2, 3, 4, 5, 6}};
    const vector<int32_t> coins{1, 2, 5};
    static constexpr const auto result{std::array<int32_t, 6>{1, 2, 2, 3, 4, 5}};
    for (size_t i{0}; i < amount.size(); i++) {
        CHECK(result[i] == leetcode_518::change(amount[i], coins));
        CHECK(result[i] == leetcode_518::change2(amount[i], coins));
    }
}

TEST_CASE("3 [test_518]", "[test_518]") {
    static constexpr const auto amount{10};
    const vector<int32_t> coins{10};
    static constexpr const auto result{1};
    CHECK(result == leetcode_518::change(amount, coins));
    CHECK(result == leetcode_518::change2(amount, coins));
}

TEST_CASE("2 [test_518]", "[test_518]") {
    static constexpr const auto amount{3};
    const vector<int32_t> coins{2};
    static constexpr const auto result{0};
    CHECK(result == leetcode_518::change(amount, coins));
    CHECK(result == leetcode_518::change2(amount, coins));
}

TEST_CASE("1s [test_518]", "[test_518]") {
    static constexpr const auto amount{std::array<int32_t, 6>{1, 2, 3, 4, 5, 6}};
    const vector<int32_t> coins{1};
    static constexpr const auto result{1};
    for (size_t i{0}; i < amount.size(); i++) {
        CHECK(result == leetcode_518::change(amount[i], coins));
        CHECK(result == leetcode_518::change2(amount[i], coins));
    }
}

TEST_CASE("5 [test_518]", "[test_518]") {
    static constexpr const auto amount{4};
    const vector<int32_t> coins{1, 2, 3};
    static constexpr const auto result{4};
    CHECK(result == leetcode_518::change(amount, coins));
    CHECK(result == leetcode_518::change2(amount, coins));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_518_TEST_CPP
