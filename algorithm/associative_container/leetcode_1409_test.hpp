// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag arrays as hashmap
//@Tag 自定义hash
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
};


using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1409}", "{test_1409}") {
    const vector<int32_t> input{3, 1, 2, 1};
    static constexpr const auto m{5};
    const vector<int32_t> result{2, 1, 2, 1};
    CHECK_THAT(result, Equals(leetcode_1409::processQueries(input, m)));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1409_TEST_HPP
