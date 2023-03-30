// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1409_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1409_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_1409 {
using std::vector;

struct leetcode_1409 {
    static vector<int32_t> processQueries(const vector<int32_t> &queries, int32_t m);

    static vector<int32_t> processQueries2(const vector<int32_t> &queries, int32_t m);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1409}", "{test_1409}") {
    const vector<int32_t> input{3, 1, 2, 1};
    static constexpr const auto m{5};
    const vector<int32_t> result{2, 1, 2, 1};
    CHECK_THAT(result, Equals(leetcode_1409::processQueries(input, m)));
    CHECK_THAT(result, Equals(leetcode_1409::processQueries2(input, m)));
}

TEST_CASE("test case 2 {test_1409}", "{test_1409}") {
    const vector<int32_t> input{4, 1, 2, 2};
    static constexpr const auto m{4};
    const vector<int32_t> result{3, 1, 2, 0};
    CHECK_THAT(result, Equals(leetcode_1409::processQueries(input, m)));
    CHECK_THAT(result, Equals(leetcode_1409::processQueries2(input, m)));
}

TEST_CASE("test case 3 {test_1409}", "{test_1409}") {
    const vector<int32_t> input{7, 5, 5, 8, 3};
    static constexpr const auto m{8};
    const vector<int32_t> result{6, 5, 0, 7, 5};
    CHECK_THAT(result, Equals(leetcode_1409::processQueries(input, m)));
    CHECK_THAT(result, Equals(leetcode_1409::processQueries2(input, m)));
}

TEST_CASE("test case 4 {test_1409}", "{test_1409}") {
    const vector<int32_t> input{8, 7, 4, 2, 8, 1, 7, 7};
    static constexpr const auto m{8};
    const vector<int32_t> result{7, 7, 5, 4, 3, 4, 4, 0};
    CHECK_THAT(result, Equals(leetcode_1409::processQueries(input, m)));
    CHECK_THAT(result, Equals(leetcode_1409::processQueries2(input, m)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1409_TEST_HPP
