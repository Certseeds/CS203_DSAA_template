// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Description 非常简单
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_771_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_771_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_771 {
using std::string;

struct leetcode_771 {
    static int numJewelsInStones(const string &jewels, const string &stones);
};

TEST_CASE("1 [test_771]", "[test_771]") {
    static constexpr const char *const jewels{"aA"}, *const stones{"aAAbbbb"};
    static constexpr const auto output{3};
    CHECK(output == leetcode_771::numJewelsInStones(jewels, stones));
}

TEST_CASE("2 [test_771]", "[test_771]") {
    static constexpr const char *const jewels{"z"}, *const stones{"ZZ"};
    static constexpr const auto output{0};
    CHECK(output == leetcode_771::numJewelsInStones(jewels, stones));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_771_TEST_HPP
