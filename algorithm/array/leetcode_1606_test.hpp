// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1606_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1606_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1606 {
using std::vector;

struct leetcode_1606 {
    static vector<int32_t> busiestServers(int32_t k, const vector<int32_t> &arrival, const vector<int32_t> &load);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 {test_1606}", "{test_1606}") {
    static constexpr const auto k{3};
    const vector<int32_t> arrival{1, 2, 3, 4, 5};
    const vector<int32_t> load{5, 2, 3, 3, 3};
    const vector<int32_t> result{1};
    CHECK_THAT(result, UnorderedEquals(leetcode_1606::busiestServers(k, arrival, load)));
}

TEST_CASE("test case 2 {test_1606}", "{test_1606}") {
    static constexpr const auto k{2};
    const vector<int32_t> arrival{1, 2, 3};
    const vector<int32_t> load{114514, 1, 114514};
    const vector<int32_t> result{1};
    CHECK_THAT(result, UnorderedEquals(leetcode_1606::busiestServers(k, arrival, load)));
}

TEST_CASE("test case 3 {test_1606}", "{test_1606}") {
    static constexpr const auto k{3};
    const vector<int32_t> arrival{1, 2, 3, 4, 8, 9, 10};
    const vector<int32_t> load{5, 2, 10, 3, 1, 2, 2};
    const vector<int32_t> result{1};
    CHECK_THAT(result, UnorderedEquals(leetcode_1606::busiestServers(k, arrival, load)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1606_TEST_HPP
