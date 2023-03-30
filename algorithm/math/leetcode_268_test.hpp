// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_268_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_268_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_268 {
using std::vector;

struct leetcode_268 {
    static int32_t missingNumber(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_268]", "[test_268]") {
    const vector<int32_t> input{3, 0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_268::missingNumber(input));
}

TEST_CASE("2 [test_268]", "[test_268]") {
    const vector<int32_t> input{0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_268::missingNumber(input));
}

TEST_CASE("3 [test_268]", "[test_268]") {
    const vector<int32_t> input{9, 6, 4, 2, 3, 5, 7, 0, 1};
    static constexpr const auto result{8};
    CHECK(result == leetcode_268::missingNumber(input));
}


TEST_CASE("4 [test_268]", "[test_268]") {
    const vector<int32_t> input{0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_268::missingNumber(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_268_TEST_HPP

