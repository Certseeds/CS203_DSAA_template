// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_136_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_136_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_136 {
using std::vector;

struct leetcode_136 {
    static int singleNumber(const vector<int32_t> &nums);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_136]", "[test_136]") {
    const vector<int32_t> input{3, 4, 3};
    static constexpr const auto result{4};
    CHECK(result == leetcode_136::singleNumber(input));
}

TEST_CASE("2 [test_136]", "[test_136]") {
    const vector<int32_t> input{1, 1, 2, 2, 3, 3, 4};
    static constexpr const auto result{4};
    CHECK(result == leetcode_136::singleNumber(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_136_TEST_HPP

