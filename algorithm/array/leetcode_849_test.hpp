// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_849_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_849_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_849 {
using std::vector;

struct leetcode_849 {
    static int32_t numMagicSquaresInside(const vector<int32_t> &seats);
};

TEST_CASE("test case 1 [test_849]", "[test_849]") {
    const vector<int32_t> inputs{1, 0, 0, 0, 1, 0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_849::numMagicSquaresInside(inputs));
}

TEST_CASE("test case 2 [test_849]", "[test_849]") {
    const vector<int32_t> inputs{1, 0, 0, 0};
    static constexpr const auto result{3};
    CHECK(result == leetcode_849::numMagicSquaresInside(inputs));
}

TEST_CASE("test case 3 [test_849]", "[test_849]") {
    const vector<int32_t> inputs{0, 0, 0, 0, 1};
    static constexpr const auto result{4};
    CHECK(result == leetcode_849::numMagicSquaresInside(inputs));
}

TEST_CASE("test case 4 [test_849]", "[test_849]") {
    const vector<int32_t> inputs{0, 1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_849::numMagicSquaresInside(inputs));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_849_TEST_HPP
