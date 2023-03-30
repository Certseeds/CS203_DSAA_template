// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag binary-search
//@Tag 二分搜索

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_SO_53II_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_SO_53II_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_so_53ii {
using std::vector;

struct leetcode_so_53ii {
    static int32_t missingNumber(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_so_53ii::missingNumber(input));
}

TEST_CASE("test case 2 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_so_53ii::missingNumber(input));
}

TEST_CASE("test case 3 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_so_53ii::missingNumber(input));
}

TEST_CASE("test case 4 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_so_53ii::missingNumber(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_SO_53II_HPP
