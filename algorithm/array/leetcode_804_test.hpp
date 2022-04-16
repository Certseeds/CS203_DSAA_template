// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_804_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_804_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_804 {
using std::vector;
using std::array;

struct leetcode_804 {
    static int32_t uniqueMorseRepresentations(const vector<string> &words);
};

TEST_CASE("test case 1 [test_804]", "[test_804]") {
    static constexpr const std::array<const char *const, 4> inputs{"gin", "zen", "gig", "msg"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_804::uniqueMorseRepresentations({inputs.cbegin(), inputs.cend()}));
}

TEST_CASE("test case 2 [test_804]", "[test_804]") {
    static constexpr const std::array<const char *const, 1> inputs{"a"};
    static constexpr const auto result{1};
    CHECK(result == leetcode_804::uniqueMorseRepresentations({inputs.cbegin(), inputs.cend()}));

}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_804_TEST_HPP
