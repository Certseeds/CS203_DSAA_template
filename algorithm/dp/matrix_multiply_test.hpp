// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_MATRIX_MULTIPLY_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_MATRIX_MULTIPLY_TEST_HPP

#include <cstddef>
#include <cstdint>
#include <tuple>
#include <vector>

#include <catch_main.hpp>

namespace dp {
namespace matrix_multiply {// Introduction to Algorithms Edition3 Chapter15.2
using std::tuple;
using std::vector;

namespace iter {
int64_t min_multiply(const vector<tuple<int32_t, int32_t>> &mats);

TEST_CASE("1 [iter::test_matrix_multiply]", "[test_matrix_multiply]") {
    const vector<tuple<int32_t, int32_t>> mats{
            std::make_tuple(30, 35),
            std::make_tuple(35, 15),
            std::make_tuple(15, 5),
            std::make_tuple(5, 10),
            std::make_tuple(10, 20),
            std::make_tuple(20, 25),
    };
    constexpr const auto results{15125};
    const auto output = min_multiply(mats);
}
}
namespace rec {
int64_t min_multiply(const vector<tuple<int32_t, int32_t>> &mats);

TEST_CASE("1 [rec::test_matrix_multiply]", "[test_matrix_multiply]") {
    const vector<tuple<int32_t, int32_t>> mats{
            std::make_tuple(30, 35),
            std::make_tuple(35, 15),
            std::make_tuple(15, 5),
            std::make_tuple(5, 10),
            std::make_tuple(10, 20),
            std::make_tuple(20, 25),
    };
    constexpr const auto results{15125};
    const auto output = min_multiply(mats);
}
}
}
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_MATRIX_MULTIPLY_TEST_HPP
