// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_781 {
using std::vector;

struct leetcode_781 {
    static int32_t numRabbits(const vector<int32_t> &answers);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_781]", "[test_781]") {
    const vector<int32_t> input{1, 1, 2};
    static constexpr const auto output{5};
    CHECK(output == leetcode_781::numRabbits(input));
}

TEST_CASE("2 [test_781]", "[test_781]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto output{15};
    CHECK(output == leetcode_781::numRabbits(input));
}

TEST_CASE("3 [test_781]", "[test_781]") {
    const vector<int32_t> input{10, 10, 10};
    static constexpr const auto output{11};
    CHECK(output == leetcode_781::numRabbits(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP

