// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力枚举
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_500 {
using std::array;
using std::vector;

struct leetcode_500 {
    static vector<string> findWords(const vector<string> &words);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_500]", "[test_500]") {
    static constexpr const std::array<const char *const, 6> input{"Metal", "Gear", "Soild", "Venom", "Phantom",
                                                                  "Pain"};

    const vector<std::string> result{};
    CHECK_THAT(result, Equals(leetcode_500::findWords({std::cbegin(input), std::cend(input)})));
}

TEST_CASE("test case 2 [test_500]", "[test_500]") {
    static constexpr const std::array<const char *const, 4> input{"Hello", "Alaska", "Dad", "Peace"};

    const vector<std::string> result{"Alaska", "Dad"};
    CHECK_THAT(result, Equals(leetcode_500::findWords({std::cbegin(input), std::cend(input)})));
}

TEST_CASE("test case 3 [test_500]", "[test_500]") {
    static constexpr const std::array<const char *const, 3> input{"omk", "adsdf", "sfd"};

    const vector<std::string> result{"adsdf", "sfd"};
    CHECK_THAT(result, Equals(leetcode_500::findWords({std::cbegin(input), std::cend(input)})));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_TEST_HPP
