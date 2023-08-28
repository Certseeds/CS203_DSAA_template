
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1363_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1363_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1363 {

namespace leetcode_1363 {
string largestMultipleOfThree(const vector<int32_t> &digits);
namespace optimize{
string largestMultipleOfThree(const vector<int32_t> &digits);
}
}

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{8, 1, 9};
    constexpr const char *const result{"981"};
    CHECK(result == leetcode_1363::largestMultipleOfThree(input));
    CHECK(result == leetcode_1363::optimize::largestMultipleOfThree(input));
}

TEST_CASE("1-2 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{8, 6, 7, 1, 0};
    constexpr const char *const result{"8760"};
    CHECK(result == leetcode_1363::largestMultipleOfThree(input));
    CHECK(result == leetcode_1363::optimize::largestMultipleOfThree(input));
}

TEST_CASE("1-3 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{1};
    constexpr const char *const result{""};
    CHECK(result == leetcode_1363::largestMultipleOfThree(input));
    CHECK(result == leetcode_1363::optimize::largestMultipleOfThree(input));
}

TEST_CASE("1-4 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{0, 0, 0, 0, 0, 0};
    constexpr const char *const result{"0"};
    CHECK(result == leetcode_1363::largestMultipleOfThree(input));
    CHECK(result == leetcode_1363::optimize::largestMultipleOfThree(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1363_TEST_HPP

